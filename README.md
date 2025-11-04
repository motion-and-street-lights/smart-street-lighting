# Smart Street Lighting System

An intelligent Arduino-based automatic lighting system that conserves energy by detecting motion and ambient light levels. The system uses a PIR sensor to detect human presence and an LDR sensor to measure light intensity, activating LEDs only when needed.

## Overview

This project implements an energy-efficient automatic lighting system using Arduino Uno. The system intelligently controls LED brightness based on ambient light intensity and human presence detection. The LED only operates when it's dark and motion is detected, making it ideal for energy-saving applications in street lighting, hallways, and outdoor spaces.

## Features

- Automatic light detection using LDR sensor
- Motion detection using PIR sensor
- Energy efficient operation (lights activate only when dark and motion detected)
- Adjustable brightness levels
- Real-time sensor monitoring via serial output
- Customizable light and motion thresholds
- Low power consumption

## Components Required

- Arduino Uno (1x)
- PIR Motion Sensor - HC-SR501 or similar (1x)
- LDR (Light Dependent Resistor) (1x)
- LED (1x)
- 10kΩ Resistor for LDR (1x)
- 220Ω Resistor for LED (1x)
- Breadboard (1x)
- Jumper Wires

## Circuit Diagram

![WhatsApp Image 2025-11-04 at 12 29 34_58c4a854](https://github.com/user-attachments/assets/21bac282-ab28-4415-a738-ccf3f874c9b6)


*Pin Connections:*
- *A0* - LDR (with 10kΩ pull-down resistor to GND)
- *Pin 2* - PIR Sensor OUT
- *Pin 9* - LED (through 220Ω resistor)
- *5V* - PIR VCC and LDR voltage divider
- *GND* - Common ground

## How It Works

The system operates based on two sensor inputs:

1. *LDR (Light Sensor)*: Continuously monitors ambient light levels. Higher values indicate darker conditions.

2. *PIR (Motion Sensor)*: Detects infrared radiation changes caused by human movement.

3. *Control Logic*:
   - If light value > 700 (dark) AND motion detected → LED at full brightness (255)
   - If light value > 700 (dark) AND no motion → LED dims (100)
   - If light value ≤ 700 (bright) → LED turns off (0)

This dual-condition approach ensures the lighting system only activates when truly needed, maximizing energy efficiency.

## Installation

### Hardware Setup

1. Assemble the circuit on a breadboard according to the pin connections above
2. Connect the Arduino Uno to your computer via USB cable
3. Verify all connections are secure

### Software Setup

1. Install Arduino IDE from https://www.arduino.cc/en/software

2. Clone or download this repository

3. Open smart_street_light.ino in Arduino IDE

4. Select your board: *Tools → Board → Arduino Uno*

5. Select your port: *Tools → Port → [Your Arduino Port]*

6. Click the Upload button

## Usage

1. After uploading the code, open Serial Monitor (Tools → Serial Monitor) at 9600 baud rate

2. The Serial Monitor will display real-time readings:
   
   Light: 850 | Motion: 1
   Light: 823 | Motion: 1
   Light: 745 | Motion: 0
   

3. Test the system:
   - Cover the LDR to simulate darkness
   - Move near the PIR sensor to trigger motion detection
   - Observe LED brightness changes

## Code

cpp
int LDR = A0; // Light sensor pin
int PIR = 2;  // PIR sensor pin
int LED = 9;  // LED output pin

void setup() {
  pinMode(PIR, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int lightValue = analogRead(LDR);
  int motion = digitalRead(PIR);
  
  Serial.print("Light: ");
  Serial.print(lightValue);
  Serial.print(" | Motion: ");
  Serial.println(motion);
  
  // Adjust brightness based on conditions
  if (lightValue > 700) { // dark condition (tune this threshold)
    if (motion == HIGH) {
      analogWrite(LED, 255); // Full brightness
    } else {
      analogWrite(LED, 100); // Dim
    }
  } else {
    analogWrite(LED, 0); // Turn off during day
  }
  
  delay(500);
}


### Code Explanation

- *Pin Definitions*: LDR on A0 (analog), PIR on pin 2 (digital), LED on pin 9 (PWM)
- *setup()*: Configures pin modes and initializes serial communication at 9600 baud
- *loop()*: Reads sensor values, prints to serial monitor, and controls LED based on light and motion conditions
- *PWM Control*: Uses analogWrite() to set LED brightness (0-255 range)
- *Delay*: 500ms delay prevents rapid switching and reduces processing load

## Customization

### Adjust Light Threshold

Change the darkness detection threshold (default: 700):
cpp
if (lightValue > 850) { // More sensitive to darkness


### Modify Brightness Levels

cpp
analogWrite(LED, 200); // Adjust full brightness
analogWrite(LED, 50);  // Adjust dim level


### Change Update Frequency

cpp
delay(1000); // Update every 1 second instead of 500ms


## Applications

This system can be adapted for various use cases:

- Street and outdoor lighting
- Home automation (hallways, staircases, garages)
- Security and motion-activated lighting
- Office and warehouse lighting management
- Energy-saving applications in commercial spaces

### Scaling for Real-World Use

For practical deployment, consider:
- Replacing the LED with LED strips or floodlights
- Using a relay module to control AC-powered bulbs
- Adding multiple sensors for broader coverage
- Implementing wireless control (Bluetooth/WiFi modules)

## Troubleshooting

*LED doesn't turn on*
- Check all wire connections
- Verify power supply is connected
- Test LED separately with a simple circuit

*LED stays on constantly*
- Adjust the light threshold value in code
- Check PIR sensor positioning
- Verify there's sufficient ambient light during testing

*No Serial Monitor output*
- Verify baud rate is set to 9600
- Check USB connection
- Try a different USB cable or port

*PIR sensor not detecting motion*
- Allow 30-60 seconds for sensor calibration after power-on
- Check sensor range (typically 3-7 meters)
- Adjust sensor sensitivity if available

*Erratic behavior*
- Check for loose connections
- Verify power supply provides stable 5V
- Add longer delays between readings

## Contributing

Contributions are welcome. To contribute:

1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Submit a pull request with a clear description of improvements

## License

This project is open source and available under the MIT License.

## Contact

For questions or suggestions, please open an issue in the repository.

## Acknowledgments

- Arduino community for documentation and support
- Tinkercad for circuit simulation tools
