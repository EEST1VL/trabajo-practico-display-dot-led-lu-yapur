#include <Arduino.h>

unsigned char vect_ascii[87] = {
/************************CONTROL*********************************************/
0000000, 0000001, 0000010, 0000011,          //NUll,SOH,STX,ETX
0000100, 0000101, 0000110, 0000111,          //EOT,ENQ,ACK,BEL
0001000, 0001001, 0001010, 0001011,          //BS,HT,LF,VT,
0001100, 0001101, 0001110, 0001111,          //FF,CR,SO,SI
0010000, 0010001, 0010010, 0010011,          //DLE,DC1,DC2,DC3
0010100, 0010101, 0010110, 0010111,          //DC4, NAK, SYN,ETB
0011000, 0011001, 0011010, 0011011,          //CAN, EM, SUB, ESC
0011100, 0011101, 0011110, 0011111,          //FS GS, RS, US
1111111, 0100000,                            //DEL, SPACE

/************************LETRAS MAY******************************************/
1000001, 1000010, 1000011, 1000100, 1000101,  //A,B,C,D,E
1000110, 1000111, 1001000, 1001001, 1001010,  //F,G,H,I,J
1001011, 1001100, 1001101, 1001110, 10100101, //K,L,M,N,Ñ
1001111, 1010000, 1010001, 1010010, 1010011,  //O,P,Q,R,S
1010100, 1010101, 1010110, 1010111, 1011000,  //T,U,V,X
1011001, 1011010,                             //Y,Z

/************************LETRAS MIN ******************************************/
1100001, 1100010, 1100011, 1100100,  //a,b,c,d
1100101, 1100110, 1100111, 1101000,  //e,f,g,h
1101001, 1101010, 1101011, 1101100,  //i,j,k,l
1101101, 1101110, 10100100, 1101111, //m,n,ñ,o
1110000, 1110001, 1110010, 1110011,  //p,q,r,s
1110100, 1110101, 1110110, 1110111,  // t,u,v,w
1111000, 1111001, 1111010            //x,y,z
};

void config_TIMER0(void)
{                         // Codigo de "config_TIMER0". Devolver en vacio.
  TCCR0A = (1 << WGM01);  // Activa el bit CTC (clear timer on compare match)
  OCR0A = 62;             // valor de comparacion de int cada 1ms
  TCCR0B = (1 << CS02);   // divido por 256 y generar interrupciones cada 1 ms
  TIMSK0 = (1 << OCIE0A); // Habilita las interrupciones entimer compare
}

void config_sa(void){
  PORTB |= (1 << PB0); //RCK
  PORTB |= (1 << PB1); //SCK
  PORTB |= (1 << PB2); //SI
  PORTB |= (1 << PB3); //O_L
}

typedef enum
{
  fila0,
  fila1,
  fila2,
  fila3,
  fila4,
  fila5,
  fila6
} estadofila;

void Multiplexado()
int main(void){

}