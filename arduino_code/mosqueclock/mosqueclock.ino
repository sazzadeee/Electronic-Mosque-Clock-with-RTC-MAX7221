
// created by Sazzad Hossain
//A4 , A5 pin for i2c communication

#include <IRremote.h>
#include<Wire.h>  
#include<RTClib.h>  
#include <LedControl.h>       

int RECV_PIN = 2;
IRrecv irrecv(RECV_PIN);
decode_results results;

RTC_DS1307 rtc;   //DS3231 are jonnou RTC_DS1307 aita lekha lagbe
int hour,hour24,minutes,seconds,h,m,s,h2,s2,m2;
  // int fojorh,fojorm,johorh,johorm,asorh,asorm,magribh,magribm,ashah,asham;
byte button,state;
int fojor,johor,asor,magrib,asha;



// Pin assignments
int DIN = 13;  // Data In
int CS = 12;   // Chip Select
int CLK = 11;  // Clock

// Create a LedControl object
LedControl lc = LedControl(DIN, CLK, CS, 6);  // (DataIn, CLK, Load, Number of MAX7219)

void setup() {
  for(int i=0;i<6;i++)
  {

   lc.shutdown(i, false);  // wake up call   NORMALLY OFF THAKE AITAKE ON KORTE HOI
   lc.setIntensity(i, 8);    // brightness 0 to 15;   
   lc.clearDisplay(i);   // clear the display
  }
  irrecv.enableIRIn();   // Start the receiver
  rtc.begin();
  Serial.begin(9600);
  //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
/*
fojorh=4;
fojorm=35;
johorh=1;
johorm=30;
asorh=4;
asorm=15;
magribh=7;
magribm=45;
ashah=8;
asham=45;
*/
fojor= 280;
johor=90;
asor=270;
magrib=400;
asha=510;

}

void loop() {


  DateTime present = rtc.now();
  hour24=present.hour();
  minutes=present.minute();
  seconds=present.second();
  
  if(hour24>12)     // 24 hour to 12 hour convert
  { hour=hour24-12;}
  else hour=hour24;


  h=hour/10;
  h2=hour%10;
  m=minutes/10;
  m2=minutes%10;
  s=seconds/10;
  s2=seconds%10;
  //lc.setDigit(0, 0, 1, false);  == (address of display, digit position, value, decimal point or dot (.) )
// time
  lc.setDigit(0, 0, h, false); 
  lc.setDigit(0, 1, h2, false);
  //lc.setDigit(0, 2, 3, false);
  lc.setDigit(0, 3, m, false);
  lc.setDigit(0, 4, m2, false);
  //lc.setDigit(0, 5, 6, false);
  lc.setDigit(0, 6, s, false);
  lc.setDigit(0, 7, s2, false);

    if (irrecv.decode(&results)) 
    {
    //Serial.println(results.value, HEX);    
    irrecv.resume(); // Receive the next value 
    //delay(50);
    button=value();
    Serial.print("button value= "); 
    Serial.println(button); 
    
    }
    

     if(button==10)  // menu
    {
      state=state+1;
      if(state>5)  state=0;
      Serial.print("device= ");
      Serial.println(state);
      button=0;
      //Serial.print("b done");
    }
// increamnet decreament
    if(state==1)
    {
      if(button==20) //p+
      {
        fojor=fojor+1;
        button=0;
      }
      if(button==40) //p-
      {
        fojor=fojor-1;
        button=0;
      }
    }
    ////////// 
      if(state==2)
    {
      if(button==20) //p+
      {
        johor=johor+1;
        button=0;
      }
      if(button==40) //p-
      {
        johor=johor-1;
        button=0;
      }
    }
    ////////// 
      if(state==3)
    {
      if(button==20) //p+
      {
        asor=asor+1;
        button=0;
      }
      if(button==40) //p-
      {
        asor=asor-1;
       button=0;
      }
    }
    ////////// 
      if(state==4)
    {
      if(button==20) //p+
      {
        magrib=magrib+1;
        button=0;
      }
      if(button==40) //p-
      {
        magrib=magrib-1;
        button=0;
      }
    }
    ////////// 
      if(state==5)
    {
      if(button==20) //p+
      {
        asha=asha+1;
        button=0;
      }
      if(button==40) //p-
      {
        asha=asha-1;
        button=0;
      }
    }
    
Dig4(1,fojor);    //adress,time(min)
Dig4(2,johor);
Dig4(3,asor);
Dig4(4,magrib);
Dig4(5,asha);

/*
  // fojor time
  dig4(1,fojorh,fojorm);  // (deviceaddress,hour,minute)
  // display johor
  dig4(2,johorh,johorm);
  //asor
  dig4(3,asorh,asorm);
  //magrib
  dig4(4,magribh,magribm);
  // asha
  dig4(5,ashah,asham);
  delay(100);
*/
//button=0;
}
