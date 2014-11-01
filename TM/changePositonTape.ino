void changePositonTape(int aux)
{
  digitalWrite(positionTape, LOW);
  positionTape = positionTape + aux;
  if (positionTape < STARTPOS) positionTape = STOPPOS;
  if (positionTape > STOPPOS) positionTape = STARTPOS;
  digitalWrite(positionTape, HIGH);
}

void configInputTape(void)
{
  int aux = positionTape - STARTPOS;
  inputTape[aux] = digitalRead(VALUE);
  digitalWrite(aux + STARTTAPE, inputTape[aux]);
}

void changeState(int aux)
{
  digitalWrite(state, LOW);
  state = state + aux;
  if (state < INITSTATE) state = ENDSTATE;
  if (state > ENDSTATE) state = INITSTATE;
  digitalWrite(state, HIGH);
}

void writeTape(void)
{
  digitalWrite((STARTTAPE + (positionTape - STARTPOS)), inputTape[positionTape - STARTPOS]);
}
