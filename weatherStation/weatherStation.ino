#include <LiquidCrystal_I2C.h>
#include <hd44780.h>
LiquidCrystal_I2C lcd(0x27,16,2); //címe a 0x27 16 karakteres és 2 sorban fog elhelyezkedni

byte degree_symbol[8] = //igy fog kinézni a fok jele
{
  0b00111,
  0b00101,
  0b00111,
  0b00000,
  0b00000,
  0b00000,
  0b00000 
};

int pin=11; //pin
volatile unsigned long duration=0;
unsigned char i[5];
unsigned int j[40];
unsigned char value=0;
unsigned answer=0;
int z=0;
int b=1;

void setup() {
  
  lcd.init(); //1.sor
  lcd.init(); //2.sor
  lcd.backlight();
  lcd.print("Hom  = ");
  lcd.setCursor(0,1); //bottom left
  lcd.print("Para = ");
  
  lcd.createChar(1, degree_symbol); //number, symbol
  lcd.setCursor(9,0); //1.sor 9. karaktere
  lcd.write(1);
  lcd.print("C");
  lcd.setCursor(10,1); //x=10, y=1
  lcd.print("%");

}

void loop() {
  
  
  lcd.display();
  delay(1000);
  while(1)
  {
    //delay(100);
    pinMode(pin,OUTPUT);
    digitalWrite(pin,LOW);
    delay(20);
    digitalWrite(pin,HIGH);
    pinMode(pin,INPUT_PULLUP); //magas lesz alapérelmezetten

    duration=pulseIn(pin,LOW);
    if(duration <= 84 && duration >= 72)
    {
      while(1)
      {
        duration=pulseIn(pin,HIGH);
        if(duration <= 26 && duration >= 20)
        {
          value=0;
        }
        else if(duration <= 74 && duration >= 65)
        {
          value=1;  
        }
        else if(z==40)
        {
          break;
        }
        i[z/8]|=value<<(7-(z%8)); //eltolom a biteket 7-(z%8)-al
        j[z]=value;
        z++;
      }
    }
    answer=i[0]+i[1]+i[2]+i[3];
    if(answer==i[4] && answer!=0)
    {
      lcd.setCursor(7,0);
      lcd.print(i[2]);
      lcd.setCursor(7,1);
      lcd.print(i[0]);
    }
    z=0; //kinullázom a z értékét is, hogy a következő ciklus lefutásnál ne az eddigi számokkal számoljon
    i[0]=i[1]=i[2]=i[3]=i[4]=0; //kinullázom az eddigi értékeket, hogy utána így tudjon számolni
  
  }
  
  

}
