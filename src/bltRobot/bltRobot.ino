// d = down
// u = up
// r = right
// l = left
// w = weapon
// s = start 
// Обозначения для приложения пульта

#include <SoftwareSerial.h>

SoftwareSerial Bluetooth(8, 7); // RX, TX 

int val; // переменная для приема команды
int LED = 13; // L-светодиод для свидетельства выполнения команд


// Сопоставляем пины на Arduino с пинами на плате L298N.
int in2 = 12;
int in1 = 11;
int enA = 3;

int in4 = 10;
int in3 = 9;
int enB = 5;


void setup() {
// Устанавилваем режим работы Bluetooth-прередатчика
  Bluetooth.begin(9600);
// Тестовая команда для проверки работоспособности модуля
  Bluetooth.println("Ожидание команды...");
  Serial.begin(9600);
  Serial.println("Ожидание команды...");

// Устанавливаем режим работы пинов на "выход".
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(13, OUTPUT);
}


// Мотор A крутится вперёд.
void turnForthMotorA() {
    digitalWrite(in2, HIGH); // Ток будет идти от HIGH к LOW.
    digitalWrite(in1, LOW);
    analogWrite(enA, 100); // Задаём силу вращения мотора.
}

// Мотор A крутится назад.
void turnBackMotorA() {
    digitalWrite(in2, LOW);
    digitalWrite(in1, HIGH);
    analogWrite(enA, 100);
}

// Мотор A выключается.
void turnOffMotorA() {
    digitalWrite(in2, LOW);
    digitalWrite(in1, LOW);
}

// Мотор B крутится вперёд.
void turnForthMotorB() {
    digitalWrite(in4, HIGH);
    digitalWrite(in3, LOW);
    analogWrite(enB, 100);
}

// Мотор B крутится назад.
void turnBackMotorB() {
    digitalWrite(in4, LOW);
    digitalWrite(in3, HIGH);
    analogWrite(enB, 100);
}

// Мотор B выключается.
void turnOffMotorB() {
    digitalWrite(in4, LOW);
    digitalWrite(in3, LOW);
}


void loop() {
   if (Bluetooth.available()){ // проверка наличия команд
    val = Bluetooth.read(); // чтение команды
    Serial.write(val);    
    if (val == 'u') { // проверка команды
        turnForthMotorA();
        Bluetooth.println("up");
        
      } 
    
    else if (val == 'd') {
      
      Bluetooth.println("down");
    }
    
    else if (val == 'r') { 
      
      Bluetooth.println("right"); 
    }
    else if (val == 'l') {
      
      Bluetooth.println("left");  
    }
    else if (val == 'w') {
     
      Bluetooth.println("FIRE!!!");
    }
    else if (val == 'o') {
      turnOffMotorA();
      turnOffMotorB();
      Bluetooth.println("Motors are stopped");
    }
  } 
}
