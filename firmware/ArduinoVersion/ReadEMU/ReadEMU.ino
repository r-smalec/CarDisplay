#include "EMUSerial.h"

HardwareSerial EMU_serial(PA10, PA9);

EMUSerial emu(EMU_serial);

void setup()
{
	Serial.begin(9600); //Debugging
	EMU_serial.begin(19200); //EMU Serial setup, 8 Data Bits 1 Stopbit, RX Pin, TX Pin
  Serial.println("Hejka");
}

void loop()
{
  // Serial.println("dupa");
  // delay(500);
  // if(EMU_serial.available())
  //   Serial.println(EMU_serial.read());
	
  emu.checkEmuSerial();

  Serial.println("RPM");
	Serial.println(emu.emu_data.RPM);
  Serial.println("Batt");
	Serial.println(emu.emu_data.Batt);
  Serial.println("TPS");
  Serial.println(emu.emu_data.TPS);
  Serial.println("CLT");
  Serial.println(emu.emu_data.CLT);
  Serial.println("Oil T");
	Serial.println(emu.emu_data.oilTemperature);
  Serial.println("Oil P");
	Serial.println(emu.emu_data.oilPressure);
  Serial.println("IAT");
	Serial.println(emu.emu_data.IAT);
  Serial.println("MAP");
	Serial.println(emu.emu_data.MAP);
  Serial.println("------");
  delay(500);
}