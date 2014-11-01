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
}
