# Balanca Aerodinamica

Balança Aerodinâmica é um projeto de estudantes de Engenharia da Universidade de Brasília, Faculdade do Gama (FGA), que tem como objetivo construir uma balança para testar perfis de asa dentro de um túnel de vento.

## Requisitos:

- Arduino IDE instalado.

- Arquivos calibracao.ino e balanca_aero.ino.

- Ter biblioteca HX711 baixada.

- Massa conhecida.

  

### Como Utilizar:

Em cada algoritmo importe a biblioteca "HX711.h".

 1. É necessário encontrar os fatores de calibração para que as medições
	tenham precisão.
	Abra o arquivo calibracao.ino, excute-o , após iniciar as medições adicione 		a massa conhecida e altere o fator de calibração até que o valor retornado seja próximo à massa conhecida.
	### Fator de calibração arrasto:

	As teclas "a","s","d","f" são responsáveis por aumentar o fator em +10,+100,+1000,+10000.
  
  As teclas "z","x","c","v" diminuem o fator em -10,-100,-1000,-10000.
  
  A tecla "t" é responsável por zerar a balança.

### Fator de calibração sustentação:

  As teclas "h","j","k","l" são responsáveis por aumentar o fator em +10,+100,+1000,+10000.
  
  As teclas "u","i","o","p" diminuem o fator em -10,-100,-1000,-10000.
	
  A tecla "y" é responsável por zerar a balança.

  Após encontrar os valores dos fatores, anote-os porque serão utilizados no algoritmo balanca_aero.ino.

  

2. No algoritmo balanca_aero.ino substitua os valores dos fatores encontrados anteriormente.
	Inicie o código com o túnel de vento desligado.Após iniciar as medições, ligue o túnel.

  

Os algoritmos utilizados(calibracao.ino e balanca_aero.ino)são adaptação dos códigos disponíveis em : [http://blog.eletrogate.com/balanca-digital-com-arduino-aprenda-a-usar-a-celula-de-carga/](http://blog.eletrogate.com/balanca-digital-com-arduino-aprenda-a-usar-a-celula-de-carga/)

  

HX711.h disponível em: [https://github.com/bogde/HX711](https://github.com/bogde/HX711)
