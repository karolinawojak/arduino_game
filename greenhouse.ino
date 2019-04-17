#include <LiquidCrystal.h>
#include <NewPing.h>
#include <stdio.h>
#include <DS1302.h>
#include <TroykaDHT.h>

LiquidCrystal lcd(12,11,7,4,3,2); //RS, E, D4, D5, D6, D7

//TEMPERATURE AND HUMIDITY SENSOR 

DHT dht(A1, DHT11);  

//RTC

const int kCePin   = 10;  // Chip Enable
const int kIoPin   = 9;  // Input/Output
const int kSclkPin = 6;  // Serial Clock
DS1302 rtc(kCePin, kIoPin, kSclkPin);

//SOANR

#define TRIGGER_PIN  8
#define ECHO_PIN     13
#define MAX_DISTANCE 200
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

//OTHER SENSORS AND ELEMENTS

const int lamp = 5;
#define pump A4
#define buzzer A3
#define soil A0
#define light_sensor A2
#define button_read A5


void setup() {

  pinMode(lamp, OUTPUT); //RELAY - LAMP
  pinMode(pump, OUTPUT); //RELAY - PUMP
  pinMode(buzzer, OUTPUT); //BUZZER
  
  lcd.clear();
  lcd.begin(16, 2);
}

//DELAY

int del = 20;

//SCREEN HANDLING

int screen = 0;
int b1 = 0;
int b2 = 0;
int b3 = 0;
int b4 = 0;
int b5 = 0;

//PUMP ACTIVATION TIME HANDLING

int h1 = 1;
int h2 = 7;
int m1 = 0;
int m2 = 0;
int curr = 0;
int mode = 0;

//TIME SETTING FOR MODES

int h_morning_1 = 0; 
int h_morning_2 = 8;
int h_evening_1 = 1;
int h_evening_2 = 8;
int curr_mode = 0;

//LOW END AND HIGH END VALUES

const int min_light = 15;
const int min_dist = 15;
const int min_hum = 40;
const int pump_del = 500;
  
//ICONS

int water_icon = 0;
int bulb_icon = 0;

void loop() {

  //GETTING BUTTONS VOLTAGE
  
  int button = analogRead(button_read);
  int b1_l = 400;
  int b1_h = 550;
  int b2_l = 600;
  int b2_h = 680;
  int b3_l = 700;
  int b3_h = 750;
  int b4_l = 770;
  int b4_h = 900;
  int no_b = 1000;

  //VALUES FROM SENSORS
  
  int soil_humidity;
  int soil_humidity_pr; //PERCENTAGE
  int echo;
  int light;
  int light_p; //PERCENTAGE
  float temp;
  float hum;

  //TIME
  
  Time t = rtc.time();
  int hours = t.hr;
  int minutes = t.min;
  int seconds = t.sec;
  int years = t.yr;
  int months = t.mon;
  int days = t.date;
  
  //PUMP ON - DEFAULT
  
  digitalWrite(pump,0); 
  
  //LAMP ACTIVATION
  
  if (mode == 0 and screen == 0){
    if (hours >= (String(h_morning_1)+String(h_morning_2)).toInt() and hours <= (String(h_evening_1)+String(h_evening_2)).toInt()){
      light = analogRead(light_sensor);
      light_p = map(light, 0, 1023, 0, 100);
      
      if (light_p < min_light){
        digitalWrite(lamp, 1);
      }
        
      else {
        digitalWrite(lamp, 0);
      }
    }
    
    else {
      digitalWrite(lamp, 0);
      }
  }

  else if (mode == 1 and screen == 0) {
    if (hours >= (String(h_morning_1)+String(h_morning_2)).toInt() and hours <= (String(h_evening_1)+String(h_evening_2)).toInt()){
      light = analogRead(light_sensor);
      light_p = map(light, 0, 1023, 0, 100);

      if (light_p < min_light){
        digitalWrite(lamp, 1);
      }
        
      else {
        digitalWrite(lamp, 0);
      }
    }
    else {
      digitalWrite(lamp, 1);
    }
  }
  
  //PUMP ACTIVATION AT SPECIFIC TIME
  
  if (hours == (String(h1)+String(h2)).toInt() and minutes == (String(m1)+String(m2)).toInt() and seconds == 00 and screen == 0) {
    soil_humidity = analogRead(soil);
    soil_humidity_pr = map(soil_humidity, 0, 1023, 100, 0);
    
    if (soil_humidity_pr < min_hum) {
      echo = sonar.ping_cm();

      if (echo > min_dist) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Not enough water");
        digitalWrite(buzzer, 1);
        delay(1000);
        digitalWrite(buzzer, 0);
        delay(1000);
        water_icon = 1;
      }
      
      else {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Auto watering...");
        digitalWrite(pump,1);
        delay(pump_del);
        digitalWrite(pump,0);
        water_icon = 0;
      }
    }
  }
    
  if (button >= no_b) {
    b1 = 0;
    b2 = 0;
    b3 = 0;
    b4 = 0;
    b5 = 0;
  }

  //START SCREEN
  
  if (screen == 0 and b1 == 0 and b2 == 0 and b3 == 0 and b4 == 0 and b5 ==0) {
    byte droplet[] = {B00100,B00100,B01110,B01110,B11101,B11001,B10001,B01110};
    byte sun[] = {0b00100, 0b10101, 0b01110, 0b11111, 0b01110, 0b10101, 0b00100, 0b00000};
    byte moon[] = {0b00000, 0b00110, 0b01101, 0b11000, 0b11000, 0b01101, 0b00110, 0b00000};
    
    lcd.createChar(0,droplet);
    lcd.createChar(1,sun);
    lcd.createChar(2,moon);

    if (mode == 0) {
      lcd.setCursor(1,0);
      lcd.print(char(1));
    }

    else if (mode == 1) {
      lcd.setCursor(1,0);
      lcd.print(char(2));
    }

    
    if (water_icon == 1){
    lcd.setCursor(14,0);
    lcd.print(char(0));
    }

    lcd.setCursor(4,0);
    p2d(hours);
    lcd.setCursor(6,0);
    lcd.print(':');
    lcd.setCursor(7,0);
    p2d(minutes);
    lcd.setCursor(9,0);
    lcd.print(':');
    lcd.setCursor(10,0);
    p2d(seconds);
    lcd.setCursor(4,1);
    p2d(days);
    lcd.setCursor(6,1);
    lcd.print('/');
    lcd.setCursor(7,1);
    p2d(months);
    lcd.setCursor(9,1);
    lcd.print('/');
    lcd.setCursor(10,1);
    p2d(years);
    delay(del);
    lcd.clear();

    //SCREEN NAVIGATION
    
    if (button >= b1_l and button <= b1_h) {
      lcd.clear();
      lcd.setCursor(3,0);
      lcd.print("Statistics");
      delay(2000);
      lcd.clear();
      screen = 1;
      b1 = 1;
      }
      
    else if (button >= b2_l and button <= b2_h) {
      lcd.clear();
      lcd.setCursor(4,0);
      lcd.print("Set time");
      delay(2000);
      screen = 2;
      b2 = 1;
      }

    else if (button >= b3_l and button <= b3_h) {
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("Set light mode");
      delay(2000);
      screen = 3;
      b3 = 1;
      }

    else if (button >= b4_l and button <= b4_h) {
      lcd.clear();
      screen = 4;
      b4 = 1;
      }
    }

//STATISTIC SCREEN

else if (screen == 1) {
  dht.read();
  dht.getState();

  temp = dht.getTemperatureC();
  hum = dht.getHumidity();

  soil_humidity = analogRead(soil);
  soil_humidity_pr = map(soil_humidity, 0, 1023, 100, 0);

  light = analogRead(light_sensor);
  light_p = map(light, 0, 1023, 0, 100);
    
  byte droplet[] = {B00100,B00100,B01110,B01110,B11101,B11001,B10001,B01110};
  byte thermometer[] = {B00100,B01010,B01010,B01010,B01110,B11111,B11111,B01110};
  byte bubble[] = {B01110, B10001, B10101, B10101, B01110, B01010, B01110, B00100 };

  lcd.createChar(0,droplet);
  lcd.createChar(1,thermometer);
  lcd.createChar(2,bubble);

  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print('A');
  lcd.setCursor(2,0);
  lcd.print(char(0));
  lcd.setCursor(3,0);
  rearrange(hum);
  lcd.setCursor(6,0);
  lcd.print('%');
  lcd.setCursor(1,1);
  lcd.print('S');
  lcd.setCursor(2,1);
  lcd.print(char(0));
  lcd.setCursor(3,1);
  rearrange(soil_humidity_pr);
  lcd.setCursor(6,1);
  lcd.print('%');
  lcd.setCursor(10,0);
  lcd.print(char(1));
  lcd.setCursor(11,0);
  rearrange(temp);
  lcd.setCursor(14,0);
  lcd.print('C');
  lcd.setCursor(10,1);
  lcd.print(char(2));
  lcd.setCursor(11,1);
  rearrange(light_p);
  lcd.setCursor(14,1);
  lcd.print('%');

  //EXIT
  
  if (button >= b4_l and button <= b4_h) {
    lcd.clear();
    screen = 0;
    b4 = 1;
    }
  delay(del);
}

//SCREEN FOR SETTING PUMP TIMES

else if (screen == 2){

    byte underscore[] = {0b11111, 0b01110, 0b00100, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000};
    lcd.createChar(0,underscore);
  
    lcd.clear();
    lcd.setCursor(5,0);
    lcd.print(String(h1) + String(h2) + ":" + String(m1) + String(m2));
    lcd.setCursor(curr+5,1);
    lcd.print(char(0));
    
    if (button >= b1_l and button <= b1_h) {
      delay(200);
      curr = curr - 1;
      if (curr == 2){
        curr = 1;
      }
      if (curr < 0) {
        curr = 4;
      }
    }

    else if (button >= b2_l and button <= b2_h) {
      delay(200);
      curr = curr + 1;
      if (curr == 2){
        curr = 3;
      }
      if (curr > 4) {
        curr = 0;
      }
    }
    
    if (button >= b3_l and button <= b3_h) {
    delay(200);
      
      if (curr == 0){
        h1 = h1 + 1;
        if (h1 > 2 or (h1 == 2 and h2 > 3)){
          h1 = 0;
        }
      }
      else if (curr == 1){
        h2 = h2 + 1;
        if ((h1 != 2 and h2 > 9) or (h1 == 2 and h2 > 3)){
          h2 = 0;
        }
      }
      else if (curr == 3){
        m1 = m1 + 1;
        if (m1 > 5){
          m1 = 0;
        }
      }
      else if (curr == 4){
        m2 = m2 + 1;
        if (m2 > 9){
          m2 = 0;
        }
      }
    }
    
    //EXIT
    
    if (button >= b4_l and button <= b4_h) {
      lcd.clear();
      screen = 0;
      b4 = 1;
      curr = 0;
    }
  delay(del);
}

//SCREEN FOR SETTING MODE

else if (screen == 3) {
  
  lcd.clear();
  
  lcd.setCursor(2,0);
  lcd.print("Day only");
  lcd.setCursor(2,1);
  lcd.print("Day and night");

  if (button >= b3_l and button <= b3_h) {
    delay(200);
    if (curr == 0){
      curr = 1;
    }
    else if (curr == 1){
      curr = 0;
    }
  }
  
  if (curr == 0){
    lcd.setCursor(0,0);
    lcd.print("*");
    mode = 0;
  }
  else if (curr == 1) {
    lcd.setCursor(0,1);
    lcd.print("*");
    mode = 1;
  }

  //SETTING MODE TIMES
  
   if (button >= b1_l and button <= b1_h){
    delay(200);
    screen = 5;
    b5 = 1;
   }
   
  //EXIT
  
  if (button >= b4_l and button <= b4_h) {
    lcd.clear();
    screen = 0;
    b4 = 1;
  }
  delay(21);
  
}

//NON-AUTOMATED WATERING 
else if (screen == 4){
    
    lcd.clear();
    delay(500);
    
    soil_humidity = analogRead(soil);
    soil_humidity_pr = map(soil_humidity, 0, 1023, 100, 0);
    lcd.setCursor(0,0);
    lcd.print("Humidity: " + String(soil_humidity_pr) + "%");
    delay(2000);

    echo = sonar.ping_cm();
    if (echo > min_dist) {
      digitalWrite(buzzer, 1);
      lcd.setCursor(0,1);
      lcd.print("Not enough water");
      delay(1000);
      digitalWrite(buzzer, 0);
      delay(2000);
      water_icon = 1;
    }
    
    else {
      lcd.setCursor(0,1);
      lcd.print("Water level ok");
      delay(2000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Humidity: " + String(soil_humidity_pr) + "%");
      lcd.setCursor(0,1);
      lcd.print("Watering...");
      digitalWrite(pump,1);
      delay(5000);
      digitalWrite(pump,0);
      soil_humidity = analogRead(soil);
      soil_humidity_pr = map(soil_humidity, 0, 1023, 100, 0);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Humidity: " + String(soil_humidity_pr) + "%");
      delay(2000);
      water_icon = 0;
    }
    
    b4 = 0;
    screen = 0;    
  }

  //SCREEN FOR SETTING MODE TIMES
  
  else if (screen == 5){
    byte underscore[] = {0b11111, 0b01110, 0b00100, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000};
    byte sun[] = {0b00100, 0b10101, 0b01110, 0b11111, 0b01110, 0b10101, 0b00100, 0b00000};
    byte moon[] = {0b00000, 0b00110, 0b01101, 0b11000, 0b11000, 0b01101, 0b00110, 0b00000};
    
    lcd.createChar(0,underscore);
    lcd.createChar(1,sun);
    lcd.createChar(2,moon);
  
    lcd.clear();
    lcd.setCursor(3,0);
    lcd.print(char(1));
    lcd.setCursor(12,0);
    lcd.print(char(2));
    
    lcd.setCursor(5,0);
    lcd.print(String(h_morning_1) + String(h_morning_2) + "-" + String(h_evening_1) + String(h_evening_2));
    lcd.setCursor(curr_mode+5,1);
    lcd.print(char(0));
    
    if (button >= b1_l and button <= b1_h) {
      delay(200);
      curr_mode = curr_mode - 1;
      if (curr_mode == 2){
        curr_mode = 1;
      }
      if (curr_mode < 0) {
        curr_mode = 4;
      }
    }

    else if (button >= b2_l and button <= b2_h) {
      delay(200);
      curr_mode = curr_mode + 1;
      if (curr_mode == 2){
        curr_mode = 3;
      }
      if (curr_mode > 4) {
        curr_mode = 0;
      }
    }
    
    if (button >= b3_l and button <= b3_h) {
    delay(200);
      
      if (curr_mode== 0){
        h_morning_1 = h_morning_1 + 1;
        if (h_morning_1 > 2 or (h_morning_1 == 2 and h_morning_2 > 3)){
          h_morning_1 = 0;
        }
      }
      
      else if (curr_mode == 1){
        h_morning_2 = h_morning_2 + 1;
        if ((h_morning_1 != 2 and h_morning_2 > 9) or (h_morning_1 == 2 and h_morning_2 > 3)){
          h_morning_2 = 0;
        }
      }
      
      else if (curr_mode == 3){
        h_evening_1 = h_evening_1 + 1;
        if (h_evening_1 > 2 or (h_evening_1 == 2 and h_evening_2 > 3)){
          h_evening_1 = 0;
        }
      }
      
      else if (curr_mode == 4){
        h_evening_2 = h_evening_2 + 1;
        if ((h_evening_1 != 2 and h_evening_2 > 9) or (h_evening_1 == 2 and h_evening_2 > 3)){
          h_evening_2 = 0;
        }
      }
    }
    
    //EXIT
    
    if (button >= b4_l and button <= b4_h) {
      lcd.clear();
      screen = 0;
      b5 = 1;
      curr_mode = 0;
    }
  delay(del);
  }
}

//TWO DIGIT NUMBERS FOR TIMER

void p2d(int number) {
  if (number >= 0 and number < 10) {
    lcd.print('0'+String(number));
  }
  else {
  lcd.print(number);
  }
}

//FREEZING VALUES FOR STATISTIC SCREEN
void rearrange(int number) {
  if (number < 100 and number >= 10) {
    lcd.print(' '+String(number));
  }
  else if (number < 10) {
    lcd.print("  "+String(number));
  }
  
  else {
    lcd.print(number);
  }
}
