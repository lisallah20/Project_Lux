#define LDR 35
#define MAX_ADC_READING 4095
#define ADC_REF_VOLTAGE 5.0
#define REF_RESISTANCE 10000
#define LUX_CALC_SCALAR 0.730027001
#define LUX_CALC_EXPONENT 0.611586353
#include <LiquidCrystal_I2C.h>

int lcdColumns = 16;
int lcdRows = 2;
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);  

void setup() {
  lcd.begin();                     
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("PROJEK KELAS");
  lcd.setCursor(0, 1);
  lcd.print("2 D4 TELKOM B");
  Serial.begin(9600);
  delay (2000);
  lcd.clear();
}
void loop() {
  int ldrRawData;
  float resistorVoltage, ldrVoltage;
  float ldrResistance;
  float ldrLux;
  ldrRawData = analogRead(LDR);   //Baca sensor
  //------------Konversi  dari data analog ke nilai lux------------//
  resistorVoltage = (float)ldrRawData / MAX_ADC_READING * ADC_REF_VOLTAGE;
  ldrVoltage = ADC_REF_VOLTAGE - resistorVoltage;
  ldrResistance = ldrVoltage / resistorVoltage * REF_RESISTANCE;
  ldrLux = LUX_CALC_SCALAR * pow(ldrResistance, LUX_CALC_EXPONENT);
  lcd.setCursor(0,0);
  lcd.print("LUX : ");
  Serial.print("Intensitas Cahaya : ");
  lcd.println(ldrLux);
  Serial.print(ldrLux);    
  Serial.println(" Lux");
  int LDR_val = analogRead(LDR);
  lcd.setCursor(0, 0);
  lcd.print("Nilai ADC = ");
  lcd.println(LDR_val);
  Serial.println(LDR_val);
  delay(1000);
}
