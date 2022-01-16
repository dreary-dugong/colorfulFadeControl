const int rPin = 9;
const int gPin = 10;
const int bPin = 11;

const int potPin1 = A1;
const int potPin2 = A2;

unsigned int time = 0;

void setup() {
    pinMode(rPin, OUTPUT);    
    pinMode(gPin, OUTPUT);    
    pinMode(bPin, OUTPUT);    
    
    pinMode(potPin1, INPUT);
    pinMode(potPin1, INPUT);
    Serial.begin(9600);
}

void loop() {
    
    digitalWrite(bPin, HIGH);

    int pot1Sig = analogRead(potPin1);
    int pot2Sig = analogRead(potPin1);
    
    float rRate = exp(pot1Sig * (7.0/1023.0)) * 0.001;
    float rStrength = 255.0 * (sin(rRate * time)+1.0)/2.0;

    float gRate = exp(pot2Sig * (7.0/1023.0)) * 0.001;
    float gStrength = 255.0 * (sin(gRate * time)+1.0)/2.0;
    
    Serial.println(pot1Sig);
    Serial.println(rRate);
    Serial.println(rStrength);
    Serial.println(time);
    Serial.println( );
    
    analogWrite(rPin, rStrength);
    analogWrite(gPin, gStrength);
    delay(10);
    
    time += 1;
    
}
