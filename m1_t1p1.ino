const int tempSensorPin = A0; // Pin where the temperature sensor is connected
const int ledPin = 13; // Pin where the LED is connected (built-in LED)
const float thresholdTemperature = 30.0; // Threshold temperature in Celsius

void setup() {
  pinMode(ledPin, OUTPUT); // Set LED pin as output
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  int sensorValue = analogRead(tempSensorPin); // Read the temperature sensor
  float voltage = sensorValue * (5.0 / 1023.0); // Convert the analog reading to voltage
  float temperatureC = (voltage - 0.5) * 100.0; // Convert voltage to temperature in Celsius

  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" °C");

  if (temperatureC > thresholdTemperature) {
    digitalWrite(ledPin, HIGH); // Turn LED on
    Serial.println("Temperature above threshold: LED ON");
  } else {
    digitalWrite(ledPin, LOW); // Turn LED off
    Serial.println("Temperature below threshold: LED OFF");
  }
  delay(1000); // Wait for a second
}

