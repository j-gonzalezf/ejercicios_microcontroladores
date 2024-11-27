int ctr1 = 0;
int ctr2 = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  // 20 iteraciones de 100 ms = 2 segundos
  for (int i = 0; i < 20; i++) {
    ctr1++;
    printCtr(ctr1, ctr2);
    delay(100);
  }

  ctr2++;
  ctr1 -= ctr2;
  printCtr(ctr1, ctr2);
}

void printCtr(int c1, int c2) {
  Serial.print("C1: ");
  Serial.print(c1);
  Serial.print(" C2: ");
  Serial.println(c2);
}
