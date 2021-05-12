#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
class House{
  
  public:
    int house_consume = 230;
};

class Flat{
  public:
    int flat_consume = 200;
};

class School{
  public:
      int students = 300;
      int square_school = 20;
      float school_size = 2.5 * students;
      float school_consume = square_school * school_size;
};

class Hospital{
  public:
      int patients = 100;
      int square_hospital = 100;
      float hospital_size = 6 * patients;
      float hospital_consume = square_hospital * hospital_size;
};
long total_consume = 0;



void setup() {                      
  lcd.init(); //1.sor
  lcd.init(); //2.sor
  lcd.backlight();
  lcd.print("kWh/m = ");
  lcd.setCursor(0,1); //bottom left
  lcd.print("kWh/d = ");
  
  Serial.begin(9600);
  

  int house_piece = 50;
  int flat_piece = 50;
  int school_piece = 1;
  int hospital_piece = 1;
  
  
  House houses[house_piece];
  Flat flats[flat_piece];
  School schools[school_piece];
  Hospital hospitals[hospital_piece];

  
  int house_length = 0;
  for (int i=1; i <= house_piece; i++){
    if (house_piece == 0){
      break;
    } else {
      houses[i] = House();
      house_length = i;
      total_consume += houses[i].house_consume;
    }
    
    
 }
 
 int flat_length = 0;
 for (int i=1; i <= flat_piece; i++){
  if (flat_piece == 0){
      break;
    }else {
      flats[i] = Flat();
      flat_length = i;
      total_consume += flats[i].flat_consume;
    }
    
 }
 int school_length = 0;
 for (int i=1; i <= school_piece; i++){
  if (school_piece == 0){
      break;
    } else {
      schools[i] = School();
      school_length = i;
      total_consume += schools[i].school_consume;
    }
    
    
 }
 int hospital_length = 0;
 for (int i=1; i <= hospital_piece; i++){
  if (hospital_piece == 0){
      break;
    } else {
      hospitals[i] = Hospital();
      hospital_length = i;
      total_consume += hospitals[i].hospital_consume;
    }
    
    
 }

 Serial.print("Házak száma: ");
 Serial.println(house_length);
 Serial.print("Lakások száma: ");
 Serial.println(flat_length);
 Serial.print("Iskolák száma: ");
 Serial.println(school_length);
 Serial.print("Kórházak száma: ");
 Serial.println(hospital_length);
 Serial.print("Összes fogyasztó igénye havi szinten: ");
 Serial.print(total_consume);
 Serial.println(" kWh");
 Serial.print("Összes fogyasztó igénye napi szinten: ");
 Serial.print(total_consume / 30);
 Serial.println(" kWh");
 
}

void loop() {
  lcd.display();
  // put your main code here, to run repeatedly:
  
  
  lcd.setCursor(8,0);
  lcd.print(total_consume);
  lcd.setCursor(8,1);
  lcd.print(total_consume/30);
  
  
}
