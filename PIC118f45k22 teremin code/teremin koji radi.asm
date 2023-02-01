
_system_init:

;teremin koji radi.c,8 :: 		void system_init(){
;teremin koji radi.c,11 :: 		ADC_Init();
	CALL        _ADC_Init+0, 0
;teremin koji radi.c,12 :: 		ANSELA = 0x04;           //RA2 se postavlja kao ulaz za ADC
	MOVLW       4
	MOVWF       ANSELA+0 
;teremin koji radi.c,13 :: 		TRISA = 0x04;
	MOVLW       4
	MOVWF       TRISA+0 
;teremin koji radi.c,14 :: 		LATA = 0;
	CLRF        LATA+0 
;teremin koji radi.c,17 :: 		UART1_Init( 80000 );
	BSF         BAUDCON+0, 3, 0
	CLRF        SPBRGH+0 
	MOVLW       49
	MOVWF       SPBRG+0 
	BSF         TXSTA+0, 2, 0
	CALL        _UART1_Init+0, 0
;teremin koji radi.c,18 :: 		ir_measure_init( ADC_Read, 2 , RESOLUTION_10 );   //podesava se sta ce biti ulaz za citanje i ra;unanje po funkciji
	MOVLW       _ADC_Read+0
	MOVWF       FARG_ir_measure_init_read_adc+0 
	MOVLW       hi_addr(_ADC_Read+0)
	MOVWF       FARG_ir_measure_init_read_adc+1 
	MOVLW       FARG_ADC_Read_channel+0
	MOVWF       FARG_ir_measure_init_read_adc+2 
	MOVLW       hi_addr(FARG_ADC_Read_channel+0)
	MOVWF       FARG_ir_measure_init_read_adc+3 
	MOVLW       2
	MOVWF       FARG_ir_measure_init_channel+0 
	CLRF        FARG_ir_measure_init_resolution+0 
	CALL        _ir_measure_init+0, 0
;teremin koji radi.c,20 :: 		}
L_end_system_init:
	RETURN      0
; end of _system_init

_main:

;teremin koji radi.c,23 :: 		void main(){
;teremin koji radi.c,25 :: 		system_init();
	CALL        _system_init+0, 0
;teremin koji radi.c,27 :: 		while( 1 ){
L_main0:
;teremin koji radi.c,29 :: 		br =  ir_measure_cm()*100;       //ocita broj i pomnozi sa 100 zbog zareza
	CALL        _ir_measure_cm+0, 0
	MOVLW       0
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVLW       72
	MOVWF       R6 
	MOVLW       133
	MOVWF       R7 
	CALL        _Mul_32x32_FP+0, 0
	CALL        _double2word+0, 0
	MOVF        R0, 0 
	MOVWF       _br+0 
	MOVF        R1, 0 
	MOVWF       _br+1 
;teremin koji radi.c,30 :: 		hibr = br/256;                   //racuna hi
	MOVF        R1, 0 
	MOVWF       R5 
	CLRF        R6 
	MOVF        R5, 0 
	MOVWF       _hibr+0 
	MOVF        R6, 0 
	MOVWF       _hibr+1 
;teremin koji radi.c,31 :: 		lobr = br-(hibr*256);            //racuna lo
	MOVF        R5, 0 
	MOVWF       R3 
	CLRF        R2 
	MOVF        R2, 0 
	SUBWF       R0, 0 
	MOVWF       _lobr+0 
	MOVF        R3, 0 
	SUBWFB      R1, 0 
	MOVWF       _lobr+1 
;teremin koji radi.c,33 :: 		UART1_Write(1);                  //signal za hi
	MOVLW       1
	MOVWF       FARG_UART1_Write_data_+0 
	CALL        _UART1_Write+0, 0
;teremin koji radi.c,34 :: 		UART1_Write(hibr);
	MOVF        _hibr+0, 0 
	MOVWF       FARG_UART1_Write_data_+0 
	CALL        _UART1_Write+0, 0
;teremin koji radi.c,36 :: 		UART1_Write(2);                  //signal za lo
	MOVLW       2
	MOVWF       FARG_UART1_Write_data_+0 
	CALL        _UART1_Write+0, 0
;teremin koji radi.c,37 :: 		UART1_Write(lobr);
	MOVF        _lobr+0, 0 
	MOVWF       FARG_UART1_Write_data_+0 
	CALL        _UART1_Write+0, 0
;teremin koji radi.c,41 :: 		}
	GOTO        L_main0
;teremin koji radi.c,42 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
