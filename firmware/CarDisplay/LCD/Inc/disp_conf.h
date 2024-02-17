#ifndef _DISP_CONFIG_H_
#define _DISP_CONFIG_H_

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>		//itoa()
#include "Debug.h"
#include "main.h"

#define DISP_RST_PIN     	D3_DISP_RST_GPIO_Port, D3_DISP_RST_Pin
#define DISP_DC_PIN      	D4_DISP_DC_GPIO_Port, D4_DISP_DC_Pin
#define DISP_CS_PIN			A3_DISP_CS_GPIO_Port, A3_DISP_CS_Pin
#define DISP_BL_PIN			D2_DISP_BL_GPIO_Port, D2_DISP_BL_Pin

extern SPI_HandleTypeDef hspi3;

#define DISP_HEIGHT 240
#define DISP_WIDTH 240

#define HORIZONTAL 0
#define VERTICAL   1

void DISP_SendCommand(uint8_t reg);
void DISP_SendData_8Bit(uint8_t data);
void DISP_SendData_16Bit(uint16_t data);

void DISP_Init(uint8_t Scan_dir);
void DISP_Exit(void);

void DISP_SetCursor(uint16_t Xstart, uint16_t Ystart, uint16_t Xend, uint16_t Yend);

void DISP_Clear(uint16_t Color);
void DISP_Display(uint16_t *Image);
void DISP_DisplayWindows(uint16_t Xstart, uint16_t Ystart, uint16_t Xend, uint16_t Yend, uint16_t *Image);

void DISP_DrawPaint(uint16_t x, uint16_t y, uint16_t Color);
void DISP_SetBackLight(uint8_t Value);

#endif
