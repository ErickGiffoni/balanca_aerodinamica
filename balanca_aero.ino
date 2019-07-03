#include "HX711.h"

//pinos de entrada
#define pino_entrada1 A0
#define pino_entrada2 A4
//pinos de clock
#define pino_clock1 A1
#define pino_clock2 A5

float fator_de_calibracao1 = 1863150.00;
float fator_de_calibracao2 = 390200.00;

HX711 balanca_aero_arrasto;
HX711 balanca_aero_sustentacao;

//dados para as funçoes de arrasto e de sustentacao
double fg = 9.81; // m/s^2 - aceleracao gravitacional
double corda = 0.079; // m - 8 cm
double densidade_do_fluido = 1.225/1.11; // kg/m^3
float velocidade = 11.15; // m/s
double velocidade_2 = velocidade*velocidade; // mˆ2/sˆ2 - velocidade ao quadrad
float envergadura = 0.145;
float massa1 = 0.0, massa2 = 0.0;


void setup() {
  Serial.begin(9600);

  balanca_aero_arrasto.begin(pino_entrada1, pino_clock1);
  balanca_aero_sustentacao.begin(pino_entrada2, pino_clock2);

  Serial.print("\t\tProjeto Integrador de Engenharia 1\n");
  Serial.print("\t\tUniversidade de Brasília - Faculdade do Gama\n\n");
  Serial.print("\t\t\t\tBALANÇA AERODINÂMICA\n\n\n");
  balanca_aero_arrasto.set_scale();
  balanca_aero_sustentacao.set_scale();
  
  //define o fator de calibracao
  balanca_aero_arrasto.tare();
  balanca_aero_sustentacao.tare();
}

void loop() {
  //zera a balanca
  balanca_aero_arrasto.set_scale(fator_de_calibracao1);
  balanca_aero_sustentacao.set_scale(fator_de_calibracao2);

  //get_units realizara a media dos 15 valores de  massas medidas
  massa1 = balanca_aero_arrasto.get_units(15);
  massa2 = balanca_aero_sustentacao.get_units(15);
  massa1 = abs(massa1);
  massa2 = abs(massa2);

  Serial.print("Massas aferidas pelas células de carga (kg) :\n\n");
  Serial.print("\t\tMassa 1(ARRASTO) = ");
  Serial.print(massa1,4);
  Serial.print("\t Força= ");
  Serial.println(massa1*fg,4);
  Serial.print("\t\tMassa 2(SUSTENTAÇÃO)= ");
  Serial.print(massa2,4);
  Serial.print("\t Força= ");
  Serial.print(massa2*fg,4);
  Serial.print("\n\n");
  
  //chamada das funcoes
  double sustentacao, arrasto ;
  sustentacao = coef_sustentacao(massa2);
  arrasto = coef_arrasto(massa1);
  
  //imprime os coeficientes
  Serial.print("Coeficientes calculados:\n\n");
  Serial.print("\t\tCoeficiente de arrasto: ");
  Serial.println(arrasto,4);
  Serial.print("\n\t\tCoeficiente de sustentação: ");
  Serial.println(sustentacao,4);
 //Atraso de 5,5 segundos
  delay(5500);
  Serial.print("------------------------------//------------------------------\n\n");
}

double coef_sustentacao(double massa_da_celula){
  return ((massa2*fg)/((0.5)*(densidade_do_fluido)*(velocidade_2)*(corda)*(envergadura)));
}

double coef_arrasto(double massa_da_celula){
  return ((massa1*fg)/((0.5)*(densidade_do_fluido)*(velocidade_2)*(corda)*(envergadura)));
}
