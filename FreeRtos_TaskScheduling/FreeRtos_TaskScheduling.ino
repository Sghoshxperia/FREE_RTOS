static int wait = 500;

void ReadFromUser(void *parameters)
{
  while(1){

    Serial.println("Enter the delay time for led:");
      
    while(Serial.available()==0){}
    wait = Serial.parseInt();

    Serial.print("Delay time updated to: ");
    Serial.println(wait);

    Serial.setTimeout(10000);
  }  
}

void LedToggle(void *parameters)
{
  while(1){
    digitalWrite(2,HIGH);
    vTaskDelay(wait/portTICK_PERIOD_MS);
    digitalWrite(2,LOW);
    vTaskDelay(wait/portTICK_PERIOD_MS);
   // Serial.println(xPortGetCoreID());
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); 
  vTaskDelay(1000/portTICK_PERIOD_MS);
  
  pinMode(2,OUTPUT);


  xTaskCreatePinnedToCore(
    LedToggle,
    "toggle led",
    1024,
    NULL,
    1,
    NULL,
    1);

   xTaskCreatePinnedToCore(
    ReadFromUser,
    "User Data",
    1024,
    NULL,
    1,
    NULL,
    1);
}

void loop() {
  // put your main code here, to run repeatedly:

}
