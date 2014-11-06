// --- Reinicia o Sistema, caso exista DADOS na Serial carrega para a FITA --- //

void resetSystem(void)
{
  // Zera Fita
  for (int count = 0; count <= STOPTAPE - STARTTAPE; count++){
    inputTape[count] = LOW;
    digitalWrite((STARTTAPE + count), inputTape[count]);
  }
  
  // Zera Posicao
  for (int count = STARTPOS + 1; count <= STOPPOS; count++){
    digitalWrite(count, LOW);
  }
  digitalWrite(STARTPOS, HIGH);
  positionTape = STARTPOS;
  
  // Estado Inicial
  for (int count = INITSTATE + 1; count <= ENDSTATE; count++){
    digitalWrite(count,LOW);
  }
  digitalWrite(INITSTATE, HIGH);
  state = INITSTATE;
  
  // Verifica DADOS da Serial
  if (Serial.available()) serialData();
}

void serialData()
{
  // Caso encontre DADOS na SERIAL, verifica quantos vezes o "1" foi pressionado, até atingir o tamanho da FITA. Atribui "0" para qualquer outro dado na Serial e descarta o excesso.
  for (int auxSerial = 0; auxSerial <= STOPTAPE; auxSerial++)
  {
    int serialData = Serial.read() - '0';
    if (serialData == 1) inputTape[auxSerial] = serialData;
    else inputTape[auxSerial] = 0;
  }  
  while (Serial.available()) Serial.read();
  Serial.print("NEW TAPE:");
  debugTape();
  Serial.println();
  loadTape();
}

// --- Carrega os DADOS lidos na SERIAL --- //
void loadTape(void)
{
  for (int aux = 0; aux <= STOPTAPE - STARTTAPE;  aux++) digitalWrite(STARTTAPE + aux, inputTape[aux]);
}
