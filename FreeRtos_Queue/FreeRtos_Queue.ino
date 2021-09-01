static QueueHandle_t msg_queue_1;
static QueueHandle_t msg_queue_2;
int len = 100;
int i = 0;
char command[] = "delay";

static int msg_queue_len_1 = 5;
static int msg_queue_len_2 = 5;

void Task_A(void *parameters){

  int item_a;

  while(1)
  {
    if(xQueueReceive(msg_queue_1, (void *)&item_a, 0) == pdTRUE){}
    Serial.println(item_a);  
    
    vTaskDelay(1000/portTICK_PERIOD_MS);
    
  }
  

}

void Task_B(void *parameters)
{
  int num = 5;

  
  while(1){  
  if(xQueueSend(msg_queue_1, (void *)&num, 10)!= pdTRUE){
    //Serial.println("Queue full");
  }
  
    num++;
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
  
  
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  vTaskDelay(1000 / portTICK_PERIOD_MS);

   msg_queue_1 = xQueueCreate(msg_queue_len_1, sizeof(int));

   xTaskCreatePinnedToCore(Task_A,
                          "Task A",
                          1024,
                          NULL,
                          1,
                          NULL,
                          1);

  xTaskCreatePinnedToCore(Task_B,
                          "Task B",
                          1024,
                          NULL,
                          1,
                          NULL,
                          1);
                          
}

void loop() {
  // put your main code here, to run repeatedly:

}
