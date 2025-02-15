# Arduino-Based-GPS-Tracker-with-Real-Time-IST-Conversion
This project retrieves real-time GPS coordinates using the Tiny GPS++ library and converts GMT to Indian Standard Time (IST). The data is displayed via the serial monitor.

# Features 
1. Reads Latitude and Longitude from GPS
2. Extracts date and Time from GPS module
3. Converts GMT time to IST (+5:30)
4. Displays data in Serial monitor

# Hardware Requirements
1. Arduino Nano
![Arduino Nano](https://github.com/user-attachments/assets/05706d9d-4c34-40e5-a674-b5b7e9575926)

![Pinout](https://github.com/user-attachments/assets/f50c1286-a733-46aa-aef7-419529048561)

3. GPS Module (eg. Neo 6M)
![GPS Module](https://github.com/user-attachments/assets/7040d74c-e987-4c3b-901b-4e668c05d1ae)

3. Jumper wires for connections
![Cicuit Connections](https://github.com/user-attachments/assets/05c1c904-a4d1-426a-b45f-8b91eed372a3)


# Libraries Required
1. TinyGPSPlus
2. Software Serial

# Connections

GPS----Arduino
TX----4
RX----3
VCC----5V
GND----GND

1. Upload the code to your Arduino board
2. Open the serial Monitor (Baud Rate: 9600)
3. View the Live GPS coordinates and IST time

# References

[1] https://forum.arduino.cc/t/arduino-nano-and-neo-6m-gps-module/1177344
[2] https://store.arduino.cc/products/arduino-nano
[3] https://docs.cirkitdesigner.com/project/published/baf3e8fc-35c1-4cae-9ffb-1ca50cec7e2e/arduino-nano-gps-tracker
