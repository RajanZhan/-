#include "dh.h"
int led = 5; // 指示灯的输出端口


void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  Serial.println("DHT11 TEST PROGRAM");
  Serial.print("LIBRARY");
  // 输出 DHT 库的版本号
  Serial.println(DHT11LIB_VERSION);
  Serial.println();
  
}


// 指示灯
void Pointer(int led)
{
  digitalWrite(led,HIGH);
  delay(100);
  digitalWrite(led,LOW);
  delay(200);
}


void loop() {
  char tmpRes[512];
  readTmp(8,tmpRes);// 读取8引脚的温湿度数据
  Serial.println("A");
  Serial.print(tmpRes);
  Serial.println("B");
  delay(2000);
  Pointer(led);
}
