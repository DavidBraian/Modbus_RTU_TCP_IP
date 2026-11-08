#ifndef CRC16_MODBUS_H
#define CRC16_MODBUS_H

unsigned short int CRC16_Modbus_Outdata(unsigned char buffer[], unsigned char sizedata);
void CRC16_Modbus_Indata(unsigned  char buffer[], unsigned char sizedata);

#endif 