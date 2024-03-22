const int TRIG_PIN1 = 2;
const int ECHO_PIN1 = 3;
const int TRIG_PIN2 = 6; // New trigger pin for the second sensor
const int ECHO_PIN2 = 7; // New echo pin for the second sensor
const int RELAY_PIN = 5;

unsigned long lightOffStartTime = 0; // Tracks when both sensors exceed their distance threshold
const long lightOffDelay = 3000; // 3 seconds delay
bool lightOn = false;

void setup() {
  pinMode(TRIG_PIN1, OUTPUT);
  pinMode(ECHO_PIN1, INPUT);
  pinMode(TRIG_PIN2, OUTPUT);
  pinMode(ECHO_PIN2, INPUT);
  pinMode(RELAY_PIN, OUTPUT);

  digitalWrite(RELAY_PIN, LOW); // Start with the relay off
  Serial.begin(9600);
}

void loop() {
  long duration1, distance1, duration2, distance2;

  // First sensor measurement
  digitalWrite(TRIG_PIN1, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN1, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN1, LOW);
  duration1 = pulseIn(ECHO_PIN1, HIGH);
  distance1 = duration1 * 0.034 / 2;

  // Second sensor measurement
  digitalWrite(TRIG_PIN2, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN2, LOW);
  duration2 = pulseIn(ECHO_PIN2, HIGH);
  distance2 = duration2 * 0.034 / 2;

  // Debugging output
  Serial.print("Distance 1: ");
  Serial.print(distance1);
  Serial.println(" cm");
  Serial.print("Distance 2: ");
  Serial.print(distance2);
  Serial.println(" cm");

  // Light control logic
  if (distance1 < 100 || distance2 < 50) {
    digitalWrite(RELAY_PIN, HIGH); // Turn on the light
    lightOn = true;
    lightOffStartTime = millis(); // Reset the timer whenever the light is turned on
  } else if (lightOn && millis() - lightOffStartTime >= lightOffDelay) {
    digitalWrite(RELAY_PIN, LOW); // Turn off the light after 3 seconds
    lightOn = false;
  }

  delay(100); // Short delay to prevent too rapid triggering
}
