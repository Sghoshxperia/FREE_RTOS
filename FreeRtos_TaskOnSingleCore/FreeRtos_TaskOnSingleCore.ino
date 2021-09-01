void LedToggle(void *parameters)
{
  while(1){
    digitalWrite(2,HIGH);
    vTaskDelay(1000/portTICK_PERIOD_MS);
    digitalWrite(2,LOW);
    vTaskDelay(1000/portTICK_PERIOD_MS);
    Serial.println(xPortGetCoreID());
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); 
  pinMode(2,OUTPUT);

  xTaskCreatePinnedToCore(
    LedToggle,
    "toggle led",
    1024,
    NULL,
    2,
    NULL,
    1);
      
}

void loop() {
  // put your main code here, to run repeatedly:

}
