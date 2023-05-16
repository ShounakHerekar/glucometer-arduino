#include<LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,4,5,6,7);
const int temp = A0;
int ir1state=0;
int ir2state=0;
int vout=0;
int xout=0;
int yout=0;
int zout=0;
float con=(5.0*1000)/1023; 
void setup()
{
pinMode(temp,INPUT);
Serial.begin(9600);
lcd.begin(16,2);
delay(500);
}
void loop()
{
ir1state=analogRead(temp);
xout=0.1873*ir1state;
ir2state=(8*10^-5)*ir1state^2;
yout=ir2state+xout+46.131;
vout=yout*(-1);
zout=vout/100;
//Serial.println(ir1state);
//Serial.println(ir2state);
//Serial.print("GL:");
//Serial.print(zout);
//Serial.print("mg per dL");
//delay(1000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("GL");
if ((ir1state<=300)&&(ir1state>=20))
{
Serial.print("GL: ");
Serial.print(zout);
Serial.print("mg per dL\n");
//delay(1000);
lcd.clear();
lcd.setCursor(0,0);  
lcd.print("GL:");
lcd.print(zout);
lcd.print("mg per dL");
delay(1000);
}
else
{
lcd.clear();
lcd.setCursor(0,0);
lcd.print("GL:");
delay(1000);
Serial.println("GL:");
delay(1000);
}
}
