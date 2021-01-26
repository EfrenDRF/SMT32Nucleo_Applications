/**
  ******************************************************************************
  * @file    _5_main_Arduino_slaveCfg.ino
  * @author  Efren Del Real
  * @Date    January 24th 2021
  * @version V1.0
  * @brief   Application - Arduino board is configured as SPI slave mode in order
  *                        to be able to receive a message from Nucleo board and 
  *                        display the SPI message into COM console.
  ******************************************************************************
*/

/*Include header files-------------------------*/
#include <SPI.h>
#include<stdint.h>

/*Macor definition ----------------------------*/
#define SPI_SCK      13
#define SPI_MOSI     11
#define SPI_SS       10

/*Local function declaration ------------------*/
static void vSPI_SlaveInit(void);

/*Local variables declaration------------------*/
uint8_t u8RxDataBuff[100];
uint8_t u8Index = 0u;
uint8_t u8DataLen = 0u;
boolean boolRxDataFlag = false;



// The setup() function runs right after reset.
void setup() 
{
  // Initialize serial communication
  Serial.begin(115200);
  
  // Initialize SPI Slave.
  vSPI_SlaveInit();
  
}

// The loop function runs continuously after setup().
void loop() 
{

  // .- Execute whether the Rx data is already received.
  if(boolRxDataFlag == true)
  {
    boolRxDataFlag = false;
    u8RxDataBuff[u8Index] = '\0';
  
    // .- Display Rx data in console.
    Serial.print("Length: ");
    Serial.println(u8DataLen);
    Serial.print("RxData: ");
    Serial.println((char*)u8RxDataBuff);
    
    // .- Cleans buffer and index.
    memset(u8RxDataBuff, 0u, sizeof(u8RxDataBuff));
    u8Index = 0u;
  }

}


// SPI interrupt routine
ISR (SPI_STC_vect)
{
 static uint8_t u8sDataLen  = 0u;
 uint8_t u8RxData = SPDR;  // grab byte from SPI Data Register


  if(u8sDataLen > 0)
  {
    u8RxDataBuff[u8Index++] = u8RxData;
    u8sDataLen--;
    
    if(u8sDataLen == 0)
    {
      // .- Rx data is completed.
      boolRxDataFlag = true;
    }
  }
  else if((u8RxData & 0xC0) == 0xC0)
  {
   u8sDataLen = u8RxData & 0x3F;
   u8DataLen  = u8sDataLen;
  }
  


}  // end of interrupt routine SPI_STC_vect


/*
 *
 */
static void vSPI_SlaveInit(void) 
{ 
  pinMode(SCK, INPUT);
  pinMode(MOSI, INPUT);
  pinMode(SS, INPUT);
  
  // Enable SPI as slave.
  SPCR = (1 << SPE);
  SPI.attachInterrupt();
  Serial.println("SPI has been configured as slave successfully.");
}

/********************************* END OF FILE **************************************************************************/

