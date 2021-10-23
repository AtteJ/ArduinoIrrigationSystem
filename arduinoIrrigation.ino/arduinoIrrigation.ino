const int RELAY_PIN = A5;
const int SENSOR_PIN = A4;

const int MOISTURE_LIMIT = 300;

float OUTPUT_VALUE;

void setup() {
  Serial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT);
}

void loop()
{
  for (int i = 0; i <= 100; i++)
  {
    OUTPUT_VALUE = OUTPUT_VALUE + analogRead(SENSOR_PIN);  // Reads from the soil moisture sensor
    delay(1);
  }
  OUTPUT_VALUE = OUTPUT_VALUE / 100;
  float OUTPUT_PERCENT = OUTPUT_VALUE / 1024 * 100; // Converts output to percents
  if (OUTPUT_VALUE < MOISTURE_LIMIT)
    pump_water();
  
  // Serial.println(OUTPUT_VALUE);
  Serial.print(OUTPUT_PERCENT);
  Serial.println(" %");
  delay(10000);
}

void pump_water() {
  digitalWrite(RELAY_PIN, HIGH); // turn on pump 1.5 seconds
  delay(1500);
  digitalWrite(RELAY_PIN, LOW);  // turn off pump
}
