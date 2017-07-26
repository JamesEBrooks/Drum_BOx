
void KeyPad_Rdraw(NumPad &RKeyPad, byte NumButtons){  /// these need chnging so they can display any instance, pointer to the instance?
  for(int i=0;i<NumButtons;i++){// reall this want to be sent the number of points, i.e. loop length and a referance to the object (pooint&rthis)
   
 
     myGLCD.setColor(66,95,128);
    myGLCD.fillRoundRect (RKeyPad.GetButton(i).TopLeft.x, RKeyPad.GetButton(i).TopLeft.y, RKeyPad.GetButton(i).BottomRight.x, RKeyPad.GetButton(i).BottomRight.y);
    myGLCD.setColor(93,126,163);
    myGLCD.drawRoundRect (RKeyPad.GetButton(i).TopLeft.x, RKeyPad.GetButton(i).TopLeft.y, RKeyPad.GetButton(i).BottomRight.x, RKeyPad.GetButton(i).BottomRight.y);
     myGLCD.setColor(163,187,214);
     myGLCD.setBackColor(66,95,128);
 myGLCD.print(StepNumbersStrings[i], RKeyPad.GetButton(i).TopLeft.x+10,  RKeyPad.GetButton(i).TopLeft.y+10); // string stay gobale? noooo
  }
}


















void KeyPad_draw(void){  /// these need chnging so they can display any instance, pointer to the instance?
  for(int i=0;i<12;i++){// reall this want to be sent the number of points, i.e. loop length and a referance to the object (pooint&rthis)
   
 
     myGLCD.setColor(240,240,240);
    myGLCD.fillRoundRect (KeyPad.GetButton(i).TopLeft.x, KeyPad.GetButton(i).TopLeft.y, KeyPad.GetButton(i).BottomRight.x, KeyPad.GetButton(i).BottomRight.y);
    myGLCD.setColor(VGA_SILVER);
    myGLCD.drawRoundRect (KeyPad.GetButton(i).TopLeft.x, KeyPad.GetButton(i).TopLeft.y, KeyPad.GetButton(i).BottomRight.x, KeyPad.GetButton(i).BottomRight.y);
     myGLCD.setColor(SML_TXT);
     myGLCD.setBackColor(240,240,240);
 myGLCD.print(KeyPadStrings[i], KeyPad.GetButton(i).TopLeft.x+10,  KeyPad.GetButton(i).TopLeft.y+10);
  }
}

void Transport_draw(void){  /// these need chnging so they can display any instance, pointer to the instance?
 myGLCD.setFont(arial_normal);
     myGLCD.setColor(BUT_RED);
    myGLCD.fillRoundRect (Transport.GetButton(0).TopLeft.x, Transport.GetButton(0).TopLeft.y, Transport.GetButton(0).BottomRight.x, Transport.GetButton(0).BottomRight.y);
    myGLCD.setColor(VGA_SILVER);
    myGLCD.drawRoundRect (Transport.GetButton(0).TopLeft.x, Transport.GetButton(0).TopLeft.y, Transport.GetButton(0).BottomRight.x, Transport.GetButton(0).BottomRight.y);
     myGLCD.setColor(SML_TXT);
     myGLCD.setBackColor(BUT_RED);
 myGLCD.print(TransportStrings[0], Transport.GetButton(0).TopLeft.x+13,  Transport.GetButton(0).TopLeft.y+10);
 
 myGLCD.setColor(BUT_GREEN);
    myGLCD.fillRoundRect (Transport.GetButton(1).TopLeft.x, Transport.GetButton(1).TopLeft.y, Transport.GetButton(1).BottomRight.x, Transport.GetButton(1).BottomRight.y);
    myGLCD.setColor(VGA_SILVER);
    myGLCD.drawRoundRect (Transport.GetButton(1).TopLeft.x, Transport.GetButton(1).TopLeft.y, Transport.GetButton(1).BottomRight.x, Transport.GetButton(1).BottomRight.y);
     myGLCD.setColor(SML_TXT);
     myGLCD.setBackColor(BUT_GREEN);
 myGLCD.print(TransportStrings[1], Transport.GetButton(1).TopLeft.x+6,  Transport.GetButton(1).TopLeft.y+10);
 
 myGLCD.setColor(240,240,240);
    myGLCD.fillRoundRect (Transport.GetButton(2).TopLeft.x, Transport.GetButton(2).TopLeft.y, Transport.GetButton(2).BottomRight.x, Transport.GetButton(2).BottomRight.y);
    myGLCD.setColor(VGA_SILVER);
    myGLCD.drawRoundRect (Transport.GetButton(2).TopLeft.x, Transport.GetButton(2).TopLeft.y, Transport.GetButton(2).BottomRight.x, Transport.GetButton(2).BottomRight.y);
     myGLCD.setColor(SML_TXT);
     myGLCD.setBackColor(240,240,240);
 myGLCD.print(TransportStrings[2], Transport.GetButton(2).TopLeft.x+6,  Transport.GetButton(2).TopLeft.y+10);
 myGLCD.setFont(Inconsola);
}

void TransStats_draw(void){  /// these need chnging so they can display any instance, pointer to the instance?
 myGLCD.setFont(arial_normal);
     myGLCD.setColor(LED_BACK);
    myGLCD.fillRoundRect (StatsScreen.GetButton(0).TopLeft.x, StatsScreen.GetButton(0).TopLeft.y, StatsScreen.GetButton(0).BottomRight.x, StatsScreen.GetButton(0).BottomRight.y);
    myGLCD.setColor(VGA_SILVER);
    myGLCD.drawRoundRect (StatsScreen.GetButton(0).TopLeft.x, StatsScreen.GetButton(0).TopLeft.y, StatsScreen.GetButton(0).BottomRight.x, StatsScreen.GetButton(0).BottomRight.y);
     myGLCD.setColor(SML_TXT);
     myGLCD.setBackColor(LED_BACK);
 myGLCD.print(StatsportStrings[0], StatsScreen.GetButton(0).TopLeft.x+21,  StatsScreen.GetButton(0).TopLeft.y+8,90);
 
 myGLCD.setColor(LED_BACK);
    myGLCD.fillRoundRect (StatsScreen.GetButton(1).TopLeft.x, StatsScreen.GetButton(1).TopLeft.y, StatsScreen.GetButton(1).BottomRight.x, StatsScreen.GetButton(1).BottomRight.y);
    myGLCD.setColor(VGA_SILVER);
    myGLCD.drawRoundRect (StatsScreen.GetButton(1).TopLeft.x, StatsScreen.GetButton(1).TopLeft.y, StatsScreen.GetButton(1).BottomRight.x, StatsScreen.GetButton(1).BottomRight.y);
     myGLCD.setColor(SML_TXT);
     myGLCD.setBackColor(LED_BACK);
 myGLCD.print(StatsportStrings[1], StatsScreen.GetButton(1).TopLeft.x+10,  StatsScreen.GetButton(1).TopLeft.y+8);
 
 myGLCD.setColor(LED_BACK);
    myGLCD.fillRoundRect (StatsScreen.GetButton(2).TopLeft.x, StatsScreen.GetButton(2).TopLeft.y, StatsScreen.GetButton(2).BottomRight.x, StatsScreen.GetButton(2).BottomRight.y);
    myGLCD.setColor(VGA_SILVER);
    myGLCD.drawRoundRect (StatsScreen.GetButton(2).TopLeft.x, StatsScreen.GetButton(2).TopLeft.y, StatsScreen.GetButton(2).BottomRight.x, StatsScreen.GetButton(2).BottomRight.y);
     myGLCD.setColor(SML_TXT);
     myGLCD.setBackColor(LED_BACK);
 myGLCD.print(StatsportStrings[2], StatsScreen.GetButton(2).TopLeft.x+4,  StatsScreen.GetButton(2).TopLeft.y+10);
 myGLCD.setFont(Inconsola);
}


void LED_draw(void){ // pass pointer, so only one function, pointer to ref or mut? a table that will aloow many? same for all
  myGLCD.setFont(SmallFont);
myGLCD.setBackColor(STA_GRY);
  for(int i=0;i<4;i++){
     myGLCD.setColor(SML_TXT);
 myGLCD.print(LEDStrings[i], ReferenceMeter.GetLED(i).BottomRight.x+4, ReferenceMeter.GetLED(i).TopLeft.y);
 
    switch(ReferenceMeter.GetLED_Status(i))
    {
      case HIGH:
    myGLCD.setColor(242,109,125); //red ON
    myGLCD.fillRoundRect (ReferenceMeter.GetLED(i).TopLeft.x, ReferenceMeter.GetLED(i).TopLeft.y, ReferenceMeter.GetLED(i).BottomRight.x, ReferenceMeter.GetLED(i).BottomRight.y);
    myGLCD.setColor(242,108,79);  // ON edge
    myGLCD.drawRoundRect (ReferenceMeter.GetLED(i).TopLeft.x, ReferenceMeter.GetLED(i).TopLeft.y, ReferenceMeter.GetLED(i).BottomRight.x, ReferenceMeter.GetLED(i).BottomRight.y);
    break;
    case LOW:
    myGLCD.setColor(STA_ORG);
    myGLCD.fillRoundRect (ReferenceMeter.GetLED(i).TopLeft.x, ReferenceMeter.GetLED(i).TopLeft.y, ReferenceMeter.GetLED(i).BottomRight.x, ReferenceMeter.GetLED(i).BottomRight.y);
    myGLCD.setColor(STA_ORG);
    myGLCD.drawRoundRect (ReferenceMeter.GetLED(i).TopLeft.x, ReferenceMeter.GetLED(i).TopLeft.y, ReferenceMeter.GetLED(i).BottomRight.x, ReferenceMeter.GetLED(i).BottomRight.y);
    break;
    }
  }
   myGLCD.setFont(Inconsola);
}
///wrong
void LED2_draw(void){
  myGLCD.setFont(SmallFont);
 myGLCD.setBackColor(STA_GRY);
  for(int i=0;i<4;i++){
    myGLCD.setColor(SML_TXT);
 myGLCD.print(LEDStrings[i], MeterUnderTest.GetLED(i).BottomRight.x+4, MeterUnderTest.GetLED(i).TopLeft.y);
    switch(MeterUnderTest.GetLED_Status(i))
    {
      case HIGH:
    myGLCD.setColor(242,109,125); //red ON
    myGLCD.fillRoundRect (MeterUnderTest.GetLED(i).TopLeft.x, MeterUnderTest.GetLED(i).TopLeft.y, MeterUnderTest.GetLED(i).BottomRight.x, MeterUnderTest.GetLED(i).BottomRight.y);
    myGLCD.setColor(242,108,79); // ON edge
    myGLCD.drawRoundRect (MeterUnderTest.GetLED(i).TopLeft.x, MeterUnderTest.GetLED(i).TopLeft.y, MeterUnderTest.GetLED(i).BottomRight.x, MeterUnderTest.GetLED(i).BottomRight.y);
    break;
    case LOW:
    myGLCD.setColor(STA_ORG);
    myGLCD.fillRoundRect (MeterUnderTest.GetLED(i).TopLeft.x, MeterUnderTest.GetLED(i).TopLeft.y, MeterUnderTest.GetLED(i).BottomRight.x, MeterUnderTest.GetLED(i).BottomRight.y);
    myGLCD.setColor(STA_ORG);
    myGLCD.drawRoundRect (MeterUnderTest.GetLED(i).TopLeft.x, MeterUnderTest.GetLED(i).TopLeft.y, MeterUnderTest.GetLED(i).BottomRight.x, MeterUnderTest.GetLED(i).BottomRight.y);
    break;
    }
  }
  myGLCD.setFont(Inconsola);
}
///////////////////////
void StepLED_draw(StepLED_Block &RLEDPad, byte NumLED,boolean Type){ // pass pointer, so only one function, pointer to ref or mut? a table that will aloow many? same for all
  myGLCD.setFont(SmallFont);
myGLCD.setBackColor(STA_GRY);
  for(int i=0;i<NumLED;i++){
     myGLCD.setColor(SML_TXT);
 //myGLCD.print(LEDStrings[i], RLEDPad.GetLED(i).BottomRight.x+4, RLEDPad.GetLED(i).TopLeft.y);
 if(Type==HIGH){
    switch(RLEDPad.GetLED_Status(i))
    {
      case HIGH:
    myGLCD.setColor(IntrumentColours[InstrumentSelect][0],IntrumentColours[InstrumentSelect][1],IntrumentColours[InstrumentSelect][2]); //red ON  InstrumentSelect
    myGLCD.fillRoundRect (RLEDPad.GetLED(i).TopLeft.x, RLEDPad.GetLED(i).TopLeft.y, RLEDPad.GetLED(i).BottomRight.x, RLEDPad.GetLED(i).BottomRight.y);
    myGLCD.setColor(IntrumentColoursHL[InstrumentSelect][0],IntrumentColoursHL[InstrumentSelect][1],IntrumentColoursHL[InstrumentSelect][2]);
    myGLCD.drawRoundRect (RLEDPad.GetLED(i).TopLeft.x, RLEDPad.GetLED(i).TopLeft.y, RLEDPad.GetLED(i).BottomRight.x, RLEDPad.GetLED(i).BottomRight.y);
    break;
    case LOW:
    myGLCD.setColor(19,59,105);
    myGLCD.fillRoundRect (RLEDPad.GetLED(i).TopLeft.x, RLEDPad.GetLED(i).TopLeft.y, RLEDPad.GetLED(i).BottomRight.x, RLEDPad.GetLED(i).BottomRight.y);
    myGLCD.setColor(19,59,105);
    myGLCD.drawRoundRect (RLEDPad.GetLED(i).TopLeft.x, RLEDPad.GetLED(i).TopLeft.y, RLEDPad.GetLED(i).BottomRight.x, RLEDPad.GetLED(i).BottomRight.y);
    break;
    }
 }else
 {
  switch(RLEDPad.GetLED_Status(i))
    {
      case HIGH:
    myGLCD.setColor(IntrumentColours[i][0],IntrumentColours[i][1],IntrumentColours[i][2]); //red ON
    myGLCD.fillRoundRect (RLEDPad.GetLED(i).TopLeft.x, RLEDPad.GetLED(i).TopLeft.y, RLEDPad.GetLED(i).BottomRight.x, RLEDPad.GetLED(i).BottomRight.y);
    myGLCD.setColor(IntrumentColoursHL[i][0],IntrumentColoursHL[i][1],IntrumentColoursHL[i][2]);  // ON edge
    myGLCD.drawRoundRect (RLEDPad.GetLED(i).TopLeft.x, RLEDPad.GetLED(i).TopLeft.y, RLEDPad.GetLED(i).BottomRight.x, RLEDPad.GetLED(i).BottomRight.y);
    
    myGLCD.setColor(109,202,242);
    myGLCD.setBackColor(11,30,51);
    myGLCD.setFont(Inconsola);
    myGLCD.print(InstruList[i], 20,200);
    
    
    break;
    case LOW:
    myGLCD.setColor(19,59,105);
    myGLCD.fillRoundRect (RLEDPad.GetLED(i).TopLeft.x, RLEDPad.GetLED(i).TopLeft.y, RLEDPad.GetLED(i).BottomRight.x, RLEDPad.GetLED(i).BottomRight.y);
    myGLCD.setColor(19,59,105);
    myGLCD.drawRoundRect (RLEDPad.GetLED(i).TopLeft.x, RLEDPad.GetLED(i).TopLeft.y, RLEDPad.GetLED(i).BottomRight.x, RLEDPad.GetLED(i).BottomRight.y);
    break;
   
     
   
 }
    
  }
  
}
}




/*************************
**   Custom functions   **
*************************/




void updateStr(char* val)
{
  if (stCurrentLen<11)
  {
    stCurrent[stCurrentLen]=*val;
    stCurrent[stCurrentLen+1]='\0';
    stCurrentLen++;
    myGLCD.setFont(Inconsola);
    myGLCD.setColor(LCD_TXT);
    myGLCD.setBackColor(LCD_GREEN);
    myGLCD.print(stCurrent, VERTICAL_GUIDE3+5, HORIZONTAL_GUIDE3); // here
  }
  /*else
  {
    myGLCD.setColor(VGA_SILVER);
    myGLCD.setBackColor(VGA_WHITE);
    myGLCD.print("BUFFER FULL!", CENTER, 192);
    delay(500);
    myGLCD.print("            ", CENTER, 192);
    delay(500);
    myGLCD.print("BUFFER FULL!", CENTER, 192);
    delay(500);
    myGLCD.print("            ", CENTER, 192);
    //LCD
    myGLCD.setColor(LCD_GREEN);
  myGLCD.fillRect(VERTICAL_GUIDE1, HORIZONTAL_GUIDE1-5, VERTICAL_GUIDE2+248,HORIZONTAL_GUIDE1+ 96); 
  myGLCD.fillRect(VERTICAL_GUIDE1, HORIZONTAL_GUIDE2-5, VERTICAL_GUIDE2+248, HORIZONTAL_GUIDE2+96);

KeyPad_draw();
  }*/
}



// Draw a red frame while a button is touched
void waitForIt(int x1, int y1, int x2, int y2)
{
  myGLCD.setColor(VGA_YELLOW);
  myGLCD.drawRoundRect (x1, y1, x2, y2);
  while (myTouch.dataAvailable()){
    myTouch.read();
 
  //////// bodge
  StepLED_draw(Run_StepLED,16,HIGH);

///////////////////// put in fuction

  currentMillis = micros();
  if(currentMillis - previousMillis > interval) {
   
    previousMillis = currentMillis;   
Position+=1;
if(Position>16){Position=0;}
  
  }
  
////////////////////  
Run_StepLED.SwitchSetStatus(Position,HIGH);
StepLED_draw(Run_StepLED,16,HIGH);  
  }
  //////////
   myGLCD.setColor(93,126,163);
  myGLCD.drawRoundRect (x1, y1, x2, y2);
}
//////////////////////////
/////////////////////////

void fmtDouble(double val, byte precision, char *buf, unsigned bufLen = 12);
unsigned fmtUnsigned(unsigned long val, char *buf, unsigned bufLen = 12, byte width = 0);


unsigned fmtUnsigned(unsigned long val, char *buf, unsigned bufLen, byte width)
{
  if (!buf || !bufLen)
    return(0);

  // produce the digit string (backwards in the digit buffer)
  char dbuf[10];
  unsigned idx = 0;
  while (idx < sizeof(dbuf))
  {
    dbuf[idx++] = (val % 10) + '0';
    if ((val /= 10) == 0)
      break;
  }

  // copy the optional leading zeroes and digits to the target buffer
  unsigned len = 0;
  byte padding = (width > idx) ? width - idx : 0;
  char c = '0';
  while ((--bufLen > 0) && (idx || padding))
  {
    if (padding)
      padding--;
    else
      c = dbuf[--idx];
    *buf++ = c;
    len++;
  }

  // add the null termination
  *buf = '\0';
  return(len);
}



void fmtDouble(double val, byte precision, char *buf, unsigned bufLen)
{
  if (!buf || !bufLen)
    return;

  // limit the precision to the maximum allowed value
  const byte maxPrecision = 9;
  if (precision > maxPrecision)
    precision = maxPrecision;

  if (--bufLen > 0)
  {
    // check for a negative value
    if (val < 0.0)
    {
      val = -val;
      *buf = '-';
      bufLen--;
    }

    // compute the rounding factor and fractional multiplier
    double roundingFactor = 0.5;
    unsigned long mult = 1;
    for (byte i = 0; i < precision; i++)
    {
      roundingFactor /= 10.0;
      mult *= 10;
    }

    if (bufLen > 0)
    {
      // apply the rounding factor
      val += roundingFactor;

      // add the integral portion to the buffer
      unsigned len = fmtUnsigned((unsigned long)val, buf, bufLen);
      buf += len;
      bufLen -= len;
    }

    // handle the fractional portion
    if ((precision > 0) && (bufLen > 0))
    {
      *buf++ = '.';
      if (--bufLen > 0)
        buf += fmtUnsigned((unsigned long)((val - (unsigned long)val) * mult), buf, bufLen, precision);
    }
  }

  // null-terminate the string
  *buf = '\0';
}
