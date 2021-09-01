void LedToggle1(void *parameters)
{
  while(1){
    digitalWrite(2,HIGH);
    vTaskDelay(1000/portTICK_PERIOD_MS);
    digitalWrite(2,LOW);
    vTaskDelay(1000/portTICK_PERIOD_MS);
    Serial.println(xPortGetCoreID());
  }
}

void LedToggle2(void *parameters)
{
  while(1){
    digitalWrite(4,HIGH);
    vTaskDelay(500/portTICK_PERIOD_MS);
    digitalWrite(4,LOW);
    vTaskDelay(500/portTICK_PERIOD_MS);
    Serial.println(xPortGetCoreID());
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); 
  pinMode(2,OUTPUT);
  pinMode(4,OUTPUT);

  xTaskCreatePinnedToCore(
    LedToggle1,
    "toggle led 1",
    1024,
    NULL,
    2,
    NULL,
    1);
      

 xTaskCreatePinnedToCore(
    LedToggle2,
    "toggle led 2",
    1024,
    NULL,
    1,
    NULL,
    0);
      
}

void loop() {
  // put your main code here, to run repeatedly:

}
