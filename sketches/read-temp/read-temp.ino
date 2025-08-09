#define ADC_VREF_mV 3.3 // in millivolt, original 3300.3
#define ADC_RESOLUTION 1024.0

const int sensorPin = 34; // Entrada analógica del ESP32 (puedes usar A0 o GPIO34)

void setup() {
  Serial.begin(115200);
  //pinMode(LED_BUILTIN, OUTPUT);  // Initialize the built-in LED pin as an output
}

void loop() {
  int rawValue = analogRead(sensorPin);// Lectura del ADC
  Serial.print(rawValue);
  //tempCalc1(rawValue);
  
  float milliVolt = rawValue * (ADC_VREF_mV / ADC_RESOLUTION);
  float temperature_C = milliVolt / 10;
  float temperature_F = temperature_C * 9 / 5 + 32;
  Serial.print("Temperature: ");
  Serial.print(temperature_C);   // print the temperature in °C
  Serial.print("°C");
  Serial.print("  ~  "); // separator between °C and °F
  Serial.print(temperature_F);   // print the temperature in °F
  Serial.println("°F");
  
  delay(1000); // Esperar 1 segundo
}

/*
void tempCalc1(int rawValue){
  float milliVolt = rawValue * (ADC_VREF_mV / ADC_RESOLUTION);
  float temperature_C = milliVolt / 10;
  // convert the °C to °F
  float temperature_F = temperature_C * 9 / 5 + 32;
  Serial.print("Temperature: ");
  Serial.print(temperature_C);   // print the temperature in °C
  Serial.print("°C");
  Serial.print("  ~  "); // separator between °C and °F
  Serial.print(temperature_F);   // print the temperature in °F
  Serial.println("°F");
}

void tempCalc2(int rawValue){
  float voltage = rawValue * (3.3 / 4095.0);     // Convertir a voltaje (ESP32 usa ADC de 12 bits)
  float temperatureC = voltage * 100.0;          // LM35: 10 mV/°C → 100°C/V
  Serial.print("Temperatura: ");
  Serial.print(temperatureC);
  Serial.println(" °C");
}*/