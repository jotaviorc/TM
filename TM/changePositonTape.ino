// --- Modifica POSIÇÃO atual conforme AUXILIAR --- //

void changePositionTape(int aux, int auxMenu)
{
  digitalWrite(positionTape, LOW);
  positionTape = positionTape + aux;
  if (auxMenu)
  {
    if (positionTape < STARTPOS) positionTape = STOPPOS;
    if (positionTape > STOPPOS) positionTape = STARTPOS;
    digitalWrite(positionTape, HIGH);
  }
  else
  {
    if (positionTape >= STARTPOS || positionTape <= STOPPOS) digitalWrite(positionTape, HIGH);
  }
}

// --- Modifica o dado da FITA conforme POSIÇÃO e grava o valor no inputTape. Leitura do Dado via VALEU --- //

void configInputTape(void)
{
  int aux = positionTape - STARTPOS;
  inputTape[aux] = inputTape[aux] == 1? 0: 1;
  debugTape();
  Serial.println();
  digitalWrite(STARTTAPE + aux, inputTape[aux]);
}

// --- Modifica ESTADO atual conforme AUXILIAR, apenas quando TESTE estiver em "1" --- //

void changeState(int aux)
{
  digitalWrite(state, LOW);
  state = state + aux;
  if (state < INITSTATE) state = ENDSTATE;
  if (state > ENDSTATE) state = INITSTATE;
  digitalWrite(state, HIGH);
}

// --- Escreve DADO da POSIÇÃO da FITA na SAIDA entre STARTTAPE e STOPTAPE --- //

void writeTape(void)
{
  digitalWrite((STARTTAPE + (positionTape - STARTPOS)), inputTape[positionTape - STARTPOS]);
}

// --- Escreve dados de toda FITA na SAIDA SERIAL --- //

void debugTape(void)
{
  for (int count = 0; count <= STOPTAPE - STARTTAPE; count ++)  Serial.print(inputTape[count]);
}
