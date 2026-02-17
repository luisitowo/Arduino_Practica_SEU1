#include "LowPower.h"


const int pinDigital = 2;    
const int pinAnalogo = A0;   
const int ledStatus = 13;    

void setup() {
  pinMode(pinDigital, INPUT_PULLUP);
  pinMode(ledStatus, OUTPUT);
  Serial.begin(9600);
  
  Serial.println("--- INICIO DE PRÁCTICA: MEDICIÓN DE CONSUMO ---");
}

void loop() {

  digitalWrite(ledStatus, HIGH);
  Serial.println("\n[ESTADO: MODO NOMINAL]");
  

  int lecturaD = digitalRead(pinDigital);
  int lecturaA = analogRead(pinAnalogo);
  float voltaje = lecturaA * (5.0 / 1023.0);

  Serial.print("Lectura Digital (Pin 2): "); Serial.println(lecturaD);
  Serial.print("Lectura Analógica (A0): "); Serial.print(lecturaA);
  Serial.print(" -> Voltaje calculado: "); Serial.print(voltaje); Serial.println("V");
  
  Serial.println("Midiendo potencia nominal... (5 segundos)");
  delay(5000);


  Serial.println("[ESTADO: ENTRANDO A MODO SLEEP]");
  Serial.println("El monitor serie se pausará. Observe el medidor USB.");
  delay(100); 
  
  digitalWrite(ledStatus, LOW); 
  
  LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
}
