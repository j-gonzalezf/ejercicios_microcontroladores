int ctr = 0;
unsigned long previousTime = 0;
const long interval = 1000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentTime = millis();

  if (currentTime - previousTime >= interval) {
    previousTime = currentTime;
    Serial.println(ctr);
    ctr++;
  }
}
