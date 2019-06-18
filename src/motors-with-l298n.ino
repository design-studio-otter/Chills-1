int in2 = 12;
int in1 = 11;
int enA = 3;

int in4 = 10;
int in3 = 9;
int enB = 5;

void setup() {

    pinMode(enA, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);

    pinMode(enB, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);

}

// void TurnMotorA() {
//     digitalWrite(in1, HIGH);
//     digitalWrite(in2, LOW);
// }

// void TurnOFFA() {
//     digitalWrite(in1, LOW);
//     digitalWrite(in2, LOW);
// }

void loop() {

    digitalWrite(in2, HIGH);
    digitalWrite(in1, LOW);
    analogWrite(enA, 100);

    digitalWrite(in4, HIGH);
    digitalWrite(in3, LOW);
    analogWrite(enB, 200);

    delay(100);

}
