TM
==

Turing Machine para Arduino

Construção de uma TM utilizando o Arduino MEGA para demonstração acadêmica do seu funcionamento.

#Funcionalidades:

  * Controle da posição da fita via comando externo;
  * Definição do valor da fita via comando externo e interface serial;
  * Execução e Reset via comando externo.

#Futuras Funcionalidades:

  * Criação dos estados da TM de forma dinâmica.

#Limitações:

  * As saídas do Arduino para FITA, POSIÇÕES e ESTADOS são criadas em seqüência. Porém não há limite para a quantidade de cada uma, até a total utilização de todas as portas DIGITAIS disponíveis.
  * Os pinos do Arduino 0 e 1 são utilizados para comunicação serial e não estão disponíveis para outra utilização.
  * Para maximizar a utilização de portas o INICIO e TÉRMINO da fita são indicados desligando a saída de POSIÇÕES.
