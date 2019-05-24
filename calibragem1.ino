
#include "HX711.h"

// definir pinos de entradas 
#define CLOCK D6
#define DATA D7

float fator_de_calibracao = 1000;
float fator_de_calibracao2 = 1000;

// peso conhecido para ser usado como base
float peso = 1.000;
float peso2 = 1.000;


HX711 balanca_aero;
HX711 balanca_aero2;

void calibrar_balanca(HX711 balanca,float calibracao_fator);

void setup() {
  Serial.begin(9600);
//  balanca_aero.begin(saida,entrada);  
//  balanca_aero2.begin(saida2,entrada2);  
  balanca_aero.set_scale();
  balanca_aero2.set_scale();
  //zerar balança
  balanca_aero.tare();
  balanca_aero2.tare();
//  pinMode(DATA, INPUT);

}

void loop() {
  calibrar_balanca( balanca_aero, fator_de_calibracao, peso);
  calibrar_balanca( balanca_aero, fator_de_calibracao2, peso2);
  
  delay(1000);
}

void calibrar_balanca(HX711 balanca,float calibracao_fator, float peso){
  balanca.set_scale(fator_de_calibracao);
 float aux = balanca.get_units();
  if(aux > peso){
    do{
      calibracao_fator++;
      balanca.set_scale(calibracao_fator);
      aux = balanca.get_units();
      
      }while(aux>peso);
      Serial.print(calibracao_fator);
      delay(1000);
    }
    
   else if(aux < peso){
    
      do{
       calibracao_fator--;
       balanca.set_scale(calibracao_fator);
       float aux = balanca.get_units();
      }while(aux< peso);
      
      Serial.print(calibracao_fator);
      delay(1000);
    
    }
    else{
      
      Serial.print(calibracao_fator);
      delay(1000);
      
     } 
  
 }

