const int inPin0 = 0;
const int inPin1 = 1;

void calculatekW(float &sum)
{
  //kb átlagban 1050 kWh-t termel egy átlagos napelem
  //számítások sajnos nincsenek meg nekem, de átlagban mondható, hogy 
  //1650x1650mm a méret, ami 2,72m^2. 
  int valueAt0 = analogRead(inPin0);         
  int valueAt1 = analogRead(inPin1);         
  
  float voltsAt0 = (valueAt0 / 1024.0) * 5;    
  float voltsAt1 = (valueAt1 / 1024.0) * 5;    
  float amper = 0.52;
  float kWat0 = (voltsAt0 * amper) / 1000;
  float kWat1 = (voltsAt1 * amper) / 1000;
  float kWat2 = (kWat0 + kWat1) / 2;
  sum = sum + kWat0 + kWat1 + kWat2;
  delay(500);


}
