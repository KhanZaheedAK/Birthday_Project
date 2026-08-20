#define LEFT   D1
#define RIGHT  D5
#define CENTER D6
#define MULTI  D2
#define BUZZER D7

void setup() {
  pinMode(LEFT, OUTPUT);
  pinMode(RIGHT, OUTPUT);
  pinMode(CENTER, OUTPUT);
  pinMode(MULTI, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  digitalWrite(LEFT, LOW);
  digitalWrite(RIGHT, LOW);
  digitalWrite(CENTER, LOW);
  digitalWrite(MULTI, LOW);
}

void beep(int frequency, int duration) {
  tone(BUZZER, frequency, duration);
  delay(duration + 50);   // original buzzer timing
}

void birthdayTune() {
  beep(262, 250);  // C
  beep(262, 250);  // C
  beep(294, 500);  // D
  beep(262, 500);  // C
  beep(349, 500);  // F
  beep(330, 900);  // E
}

void loop() {

  // ===== BUILD THE H =====
  digitalWrite(LEFT, HIGH);
  delay(1200);

  digitalWrite(RIGHT, HIGH);
  delay(1200);

  digitalWrite(CENTER, HIGH);
  delay(1800);

  // ===== MULTI LED =====
  digitalWrite(MULTI, HIGH);
  delay(1500);

  // ===== BUZZER TUNE REPEATS 3 TIMES =====
  for (int i = 0; i < 3; i++) {
    birthdayTune();
    delay(500);
  }

  // ===== CELEBRATION FLASH =====
  for (int i = 0; i < 5; i++) {

    digitalWrite(LEFT, LOW);
    digitalWrite(RIGHT, LOW);
    digitalWrite(CENTER, LOW);
    digitalWrite(MULTI, LOW);
    delay(700);

    digitalWrite(LEFT, HIGH);
    digitalWrite(RIGHT, HIGH);
    digitalWrite(CENTER, HIGH);
    digitalWrite(MULTI, HIGH);
    delay(700);
  }

  // ===== FINAL DISPLAY =====
  digitalWrite(LEFT, HIGH);
  digitalWrite(RIGHT, HIGH);
  digitalWrite(CENTER, HIGH);
  digitalWrite(MULTI, HIGH);

  delay(5000);

  // ===== RESET =====
  digitalWrite(LEFT, LOW);
  digitalWrite(RIGHT, LOW);
  digitalWrite(CENTER, LOW);
  digitalWrite(MULTI, LOW);

  delay(2500);
}