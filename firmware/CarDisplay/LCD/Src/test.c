#include "image.h"
#include "test.h"
#include "disp_conf.h"


void DISP_test() {

	printf("DISP_test Demo\r\n");
	DISP_Init(VERTICAL);
  
	printf("DISP_ Init and Clear...\r\n");
 	DISP_Clear(BLACK);
	
	printf("DISP_NewImage\r\n");
	DISP_NewImage(DISP_WIDTH,DISP_HEIGHT, 0, BLACK);
	
	printf("Set Clear and Display Funtion\r\n");

	printf("DISP_Clear\r\n");
	DISP_Clear(BLACK);
	HAL_Delay(100);
	
	printf("drawing...\r\n");
	
	DISP_DrawCircle(120,120, 120, BLUE ,DOT_PIXEL_2X2,DRAW_FILL_EMPTY);
	DISP_DrawLine  (120, 0, 120, 12,GREEN ,DOT_PIXEL_4X4,LINE_STYLE_SOLID);
    DISP_DrawLine  (120, 228, 120, 240,GREEN ,DOT_PIXEL_4X4,LINE_STYLE_SOLID);
    DISP_DrawLine  (0, 120, 12, 120,GREEN ,DOT_PIXEL_4X4,LINE_STYLE_SOLID);
    DISP_DrawLine  (228, 120, 240, 120,GREEN ,DOT_PIXEL_4X4,LINE_STYLE_SOLID);

  //DISP_DrawImage(gImage_70X70, 85, 25, 70, 70);
    DISP_DrawString(123, 123, "WAVESHARE",&Font16,  BLACK, GREEN);
	
	DISP_DrawLine  (120, 120, 70, 70,YELLOW ,DOT_PIXEL_3X3,LINE_STYLE_SOLID);
	DISP_DrawLine  (120, 120, 176, 64,BLUE ,DOT_PIXEL_3X3,LINE_STYLE_SOLID);
	DISP_DrawLine  (120, 120, 120, 210,RED ,DOT_PIXEL_2X2,LINE_STYLE_SOLID);
	HAL_Delay(1000);

	printf("quit...\r\n");
	DISP_Exit();
}

