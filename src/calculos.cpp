/*
calcular a sustentacao L
calcular o arrasto D

L =     Cl
    1/2*p*v^2*c

D =     Cd
    1/2*p*v^2*c

p = (Rho - densidade do fluido) 1,225kg/m^3
c = (tamanho da corda da asa) 8 cm
v = (velocidade do vento)
Cl = (coef de sustentacao)
Cd = (coef de arrasto)
L = valor da célula de carga(kg) * 9,81 m/s^2

Se :
  1/2*p*v^2*c = Cl / L
e se:
  D =     Cd
      1/2*p*v^2*c
entao:
  D = Cd * L / Cl

Cl = L * 1/2*p*v^2*c
e
Cd = massa da celula(kg) * 1/2*p*v^2*c
*/

/* Variaveis globais para facilitar os calculos */
double fg = 9.81; // m/s^2 - aceleracao gravitacional
double corda = 0.08; // m - 8 cm
double densidade_do_fluido = 1.225; // kg/m^3
double velocidade = 10.0; // m/s
double velocidade_2 = velocidade*velocidade // mˆ2/sˆ2 - velocidade ao quadrado
double massa_da_celula = 0.0; // kg

/* Funcoes */

double coef_sustentacao(double *massa_da_celula){
  return ((*massa_da_celula)*(fg)*(0.5)*(densidade_do_fluido)*(velocidade_2)*(corda));
}

double coef_arrasto(double *massa_da_celula){
  return ((*massa_da_celula)*(0.5)*(densidade_do_fluido)*(velocidade_2)*(corda));
}
