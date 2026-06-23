#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

// Pins matching your circuit image
#define PULSE_PIN 13
#define SDA_PIN 21
#define SCL_PIN 20

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// BPM Tracking Variables
unsigned long lastBeatTime = 0;
unsigned long currentBeatTime = 0;

// CHANGED: Adjusted for 16-bit scale (0-65535). Midpoint is roughly 35000 at 3.3V
int threshold = 35000;               
bool anyBeat = false;
int bpm = 0;

void setup() 
{
    Serial.begin(115200);
    
    // REMOVED: pinMode(PULSE_PIN, INPUT) as it glitches ESP32 analog reads.

    // Initialize I2C with your exact pins: SDA=21, SCL=20
    Wire.begin(SDA_PIN, SCL_PIN);

    // Initialize OLED Display
    if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
        Serial.println(F("SSD1306 allocation failed"));
        for(;;);
    }
    
    display.setTextColor(SSD1306_WHITE);
    display.clearDisplay();
    display.display();
    
    Serial.println("Heart Rate Monitor Started");
}

void loop() 
{
    // Read the analog signal from the Pulse Sensor
    int signalValue = analogRead(PULSE_PIN);
    
    // Heartbeat detection logic
    if (signalValue > threshold && anyBeat == false) 
    {
        anyBeat = true;
        currentBeatTime = millis();
        
        unsigned long beatDuration = currentBeatTime - lastBeatTime;
        
        // Debounce: Human heart standard range
        if (beatDuration > 300 && beatDuration < 2000) 
        {
            bpm = 60000 / beatDuration; 
        }
        
        lastBeatTime = currentBeatTime;
    }

    // Reset the beat flag when the signal drops back below the threshold
    if (signalValue < (threshold - 2000)) 
    {
        anyBeat = false;
    }

    // Print to Serial Monitor
    Serial.print("Signal:");
    Serial.print(signalValue);
    Serial.print(",");
    Serial.print("BPM:");
    Serial.println(bpm);

    // Draw everything to the OLED Screen
    display.clearDisplay();
    
    display.setTextSize(1);
    display.setCursor(15, 0);
    display.println("HEART RATE MONITOR");
    
    display.drawFastHLine(0, 12, 128, SSD1306_WHITE);

    display.setCursor(0, 22);
    display.print("Signal: ");
    display.print(signalValue);

    display.setCursor(100, 22);
    if(anyBeat) {
        display.print("<3"); 
    } else {
        display.print("  ");
    }

    display.setTextSize(2);
    display.setCursor(0, 42);
    display.print("BPM: ");
    if (bpm > 30 && bpm < 200) {
        display.print(bpm);
    } else {
        display.print("---"); 
    }

    display.display();
    
    delay(20); 
}
