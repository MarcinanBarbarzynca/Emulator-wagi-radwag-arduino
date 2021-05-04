# Emulator-wagi-radwag-arduino
Ten program emuluje podstawowe komendy dla wagi Radwaga

# Co to jest?
Jest to program na arduino który pozwala testować komunikatory służące do rozmawiania z urządzeniami Radwag przez porty RS232 i USB.

# Algorytm działania
Po odebraniu komunikatu Arduino wysyła odpowiedź
Wyślij "?" aby otrzymać listę komend
C0 
C1
NR
Wagi wymagają aby komunikat zawierał @CRLF
