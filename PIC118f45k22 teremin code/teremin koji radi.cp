#line 1 "R:/Teremind/ter radi/teremin koji radi.c"
#line 1 "r:/teremind/ter radi/ir_distance_hw.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for pic/include/stdint.h"




typedef signed char int8_t;
typedef signed int int16_t;
typedef signed long int int32_t;


typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long int uint32_t;


typedef signed char int_least8_t;
typedef signed int int_least16_t;
typedef signed long int int_least32_t;


typedef unsigned char uint_least8_t;
typedef unsigned int uint_least16_t;
typedef unsigned long int uint_least32_t;



typedef signed char int_fast8_t;
typedef signed int int_fast16_t;
typedef signed long int int_fast32_t;


typedef unsigned char uint_fast8_t;
typedef unsigned int uint_fast16_t;
typedef unsigned long int uint_fast32_t;


typedef signed int intptr_t;
typedef unsigned int uintptr_t;


typedef signed long int intmax_t;
typedef unsigned long int uintmax_t;
#line 95 "r:/teremind/ter radi/ir_distance_hw.h"
typedef enum
{
 RESOLUTION_10,
 RESOLUTION_12,
} ir_resolution_t;
#line 135 "r:/teremind/ter radi/ir_distance_hw.h"
void ir_measure_init( uint16_t( *read_adc )( uint16_t adc_channel ),
 uint8_t channel,
 ir_resolution_t resolution );
#line 3 "R:/Teremind/ter radi/teremin koji radi.c"
void system_init( void );
 unsigned int lobr = 0;
unsigned int hibr = 0;
unsigned int br = 0;

void system_init(){


 ADC_Init();
 ANSELA = 0x04;
 TRISA = 0x04;
 LATA = 0;


 UART1_Init( 80000 );
 ir_measure_init( ADC_Read, 2 , RESOLUTION_10 );

}


void main(){

 system_init();

 while( 1 ){

 br = ir_measure_cm()*100;
 hibr = br/256;
 lobr = br-(hibr*256);

 UART1_Write(1);
 UART1_Write(hibr);

 UART1_Write(2);
 UART1_Write(lobr);



 }
}
