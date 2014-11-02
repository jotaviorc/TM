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
  if (Serial.available()) serialData();
}

void serialData()
{
  for (int auxSerial = 0; auxSerial <= 11; auxSerial++)
  {
    int serialData = Serial.read() - '0';
    if (serialData == 0 || serialData == 1) inputTape[auxSerial] = serialData;
    else inputTape[auxSerial] = 0;
  }
  while (Serial.available()) Serial.read();
  Serial.print("NEW TAPE:");
  debugTape();
  loadTape();
  Serial.println();
}

void loadTape(void)
{
  for (int aux = 0; aux <= 11; aux++)
  {
    digitalWrite(STARTTAPE + aux, inputTape[aux]);
  }
}
