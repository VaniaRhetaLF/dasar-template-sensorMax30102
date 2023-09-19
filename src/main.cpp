// Program Sensor Max 30102
// Version 1.0
// Vania
// PT. Makerindo Prima Solusi
// 18/09/2023
// COM6

//--- Library
#include<Arduino.h>
#include<DFRobot_BloodOxygen_S.h>
#include<Wire.h>

//--- Definisi
#define I2C_ADDRESS   0x57
DFRobot_BloodOxygen_S_I2C MAX30102(&Wire ,I2C_ADDRESS);

// --- Prosedur
void bacaSensor()
{
  MAX30102.getHeartbeatSPO2();

  Serial.print("SaturasiO2 is : ");
  int spo2 = MAX30102._sHeartbeatSPO2.SPO2;
  if (MAX30102._sHeartbeatSPO2.SPO2 < 0)
  {
    spo2 = 0;
    Serial.print(spo2);
  }
  else if (MAX30102._sHeartbeatSPO2.SPO2 >= 0)
  {
    Serial.print(MAX30102._sHeartbeatSPO2.SPO2);
  }
  Serial.println("%");

  Serial.print("heart rate is : ");
  int heartBeat = MAX30102._sHeartbeatSPO2.Heartbeat;
  if (MAX30102._sHeartbeatSPO2.Heartbeat < 0)
  {
    heartBeat = 0;
    Serial.print(heartBeat);
  }
  else if (MAX30102._sHeartbeatSPO2.Heartbeat >= 0)
  {
    Serial.print(MAX30102._sHeartbeatSPO2.Heartbeat);
  }
  Serial.println(" Times/min");

  //The sensor updates the data every 4 seconds
  delay(4000);
}


void setup()
{
  Serial.begin(115200);
  Wire.begin();
  while (false == MAX30102.begin())
  {
    Serial.println("Gagal!");
    delay(1000);
  }
  Serial.println("Sukses!");
  Serial.println("Memulai...");
  MAX30102.sensorStartCollect();
}


void loop()
{
  bacaSensor();
}