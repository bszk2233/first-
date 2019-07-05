int LED_Code[] = 
{
  0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07,
  0x7f, 0x6f, 0x77, 0x7c, 0x39,0x5e, 0x79, 0x71
};

int M_SDA = 4;
int M_RCK = 5;
int M_SCL = 6;
int M_CLR = 7;

#define HC595_RCK_H()   digitalWrite(M_RCK, HIGH);
#define HC595_RCK_L()   digitalWrite(M_RCK, LOW);

#define HC595_CLR_H()   digitalWrite(M_CLR, HIGH);
#define HC595_CLR_L()   digitalWrite(M_CLR, LOW);  

#define HC595_SCL_H()   digitalWrite(M_SCL, HIGH);
#define HC595_SCL_L()   digitalWrite(M_SCL, LOW); 

#define HC595_SDA_H()   digitalWrite(M_SDA, HIGH);
#define HC595_SDA_L()   digitalWrite(M_SDA, LOW); 


void setup()
{

    HC595_Init();

    Serial.begin(9600);

}

void loop()
{
  String inputbuf = "";
  int serialFlag = 0;
  int i = 0;
  int cnt = 0;
  
  while (Serial.available() > 0) 
  {
    serialFlag = 1;
    inputbuf += char(Serial.read());
    cnt++;
    delay(1);
  }  

  for (i = 0; i < cnt; i++)
  {
    switch  (inputbuf[i])
    {
      case '0':  HC595_WriteByte(LED_Code[0]);
        break;
      case '1':  HC595_WriteByte(LED_Code[1]);
        break;
      case '2':  HC595_WriteByte(LED_Code[2]);
        break;
      case '3':  HC595_WriteByte(LED_Code[3]);
        break;
      case '4':  HC595_WriteByte(LED_Code[4]);
        break;
      case '5':  HC595_WriteByte(LED_Code[5]);
        break;
      case '6':  HC595_WriteByte(LED_Code[6]);
        break;
      case '7':  HC595_WriteByte(LED_Code[7]);
        break;
      case '8':  HC595_WriteByte(LED_Code[8]);
        break;
      case '9':  HC595_WriteByte(LED_Code[9]);
        break;
      case 'A':  HC595_WriteByte(LED_Code[10]);
        break;
      case 'B':  HC595_WriteByte(LED_Code[11]);
        break;
      case 'C':  HC595_WriteByte(LED_Code[12]);
        break;
      case 'D':  HC595_WriteByte(LED_Code[13]);
        break;
      case 'E':  HC595_WriteByte(LED_Code[14]);
        break;
      case 'F':  HC595_WriteByte(LED_Code[15]);
        break;
      default:  
        break;
    }
    delay(200);  
  }
  
}

void HC595_Delay(uint32_t t)
{
  while(t--)  for(uint8_t i = 0; i < 10; i++);
}

void HC595_Init()
{
  pinMode(M_SDA, OUTPUT);
  pinMode(M_RCK, OUTPUT);
  pinMode(M_SCL, OUTPUT);
  pinMode(M_CLR, OUTPUT);

  HC595_CLR_L();  //CLR(Pin_10)低电平时将移位寄存器数据清零
  delay(10);
  HC595_CLR_H();
  
  HC595_SCL_H();
  HC595_SDA_L();
  
  HC595_RCK_H();  //RCK(Pin_12)上升沿移位寄存器数据进入存储寄存器

}

void HC595_WriteByte(int data)
{
  for(uint8_t i = 0; i < 8; i++)
  {
    if((data << i) & 0x80)
    {
      HC595_SDA_H();
    }
    else
    {
      HC595_SDA_L();
    }
    
    HC595_SCL_L();
    HC595_Delay(1);
    HC595_SCL_H();
    HC595_Delay(1);
    
  }
  
  HC595_RCK_L();
  HC595_Delay(1);
  HC595_RCK_H();
}
