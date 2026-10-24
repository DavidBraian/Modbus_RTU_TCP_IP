#include<stdlib.h>
#include<stdio.h>
#include"CRC16_ModBus.h"

int main()
{
    //Calculando o CRC16 ModBus a ser enviado

    //Variavel de dados
    unsigned short buffer[7] =         {0x05,0x05,0x01,0x00,0x00};

    //Variaveis de controle 
    unsigned short tamanhoDados = 0;

    printf("Qual e o endereco do dispositivo ? :\n");
    scanf("%x",&buffer[0]);
    printf("Qual e a funcao ? :\n");
    scanf("%x",&buffer[1]);
    printf("Qual e o endereco da variavel ? :\n");
    scanf("%x",&buffer[2]);
    printf("Qual e o valor a ser escrito ? :\n");
    scanf("%x",&buffer[3]);

    if(buffer[1] == 5)
    {
        tamanhoDados = 5;
    }
    else
    {
        printf("Funcao desconhecida\n\n\n");
    }

    CRC16_Modbus_Outdata(&buffer[0],tamanhoDados);
    printf("\n\n\n");
    printf("Seu frame Modbus RTU fica assim :\n\n");

    for(unsigned char i = 0; i <= 6; i++)
    {
        printf("[%X]",buffer[i]);
    }
    printf("\n\n\n\n");

    printf("/*********************     Validando o CRC recebido     *********************/\n\n");

    if(buffer[1] == 5)
    {
        tamanhoDados = 6;
        CRC16_Modbus_Indata(&buffer[0],tamanhoDados);
    }
    
    system("pause");
}
