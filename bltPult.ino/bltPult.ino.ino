  // d = down
// u = up
// r = right
// l = left
// w = weapon
// s = start 
// Обозначения для приложения пульта

// 1й двигатеь

#define IN1 10
#define IN2 9
#define enA 8

// 2й двигатель

#define IN3 7
#define IN4 6
#define enB 5

int val; // переменная для приема команды

void setup(){
  Serial.begin(9600);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop(){
  if (Serial.available()){ // проверка наличия команд
    
    val = Serial.read(); // чтение команды
    
    if (val == 'u') { // проверка команды
        digitalWrite(IN2, HIGH);
        delay(1000);
        digitalWrite(IN2, LOW);
      } 
    
    if (val == 'd') {
      digitalWrite(IN3, HIGH);
      delay(750);
      digitalWrite(IN3, LOW);
      delay(750);
    }
    
    if (val == 'o') {} 
      digitalWrite(IN3, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(13, HIGH);
      delay(650);
      digitalWrite(13, LOW);
      delay(650);
    }
  
}
