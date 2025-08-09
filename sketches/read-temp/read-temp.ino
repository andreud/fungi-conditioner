const int sensorPin = 34; // Entrada analógica del ESP32 (puedes usar A0 o GPIO34)

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);  // Initialize the built-in LED pin as an output

}

void loop() {
  int rawValue = analogRead(sensorPin);         // Lectura del ADC
  float voltage = rawValue * (3.3 / 4095.0);     // Convertir a voltaje (ESP32 usa ADC de 12 bits)
  float temperatureC = voltage * 100.0;          // LM35: 10 mV/°C → 100°C/V

  Serial.print("Temperatura: ");
  Serial.print(temperatureC);
  Serial.println(" °C");
  // digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED on
  // delay(1000);                      // Wait for 1 second
  // digitalWrite(LED_BUILTIN, LOW);   // Turn the LED off
  // delay(1000);   

  Serial.print("hello");
  //Serial.print(rawValue);

  delay(1000); // Esperar 1 segundo
}
