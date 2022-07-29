/*
 * ======== i2c_params.c ========
 *
 * Parameter structure required by the I2C driver.
 *
 */

/* PSP include files */
#include <psp_i2c.h>

/* I2C Init Parameters: */
#define I2C_OWN_ADDR          (0x10u)
#define I2C_BUS_FREQ          (200000u)
#define I2C_INPUT_BUS_FREQ    (27000000u)
#define I2C_NUM_BITS          (8u)

/* Default Initial Parameters */
PSP_I2cConfig I2C_devParams =   {   
  PSP_OPMODE_POLLED,   /** Driver operation mode                       */
  I2C_OWN_ADDR,        /**< Own address (7 or 10 bit)                  */
  I2C_NUM_BITS,        /**< Number of bits/byte to be sent/received    */
  I2C_BUS_FREQ,        /**< I2C Bus Frequency                          */
  I2C_INPUT_BUS_FREQ,  /**< Module input clock freq                    */
  FALSE,               /**< 7bit/10bit Addressing mode                 */
  FALSE                /**< Digital Loop Back (DLB) mode enabled       */
};


