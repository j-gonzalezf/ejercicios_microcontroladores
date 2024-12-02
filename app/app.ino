bool publishing = false;
unsigned long previous_time = 0;
unsigned long interval = 1000;
enum Mode { FIXED, ALTERNATIVE };
Mode mode = FIXED;
bool alternate = false;
int value = 1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial());
  print_help();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    manage_command(command);
  }

  if (publishing) {
    // con delay se bloquearía el programa
    unsigned long current_time = millis();

    if (current_time - previous_time >= interval) {
      previous_time = current_time;
      publish_value();
    }
  }
}

void manage_command(String c) {
  // switch no funciona con cadenas en C++
  if (c.equalsIgnoreCase("H")) {

    print_help();
  
  } else if (c.equalsIgnoreCase("START")) {

    publishing = true;
  
  } else if (c.equalsIgnoreCase("STOP")) {
  
    publishing = false;
  
  } else if (c.equalsIgnoreCase("T")) {

    Serial.println("Introduce un valor entre 1 y 10 para cambiar el periodo de publicación: ");
    while (!Serial.available()) {}
    delay(10);
    int new_interval = Serial.parseInt();

    if (new_interval >= 1 && new_interval <= 10) {
      interval = 1000 / new_interval;

      Serial.print("El nuevo periodo de publicación es ");
      Serial.println(new_interval);
    } else {
      Serial.println("Valor no válido. Debes introducir un valor entre 1 y 10.");
    }

    // limpia el buffer para evitar mensajes indeseados
    while (Serial.available()) {
      Serial.read();
    }

  } else if (c.equalsIgnoreCase("M")) {

    mode = (mode == FIXED) ? ALTERNATIVE : FIXED;
    if (mode == FIXED) {
      Serial.println("Cambiado a modo fijo.");
    } else {
      Serial.println("Cambiado a modo alternativo.");
    }

  } else {
    
    Serial.println("Este comando no existe, prueba otra vez.");
  
  }
}

void print_help() {
  Serial.println("H o h (help): muestra este menu de ayuda.");
  Serial.println("START o start: publica cada segundo un valor por el puerto serie.");
  Serial.println("STOP o stop: detiene la publicación del valor.");
  Serial.println("T o t (time): El siguiente valor enviado cambiará el periodo de publicación de la señal entre 1 y 10 veces por segundo.");
  Serial.println("M o m (mode): cambia el modo de fijo a alternativo. " +
  String("En modo fijo la señal se emite mantiene siempre el mismo valor siendo el ultimo emitido, por defecto debe ser un 1. ") +
  String("Por otra parte, en modo alternativo cada vez que se publica el valor se alterna entre 0 y 1."));
}

void publish_value() {
  if (mode == FIXED) {
    Serial.println(value);
  } else {
    Serial.println(alternate ? 1 : 0);
    alternate = !alternate;
  }
}
