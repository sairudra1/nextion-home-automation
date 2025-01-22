#include <EEPROM.h>
int light = 3;
int fan = 4;
int socket = 5;
int lamp = 6;
int load1, load2, load3, load4;
int main;
String data_display = "";
unsigned long previousMillis = 0;  // Stores the last time the function was executed
const long interval = 10000;        // Interval of 5 seconds (5000 milliseconds)

//constraints as we are using serial port for the uart comunication with nextion display
//we cannot use serial monitor for serial printing
void setup() {
  pinMode(light, OUTPUT);
  pinMode(fan, OUTPUT);
  pinMode(socket, OUTPUT);
  pinMode(lamp, OUTPUT);
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.print("page start");
  Serial.write(0xff);
  Serial.write(0xff);
  Serial.write(0xff);
  load1 = EEPROM.read(1);
  load2 = EEPROM.read(2);
  load3 = EEPROM.read(3);
  load4 = EEPROM.read(4);
  delay(5000);
  Serial.print("page one");
  Serial.write(0xff);
  Serial.write(0xff);
  Serial.write(0xff);
}

void loop() {
  if (Serial.available()) {
    data_display = "";
    while (Serial.available()) {
      data_display += char(Serial.read());
    }
    next_step(data_display);
  }
  unsigned long currentMillis = millis();  // Get the current time in milliseconds

  // Check if 5 seconds have passed
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;  // Update the time of the last execution
    HMIupdate();                     // Call the function
  }
  // put your main code here, to run repeatedly:
  switching();
}

HMIupdate() {
  if (main) {
    digitalWrite(light, load1);
    digitalWrite(fan, load2);
    digitalWrite(socket, load3);
    digitalWrite(lamp, load4);
    if (load1) {
      Serial.print("b0.pco=34784");
      Serial.write(0xff);
      Serial.write(0xff);
      Serial.write(0xff);

      Serial.print("b1.pco=34784");
      Serial.write(0xff);
      Serial.write(0xff);
      Serial.write(0xff);
    } else {
      Serial.print("b0.pco=65504");
      Serial.write(0xff);
      Serial.write(0xff);
      Serial.write(0xff);

      Serial.print("b1.pco=65504");
      Serial.write(0xff);
      Serial.write(0xff);
      Serial.write(0xff);
    }
    if (load2) {
      Serial.print("b2.pco=34784");
      Serial.write(0xff);
      Serial.write(0xff);
      Serial.write(0xff);

      Serial.print("b3.pco=34784");
      Serial.write(0xff);
      Serial.write(0xff);
      Serial.write(0xff);
    } else {
      Serial.print("b2.pco=65504");
      Serial.write(0xff);
      Serial.write(0xff);
      Serial.write(0xff);

      Serial.print("b3.pco=65504");
      Serial.write(0xff);
      Serial.write(0xff);
      Serial.write(0xff);
    }
    if (load3) {
      Serial.print("b4.pco=34784");
      Serial.write(0xff);
      Serial.write(0xff);
      Serial.write(0xff);

      Serial.print("b5.pco=34784");
      Serial.write(0xff);
      Serial.write(0xff);
      Serial.write(0xff);
    } else {
      Serial.print("b4.pco=65504");
      Serial.write(0xff);
      Serial.write(0xff);
      Serial.write(0xff);

      Serial.print("b5.pco=65504");
      Serial.write(0xff);
      Serial.write(0xff);
      Serial.write(0xff);
    }
    if (load4) {
      Serial.print("b6.pco=34784");
      Serial.write(0xff);
      Serial.write(0xff);
      Serial.write(0xff);

      Serial.print("b7.pco=34784");
      Serial.write(0xff);
      Serial.write(0xff);
      Serial.write(0xff);
    } else {
      Serial.print("b6.pco=65504");
      Serial.write(0xff);
      Serial.write(0xff);
      Serial.write(0xff);

      Serial.print("b7.pco=65504");
      Serial.write(0xff);
      Serial.write(0xff);
      Serial.write(0xff);
    }
  } else {
    Serial.print("b0.pco=0");
    Serial.write(0xff);
    Serial.write(0xff);
    Serial.write(0xff);

    Serial.print("b1.pco=0");
    Serial.write(0xff);
    Serial.write(0xff);
    Serial.write(0xff);

    Serial.print("b2.pco=0");
    Serial.write(0xff);
    Serial.write(0xff);
    Serial.write(0xff);

    Serial.print("b3.pco=0");
    Serial.write(0xff);
    Serial.write(0xff);
    Serial.write(0xff);

    Serial.print("b4.pco=0");
    Serial.write(0xff);
    Serial.write(0xff);
    Serial.write(0xff);

    Serial.print("b5.pco=0");
    Serial.write(0xff);
    Serial.write(0xff);
    Serial.write(0xff);

    Serial.print("b6.pco=0");
    Serial.write(0xff);
    Serial.write(0xff);
    Serial.write(0xff);

    Serial.print("b7.pco=0");
    Serial.write(0xff);
    Serial.write(0xff);
    Serial.write(0xff);
  }
}

void switching() {
  if (main) {
    digitalWrite(light, load1);
    digitalWrite(fan, load2);
    digitalWrite(socket, load3);
    digitalWrite(lamp, load4);
  } else {
    Serial.print("b0.pco=0");
    Serial.write(0xff);
    Serial.write(0xff);
    Serial.write(0xff);

    Serial.print("b1.pco=0");
    Serial.write(0xff);
    Serial.write(0xff);
    Serial.write(0xff);

    Serial.print("b2.pco=0");
    Serial.write(0xff);
    Serial.write(0xff);
    Serial.write(0xff);

    Serial.print("b3.pco=0");
    Serial.write(0xff);
    Serial.write(0xff);
    Serial.write(0xff);

    Serial.print("b4.pco=0");
    Serial.write(0xff);
    Serial.write(0xff);
    Serial.write(0xff);

    Serial.print("b5.pco=0");
    Serial.write(0xff);
    Serial.write(0xff);
    Serial.write(0xff);

    Serial.print("b6.pco=0");
    Serial.write(0xff);
    Serial.write(0xff);
    Serial.write(0xff);

    Serial.print("b7.pco=0");
    Serial.write(0xff);
    Serial.write(0xff);
    Serial.write(0xff);

    digitalWrite(light, 0);
    digitalWrite(fan, 0);
    digitalWrite(socket, 0);
    digitalWrite(lamp, 0);
  }
}

void next_step(String data) {
  if (data == "lighton") {
    load1 = 1;
    EEPROM.write(1, load1);
  }
  if (data == "lightoff") {
    load1 = 0;
    EEPROM.write(1, load1);
  }
  if (data == "fanon") {
    load2 = 1;
    EEPROM.write(2, load2);
  }
  if (data == "fanoff") {
    load2 = 0;
    EEPROM.write(2, load2);
  }
  if (data == "socketon") {
    load3 = 1;
    EEPROM.write(3, load3);
  }
  if (data == "socketoff") {
    load3 = 0;
    EEPROM.write(3, load3);
  }
  if (data == "lampon") {
    load4 = 1;
    EEPROM.write(4, load4);
  }
  if (data == "lampoff") {
    load4 = 0;
    EEPROM.write(4, load4);
  }
  if (data == "allon") {
    load1 = EEPROM.read(1);
    load2 = EEPROM.read(2);
    load3 = EEPROM.read(3);
    load4 = EEPROM.read(4);
  }
  if (data == "alloff") {
    main = 0;
  }
}
