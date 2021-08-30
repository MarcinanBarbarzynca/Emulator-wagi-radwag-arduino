# Emulator-wagi-radwag-arduino
Ten program emuluje podstawowe komendy dla wagi Radwaga

# Co to jest?
Jest to program na arduino który pozwala testować komunikatory służące do rozmawiania z urządzeniami Radwag przez porty RS232 i USB.

# Algorytm działania
Po odebraniu komunikatu Arduino wysyła odpowiedź
<br />Wyślij "?" aby otrzymać listę komend
<br />C0 
<br />C1
<br />NR
<br />Wagi wymagają aby komunikat zawierał @CRLF
<br />Wagę nieustaloną drukuje ze znakiem zapytania 'SI        0.476 kg' 

# Efekty komend:
1. PC - Drukuje wszystkie implementowane komendy 'PC A ",SUI,CU1,CU0,ODH,OUH,IC1,IC0,TZ,SI,SU,C1,C0,DH,UH,OT,UT,SM,K1,K0,BP,IC,SS,NB,BN,FS,RV,UI,US,UG,PC,Z,T,S,A"'
2. NB - Drukuje numer fabryczny : 'NB A "692670"'
