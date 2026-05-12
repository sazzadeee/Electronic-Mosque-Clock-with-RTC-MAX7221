void Dig4(int addres,int min)
{
    int h,m1,m2,m;
    h=min/60;
    m=min%60;
    m1=m/10;
    m2=m%10;
  
  //lc.setDigit(addres, 0, h, false);
  lc.setDigit(addres, 1, h, 1);
  lc.setDigit(addres, 2, m1, false);
  lc.setDigit(addres, 3, m2, false);

}
//////////////////////////////

int value()
{
  if(results.value == 0x38863BC0) return 99; //>
  else if(results.value == 0x38863BDC)  return 10; //menu
  else if(results.value == 0x38863BF2)  return 20;  //P+
  else if(results.value == 0x38863BFA)  return 40;
  else return 88;
 /* 
  else if(results.value == 0x38863BD0)   return 2;
  else if(results.value == 0x38863BF0)   return 3;
  else if(results.value == 0x38863BC8)   return 4;
  else if(results.value == 0x38863BE8)   return 5;
  else if(results.value == 0x38863BD8)   return 6;
  else if(results.value == 0x38863BF8)   return 7;
  else if(results.value == 0x38863BC4)   return 8;
  else if(results.value == 0x38863BE4)   return 9;
  */
}

/*
void dig4(int addres,int hour,int minute)  // (displaynumber,hour,minute)
{  int h,m,h1,m1;
   h=hour/10;
   h1=hour%10;
   m=minute/10;
   m1=minute%10;

  lc.setDigit(addres, 0, h, false);
  lc.setDigit(addres, 1, h1, 1);
  lc.setDigit(addres, 2, m, false);
  lc.setDigit(addres, 3, m1, false);
}
*/