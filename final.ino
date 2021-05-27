// This #include statement was automatically added by the Particle IDE.
#include <ThingSpeak.h>

// This #include statement was automatically added by the Particle IDE.
#include <Grove_LCD_RGB_Backlight.h>


rgb_lcd lcd;
const int colorR = 255;
const int colorG = 0;
const int colorB = 0;

int light_on = 0;

void setup() {

    Serial.begin(115200);
    pinMode(A0, INPUT);

    
    
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    lcd.setRGB(colorR, colorG, colorB);
    // Print a message to the LCD.
    lcd.print("LIGHT OFF"); 
    
    
    //delay(1000);
    
    pinMode(D7, OUTPUT);
    
    

}

void loop() {
    
    
    int x = analogRead(A0);

    
    if (x > 3000) {
        

        delay(500);
            
            
            if (light_on) {
                
                digitalWrite(D7, LOW);

                light_on = 0;
                
                lcd.clear();

                delay(500);
                lcd.print("LIGHT OFF");
                
                Particle.publish("Energy Usage Time", "0", PRIVATE);
                
            }
            else {
                
                digitalWrite(D7, HIGH);
  
                light_on = 1;
                
                lcd.clear();
 
                delay(500);
                lcd.print("LIGHT ON");
                
                
                Particle.publish("Energy Usage Time", "1", PRIVATE);
            }

 
            

    }
    

   
}
