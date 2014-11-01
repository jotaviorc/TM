void startPlay(void)
{
  digitalWrite(state, LOW);
  digitalWrite(positionTape, LOW);
  positionTape = STARTPOS;
  state = INITSTATE;
  digitalWrite(state, HIGH);
  digitalWrite(positionTape, HIGH);
}

int flagINIT = 0;

void stateSlectFunction()
{
  int delayAuxExe = 100;
  int select = 0;
  delay(delayAuxExe);
  do 
  {   
    debugTape();
    Serial.print(" -> State: Q");
    Serial.print(select);
    Serial.print(", Tape Possition: ");
    Serial.println(positionTape - STARTPOS);
    state = INITSTATE + select;
    digitalWrite(state, LOW);
    switch (select)
    {
      case 0:
        select = stateQ0();
        break;
      case 1:
        select = stateQ1();
        break;
      case 2:
        select = stateQ2();
        break;
      case 3:
        select = stateQ3();
        break;
      case 4:
        select = stateQ4();
        break;
      case 5:
        select = stateQ5();
        break;
      case 6:
        select = stateQ6();
        break;
      case 7:
        select = stateQ7();
        break;
      case 8:
        select = stateQ8();
        break;
      case 9:
        select = stateQ9();
        break;
      case 10:
        select = stateQ10();
        break;
      case 11:
        select = stateQ11();
        break;
    }
    digitalWrite(INITSTATE + select, HIGH);
    delay(delayAuxExe);
  }
  while (select != 12);
  Serial.println("EXECTION DONE");
  flagINIT = 0;
}

int stateQ0(void)
{
  if (inputTape[positionTape - STARTPOS]) {
    changePositonTape(+1);
    return 0;
  }
  else {
    changePositonTape(+1);
    return 1;
  }
}

int stateQ1(void)
{
  if (positionTape == STOPPOS) {
    changePositonTape(-1);
    return 4;
  }
  if (inputTape[positionTape - STARTPOS]) {
    inputTape[positionTape - STARTPOS] = 0;
    writeTape();
    changePositonTape(-1);
    return 2;
  }
  else {
    changePositonTape(+1);
    return 1;
  }
}

int stateQ2(void)
{
  if (positionTape == STARTPOS) {
    if (!flagINIT) {
      flagINIT = 1;
    }
    else {
      inputTape[positionTape - STARTPOS] = 1;
      writeTape();
      changePositonTape(+1);
    }
    return 3;
  }
  if (inputTape[positionTape - STARTPOS]) {
    changePositonTape(+1);
    return 3;
  }
  else {
    changePositonTape(-1);
    return 2;
  }
}

int stateQ3(void)
{
  inputTape[positionTape - STARTPOS] = 1;
  writeTape();
  changePositonTape(+1);
  return 0;
}

int stateQ4(void)
{
  if (positionTape == STARTPOS) {
    return 5;
  }
  else {
    changePositonTape(-1);
    return 4;
  }
}

int stateQ5(void)
{
  if (inputTape[positionTape - STARTPOS]) {
    changePositonTape(+1);
    return 6;
  }
}

int stateQ6(void)
{
  if (inputTape[positionTape - STARTPOS]) {
    changePositonTape(+1);
    return 7;
  }
  else {
//    changePositonTape(-1);
    return 11;
  }
}

int stateQ7(void)
{
  if (inputTape[positionTape - STARTPOS]) {
    
    changePositonTape(+1);
    return 8;
  }
  else {
//    changePositonTape(-1);
    return 11;
  }
}

int stateQ8(void)
{
  if (inputTape[positionTape - STARTPOS]) {
    inputTape[positionTape - STARTPOS] = 0;
    writeTape();
    changePositonTape(+1);
    return 9;
  }
  else
  {
//    changePositonTape(-1);
    return 11;
  }
}

int stateQ9(void)
{
  if (inputTape[positionTape - STARTPOS]) {
    changePositonTape(+1);
    return 9;
  }
  else
  {
    inputTape[positionTape - STARTPOS] = 1;
    writeTape();
    changePositonTape(-1);
    return 10;
  }
}

int stateQ10(void)
{
  if (inputTape[positionTape - STARTPOS]) {
    changePositonTape(-1);
    return 10;
  }
  else
  {
    changePositonTape(+1);
    return 5;
  }
}

int stateQ11(void)
{
  Serial.println("FINAL STATE");
  return 12;
}
