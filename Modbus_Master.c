#include<stdlib.h>
#include<stdio.h>
#include"CRC16_ModBus.h"

int main()
{
    //Variaveis de dados
    unsigned char bufferIn[256] = {0x05,0x03,0x00,0x06,0x00,0x05,0x01,0x02,0x03,0x04,0x05};
    unsigned char bufferOut[256] = {0x05,0x03,0x00,0x06,0x00,0x05,0x01,0x02,0x03,0x04,0x05};

    //Variaveis de controle 
    unsigned char tamanhoDados = 5;

    //Preenchendo ID do Device e Função modbus
    printf("Qual e o endereco do dispositivo ? :\n");
    scanf("%x",&bufferOut[0]);
    printf("Qual e a funcao ? :\n");
    scanf("%x",&bufferOut[1]);

    CRC16_Modbus_Outdata(&bufferOut[0], tamanhoDados);

    switch(bufferOut[1])
    {
        case 0x03:

                //Preenchendo no buffer de entrada o endereço inicial e quantidade de variaveis a serem lidas
                printf("Quer ler a partir de qual endereco ?, informe o byte mais significativo (MSB) :\n");
                scanf("%x",&bufferOut[2]);
                printf("Agora informe o byte menos significativo (LSB) do endereco :\n");
                scanf("%x",&bufferOut[3]);
                printf("Quantos enderecos voce quer ler ?, informe o byte mais significativo (MSB) :\n");
                scanf("%x",&bufferOut[4]);
                printf("Agora informe o byte menos significativo (LSB) da quantidade dos enderecos :\n");
                scanf("%x",&bufferOut[5]);

                //Configurando variavel de controle
                tamanhoDados = 6;
                printf("\n\n\n");

                //Escrevendo no buffer de saída
                printf("Seu frame Modbus RTU fica assim :\n\n");
                for(unsigned char i = 0; i <= 5; i++)
                {
                    printf("[%X]",bufferOut[i]);
                }

                //Calculando CRC
                printf("[%X]",(bufferOut[7] = (CRC16_Modbus_Outdata(&bufferOut[0],tamanhoDados) & 0x00FF))); //LSB
                printf("[%X]",(bufferOut[6] = (CRC16_Modbus_Outdata(&bufferOut[0],tamanhoDados) >> 8)));     //MSB
                printf("\n\n\n\n");

                break;

        case 0x05:

                //Preenchendo no buffer de entrada demais informações da função 5 modbus
                printf("Qual e o endereco da variavel ?, informe o byte mais significativo (MSB) :\n");
                scanf("%x",&bufferOut[2]);
                printf("Agora informe o byte menos significativo (LSB) do endereço :\n");
                scanf("%x",&bufferOut[3]);
                printf("Qual valor deseja escrever na variavel ?, informe o byte mais significativo (MSB) :\n");
                scanf("%x",&bufferOut[4]);
                printf("Agora informe o byte menos significativo (LSB) do valor a ser escrito :\n");
                scanf("%x",&bufferOut[5]);

                //Configurando variavel de controle 
                tamanhoDados = 6;
                printf("\n\n\n");

                //Escrevendo no buffer de saída
                printf("Seu frame Modbus RTU fica assim :\n\n");

                for(unsigned char i = 0; i <= 4; i++)
                {
                    printf("[%X]",bufferOut[i]);
                }

                //Calculando CRC
                printf("[%X]",(bufferOut[7] = (CRC16_Modbus_Outdata(&bufferOut[0],tamanhoDados) & 0x00FF))); //LSB
                printf("[%X]",(bufferOut[6] = (CRC16_Modbus_Outdata(&bufferOut[0],tamanhoDados) >> 8)));     //MSB
                printf("\n\n\n\n");

                break;

        default:
                printf("Funcao desconhecida\n\n\n");
                break;
    }

    /*printf("/--------------------     Validando o CRC recebido     --------------------/\n\n");

    if(buffer[1] == 5)
    {
        tamanhoDados = 6;
        CRC16_Modbus_Indata(&buffer[0],tamanhoDados);
    }*/
    
    system("pause");
}
