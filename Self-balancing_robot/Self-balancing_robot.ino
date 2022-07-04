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
  motor_forward();
  delay(3);
  motor_backward();
  delay(3);
}
