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
    
    // String temp = String(analogRead(A0));
    // Particle.publish("clap", temp, PRIVATE);
  
    
    int x = analogRead(A0);
    // lcd.clear();
    // lcd.print(x);
    
    if (x > 3000) {
        
        // delay(500);
        // while(1) {
        //     x = analogRead(A0);
        // }
        
        delay(500);
        // if (x > 3000) {
            
            
            if (light_on) {
                
                digitalWrite(D7, LOW);
                //delay(1000);
                light_on = 0;
                
                lcd.clear();
                //lcd.print(light_on);
                delay(500);
                lcd.print("LIGHT OFF");
                
                Particle.publish("Energy Usage Time", "0", PRIVATE);
                
            }
            else {
                
                digitalWrite(D7, HIGH);
                //delay(1000);
                light_on = 1;
                
                lcd.clear();
                //lcd.print(light_on);
                delay(500);
                lcd.print("LIGHT ON");
                
                
                Particle.publish("Energy Usage Time", "1", PRIVATE);
            }

 
            
       // }

    }
    

    

    //delay(10);
    
    // if (digitalRead(D4) == HIGH) {
        
    //     delay(500);
        
    //     lcd.print("first clap"); 
        
    //     if (digitalRead(D4) == HIGH) {
    //         lcd.print("second clap"); 
    //     }
        
    // }
}