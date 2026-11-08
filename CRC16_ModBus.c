#include<stdio.h>
#include"CRC16_ModBus.h"

unsigned short int CRC16_Modbus_Outdata(unsigned char buffer[], unsigned char sizedata)
{
    //Variaveis de controle
    unsigned char cont         = 0;

    //Variaveis utilizadas no calculo
	unsigned short int CRC = 0xFFFF;

    //Iniciando o valor do CRC16 modbus.
	CRC ^= buffer[0];

    //Logica de iterações para o calculo do CRC16 modbus
	for(char i = 1; i<= sizedata; i++)
	{
        while(cont <= 7)
        {
            if(CRC & 0x0001 == 1)
            {
                CRC = (CRC >> 1) ^ 0XA001;
            }
            else
            {
                CRC >>= 1;
            }
            cont++;
        }
        cont =  0;
        CRC ^= buffer[i];
	}

   return CRC;
}

void CRC16_Modbus_Indata(unsigned char buffer[], unsigned char sizedata)
{
    //Variaveis de controle
    unsigned char cont          = 0;
    //Variaveis utilizadas no calculo
	unsigned short int CRC = 0xFFFF;

    //Iniciando o valor do CRC16 modbus.
	CRC ^= buffer[0];

    //Logica de iterações para o calculo do CRC16 modbus
	for(char i = 1; i<= sizedata; i++)
	{
        while(cont <= 7)
        {
            if(CRC & 0x0001 == 1)
            {
                CRC = (CRC >> 1) ^ 0XA001;
            }
            else
            {
                CRC >>= 1;
            }
            cont++;
        }
        cont =  0;
        CRC ^= buffer[i];
	}

    if(CRC == 0x0000) printf("CRC valido!\n\n\n");
    else printf("CRC invalido, erro na transmissao detectado.! \n\n\n");
 
}