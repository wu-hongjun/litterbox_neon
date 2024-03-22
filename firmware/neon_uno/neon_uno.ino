const int TRIG_PIN1 = 2;
const int ECHO_PIN1 = 3;
const int TRIG_PIN2 = 6;
const int ECHO_PIN2 = 7;
const int RELAY_PIN = 5;

unsigned long previousTime = 0;
const long interval = 250; // 0.52 seconds
long previousDistance1 = 0, previousDistance2 = 0;
const long distanceChangeThreshold = 10; // Change threshold in cm
unsigned long lightOffStartTime = 0;
const long lightOffDelay = 5000; // 5 seconds delay
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

long measureDistance(int triggerPin, int echoPin) {
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2;
}

void loop() {
  unsigned long currentTime = millis();

  if (currentTime - previousTime >= interval) {
    long distance1 = measureDistance(TRIG_PIN1, ECHO_PIN1);
    long distance2 = measureDistance(TRIG_PIN2, ECHO_PIN2);
    
    Serial.print("Bottom Distance: ");
    Serial.print(distance1);
    Serial.println(" cm");
    Serial.print("Top Distance: ");
    Serial.print(distance2);
    Serial.println(" cm");

    if (abs(distance1 - previousDistance1) > distanceChangeThreshold || abs(distance2 - previousDistance2) > distanceChangeThreshold) {
      digitalWrite(RELAY_PIN, HIGH); // Turn on the light
      lightOn = true;
      lightOffStartTime = millis();
    } else if (lightOn && currentTime - lightOffStartTime >= lightOffDelay) {
      digitalWrite(RELAY_PIN, LOW); // Turn off the light after 3 seconds
      lightOn = false;
    }

    previousDistance1 = distance1;
    previousDistance2 = distance2;
    previousTime = currentTime;
  }
}
