const int pingPin = 15; 
const int echoPin = 16;

#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#include <Servo.h>
Servo myservo;    

int pos = 0;  
long cm = 0;

void setup()
{ 
  myservo.attach(9);  
  lcd.begin(16, 2);   

  lcd.setCursor(0,0);
  lcd.print("Angle:");
  lcd.setCursor(0,1);
  lcd.print("Dist:");
}

long getUltrasonicvalue()
{
  long duration;

  pinMode(pingPin, OUTPUT); 
  digitalWrite(pingPin, LOW);                                
  delayMicroseconds(2);                                        
  digitalWrite(pingPin, HIGH);                          
  delayMicroseconds(10);
  digitalWrite(pingPin, LOW);

  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  return duration / 29 / 2;   
}
      int lastangle=0;
      int lastdist=0;
void loop() 
{
  for (pos = 0; pos <= 180; pos++)
  { 
    myservo.write(pos);
    delay(40);                 

    cm = getUltrasonicvalue();

    lcd.setCursor(6,0);
    lcd.print("    ");
    lcd.setCursor(6,0);
    lcd.print(pos);

    lcd.setCursor(6,1);
    lcd.print("    ");
    lcd.setCursor(6,1);
    lcd.print(cm);

    if (cm < 10)
    { 
      lastangle=pos;
      lastdist=cm;
      lcd.setCursor(12,0);
      lcd.print("OBJ");
    }
    if(lastangle!=0)
    {
    lcd.setCursor(9,0);
    lcd.print(lastangle);
    lcd.setCursor(11,1);
    lcd.print(lastdist);
    }
    else
    {
      lcd.setCursor(12,0);
      lcd.print("   ");
    }

    delay(80);
  }

  for (pos = 180; pos >= 0; pos--)
  { 
    myservo.write(pos);
    delay(40);                 

    cm = getUltrasonicvalue();

    lcd.setCursor(6,0);
    lcd.print("    ");
    lcd.setCursor(6,0);
    lcd.print(pos);

    lcd.setCursor(6,1);
    lcd.print("    ");
    lcd.setCursor(6,1);
    lcd.print(cm);

    if (cm < 10)
    { 
      lastangle=pos;
      lastdist=cm;
      lcd.setCursor(12,0);
      lcd.print("OBJ");
    }
    if(lastangle!=0)
    {
    lcd.setCursor(9,0);
    lcd.print(lastangle);
    lcd.setCursor(11,1);
    lcd.print(lastdist);
    }
    else
    {
      lcd.setCursor(12,0);
      lcd.print("   ");
    }

    delay(80);
  }
}
