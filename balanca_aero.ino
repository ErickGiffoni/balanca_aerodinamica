#include "HX711.h"

//pinos de entrada
#define
#define
//pinos de clock
#define
#define

float fator_de_calibracao1 = 1000.0;
float fator_de_calibracao2 = 1000.0;

HX711 balanca_aero;
HX711 balanca_aero2;

//dados para as funçoes de arrasto e de sustentacao
double fg = 9.81; // m/s^2 - aceleracao gravitacional
double corda = 0.08; // m - 8 cm
double densidade_do_fluido = 1.225; // kg/m^3
double velocidade = 10.0; // m/s
double velocidade_2 = velocidade*velocidade; // mˆ2/sˆ2 - velocidade ao quadrado
double massa_da_celula = 0.0; // kg

double massa1 = 0.0, massa2 = 0.0;
double sustentacao = 0.0, arrasto = 0.0;

//Assinatura das funcoes
double coef_sustentacao(double *massa_da_celula);
double coef_arrasto(double *massa_da_celula);

void setup() {
  Serial.begin(9600);

  balanca_aero.begin(pino_entrada1, pino_clock1);
  balanca_aero2.begin(pino_entrada2, pino_clock2);

  Serial.print("\t\tProjeto Integrador de Engenharia 1\n");
  Serial.print("\t\tUniversidade de Brasília - Faculdade do Gama\n\n");
  Serial.print("\t\t\t\tBALANÇA AERODINÂMICA\n\n\n");

  //define o fator de calibracao
  balanca_aero.set_scale(fator_de_calibracao1);
  balanca_aero2.set_scale(fator_de_calibracao2);

}

void loop() {
  //zera a balanca
  balanca_aero.tare();
  balanca_aero2.tare();

  //get_units realizara a media dos 5 valores de  massas medidas
  massa1 = balanca_aero.get_units(5);
  massa2 = balanca_aero2.get_units(5);

  Serial.print("Massas aferidas pelas células de carga (kg) :\n\n");
  Serial.print("\t\tMassa 1 = ");
  Serial.print(massa1);
  Serial.print("\n");
  Serial.print("\t\tMassa 2 = ");
  Serial.print(massa2);
  Serial.print("\n\n");
  //chamada das funcoes
  sustentacao = coef_sustentacao(&massa1);
  arrasto = coef_arrasto(&massa2);

  //imprime os coeficientes
  Serial.print("Coeficientes calculados:\n\n");
  Serial.print("\t\tCoeficiente de sustentação: ");
  Serial.print(sustentacao);
  Serial.print("\n\t\tCoeficiente de arrasto: ");
  Serial.print(arrasto);

  delay(1000);
  Serial.print("------------------------------//------------------------------\n\n");

}
double coef_sustentacao(double *massa_da_celula){
  return ((*massa_da_celula)/((fg)*(0.5)*(densidade_do_fluido)*(velocidade_2)*(corda)));
}

double coef_arrasto(double *massa_da_celula){
  return ((*massa_da_celula)/((0.5)*(densidade_do_fluido)*(velocidade_2)*(corda)));
}
