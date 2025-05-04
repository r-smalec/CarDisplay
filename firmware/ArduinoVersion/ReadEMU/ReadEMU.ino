#include <SPI.h>
#include "LCD_Driver.h"
#include "GUI_Paint.h"
#include "image.h"

#include "EMUSerial.h"

void paramScreenDisplay();

HardwareSerial EMU_serial(PA10, PA9);

EMUSerial emu(EMU_serial);

void setup() {

	Serial.begin(9600);
	EMU_serial.begin(19200);

  Config_Init();
  LCD_Init();
  LCD_SetBacklight(1000);
  Paint_NewImage(240, 250, 0, BLACK);
  paramScreenDisplay();

  Serial.println("Board connected");
}

void loop() {
	
  emu.checkEmuSerial();

  Serial.print("CLT \t");
  Serial.println(emu.emu_data.CLT);
  Paint_DrawNum(105, 15, (int32_t)emu.emu_data.CLT, &Font24, BRRED, BLACK);
  if(emu.emu_data.CLT < 100){
    Paint_ClearWindows(105+2*17, 15, 105+3*17, 15+24, BLACK);
  }

  Serial.print("Batt \t");
	Serial.println(emu.emu_data.Batt);
  Paint_DrawNum(130, 85, (int32_t)emu.emu_data.Batt, &Font24, BLACK, BRRED);
  Paint_DrawString_EN(165, 85, ".", &Font24, BLACK, BRRED);
  int32_t batt_f = (int32_t)((float)(emu.emu_data.Batt - (int32_t)emu.emu_data.Batt) * 10);
  Paint_DrawNum(180, 85, batt_f, &Font24, BLACK, BRRED);

  Serial.print("Oil T \t");
	Serial.println(emu.emu_data.oilTemperature);
  Paint_DrawNum(40, 123, (int32_t)emu.emu_data.oilTemperature, &Font24, BRRED, BLACK);
  if(emu.emu_data.oilTemperature < 100){
    Paint_ClearWindows(40+2*17, 123, 40+3*17, 123+24, BLACK);
  }

  Serial.print("Oil P \t");
	Serial.println(emu.emu_data.oilPressure);
  Paint_DrawNum(160, 123, (int32_t)emu.emu_data.oilPressure, &Font24, BRRED, BLACK);
  Paint_DrawString_EN(175, 123, ".", &Font24, BRRED, BLACK);
  int32_t oil_p_f = (int32_t)((float)(emu.emu_data.oilPressure - (int32_t)emu.emu_data.oilPressure) * 10);
  Paint_DrawNum(190, 123, oil_p_f, &Font24, BRRED, BLACK);

  Serial.print("IAT \t");
	Serial.println(emu.emu_data.IAT);
  Paint_DrawNum(105, 203, (int32_t)emu.emu_data.IAT, &Font24, BLACK, BRRED);

  Serial.print("RPM \t");
	Serial.println(emu.emu_data.RPM);
  Serial.print("TPS \t");
  Serial.println(emu.emu_data.TPS);
  Serial.print("MAP \t");
	Serial.println(emu.emu_data.MAP);
  Serial.println("------------");
  delay(500);
}

void paramScreenDisplay() {

	Paint_Clear(BLACK);
	Paint_DrawString_EN(65, 42, "WATER oC", &Font20, BLACK, BRRED);
  Paint_DrawString_EN(25, 152, "OIL oC", &Font20, BLACK, BRRED);
	Paint_DrawString_EN(130, 152, "OIL bar", &Font20, BLACK, BRRED);
	Paint_DrawString_EN(25, 90, "BATT V", &Font20, BLACK, BRRED);
  Paint_DrawString_EN(75, 182, "IAT oC", &Font20, BLACK, BRRED);

  Paint_DrawLine(20, 65, 220, 65, BRRED, DOT_PIXEL_2X2, LINE_STYLE_SOLID);
	Paint_DrawLine(5, 115, 235, 115, BRRED, DOT_PIXEL_2X2, LINE_STYLE_SOLID);
	Paint_DrawLine(120, 115, 120, 176, BRRED, DOT_PIXEL_2X2, LINE_STYLE_SOLID);
	Paint_DrawLine(20, 176, 220, 176, BRRED, DOT_PIXEL_2X2, LINE_STYLE_SOLID);
	

}