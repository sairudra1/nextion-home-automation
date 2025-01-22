#include <EEPROM.h>
int light = 3;
int fan = 4;
int socket = 5;
int lamp = 6;
int load1, load2, load3, load4;
int main;
String data_display = "";
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
  // put your main code here, to run repeatedly:
  switching();
}
void switching() {
  if (main) {
    digitalWrite(light, load1);
    digitalWrite(fan, load2);
    digitalWrite(socket, load3);
    digitalWrite(lamp, load4);
  }
  else{
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
