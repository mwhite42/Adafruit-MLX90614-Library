/***************************************************
  This is a library example for the MLX90614 Temp Sensor

  Designed specifically to work with the MLX90614 sensors in the
  adafruit shop
  ----> https://www.adafruit.com/products/1748
  ----> https://www.adafruit.com/products/1749

  These sensors use I2C to communicate, 2 pins are required to
  interface
  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include <Adafruit_MLX90614.h>


 Adafruit_MLX90614 mlx = Adafruit_MLX90614();
 Adafruit_MLX90614 base = Adafruit_MLX90614();

char publishString[80];

 void setup() {
   Serial.begin(9600);

   Serial.println("Still Temp Monitor Test");

   mlx.begin(0x55);
  base.begin(0x5A);

 }

 void loop() {

//  Serial.println("Ambient = ");
//  Serial.print(mlx.readAmbientTempC());
  // Serial.print("*C\tObject = "); Serial.print(mlx.readObjectTempC()); Serial.println("*C");
  // Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempF());
  // Serial.print("*F\tObject = "); Serial.print(mlx.readObjectTempF()); Serial.println("*F");
    ////
//    Serial.print("-");
//    Serial.print(base.readAmbientTempF());
  //  Serial.print("-");
   sprintf(publishString, "Ambient %f | %f   Object %f | %f", mlx.readAmbientTempF(), base.readAmbientTempF(), mlx.readObjectTempF(), base.readObjectTempF());
//   sprintf(publishString, "Ambient %f    Object  %f", mlx.readAmbientTempF(),mlx.readObjectTempF());

   Serial.println(publishString);
   Spark.publish("temperature", publishString);

   delay(5000);
 }
