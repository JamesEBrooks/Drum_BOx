// green 190,235,56



// Remenber you have created your own calculator stylr print function in the library file for the lcd driver!!!!!myGLCD.printLCD

#define LED_ON		        242,109,125
#define LED_ON_EDGE             242,108,79
#define LED_OFF                 245,240,220
#define LED_BACK                240,240,240

#define BUT_RED			246,150,121
#define BUT_GREEN               196,223,155

#define LCD_GREEN		53,212,230
#define LCD_TXT		        100,100,100
#define SML_TXT		        106,106,106

#define TSC_SILVER		0xC618
#define TSC_GRAY		70,70,70
#define TSC_YELLOW		0xFFE0

#define STA_ORG		        220,215,195
#define STA_GRY		        225,225,225
#include <UTFT.h>
#include <UTouch.h>
#include"NUMPAD.H"
// Declare which fonts we will be using
//extern uint8_t BigFont[];
extern uint8_t SmallFont[];
extern uint8_t arial_bold[];
extern uint8_t Inconsola[];
extern uint8_t arial_normal[];







// Uncomment the next two lines for the Arduino 2009/UNO
//UTFT        myGLCD(ITDB24D,19,18,17,16);   // Remember to change the model parameter to suit your display module!
//UTouch      myTouch(15,10,14,9,8);
#include <EasyTransfer.h>
// Uncomment the next line for Arduino Mega
//UTFT myGLCD(ITDB32S,38,39,40,41);   // Remember to change the model parameter to suit your display module!
char* LEDStrings[]={
  "Run", "Flow", "Wait",
  "Gate"};
char* SettingsStrings[]={
  "MODBUS Channel A", "MODBUS Channel B", "Run Division",
  "Run Number"};

byte SettingData[]={1,2,3,4};
byte GlobleSettingsNum=0;    
  
char* KeyPadStrings[]={
  "1", "2", "3",
  "4","5","6","7","8","9","C","0","E"};
char* StepNumbersStrings[]={
  "1", "2", "3",
  "4","5","6","7","8","9","10","11","12","13","14","15","16"};
char* TransportStrings[]={
  "Run", "Stop", "Gate"};
char* StatsportStrings[]={
  "<>", "Exp", "Back"}; 


byte IntrumentColours[7][3]={ {242,109,125},{189,109,242},{109,202,242},{109,242,176},{142,242,109},{242,226,109},{242,189,109}};
byte IntrumentColoursHL[7][3]={ {252,182,190},{215,169,245},{168,224,247},{178,247,213},{191,237,175},{245,237,181},{247,209,151}};
  
long previousMillis = 0;        // will store last time LED was updated
long interval = 100000; 
byte Position =0;
unsigned long currentMillis=0;
  
float FlowRate[90][1];
float AINPA1[90];
float AINPB1[90];
float V_MUT[90];
float V_REF[90];
float Deviation[90];
float Error[90];
int counter=0;

byte ScreenReturnFlag=0;
byte StatScreenSelect=0;

boolean OneBarArray_logic[7][16];
byte InstrumentSelect=0;

byte LCDdispSelect1=0;
byte LCDdispSelect2=0;

char* CalData[]={
  "Run","Flow","REF Lts","MUT Lts","Deviation","Error","Ainp R","Ainp T"};
  char* LargeCalData[]={
  "Run","Flow","REF Lts","MUT Lts","Dev","Error"};
  
  char* ListData[]={
  "1a","1b","1c","2a","2b","2c","3a","3b","3c"};
  
char* InstruList[]={
  "808 Kick      ","909 Kick      ","909 Snare     ","808 Snare     ","808 Clap     ","909 Rimshot   ","808 Open HH   ","808 Closed HH"};  
  
  

Square Temp; //keypad temp this all needs cleaning up
Square LED_Temp;

const word VERTICAL_GUIDE1=315;
const word VERTICAL_GUIDE2=480;
const word VERTICAL_GUIDE3=16; // keypad LCD ofset
const word VERTICAL_GUIDE4=300;
const word VERTICAL_GUIDE5=335; //sats far left

const word HORIZONTAL_GUIDE1=40;
const word HORIZONTAL_GUIDE2=175;
const word HORIZONTAL_GUIDE3=317; // LCD pannel
const word HORIZONTAL_GUIDE4=295; // stat heading
const word HORIZONTAL_GUIDE5=315; // stats start

union {
  byte U_Info[4];
  float U_Status;
} 
Com_Txnifo;


////////////////////
EasyTransfer ETin,ETout;
struct RECEIVE_DATA_STRUCTURE{
  
  float Com_Analog2;
  float Com_Volume2;
  float Com_Flow2;
  float Com_Batch2;
  float Com_Analog;
  float Com_Volume;
  float Com_Flow;
  float Com_Batch;
  float Com_Status;//Bug? needs to be float? anyway use a union with 4 bytes

};
///////
struct SEND_DATA_STRUCTURE{
  uint8_t ModbusChannelA;
  uint8_t ModbusChannelB;
  uint8_t RunDivision;
 uint8_t RunNumber;
  uint16_t Control_3;
  uint16_t Control_4;
  uint16_t Batch_Size;
};
/*
  Recive transmit data , needs both, how to deal with thte transport and timing of runs. what
 is done on which. it might not matter so much looking forward. Have seperate control;s for each of the
 two gates, even though the turn at the same time (although for the calibration setup it might be better
 for both to use the same channel.
 */
///////

RECEIVE_DATA_STRUCTURE rxdata;
SEND_DATA_STRUCTURE txdata;   

// Uncomment the next two lines for the Arduino Mega
UTFT myGLCD(CTE70,25,26,27,28);    // Remember to change the model parameter to suit your display module!
UTouch      myTouch(6,5,4,3,2);

int x, y;   ////!!!!!!!!!!!! what!!
char stCurrent[20]="";
int stCurrentLen=0;
char stLast[20]="";

byte OldCom_Txnifo=3;
float Old_Flow=0;

LED_Block ReferenceMeter;
LED_Block MeterUnderTest;
StepLED_Block StepLED;
StepLED_Block Run_StepLED;
StepLED_Block KitLED;

NumPad KeyPad;
NumPad KitPad;
NumPad Transport;
NumPad StatsScreen;
///// Class has to be in .H file i htink this is the problem.
char TxtVolume[12];
char TxtA1[12];
char TxtA2[12];
char TxtFlow[12];
char TxtBatch[6];
/*************************
 * 
 * Stoppping the fliker on the LCD pannel, use a char[] it is the full display length. all the carictars are put on screen
 * you blank the array, re right it and then dispaly it in that order, so no blanking
 * 
 *************************/

void setup()

{
 // startTimer(TC2, 0, TC3_IRQn, FREQ_1Hz);

  
  
  LED_Temp.TopLeft.x=VERTICAL_GUIDE2+250;
  LED_Temp.TopLeft.y=HORIZONTAL_GUIDE1-5;
  LED_Temp.BottomRight.x=VERTICAL_GUIDE2+275;
  LED_Temp.BottomRight.y=HORIZONTAL_GUIDE1+96;
  ReferenceMeter.SetSize(LED_Temp);

  LED_Temp.TopLeft.x=VERTICAL_GUIDE2+250;
  LED_Temp.TopLeft.y=HORIZONTAL_GUIDE2-5;
  LED_Temp.BottomRight.x=VERTICAL_GUIDE2+275;
  LED_Temp.BottomRight.y=HORIZONTAL_GUIDE2+96;
  MeterUnderTest.SetSize(LED_Temp);
  
  LED_Temp.TopLeft.x=400;
  LED_Temp.TopLeft.y=120;
  LED_Temp.BottomRight.x=550;
  LED_Temp.BottomRight.y=460;
  KitLED.ydiv=4;
  KitLED.xdiv=2;
  KitLED.pad=12;
  KitLED.SetSize(LED_Temp);
  
  Temp.TopLeft.x=400;
  Temp.TopLeft.y=120;
  Temp.BottomRight.x=550;
  Temp.BottomRight.y=460;
  KitPad.ydiv=4;
  KitPad.xdiv=2;
  KitPad.SetSize(Temp);
 //KitPad.xdiv=4; // do this after SetSize and it over ries tthe presets// or maybe not doies nnt seem to work
  LED_Temp.TopLeft.x=5;
  LED_Temp.TopLeft.y=55;
  LED_Temp.BottomRight.x=800;
  LED_Temp.BottomRight.y=135;
  Run_StepLED.xdiv=16;
  Run_StepLED.ydiv=1;
  Run_StepLED.pad=21;
  Run_StepLED.SetSize(LED_Temp);
/////////  
  LED_Temp.TopLeft.x=5;
  LED_Temp.TopLeft.y=20;
  LED_Temp.BottomRight.x=800;
  LED_Temp.BottomRight.y=100;
  StepLED.xdiv=16;
  StepLED.ydiv=1;
  StepLED.pad=17;
  StepLED.SetSize(LED_Temp);


  Temp.TopLeft.x=5;
  Temp.TopLeft.y=20;
  Temp.BottomRight.x= 800;
  Temp.BottomRight.y=100;
  KeyPad.ydiv=1;
  KeyPad.xdiv=16;
  KeyPad.SetSize(Temp);
  KeyPad.xdiv=4; // do this after SetSize and it over ries tthe presets// or maybe not doies nnt seem to work
  
  

  Temp.TopLeft.x=VERTICAL_GUIDE3; ///// YOU WERE HERE!!!!!! DRUNK ;)
  Temp.TopLeft.y=370;
  Temp.BottomRight.x= VERTICAL_GUIDE4;
  Temp.BottomRight.y=441;

  Transport.ydiv=1;
  Transport.SetSize(Temp);

   Temp.TopLeft.x=VERTICAL_GUIDE3+500; ///// YOU WERE HERE!!!!!! DRUNK ;)
  Temp.TopLeft.y=370+17;
  Temp.BottomRight.x= VERTICAL_GUIDE4+500;
  Temp.BottomRight.y=441+17;

  StatsScreen.ydiv=1;
  StatsScreen.SetSize(Temp);



  txdata.Batch_Size=0;
  txdata.ModbusChannelA=1;  /// needs C and D as well for switching between meters,, duh
  txdata.ModbusChannelB=2;
  txdata.RunDivision=3;
  txdata.RunNumber=3;
  txdata.Control_4=LOW;
  txdata.Control_3=LOW;

  // Initial setup
  Serial.begin(9600);
  Serial1.begin(115200);
  ETin.begin(details(rxdata), &Serial1);
  ETout.begin(details(txdata), &Serial1);
  myGLCD.InitLCD();
  myGLCD.clrScr();

  myTouch.InitTouch();
  myTouch.setPrecision(PREC_EXTREME);
  
  
myGLCD.fillScr(11,30,51);//
/////////
myGLCD.setBackColor(11,30,51); 
 //myGLCD.setFont(arial_normal);
  myGLCD.setFont(SmallFont);
  for(int i=240;i>0;i--){
myGLCD.setColor(i,i,i);
delay(1);
  myGLCD.print("Copyright 2014 James Brooks", CENTER,225);
 }
delay(100);
for(int i=0;i<240;i++){
myGLCD.setColor(i,i,i);
delay(1);
  myGLCD.print("Copyright 2014 James Brooks", CENTER,225);
 }
 delay(500);
///////
myGLCD.fillScr(11,30,51); 
  myGLCD.setColor(109,202,242);
    myGLCD.setBackColor(11,30,51);
    myGLCD.setFont(Inconsola);
    myGLCD.print("Bar Number: ", 20,250);
myGLCD.setFont(SmallFont);
  
// BackDropDraw_A();
 //KeyPad_draw();
 KeyPad_Rdraw(KeyPad,16); // new referace
 KeyPad_Rdraw(KitPad,8); // new referace
  //Transport_draw();
 // Stats_Box_Draw();
  ETout.sendData();  // send setup data
}

void loop()
{

 
   // if(ETin.receiveData()){
     // memset(TxtVolume, 0, sizeof (TxtVolume));
      fmtDouble(rxdata.Com_Volume, 3, TxtVolume,12);
      fmtDouble(rxdata.Com_Flow, 3, TxtFlow,11);
      fmtDouble(rxdata.Com_Batch, 0, TxtBatch,9);
      fmtDouble((rxdata.Com_Analog*1000), 3, TxtA1,12); // chnage the decimal back to higher, need bettyer screenn redraw
/*


      myGLCD.setFont(Inconsola);
      myGLCD.setColor(190,235,56);
      // myGLCD.fillRect(500, 16, 750, 48);
      myGLCD.setColor(LCD_TXT);
      myGLCD.setBackColor(LCD_GREEN);

      myGLCD.print("Volume", VERTICAL_GUIDE1, HORIZONTAL_GUIDE1);    
    //  myGLCD.printLCD(TxtVolume," ", VERTICAL_GUIDE2,HORIZONTAL_GUIDE2,11);
      myGLCD.printLCD(TxtVolume," ", VERTICAL_GUIDE2,HORIZONTAL_GUIDE1,10);

     // myGLCD.setColor(190,235,56);
      // myGLCD.fillRect(500, 48, 750, 80);
    //  myGLCD.setColor(VGA_GRAY);

      myGLCD.print("Flow", VERTICAL_GUIDE1, HORIZONTAL_GUIDE1+32); 
      //myGLCD.printNumF(rxdata.Com_Flow, 3, 500,48);
      myGLCD.printLCD(TxtFlow," ", VERTICAL_GUIDE2,HORIZONTAL_GUIDE1+32,10);

    //  myGLCD.setColor(190,235,56);
      // myGLCD.fillRect(500, 80, 750, 112);
     // myGLCD.setColor(VGA_GRAY);
switch ( LCDdispSelect1) {
  case 0:
      myGLCD.print("Batch ", VERTICAL_GUIDE1, HORIZONTAL_GUIDE1+64);    
      // myGLCD.printNumI((int)rxdata.Com_Batch, 500,80);
      myGLCD.printLCD(TxtBatch," ", VERTICAL_GUIDE2,HORIZONTAL_GUIDE1+64,10);
      break;
      case 1:
      myGLCD.print("Ainp 1", VERTICAL_GUIDE1, HORIZONTAL_GUIDE1+64);    
      // myGLCD.printNumI((int)rxdata.Com_Batch, 500,80);
      myGLCD.printLCD(TxtA1," ", VERTICAL_GUIDE2,HORIZONTAL_GUIDE1+64,10);
break;

 /*     case 2:
      myGLCD.print("Input2", VERTICAL_GUIDE1, HORIZONTAL_GUIDE1+64);    
      // myGLCD.printNumI((int)rxdata.Com_Batch, 500,80);
      myGLCD.print(TxtA1, VERTICAL_GUIDE2,HORIZONTAL_GUIDE1+64);
break;
}
     // LCD_Draw();
*/
      Com_Txnifo.U_Status=rxdata.Com_Status;

// ETin.receiveData();
      //////
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
        Stats_Box_Draw();
      }
      
    
Old_Flow=rxdata.Com_Flow;
       // this keeps the old value so it's no zero i.e after gate close like the others
      //OldCom_Txnifo=Com_Txnifo.U_Info[1];
      //Stats_Box_Draw();
      
      if(Com_Txnifo.U_Info[1]==7 && OldCom_Txnifo!=7){
          myGLCD.setColor(VGA_RED);
    myGLCD.setBackColor(VGA_YELLOW);
    while(true){
     
    myGLCD.print("ADJUST FLOW!", CENTER, 192);
    delay(500);
    myGLCD.print("              ", CENTER, 192);
    delay(500);
    myGLCD.print("PRESS SCREEN", CENTER, 192); // other message for end of run
    delay(500);
    myGLCD.print("              ", CENTER, 192);
    delay(500);
    
    if (myTouch.dataAvailable())
    break;
    }
    txdata.Control_3=8;
           ETout.sendData();
           delay(500);
           ETout.sendData();
           delay(500);
           ETout.sendData();
           delay(500);
        txdata.Control_3=0;
    ETout.sendData();
           delay(500);
           ETout.sendData();
           delay(500);
           ETout.sendData();
           delay(500);    
    myGLCD.fillScr(11,30,51);
    
   // if(counter==8){StatSCreen();}
   
 // BackDropDraw_A();
//KeyPad_draw();
KeyPad_Rdraw(KeyPad,16); 
  //Transport_draw();
  //Stats_Box_Draw();
  myGLCD.setBackColor(11,30,51);
   myGLCD.setColor(VGA_SILVER);
   delay(500);
      }
//  ETout.sendData();  // unnecicery i think
      OldCom_Txnifo=Com_Txnifo.U_Info[1];
      ///////
//if(counter==8){StatSCreen();}

      Com_Txnifo.U_Status=rxdata.Com_Status;
      ReferenceMeter.SetStatus(Com_Txnifo.U_Info[0],Com_Txnifo.U_Info[1]);
      MeterUnderTest.SetStatus(Com_Txnifo.U_Info[0],Com_Txnifo.U_Info[1]); // this will be [1] when othe rmodbus chaneel comes from mega
      //LED_draw();  // only draw if changed!!
     // LED2_draw();
   // }


    //KeyPad_draw();
    //

StepLED_draw(StepLED,16,HIGH);
StepLED_draw(KitLED,7,LOW);
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

    if (myTouch.dataAvailable())
    {


      //Temp.BottomRight.x= myTouch.getX();
      //Temp.BottomRight.y=myTouch.getY();
      //KeyPad.SetSize(Temp);

      myTouch.read();
      x=myTouch.getX();
      y=myTouch.getY();

     // KeyPad_Scan();
     StepPad_Scan(KeyPad,16,StepLED,HIGH,HIGH); // use #defines her to make iut more iteligabe
     StepPad_Scan(KitPad,7,KitLED,LOW,LOW);
     // statscan();
     // Transport_Scan();
      // Scan_Keypad();
      // Buttons();

 /// other sreen !!!!!!!!!!!!!!1here
//LCD1scan();
//LCD2scan();

    }
  
}


void LCD_Draw(void){


// 12 should be settable an not a magic number , it is how lond the lcd is or how many charicars are on it

  fmtDouble(rxdata.Com_Volume2, 3, TxtVolume,12); // 10 plus null
  fmtDouble(rxdata.Com_Flow2, 3, TxtFlow,11);
  fmtDouble((rxdata.Com_Analog2*1000), 3, TxtA2,12);

  myGLCD.setFont(Inconsola);
  myGLCD.setColor(190,235,56);
  // myGLCD.fillRect(500, 16, 750, 48);
  myGLCD.setColor(LCD_TXT);
  myGLCD.setBackColor(LCD_GREEN);

  myGLCD.print("Volume", VERTICAL_GUIDE1, HORIZONTAL_GUIDE2);     
  myGLCD.printLCD(TxtVolume," ", VERTICAL_GUIDE2,HORIZONTAL_GUIDE2,10);


  myGLCD.print("Flow", VERTICAL_GUIDE1, HORIZONTAL_GUIDE2+32); 
  //myGLCD.printNumF(rxdata.Com_Flow, 3, 500,48);
  myGLCD.printLCD(TxtFlow," ", VERTICAL_GUIDE2,HORIZONTAL_GUIDE2+32,10);

  //myGLCD.setColor(190,235,56);
  // myGLCD.fillRect(500, 80, 750, 112);
  //myGLCD.setColor(VGA_GRAY);
switch ( LCDdispSelect2) {
  case 0:
  myGLCD.print("Ainp 1", VERTICAL_GUIDE1, HORIZONTAL_GUIDE2+64);    
  // myGLCD.printNumI((int)rxdata.Com_Batch, 500,80);
  myGLCD.printLCD(TxtA2," ", VERTICAL_GUIDE2,HORIZONTAL_GUIDE2+64,10);
  break;
  case 1:
  myGLCD.print("Ainp 2", VERTICAL_GUIDE1, HORIZONTAL_GUIDE2+64);    
  // myGLCD.printNumI((int)rxdata.Com_Batch, 500,80);
  myGLCD.printLCD(TxtA2," ", VERTICAL_GUIDE2,HORIZONTAL_GUIDE2+64,10);
  break;
}
}

/////////////////////////////////////////////////
//////////////////////////////////////////////////



void BackDropDraw_A(void){
  myGLCD.setFont(Inconsola);

  //myGLCD.setBackColor(0, 0, 255); //???? blue?

  
  myGLCD.setBackColor(11,30,51);

  myGLCD.setColor(LCD_TXT);
  myGLCD.setFont(arial_normal);
  myGLCD.print("Reference Meter", VERTICAL_GUIDE1, HORIZONTAL_GUIDE1-25);
  myGLCD.print("Meter Under Test", VERTICAL_GUIDE1, HORIZONTAL_GUIDE2-25);
  myGLCD.setFont(Inconsola);
  myGLCD.setBackColor(VGA_SILVER);
  // drawButtons();
 // KeyPad_draw();
//  Transport_draw();


  ///LED background
  myGLCD.setColor(STA_GRY);
  myGLCD.fillRect(VERTICAL_GUIDE2+253, HORIZONTAL_GUIDE1-5, VERTICAL_GUIDE2+307,HORIZONTAL_GUIDE1+96);
  myGLCD.fillRect(VERTICAL_GUIDE2+253, HORIZONTAL_GUIDE2-5, VERTICAL_GUIDE2+307,HORIZONTAL_GUIDE2+96);

  //LCD backgrounds  
  myGLCD.setColor(LCD_GREEN);
  myGLCD.fillRect(VERTICAL_GUIDE1, HORIZONTAL_GUIDE1-5, VERTICAL_GUIDE2+248,HORIZONTAL_GUIDE1+ 96); 
  myGLCD.fillRect(VERTICAL_GUIDE1, HORIZONTAL_GUIDE2-5, VERTICAL_GUIDE2+248, HORIZONTAL_GUIDE2+96);


  myGLCD.setColor(LCD_GREEN); /// keypad lcd
  myGLCD.fillRect(VERTICAL_GUIDE3+5, HORIZONTAL_GUIDE3-5, VERTICAL_GUIDE4-5, HORIZONTAL_GUIDE3+32);

  //Stats background
  myGLCD.setColor(STA_GRY);
  myGLCD.fillRoundRect ( VERTICAL_GUIDE1,HORIZONTAL_GUIDE4-7, VERTICAL_GUIDE2+305,HORIZONTAL_GUIDE5+149);

  for(int i=0;i<5;i++){
    myGLCD.setColor(STA_ORG);
    myGLCD.fillRoundRect ( VERTICAL_GUIDE1,HORIZONTAL_GUIDE5+(i*32)-2, VERTICAL_GUIDE2+305,HORIZONTAL_GUIDE5+(i*32)+13);
  } 
  myGLCD.setColor(VGA_SILVER);
  myGLCD.drawRoundRect ( VERTICAL_GUIDE1,HORIZONTAL_GUIDE4-7, VERTICAL_GUIDE2+305,HORIZONTAL_GUIDE5+149);  

  
  
}

void StatsDropDraw_A(void){
   //Stats background
  myGLCD.setColor(STA_GRY);
  myGLCD.fillRoundRect ( VERTICAL_GUIDE1,HORIZONTAL_GUIDE4-7, VERTICAL_GUIDE2+305,HORIZONTAL_GUIDE5+149);

  for(int i=0;i<5;i++){
    myGLCD.setColor(STA_ORG);
    myGLCD.fillRoundRect ( VERTICAL_GUIDE1,HORIZONTAL_GUIDE5+(i*32)-2, VERTICAL_GUIDE2+305,HORIZONTAL_GUIDE5+(i*32)+13);
  } 
  myGLCD.setColor(VGA_SILVER);
  myGLCD.drawRoundRect ( VERTICAL_GUIDE1,HORIZONTAL_GUIDE4-7, VERTICAL_GUIDE2+305,HORIZONTAL_GUIDE5+149); 
}


