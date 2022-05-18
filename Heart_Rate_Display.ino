/******************************************************************************
Heart_Rate_Display.ino
Demo Program for AD8232 Heart Rate sensor.
Casey Kuhns @ SparkFun Electronics
6/27/2014
https://github.com/sparkfun/AD8232_Heart_Rate_Monitor
The AD8232 Heart Rate sensor is a low cost EKG/ECG sensor.  This example shows
how to create an ECG with real time display.  The display is using Processing.
This sketch is based heavily on the Graphing Tutorial provided in the Arduino
IDE. http://www.arduino.cc/en/Tutorial/Graph
Resources:
This program requires a Processing sketch to view the data in real time.
Development environment specifics:
	IDE: Arduino 1.0.5
	Hardware Platform: Arduino Pro 3.3V/8MHz
	AD8232 Heart Monitor Version: 1.0
This code is beerware. If you see me (or any other SparkFun employee) at the
local pub, and you've found our code helpful, please buy us a round!
Distributed as-is; no warranty is given.
******************************************************************************/

void setup()
{
  Serial.begin(9600);
  // L0+ и L0-, подключенные на 10 и 11 пины, являются выходами детектора контактов электродов
  pinMode(10, INPUT); // Настройка выхода L0-
  pinMode(11, INPUT); // Настройка выхода L0+
}
void loop()
{
  // При отсутствии контакта на одном из 3 электродов
  // в мониторе порта будет отображаться "!" на месте
  // отображения значения этого электрода
  if((digitalRead(10) == 1)||(digitalRead(11) == 1))
  {
    Serial.println('!');
  }
  else{
    // отправка аналоговых значений с датчиков
      Serial.println(analogRead(A0));
  }
  // Небольшая задержка для получения значений с электродов
  delay(1);
}