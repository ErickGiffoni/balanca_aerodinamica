#include "HX711.h"                    // Biblioteca HX711 

//Pinos de dados 
#define DOUT1 A0    
#define DOUT2 A4                    
//pinos de clock
#define CLK1 A1 
#define CLK2 A5   
HX711 ARRASTO_HX711;   // define instancia balança HX711
HX711 SUSTENTACAO_HX711;
 
float fator_de_calibracao_arrasto = 1863150.00;   // fator de calibração para teste inicial
float fator_de_calibracao_sustentacao = 302200.00; 

void setup()
{
  Serial.begin(9600);   // monitor serial 9600 Bps
  ARRASTO_HX711.begin(DOUT1, CLK1);
  SUSTENTACAO_HX711.begin(DOUT2, CLK2);
  
  Serial.println("\nCalibração");
  Serial.println("Remova os pesos");
  Serial.println("Depois que as leituras começarem, coloque um peso conhecido sobre a Balança");
  Serial.println("Fator de calibração para o arrasto:");
  Serial.println("Pressione a,s,d,f para aumentar Fator de Calibração por 10,100,1000,10000 respectivamente");
  Serial.println("Pressione z,x,c,v para diminuir Fator de Calibração por 10,100,1000,10000 respectivamente");
  delay(3000);
  Serial.println("Fator de calibração para a sustentação:");  
  Serial.println("Pressione h,j,k,l para aumentar Fator de Calibração por 10,100,1000,10000 respectivamente");
  Serial.println("Pressione u,i,o,p para diminuir Fator de Calibração por 10,100,1000,10000 respectivamente");
  Serial.println("Após leitura correta do peso, pressione y para TARA(zerar) ");
  delay(3000);
 
  ARRASTO_HX711.set_scale();   // configura a escala da Balança
  SUSTENTACAO_HX711.set_scale();
  
  ARRASTO_HX711.tare();
  SUSTENTACAO_HX711.tare();
} 
void loop()
{
  ARRASTO_HX711.set_scale(fator_de_calibracao_arrasto);   // ajusta fator de calibração
  SUSTENTACAO_HX711.set_scale(fator_de_calibracao_sustentacao);
  
  Serial.print("Arrasto Massa: ");   
  Serial.print(ARRASTO_HX711.get_units(3),4);
  Serial.print(" kg");
  Serial.print("\t\tFator de Calibração: ");   // imprime no monitor serial
  Serial.println(fator_de_calibracao_arrasto);   // imprime fator de calibração
  Serial.print("Sustentação Massa: ");   
  Serial.print(SUSTENTACAO_HX711.get_units(3),4);
  Serial.print(" kg");
  Serial.print("\t\tFator de Calibração: ");   // imprime no monitor serial
  Serial.println(fator_de_calibracao_sustentacao);   // imprime fator de calibração
  Serial.print("\n");
  delay(2000) ;   // atraso de 0,5 segundo

 
  if (Serial.available())   // reconhece letra para ajuste do fator de calibração
  {
   char temp = Serial.read();
   
//   ARRASTO
   if (temp == '+' || temp == 'a')   // a = aumenta 10
      fator_de_calibracao_arrasto += 10;
   else if (temp == '-' || temp == 'z')   // z = diminui 10
      fator_de_calibracao_arrasto -= 10;
   else if (temp == 's')   // s = aumenta 100
      fator_de_calibracao_arrasto += 100;
   else if (temp == 'x')   // x = diminui 100
      fator_de_calibracao_arrasto -= 100;
   else if (temp == 'd')   // d = aumenta 1000
      fator_de_calibracao_arrasto += 1000;
   else if (temp == 'c')   // c = diminui 1000
      fator_de_calibracao_arrasto -= 1000;
   else if (temp == 'f')   // f = aumenta 10000
      fator_de_calibracao_arrasto += 10000;
   else if (temp == 'v')   // v = dimuni 10000
      fator_de_calibracao_arrasto -= 10000;
   else if (temp == 't')
      ARRASTO_HX711.tare();   // t = zera a Balança

//  SUSTENTAÇÃO
   else if ( temp == 'u')   // z = diminui 10
      fator_de_calibracao_sustentacao -= 10;
   else if (temp == 'j')   // s = aumenta 100
      fator_de_calibracao_sustentacao += 100;
   else if (temp == 'i')   // x = diminui 100
      fator_de_calibracao_sustentacao -= 100;
   else if (temp == 'k')   // d = aumenta 1000
      fator_de_calibracao_sustentacao += 1000;
   else if (temp == 'o')   // c = diminui 1000
      fator_de_calibracao_sustentacao -= 1000;
   else if (temp == 'l')   // f = aumenta 10000
      fator_de_calibracao_sustentacao += 10000;
   else if (temp == 'p')   // v = dimuni 10000
      fator_de_calibracao_sustentacao -= 10000;
   else if (temp == 'y')
      SUSTENTACAO_HX711.tare();
  }
}
