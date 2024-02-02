#ifndef _DEV_CONFIG_H_
#define _DEV_CONFIG_H_

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>		//itoa()
#include "Debug.h"
#include "main.h"

#define DEV_RST_PIN     	DISP_RST_GPIO_Port, DISP_RST_Pin
#define DEV_DC_PIN      	DISP_DC_GPIO_Port, DISP_DC_Pin
#define DEV_CS_PIN			DISP_CS_GPIO_Port, DISP_CS_Pin
#define DEV_BL_PIN			DISP_BL_GPIO_Port, DISP_BL_Pin

SPI_HandleTypeDef *_hspi;


#define DISP_HEIGHT 240
#define DISP_WIDTH 240

#define HORIZONTAL 0
#define VERTICAL   1

void DISP_Init(SPI_HandleTypeDef *hspi, uint8_t Scan_dir);
void DISP_Exit(void);
void DISP_Reset(void);
void DISP_SendCommand(uint8_t reg);
void DISP_SendData_8Bit(uint8_t data);
void DISP_SendData_16Bit(uint16_t data);

void DISP_Clear(uint16_t Color);
void DISP_Display(uint16_t *Image);
void DISP_DisplayWindows(uint16_t Xstart, uint16_t Ystart, uint16_t Xend, uint16_t Yend, uint16_t *Image);
void DISP_DisplayPoint(uint16_t X, uint16_t Y, uint16_t Color);

void DISP_DrawPaint(uint16_t x, uint16_t y, uint16_t Color);
void DISP_SetBackLight(uint8_t Value);

#endif
