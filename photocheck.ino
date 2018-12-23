const int lphoto= A5;
const int mphoto= A4;
const int rphoto= A3;
const int lIRsense = A2;
const int mIRsense = A1;
const int rIRsense = A0;


void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() 
{
  // put your main code here, to run repeatedly:
 

  int lphotoval = analogRead(lphoto);
  int mphotoval = analogRead(mphoto);
  int rphotoval = analogRead(rphoto);
  Serial.print("L photoresistor: ");
  Serial.print(lphotoval, DEC);
  Serial.print(" M photoresistor: ");
  Serial.print(mphotoval, DEC);
  Serial.print(" R photoresistor: ");
  Serial.println(rphotoval, DEC);


/*
  int lIRval = analogRead(lIRsense);
  int mIRval = analogRead(mIRsense);
  int rIRval = analogRead (rIRsense);
  Serial.print("L IR: ");
  Serial.print(lIRval, DEC);
  Serial.print(" M IR: ");
  Serial.print(mIRval, DEC);
  Serial.print(" R IR: ");
  Serial.println(rIRval, DEC);
*/

  delay(2000);

}
