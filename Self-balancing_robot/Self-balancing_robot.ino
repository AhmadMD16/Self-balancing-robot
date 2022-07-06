#include "Wire.h"
#define A 4
#define B 5
#define C 6
#define D 7
#define E 8
#define F 9
#define G 10
#define H 11
#define time_delay 1
#define val 2

const int MPU_ADDR = 0x68;
int16_t x, y;
char tmp_str[7];

void setup() {
  Serial.begin(9600);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(H, OUTPUT);
  Wire.begin();
  Wire.beginTransmission(MPU_ADDR); 
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
}

void write(int a, int b, int c, int d) {
  digitalWrite(A, a);
  digitalWrite(B, b);
  digitalWrite(C, c);
  digitalWrite(D, d);
  digitalWrite(E, d);
  digitalWrite(F, c);
  digitalWrite(G, b);
  digitalWrite(H, a);
}

void motor_forward() {
  write(1, 0, 0, 0);
  delay(time_delay);
  write(1, 1, 0, 0);
  delay(time_delay);
  write(0, 1, 0, 0);
  delay(time_delay);
  write(0, 1, 1, 0);
  delay(time_delay);
  write(0, 0, 1, 0);
  delay(time_delay);
  write(0, 0, 1, 1);
  delay(time_delay);
  write(0, 0, 0, 1);
  delay(time_delay);
  write(1, 0, 0, 1);
  delay(time_delay);
}

void motor_backward() {
  write(1, 0, 0, 1);
  delay(time_delay);
  write(0, 0, 0, 1);
  delay(time_delay);
  write(0, 0, 1, 1);
  delay(time_delay);
  write(0, 0, 1, 0);
  delay(time_delay);
  write(0, 1, 1, 0);
  delay(time_delay);
  write(0, 1, 0, 0);
  delay(time_delay);
  write(1, 1, 0, 0);
  delay(time_delay);
  write(1, 0, 0, 0);
  delay(time_delay);
}

void loop() {
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_ADDR, 7 * 2, true);
  
  x = Wire.read() << 8 | Wire.read();
  x = map(x, -17000, 17000, -100, 100);

  Serial.println(x);

  if(x < (4-val)) {
    Serial.println("forwards");
    motor_forward();
  }

  if (x > (4+val))
  {
    Serial.println("backwards");
    motor_backward();
  }
}
