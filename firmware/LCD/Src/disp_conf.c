#include "disp_conf.h"

static void DISP_Reset(void) {

	HAL_GPIO_WritePin(DISP_RST_PIN, GPIO_PIN_SET);
    HAL_Delay(100);
    HAL_GPIO_WritePin(DISP_RST_PIN, GPIO_PIN_RESET);
    HAL_Delay(100);
    HAL_GPIO_WritePin(DISP_RST_PIN, GPIO_PIN_SET);
    HAL_Delay(100);
}

static void DISP_SPI_send(uint8_t data) {
	HAL_SPI_Transmit(&hspi3, &data, 1, 100);
}

void DISP_SendCommand(uint8_t reg) {

	HAL_GPIO_WritePin(DISP_CS_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(DISP_DC_PIN, GPIO_PIN_RESET);
	DISP_SPI_send(reg);
}

void DISP_SendData_8Bit(uint8_t data) {
	HAL_GPIO_WritePin(DISP_CS_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(DISP_DC_PIN, GPIO_PIN_SET);
	DISP_SPI_send(data);
    HAL_GPIO_WritePin(DISP_CS_PIN, GPIO_PIN_SET);
}

void DISP_SendData_16Bit(uint16_t data) {

	uint8_t data_h = (uint8_t)(data >> 8);
	uint8_t data_l = (uint8_t) data;

	HAL_GPIO_WritePin(DISP_CS_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(DISP_DC_PIN, GPIO_PIN_SET);
	DISP_SPI_send(data_h);
	DISP_SPI_send(data_l);
    HAL_GPIO_WritePin(DISP_CS_PIN, GPIO_PIN_SET);
}

static void DISP_SetAttributes(uint8_t Scan_dir) {

    //Get the screen scan direction
    uint8_t MemoryAccessReg = 0x08;

    //Get GRAM and LCD width and height
    if(Scan_dir == HORIZONTAL) {
        MemoryAccessReg = 0XC8;
    } else {
        MemoryAccessReg = 0X68;
    }

    // Set the read / write scan direction of the frame memory
    DISP_SendCommand(0x36); //MX, MY, RGB mode
    DISP_SendData_8Bit(MemoryAccessReg);	//0x08 set RGB
}

static void DISP_InitReg(void) {

	DISP_SendCommand(0xEF);
	DISP_SendCommand(0xEB);
	DISP_SendData_8Bit(0x14);

	DISP_SendCommand(0xFE);
	DISP_SendCommand(0xEF);

	DISP_SendCommand(0xEB);
	DISP_SendData_8Bit(0x14);

	DISP_SendCommand(0x84);
	DISP_SendData_8Bit(0x40);

	DISP_SendCommand(0x85);
	DISP_SendData_8Bit(0xFF);

	DISP_SendCommand(0x86);
	DISP_SendData_8Bit(0xFF);

	DISP_SendCommand(0x87);
	DISP_SendData_8Bit(0xFF);

	DISP_SendCommand(0x88);
	DISP_SendData_8Bit(0x0A);

	DISP_SendCommand(0x89);
	DISP_SendData_8Bit(0x21);

	DISP_SendCommand(0x8A);
	DISP_SendData_8Bit(0x00);

	DISP_SendCommand(0x8B);
	DISP_SendData_8Bit(0x80);

	DISP_SendCommand(0x8C);
	DISP_SendData_8Bit(0x01);

	DISP_SendCommand(0x8D);
	DISP_SendData_8Bit(0x01);

	DISP_SendCommand(0x8E);
	DISP_SendData_8Bit(0xFF);

	DISP_SendCommand(0x8F);
	DISP_SendData_8Bit(0xFF);


	DISP_SendCommand(0xB6);
	DISP_SendData_8Bit(0x00);
	DISP_SendData_8Bit(0x20);

	DISP_SendCommand(0x36);
	DISP_SendData_8Bit(0x08);//Set as vertical screen

	DISP_SendCommand(0x3A);
	DISP_SendData_8Bit(0x05);


	DISP_SendCommand(0x90);
	DISP_SendData_8Bit(0x08);
	DISP_SendData_8Bit(0x08);
	DISP_SendData_8Bit(0x08);
	DISP_SendData_8Bit(0x08);

	DISP_SendCommand(0xBD);
	DISP_SendData_8Bit(0x06);

	DISP_SendCommand(0xBC);
	DISP_SendData_8Bit(0x00);

	DISP_SendCommand(0xFF);
	DISP_SendData_8Bit(0x60);
	DISP_SendData_8Bit(0x01);
	DISP_SendData_8Bit(0x04);

	DISP_SendCommand(0xC3);
	DISP_SendData_8Bit(0x13);
	DISP_SendCommand(0xC4);
	DISP_SendData_8Bit(0x13);

	DISP_SendCommand(0xC9);
	DISP_SendData_8Bit(0x22);

	DISP_SendCommand(0xBE);
	DISP_SendData_8Bit(0x11);

	DISP_SendCommand(0xE1);
	DISP_SendData_8Bit(0x10);
	DISP_SendData_8Bit(0x0E);

	DISP_SendCommand(0xDF);
	DISP_SendData_8Bit(0x21);
	DISP_SendData_8Bit(0x0c);
	DISP_SendData_8Bit(0x02);

	DISP_SendCommand(0xF0);
	DISP_SendData_8Bit(0x45);
	DISP_SendData_8Bit(0x09);
	DISP_SendData_8Bit(0x08);
	DISP_SendData_8Bit(0x08);
	DISP_SendData_8Bit(0x26);
 	DISP_SendData_8Bit(0x2A);

 	DISP_SendCommand(0xF1);
 	DISP_SendData_8Bit(0x43);
 	DISP_SendData_8Bit(0x70);
 	DISP_SendData_8Bit(0x72);
 	DISP_SendData_8Bit(0x36);
 	DISP_SendData_8Bit(0x37);
 	DISP_SendData_8Bit(0x6F);


 	DISP_SendCommand(0xF2);
 	DISP_SendData_8Bit(0x45);
 	DISP_SendData_8Bit(0x09);
 	DISP_SendData_8Bit(0x08);
 	DISP_SendData_8Bit(0x08);
 	DISP_SendData_8Bit(0x26);
 	DISP_SendData_8Bit(0x2A);

 	DISP_SendCommand(0xF3);
 	DISP_SendData_8Bit(0x43);
 	DISP_SendData_8Bit(0x70);
 	DISP_SendData_8Bit(0x72);
 	DISP_SendData_8Bit(0x36);
 	DISP_SendData_8Bit(0x37);
 	DISP_SendData_8Bit(0x6F);

	DISP_SendCommand(0xED);
	DISP_SendData_8Bit(0x1B);
	DISP_SendData_8Bit(0x0B);

	DISP_SendCommand(0xAE);
	DISP_SendData_8Bit(0x77);

	DISP_SendCommand(0xCD);
	DISP_SendData_8Bit(0x63);


	DISP_SendCommand(0x70);
	DISP_SendData_8Bit(0x07);
	DISP_SendData_8Bit(0x07);
	DISP_SendData_8Bit(0x04);
	DISP_SendData_8Bit(0x0E);
	DISP_SendData_8Bit(0x0F);
	DISP_SendData_8Bit(0x09);
	DISP_SendData_8Bit(0x07);
	DISP_SendData_8Bit(0x08);
	DISP_SendData_8Bit(0x03);

	DISP_SendCommand(0xE8);
	DISP_SendData_8Bit(0x34);

	DISP_SendCommand(0x62);
	DISP_SendData_8Bit(0x18);
	DISP_SendData_8Bit(0x0D);
	DISP_SendData_8Bit(0x71);
	DISP_SendData_8Bit(0xED);
	DISP_SendData_8Bit(0x70);
	DISP_SendData_8Bit(0x70);
	DISP_SendData_8Bit(0x18);
	DISP_SendData_8Bit(0x0F);
	DISP_SendData_8Bit(0x71);
	DISP_SendData_8Bit(0xEF);
	DISP_SendData_8Bit(0x70);
	DISP_SendData_8Bit(0x70);

	DISP_SendCommand(0x63);
	DISP_SendData_8Bit(0x18);
	DISP_SendData_8Bit(0x11);
	DISP_SendData_8Bit(0x71);
	DISP_SendData_8Bit(0xF1);
	DISP_SendData_8Bit(0x70);
	DISP_SendData_8Bit(0x70);
	DISP_SendData_8Bit(0x18);
	DISP_SendData_8Bit(0x13);
	DISP_SendData_8Bit(0x71);
	DISP_SendData_8Bit(0xF3);
	DISP_SendData_8Bit(0x70);
	DISP_SendData_8Bit(0x70);

	DISP_SendCommand(0x64);
	DISP_SendData_8Bit(0x28);
	DISP_SendData_8Bit(0x29);
	DISP_SendData_8Bit(0xF1);
	DISP_SendData_8Bit(0x01);
	DISP_SendData_8Bit(0xF1);
	DISP_SendData_8Bit(0x00);
	DISP_SendData_8Bit(0x07);

	DISP_SendCommand(0x66);
	DISP_SendData_8Bit(0x3C);
	DISP_SendData_8Bit(0x00);
	DISP_SendData_8Bit(0xCD);
	DISP_SendData_8Bit(0x67);
	DISP_SendData_8Bit(0x45);
	DISP_SendData_8Bit(0x45);
	DISP_SendData_8Bit(0x10);
	DISP_SendData_8Bit(0x00);
	DISP_SendData_8Bit(0x00);
	DISP_SendData_8Bit(0x00);

	DISP_SendCommand(0x67);
	DISP_SendData_8Bit(0x00);
	DISP_SendData_8Bit(0x3C);
	DISP_SendData_8Bit(0x00);
	DISP_SendData_8Bit(0x00);
	DISP_SendData_8Bit(0x00);
	DISP_SendData_8Bit(0x01);
	DISP_SendData_8Bit(0x54);
	DISP_SendData_8Bit(0x10);
	DISP_SendData_8Bit(0x32);
	DISP_SendData_8Bit(0x98);

	DISP_SendCommand(0x74);
	DISP_SendData_8Bit(0x10);
	DISP_SendData_8Bit(0x85);
	DISP_SendData_8Bit(0x80);
	DISP_SendData_8Bit(0x00);
	DISP_SendData_8Bit(0x00);
	DISP_SendData_8Bit(0x4E);
	DISP_SendData_8Bit(0x00);

	DISP_SendCommand(0x98);
	DISP_SendData_8Bit(0x3e);
	DISP_SendData_8Bit(0x07);

	DISP_SendCommand(0x35);
	DISP_SendCommand(0x21);

	DISP_SendCommand(0x11);
	HAL_Delay(120);
	DISP_SendCommand(0x29);
	HAL_Delay(20);
}

void DISP_Init(uint8_t Scan_dir) {

    HAL_GPIO_WritePin(DISP_DC_PIN, GPIO_PIN_SET);
    HAL_GPIO_WritePin(DISP_CS_PIN, GPIO_PIN_SET);
    HAL_GPIO_WritePin(DISP_RST_PIN, GPIO_PIN_SET);
    HAL_GPIO_WritePin(DISP_BL_PIN, GPIO_PIN_SET);

    DISP_Reset();
    DISP_SetAttributes(Scan_dir);
    DISP_InitReg();

    DISP_SetBackLight(1);
}

void DISP_Exit(void) {

    HAL_GPIO_WritePin(DISP_DC_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(DISP_CS_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(DISP_RST_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(DISP_BL_PIN, GPIO_PIN_RESET);
}

/********************************************************************************
function:	Sets the start position and size of the display area
parameter:
		Xstart 	:   X direction Start coordinates
		Ystart  :   Y direction Start coordinates
		Xend    :   X direction end coordinates
		Yend    :   Y direction end coordinates
********************************************************************************/
void DISP_SetCursor(uint16_t Xstart, uint16_t Ystart, uint16_t Xend, uint16_t Yend) {

    //set the X coordinates
    DISP_SendCommand(0x2A);
    DISP_SendData_8Bit(0x00);
    DISP_SendData_8Bit(Xstart);
    DISP_SendData_8Bit(0x00);
    DISP_SendData_8Bit(Xend);

    //set the Y coordinates
    DISP_SendCommand(0x2B);
    DISP_SendData_8Bit(0x00);
    DISP_SendData_8Bit(Ystart);
    DISP_SendData_8Bit(0x00);
    DISP_SendData_8Bit(Yend);

    DISP_SendCommand(0X2C);
}

void DISP_Clear(uint16_t Color) {

    uint16_t i,j;
    DISP_SetCursor(0, 0, DISP_WIDTH-1, DISP_HEIGHT-1);

    HAL_GPIO_WritePin(DISP_DC_PIN, GPIO_PIN_SET);
	for(i = 0; i < DISP_WIDTH; i++){
		for(j = 0; j < DISP_HEIGHT; j++){
			DISP_SPI_send(Color>>8);
			DISP_SPI_send(Color);
		}
	 }
}

void DISP_Display(uint16_t *Image) {

    uint16_t i,j;
    DISP_SetCursor(0, 0, DISP_WIDTH-1, DISP_HEIGHT-1);
    HAL_GPIO_WritePin(DISP_DC_PIN, GPIO_PIN_SET);
    for(i = 0; i < DISP_WIDTH; i++){
      for(j = 0; j < DISP_HEIGHT; j++){
        DISP_SPI_send((*Image+i*DISP_WIDTH+j)>>8);
        DISP_SPI_send(*(Image+i*DISP_WIDTH+j));
      }
    }
}

void DISP_DisplayWindows(uint16_t Xstart, uint16_t Ystart, uint16_t Xend, uint16_t Yend, uint16_t *Image) {

    // display
    uint32_t Addr = 0;

    uint16_t i,j;
    DISP_SetCursor(Xstart, Ystart, Xend-1 , Yend-1);
    HAL_GPIO_WritePin(DISP_DC_PIN, GPIO_PIN_SET);
    for (i = Ystart; i < Yend - 1; i++) {
        Addr = Xstart + i * DISP_WIDTH ;
        for(j=Xstart;j<Xend-1;j++){
          DISP_SPI_send(*(Image+Addr+j)>>8);
          DISP_SPI_send(*(Image+Addr+j));
        }
    }
}

/******************************************************************************
function: Draw a point
parameter	:
	    X	: 	Set the X coordinate
	    Y	:	Set the Y coordinate
	  Color :	Set the color
******************************************************************************/
void DISP_DrawPaint(uint16_t x, uint16_t y, uint16_t Color)
{
	DISP_SetCursor(x,y,x,y);
	DISP_SendData_16Bit(Color);
}


void DISP_SetBackLight(uint8_t Value) {

	HAL_GPIO_WritePin(DISP_BL_PIN, Value);
}
