void Stats_Box_Draw(void){

  /// this section can go at the begign in setup for less drawing 
  myGLCD.setFont(SmallFont);
  myGLCD.setColor(TSC_GRAY);
  myGLCD.setBackColor(STA_GRY);
  myGLCD.print(CalData[0], VERTICAL_GUIDE5, HORIZONTAL_GUIDE4-2);
  myGLCD.print(CalData[1], VERTICAL_GUIDE5+43, HORIZONTAL_GUIDE4-2);
  myGLCD.print(CalData[2], VERTICAL_GUIDE5+120, HORIZONTAL_GUIDE4-2);
  myGLCD.print(CalData[3], VERTICAL_GUIDE5+210, HORIZONTAL_GUIDE4-2);
  myGLCD.print(CalData[4], VERTICAL_GUIDE5+290, HORIZONTAL_GUIDE4-2);
  myGLCD.print(CalData[5], VERTICAL_GUIDE5+383, HORIZONTAL_GUIDE4-2);


  for(int i=0;i<9;i++){
    if ( (i+1) % 2 == 0 ){
      myGLCD.setBackColor(STA_GRY);
    }
    else{
      myGLCD.setBackColor(STA_ORG);
    }
    myGLCD.print(ListData[i], VERTICAL_GUIDE5+2,HORIZONTAL_GUIDE5+(i*16));
  }

  for(int i=0;i<9;i++){
    if ( (i+1) % 2 == 0 ){
      myGLCD.setBackColor(STA_GRY);
    }
    else{
      myGLCD.setBackColor(STA_ORG);
    }
    myGLCD.printNumF(FlowRate[i][0],0, VERTICAL_GUIDE5+45,HORIZONTAL_GUIDE5+(i*16));
  }

  for(int i=0;i<9;i++){
    if ( (i+1) % 2 == 0 ){
      myGLCD.setBackColor(STA_GRY);
    }
    else{
      myGLCD.setBackColor(STA_ORG);
    }
    myGLCD.printNumF(V_MUT[i],3, VERTICAL_GUIDE5+121,HORIZONTAL_GUIDE5+(i*16));
  }

  for(int i=0;i<9;i++){
    if ( (i+1) % 2 == 0 ){
      myGLCD.setBackColor(STA_GRY);
    }
    else{
      myGLCD.setBackColor(STA_ORG);
    }
    myGLCD.printNumF(V_REF[i],3, VERTICAL_GUIDE5+211,HORIZONTAL_GUIDE5+(i*16));
  }

  for(int i=0;i<9;i++){
    if ( (i+1) % 2 == 0 ){
      myGLCD.setBackColor(STA_GRY);
    }
    else{
      myGLCD.setBackColor(STA_ORG);
    }
    myGLCD.printNumF(Deviation[i],3, VERTICAL_GUIDE5+295,HORIZONTAL_GUIDE5+(i*16));
  }

  for(int i=0;i<9;i++){
    if ( (i+1) % 2 == 0 ){
      myGLCD.setBackColor(STA_GRY);
    }
    else{
      myGLCD.setBackColor(STA_ORG);
    }
    if(Error[i]>3.0 || Error[i]<-3.0){
      myGLCD.setColor(LED_ON);
      myGLCD.printNumF(Error[i],3, VERTICAL_GUIDE5+385,HORIZONTAL_GUIDE5+(i*16));
      myGLCD.setColor(TSC_GRAY);
    }
    else{

      myGLCD.printNumF(Error[i],3, VERTICAL_GUIDE5+385,HORIZONTAL_GUIDE5+(i*16));

    }
  }

  myGLCD.setFont(Inconsola);


}

void StatSCreen(void){
  ScreenReturnFlag=0;
  myGLCD.fillScr(VGA_WHITE);
  //Stats background
  myGLCD.setColor(STA_GRY);
  myGLCD.fillRoundRect ( VERTICAL_GUIDE3-4,HORIZONTAL_GUIDE1-20, VERTICAL_GUIDE2+309,HORIZONTAL_GUIDE5+57);

  for(int i=0;i<5;i++){
    myGLCD.setColor(STA_ORG);
    myGLCD.fillRect ( VERTICAL_GUIDE3-4,(HORIZONTAL_GUIDE1+32)+((i)*64)-5, VERTICAL_GUIDE2+309,(HORIZONTAL_GUIDE1+32)+((i)*64)+24);
  } 
  myGLCD.setColor(VGA_SILVER);
  myGLCD.drawRoundRect ( VERTICAL_GUIDE3-4,HORIZONTAL_GUIDE1-20, VERTICAL_GUIDE2+309,HORIZONTAL_GUIDE5+57);
  //myGLCD.setColor(VGA_GRAY);
  // myGLCD.setFont(Inconsola);
  myGLCD.setFont(arial_bold);
  myGLCD.setColor(TSC_GRAY);
  myGLCD.setBackColor(STA_GRY);
  myGLCD.print(LargeCalData[0], VERTICAL_GUIDE3+5, HORIZONTAL_GUIDE1-5);
  myGLCD.print(LargeCalData[1], VERTICAL_GUIDE3+75, HORIZONTAL_GUIDE1-5);
  myGLCD.print(LargeCalData[2], VERTICAL_GUIDE3+210, HORIZONTAL_GUIDE1-5);
  myGLCD.print(LargeCalData[3], VERTICAL_GUIDE3+365, HORIZONTAL_GUIDE1-5);
  myGLCD.print(LargeCalData[4], VERTICAL_GUIDE3+524, HORIZONTAL_GUIDE1-5);
  myGLCD.print(LargeCalData[5], VERTICAL_GUIDE3+657, HORIZONTAL_GUIDE1-5);
  myGLCD.setFont( arial_normal );
  //myGLCD.setColor(VGA_GRAY);
  for(int i=0;i<9;i++){
    if ( (i+1) % 2 == 0 ){
      myGLCD.setBackColor(STA_GRY);
    }
    else{
      myGLCD.setBackColor(STA_ORG);
    }
    myGLCD.print(ListData[i], VERTICAL_GUIDE3+7,HORIZONTAL_GUIDE1+((i+1)*32));
  }

  for(int i=0;i<9;i++){
    if ( (i+1) % 2 == 0 ){
      myGLCD.setBackColor(STA_GRY);
    }
    else{
      myGLCD.setBackColor(STA_ORG);
    }
    myGLCD.printNumF(FlowRate[i][0],1, VERTICAL_GUIDE3+70,HORIZONTAL_GUIDE1+((i+1)*32));
  }

  switch ( StatScreenSelect) {
  case 0:
    for(int i=0;i<9;i++){
      if ( (i+1) % 2 == 0 ){
        myGLCD.setBackColor(STA_GRY);
      }
      else{
        myGLCD.setBackColor(STA_ORG);
      }
      myGLCD.printNumF(V_MUT[i],3, VERTICAL_GUIDE3+215,HORIZONTAL_GUIDE1+((i+1)*32));
    }
    break;
  case 1:
    for(int i=0;i<9;i++){
      if ( (i+1) % 2 == 0 ){
        myGLCD.setBackColor(STA_GRY);
      }
      else{
        myGLCD.setBackColor(STA_ORG);
      }
      myGLCD.printNumF(V_MUT[i],3, VERTICAL_GUIDE3+215,HORIZONTAL_GUIDE1+((i+1)*32));      
    }
    break;
  }

  for(int i=0;i<9;i++){
    if ( (i+1) % 2 == 0 ){
      myGLCD.setBackColor(STA_GRY);
    }
    else{
      myGLCD.setBackColor(STA_ORG);
    }
    myGLCD.printNumF(V_REF[i],3, VERTICAL_GUIDE3+370,HORIZONTAL_GUIDE1+((i+1)*32));
  }

  for(int i=0;i<9;i++){
    if ( (i+1) % 2 == 0 ){
      myGLCD.setBackColor(STA_GRY);
    }
    else{
      myGLCD.setBackColor(STA_ORG);
    }
    myGLCD.printNumF(Deviation[i],3, VERTICAL_GUIDE3+514,HORIZONTAL_GUIDE1+((i+1)*32));
  }

  for(int i=0;i<9;i++){
    if ( (i+1) % 2 == 0 ){
      myGLCD.setBackColor(STA_GRY);
    }
    else{
      myGLCD.setBackColor(STA_ORG);
    }
     if(Error[i]>3.0 || Error[i]<-3.0){
      myGLCD.setColor(LED_ON);
    myGLCD.printNumF(Error[i],3, VERTICAL_GUIDE3+660,HORIZONTAL_GUIDE1+((i+1)*32));
     myGLCD.setColor(TSC_GRAY);}
  
else{
  myGLCD.printNumF(Error[i],3, VERTICAL_GUIDE3+660,HORIZONTAL_GUIDE1+((i+1)*32));
}
  }
  // myGLCD.setFont(Inconsola);
  TransStats_draw();

  // myGLCD.setFont(arial_normal);
  while(ScreenReturnFlag==0){

    if (myTouch.dataAvailable())
    { /*
if(ETin.receiveData()){}  ///// live update
if(Com_Txnifo.U_Info[1]==3 && OldCom_Txnifo!=3){ // set start flag//until not !=3 counter is  reset
        delay(500);                                    // and started, ater batch/num take flow reading
        if(ETin.receiveData()){
        V_MUT[counter]=rxdata.Com_Volume;
        FlowRate[counter][0]=Old_Flow;
        V_REF[counter]=rxdata.Com_Volume2;
        Deviation[counter]=V_REF[counter]-V_MUT[counter];
        Error[counter]=(((V_MUT[counter]/V_REF[counter])*100)-100);
        AINPA1[counter]=rxdata.Com_Analog*1000;
        AINPB1[counter]=rxdata.Com_Analog2*1000;
        }
        counter++;
        if(counter>8){
          counter=0;
        }
        StatSCreen();
      }*/
      //Temp.BottomRight.x= myTouch.getX();
      //Temp.BottomRight.y=myTouch.getY();
      //KeyPad.SetSize(Temp);

      myTouch.read();
      x=myTouch.getX();
      y=myTouch.getY();

      Statsport_Scan();
      StatSelect();
    }
  }


  myGLCD.fillScr(VGA_WHITE);
  BackDropDraw_A();
  KeyPad_draw();
  Transport_draw();
  Stats_Box_Draw();

}


void Stats_Box_Export(void){
  float temp;

  Serial.print(CalData[0]);
  Serial.print(',');
  Serial.print(CalData[1]);
  Serial.print(',');
  Serial.print(CalData[2]);
  Serial.print(',');
  Serial.print(CalData[3]);
  Serial.print(',');
  Serial.print(CalData[4]);
  Serial.print(',');
  Serial.print(CalData[5]);
  Serial.print(',');
  Serial.print(CalData[6]);
  Serial.print(',');
  Serial.print(CalData[7]);

  for(int i=0;i<9;i++){
    Serial.println(',');
    Serial.print(ListData[i]);

    Serial.print(',');  
    Serial.print(FlowRate[i][0],4);

    Serial.print(',');  
    Serial.print(V_MUT[i],4);

    Serial.print(',');  
    Serial.print(V_REF[i],4);

    Serial.print(',');  
    Serial.print(Deviation[i],4);

    Serial.print(','); 
    Serial.print(Error[i],4);

    Serial.print(','); 
    Serial.print(AINPA1[i],4);

    Serial.print(','); 
    Serial.print(AINPB1[i],4);
  }




}


void SettingsScreen(void){
  ScreenReturnFlag=0;
   myGLCD.fillScr(VGA_WHITE);
   
   
   myGLCD.setFont(Inconsola);

  myGLCD.setBackColor(0, 0, 255); //???? blue?
  myGLCD.setColor(LCD_GREEN); /// keypad lcd
  myGLCD.fillRect(VERTICAL_GUIDE3+5, HORIZONTAL_GUIDE3-5, VERTICAL_GUIDE4-5, HORIZONTAL_GUIDE3+32);
  
  myGLCD.setBackColor(VGA_WHITE);

  myGLCD.setColor(LCD_TXT);
  myGLCD.setFont(arial_normal);
  myGLCD.print("GLOBLE SETTINGS", VERTICAL_GUIDE1+100, HORIZONTAL_GUIDE1-15);
  
  byte tempoffset=40;  
   for(int i=0;i<4;i++){
 myGLCD.print(SettingsStrings[i], VERTICAL_GUIDE1+25, HORIZONTAL_GUIDE1+40+(i*tempoffset));
 }
 //myGLCD.setBackColor(LCD_GREEN);

 
 for(int i=0;i<4;i++){
   if(i==GlobleSettingsNum){myGLCD.setBackColor( STA_ORG);}else{myGLCD.setBackColor(VGA_WHITE);}
  myGLCD.printNumI(SettingData[i],VERTICAL_GUIDE1+350, HORIZONTAL_GUIDE1+40+(i*tempoffset));
 }
   myGLCD.setBackColor(VGA_WHITE);
  //  myGLCD.setFont(arial_normal);
   
 
   myGLCD.setFont(Inconsola);
  KeyPad_draw();
   TransStats_draw();
  
  
    while(ScreenReturnFlag==0){

    if (myTouch.dataAvailable())
    {


      //Temp.BottomRight.x= myTouch.getX();
      //Temp.BottomRight.y=myTouch.getY();
      //KeyPad.SetSize(Temp);

      myTouch.read();
      x=myTouch.getX();
      y=myTouch.getY();
      
      
      KeyPad_Scan_Settings();
      Settsport_Scan();
      //StatSelect();
    }
  }


  myGLCD.fillScr(VGA_WHITE);
  BackDropDraw_A();
  KeyPad_draw();
  Transport_draw();
  Stats_Box_Draw();
}

