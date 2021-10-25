const int RELAY_PIN = A5;
const int SENSOR_PIN = A4;

const int MOISTURE_LIMIT = 600;
const int WATERING_TIME = 1500;

float OUTPUT_VALUE;

void setup() {
  Serial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT);
}

void loop()
{
  OUTPUT_VALUE = get_moisture();
  
  if (OUTPUT_VALUE < MOISTURE_LIMIT)
    pump_water(WATERING_TIME);
  
  Serial.println(OUTPUT_VALUE);
  delay(10000);
}


float get_moisture() {
  float SENSOR_READ = 0;
  for (int i = 0; i <= 100; i++)
  {
    SENSOR_READ = SENSOR_READ + analogRead(SENSOR_PIN);  // Reads from the soil moisture sensor
    delay(1);
  }
  SENSOR_READ = SENSOR_READ / 100;

  return SENSOR_READ;
}


void pump_water(int WATERING_TIME) {
  digitalWrite(RELAY_PIN, HIGH); // turn on pump 1.5 seconds
  delay(WATERING_TIME);
  digitalWrite(RELAY_PIN, LOW);  // turn off pump
}
