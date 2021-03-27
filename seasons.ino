byte pinLedR = 9;
byte pinLedG = 10;
byte pinLedB = 11;
 // Switch
byte SWspring = 2;
byte SWsummer = 3;
byte SWautumn = 4;
byte SWwinter = 5;
byte SWchange = 6;
 // buttonstate
bool BSspring = false; 
bool BSsummer = false;
bool BSautumn = false;
bool BSwinter = false;
bool BSchange = false;
int colorR,colorG,colorB;
bool turn = false;
bool change = false;
void setColor();

void setup() {
  // put your setup code here, to run once:
  pinMode(pinLedR,OUTPUT);
  pinMode(pinLedG,OUTPUT);
  pinMode(pinLedB,OUTPUT);
  pinMode(SWspring,INPUT);
  pinMode(SWsummer,INPUT);
  pinMode(SWautumn,INPUT);
  pinMode(SWwinter,INPUT);
  pinMode(SWchange,INPUT);
  Serial.begin(9600);
}

void loop() {
  setColor();
  delay(200);
}

void setColor()
{
  BSspring=digitalRead(SWspring);
  BSsummer=digitalRead(SWsummer);
  BSautumn=digitalRead(SWautumn);
  BSwinter=digitalRead(SWwinter);
  BSchange=digitalRead(SWchange);
  colorR=analogRead(0);
  colorG=analogRead(1);
  colorB=analogRead(2);
  if (BSspring){
    Serial.println("spring");
    turn=!turn;
    Spring();
  }
  if(BSsummer){
    Serial.println("summer");
    turn=!turn;
    Summer();
  }
  if(BSautumn){
    Serial.println("autumn");
    turn=!turn;
    Autumn();
  }
  if(BSwinter){
    Serial.println("winter");
    turn=!turn;
    Winter();
  }
  if(BSchange){
    Serial.println("change turn");
    turn=!turn;
    if(turn ==true)
   {
     change =!change;
      Serial.println("change change");
   }
  }
  if(change == true)
  {
    Change();
    ChangeColor();
  }
}
void Spring()
{
  if(turn == true)
  {
    analogWrite(pinLedR,255);
    analogWrite(pinLedG,150);
    analogWrite(pinLedB,130);
  }
  else if(turn == false)
  {
    analogWrite(pinLedR,0);
    analogWrite(pinLedG,0);
    analogWrite(pinLedB,0);
  }
}
void Summer()
{
  if(turn == true)
  {
    analogWrite(pinLedR,150);
    analogWrite(pinLedG,255);
    analogWrite(pinLedB,58);
  }
  else if(turn == false)
  {
    analogWrite(pinLedR,0);
    analogWrite(pinLedG,0);
    analogWrite(pinLedB,0);
  }
}
void Autumn()
{
  if(turn == true)
  {
    analogWrite(pinLedR,255);
    analogWrite(pinLedG,160);
    analogWrite(pinLedB,50);
  }
  else if(turn == false)
  {
    analogWrite(pinLedR,0);
    analogWrite(pinLedG,0);
    analogWrite(pinLedB,0);
  }
}
void Winter()
{
  if(turn == true)
  {
    analogWrite(pinLedR,198);
    analogWrite(pinLedG,226);
    analogWrite(pinLedB,255);
  }
  else if(turn == false)
  {
    analogWrite(pinLedR,0);
    analogWrite(pinLedG,0);
    analogWrite(pinLedB,0);
  }
}

void Change(){
  if(turn==true)
  {
    change = true;
    analogWrite(pinLedR,colorR);
    analogWrite(pinLedG,colorG);
    analogWrite(pinLedB,colorB);
  }
  else if(turn==false)
  {
    change = false;
    analogWrite(pinLedR,0);
    analogWrite(pinLedG,0);
    analogWrite(pinLedB,0);
  }
}
void ChangeColor(){
    colorR = map(colorR,0,1023,0,225);
    colorG = map(colorG,0,1023,0,225);
    colorB = map(colorB,0,1023,0,225);
    Serial.println("changecolor");
}
