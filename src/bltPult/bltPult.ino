// d = down
// u = up
// r = right
// l = left
// w = weapon
// s = start 
// Обозначения для приложения пульта

#include <SoftwareSerial.h>

SoftwareSerial Bluetooth(10, 9); // RX, TX 

int val; // переменная для приема команды
int LED = 13;


void setup(){
  Bluetooth.begin(9600);
  Serial.begin(9600);
  Serial.println("Ожидание команды...");
  pinMode(13, OUTPUT);
}

void loop(){
  if (Bluetooth.available()){ // проверка наличия команд
    val = Bluetooth.read(); // чтение команды
    Serial.println(val);
    if (val == 'u') { // проверка команды
        digitalWrite(LED, HIGH);
        delay(1000);
        digitalWrite(LED, LOW);
      } 
    
    else if (val == 'd') {
      digitalWrite(LED, HIGH);
      delay(750);
      digitalWrite(LED, LOW);
      delay(750);
    }
    
    if (val == 'o') {} 
      // Комадны для выполнения
    }
  
}
