/*
    File:       main.c
    Version:    1.1
    Date:       March. 13, 2010
    
    KnightBot  Version 1. Schematics and details at www.**.com
    
    ****************************************************************************
    Copyright (C) 2010 Fahad Mirza   <fahad_1046116@yahoo.com>

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    ****************************************************************************
*/

/* defines for line sensors */
#define LED_PORT PORTB
#define LED_DDR DDRB
#define LED1 PB0     /* left-most sensor */
#define LED2 PB1
#define LED3 PB2
#define LED4 PB3
#define LED5 PB4     /* right-most sensor */

/* defines for motor control */
#define MOTOR_PORT PORTA
#define MOTOR_DDR DDRA
#define M1DIRA PA1
#define M1DIRB PA2
#define M2DIRA PA4
#define M2DIRB PA5



#define GO_LEFT 0
#define GO_HARD_LEFT 1
#define GO_FORWARD 2
#define GO_HARD_RIGHT 3
#define GO_RIGHT 4
#define GO_BRAKE 5
#define GO_REVERSE 6


#include <avr/io.h>
#include <avr/interrupt.h>

unsigned char midpoint[5] = { 0,0,0,0,0 };    /* sensor trip points */
unsigned int k;
/* function prototypes */
void init_io();
void init_adc();
void steer_robot(unsigned char direction);
unsigned char get_line_sensor_value(unsigned char led_index);
void calibrate_line_sensors();


/* INT0 Interrupt Service Routine (ISR) */
ISR(INT0_vect)
{
       
	    unsigned char i;
		unsigned char adc_value;

        steer_robot(GO_REVERSE);
		
		for(k=0;k<65535;k++){;}

		LED_PORT &= ~(1<<LED1) & ~(1<<LED2) & ~(1<<LED4) & ~(1<<LED5);

		steer_robot(GO_HARD_LEFT);

		for(i=0;i<3;i++)
		{
			for(k=0;k<65535;k++){;}
		}
		

        do
        {
             adc_value = get_line_sensor_value(3);  
                                
        }while(adc_value < midpoint[3]);

        steer_robot(GO_BRAKE);

        // clear pending interrupts
        GIFR |=  (1<<INTF0);
}


int main (void)
{
        
        unsigned char adc_value;                      /* ADC value */ 
        unsigned char last_direction = GO_FORWARD; /* last direction steered */
        unsigned char i;                              /* loop counter */
        unsigned char sensor_bits;                    /* sensor bit values */
        
        /* initializations */
        init_io();        
        init_adc();

        
        /* calibration */    
        calibrate_line_sensors();
  
 
        while (1)                       
        {
                /* clear previous value */
                sensor_bits = 0;
                
                /* 
                create bit patter for sensors where a 1 represents the line
                under the sensor and a 0 represents no line
                */
                for (i=0; i<5; i++)
                {
                        sensor_bits = sensor_bits << 1;
                        adc_value = get_line_sensor_value(i);
                        if (adc_value >= midpoint[i]) 
                        {
                                sensor_bits |= 0x01;    // sensor_bits |= _BV(0)
                        }
                        else
                        {
                                sensor_bits &= 0xFE;  // sensor_bits &= ~_BV(0);
                        }
                }

                /* hexidecimal representations for various bit patterns of lines */  
                            
                if (sensor_bits == 0x04 || sensor_bits == 0x0E || sensor_bits == 0x1F)
                {
                        steer_robot(GO_FORWARD);
                        last_direction = GO_FORWARD;
                }
                else if (sensor_bits == 0x0C || sensor_bits == 0x08)
                {
                        steer_robot(GO_LEFT);
                        last_direction = GO_LEFT;
                }
                else if (sensor_bits == 0x02 || sensor_bits == 0x06)
                {
                        steer_robot(GO_RIGHT);
                        last_direction = GO_RIGHT;
                }
                else if (sensor_bits == 0x10 || sensor_bits == 0x18 || sensor_bits == 0x1C)
                {
                        steer_robot(GO_HARD_LEFT);
                        last_direction = GO_HARD_LEFT;
                }
                else if (sensor_bits == 0x01 || sensor_bits == 0x03 || sensor_bits == 0x07)
                {
                        steer_robot(GO_HARD_RIGHT);
                        last_direction = GO_HARD_RIGHT;
                }
                else
                {
                        /*
                        If the robot does not see a line at all, it's possible that
                        the line is between sensors. Continue going the direction
                        previously determined until the line is found.
                        */
                        steer_robot(last_direction);
                }   
        }
        return (0);
}

void init_io()
{
        /* setup input/output */
        LED_DDR |= (1<<LED1) | (1<<LED2) | (1<<LED3) | (1<<LED4) | (1<<LED5);
        MOTOR_DDR |= (1<<M1DIRA) | (1<<M1DIRB) | (1<<M2DIRA) | (1<<M2DIRB);

		/* set INT0 interrupt enable bit */
        GIMSK= (1<<INT0);
		MCUCR |= (1<<ISC01) | (1<<ISC00); // INT0 to rising edge        
          
       /* enable interrupts */
        sei();
}

void init_adc(void)
{
        ADMUX |=  (1<<REFS0) | (1<<ADLAR); // channel 0, left-justified result
        ADCSR |= (1<<ADEN) | (1<<ADPS1); // Prescaler 4
}



void steer_robot(unsigned char direction)
{
        switch (direction)
        {
                case GO_LEFT:
                        MOTOR_PORT &= ~(1<<M1DIRA);    /* clear M1 */
                        MOTOR_PORT &= ~(1<<M1DIRB);

                        MOTOR_PORT |= (1<<M2DIRA);         /* set M2 */
                        MOTOR_PORT &= ~(1<<M2DIRB);
                        break;

                
                case GO_HARD_LEFT:
						MOTOR_PORT &= ~(1<<M1DIRA);
                        MOTOR_PORT |= (1<<M1DIRB);         /* reverse M1*/
                        
                        MOTOR_PORT |= (1<<M2DIRA);         /* set M2 */
                        MOTOR_PORT &= ~(1<<M2DIRB);
                        break;

                
                case GO_FORWARD:
                        MOTOR_PORT |= (1<<M1DIRA);         /* set M1 */
                        MOTOR_PORT &= ~(1<<M1DIRB);

                        MOTOR_PORT |= (1<<M2DIRA);         /* set M2 */
                        MOTOR_PORT &= ~(1<<M2DIRB);
                        break;
                
                
                case GO_HARD_RIGHT:
                        MOTOR_PORT |= (1<<M1DIRA);         /* set M1 */
                        MOTOR_PORT &= ~(1<<M1DIRB);

						MOTOR_PORT &= ~(1<<M2DIRA);
                        MOTOR_PORT |= (1<<M2DIRB);         /* reverse M2 */
                        break;
                
                case GO_RIGHT:
                        MOTOR_PORT |= (1<<M1DIRA);         /* set M1 */
                        MOTOR_PORT &= ~(1<<M1DIRB);

                        MOTOR_PORT &= ~(1<<M2DIRA);       /* clear M2 */
                        MOTOR_PORT &= ~(1<<M2DIRB);
                        break;
                
                case GO_BRAKE:
                        MOTOR_PORT &= ~(1<<M1DIRA);       /* clear M1 */
                        MOTOR_PORT &= ~(1<<M1DIRB);

                        MOTOR_PORT &= ~(1<<M2DIRA);       /* clear M2 */
                        MOTOR_PORT &= ~(1<<M2DIRB);
                        break;

				case GO_REVERSE:
                        MOTOR_PORT &= ~(1<<M1DIRA);       /* clear M1 */
                        MOTOR_PORT |= (1<<M1DIRB);

                        MOTOR_PORT &= ~(1<<M2DIRA);       /* clear M2 */
                        MOTOR_PORT |= (1<<M2DIRB);
                        break;

                break;    
        }
}

unsigned char get_line_sensor_value(unsigned char led_index)
{
        unsigned char adc_value;
        
        switch (led_index)
        {
                case 0: LED_PORT |= (1<<LED1); break;
                case 1: LED_PORT |= (1<<LED2); break;
                case 2: LED_PORT |= (1<<LED3); break;
                case 3: LED_PORT |= (1<<LED4); break;
                case 4: LED_PORT |= (1<<LED5); break;
        }

		for(k=0;k<5000;k++){;}
        
        /* read output from ADC */
        ADCSR |= (1<<ADSC);
        while (!(ADCSR & (1<<ADIF)));
        adc_value = ADCH;
        ADCSR |= (1<<ADIF);
        
        /* turn off LED */
        switch (led_index)
        {
                case 0: LED_PORT &= ~ (1<<LED1); break;
                case 1: LED_PORT &= ~ (1<<LED2); break;
                case 2: LED_PORT &= ~ (1<<LED3); break;
                case 3: LED_PORT &= ~ (1<<LED4); break;
                case 4: LED_PORT &= ~ (1<<LED5); break;
        }
        
        return adc_value;
}

void calibrate_line_sensors()
{
        unsigned char adc_value;              /* ADC value */
        unsigned char i, j;                   /* loop counter */ 
        unsigned char thresh_high[5] = { 0,0,0,0,0 };
        unsigned char thresh_low[5] = { 255,255,255,255,255 };
                     
        for (i=0; i<50; i++) 
        { 
                for (j=0; j<5; j++)
                {
                        adc_value = get_line_sensor_value(j);
                        if (adc_value < thresh_low[j]) thresh_low[j] = adc_value;
                        if (adc_value > thresh_high[j]) thresh_high[j] = adc_value;
                }
				
				
				if(i==25)
				{

					steer_robot(GO_FORWARD);
					for(k=0;k<65535;k++){;}
					steer_robot(GO_BRAKE);

				}
				
        }
        
        for (i=0; i<5; i++)
        {
                midpoint[i] = (thresh_low[i] + (thresh_high[i] - thresh_low[i]) / 2);
        }
  
}
