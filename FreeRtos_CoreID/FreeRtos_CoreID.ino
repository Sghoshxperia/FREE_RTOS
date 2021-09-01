void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); 
  delay(7000);
  Serial.print("setup() is running on core:");
  Serial.println(xPortGetCoreID());

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("loop() is running on core:");
  Serial.println(xPortGetCoreID());

}
