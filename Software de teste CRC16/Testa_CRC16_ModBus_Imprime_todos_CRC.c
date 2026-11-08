#include<stdlib.h>
#include<stdio.h>


void CRC16_Modbus_Outdata(unsigned char buffer[], unsigned char sizedata);

int main()
{
    //Variaveis de dados
    unsigned char bufferOut[256] = {0x05,0x03,0xC3,0x4A,0x00,0x05,0x01,0x02,0x03,0x04,0x05};

    //Variaveis de controle 
    unsigned char tamanhoDados = 6;

    //Preenchendo ID do Device e Função modbus
    /*printf("Qual e o endereco do dispositivo ? :\n");
    scanf("%x",&bufferOut[0]);
    printf("Qual e a funcao ? :\n");
    scanf("%x",&bufferOut[1]);
    printf("Qual e o endereco da variavel ? :\n");
    scanf("%x",&bufferOut[2]);
    printf("Qual e o valor a ser escrito ? :\n");
    scanf("%x",&bufferOut[3]);*/

    printf("Historico do CRC :\n\n");

    CRC16_Modbus_Outdata(&bufferOut[0], tamanhoDados);

    system("pause");
}

void CRC16_Modbus_Outdata(unsigned char buffer[], unsigned char sizedata)
{
    //Variaveis de controle
    unsigned char cont         = 0;

    //Variaveis utilizadas no calculo
	unsigned short int CRC = 0xFFFF;

    //Iniciando o valor do CRC16 modbus.
	CRC ^= buffer[0];

    printf("1 byte[%X]\n\n",CRC);

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

            printf("[%X]\n\n",CRC);
            cont++;
        }
        cont =  0;
        CRC ^= buffer[i];

        if(i == sizedata)
        {
            printf("\n\n");
        }
        else
        {
            printf("%i byte[%X]\n\n",(i+1),CRC);
        }

	}
}