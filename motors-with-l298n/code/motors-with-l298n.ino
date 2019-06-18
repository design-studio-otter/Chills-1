// Сопоставляем пины на Arduino с пинами на плате L298N.
int in2 = 12;
int in1 = 11;
int enA = 3;

int in4 = 10;
int in3 = 9;
int enB = 5;

void setup() {
// Устанавливаем режим работы пинов на "выход".
    pinMode(enA, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);

    pinMode(enB, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);

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

// Пример использования этих функций.
    turnForthMotorA();
    delay(2000);
    turnBackMotorA();
    delay(2000);
    turnOffMotorA();
    turnForthMotorB();
    delay(2000);
    turnBackMotorB();
    delay(2000);
    turnOffMotorB();

    delay(100);

}
