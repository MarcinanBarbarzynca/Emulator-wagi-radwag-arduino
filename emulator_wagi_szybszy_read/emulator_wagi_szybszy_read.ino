//ten program emuluje wagę
//Po wpisaniu C1 & @CRLF to
//Po Wpisaniu NL & @CRLF to waga wypisuje swój identyfikator
//
const unsigned long interval = 1000;
unsigned long previousMillis = 0;

bool nadawanie_non_stop = true;
void print_random() {
 int random_float = random(0, 15);
 int random_ndpart = random(0, 999);
 if(random(0,10000)>5000){
   Serial.print("SI "+String(random_float)+"."+ String(random_ndpart)+ " kg \r\n"); //Wypisuje randomową wartość
 }else{
   Serial.print("SI ? "+String(random_float) +"."+ String(random_ndpart)+ " kg \r\n"); //Wypisuje randomową wartość
 }
 
}

void setup() {
  Serial.setTimeout(200);
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
    //char[100] buffer = ""
    //while Serial.read()!="\n"{
    //  String wiadomosc = Serial.read();
    //}
    String wiadomosc = Serial.readStringUntil('\n');
    
    //Serial.println("WIADOMOSC: "+wiadomosc);
    if (wiadomosc == "C1\r") {
      Serial.print("C1 A\r\n");
      nadawanie_non_stop = true;
    }
    if (wiadomosc == "C0\r") {
      Serial.print("C0 A\r\n");
      nadawanie_non_stop = false;
    }
    if (wiadomosc == "NB\r") {
      Serial.print("NB A"); 
      Serial.print(" \"999999\"");
      Serial.print("\r\n");
     // Serial.print("NB A 999999\r\n");
    }
    if (wiadomosc == "?") {
      Serial.println("Komendy: C0@CRLF; C1@CRLF;  NB@CRLF");
    }
    if (wiadomosc == "?\r\n") {
      Serial.println("Komendy: C0@CRLF; C1@CRLF;  NB@CRLF");
    }
  }
}
