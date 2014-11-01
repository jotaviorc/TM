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

}
