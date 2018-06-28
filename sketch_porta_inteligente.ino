#include <Servo.h>  // Inclusão da biblioteca Servo
#define echoPin 13  // Define o pino digital 13 do arduino como echo do sensor ultrasonico
#define trigPin 12  // Define o pino digital 12 do arduino como trig do sensor ultrasonico


Servo servo_objeto; // cria um objeto (servo_objeto) que é do tipo Servo, esse objeto faz chamadas ao metodos attach(), write()


int posicao_inicial_servo = 0;  // Seta a posição inicial do servo motor como = 0
int ledPin =  10;               // Seta o pino digital como corrente para o LED

long readUltrasonicDistance(int pin)
{
  pinMode(pin, OUTPUT);   
  digitalWrite(pin, LOW);
  delayMicroseconds(2);
  // Sets the pin on HIGH state for 10 micro seconds
  digitalWrite(pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pin, LOW);
  pinMode(pin, INPUT);
  // Reads the pin, and returns the sound wave travel time in microseconds
  return pulseIn(pin, HIGH);
}

void setup() 
{    
  Serial.begin(9600); 
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  servo_objeto.attach(9);
}

void loop() 
{ 
   digitalWrite(ledPin, LOW);  
   servo_objeto.write(posicao_inicial_servo);
   int valor = 0.01723 * readUltrasonicDistance(13);
   if(valor <=15)
   {
        func_controladora();
       //delay(5000); 
   }
 
  delay(500);
}

void func_controladora()
{
   func_liga_led();
   func_chama_servo();
}

void func_chama_servo()
{
 servo_objeto.write(0);
  delay(500);
  int posicao_final_servo = 90;
  servo_objeto.write(posicao_final_servo);
}

void func_liga_led()
{
  digitalWrite(ledPin, HIGH);
}

/*int func_distancia_ultrasonico()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
 
  digitalWrite(trigPin, LOW);
  int distancia = (ultrasonic.Ranging(CM));
  Serial.print("Distancia em CM: ");
  Serial.println(distancia);
  return distancia;
}*/
