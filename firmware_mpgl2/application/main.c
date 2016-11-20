/***********************************************************************************************************************
File: main.c                                                                

Description: The main function for the board. Should be where the OS (?) exists, might 
just be a while(1) loop


Restarted by Alex Mildenberger
October 23, 2016

***********************************************************************************************************************/

#include "configuration.h"

#define PIOA_PDR_INIT (u32)0x1BDCFE00
#define PIOB_PDR_INIT (u32)0x00400018

#define PIOA_OER_INIT (u32)0xBF55D7D5
#define PIOB_OER_INIT (u32)0x019FF566

#define PIOA_ODR_INIT (u32)0x40AA282A
#define PIOB_ODR_INIT (u32)0x00400A99

#define PIOA_IFER_INIT (u32)0x00000000
#define PIOB_IFER_INIT (u32)0x00000000

#define PIOA_IFDR_INIT (u32)0x00000000
#define PIOB_IFDR_INIT (u32)0x00000000

#define PIOA_SODR_INIT (u32)0x88010000
#define PIOB_SODR_INIT (u32)0x01A1D000

#define PIOA_CODR_INIT (u32)0x340001D5
#define PIOB_CODR_INIT (u32)0x001E2566

#define PIOA_MDER_INIT (u32)0x00000600
#define PIOB_MDER_INIT (u32)0x00000000

#define PIOA_MDDR_INIT (u32)0xFFFFF9FF
#define PIOB_MDDR_INIT (u32)0x01DFFFFF

#define PIOA_PPUDR_INIT (u32)0xFFFFFFFF
#define PIOB_PPUDR_INIT (u32)0x01DFFFFF

#define PIOA_PPUER_INIT (u32)0x00000000
#define PIOB_PPUER_INIT (u32)0x00200000

#define PIOA_ABSR_INIT (u32)0x1B000000
#define PIOB_ABSR_INIT (u32)0x00400018

#define PIOA_SCIFSR_INIT (u32)0x00000000
#define PIOB_SCIFSR_INIT (u32)0x00000000

#define PIOA_DIFSR_INIT (u32)0x00000000
#define PIOB_DIFSR_INIT (u32)0x00000000

#define PIOA_SCDR_INIT (u32)0x00000000
#define PIOB_SCDR_INIT (u32)0x00000000

#define PIOA_OWER_INIT (u32)0xB40101FF
#define PIOB_OWER_INIT (u32)0x01FFFE6

#define PIOA_OWDR_INIT (u32)0x000000000
#define PIOB_OWDR_INIT (u32)0x00000000

#define REGISTER_DISABLE ( (unsigned long int)0x00000000) 
void main(void)
{
  
  typedef volatile u32* register_address;

 // register_address PIOB_WriteProtect;
 // register_address PIOB_Enable_Register;
 // register_address PIOB_OutputEnable_Register;
 // register_address PIOB_ClearOutputData_Register;
 // register_address PIOB_SetOutputData_Register;
    
  // Save the register addresses
  //PIOB_WriteProtect = (register_address)0x400E0EE4; // write protect register address
  
  AT91C_BASE_PIOA->PIO_PER      =       ( 0x240001C0 );
  AT91C_BASE_PIOB->PIO_PER      =       ( 0x001E2006 ); // 0x400e0e00
  
  AT91C_BASE_PIOA->PIO_PDR      =       (REGISTER_DISABLE);
  AT91C_BASE_PIOB->PIO_PDR      =       (REGISTER_DISABLE);
    
  AT91C_BASE_PIOA->PIO_OER      =       ( 0x240001C0 );
  AT91C_BASE_PIOB->PIO_OER      =       ( 0x001E2006 ); // 0x400e010
  
  AT91C_BASE_PIOA->PIO_ODR      =       ( REGISTER_DISABLE );
  AT91C_BASE_PIOB->PIO_ODR      =       ( REGISTER_DISABLE );
  
  AT91C_BASE_PIOA->PIO_IFER     =       (REGISTER_DISABLE);
  AT91C_BASE_PIOB->PIO_IFER     =       (REGISTER_DISABLE); 
  
  AT91C_BASE_PIOA->PIO_IFDR     =       (REGISTER_DISABLE);
  AT91C_BASE_PIOB->PIO_IFDR     =       (REGISTER_DISABLE);
  
  AT91C_BASE_PIOA->PIO_SODR     =       (REGISTER_DISABLE);
  AT91C_BASE_PIOB->PIO_SODR     =       (REGISTER_DISABLE); // 0x400e0e28
  
  AT91C_BASE_PIOA->PIO_CODR     =       (REGISTER_DISABLE);
  AT91C_BASE_PIOB->PIO_CODR     =       ( 0x001E0000 );//(REGISTER_DISABLE); // 0x40030334
  
  AT91C_BASE_PIOA->PIO_MDER     =       (REGISTER_DISABLE);
  AT91C_BASE_PIOB->PIO_MDER     =       (REGISTER_DISABLE);
  
  AT91C_BASE_PIOA->PIO_MDDR     =       ( 0x240001C0 );
  AT91C_BASE_PIOB->PIO_MDDR     =       ( 0x001E2006 );
  
  AT91C_BASE_PIOA->PIO_PPUDR    =       ~(REGISTER_DISABLE);    
  AT91C_BASE_PIOB->PIO_PPUDR    =       ( 0x01DFFFFF );
  
  AT91C_BASE_PIOA->PIO_PPUER    =       (REGISTER_DISABLE);
  AT91C_BASE_PIOB->PIO_PPUER    =       (REGISTER_DISABLE);
  
  AT91C_BASE_PIOA->PIO_ABSR     =       (REGISTER_DISABLE);
  AT91C_BASE_PIOB->PIO_ABSR     =       (REGISTER_DISABLE);
  
  AT91C_BASE_PIOA->PIO_SCIFSR   =       REGISTER_DISABLE;
  AT91C_BASE_PIOB->PIO_SCIFSR   =       REGISTER_DISABLE;
  
  AT91C_BASE_PIOA->PIO_DIFSR    =       REGISTER_DISABLE;
  AT91C_BASE_PIOB->PIO_DIFSR    =       REGISTER_DISABLE;
  
  AT91C_BASE_PIOA->PIO_SCDR     =       REGISTER_DISABLE;
  AT91C_BASE_PIOB->PIO_SCDR     =       REGISTER_DISABLE;
  
  AT91C_BASE_PIOA->PIO_OWER     =       ( 0x240001C0 );
  AT91C_BASE_PIOB->PIO_OWER     =       ( 0x001E2006 );
  
  AT91C_BASE_PIOA->PIO_OWDR     =       REGISTER_DISABLE;
  AT91C_BASE_PIOB->PIO_OWDR     =       REGISTER_DISABLE;
  
  AT91C_BASE_PIOB->PIO_ODSR    =        0x00000000;
  
  
    while(1)
    {
      
    }
  
    
  
 
} /* end main() */