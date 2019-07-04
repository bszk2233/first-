#include <morsecode.h>

int LED = 13;
int Code_Delay = 100;

MorseCode morse(LED, Code_Delay);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  //morse.dot();

  String inputbuf = "";
  String encode = "";
  int i, j;
  int serialFlag = 0;
  int cnt_1 = 0, cnt_2 = 0;

  while (Serial.available() > 0) {
    serialFlag = 1;
    inputbuf += char(Serial.read());
    cnt_1++;
    delay(1);
  }

  if (serialFlag) {
    for (i = 0; i < cnt_1; i++) {
      if (inputbuf[i] >= 97 && inputbuf[i] <= 122) {
        for (j = 0; j < 4; j++) {
          encode += char(morse.MorseCode[int(inputbuf[i] - 97)][j]);
          cnt_2++;
        }
      }
      else if (inputbuf[i] == ' ')
        encode += '/';
        cnt_2++;
    }

    Serial.print("The message is: ");
    Serial.print(inputbuf);
    Serial.print("It's morse code is: ");
    Serial.println(encode);
    Serial.println("Now sending...");
    
    for (i = 0; i < cnt_2; i++) {
      switch (encode[i]) {
        case '.': morse.dot();
          break;
        case '-': morse.dash();
          break;
        case ' ': morse.divid();
          break;
        case '/': morse.space();
          break;
        default:
          break;
      }
      Serial.print(">");
    }
    Serial.println("Done.");
  }
}
