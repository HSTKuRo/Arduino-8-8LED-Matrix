#include <LedControl.h>
// Pin 12:Data in, Pin 11: Clock,  Pin 10: CS(Load)
LedControl display = LedControl(12,11,10,1);
 
const uint64_t IMAGES[] = {
  0x183c7effffff6600,
  0x183c7effffff6600,
  0x183c7effffff6600,
  0x183c7effffff6600,
  0x183c7effffff6600,
  0x183c7effffff6600,
  0x0c1e3f7f7f7f3300,
  0x0c1e3f7f7f7f3300,
  0x060f1f3f3f3f1900,
  0x060f1f3f3f3f1900,
  0x03070f1f1f1f0c00,
  0x03070f1f1f1f0c00,
  0x0103070f0f0f0600,
  0x0103070f0f0f0600,
  0x0001030707070300,
  0x0001030707070300,
  0x0000010303030100,
  0x0000010303030100,
  0x0000000101010000,
  0x0000000101010000,
  0x0000000000000000,
  0x0000008080800000,
  0x0000008080800000,
  0x000080c0c0c08000,
  0x000080c0c0c08000,
  0x0080c0e0e0e0c000,
  0x0080c0e0e0e0c000,
  0x80c0e0f0f0f06000,
  0x80c0e0f0f0f06000,
  0xc0e0f0f8f8f83000,
  0xc0e0f0f8f8f83000,
  0x60f0f8fcfcfc9800,
  0x60f0f8fcfcfc9800,
  0x3078fcfefefecc00,
  0x3078fcfefefecc00,
  0x183c7effffff6600,
  0x183c7effffff6600,
  0x183c7effffff6600,
  0x183c7effffff6600,
  0x183c7effffff6600,
  0x183c7effffff6600,
  0x0000000000000000,
  0x0042241818244200,
  0x0042241818244200,
  0x0042241818244200,
  0x0042241818244200,
  0x0000000000000000,
  0x000000c3663c1800,
  0x000000c3663c1800,
  0x000000c3663c1800,
  0x000000c3663c1800,
  0x000000c3663c1800,
  0x000000c3663c1800,
  0x00000000c3663c18,
  0x00000000c3663c18,
  0x0000000000c3663c,
  0x0000000000c3663c,
  0x000000000000c366,
  0x000000000000c366,
  0x00000000000000c3,
  0x00000000000000c3,
  0x0000000000000000,
  0x1800000000000000,
  0x3c18000000000000,
  0x663c180000000000,
  0xc3663c1800000000,
  0x00c3663c18000000,
  0x0000c3663c180000,
  0x000000c3663c1800,
  0x000000c3663c1800,
  0x000000c3663c1800,
  0x000000c3663c1800,
  0x000000c3663c1800,
  0x000000c3663c1800,
  0x0000000000000000,
  0x00ffff0000ffff00,
  0x00ffff0000ffff00,
  0xffff00000000ffff,
  0xffff00000000ffff,
  0x00ffff0000ffff00,
  0x00ffff0000ffff00,
  0x0000ffffffff0000,
  0x0000ffffffff0000,
  0x00ffff0000ffff00,
  0x00ffff0000ffff00,
  0x00ffff0000ffff00,
  0x00ffff0000ffff00,
  0x00ffff0000ffff00,
  0x00ffff0000ffff00,
  0x0000000000000000,
  0x0000000000000000,
  0x0000000000000000,
  0x0000000000000000
};
const int IMAGES_LEN = sizeof(IMAGES)/8;















void setup()
{
  display.clearDisplay(0);    
  display.shutdown(0, false);  
  display.setIntensity(0, 10); 

}
void displayImage(uint64_t image) {
  for (int i = 0; i < 8; i++) {
    byte row = (image >> i * 8) & 0xFF;
    for (int j = 0; j < 8; j++) {
      display.setLed(0, i, j, bitRead(row, j));
    }
  }
}

int i = 0;

void loop() {
   displayImage(IMAGES[i]);
  if (++i >= IMAGES_LEN ) {
    i = 0;
  }
  delay(50); 
}
