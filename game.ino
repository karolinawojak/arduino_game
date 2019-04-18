#include <LiquidCrystal.h>

LiquidCrystal lcd(8,9,4,5,6,7);

void setup() {

  welcome();
  delay(500);
  startup_anim_01();
  delay(500);
  lcd.clear();
  lcd.begin(16, 2);
}

int x;
int start_set = 1;
int wel_del = 300;
int if_menu = 1;
int sel_menu = 0;
bool if_exit = 0;
int which_map = 0;
int cars_x[25] = {13, 18, 21, 25, 29, 32, 36, 40, 47, 53, 60, 65, 70, 74, 78, 82, 85, 89, 93, 99, 103, 108, 112, 116,121};
int cars_y[25] = {1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0};
int fail_menu = 0;
 
void loop() {
  
  if (if_exit == 1){
    lcd.clear();

    int exit_time;
   
    for (exit_time = 0; exit_time < 4; exit_time++)
    {
      exit();   
    }
    lcd.noDisplay();
  }

  if (if_exit == 0){
    
    if (if_menu == 1){
      menu();
    }
  }
  
  if (if_menu == 0){
    int intr_1;
    int intr_2;

   for (intr_1 = 0; intr_1 < 1; intr_1++){
      intro_1();
    }
    lcd.clear();
    
    for (intr_2 = 0; intr_2 < 5; intr_2++){
      talking_boy();
      lcd.setCursor(5,0); 
      lcd.print("TIME TO");
      lcd.setCursor(5,1); 
      lcd.print("GET UP");
      delay(300);
    }
    which_map = 1;
    lcd.clear();
    }
  if (which_map == 1) {
    if_menu = 2;
    map_01();
  }
  else if (which_map==2){
    map_02(); 
  }
    else if (which_map==3){
    map_03();
  }
    else if (which_map==4){
    map_04(); 
  }
    else if (which_map==5){
      if (fail_menu == 0){
        map_05(); 
      }
      else if (fail_menu == 1){
        menu_2();
      }
  }
    else if (which_map==6){
    map_06();
  }
    else if (which_map==7){
    map_07();
  }
    else if (which_map==8){
    map_08();
  }
    else if (which_map==9){
    map_09();
  }

}

//FUNCTIONS FOR LETTER CREATION

void w(){
  byte L_up[8] = {0b01000,0b01000,0b01000,0b01000,0b01000,0b01000,0b01000,0b01000};
  byte L_down[8] = {0b01000,0b01000,0b01000,0b01000,0b01001,0b01010,0b01100,0b01000};
  byte R_up[8] = {0b00010,0b00010,0b00010,0b00010,0b00010,0b00010,0b00010,0b00010};
  byte R_down[8] = {0b00010,0b00010,0b00010,0b00010,0b10010,0b01010,0b00110,0b00010};
  
  lcd.createChar(1, L_up);
  lcd.createChar(2, L_down);
  lcd.createChar(3, R_up);
  lcd.createChar(4, R_down);

  lcd.begin(16, 2);
  lcd.clear();
  
  lcd.setCursor(1,0);
  lcd.print(char(1));

  lcd.setCursor(1,1);
  lcd.print(char(2));

  lcd.setCursor(2,0);
  lcd.print(char(3));

  lcd.setCursor(2,1);
  lcd.print(char(4));

  delay(wel_del);  
}

void e(){
  byte L_up[8] = {0b01111,0b01000,0b01000,0b01000,0b01000,0b01000,0b01000,0b01111};
  byte L_down[8] = {0b01000,0b01000,0b01000,0b01000,0b01000,0b01000,0b01000,0b01111};
  byte R_up[8] = {0b11110,0b00000,0b00000,0b00000,0b00000,0b00000,0b00000,0b11100};
  byte R_down[8] = {0b00000,0b00000,0b00000,0b00000,0b00000,0b00000,0b00000,0b11110};
  
  lcd.createChar(1, L_up);
  lcd.createChar(2, L_down);
  lcd.createChar(3, R_up);
  lcd.createChar(4, R_down);

  lcd.clear();
  
  lcd.setCursor(3,0);
  lcd.print(char(1));

  lcd.setCursor(3,1);
  lcd.print(char(2));

  lcd.setCursor(4,0);
  lcd.print(char(3));

  lcd.setCursor(4,1);
  lcd.print(char(4));

  delay(wel_del); 
}

void l(){
  byte L_up[8] = {0b01000,0b01000,0b01000,0b01000,0b01000,0b01000,0b01000,0b01000};
  byte L_down[8] = {0b01000,0b01000,0b01000,0b01000,0b01000,0b01000,0b01000,0b01111};
  byte R_down[8] = {0b00000,0b00000,0b00000,0b00000,0b00000,0b00000,0b00000,0b11110};
  
  lcd.createChar(1, L_up);
  lcd.createChar(2, L_down);
  lcd.createChar(4, R_down);

  lcd.clear();
  
  lcd.begin(16, 2);
   
  lcd.setCursor(5,0);
  lcd.print(char(1));

  lcd.setCursor(5,1);
  lcd.print(char(2));

  lcd.setCursor(6,1);
  lcd.print(char(4));

  delay(wel_del);  
}

void c(){
  byte L_up[8] = {0b01111,0b01000,0b01000,0b01000,0b01000,0b01000,0b01000,0b01000};
  byte L_down[8] = {0b01000,0b01000,0b01000,0b01000,0b01000,0b01000,0b01000,0b01111};
  byte R_up[8] = {0b11110,0b00000,0b00000,0b00000,0b00000,0b00000,0b00000,0b00000};
  byte R_down[8] = {0b00000,0b00000,0b00000,0b00000,0b00000,0b00000,0b00000,0b11110};
  
  lcd.createChar(1, L_up);
  lcd.createChar(2, L_down);
  lcd.createChar(3, R_up);
  lcd.createChar(4, R_down);

  lcd.clear();
  
  lcd.setCursor(7,0);
  lcd.print(char(1));

  lcd.setCursor(7,1);
  lcd.print(char(2));

  lcd.setCursor(8,0);
  lcd.print(char(3));

  lcd.setCursor(8,1);
  lcd.print(char(4));

  delay(wel_del);
}

void o(){
  byte L_up[8] = {0b01111,0b01000,0b01000,0b01000,0b01000,0b01000,0b01000,0b01000};
  byte L_down[8] = {0b01000,0b01000,0b01000,0b01000,0b01000,0b01000,0b01000,0b01111};
  byte R_up[8] = {0b11110,0b00010,0b00010,0b00010,0b00010,0b00010,0b00010,0b00010};
  byte R_down[8] = {0b00010,0b00010,0b00010,0b00010,0b00010,0b00010,0b00010,0b11110};
  
  lcd.createChar(1, L_up);
  lcd.createChar(2, L_down);
  lcd.createChar(3, R_up);
  lcd.createChar(4, R_down);

  lcd.clear();
  
  lcd.setCursor(9,0);
  lcd.print(char(1));

  lcd.setCursor(9,1);
  lcd.print(char(2));

  lcd.setCursor(10,0);
  lcd.print(char(3));

  lcd.setCursor(10,1);
  lcd.print(char(4));

  delay(wel_del);
}

void m(){
  byte L_up[8] = {0b01000,0b01100,0b01010,0b01001,0b01000,0b01000,0b01000,0b01000};
  byte L_down[8] = {0b01000,0b01000,0b01000,0b01000,0b01000,0b01000,0b01000,0b01000};
  byte R_up[8] = {0b00010,0b00110,0b01010,0b10010,0b00010,0b00010,0b00010,0b00010};
  byte R_down[8] = {0b00010,0b00010,0b00010,0b00010,0b00010,0b00010,0b00010,0b00010};
  
  lcd.createChar(1, L_up);
  lcd.createChar(2, L_down);
  lcd.createChar(3, R_up);
  lcd.createChar(4, R_down);

  lcd.clear();
  
  lcd.setCursor(11,0);
  lcd.print(char(1));

  lcd.setCursor(11,1);
  lcd.print(char(2));

  lcd.setCursor(12,0);
  lcd.print(char(3));

  lcd.setCursor(12,1);
  lcd.print(char(4));

  delay(wel_del);
}

void e2(){
  byte L_up[8] = {0b01111,0b01000,0b01000,0b01000,0b01000,0b01000,0b01000,0b01111};
  byte L_down[8] = {0b01000,0b01000,0b01000,0b01000,0b01000,0b01000,0b01000,0b01111};
  byte R_up[8] = {0b11110,0b00000,0b00000,0b00000,0b00000,0b00000,0b00000,0b11100};
  byte R_down[8] = {0b00000,0b00000,0b00000,0b00000,0b00000,0b00000,0b00000,0b11110};
  
  lcd.createChar(1, L_up);
  lcd.createChar(2, L_down);
  lcd.createChar(3, R_up);
  lcd.createChar(4, R_down);

  lcd.clear();
  
  lcd.setCursor(13,0);
  lcd.print(char(1));

  lcd.setCursor(13,1);
  lcd.print(char(2));

  lcd.setCursor(14,0);
  lcd.print(char(3));

  lcd.setCursor(14,1);
  lcd.print(char(4));

  delay(wel_del);
}

//END FUNCTIONS FOR LETTER CREATION

//WELCOME ANIMATION

void welcome() {
  w();
  e();
  l();
  c();
  o();
  m();
  e2();
}

void startup_anim_01(){
  byte hero[8] = {B00000,B01110,B01010,B00100,B01010,B00100,B01010,};

  lcd.createChar(0, hero);
  lcd.clear();
  
  int x;
  for (x = 15; x >= 0; x = x-1)
  {
    lcd.setCursor(x,0);
    lcd.print(char(0));
    delay(150);
  }
  for (x; x <= 15; x = x+1)
  {
    lcd.setCursor(x,1);
    lcd.print(char(0));
    delay(150);
  }
}

//MENU CREATION - SELECTION

void menu () {

  byte circle_0[8] = {0b00000,0b00100,0b01010,0b10001,0b10001,0b01010,0b00100,0b00000};
  byte circle_1[8] = {0b00000,0b00100,0b01110,0b11111,0b11111,0b01110,0b00100,0b00000};

  int a_read = analogRead(A0);

  int a1_low = 100;
  int a1_high = 160;
  int a2_low = 250;
  int a2_high = 350;
  int a3_low = 650;
  int a3_high = 740;

  lcd.createChar(0, circle_0);
  lcd.createChar(1, circle_1);
  
  if (a_read > a1_low and a_read < a1_high)
  {
    sel_menu = 0;
    delay(200);
  }

  if (a_read > a2_low and a_read < a2_high)
  {
    sel_menu = 1;
    delay(200);
  }

  lcd.setCursor(6,0);
  lcd.print("PLAY");
  lcd.setCursor(6,1);
  lcd.print("EXIT");

  
  if (sel_menu == 0) {
    
    lcd.setCursor(5,0); 
    lcd.print(char(0));
    delay(100);
    lcd.setCursor(5,0);
    lcd.print(char(1));
    delay(100);
  
    lcd.setCursor(10,0);
    lcd.print(char(0));
    delay(100);
    lcd.setCursor(10,0);
    lcd.print(char(1));
    delay(100);

    lcd.setCursor(5,1); 
    lcd.print(" ");
  
    lcd.setCursor(10,1);
    lcd.print(" ");

    if (a_read > a3_low and a_read < a3_high) {
      if_menu = 0;
    }
  }

  else if (sel_menu == 1) {
  
    lcd.setCursor(5,1); 
    lcd.print(char(0));
    delay(100);
    lcd.setCursor(5,1);
    lcd.print(char(1));
    delay(100);
  
    lcd.setCursor(10,1);
    lcd.print(char(0));
    delay(100);
    lcd.setCursor(10,1);
    lcd.print(char(1));
    delay(100);
  
    lcd.setCursor(5,0); 
    lcd.print(" ");
  
    lcd.setCursor(10,0);
    lcd.print(" ");

    if (a_read > a3_low and a_read < a3_high) {
      if_exit = 1;
    }
  }
}

//EXIT ANIMATION

void exit() {

  byte hand_opened_l_u[8] = {0b00000,0b00001,0b00010,0b00010,0b00010,0b00010,0b00010,0b11010};
  byte hand_opened_r_u[8] = {0b01000,0b10100,0b10110,0b10101,0b10101,0b10101,0b10101,0b00001};
  byte hand_opened_l_d[8] = {0b10110,0b10010,0b01000,0b00100,0b00100,0b00010,0b00011,0b00000};
  byte hand_opened_r_d[8] = {0b00001,0b00001,0b00010,0b00010,0b00100,0b00100,0b11100,0b00000};

  byte hand_closed_l_u[8] = {0b00000,0b00000,0b00000,0b00000,0b00001,0b00010,0b00010,0b11010};
  byte hand_closed_r_u[8] = {0b00000,0b00000,0b00000,0b00000,0b11010,0b10101,0b10101,0b10101};
  byte hand_closed_l_d[8] = {0b10110,0b10001,0b01000,0b00100,0b00100,0b00010,0b00011,0b00000};
  byte hand_closed_r_d[8] = {0b10101,0b10101,0b01010,0b00010,0b00100,0b00100,0b11100,0b00000};
  
  lcd.createChar(0, hand_opened_l_u);
  lcd.createChar(1, hand_opened_r_u);
  lcd.createChar(2, hand_opened_l_d);
  lcd.createChar(3, hand_opened_r_d);

  lcd.setCursor(1,0); 
  lcd.print("BYE");

  lcd.setCursor(4,1); 
  lcd.print("BYE");
  
  lcd.setCursor(13,0); 
  lcd.print(char(0));

  lcd.setCursor(14,0); 
  lcd.print(char(1));

  lcd.setCursor(13,1); 
  lcd.print(char(2));

  lcd.setCursor(14,1); 
  lcd.print(char(3));

  delay(500);

  lcd.createChar(4, hand_closed_l_u);
  lcd.createChar(5, hand_closed_r_u);
  lcd.createChar(6, hand_closed_l_d);
  lcd.createChar(7, hand_closed_r_d);
  
  lcd.setCursor(13,0); 
  lcd.print(char(4));

  lcd.setCursor(14,0); 
  lcd.print(char(5));

  lcd.setCursor(13,1); 
  lcd.print(char(6));

  lcd.setCursor(14,1); 
  lcd.print(char(7));

  delay(500);
  
}

//INTRO ANIMATIONS

void intro_1 (){
  byte bed_0[8] = {0b00000, 0b00000, 0b11111, 0b10000, 0b10000, 0b10110, 0b11001, 0b11001};
  byte bed_1[8] = {0b00000, 0b00000, 0b11111, 0b01000, 0b01000, 0b01000, 0b01000, 0b11000};
  byte bed_2[8] = {0b00000, 0b00000, 0b11111, 0b00001, 0b00001, 0b00001, 0b00001, 0b00001};
  byte bed_3[8] = {0b11001, 0b11001, 0b10110, 0b10000, 0b11111, 0b00000, 0b00000, 0b00000};
  byte bed_4[8] = {0b11000, 0b01000, 0b01000, 0b01000, 0b11111, 0b00000, 0b00000, 0b00000};
  byte bed_5[8] = {0b00001, 0b00001, 0b00001, 0b00001, 0b11111, 0b00000, 0b00000, 0b00000};
  
  lcd.createChar(0, bed_0);
  lcd.createChar(1, bed_1);
  lcd.createChar(2, bed_2);
  lcd.createChar(3, bed_3);
  lcd.createChar(4, bed_4);
  lcd.createChar(5, bed_5);

  lcd.clear();

  lcd.setCursor(1,0); 
  lcd.print(char(0));
  lcd.setCursor(2,0); 
  lcd.print(char(1));
  lcd.setCursor(3,0); 
  lcd.print(char(2));
  lcd.setCursor(1,1); 
  lcd.print(char(3));
  lcd.setCursor(2,1); 
  lcd.print(char(4));
  lcd.setCursor(3,1); 
  lcd.print(char(5));
  
  lcd.setCursor(5,0); 
  lcd.print("zZz...");
  delay(1200);
  lcd.setCursor(5,0); 
  lcd.print("      ");
  
  lcd.setCursor(7,1); 
  lcd.print("zZz...");
  delay(1200);
  lcd.setCursor(7,1); 
  lcd.print("      ");
  
  lcd.setCursor(10,0); 
  lcd.print("zZz...");
  delay(1200);
  lcd.setCursor(10,0); 
  lcd.print("      ");
  
  lcd.setCursor(12,1); 
  lcd.print("zZz!");
  delay(1200);
  lcd.clear();

  lcd.setCursor(2,0); 
  lcd.print("RING!!!");
  delay(600);

  lcd.setCursor(8,1); 
  lcd.print("RING!!!");
  lcd.setCursor(2,0); 
  lcd.print("       ");
  delay(600);
  
}

void talking_boy (){
  byte head_0[8] = {0b00000, 0b00011, 0b00111, 0b01111, 0b01111, 0b11110, 0b11110, 0b11010};
  byte head_1[8] = {0b00000, 0b11000, 0b11110, 0b10110, 0b00001, 0b00001, 0b10101, 0b10101};
  byte head_2[8] = {0b11010, 0b11000, 0b11000, 0b01100, 0b01110, 0b00111, 0b00011, 0b00000};
  byte head_3[8] = {0b00001, 0b00001, 0b01001, 0b00010, 0b01010, 0b11110, 0b11100, 0b00000};
  byte head_4[8] = {0b00001, 0b00001, 0b00001, 0b00010, 0b01010, 0b11110, 0b11100, 0b00000};
  
  lcd.createChar(0, head_0);
  lcd.createChar(1, head_1);
  lcd.createChar(2, head_2);
  lcd.createChar(3, head_3);
  lcd.createChar(4, head_4);

  lcd.setCursor(1,0); 
  lcd.print(char(0));
  lcd.setCursor(2,0); 
  lcd.print(char(1));
  lcd.setCursor(1,1); 
  lcd.print(char(2));
  lcd.setCursor(2,1); 
  lcd.print(char(3));
  delay(350);
  lcd.setCursor(2,1); 
  lcd.print(char(4));
  delay(350);

}

void talking_girl (){
  byte head_0[8] = {0b00000, 0b00100, 0b01110, 0b01111, 0b01111, 0b11101, 0b11000, 0b10000};
  byte head_1[8] = {0b00000, 0b00100, 0b01110, 0b11110, 0b11111, 0b11111, 0b01111, 0b01111};
  byte head_2[8] = {0b10101, 0b10000, 0b10010, 0b01000, 0b00100, 0b00100, 0b00011, 0b00000};
  byte head_3[8] = {0b00111, 0b00111, 0b00111, 0b00110, 0b00100, 0b01000, 0b10000, 0b00000};
  byte head_4[8] = {0b10101, 0b10000, 0b10000, 0b01000, 0b00100, 0b00100, 0b00011, 0b00000};
  
  lcd.createChar(0, head_0);
  lcd.createChar(1, head_1);
  lcd.createChar(2, head_2);
  lcd.createChar(3, head_3);
  lcd.createChar(4, head_4);

  lcd.setCursor(13,0); 
  lcd.print(char(0));
  lcd.setCursor(14,0); 
  lcd.print(char(1));
  lcd.setCursor(13,1); 
  lcd.print(char(2));
  lcd.setCursor(14,1); 
  lcd.print(char(3));
  delay(200);
  lcd.setCursor(13,1); 
  lcd.print(char(4));
  delay(200);

}

//END INTRO ANIMATIONS

//MAPS CREATION AND HANDLING

void map_01(){
  byte hero[8] = {B00000,B01110,B01010,B00100,B01010,B00100,B01010};
  byte cactus[8] = {0b00000,0b10100,0b10100,0b01101,0b00110,0b00100,0b01110,0b01110};
  byte bed_01[8] = {0b00000, 0b00000, 0b00100, 0b00100, 0b00110, 0b00101, 0b00111, 0b00100};
  byte bed_02[8] = {0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b01111, 0b11111, 0b00001};
  byte war_drob[8] = {0b11111, 0b10001, 0b10001, 0b11111, 0b10001, 0b10011, 0b10001, 0b11111};
  byte desk[8] = {0b00000, 0b00000, 0b00000, 0b00000, 0b11111, 0b10001, 0b10001, 0b10001};
  byte arrow[8] = {0b00000, 0b00000, 0b00100, 0b00110, 0b11111, 0b00110, 0b00100, 0b00000};
  byte chair[8] = {0b00000, 0b00000, 0b00000, 0b00000, 0b00010, 0b00010, 0b01110, 0b01010};

  int right_low = 0;
  int right_high = 50;
  int left_low = 410;
  int left_high = 490;
  int down_low = 250;
  int down_high = 350;
  int up_low = 100;
  int up_high = 160;
  
  lcd.createChar(1, cactus);
  lcd.createChar(2, bed_01);
  lcd.createChar(3, bed_02);
  lcd.createChar(4, war_drob);
  lcd.createChar(5, desk);
  lcd.createChar(6, arrow);
  lcd.createChar(7, chair);
  lcd.createChar(0, hero);
  
  lcd.setCursor(13,0); 
  lcd.print(char(1));
  lcd.setCursor(0,0); 
  lcd.print(char(2));
  lcd.setCursor(1,0); 
  lcd.print(char(3));
  lcd.setCursor(9,0); 
  lcd.print(char(4));
  lcd.setCursor(10,0); 
  lcd.print(char(4));
  lcd.setCursor(6,1); 
  lcd.print(char(5));
  lcd.setCursor(7,1); 
  lcd.print(char(7));
  lcd.setCursor(15,1); 
  lcd.print(char(6));
  lcd.setCursor(3,0); 
  lcd.print(char(5));

  static int pos_x = 0;
  static int pos_y = 1;
  
  lcd.setCursor(pos_x,pos_y); 
  lcd.print(char(0));

  if (pos_x==15 and pos_y==1){
    lcd.clear();
    pos_x = 0;
    pos_y = 1;
    which_map=2;
  }
  
  int r = analogRead(A0);  

  if (r >= right_low and r <= right_high)
  { 
    if ((pos_x==5 and pos_y==1) or (pos_x==8 and pos_y==0) or (pos_x==12 and pos_y==0)  or (pos_x==2 and pos_y==0)){
      pos_x=pos_x;
    }
    else{
    pos_x = pos_x+1;
    if (pos_x>15){
        pos_x=15;
    }
    else {
      lcd.setCursor(pos_x-1,pos_y);
      lcd.print(" ");
      lcd.setCursor(pos_x,pos_y);
      delay(200);
    }
  }
  }

  if (r > left_low and r < left_high)
  { 
    if ((pos_x==2 and pos_y==0) or (pos_x==8 and pos_y==1) or (pos_x==11 and pos_y==0) or (pos_x==14 and pos_y==0) or (pos_x==4 and pos_y==0)){
      pos_x=pos_x;
    }
    else{
      pos_x = pos_x-1;
    if (pos_x<0){
      pos_x=0;
    }
    else{
      lcd.setCursor(pos_x+1,pos_y);
      lcd.print(" ");
      lcd.setCursor(pos_x,pos_y);
      delay(200);
     }
  }
  }

  if (r > down_low and r < down_high)
  {
    if (pos_x==6 or pos_x==7){
      pos_y=pos_y;
    }
    else{
    pos_y = pos_y+1;
    if (pos_y>1){
      pos_y=1;
   }
    else{
      lcd.setCursor(pos_x,pos_y-1);
      lcd.print(" ");
      lcd.setCursor(pos_x,pos_y);
      delay(200);
    }
    }
  }

  if (r > up_low and r < up_high)
  { 
    if (pos_x==0 or pos_x==1 or pos_x==9 or pos_x==10 or pos_x==13 or pos_x==3){
      pos_y=pos_y;
    }
    else{
    pos_y = pos_y-1;
    
    
    if (pos_y<0){
      pos_y=0;
    }
    else{
      lcd.setCursor(pos_x,pos_y+1);
      lcd.print(" ");
      lcd.setCursor(pos_x,pos_y);
      delay(200);
    }
  }
  }
  
}

void map_02(){
  byte hero[8] = {B00000,B01110,B01010,B00100,B01010,B00100,B01010};
  byte cooker[8] = {0b11111, 0b10101, 0b11111, 0b10101, 0b11111, 0b10001, 0b10001, 0b10001};
  byte sink[8] = {0b10001, 0b10001, 0b11111, 0b10001, 0b10001, 0b10011, 0b10001, 0b11111};
  byte chair_2[8] = {0b00000, 0b00000, 0b00000, 0b00000, 0b01000, 0b01000, 0b01110, 0b01010};
  byte girl[8] = {0b10001, 0b01110, 0b01010, 0b00100, 0b01110, 0b00100, 0b01110, 0b00000};
  byte desk[8] = {0b00000, 0b00000, 0b00000, 0b00000, 0b11111, 0b10001, 0b10001, 0b10001};
  byte arrow[8] = {0b00000, 0b00000, 0b00000, 0b00100, 0b00100, 0b11111, 0b01110, 0b00100};
  byte chair[8] = {0b00000, 0b00000, 0b00000, 0b00000, 0b00010, 0b00010, 0b01110, 0b01010};
  
  int right_low = 0;
  int right_high = 50;
  int left_low = 410;
  int left_high = 490;
  int down_low = 250;
  int down_high = 350;
  int up_low = 100;
  int up_high = 160;
  
  lcd.createChar(1, cooker);
  lcd.createChar(2, sink);
  lcd.createChar(3, chair);
  lcd.createChar(4, chair_2);
  lcd.createChar(5, desk);
  lcd.createChar(6, arrow);
  lcd.createChar(7, girl);
  lcd.createChar(0, hero);
  
  lcd.setCursor(15,0); 
  lcd.print(char(1));
  lcd.setCursor(15,1); 
  lcd.print(char(2));
  lcd.setCursor(5,1); 
  lcd.print(char(3));
  lcd.setCursor(3,1); 
  lcd.print(char(4));
  lcd.setCursor(4,1); 
  lcd.print(char(5));
  lcd.setCursor(10,1); 
  lcd.print(char(6));
  lcd.setCursor(14,1); 
  lcd.print(char(7));
  lcd.setCursor(0,0); 
  lcd.print("HH");

  static int pos_x = 0;
  static int pos_y = 1;
  
  lcd.setCursor(pos_x,pos_y); 
  lcd.print(char(0));

  if (pos_x==10 and pos_y==1){
    int g_move;
    lcd.setCursor(14,0);
    lcd.print("!");
    delay(200);
    lcd.setCursor(14,0);
    lcd.print(" ");
    delay(200);
    lcd.setCursor(14,0);
    lcd.print("!");
    delay(200);
    lcd.setCursor(14,0);
    lcd.print(" ");
    delay(400);
    for (g_move=1;g_move<4;g_move++){
      lcd.setCursor(14-g_move+1,1);
      lcd.print(" ");
      lcd.setCursor(14 - g_move,1); 
      lcd.print(char(7));
      delay(200);
    }
    lcd.setCursor(10,0);
    lcd.print("<3");
    delay(500);
    lcd.setCursor(10,0);
    lcd.print("  ");
    delay(200);
    lcd.clear();
    int g_talk;
    int stars;
    for (g_talk=0;g_talk<4;g_talk++){
      talking_girl();
      lcd.setCursor(1,0);
      lcd.print("HELLO");
      lcd.setCursor(1,1);
      lcd.print("DARLING!");
      delay(200);
    }
    lcd.clear();
    for (g_talk=0;g_talk<4;g_talk++){
      talking_boy();
      lcd.setCursor(5,0);
      lcd.print("OH. HELLO!");
      delay(200);
    }
    lcd.clear();
    for (g_talk=0;g_talk<4;g_talk++){
      talking_girl();
      lcd.setCursor(1,0);
      lcd.print("I'M SHORT");
      lcd.setCursor(1,1);
      lcd.print("ON MILK");
      delay(200);
    }
   lcd.clear();
   for (g_talk=0;g_talk<4;g_talk++){
      talking_girl();
      lcd.setCursor(1,0);
      lcd.print("COULD YOU");
      lcd.setCursor(1,1);
      lcd.print("BUY IT?");
      delay(200);
    }
    lcd.clear();
    for (g_talk=0;g_talk<4;g_talk++){
      talking_boy();
      lcd.setCursor(5,0);
      lcd.print("NO PROBLEM");
      delay(200);
    }
   lcd.clear();
   for (g_talk=0;g_talk<4;g_talk++){
      talking_girl();
      lcd.setCursor(1,0);
      lcd.print("<3 <3");
      delay(200);
    }
  lcd.clear();
  lcd.setCursor(5,0);
  lcd.print("QUEST");
  lcd.setCursor(3,1);
  lcd.print("ACCEPTED!"); 
  for (stars=0;stars<7;stars++){
    lcd.setCursor(0,0);
    lcd.print("*");
    lcd.setCursor(1,0);
    lcd.print(" ");
    lcd.setCursor(2,0);
    lcd.print("*");
    lcd.setCursor(3,0);
    lcd.print(" ");
    lcd.setCursor(4,0);
    lcd.print("*");
    lcd.setCursor(10,0);
    lcd.print("*");
    lcd.setCursor(11,0);
    lcd.print(" ");
    lcd.setCursor(12,0);
    lcd.print("*");
    lcd.setCursor(13,0);
    lcd.print(" ");
    lcd.setCursor(14,0);
    lcd.print("*");
    lcd.setCursor(15,0);
    lcd.print(" ");
    lcd.setCursor(0,1);
    lcd.print(" ");
    lcd.setCursor(1,1);
    lcd.print("*");
    lcd.setCursor(2,1);
    lcd.print(" ");
    lcd.setCursor(12,1);
    lcd.print(" ");
    lcd.setCursor(13,1);
    lcd.print("*");
    lcd.setCursor(14,1);
    lcd.print(" ");
    lcd.setCursor(15,1);
    lcd.print("*");
    delay(200);
    lcd.setCursor(0,0);
    lcd.print(" ");
    lcd.setCursor(1,0);
    lcd.print("*");
    lcd.setCursor(2,0);
    lcd.print(" ");
    lcd.setCursor(3,0);
    lcd.print("*");
    lcd.setCursor(4,0);
    lcd.print(" ");
    lcd.setCursor(10,0);
    lcd.print(" ");
    lcd.setCursor(11,0);
    lcd.print("*");
    lcd.setCursor(12,0);
    lcd.print(" ");
    lcd.setCursor(13,0);
    lcd.print("*");
    lcd.setCursor(14,0);
    lcd.print(" ");
    lcd.setCursor(15,0);
    lcd.print("*");
    lcd.setCursor(0,1);
    lcd.print("*");
    lcd.setCursor(1,1);
    lcd.print(" ");
    lcd.setCursor(2,1);
    lcd.print("*");
    lcd.setCursor(12,1);
    lcd.print("*");
    lcd.setCursor(13,1);
    lcd.print(" ");
    lcd.setCursor(14,1);
    lcd.print("*");
    lcd.setCursor(15,1);
    lcd.print(" ");
    delay(150);
    
  }
    lcd.clear();
    pos_x = 0;
    pos_y = 1;
    which_map=3;
  }
  int r = analogRead(A0);  
  if (r >= right_low and r <= right_high)
  { 
    if ((pos_x==2 and pos_y==1) or (pos_x==14 and pos_y==0) or (pos_x==13 and pos_y==1)){
      pos_x=pos_x;
    }
    else{
    pos_x = pos_x+1;
    if (pos_x>15){
        pos_x=15;
    }
    else {
      lcd.setCursor(pos_x-1,pos_y);
      lcd.print(" ");
      lcd.setCursor(pos_x,pos_y);
      delay(200);
    }
  }
  }

  if (r > left_low and r < left_high)
  { 
    if ((pos_x==6 and pos_y==1) or (pos_x==2 and pos_y==0)){
      pos_x=pos_x;
    }
    else{
    pos_x = pos_x-1;
    if (pos_x<0){
      pos_x=0;
    }
    else{
      lcd.setCursor(pos_x+1,pos_y);
      lcd.print(" ");
      lcd.setCursor(pos_x,pos_y);
      delay(200);
     }
  }
  }

  if (r > down_low and r < down_high)
  {
    if (pos_x==3 or pos_x==4 or pos_x==5 or pos_x==14){
      pos_y=pos_y;
    }
    else{
    pos_y = pos_y+1;
    if (pos_y>1){
      pos_y=1;
   }
    else{
      lcd.setCursor(pos_x,pos_y-1);
      lcd.print(" ");
      lcd.setCursor(pos_x,pos_y);
      delay(200);
    }
    }
  }

  if (r > up_low and r < up_high)
  { 
    if (pos_x==0 or pos_x==1){
      pos_y=pos_y;
    }
    else{
    pos_y = pos_y-1;
    if (pos_y<0){
      pos_y=0;
    }
    else{
      lcd.setCursor(pos_x,pos_y+1);
      lcd.print(" ");
      lcd.setCursor(pos_x,pos_y);
      delay(200);
    }
  } 
}
}

void map_03(){
  byte hero[8] = {B00000,B01110,B01010,B00100,B01010,B00100,B01010};
  byte house_01[8] = {0b00100, 0b00100, 0b00100, 0b00100, 0b00100, 0b00100, 0b00100, 0b00100};
  byte house_02[8] = {0b01000, 0b00100, 0b00010, 0b00001, 0b11111, 0b00100, 0b00100, 0b00100};
  byte house_03[8] = {0b00000, 0b00000, 0b00000, 0b00000, 0b11111, 0b00000, 0b01110, 0b01010};
  byte house_04[8] = {0b01010, 0b01010, 0b01110, 0b00000, 0b01110, 0b01010, 0b01010, 0b01110};
  byte tree[8] = {0b00100,0b01110,0b11111,0b01110,0b11111,0b01110,0b11111,0b00100};
  byte arrow[8] = {0b00000, 0b00000, 0b00000, 0b00100, 0b00100, 0b11111, 0b01110, 0b00100};
  byte rock[8] = {0b00000, 0b00000, 0b00000, 0b00000, 0b00110, 0b01111, 0b11111, 0b00000};
  
  int right_low = 0;
  int right_high = 50;
  int left_low = 410;
  int left_high = 490;
  int down_low = 250;
  int down_high = 350;
  int up_low = 100;
  int up_high = 160;
  
  lcd.createChar(1, rock);
  lcd.createChar(2, house_01);
  lcd.createChar(3, house_02);
  lcd.createChar(4, house_03);
  lcd.createChar(5, house_04);
  lcd.createChar(6, arrow);
  lcd.createChar(7, tree);
  lcd.createChar(0, hero);
  
  lcd.setCursor(1,1); 
  lcd.print(char(2));
  lcd.setCursor(1,0); 
  lcd.print(char(3));
  lcd.setCursor(0,0); 
  lcd.print(char(4));
  lcd.setCursor(0,1); 
  lcd.print(char(5));
  lcd.setCursor(8,1); 
  lcd.print(char(6));
  lcd.setCursor(10,0); 
  lcd.print(char(7));
  lcd.setCursor(11,1); 
  lcd.print(char(7));
  lcd.setCursor(13,1); 
  lcd.print(char(7));
  lcd.setCursor(14,1); 
  lcd.print(char(7));
  lcd.setCursor(15,0); 
  lcd.print(char(7));
  lcd.setCursor(12,0); 
  lcd.print(char(1));
  lcd.setCursor(5,1); 
  lcd.print(char(1));
  lcd.setCursor(3,1); 
  lcd.print(".");
  lcd.setCursor(6,0); 
  lcd.print(".");
  lcd.setCursor(10,1); 
  lcd.print(".");
  lcd.setCursor(13,0); 
  lcd.print(".");
  

  static int pos_x = 2;
  static int pos_y = 0;
  
  lcd.setCursor(pos_x,pos_y); 
  lcd.print(char(0));

  if (pos_x==8 and pos_y==1){
    lcd.clear();
    pos_y = 0;
    pos_x = 2;
    
    which_map=4;
  }
  int r = analogRead(A0);  
  if (r >= right_low and r <= right_high)
  { 
    if ((pos_x==4 and pos_y==1) or (pos_x==9 and pos_y==0) or (pos_x==10 and pos_y==1)){
      pos_x=pos_x;
    }
    else{
    pos_x = pos_x+1;
    if (pos_x>15){
        pos_x=15;
    }
    else {
      lcd.setCursor(pos_x-1,pos_y);
      lcd.print(" ");
      lcd.setCursor(pos_x,pos_y);
      delay(200);
    }
  }
  }

  if (r > left_low and r < left_high)
  { 
    if ((pos_x==2 and pos_y==0) or (pos_x==2 and pos_y==1) or (pos_x==6 and pos_y==1)){
      pos_x=pos_x;
    }
    else{
    pos_x = pos_x-1;
    if (pos_x<0){
      pos_x=0;
    }
    else{
      lcd.setCursor(pos_x+1,pos_y);
      lcd.print(" ");
      lcd.setCursor(pos_x,pos_y);
      delay(200);
     }
  }
  }

  if (r > down_low and r < down_high)
  {
    if (pos_x==5 or pos_x==0){
      pos_y=pos_y;
    }
    else{
    pos_y = pos_y+1;
    if (pos_y>1){
      pos_y=1;
   }
    else{
      lcd.setCursor(pos_x,pos_y-1);
      lcd.print(" ");
      lcd.setCursor(pos_x,pos_y);
      delay(200);
    }
    }
  }

  if (r > up_low and r < up_high)
  { 
    if (pos_x==10 or pos_x==1){
      pos_y=pos_y;
    }
    else{
    pos_y = pos_y-1;
    
    
    if (pos_y<0){
      pos_y=0;
    }
    else{
      lcd.setCursor(pos_x,pos_y+1);
      lcd.print(" ");
      lcd.setCursor(pos_x,pos_y);
      delay(200);
    }
  }
  }
}

void map_04(){
  byte hero[8] = {B01110,B01010,B00100,B01010,B00100,B01010,B11111,B00000};
  byte car_1[8] = {0b00000, 0b00011, 0b00100, 0b11111, 0b10000, 0b11111, 0b00110, 0b00000};
  byte car_11[8] = {0b00000, 0b10000, 0b01000, 0b11110, 0b00001, 0b11111, 0b00110, 0b00000};
  byte car_2[8] = {0b00000, 0b00000, 0b11111, 0b10000, 0b10000, 0b11111, 0b01110, 0b00000};
  byte car_21[8] = {0b00000, 0b00000, 0b11100, 0b10010, 0b10011, 0b11111, 0b01100, 0b00000};
  byte car_3[8] = {0b00000, 0b00000, 0b01111, 0b10000, 0b11111, 0b11111, 0b01100, 0b00000};
  byte arrow[8] = {0b00100, 0b00100, 0b00100, 0b11111, 0b01110, 0b00100, 0b11111,0b00000};
  byte car_31[8] = {0b00000, 0b00000, 0b11000, 0b00100, 0b11111, 0b11111, 0b01100, 0b00000};
  
  int right_low = 0;
  int right_high = 50;
  int left_low = 410;
  int left_high = 490;
  int down_low = 250;
  int down_high = 350;
  int up_low = 100;
  int up_high = 160;
  
  lcd.createChar(1, car_1);
  lcd.createChar(2, car_11);
  lcd.createChar(3, car_2);
  lcd.createChar(4, car_21);
  lcd.createChar(5, car_3);
  lcd.createChar(6, arrow);
  lcd.createChar(7, car_31);
  lcd.createChar(0, hero);
  
  lcd.setCursor(1,1); 
  lcd.print(char(3));
  lcd.setCursor(2,1); 
  lcd.print(char(4));
  lcd.setCursor(8,1); 
  lcd.print(char(5));
  lcd.setCursor(9,1); 
  lcd.print(char(7));
  lcd.setCursor(12,1); 
  lcd.print(char(1));
  lcd.setCursor(13,1); 
  lcd.print(char(2));
  lcd.setCursor(12,0); 
  lcd.print(char(6));
  lcd.setCursor(0,0); 
  lcd.print("____________");
  lcd.setCursor(13,0); 
  lcd.print("___");

  static int pos_x = 0;
  static int pos_y = 0;
  
  lcd.setCursor(pos_x,pos_y); 
  lcd.print(char(0));

  if (pos_x==12 and pos_y==0){
    delay(500);
    lcd.setCursor(12,0); 
    lcd.print("_");
    delay(500);
    lcd.setCursor(12,1); 
    lcd.print(" ");
    lcd.setCursor(14,1); 
    lcd.print(char(2));
    lcd.setCursor(13,1); 
    lcd.print(char(1));
    delay(200);
    lcd.setCursor(13,1); 
    lcd.print(" ");
    lcd.setCursor(15,1); 
    lcd.print(char(2));
    lcd.setCursor(14,1); 
    lcd.print(char(1));
    delay(200);
    lcd.setCursor(14,1); 
    lcd.print(" ");
    lcd.setCursor(15,1); 
    lcd.print(char(1));
    delay(200);
    lcd.setCursor(15,1); 
    lcd.print(" ");
    delay(500);
    lcd.clear();
    lcd.setCursor(7,0); 
    lcd.print("3...");
    delay(500);
    lcd.clear();
    lcd.setCursor(7,0); 
    lcd.print("2...");
    delay(500);
    lcd.clear();
    lcd.setCursor(7,0); 
    lcd.print("1...");
    delay(500);
    lcd.clear();
    lcd.setCursor(7,0); 
    lcd.print("GO!");
    delay(500);
    lcd.clear();
    pos_x = 0;
    pos_y = 0;
    which_map=5;
  }
  int r = analogRead(A0);  
  if (r >= right_low and r <= right_high)
  { 

    pos_x = pos_x+1;
    if (pos_x>15){
        pos_x=15;
    }
    else {
      lcd.setCursor(pos_x-1,pos_y);
      lcd.print(" ");
      lcd.setCursor(pos_x,pos_y);
      delay(200);
    }
  }

  if (r > left_low and r < left_high)
  { 

    pos_x = pos_x-1;
    if (pos_x<0){
      pos_x=0;
    }
    else{
      lcd.setCursor(pos_x+1,pos_y);
      lcd.print(" ");
      lcd.setCursor(pos_x,pos_y);
      delay(200);
     }
  }

  if (r > down_low and r < down_high)
  {
    pos_y = pos_y+1;
    if (pos_y>0){
      pos_y=0;
   }
    else{
      lcd.setCursor(pos_x,pos_y-1);
      lcd.print(" ");
      lcd.setCursor(pos_x,pos_y);
      delay(200);
    }
  }

  if (r > up_low and r < up_high)
  { 
    pos_y = pos_y-1;
    
    if (pos_y<0){
      pos_y=0;
    }
    else{
      lcd.setCursor(pos_x,pos_y+1);
      lcd.print(" ");
      lcd.setCursor(pos_x,pos_y);
      delay(200);
    }
  }
}

//CARS MINI GAME

void map_05(){
  byte hero[8] = {0b00000,0b00000,0b00000,0b00000,0b00000,0b01110,0b11111,0b01010};
  byte car_1[8] = {0b00000,0b00000,0b00000,0b00000,0b00000,0b01111,0b11111,0b01010};
  
  int down_low = 250;
  int down_high = 350;
  int up_low = 100;
  int up_high = 160;
  
  static int posy=1;
  static int car_counter=25;
  int button = analogRead(A0);
  int i = 0;
  
  lcd.createChar(0, car_1);
  lcd.createChar(1, hero);
   
  lcd.clear(); 

  lcd.setCursor(14,0);
  lcd.print(car_counter);
 
  lcd.setCursor(1,posy);
  lcd.print(char(1));
                
  for(i=0; i<25; i++) {
    cars_x[i] = cars_x[i] - 1;
    if(cars_x[i] >= 0 and cars_x[i] <= 12) { 
      lcd.setCursor(cars_x[i],cars_y[i]);
      lcd.print(char(0));
      if (cars_x[i] == 0){
        lcd.setCursor(14,0);
        lcd.print(car_counter);
        car_counter--;
      }
    }
   if (cars_x[i]==1 and cars_y[i] == posy){
    fail_menu = 1;
    lcd.clear();
   }
   if (car_counter <= 0) {
    lcd.clear();
    which_map = 6;
   }
   
   if (button > down_low and button < down_high)
   {
    posy = posy+1;
    if (posy>1){
      posy=1;
   }
    else{
      lcd.setCursor(1,posy-1);
      lcd.print(" ");
      lcd.setCursor(1,posy);
      delay(100);
    }
  }
  if (button > up_low and button < up_high)
  { 
    posy = posy-1;
    if (posy<0){
      posy=0;
    }
    else{
      lcd.setCursor(1,posy+1);
      lcd.print(" ");
      lcd.setCursor(1,posy);
      delay(100);
    }
  } 
  } 
  delay(200);
}

//GOAL REACHED ANIMATION

void map_06(){
  byte hero[8] = {0b00000,0b00000,0b00000,0b00000,0b00000,0b01110,0b11111,0b01010};
  byte shop_01[8] = {0b11111, 0b10000, 0b10000, 0b11111, 0b10010, 0b10010, 0b10010, 0b10010};
  byte shop_02[8] = {0b10010, 0b10010, 0b10010, 0b10010, 0b10010, 0b10010, 0b10010, 0b11111};
  byte shop_03[8] = {0b11111, 0b00000, 0b00000, 0b11111, 0b00000, 0b11111, 0b10101, 0b10101};
  byte shop_04[8] = {0b10101, 0b10101, 0b10101, 0b10101, 0b10101, 0b10101, 0b10101, 0b11111};
  byte shop_05[8] = {0b11111, 0b00001, 0b00001, 0b11111, 0b01001, 0b01001, 0b01001, 0b01001};
  byte shop_06[8] = {0b01001, 0b01001, 0b01001, 0b01001, 0b01001, 0b01001, 0b01001, 0b11111};
  byte car_06[8] = {0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00111, 0b11111, 0b01010};

  int i;
  
  lcd.createChar(1, shop_01);
  lcd.createChar(2, shop_02);
  lcd.createChar(3, shop_03);
  lcd.createChar(4, shop_04);
  lcd.createChar(5, shop_05);
  lcd.createChar(6, shop_06);
  lcd.createChar(7, car_06);
  lcd.createChar(0, hero);

  lcd.setCursor(1,1); 
  lcd.print(char(0));
    
    for (i=0;i<=16;i++){

      lcd.setCursor(16-i,0); 
      lcd.print(char(7));
      lcd.setCursor(17-i,0); 
      lcd.print(" ");
      lcd.setCursor(17-i,0); 
      lcd.print(char(7));
      lcd.setCursor(18-i,0); 
      lcd.print(" ");
      lcd.setCursor(18-i,0); 
      lcd.print(char(1));
      lcd.setCursor(19-i,0); 
      lcd.print(" ");
      lcd.setCursor(18-i,1); 
      lcd.print(char(2));
      lcd.setCursor(19-i,1); 
      lcd.print(" ");
      lcd.setCursor(19-i,0); 
      lcd.print(char(3));
      lcd.setCursor(20-i,0); 
      lcd.print(" ");
      lcd.setCursor(19-i,1); 
      lcd.print(char(4));
      lcd.setCursor(20-i,1); 
      lcd.print(" ");
      lcd.setCursor(20-i,0); 
      lcd.print(char(5));
      lcd.setCursor(21-i,0); 
      lcd.print(" ");
      lcd.setCursor(20-i,1); 
      lcd.print(char(6));
      lcd.setCursor(21-i,1); 
      lcd.print(" ");
      
      lcd.setCursor(21-i,0); 
      lcd.print(char(7));
      lcd.setCursor(22-i,0); 
      lcd.print(" ");
      lcd.setCursor(22-i,1); 
      lcd.print(char(7));
      lcd.setCursor(23-i,1); 
      lcd.print(" ");

      lcd.setCursor(23-i,0); 
      lcd.print(char(7));
      lcd.setCursor(24-i,0); 
      lcd.print(" ");

      lcd.setCursor(24-i,0); 
      lcd.print(char(7));
      lcd.setCursor(25-i,0); 
      lcd.print(" ");
      delay(500);
    }
    delay(500);
    lcd.clear();
    which_map=7;
}    
void map_07(){
  byte hero[8] = {B00000,B01110,B01010,B00100,B01010,B00100,B01010};
  byte shelf_01[8] = {0b11111, 0b10001, 0b11111, 0b10001, 0b11111, 0b10001, 0b11111, 0b10001};
  byte shelf_02[8] = {0b11111, 0b10000, 0b10101, 0b10101, 0b11111, 0b10000, 0b11111, 0b10000};
  byte shelf_03[8] = {0b11111, 0b00001, 0b00001, 0b11001, 0b11111, 0b00001, 0b11111, 0b00001};
  byte shelf_04[8] = {0b00111, 0b00101, 0b00101, 0b00111, 0b00101, 0b00101, 0b11111, 0b10001};
  
  int right_low = 0;
  int right_high = 50;
  int left_low = 410;
  int left_high = 490;
  int down_low = 250;
  int down_high = 350;
  int up_low = 100;
  int up_high = 160;
  
  lcd.createChar(1, shelf_01);
  lcd.createChar(2, shelf_02);
  lcd.createChar(3, shelf_03);
  lcd.createChar(4, shelf_04);
  lcd.createChar(0, hero);
  
  lcd.setCursor(2,0); 
  lcd.print(char(1));
  lcd.setCursor(4,0); 
  lcd.print(char(1));
  lcd.setCursor(6,0); 
  lcd.print(char(1));
  lcd.setCursor(8,1); 
  lcd.print(char(4));
  lcd.setCursor(9,1); 
  lcd.print(char(4));
  lcd.setCursor(12,0); 
  lcd.setCursor(13,1); 
  lcd.print(char(2));
  lcd.setCursor(14,1); 
  lcd.print(char(3));
  lcd.setCursor(11,0); 
  lcd.print("DAIRY");
 
  static int pos_x = 0;
  static int pos_y = 0;
  
  lcd.setCursor(pos_x,pos_y); 
  lcd.print(char(0));

  if (pos_x==12 and pos_y==1){
    lcd.setCursor(12, 1);
    lcd.print(" ");
    delay(300);
    lcd.setCursor(12, 1);
    lcd.print(char(0));
    delay(300);
    lcd.setCursor(12, 1);
    lcd.print(" ");
    delay(300);
    lcd.setCursor(12, 1);
    lcd.print(char(0));
    delay(300);
    lcd.clear();
    pos_x = 0;
    pos_y = 0;
    which_map=8;
  }
  
  int r = analogRead(A0);  
  if (r >= right_low and r <= right_high)
  { 
    if ((pos_x==1 and pos_y==0) or (pos_x==3 and pos_y==0) or (pos_x==5 and pos_y==0) or (pos_x==7 and pos_y==1) or (pos_x==10 and pos_y==0)){
      pos_x=pos_x;
    }
    else{
    pos_x = pos_x+1;
    if (pos_x>15){
        pos_x=15;
    }
    else {
      lcd.setCursor(pos_x-1,pos_y);
      lcd.print(" ");
      lcd.setCursor(pos_x,pos_y);
      delay(200);
    }
  }
  }

  if (r > left_low and r < left_high)
  { 
    if ((pos_x==3 and pos_y==0) or (pos_x==5 and pos_y==0) or (pos_x==7 and pos_y==0) or (pos_x==10 and pos_y==1)){
      pos_x=pos_x;
    }
    else{
    pos_x = pos_x-1;
    if (pos_x<0){
      pos_x=0;
    }
    else{
      lcd.setCursor(pos_x+1,pos_y);
      lcd.print(" ");
      lcd.setCursor(pos_x,pos_y);
      delay(200);
     }
  }
  }

  if (r > down_low and r < down_high)
  {
    if (pos_x==8 or pos_x==9){
      pos_y=pos_y;
    }
    else{
    pos_y = pos_y+1;
    if (pos_y>1){
      pos_y=1;
   }
    else{
      lcd.setCursor(pos_x,pos_y-1);
      lcd.print(" ");
      lcd.setCursor(pos_x,pos_y);
      delay(200);
    }
    }
  }

  if (r > up_low and r < up_high)
  { 
    if (pos_x==2 or pos_x==4  or pos_x==6){
      pos_y=pos_y;
    }
    else{
    pos_y = pos_y-1;
    
    
    if (pos_y<0){
      pos_y=0;
    }
    else{
      lcd.setCursor(pos_x,pos_y+1);
      lcd.print(" ");
      lcd.setCursor(pos_x,pos_y);
      delay(200);
    }
  }
  }
}

void map_08(){
  lcd.setCursor(0,0);
  lcd.print("AND THIS IS HOW");
  lcd.setCursor(0,1);
  lcd.print("OUR HERO BOUGHT");
  delay(3000);
  lcd.clear();
  lcd.setCursor(6,0);
  lcd.print("MILK");
  delay(3000);
  lcd.setCursor(4,0);
  lcd.print("THE  END");
  delay(2000);
  which_map = 9;
  lcd.clear();
}

//END MAPS CREATION AND HANDLING

//CREDITS ANIMATION

void map_09(){

  int a_read = analogRead(A0);
    
  lcd.setCursor(0,0);
  lcd.print("Credits: Lukasz Startek, Karolina Wojak");
  delay(400);
  lcd.scrollDisplayLeft();
  if (a_read > 650 and a_read < 740) {
    lcd.clear();
    if_menu = 1;
    which_map = 0;
  }  
}

//END MAPS CREATION AND HANDLING

//END MENU

void menu_2() {

  byte circle_0[8] = {0b00000,0b00100,0b01010,0b10001,0b10001,0b01010,0b00100,0b00000};
  byte circle_1[8] = {0b00000,0b00100,0b01110,0b11111,0b11111,0b01110,0b00100,0b00000};

  int a_read = analogRead(A0);
  static int sel;

  int a1_low = 100;
  int a1_high = 160;
  int a2_low = 250;
  int a2_high = 350;
  int a3_low = 650;
  int a3_high = 740;
  
  lcd.createChar(0, circle_0);
  lcd.createChar(1, circle_1);
  
  if (a_read > a1_low and a_read < a1_high)
  {
    sel = 0;
    delay(200);
  }

  if (a_read > a2_low and a_read < a2_high)
  {
    sel = 1;
    delay(200);
  }

  lcd.setCursor(3,0);
  lcd.print("TRY  AGAIN");
  lcd.setCursor(6,1);
  lcd.print("EXIT");

  
  if (sel == 0) {
    
    lcd.setCursor(2,0); 
    lcd.print(char(0));
    delay(100);
    lcd.setCursor(2,0);
    lcd.print(char(1));
    delay(100);
  
    lcd.setCursor(13,0);
    lcd.print(char(0));
    delay(100);
    lcd.setCursor(13,0);
    lcd.print(char(1));
    delay(100);

    lcd.setCursor(5,1); 
    lcd.print(" ");
  
    lcd.setCursor(10,1);
    lcd.print(" ");

    if (a_read > a3_low and a_read < a3_high) {
      lcd.clear();
      fail_menu = 0;
    }
  }
  else if (sel == 1) {
  
    lcd.setCursor(5,1); 
    lcd.print(char(0));
    delay(100);
    lcd.setCursor(5,1);
    lcd.print(char(1));
    delay(100);
  
    lcd.setCursor(10,1);
    lcd.print(char(0));
    delay(100);
    lcd.setCursor(10,1);
    lcd.print(char(1));
    delay(100);
  
    lcd.setCursor(2,0); 
    lcd.print(" ");
  
    lcd.setCursor(13,0);
    lcd.print(" ");

    if (a_read > a3_low and a_read < a3_high) {
      lcd.clear();
      if_exit = 1;
      fail_menu = 0;
      which_map = 0;
    }
  }
}
