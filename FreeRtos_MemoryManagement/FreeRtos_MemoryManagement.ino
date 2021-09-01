char *msg_ptr = NULL;
//char msg_ptr[100] = "";
char str[100] = "";
unsigned int len = 0;
int flag = 0;
char c = ' ';  
int i = 0;



void ReadFromUser(void *parametes){

  memset(str, 0, 100);

  while(1){
  
  
  if(Serial.available()>0){
  c = Serial.read();

   if(i<100)
   {
    str[i]=c;
    i++;
   }
 }
  
  if(c == '\n'){
  len = i-1;
  str[len] = '\0';
  
    if(flag==0)
    {
    msg_ptr = (char*)pvPortMalloc(len*sizeof(char));
    configASSERT(msg_ptr);
     
    memcpy(msg_ptr, str, len+1);
    flag = 1;
   // Serial.println(flag);
    }

  memset(str, 0, 100);
  len = 0;
  }
 }
  
}

void DisplayFromUser(void *parameters){

  
    while(1){
     Serial.println("i am here");
      if(flag==1)
      {
        Serial.print("The string is: ");
        Serial.println(msg_ptr);
        vPortFree(msg_ptr);
        msg_ptr = NULL;
        flag = 0;
      }
   }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  vTaskDelay(5000 / portTICK_PERIOD_MS);
  Serial.println("Enter a String:");

   xTaskCreatePinnedToCore(ReadFromUser,
                          "Read Serial",
                          1500,
                          NULL,
                          1,
                          NULL,
                          1);

  // Start Serial print task
  xTaskCreatePinnedToCore(DisplayFromUser,
                          "Print Message",
                          1500,
                          NULL,
                          1,
                          NULL,
                          1);

}

void loop() {
  // put your main code here, to run repeatedly:

}
