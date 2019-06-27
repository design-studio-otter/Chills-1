// d = down
// u = up
// r = right
// l = left
// w = weapon
// s = start
// Обозначения для приложения пульта

//
// Мотор А - левое колесо
// Мотор B - правое колесо



#include <SoftwareSerial.h>

SoftwareSerial Bluetooth(10, 11); // RX, TX

int val; // переменная для приема команды
int LED = 13; // L-светодиод для свидетельства выполнения команд

// инициализируем оружие

int wn = 4;

// Сопоставляем пины на Arduino с пинами на плате L298N.
int in2 = 7;
int in1 = 6;
int enA = 3;

int in4 = 9;
int in3 = 8;
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
  pinMode(wn, OUTPUT);
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

// Включение оружия
void weaponOn() {
  digitalWrite(wn, HIGH);
  delay(250);
  digitalWrite(wn, LOW);
  delay(250);
}

// Выключение оружия

void weaponOff() {
  digitalWrite(wn, LOW);
}
void loop() {
   if (Bluetooth.available()){ // проверка наличия команд
    val = Bluetooth.read(); // чтение команды
    Serial.write(val);
    // проверка команды
    if (val == 'u') { // движение вперед
        // действия для выполнения
        turnForthMotorA();
        Bluetooth.println("up"); // сообщение в Bluetooth порт для ручной проверки успешности выполнения
        Serial.println("Движение вперед"); // сообщение в Serial порт компьюетра для ручной проверки успешности выполнения
      }

    else if (val == 'd') { // движение назад
      turnBackMotorA();
      turnBackMotorB();
      Bluetooth.println("down");
      Serial.println("Движение назад");
    }

    else if (val == 'r') { // движение направо

      turnForthMotorA();
      turnOffMotorB();
      Bluetooth.println("right");
      Serial.println("Поворот направо");
    }
    else if (val == 'l') { // движение налево

      turnForthMotorB();
      turnOffMotorA();
      Bluetooth.println("left");
      Serial.println("Поворот налево");
    }
    else if (val == 'w') { // огонь.
      weaponOn();
      Bluetooth.println("Огонь");
      Serial.println("Огонь");
    }
    else if (val == '4'){ // окончание огня.
      weaponOff();
      Bluetooth.println("Огонь прекращен");
      Serial.println("Огонь прекращен");
    }
    else if (val == 'o') { // выключение всех моторов, остановка.
      turnOffMotorA();
      turnOffMotorB();
      weaponOff();
      Bluetooth.println("Все моторы остановлены");
      Serial.println("Все моторы остановлены");
    }

    else if (val == '0') { // окончание движения вперед.
      turnOffMotorA();
      Bluetooth.println("Движение вперед закончено");
      Serial.println("Движение вперед закончено");
    }
    else if (val == '1'){ // окончание поворота налево.
      turnOffMotorB();
      Bluetooth.println("ДВжиение налево закончено");
      Serial.println("Движение налево закончено");
    }
    else if (val == '2'){ // окончание движения назад.
      turnOffMotorA();
      turnOffMotorB();
      Bluetooth.println("Двжиение назад закончено");
      Serial.println("Движение назад закончено");
    }
    else if (val == '3'){ // окончание поворота направо.
      turnOffMotorA();
      Bluetooth.println("Двжиение направо закончено");
      Serial.println("Движение направо закончено");
    }
  }
}
