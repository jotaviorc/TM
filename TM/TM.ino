#define TEST      0

#define VALUE     4
#define RESET     5
#define PLAY      6
#define SET       7
#define POSP      8
#define POSM      9

#define STARTTAPE 10
#define STOPTAPE  21

#define STARTPOS  25
#define STOPPOS   36

#define INITSTATE 40
#define ENDSTATE  51

int inputTape[STOPTAPE - STARTTAPE];
int positionTape = STARTPOS;
int state = INITSTATE;

void setup()
{
  Serial.begin(9600);
  Serial.println("Start Maquina de Turing");
  
  pinMode(PLAY, INPUT);
  pinMode(RESET, INPUT);
  pinMode(SET, INPUT);
  pinMode(POSP, INPUT);
  pinMode(POSM, INPUT);
  
  // OUTPUT Tape
  for (int count = STARTTAPE; count <= STOPTAPE; count++){
    pinMode(count, OUTPUT);
  }
  // OUTPUT Position
  for (int count = STARTPOS; count <= STOPPOS; count++){
    pinMode(count, OUTPUT);
  }
  // OUTPUT STATE
  for (int count = INITSTATE; count <= ENDSTATE; count++){
    pinMode(count, OUTPUT);
  }  
  ledTest(STARTTAPE,STOPTAPE);
  ledTest(STARTPOS,STOPPOS);
  ledTest(INITSTATE,ENDSTATE);
  resetSystem();
}

void ledTest(int aux, int endAux)
{
  for (int count = aux; count <= endAux ; count ++)
  {
    digitalWrite(count, HIGH);
    delay(50);
    digitalWrite(count, LOW);
  }
}

void loop()
{
  int auxTemp = 250;
  if (digitalRead(RESET) == HIGH){
    Serial.println("RESET");
    resetSystem();
    delay(auxTemp);
  }
  if (digitalRead(POSP) == HIGH){
    Serial.println("POS +");
    changePositonTape(1);
    delay(auxTemp);
  }
  if (digitalRead(POSM) == HIGH){
    Serial.println("POS -");
    changePositonTape(-1);
    delay(auxTemp);
  }
  if (digitalRead(SET) == HIGH){
    Serial.println("SET");
    if (TEST) changeState(1);
    else configInputTape();
    delay(auxTemp);

  }
  if (digitalRead(PLAY) == HIGH){
    Serial.println("PLAY");
    if (TEST) changeState(-1);
    else ;// PLAY
    delay(auxTemp);
    
  }
}
