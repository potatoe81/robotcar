const int motor1f = 3;//2 on h-bridge
const int motor1b = 2;//7 on h-bridge
const int motor1enable = 10;//1 on h-bridge left enable
const int motor2f = 5;//15 on h-bridge
const int motor2b = 4;//10 on h-bridge
const int motor2enable = 9;//9 on h-bridge right enable


void setup() {
  // put your setup code here, to run once:
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

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("we here");
  digitalWrite(motor1enable, LOW);
  digitalWrite(motor1enable, LOW);
  digitalWrite(motor1f, LOW);
  digitalWrite(motor1b, LOW);
  digitalWrite(motor2f, LOW);
  digitalWrite(motor2b, LOW);
  delay(1000);

  digitalWrite(motor1enable, HIGH);
  Serial.println("left enable");
  delay(5000);
  
  digitalWrite(motor2enable, HIGH);
  Serial.println("right enable");
  delay(5000);
  
  digitalWrite(motor1f, LOW);
  delay(2000);
  
  digitalWrite(motor1b, HIGH);
  Serial.println("back left motor");
  delay(2000);
  
  digitalWrite(motor2f, LOW);
  Serial.println("front right motor");
  delay(2000);
  
  digitalWrite(motor2b, HIGH);
  Serial.println("back right motor");
  delay(2000);
}
