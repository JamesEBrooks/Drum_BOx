#ifndef NUMPAD_H
#define NUMPAD_H

struct Point{
  int x;
  int y;
};

struct Square{
  Point TopLeft;
  Point BottomRight;
};

class NumPad {
  
  public:
  
//void KeyPad_draw(void);
//void NumPad (Square sqaure);
  
  void SetSize (Square sqaure);
  Square GetButton(int Button_Num);
  
  int xdiv,ydiv;
  private:
  int width;
  int height;
  int buttonwidth;
  int buttonheight;
  int pad;
  Square ButtonList[16];  // max number make it a constant in header
  Point origin;
  void SetPoints (void);
};

void NumPad::SetPoints(void){
  uint8_t counter=0;
  for(int y=0;y<ydiv;y++){
    for(int x=0;x<xdiv;x++){
      ButtonList[counter].TopLeft.x=origin.x+((x*buttonwidth)+pad);
      ButtonList[counter].TopLeft.y=origin.y+((y*buttonheight)+pad);
      ButtonList[counter].BottomRight.x=origin.x+(((x+1)*buttonwidth)-pad);
      ButtonList[counter].BottomRight.y=origin.y+(((y+1)*buttonheight)-pad);
      counter++;
    }
  }
}

void NumPad::SetSize(Square square){
  pad=5; //  this needsd to be a set percent if the width i 
  //xdiv=16; /// this nees comenting out and setting when the object is defined
  //ydiv=4;
  origin=square.TopLeft;
  width=square.BottomRight.x-square.TopLeft.x;
  height=square.BottomRight.y-square.TopLeft.y;
  buttonwidth=width/xdiv;
  buttonheight=height/ydiv;  
  SetPoints();
 
}

Square NumPad::GetButton(int Button_Num){
  return (ButtonList[Button_Num]);
}

//////////////////////////////LED

class LED_Block {
  
  public:
  
 // void LED_draw(void);
//void NumPad (Square sqaure);
  void SetStatus(byte Status,byte CMode);
  void SetSize (Square sqaure);
  Square GetLED(int LED_Num);
  boolean GetLED_Status(int LED_Num);
  int ydiv;
  private:
  int width;
  int height;
  int buttonwidth;
  int buttonheight;
  int pad;
  Square LEDList[4]; // this 4 can it go along with the 12 obove its a bit restrictive?
  boolean LED_logic[4];
  Point origin;
  void SetPoints (void);
};



void LED_Block::SetPoints(void){
  uint8_t counter=0;
  for(int y=0;y<ydiv;y++){
   
      LEDList[counter].TopLeft.x=origin.x+pad;
      LEDList[counter].TopLeft.y=origin.y+((y*buttonheight)+pad);
      LEDList[counter].BottomRight.x=origin.x+((buttonwidth)-pad);
      LEDList[counter].BottomRight.y=origin.y+(((y+1)*buttonheight)-pad);
      counter++;
 
  }
}

void LED_Block::SetSize(Square square){
  pad=7; //  this needsd to be a set percent if the width i 

  ydiv=4;
  origin=square.TopLeft;
  width=square.BottomRight.x-square.TopLeft.x;
  height=square.BottomRight.y-square.TopLeft.y;
  buttonwidth=width;
  buttonheight=height/ydiv;  
  SetPoints();
 
}

Square LED_Block::GetLED(int LED_Num){
  return (LEDList[LED_Num]);
}

boolean LED_Block::GetLED_Status(int LED_Num){
  return (LED_logic[LED_Num]);
}

void LED_Block::SetStatus(byte Status,byte CMode){
  switch ( Status ) {
    case 5:
   // LED_logic[0]=LOW;   // this needs to be a byte and use bit mapping, much more elegant
    LED_logic[1]=LOW;
    LED_logic[2]=HIGH;
   // LED_logic[3]=LOW;
   break;
case 8:
   // LED_logic[0]=LOW;   // this needs to be a byte and use bit mapping, much more elegant
    LED_logic[1]=HIGH;
    LED_logic[2]=LOW;
  //  LED_logic[3]=LOW;
   break; 
  default:
 // LED_logic[0]=LOW;   // this needs to be a byte and use bit mapping, much more elegant
    LED_logic[1]=LOW;
    LED_logic[2]=LOW;
  //  LED_logic[3]=LOW;
  }
  switch ( CMode ) {
    case 2:
   LED_logic[0]=HIGH;   // this needs to be a byte and use bit mapping, much more elegant
  //  LED_logic[1]=LOW;
   // LED_logic[2]=HIGH;
    LED_logic[3]=LOW;
   break;
case 5:
   
    LED_logic[0]=LOW;   // this needs to be a byte and use bit mapping, much more elegant
  //  LED_logic[1]=HIGH;
  //  LED_logic[2]=LOW;
    LED_logic[3]=LOW;
   break; 
  default:
 LED_logic[0]=LOW;   // this needs to be a byte and use bit mapping, much more elegant
 //   LED_logic[1]=LOW;
  //  LED_logic[2]=LOW;
    LED_logic[3]=LOW;
  }
  
}
//////////////////////////////LED

class StepLED_Block {
  
  public:
  
 // void LED_draw(void);
//void NumPad (Square sqaure);
  void SetMEMStatus(byte Step,boolean Status);
  void SetStatus(byte Status,byte CMode);
  void SwitchSetStatus(byte Status,byte CMode);
  void SetSize (Square sqaure);
  Square GetLED(int LED_Num);

  boolean GetLED_Status(int LED_Num);
  int xdiv,ydiv;
  int pad;
  private:
  int width;
  int height;
  int buttonwidth;
  int buttonheight;
  
  Square LEDList[16]; // this 4 can it go along with the 12 obove its a bit restrictive?
  boolean LED_logic[16];
  Point origin;
  void SetPoints (void);
};



void StepLED_Block::SetPoints(void){
  uint8_t counter=0;
   for(int y=0;y<ydiv;y++){
    for(int x=0;x<xdiv;x++){
      LEDList[counter].TopLeft.x=origin.x+((x*buttonwidth)+pad);
      LEDList[counter].TopLeft.y=origin.y+((y*buttonheight)+(pad*2)+9);
      LEDList[counter].BottomRight.x=origin.x+(((x+1)*buttonwidth)-pad);
      LEDList[counter].BottomRight.y=origin.y+(((y+1)*buttonheight)-pad);
      counter++;
    }
  }

}

void StepLED_Block::SetSize(Square square){
 // pad=20; //  this needsd to be a set percent if the width i 
  
  origin=square.TopLeft;
  width=square.BottomRight.x-square.TopLeft.x;
  height=square.BottomRight.y-square.TopLeft.y;
  buttonwidth=width/xdiv;
  buttonheight=height/ydiv;  
  SetPoints();
 
}

Square StepLED_Block::GetLED(int LED_Num){
  return (LEDList[LED_Num]);
}

boolean StepLED_Block::GetLED_Status(int LED_Num){
  return (LED_logic[LED_Num]);
}

void StepLED_Block::SetMEMStatus(byte Step,boolean Status){
  
   
    LED_logic[Step]=Status;

 
}

void StepLED_Block::SetStatus(byte Step,boolean Status){
  
   
    LED_logic[Step]=!LED_logic[Step];

 
}

void StepLED_Block::SwitchSetStatus(byte Step,boolean Status){
  
    memset(LED_logic, 0, sizeof(LED_logic)); 
    LED_logic[Step]=HIGH;

 
}

#endif

