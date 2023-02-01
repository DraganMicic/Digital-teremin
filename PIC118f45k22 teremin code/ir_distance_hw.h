/****************************************************************************
* Title                 :   IR Distance HW
* Filename              :   ir_distance_hw.h
* Author                :   VM
* Origin Date           :   03/11/2015
* Notes                 :   None
*****************************************************************************/
/**************************CHANGE LIST **************************************
*
*    Date    Software Version       Initials   Description
*  08/17/13       1.0.0                VM      Interface Created.
*
*****************************************************************************/
/** @file ir_distance_hw.h
 *  @brief This file contains the functions for calculatin the istance between
 *  the IR Distance click and an object.
 *
 *  @date 03 Nov 2015
 *  @author Viktor Milovanovic
 *  @copyright GNU Public License
 *
 *  @version 1.0.0 - Initial testing and verification
 *
 *  @note Test configuration:
 *   MCU:             STM32F107VC
 *   Dev.Board:       EasyMx Pro v7
 *   Oscillator:      72 Mhz internal
 *   Ext. Modules:    GPS Click
 *   SW:              ARM 4.5.2
 *
 */

/**
 * @mainpage
 *  <h1>IR Distance Click</h1>
 * @par Introduction
 *
 * @par
 * <a href="http://www.mikroe.com/click/">IR Distance Click </a>
 * is a distance measuring sensor unit, composed of an integrated
 * combination of PSD (position sensitive detector) ,
 * IR-LED (infrared emitting diode) and signal
 * processing circuit.
 * @par
 * The variety of the reflectivity of the object, the
 * environmental temperature and the operating
 * duration are not influenced easily to the distance
 * detection because of adopting the triangulation
 * method.
 * @par
 * This device outputs the voltage corresponding to
 * the detection distance. So this sensor can also be
 * used as a proximity sensor.
 *
 * @par For examples refer to
 * @ref example
 *
 * @par Specifications and Datasheets can be found here
 * @ref specification
 *
 * @note You will need to install this library via the <a href="http://www.mikroe.com/package-manager/">Package Manager</a> to use it.
 */



#ifndef IR_Distance_HW_H_
#define IR_Distance_HW_H_

/******************************************************************************
* Includes
*******************************************************************************/
#include <stdint.h>

/******************************************************************************
* Preprocessor Constants
*******************************************************************************/

/******************************************************************************
* Configuration Constants
*******************************************************************************/

/******************************************************************************
* Macros
*******************************************************************************/

/******************************************************************************
* Typedefs
*******************************************************************************/
/**
 * @enum Resolutions Supported
 *
 * The 10 and 12 bit resolutions are currently supported.  If your
 * ADC supports higher than 12 bits, configure your ADC to downsample to 12.
 */
typedef enum
{
    RESOLUTION_10,  /**< 10-bit resolution */
    RESOLUTION_12,  /**< 12-bit resolution */
} ir_resolution_t;

/******************************************************************************
* Variables
*******************************************************************************/


/******************************************************************************
* Function Prototypes
*******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief ir_measure_init
 * @param read_adc
 * - ADC function which will read the analog value
 * @param channel
 * - ADC reading channel
 * @param resolution
 * - Desired ADC resolution
 */
#if defined(__MIKROC_PRO_FOR_AVR__)   || \
    defined(__MIKROC_PRO_FOR_8051__)  || \
    defined(__MIKROC_PRO_FOR_DSPIC__) || \
    defined(__MIKROC_PRO_FOR_PIC32__)

void ir_measure_init( uint16_t( *read_adc )( uint8_t adc_channel ),
                      uint8_t channel,
                      ir_resolution_t resolution );
#elif defined( __MIKROC_PRO_FOR_ARM__ )
void ir_measure_init( uint16_t( *read_adc )( uint16_t adc_channel ),
                      uint8_t channel,
                      ir_resolution_t resolution );
#else
void ir_measure_init( uint16_t( *read_adc )( uint16_t adc_channel ),
                      uint8_t channel,
                      ir_resolution_t resolution );
#endif




#ifdef __cplusplus
} // extern "C"
#endif

#endif /*File_H_*/

/*** End of File **************************************************************/

/**
 * @page example Example
 *
 * @par Example created using the EasyMX Pro v7
 *
 * @code
 *
 * void system_init( void );
 *
 *
 * void system_init()
 * {
 *
 *   ADC1_Init();
 *    UART1_Init_Advanced(115200, _UART_8_BIT_DATA, _UART_NOPARITY, _UART_ONE_STOPBIT, &_GPIO_MODULE_USART1_PA9_10);
 *
 *   ir_measure_init( ADC1_Read, 4, RESOLUTION_12 );
 *   UART1_Write_Text( "READY \r\n" );
 * }
 *
 * void main()
 * {
 *   char tmp_text[20];
 *
 *   system_init();
 *
 *   while( 1 )
 *   {
 *       sprintf( tmp_text, "Distance is: %4.2f\r\n", ir_measure_cm() );
 *       UART1_Write_Text( tmp_text );
 *       Delay_ms( 500 );
 *   }
 * }
 *
 * @endcode
 */

/**
 * @page specification Specifications
 *
 * <a href="http://www.sharp-world.com/products/device/lineup/data/pdf/datasheet/gp2y0a60szxf_e.pdf">Datasheet</a>
 */
