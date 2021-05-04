//ten program emuluje wagę
//Po wpisaniu C1 & @CRLF to
//Po Wpisaniu NL & @CRLF to waga wypisuje swój identyfikator
//
const unsigned long interval = 1000;
unsigned long previousMillis = 0;

bool nadawanie_non_stop = true;
void print_random() {
  Serial.print("SI : "+String(random(0, 10000)) + "\r\n"); //Wypisuje randomową wartość
}

void setup() {
  Serial.begin(9600);
}

void loop() {

  if (nadawanie_non_stop == true) {
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval)
    {
      print_random();
      previousMillis = currentMillis;
    }
  }
  if (Serial.available() > 0) {
    String wiadomosc = Serial.readString();
    if (wiadomosc == "C1\r\n") {
      Serial.println("C1\r\n");
      nadawanie_non_stop = true;
    }
    if (wiadomosc == "C0\r\n") {
      Serial.println("C0\r\n");
      nadawanie_non_stop = false;
    }
    if (wiadomosc == "NR\r\n") {
      Serial.println("ID: 999999");
    }
    if (wiadomosc == "?") {
      Serial.println("Komendy: C0@CRLF; C1@CRLF;  NR@CRLF");
    }
    if (wiadomosc == "?\r\n") {
      Serial.println("Komendy: C0@CRLF; C1@CRLF;  NR@CRLF");
    }
  }
}
