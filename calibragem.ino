
#include "HX711.h"

float fator_de_calibracao = 1000;
float peso = 1.000;
HX711 balanca_aero;
HX711 balanca_aero2;

void calibrar_balanca();

void setup() {
  Serial.begin(9600);
//  balanca_aero.begin(saida,entrada);  
//  balanca_aero2.begin(saida2,entrada2);  
  balanca_aero.set_scale();
  balanca_aero2.set_scale();
  balanca_aero.tare();
  balanca_aero2.tare();

}

void loop() {
 
}

void calibrar_balanca(HX711 balanca){
  balanca.set_scale(fator_de_calibracao);
  aux = balanca.get_unit();
  if(aux > peso){
    
    }
   else if(aux < peso){
    
    }
    else{
      return
      } 
  
 }