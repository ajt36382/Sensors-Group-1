const int analogPin = 34; // ADC Pin
const int sampleRate = 10; // Sampling Rate (Hz)
const unsigned long interval = 1000000 / sampleRate; // Microseconds per sample

void setup() {
    Serial.begin(115200);
}

void loop() {
    unsigned long startTime = micros();
    int value = analogRead(analogPin);
    
    Serial.println(value);

    while (micros() - startTime < interval);
}
