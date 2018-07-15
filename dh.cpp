#include "dh.h"
dht11 DHT11;

// 读取温度湿度 参数dataPort 为读取数据的端口
void readTmp(int dataPort ,char * result ) {
  
  char resTmp[128];
  char statusTmp[128];
  int chk = DHT11.read(dataPort);

  // 测试 DHT 是否正确连接
  switch (chk)
  {
    case DHTLIB_OK: 
    sprintf(statusTmp,"ok");
    break;
    case DHTLIB_ERROR_CHECKSUM: 
    sprintf(statusTmp,"Checksum error");
    break;
    case DHTLIB_ERROR_TIMEOUT: 
    sprintf(statusTmp,"Time out error");
    break;
    default: 
    sprintf(statusTmp,"Unknown error");
    break;
  }
  
  // 获取测量数据  
  char humidity[12];
  dtostrf((float)DHT11.humidity,4,2,humidity);

  char temperature[12];
  dtostrf((float)DHT11.temperature,4,2,temperature);

  sprintf(resTmp,"%s@%s@%s",statusTmp,humidity,temperature);
  strcpy(result,resTmp);
  
}
  
