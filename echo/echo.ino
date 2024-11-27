// diferencia entre el valor ASCII de 'a' y 'A'
int difference = 'a' - 'A';

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    char received_data = Serial.read();
    char converted_data;

    converted_data = data_convert(received_data);

    Serial.write(converted_data);
  }
}

char data_convert(char c) {
  if (c >= 'A' && c <= 'Z') {
    return c + difference;
  } else if (c >= 'a' && c <= 'z') {
    return c - difference;
  } else {
    return c;
  }
}
