#include "HX711.h"
//#define pinos de saida
//#define pinos de entrada 
float fator_de_calibracao1 = 1000;
float fator_de_calibracao2 = 1000;

HX711 balanca_aero;
HX711 balanca_aero2;

void setup() {
  Serial.begin(9600);
//  balanca_aero.begin(pino saida,pino entrada);
//  balanca_aero2.begin(pino saida,pino entrada);
  Serial.print("\t\tcomeçou\n");
  balanca_aero.set_scale(fator_de_calibracao1);
  balanca_aero2.set_scale(fator_de_calibracao2);
  
}

void loop() {
  balanca_aero.tare();
  balanca_aero2.tare();
  float peso1 = balanca_aero.get_unit();
  float peso2 = balanca_aero2.get_unit();

//  chamar as funçoes
// peso, arrasto..... passando peso como parametro
}
