  #include "ir_distance_hw.h"     //mora ovaj faj da se prekopira u folder gde je sam projekat

void system_init( void );
 unsigned int lobr = 0;
unsigned int hibr = 0;
unsigned int br = 0;

void system_init(){


    ADC_Init();
  ANSELA = 0x04;           //RA2 se postavlja kao ulaz za ADC
    TRISA = 0x04;
    LATA = 0;


    UART1_Init( 80000 );
    ir_measure_init( ADC_Read, 2 , RESOLUTION_10 );   //podesava se sta ce biti ulaz za citanje i ra;unanje po funkciji

}


void main(){

     system_init();

     while( 1 ){

     br =  ir_measure_cm()*100;       //ocita broj i pomnozi sa 100 zbog zareza
     hibr = br/256;                   //racuna hi
     lobr = br-(hibr*256);            //racuna lo

     UART1_Write(1);                  //signal za hi
     UART1_Write(hibr);

     UART1_Write(2);                  //signal za lo
     UART1_Write(lobr);
     //Delay_ms(100);

       
     }
}