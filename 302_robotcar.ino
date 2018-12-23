
//1 is left motor, 2 is right motor
//f is forward, b is backward


const int motor1f = 3;//2 on h-bridge
const int motor1b = 2;//7 on h-bridge
const int motor1enable = 10;//1 on h-bridge left enable
const int motor2f = 5;//15 on h-bridge
const int motor2b = 4;//10 on h-bridge
const int motor2enable = 9;//9 on h-bridge right enable

//const int onPin = 13;


//hello friends still gotta figure out that red line shit
const int lphoto = A5;
const int mphoto = A4;
const int rphoto = A3;
const int lIRsense = A2;
const int mIRsense = A1;
const int rIRsense = A0;

//int RED
int diffThreshold= 75;
int stepdelay = 20000;
int danger = 200;
int BLACK_VAL = 240;
int WHITE_VAL = 370;
int RED_VAL = 340;

int motor1fstate = LOW;
int motor1enablestate = LOW;
int motor2fstate = LOW;
int motor2bstate = LOW;
int motor2enablestate = LOW;

void enableRightMotor()
{
  digitalWrite(motor2enable, HIGH);
}

void enableLeftMotor()
{
  digitalWrite(motor1enable, HIGH);
}
void BreakRight()
{
  digitalWrite(motor2enable, LOW);
}
void BreakLeft()
{
  digitalWrite(motor1enable, LOW);    
}
void goForward()
{
  digitalWrite(motor1f, HIGH);
 

  digitalWrite(motor1b, LOW);
  
  digitalWrite(motor2f, HIGH);
 
  
  digitalWrite(motor2b, LOW);

    digitalWrite(motor2f, HIGH);
 
  
  digitalWrite(motor2b, LOW);
}

void turnCW()
{
  digitalWrite(motor1f, HIGH);

  
  digitalWrite(motor1b, LOW);
  digitalWrite(motor2f, LOW);
  
  digitalWrite(motor2b, HIGH);


}

void turnCCW()
{
  digitalWrite(motor1f, LOW);
  
;
  digitalWrite(motor1b, HIGH);
  
  digitalWrite(motor2f, HIGH);

  
  digitalWrite(motor2b, LOW);

}

void goBack()
{
  digitalWrite(motor1f, LOW);
  
  digitalWrite(motor1b, HIGH);


  
  digitalWrite(motor2f, LOW);
  

  digitalWrite(motor2b, HIGH);

}


void setup() 
{
  // put your setup code here, to run once:
  
  //digitalWrite(onPin, HIGH);
  Serial.print("Hope we move\n");
  pinMode(motor1f, OUTPUT); 
  pinMode(motor1b, OUTPUT);
  pinMode(motor2f, OUTPUT);
  pinMode(motor2b, OUTPUT);
  pinMode(motor1enable, OUTPUT);
  pinMode(motor2enable, OUTPUT);
  digitalWrite(motor1enable, HIGH);
  digitalWrite(motor2enable, HIGH);

  Serial.begin(9600);

}

void loop() 
{
  int lphotoval = analogRead(lphoto);
  int mphotoval = analogRead(mphoto);
  int rphotoval = analogRead(rphoto);
  int lIRval = analogRead(lIRsense);
  int mIRval = analogRead(mIRsense);
  int rIRval = analogRead (rIRsense);
  // put your main code here, to run repeatedly:

  Serial.println("LMR photo: ");
  Serial.println(lphotoval, DEC);
  Serial.println(mphotoval, DEC);
  Serial.println(rphotoval, DEC);

  Serial.println("LMR IR: ");
  Serial.println(lIRval, DEC);
  Serial.println(mIRval, DEC);
  Serial.println(rIRval, DEC);
  
  enableLeftMotor();
  enableRightMotor();
  
    if (mIRval >= danger)
    {
      Serial.println("Block detected");
      BreakLeft();
      BreakRight();
    }
    
    /*
    else if (rIRval>= danger)//checks if the bonus course happened
    {
      Serial.println("Trynna get between walls. . .");
      turnCCW();
    }
    else if (lIRval>= danger)
    {
      Serial.println("Still trynna get between walls. . .");
      turnCW();
    }
   */
   
    if (mphotoval<= BLACK_VAL + diffThreshold && mphotoval<lphotoval && mphotoval<rphotoval)
    {
      Serial.println("Going forward!");
      goForward();
    }

    else if ((rphotoval<BLACK_VAL + diffThreshold && mphotoval<BLACK_VAL + diffThreshold) || (rphotoval<mphotoval && rphotoval<lphotoval))
    {
      Serial.println("Turning right. . .");
      turnCW();
    }
    else if ((lphotoval<BLACK_VAL + diffThreshold && mphotoval<BLACK_VAL + diffThreshold) || (lphotoval<mphotoval && lphotoval<rphotoval))
    {
      Serial.println("Turning left. . .");
      turnCCW();
      turnCCW();
    } 
/*    else if ((mphotoval>=RED_VAL && lphotoval>=RED_VAL && rphotoval>= RED_VAL) && max(lphotoval, mphotoval)<WHITE_VAL)
    {
      Serial.println("Red line detected!");
      takeBreak();
    }
*/
    
    else
    {
      Serial.println("Going forward!");
      goForward();
    }
  
  delay(100);//
  BreakLeft();//shut off motors for a lil
  BreakRight();
  delay(1000); //delay a little to prepare for another reading
}
