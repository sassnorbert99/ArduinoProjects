#include <LiquidCrystal_I2C.h>
/**vcc LCD pin at 5V
  *Gnd LCD pin at 0V
  *SDA to SDA arduino board
  *SCL to SCL arduino board
*/

#include <Wire.h>
LiquidCrystal_I2C lcd(0x27,16,2);

const int inPin = 0; // analog pin      //Declare pin where we have connect input signal
void setup()
{
  lcd.begin(16,2);                      //LCD screen initialization
  
  lcd.backlight();
  lcd.print("V");
  lcd.setCursor(1,0);
  lcd.print("o");
  lcd.setCursor(2,0);
  lcd.print("l");
  lcd.setCursor(3,0);
  lcd.print("t");
  lcd.setCursor(4,0);
  lcd.print("a");
  lcd.setCursor(5,0);
  lcd.print("g");
  lcd.setCursor(6,0);
  lcd.print("e");
  lcd.setCursor(7,0);
  lcd.print(":");
  lcd.setCursor(0,1);
  lcd.print("k");
  lcd.setCursor(1,1);
  lcd.print("W");
  lcd.setCursor(2,1);
  lcd.print(":");
}

void loop()
{
  lcd.display();
  int value = analogRead(inPin);         //Read the signal at pin A0 and result put on variable value
  
  float volts = (value / 1024.0) * 5;    //Convert 1024 levels in Volts value
  float amper = 0.52;
  float kW = (volts * amper) / 1000;

  
  lcd.setCursor(10,0);                   //Put the cursor at second row and the first column
  lcd.print(volts);                      //Print volts value
  lcd.print("V");                       //print V symbol
  lcd.setCursor(6,1);                   //Put the cursor at second row and the first column
  lcd.print(kW, 6);
  lcd.print("k");
  lcd.print("W");
  delay(500);


}
