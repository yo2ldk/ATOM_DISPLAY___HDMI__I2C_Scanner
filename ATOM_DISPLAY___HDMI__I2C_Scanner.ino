#include <M5AtomDisplay.h>
M5AtomDisplay gfx( xxx, xxxx);  //   edit xx with your display settings


#include <Wire.h>

void setup()
{
  Serial.begin (115200);  
  Wire.begin (25, 21);   // sda= GPIO_21 /scl= GPIO_22

  gfx.init();
  gfx.setRotation(0);
}

void Scanner ()
{
  gfx.fillScreen(TFT_BLACK);
  gfx.display();
  gfx.setCursor(300, 10);
  gfx.setTextSize(7);
  gfx.setTextColor(TFT_BLUE);
  gfx.println (" Scanner 4 I2C - Scanning Now...");
  byte count = 0;

  Wire.begin();
  for (byte i = 8; i < 120; i++)
  {
    Wire.beginTransmission (i);          // Begin I2C transmission Address (i)
    if (Wire.endTransmission () == 0)  // Receive 0 = success (ACK response) 
    {
      delay (1000);
      gfx.setCursor(520, 150);
      gfx.setTextSize(4);
      gfx.setTextColor(TFT_YELLOW);
      gfx.print ("***   Found address: ");
      gfx.print (i, DEC);
      gfx.print (" (0x");
      gfx.print (i, HEX);     // PCF8574 7 bit address
      gfx.println (")  ***");
      delay (2000);
      gfx.clearDisplay();
      gfx.setCursor(300, 10);
      gfx.setTextSize(7);
      gfx.setTextColor(TFT_BLUE);
      gfx.println (" Scanner 4 I2C - Scanning Now...");
        count++;
    }
  }
  gfx.setCursor(720, 200);
  gfx.setTextSize(4);
  delay (500);
  gfx.print ("Found ");      
  gfx.print (count, DEC);        // numbers of devices
  gfx.println (" device(s).");
  delay (1000);
  gfx.clearDisplay();
  
}

void loop()
{
  Scanner ();
  delay (1500);
  
}

/*

void setup()
{
  gfx.init();
  //gfx.setBrightness(32);               //   0 la 255
  gfx.setRotation(0);
  gfx.fillScreen(TFT_WHITE);
  gfx.display();
  
  gfx.fillRect(0, 0, 640, 480, TFT_NAVY);
  gfx.fillRect(640, 0, 640, 480, TFT_YELLOW);
  gfx.fillRect(1280, 0, 640, 480, TFT_RED);
  gfx.setTextColor(TFT_BLUE);
  gfx.setCursor(800, 80);
  gfx.setTextSize(7);
  gfx.startWrite();
  gfx.println(" Hello !! ");
  gfx.setCursor(650, 220);
  gfx.println(" 73, de YO2LDK");
  gfx.setCursor(650, 340);
   gfx.println(" - Alexander - ");
  //gfx.endWrite();
}

void loop() {

}
*/
