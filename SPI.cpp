

#define SPI_COMMAND_0 ((unsigned int *)0x03210000)
#define SPI_TX_DATA_0 ((unsigned int *)0x03210018) //TX data buffer voor SPI
#define SPI_TX_FIFO_0 ((unsigned int *)0x03210108) //TX data fifo voor SPI, schrijf hier heen?

#include <iostream>
#include "stdio.h"
using namespace std;

void initSPI();
void writeSPI(unsigned short adress, unsigned short data);

int main() {


	initSPI();

	while (1) {
		SPI_TX_DATA_0 |= 0xCC;
	}
	return 0;
}

 
void initSPI() {                     //set SPI_COMMAND_0 bits:

	SPI_COMMAND_0 |= (1 << 30);   //1 master mode
	SPI_COMMAND_0 &= ~(1 << 29);   //29:28   default (0)
	SPI_COMMAND_0 &= ~(1 << 26);   //27:26   chip select (configure in software)
	SPI_COMMAND_0 |= (1 << 25);   //1 high (slave is low active)
	SPI_COMMAND_0 |= (1 << 24);   //1 high (slave is low active)
	SPI_COMMAND_0 |= (1 << 23);   //1 high (slave is low active)
	SPI_COMMAND_0 |= (1 << 22);   //1 high (slave is low active)
	SPI_COMMAND_0 &= ~(1 << 21);   //0 low (controlled by software hoeft niet te veranderen)
	SPI_COMMAND_0 |= (1 << 19);   //19:18   ligt aan de SPI device nu is het low
	SPI_COMMAND_0 &= ~(1 << 17);   //0 normal mode
	SPI_COMMAND_0 &= ~(1 << 16);   //ligt aan device (waarschijnlijk 0)
	SPI_COMMAND_0 &= ~(1 << 15);   //ligt aan device (waarschijnlijk 0)
	SPI_COMMAND_0 &= ~(1 << 14);   //0
	SPI_COMMAND_0 &= ~(1 << 13);   //0
	SPI_COMMAND_0 &= ~(1 << 12);   //0 disable receive
	SPI_COMMAND_0 |= (1 << 11);   //1 enable transmitting
	SPI_COMMAND_0 &= ~(1 << 15);   //0 disable
	SPI_COMMAND_0 |= (16 << 0);    //4:0     ligt aan device (waarschijnlijk 8)
	SPI_COMMAND_0 |= (1 << 31);   //1 dit moest als laatste     

}

void writeSPI(unsigned short adress, unsigned short data) {

	SPI_TX_DATA_0 = adress;
	SPI_TX_DATA_0 = data;

}

void WriteIOpin(unsigned short pin, bool state) {



}

void WriteAllPins(unsigned short data) {



}
\
/*PSEUDOCODE IO EXPANDER
IODIRA	adrr = 0x00;	1 = input 0 = output
IODIRB	adrr = 0x10;	1 = input 0 = output
IOCON	adrr = 0x05;	= B0
GPIO	adrr = 0x09;	1 = high, 0 = low
OLAT	adrr = 0x0A;	data = 0xFF

*/



