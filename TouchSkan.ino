void StepPad_Scan(NumPad &RPad, byte  Num,StepLED_Block &RLED,boolean LEDType,boolean DATAType){
  for(int i=0;i<Num;i++){
   
 if ((x>=RPad.GetButton(i).TopLeft.x) && (x<=RPad.GetButton(i).BottomRight.x)
     && (y>=RPad.GetButton(i).TopLeft.y) && (y<=RPad.GetButton(i).BottomRight.y))
     { 
       waitForIt(RPad.GetButton(i).TopLeft.x, RPad.GetButton(i).TopLeft.y, RPad.GetButton(i).BottomRight.x, RPad.GetButton(i).BottomRight.y);
       updateStr(StepNumbersStrings[i]);
       if(LEDType==HIGH){
       RLED.SetStatus(i,HIGH);}
     else
   { 
    RLED.SwitchSetStatus(i,HIGH);
   }
  
  if(DATAType==HIGH && LEDType==HIGH){
     for(int j=0;j<16;j++){ // length of bar
   OneBarArray_logic[InstrumentSelect][j]=RLED.GetLED_Status(j); // memcopy u plonk
  }
  }
  
  if(DATAType==LOW && LEDType==LOW){
  InstrumentSelect=i;
  for(int j=0;j<16;j++){ // numkit
   
   StepLED.SetMEMStatus(j,OneBarArray_logic[InstrumentSelect][j]); // memcopy u plonk
  }
  
}
}
}
}
//////////////////////////////

void KeyPad_Scan(void){
  for(int i=0;i<16;i++){
   
 if ((x>=KeyPad.GetButton(i).TopLeft.x) && (x<=KeyPad.GetButton(i).BottomRight.x)
     && (y>=KeyPad.GetButton(i).TopLeft.y) && (y<=KeyPad.GetButton(i).BottomRight.y))
     { //switch case!! god knows
     switch(i){
       case 9:
       waitForIt(KeyPad.GetButton(i).TopLeft.x, KeyPad.GetButton(i).TopLeft.y, KeyPad.GetButton(i).BottomRight.x, KeyPad.GetButton(i).BottomRight.y);
          stCurrent[0]='\0';
          stCurrentLen=0;
          myGLCD.setColor(LCD_GREEN);
          myGLCD.fillRect(VERTICAL_GUIDE3+5, HORIZONTAL_GUIDE3-5, VERTICAL_GUIDE4-5, HORIZONTAL_GUIDE3+32);
       break;
       case 11:
       waitForIt(KeyPad.GetButton(i).TopLeft.x, KeyPad.GetButton(i).TopLeft.y, KeyPad.GetButton(i).BottomRight.x, KeyPad.GetButton(i).BottomRight.y);
          
          txdata.Batch_Size=atoi(stCurrent);
          ETout.sendData();
          
          if (stCurrentLen>0)
          {
            for (x=0; x<stCurrentLen+1; x++)
            {
              stLast[x]=stCurrent[x];
            }
            stCurrent[0]='\0';
            stCurrentLen=0;
            myGLCD.setColor(LCD_GREEN);
            myGLCD.fillRect(VERTICAL_GUIDE3+5, HORIZONTAL_GUIDE3-5, VERTICAL_GUIDE4-5, HORIZONTAL_GUIDE3+32);
         //   myGLCD.setColor(VGA_SILVER);
   // myGLCD.setBackColor(VGA_WHITE);
         //   myGLCD.print(stLast, LEFT, 192);
          }
        /*  else
          {
            myGLCD.setColor(LCD_GREEN);
            myGLCD.fillRect(VERTICAL_GUIDE3+5, HORIZONTAL_GUIDE3, VERTICAL_GUIDE4-5, HORIZONTAL_GUIDE3+32);
            myGLCD.setColor(VGA_SILVER);
    myGLCD.setBackColor(VGA_WHITE);
            myGLCD.print("BUFFER EMPTY", CENTER, 192);
            delay(500);
            myGLCD.print("            ", CENTER, 192);
            delay(500);
            myGLCD.print("BUFFER EMPTY", CENTER, 192);
            delay(500);
            myGLCD.print("            ", CENTER, 192);
            
                   BackDropDraw_A();
KeyPad_draw();
  Transport_draw();
  Stats_Box_Draw();// myGLCD.setColor(0, 255, 0);
          }
  */
       break;
       default:
       waitForIt(KeyPad.GetButton(i).TopLeft.x, KeyPad.GetButton(i).TopLeft.y, KeyPad.GetButton(i).BottomRight.x, KeyPad.GetButton(i).BottomRight.y);
       updateStr(KeyPadStrings[i]);
       
       break;
     }
   
     }
 
  }
}
//////////////////////////////

void KeyPad_Scan_Settings(void){
  for(int i=0;i<12;i++){
   
 if ((x>=KeyPad.GetButton(i).TopLeft.x) && (x<=KeyPad.GetButton(i).BottomRight.x)
     && (y>=KeyPad.GetButton(i).TopLeft.y) && (y<=KeyPad.GetButton(i).BottomRight.y))
     { //switch case!! god knows
     switch(i){
       case 9:
       waitForIt(KeyPad.GetButton(i).TopLeft.x, KeyPad.GetButton(i).TopLeft.y, KeyPad.GetButton(i).BottomRight.x, KeyPad.GetButton(i).BottomRight.y);
          stCurrent[0]='\0';
          stCurrentLen=0;
          myGLCD.setColor(LCD_GREEN);
          myGLCD.fillRect(VERTICAL_GUIDE3+5, HORIZONTAL_GUIDE3-5, VERTICAL_GUIDE4-5, HORIZONTAL_GUIDE3+32);
       break;
       case 11:
       waitForIt(KeyPad.GetButton(i).TopLeft.x, KeyPad.GetButton(i).TopLeft.y, KeyPad.GetButton(i).BottomRight.x, KeyPad.GetButton(i).BottomRight.y);
          
          
          /// here
       myGLCD.setBackColor(VGA_WHITE);
       myGLCD.setColor(LCD_TXT);
       myGLCD.setFont(arial_normal);
          SettingData[GlobleSettingsNum]=atoi(stCurrent);
 
         for(int i=0;i<4;i++){
   if(i==GlobleSettingsNum){myGLCD.setBackColor( STA_ORG);}else{myGLCD.setBackColor(VGA_WHITE);}
  myGLCD.printNumI(SettingData[i],VERTICAL_GUIDE1+350, HORIZONTAL_GUIDE1+40+(i*40));
 }
 
 txdata.ModbusChannelA=SettingData[0];
 txdata.ModbusChannelB=SettingData[1];
 txdata.RunDivision=SettingData[2];
 txdata.RunNumber=SettingData[3];
  ETout.sendData();
 //// 2
 
          
          if (stCurrentLen>0)
          {
            for (x=0; x<stCurrentLen+1; x++)
            {
              stLast[x]=stCurrent[x];
            }
            stCurrent[0]='\0';
            stCurrentLen=0;
            myGLCD.setColor(LCD_GREEN);
            myGLCD.fillRect(VERTICAL_GUIDE3+5, HORIZONTAL_GUIDE3-5, VERTICAL_GUIDE4-5, HORIZONTAL_GUIDE3+32);
         //   myGLCD.setColor(VGA_SILVER);
   // myGLCD.setBackColor(VGA_WHITE);
         //   myGLCD.print(stLast, LEFT, 192);
          }
        /*  else
          {
            myGLCD.setColor(LCD_GREEN);
            myGLCD.fillRect(VERTICAL_GUIDE3+5, HORIZONTAL_GUIDE3, VERTICAL_GUIDE4-5, HORIZONTAL_GUIDE3+32);
            myGLCD.setColor(VGA_SILVER);
    myGLCD.setBackColor(VGA_WHITE);
            myGLCD.print("BUFFER EMPTY", CENTER, 192);
            delay(500);
            myGLCD.print("            ", CENTER, 192);
            delay(500);
            myGLCD.print("BUFFER EMPTY", CENTER, 192);
            delay(500);
            myGLCD.print("            ", CENTER, 192);
            
                   BackDropDraw_A();
KeyPad_draw();
  Transport_draw();
  Stats_Box_Draw();// myGLCD.setColor(0, 255, 0);
          }
  */
       break;
       default:
       waitForIt(KeyPad.GetButton(i).TopLeft.x, KeyPad.GetButton(i).TopLeft.y, KeyPad.GetButton(i).BottomRight.x, KeyPad.GetButton(i).BottomRight.y);
       updateStr(KeyPadStrings[i]);
       
       break;
     }
   
     }
 
  }
}



/////////////////////////////
void Transport_Scan(void){
  for(int i=0;i<3;i++){
   
 if ((x>=Transport.GetButton(i).TopLeft.x) && (x<=Transport.GetButton(i).BottomRight.x)
     && (y>=Transport.GetButton(i).TopLeft.y) && (y<=Transport.GetButton(i).BottomRight.y))
     {
       switch(i){
         case  0:
         if(rxdata.Com_Batch!=0 &&  (counter==8 || counter==0)){
         txdata.Control_4=4;
         counter=0;
         memset(V_MUT, 0, sizeof(V_MUT));
         memset(FlowRate, 0, sizeof(FlowRate));
         memset(V_REF, 0, sizeof(V_REF));
         memset(Deviation, 0, sizeof(Deviation));
         memset(Error, 0, sizeof(Error));
      
      StatsDropDraw_A();  
  Stats_Box_Draw();
         }
         
         else{
            myGLCD.setColor(VGA_RED);
    myGLCD.setBackColor(VGA_YELLOW);
    
    myGLCD.print("BATCH AT ZERO!", CENTER, 192);
    delay(500);
    myGLCD.print("              ", CENTER, 192);
    delay(500);
    myGLCD.print("BATCH AT ZERO!", CENTER, 192);
    delay(500);
    myGLCD.print("              ", CENTER, 192);
    
    myGLCD.fillScr(VGA_WHITE);
    
    BackDropDraw_A();

KeyPad_draw();
  Transport_draw();
  Stats_Box_Draw();
  myGLCD.setBackColor(VGA_WHITE);
   myGLCD.setColor(VGA_SILVER);
         }
         
           ETout.sendData();          
        waitForIt(Transport.GetButton(i).TopLeft.x, Transport.GetButton(i).TopLeft.y, Transport.GetButton(i).BottomRight.x, Transport.GetButton(i).BottomRight.y);
          txdata.Control_4=0;
          
           ETout.sendData();
           
         break;
         
         case 1:
         txdata.Control_4=5;
         ETout.sendData();
        waitForIt(Transport.GetButton(i).TopLeft.x, Transport.GetButton(i).TopLeft.y, Transport.GetButton(i).BottomRight.x, Transport.GetButton(i).BottomRight.y);
        txdata.Control_4=0;
         ETout.sendData(); 
        SettingsScreen();
           ///// new screen temp here, later make own button
         break;
         
         case 2:
         txdata.Control_3=5;
         //StatSCreen();
           ETout.sendData();
        waitForIt(Transport.GetButton(i).TopLeft.x, Transport.GetButton(i).TopLeft.y, Transport.GetButton(i).BottomRight.x, Transport.GetButton(i).BottomRight.y);
          txdata.Control_3=0;
           ETout.sendData(); 
         break;
       }
     }
  }
}

void statscan(void){
  
 if ((x>=VERTICAL_GUIDE1) && (x<=VERTICAL_GUIDE2+305)
     && (y>=HORIZONTAL_GUIDE4-7) && (y<=HORIZONTAL_GUIDE5+149))
     { StatSCreen();}

}

void LCD1scan(void){
  
   if ((x>=VERTICAL_GUIDE1) && (x<=VERTICAL_GUIDE2+248)
     && (y>=HORIZONTAL_GUIDE1-5) && (y<=HORIZONTAL_GUIDE1+ 96))
     {
     LCDdispSelect1+=1;
     if(LCDdispSelect1>1){LCDdispSelect1=0;}
     /////////////
     txdata.Control_3=6;   
     ETout.sendData();
     waitForIt(VERTICAL_GUIDE1, HORIZONTAL_GUIDE1-5, VERTICAL_GUIDE2+248, HORIZONTAL_GUIDE1+ 96); // new non grey and sqare one
     txdata.Control_3=0;
     ETout.sendData();
     /////////////
     }
  
}

void LCD2scan(void){
  
   if ((x>=VERTICAL_GUIDE1) && (x<=VERTICAL_GUIDE2+248)
     && (y>=HORIZONTAL_GUIDE2-5) && (y<=HORIZONTAL_GUIDE2+96))
     { 
     LCDdispSelect2+=1;
     if(LCDdispSelect2>1){LCDdispSelect2=0;}
     /////////////
     txdata.Control_3=7;   
     ETout.sendData();
     waitForIt(VERTICAL_GUIDE1, HORIZONTAL_GUIDE2-5, VERTICAL_GUIDE2+248, HORIZONTAL_GUIDE2+96);
     txdata.Control_3=0;
     ETout.sendData();
     /////////////
     }
  
}


void StatSelect(void){  // this hasnt been used yet but isfir the main stats screen toggls between mutl or somthing else?
  
   if ((x>=VERTICAL_GUIDE1) && (x<=VERTICAL_GUIDE2+305)
     && (y>=HORIZONTAL_GUIDE4-7) && (y<=HORIZONTAL_GUIDE5+149))
     {
     StatScreenSelect+=1;
     if(StatScreenSelect>1){StatScreenSelect=0;}

     }
}


byte Statsport_Scan(void){
  for(int i=0;i<3;i++){
   
 if ((x>=StatsScreen.GetButton(i).TopLeft.x) && (x<=StatsScreen.GetButton(i).BottomRight.x)
     && (y>=StatsScreen.GetButton(i).TopLeft.y) && (y<=StatsScreen.GetButton(i).BottomRight.y))
     {
       switch(i){
         case  0:
         waitForIt(StatsScreen.GetButton(i).TopLeft.x, StatsScreen.GetButton(i).TopLeft.y, StatsScreen.GetButton(i).BottomRight.x, StatsScreen.GetButton(i).BottomRight.y);

break;
      
      
            case  1:
                     waitForIt(StatsScreen.GetButton(i).TopLeft.x, StatsScreen.GetButton(i).TopLeft.y, StatsScreen.GetButton(i).BottomRight.x, StatsScreen.GetButton(i).BottomRight.y);
///////////// Export

Stats_Box_Export();

////////////////////
break;


              case  2:
                       waitForIt(StatsScreen.GetButton(i).TopLeft.x, StatsScreen.GetButton(i).TopLeft.y, StatsScreen.GetButton(i).BottomRight.x, StatsScreen.GetButton(i).BottomRight.y);
ScreenReturnFlag=1;
break;
       }
     }
   }
}
//////////////////////
byte Settsport_Scan(void){
  
  for(int i=0;i<3;i++){
   
 if ((x>=StatsScreen.GetButton(i).TopLeft.x) && (x<=StatsScreen.GetButton(i).BottomRight.x)
     && (y>=StatsScreen.GetButton(i).TopLeft.y) && (y<=StatsScreen.GetButton(i).BottomRight.y))
     {
       switch(i){
         case  0:
         waitForIt(StatsScreen.GetButton(i).TopLeft.x, StatsScreen.GetButton(i).TopLeft.y, StatsScreen.GetButton(i).BottomRight.x, StatsScreen.GetButton(i).BottomRight.y);
        GlobleSettingsNum+=1;
       if(GlobleSettingsNum>3){GlobleSettingsNum=0;} 
        myGLCD.setColor(LCD_TXT);
  myGLCD.setFont(arial_normal);
         for(int i=0;i<4;i++){
   if(i==GlobleSettingsNum){myGLCD.setBackColor( STA_ORG);}else{myGLCD.setBackColor(VGA_WHITE);}
  myGLCD.printNumI(SettingData[i],VERTICAL_GUIDE1+350, HORIZONTAL_GUIDE1+40+(i*40));
 }
         
break;
      
      
            case  1:
                     waitForIt(StatsScreen.GetButton(i).TopLeft.x, StatsScreen.GetButton(i).TopLeft.y, StatsScreen.GetButton(i).BottomRight.x, StatsScreen.GetButton(i).BottomRight.y);
///////////// Export

//Stats_Box_Export();

////////////////////
break;


              case  2:
                       waitForIt(StatsScreen.GetButton(i).TopLeft.x, StatsScreen.GetButton(i).TopLeft.y, StatsScreen.GetButton(i).BottomRight.x, StatsScreen.GetButton(i).BottomRight.y);
ScreenReturnFlag=1;
break;
       }
     }
   }
}

