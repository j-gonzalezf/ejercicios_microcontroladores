int ctr1 = 0;
int ctr2 = 0;
unsigned long previousTime1 = 0;
unsigned long previousTime2 = 0;

// 1 segundo = 1000000 microsegundos
const unsigned long interval1 = 100000;
const unsigned long interval2 = 2000000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentTime = micros();

  if (currentTime - previousTime1 >= interval1) {
    previousTime1 = currentTime;
    ctr1++;
    printCtr(ctr1, ctr2);
  }

  if (currentTime - previousTime2 >= interval2) {
    previousTime2 = currentTime;
    ctr2++;
    ctr1 -= ctr2;
    printCtr(ctr1, ctr2);
  }
}

void printCtr(int c1, int c2) {
  Serial.print("C1: ");
  Serial.print(c1);
  Serial.print(" C2: ");
  Serial.println(c2);
}
