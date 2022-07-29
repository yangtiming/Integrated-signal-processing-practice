
/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  I2C Prototypes                                                          *
 *                                                                          *
 * ------------------------------------------------------------------------ */
Int16 DAVINCIEVM_I2C_init ( );
Int16 DAVINCIEVM_I2C_close( );
Int16 DAVINCIEVM_I2C_write( Uint16 slaveaddr, Uint8* data, Uint16 len );
Int16 DAVINCIEVM_I2C_read ( Uint16 slaveaddr, Uint8* data, Uint16 len );
