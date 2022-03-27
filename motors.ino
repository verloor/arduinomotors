char val;
int IN1 = 4;//направление левый
int EN1 = 6;//speed левый
int IN2 = 7;//направление правый
int EN2 = 5;//speed правый
int IN3 = 4;
int EN3 = 6;
int IN4 = 7;
int EN4 = 5;
#include <Wire.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(8, 9);
void setup()
{
   mySerial.begin(9600);
  Serial.begin(9600); // скорость передачи
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(EN1, OUTPUT);
  pinMode(EN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(EN3, OUTPUT);
  pinMode(EN4, OUTPUT);
}

void loop()
{

  if (mySerial.available())
  {
    val = mySerial.read();
    if (val == 'W') // При получении символа "W" движемся вперед
    {
      digitalWrite(IN1, HIGH);
      analogWrite(EN1, 255);
      digitalWrite(IN2, HIGH);
      analogWrite(EN2, 255);
      digitalWrite(IN3, HIGH);
      analogWrite(EN3, 255);
      digitalWrite(IN4, HIGH);
      analogWrite(EN4, 255);
    }
    if (val == 'S') // При получении символа "S" движемся назад
    {
      digitalWrite(IN1, LOW);
      analogWrite(EN1, 255);
      digitalWrite(IN2, LOW);
      analogWrite(EN2, 255);
      digitalWrite(IN3, LOW);
      analogWrite(EN3, 255);
      digitalWrite(IN4, LOW);
      analogWrite(EN4, 255);
    }
    if (val == 'A'){ // При получении символа "A" движемся влево
      digitalWrite(IN1, HIGH);
      analogWrite(EN1, 255);
      digitalWrite(IN2, LOW);
      analogWrite(EN2, 255);
      digitalWrite(IN3, HIGH);
      analogWrite(EN3, 255);
      digitalWrite(IN4, LOW);
      analogWrite(EN4, 255);
    }
    if (val == 'D'){ // При получении символа "D" движемся вправо
      digitalWrite(IN1, LOW);
      analogWrite(EN1, 255);
      digitalWrite(IN2, HIGH);
      analogWrite(EN2, 255);
      digitalWrite(IN3, LOW);
      analogWrite(EN3, 255);
      digitalWrite(IN4, HIGH);
      analogWrite(EN4, 255);
    }
    //---------- Стоп режим —-------------
    // При отпускании клавиш в программе в порт шлется "T"
    if ( val == 'T') // При нажатии клавиши "T"
    {
      // Выводы ENABLE притянуты к минусу, моторы не работают
      digitalWrite(EN1, LOW);
      digitalWrite(EN2, LOW);
      digitalWrite(EN3, LOW);
      digitalWrite(EN4, LOW);
    }  
  }
}
