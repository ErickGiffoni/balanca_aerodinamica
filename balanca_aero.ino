#include "HX711.h"

//pinos de entrada
#define
#define
//pinos de clock
#define
#define

float fator_de_calibracao1 = 1000;
float fator_de_calibracao2 = 1000;

HX711 balanca_aero;
HX711 balanca_aero2;

//dodos para as funçoes de arrasto e 
double fg = 9.81; // m/s^2 - aceleracao gravitacional
double corda = 0.08; // m - 8 cm
double densidade_do_fluido = 1.225; // kg/m^3
double velocidade = 10.0; // m/s
double velocidade_2 = velocidade*velocidade // mˆ2/sˆ2 - velocidade ao quadrado
double massa_da_celula = 0.0; // kg

//Assinatura das funcoes
double coef_sustentacao(double *massa_da_celula);
double coef_arrasto(double *massa_da_celula);

void setup() {
  Serial.begin(9600);

  balanca_aero.begin(pino entrada1,pino clock1);
  balanca_aero2.begin(pino entrada2,pino clock2);
  
  Serial.print("\t\tcomeçou\n");
  
  //define o fator de calibracao
  balanca_aero.set_scale(fator_de_calibracao1);
  balanca_aero2.set_scale(fator_de_calibracao2);
  
}

void loop() {
  //zera a balanca
  balanca_aero.tare();
  balanca_aero2.tare();
  
  //get_units realizara a media dos 5 valores de  massas medidas 
  float massa1 = balanca_aero.get_units(5);
  float massa2 = balanca_aero2.get_units(5);

  //chamada das funcoes
  double sustentacao = coef_sustentacao(&massa1);
  double arrasto = coef_arrasto(&massa2);

  //imprime os coeficientes
  Serial.print("\nCoeficiente de sustentacao: ")
  Serial.print(sustentacao);
  Serial.print("\nCoeficiente de arrasto: ")
  Serial.print(arrasto);

}
double coef_sustentacao(double *massa_da_celula){
  return ((*massa_da_celula)*(fg)*(0.5)*(densidade_do_fluido)*(velocidade_2)*(corda));
}

double coef_arrasto(double *massa_da_celula){
  return ((*massa_da_celula)*(0.5)*(densidade_do_fluido)*(velocidade_2)*(corda));
}
