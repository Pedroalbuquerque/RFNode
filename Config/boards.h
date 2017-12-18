//*************************************************
//        Board specific defs
//*************************************************


//    Moteino & Moteino Mega

/*
D2 (int0), D10(SS) D11-13 (SPI) used by RF module
D8(SS) D11-13 (SPI) used by Flash (4Mbit = 512KByte)
*/


#ifdef BOARD_MOTEINO

#define LED 9

#define TX 1
#define RX 0

#define int1  3

#define PWM1  5
#define PWM2  6
//#define PWM3  D6

#define ANA0  14
#define ANA1  15
#define ANA2  16
#define ANA3  17
#define ANA4  18
#define ANA5  19
#define ANA6  A6
#define ANA7  A7

#define SPI_MOSI  11
#define SPI_MISO  12
#define SPI_SCK   13

#define I2C_SCL   19
#define I2C_SDA   18

#endif  // Moteino
