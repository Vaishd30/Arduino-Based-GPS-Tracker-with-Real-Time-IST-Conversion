#include <TinyGPSPlus.h>
#include <SoftwareSerial.h>

TinyGPSPlus gps;
SoftwareSerial gpsSerial(3, 4); // RX, TX (connect TX from GPS to pin 4 and RX to pin 3)

void setup() {
  Serial.begin(9600);
  gpsSerial.begin(9600);
  Serial.println("GPS Module is ready");
}

void loop() {
  while (gpsSerial.available() > 0) {
    if (gps.encode(gpsSerial.read())) {
      if (gps.location.isUpdated()) {
        Serial.print("Latitude: ");
        Serial.println(gps.location.lat(), 6);
        Serial.print("Longitude: ");
        Serial.println(gps.location.lng(), 6);
      }

      if (gps.date.isUpdated() && gps.time.isUpdated()) {
        // Extract GMT time from GPS
        int gmtHour = gps.time.hour();
        int gmtMinute = gps.time.minute();
        int gmtSecond = gps.time.second();

        // Convert GMT to IST (GMT + 5:30)
        int istHour = gmtHour + 5;
        int istMinute = gmtMinute + 30;

        // Adjust for overflow in minutes and hours
        if (istMinute >= 60) {
          istMinute -= 60;
          istHour++;
        }
        if (istHour >= 24) {
          istHour -= 24; // Wrap around to next day if hour exceeds 24
        }

        // Print date and IST time
        Serial.print("Date: ");
        Serial.print(gps.date.day());
        Serial.print("/");
        Serial.print(gps.date.month());
        Serial.print("/");
        Serial.println(gps.date.year());
        
        Serial.print("Time (IST): ");
        Serial.print(istHour < 10 ? "0" : ""); // Add leading zero for single-digit hours
        Serial.print(istHour);
        Serial.print(":");
        Serial.print(istMinute < 10 ? "0" : ""); // Add leading zero for single-digit minutes
        Serial.print(istMinute);
        Serial.print(":");
        Serial.print(gmtSecond < 10 ? "0" : ""); // Add leading zero for single-digit seconds
        Serial.println(gmtSecond);
      }
    }
  }
}