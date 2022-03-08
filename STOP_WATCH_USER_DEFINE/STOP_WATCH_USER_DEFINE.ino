#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

int count_1=0,count_2=0,cnt=0;
int SW_1=8;
int SW_2=9;
int SW_3=10;

int once_1=0,once_2,once_3;
int val_1,val_2,val_3;
int y=9;
int a=0;

void Dec2ascii(unsigned char value)
{
  unsigned char x=0;
  
  x=value/10;
  lcd.print(x);
  delay(10);
  
  x=value%10;
  lcd.print(x);
  delay(10);
}

void setup() 
{
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("SRI ELECTRONIC & EMBEDDED SOLUTIONS");
  delay(100);
  pinMode(SW_1,INPUT);
  pinMode(SW_2,INPUT);
  pinMode(SW_3,INPUT);
}

void loop() 
{
  lcd.setCursor(0,1);
  lcd.print("SP WATCH:");
  
  lcd.setCursor(11,1);
  lcd.print(":");
  
  val_2=digitalRead(SW_2);
  delay(120);

  if(val_2 != LOW)
  {
    if(once_2==0)
    {
      y++;
      delay(10);
      if(y==14)
      {
        y=9;
      }
      once_2=1;
    }
  }
  else
  {
    once_2=0;
  }



  
  val_1=digitalRead(SW_1);
  
  if(val_1 != LOW)
  {
    if(once_1==0)
    {
      lcd.setCursor(y,1);
      lcd.print(cnt);
      delay(10);
      
      cnt++;
      if(cnt==9)
      {
        cnt=0;
      } 
      once_1=1;
    }
  } 

  else
  {
    once_1=0;
  }



  
  val_3=digitalRead(SW_3);
  
  if(val_3 == HIGH)
  {
    a=1;
  }
  while(a==1)
  {  
    for(count_2=0;count_2<60;count_2++)
    {
      for(count_1=0;count_1<60;count_1++)
      {
        lcd.setCursor(9,1);
        Dec2ascii(count_2);
        lcd.setCursor(11,1);
        lcd.print(':');
        lcd.setCursor(12,1); 
        Dec2ascii(count_1);
        
        delay(1000);
        if(cnt==count_1)
        {
          a=0;
          while(a==1);
        }
      }
    } 
  }
}
