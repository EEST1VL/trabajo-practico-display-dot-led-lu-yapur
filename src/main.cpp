#include <Arduino.h>



static uint8_t tabla[] = {
/************************CONTROL**********************************************/

0x00, 0x00, 0x00, 0x00, 0x00, // espacio

0000000, 0000001, 0000010, 0000011,           // NUll, SOH, STX, ETX                      
0000100, 0000101, 0000110, 0000111,           // EOT,  ENQ, ACK, BEL                   
0001000, 0001001, 0001010, 0001011,           // BS,   HT,  LF,  VT                         
0001100, 0001101, 0001110, 0001111,           // FF,   CR,  SO,  SI                        
0010000, 0010001, 0010010, 0010011,           // DLE,  DC1, DC2, DC3                
0010100, 0010101, 0010110, 0010111,           // DC4,  NAK, SYN, ETB                     
0011000, 0011001, 0011010, 0011011,           // CAN,  EM,  SUB, ESC                   
0011100, 0011101, 0011110, 0011111,           // FS,   GS,  RS,  US                          
1111111, 0100000,                             // DEL,  SPACE  

/************************LETRAS MAY*******************************************/

	0x7E, 0x09, 0x09, 0x09, 0x7E, // A
	0x7F, 0x49, 0x49, 0x49, 0x36, // B
	0x3E, 0x41, 0x41, 0x41, 0x22, // C
	0x7F, 0x41, 0x41, 0x22, 0x1C, // D
	0x7F, 0x49, 0x49, 0x49, 0x41, // E
	0x7F, 0x09, 0x09, 0x09, 0x01, // F
	0x3E, 0x41, 0x49, 0x49, 0x7A, // G
	0x7F, 0x08, 0x08, 0x08, 0x7F, // H
	0x41, 0x41, 0x7F, 0x41, 0x41, // I
	0x20, 0x40, 0x40, 0x40, 0x3F, // J
	0x7F, 0x08, 0x14, 0x22, 0x41, // K
	0x7F, 0x40, 0x40, 0x40, 0x40, // L
	0x7F, 0x02, 0x0C, 0x02, 0x7F, // M
	0x7F, 0x04, 0x08, 0x10, 0x7F, // N
	0x3E, 0x41, 0x41, 0x41, 0x3E, // O
	0x7F, 0x09, 0x09, 0x09, 0x06, // P
	0x3E, 0x41, 0x51, 0x21, 0x5E, // Q
	0x7F, 0x09, 0x19, 0x29, 0x46, // R
	0x46, 0x49, 0x49, 0x49, 0x31, // S
	0x01, 0x01, 0x7F, 0x01, 0x01, // T
	0x3F, 0x40, 0x40, 0x40, 0x3F, // U
	0x1F, 0x20, 0x40, 0x20, 0x1F, // V
	0x3F, 0x40, 0x38, 0x40, 0x3F, // W
	0x63, 0x14, 0x08, 0x14, 0x63, // X
	0x07, 0x08, 0x70, 0x08, 0x07, // Y
	0x61, 0x51, 0x49, 0x45, 0x43, // Z
  
/************************LETRAS MIN*******************************************/
0x20, 0x54, 0x54, 0x54, 0x78, // a
	0x7F, 0x48, 0x44, 0x44, 0x38, // b
	0x38, 0x44, 0x44, 0x44, 0x00, // c
	0x38, 0x44, 0x44, 0x48, 0x7F, // d
	0x38, 0x54, 0x54, 0x54, 0x18, // e
	0x08, 0x7E, 0x09, 0x01, 0x02, // f
	0x08, 0x14, 0x54, 0x54, 0x3C, // g
	0x7F, 0x08, 0x04, 0x04, 0x78, // h
	0x00, 0x44, 0x7D, 0x40, 0x00, // i
	0x20, 0x40, 0x44, 0x3D, 0x00, // j
	0x00, 0x7F, 0x10, 0x28, 0x44, // k
	0x00, 0x41, 0x7F, 0x40, 0x00, // l
	0x7C, 0x04, 0x18, 0x04, 0x78, // m
	0x7C, 0x08, 0x04, 0x04, 0x78, // n
	0x38, 0x44, 0x44, 0x44, 0x38, // o
	0x7C, 0x14, 0x14, 0x14, 0x08, // p
	0x08, 0x14, 0x14, 0x18, 0x7C, // q
	0x7C, 0x08, 0x04, 0x04, 0x08, // r
	0x48, 0x54, 0x54, 0x54, 0x20, // s
	0x04, 0x3F, 0x44, 0x40, 0x20, // t
	0x3C, 0x40, 0x40, 0x20, 0x7C, // u
	0x1C, 0x20, 0x40, 0x20, 0x1C, // v
	0x3C, 0x40, 0x30, 0x40, 0x3C, // w
	0x44, 0x28, 0x10, 0x28, 0x44, // x
	0x0C, 0x50, 0x50, 0x50, 0x3C, // y
	0x44, 0x64, 0x54, 0x4C, 0x44, // z
  
/************************Caracteres*******************************************/
	0x00, 0x00, 0x5F, 0x00, 0x00, // !
	0x00, 0x07, 0x00, 0x07, 0x00, // "
	0x14, 0x7F, 0x14, 0x7F, 0x14, // #
	0x24, 0x2A, 0x7F, 0x2A, 0x12, // $
	0x23, 0x13, 0x08, 0x64, 0x62, // %
	0x36, 0x49, 0x55, 0x22, 0x50, // &
	0x00, 0x05, 0x03, 0x00, 0x00, // '
	0x00, 0x1C, 0x22, 0x41, 0x00, // (
	0x00, 0x41, 0x22, 0x1C, 0x00, // )
	0x14, 0x08, 0x3E, 0x08, 0x14, // *
	0x08, 0x08, 0x3E, 0x08, 0x08, // +
	0x00, 0x50, 0x30, 0x00, 0x00, // ,
	0x08, 0x08, 0x08, 0x08, 0x08, // -
	0x00, 0x60, 0x60, 0x00, 0x00, // .
	0x20, 0x10, 0x08, 0x04, 0x02, // /
	0x00, 0x36, 0x36, 0x00, 0x00, // :
	0x00, 0x56, 0x36, 0x00, 0x00, // ;
	0x08, 0x14, 0x22, 0x41, 0x00, // <
	0x14, 0x14, 0x14, 0x14, 0x14, // =
	0x00, 0x41, 0x22, 0x14, 0x08, // >
	0x02, 0x01, 0x51, 0x09, 0x06, // ?
	0x32, 0x49, 0x79, 0x41, 0x3E, // @
	0x00, 0x7F, 0x41, 0x41, 0x00, // [
	0x02, 0x04, 0x08, 0x10, 0x20, // "\"
	0x00, 0x41, 0x41, 0x7F, 0x00, // ]
	0x04, 0x02, 0x01, 0x02, 0x04, // ^
	0x40, 0x40, 0x40, 0x40, 0x40, // _
	0x00, 0x01, 0x02, 0x04, 0x00, // `
	0x00, 0x08, 0x36, 0x41, 0x00, // {
	0x00, 0x00, 0x7F, 0x00, 0x00, // |
	0x00, 0x41, 0x36, 0x08, 0x00, // }

/************************Numeros*******************************************/
	0x3E, 0x41, 0x41, 0x41, 0x3E, // 0
	0x00, 0x42, 0x7F, 0x40, 0x00, // 1
	0x42, 0x61, 0x51, 0x49, 0x46, // 2
	0x21, 0x41, 0x45, 0x4B, 0x31, // 3
	0x18, 0x14, 0x12, 0x7F, 0x10, // 4
	0x27, 0x45, 0x45, 0x45, 0x39, // 5
	0x3C, 0x4A, 0x49, 0x49, 0x30, // 6
	0x01, 0x71, 0x09, 0x05, 0x03, // 7
	0x36, 0x49, 0x49, 0x49, 0x36, // 8
	0x06, 0x49, 0x49, 0x29, 0x1E, // 9
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

void enviar_trama(uint8_t fila, uint32_t datos) {
    // Suponiendo que los datos se envían por bits, MSB primero
    for (int i = tabla - 1; i >= 0; i--) {
        // Ajustar el bit correspondiente en el puerto de salida
        if (datos & (1 << i)) {
            // Establecer el bit a 1
            PORTB |= (1 << i);
        } else {
            // Establecer el bit a 0
            PORTB &= ~(1 << i);
        }
    }

    // Enviar el byte correspondiente a la fila
    // (Adaptar esta parte según el hardware específico)
    PORTB = fila;

    // Introducir un retardo (opcional)
    // delay_ms(1);
}

int main() {
    // Enviar la secuencia a todas las filas
    for (int i = 0; i < tabla i++) {
        enviar_trama(i, 0xDEADBEEF);
    }

    return 0;
}
void Multiplexado()
