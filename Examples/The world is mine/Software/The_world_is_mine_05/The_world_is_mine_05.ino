/*
  The World Is Mine!
 
  Versions:

  - Ver. 05 date 02/03/2023 created by Sergio Ghirardelli (first release)

*/


#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#include "muMatrix8ptRegular.h"
#include "muHeavy8ptBold.h"
#include "functions_5.h"
#include "continents.h"
#include "cities.h"


#ifndef PSTR
 #define PSTR // Make Arduino Due happy
#endif

#define PIN 14
#define LED_BLACK    0


// MATRIX DECLARATION:
// Parameter 1 = width of NeoPixel matrix
// Parameter 2 = height of matrix
// Parameter 3 = pin number (most are valid)
// Parameter 4 = matrix layout flags, add together as needed:
//   NEO_MATRIX_TOP, NEO_MATRIX_BOTTOM, NEO_MATRIX_LEFT, NEO_MATRIX_RIGHT:
//     Position of the FIRST LED in the matrix; pick two, e.g.
//     NEO_MATRIX_TOP + NEO_MATRIX_LEFT for the top-left corner.
//   NEO_MATRIX_ROWS, NEO_MATRIX_COLUMNS: LEDs are arranged in horizontal
//     rows or in vertical columns, respectively; pick one or the other.
//   NEO_MATRIX_PROGRESSIVE, NEO_MATRIX_ZIGZAG: all rows/columns proceed
//     in the same order, or alternate lines reverse direction; pick one.
//   See example below for these values in action.
// Parameter 5 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_GRBW    Pixels are wired for GRBW bitstream (RGB+W NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)


// Example for NeoPixel Shield.  In this application we'd like to use it
// as a 5x8 tall matrix, with the USB port positioned at the top of the
// Arduino.  When held that way, the first pixel is at the top right, and
// lines are arranged in columns, progressive order.  The shield uses
// 800 KHz (v2) pixels that expect GRB color data.
/*Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(32, 16 , PIN,
  NEO_MATRIX_TOP     + NEO_MATRIX_LEFT +
  NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
  NEO_GRB            + NEO_KHZ800); */

 Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(8, 8, 4, 2, PIN, 
  NEO_MATRIX_TOP     + NEO_MATRIX_LEFT +
  NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG +
  NEO_TILE_TOP + NEO_TILE_LEFT +
  NEO_TILE_ROWS + NEO_TILE_PROGRESSIVE,
  NEO_GRB            + NEO_KHZ800);
  
const uint16_t colors[] = {
  matrix.Color(0, 0, 0),      // 0 = Black
  matrix.Color(255, 0, 0),    // 1 = Red
  matrix.Color(0, 255, 0),    // 2 = Lime
  matrix.Color(0, 0, 255),    // 3 = Blue
  matrix.Color(255, 165, 0),  // 4 = Orange
  matrix.Color(255, 255, 0),  // 5 = Yellow
  matrix.Color(128, 0, 0),    // 6 = Maroon
  matrix.Color(128, 0, 128),  // 7 = Purple
  matrix.Color(255, 0, 255),  // 8 = Fuchsia
  matrix.Color(0, 128, 0),    // 9 = Green
  matrix.Color(128, 128, 0),  // 10 = Olive
  matrix.Color(0, 0, 128),    // 11 = Navy
  matrix.Color(0, 128, 128),  // 12 = Teal
  matrix.Color(0, 255, 255),  // 13 = Aqua
  matrix.Color(128, 128, 128),// 14 = Gray
  matrix.Color(192, 192, 192),// 15 = Silver
  matrix.Color(255, 255, 255),  // 16 = White
  matrix.Color(50, 50, 50),  // 17 = Dark grey
  };

//oscillator 0 initialization
unsigned long t0;
unsigned long speed0;


//oscillator 1 scrolling text
unsigned long t1;
unsigned long speed1;
bool trigger1;
int color1;
bool complete1;
String text1;
int j;

//oscillator 2 progressive pixels animation
unsigned long t2;
unsigned long speed2;
bool trigger2;
int color2;
bool complete2;

//oscillator 3 pixels disintegration animation
unsigned long t3;
unsigned long speed3;
bool trigger3;
int color3;
bool complete3;
bool pixels_status3 [32][8];
int x3;
int y3;
int count3;

//oscillator 4 random pixels animation
unsigned long t4;
unsigned long speed4;
bool trigger4;
int color4;
bool complete4;
bool pixels_status4 [32][8];
int x4;
int y4;
int count4;

//oscillator 5 peace text animation
unsigned long t5;
unsigned long speed5;
bool trigger5;
int color5;
int animation5;
int an_step;

//oscillator 6 flashlight animation
unsigned long t6;
unsigned long speed6;
bool osc6;
bool osc6_p;
bool osc6_p_mem;
bool osc6_n;
bool osc6_n_mem;

//oscillator 8 scrolling text
unsigned long t8;
unsigned long speed8;
bool trigger8;
int color8;
bool complete8;
String text8;
int j8;

//oscillator 9 scrolling text
unsigned long t9;
unsigned long speed9;
bool trigger9;
int color9;
bool complete9;
String text9;
int j9;
int x9;
int y9;
int a9;
int b9;
int c9;
int c9_old;
bool pixels_status9 [32][8];
int count9;
bool stop9;
bool unlock;

//timer1: for sequence
bool time1_q;
unsigned long time1_elapsed;
unsigned long time1_count;
int step7;

//buttons variables
bool but_u;
bool but_da;
bool u;
bool da;
bool both;
bool both_p;
bool u_n;
bool u_mem;
bool da_n;
bool da_mem;
bool dap_mem;
bool da_p;
bool both_mem;
unsigned long u_elapsed;
unsigned long u_count;
unsigned long da_elapsed;
unsigned long da_count;
unsigned long both_elapsed;
unsigned long both_count;




//program variables
int prog; //program number
int prog_tot;
bool prog1;
bool prog1_p;
bool prog1_mem;
bool prog2;
bool prog2_p;
bool prog2_mem;
bool prog3;
bool prog3_p;
bool prog3_mem;
bool prog4;
bool prog4_p;
bool prog4_mem;

bool initialize;


void setup() {
  
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setTextSize(1);
  
 // matrix.setFont(&muHeavy8ptBold);
  matrix.setBrightness(100);

  
// Init Serial Monitor
  Serial.begin(115200);
  Serial.println ("ok pronto");
  
  pinMode(13, INPUT_PULLUP); // Button 1
  pinMode(12, INPUT_PULLUP); // Button 2
  
  prog = 1;
  prog_tot = 4;
  prog1_mem = false;
  prog2_mem = false;
  prog3_mem = false;
  prog4_mem = false;
  an_step = 0;
    
  trigger1 = false;
  trigger2 = false;
  trigger3 = false;
  trigger4 = false;
  trigger5 = false;

  initialize = false;
  speed0 = 150;
  c9 = 2;
  c9_old = 0;
  stop9 = false;
   
}



void loop() {

    if (!initialize) {
        if (millis() - t0 >= speed0) 
                  {
                    prog++;
                    if (prog>prog_tot) {
                      prog = 1;
                      initialize = true;
                      }
                    t0 += speed0;
                  }
    
    }
    //oscillator 0 ("flashlight animation)
    
    else {
        
        but_u = !digitalRead(13); //digital channels reading
        but_da = !digitalRead(12);
        u = TON(but_u, 50, u_elapsed, u_count); //buttons must be pressed for at least 50 msec
        da = TON(but_da, 50, da_elapsed, da_count);
        both = TON ((u and da), 3000, both_elapsed, both_count);//both buttons are pressed for 3 seconds
        both_p = PosTrig(both, both_mem); //positive edge of both variable
        u_n = NegTrig(u, u_mem); //negative edge of u: when SW1 button is released
        da_n = NegTrig (da, da_mem); //negative edge of da: when SW2 button is released
        da_p = PosTrig (da, dap_mem);
    }
  
    

    if (u_n) {
      prog++;
      if (prog>prog_tot) { prog = 1;}
      }
    prog1_p = PosTrig(prog1, prog1_mem);
    prog2_p = PosTrig(prog2, prog2_mem);
    prog3_p = PosTrig(prog3, prog3_mem);
    prog4_p = PosTrig(prog4, prog4_mem);


  
    
    //oscillator 1 (the world is mine scrolling)
    if (millis() - t1 >= speed1) 
                  {
                    trigger1 = true;
                    t1 += speed1;
                  }

    //oscillator 2 (progressing pixels)
    if (micros() - t2 >= speed2) 
                  {
                    trigger2 = true;
                    t2 += speed2;
                  }

    //oscillator 3 (disintegration pixels)
    if (millis() - t3 >= speed3) 
                  {
                    trigger3 = true;
                    t3 += speed3;
                  }

      //oscillator 4 (random pixels)
    if (millis() - t4 >= speed4) 
                  {
                    trigger4 = true;
                    t4 += speed4;
                  }

      //oscillator 5 ("Peace" text animation)
    if (millis() - t5 >= speed5) 
                  {
                    trigger5 = true;
                    t5 += speed5;
                  }

    //oscillator 6 ("flashlight animation)
    if (millis() - t6 >= speed6) 
                  {
                    osc6 = !osc6;
                    t6 += speed6;
                  }
    osc6_p = PosTrig(osc6, osc6_p_mem);
    osc6_n = NegTrig(osc6, osc6_n_mem);

    //oscillator 8 (the world is mine scrolling)
    if (millis() - t8 >= speed8) 
                  {
                    trigger8 = true;
                    t8 += speed8;
                  }

    //oscillator 9 (the world is mine scrolling)
    if (millis() - t9 >= speed9) 
                  {
                    trigger9 = true;
                    t9 += speed9;
                  }

                              
//----------------------------------------------------------------------------------------------------------------------------
//"The World is mine" animation program
    
    if (prog==1) { 
      
          prog1 = true;
          prog2 = false;
          prog3 = false;
          prog4 = false;

           
          if (prog1_p) {
              j = matrix.width();
              speed2 = 1000000;
              matrix.fillRect(0, 0, 32, 16, colors[0]);
              matrix.show(); 
              complete1 = false;
              complete2 = false;
              complete3 = false;
              color1 = 4;
              speed1 = 80;
              text1 = "THE WORLD IS MINE";
              color2 = 1;
              speed3 = 0;
              for (x3 = 0; x3 <= 31; x3++) {
                    for ( y3 = 0; y3 <= 7; y3++) {
                      pixels_status3 [x3][y3] = false;
                      }
                    }
            }
          else {
                  if (trigger1) {//scrolling text
                      int lung = text1.length();
                      matrix.fillRect(0, 8, 32, 16, colors[0]);
                      matrix.setTextColor(colors[color1]);
                      matrix.setCursor(j, 8);
                      matrix.print(text1);
                      j--;
                      if(j < (-lung*6)) {
                        complete1 = true;
                        j = matrix.width();
                        color1 = random(1, 16);
                        }
                     matrix.show();
                     trigger1=false;
                    }
                  
                 
                 if (!complete2) {
                      if (trigger2) {//progressive pixels animation
                          matrix.fillRect(0, 0, 32, 8, colors[color2]);                
                          matrix.show();   
                          if (color2==1) {color2 = 3; } 
                          else if (color2==3) {color2 = 2; }
                          else if (color2==2) {color2 = 8; }
                          else if (color2==8) {color2 = 5; }
                          else if (color2==5) {color2 = 13; }
                          else if (color2==13) {color2 = 4; }
                          else if (color2==4) {color2 = 16; }
                          else if (color2==16) {color2 = 1; }
                          speed2 = speed2 - (speed2 / 100 * 5);
                          if (speed2< 100)  {
                            complete2 = true;
                            speed2 = 1000000;
                            }        
                          trigger2=false;
                      }

                 }

                 else {
                      int a = random(0, 32);
                      int b = random(0, 8);
                      if  (!pixels_status3 [a][b]) {
                              if (trigger3) 
                                {
                                  matrix.drawPixel(a, b, colors[0]);
                                  pixels_status3 [a][b]=true;  
                                  matrix.show();
                                  count3++;
                                 }
                             
                          }
                          
                      if (count3>255) {
                                  count3=0;
                                  complete3 = true;
                                  complete2 = false;
                                  for (x3 = 0; x3 <= 31; x3++) {
                                        for ( y3 = 0; y3 <= 7; y3++) {
                                              pixels_status3 [x3][y3] = false;
                                              }
                                  }
                  
                      }
                   
                  }   
          }
   
     }

//----------------------------------------------------------------------------------------------------------------------------
//"Peace" animation program
    
    if (prog==2) {
          prog1 = false;
          prog2 = true;
          prog3 = false;
          prog4 = false;
          
          if (prog2_p) {
              speed2 = 1000000;
              speed4 = 10;
              speed5 = 100;
              an_step = 0;
              animation5 = 1;
              color5 = 1;
              matrix.fillRect(0, 0, 32, 16, colors[0]); 
              matrix.show();
           
          }

          int a = random(0, 32);
          int b = random(0, 8);
          int c = random(1, 16);    

          if  (!pixels_status4 [a][b]) {
                  if (trigger4) 
                    {
                      matrix.drawPixel(a, b, colors[c]);
                      pixels_status4 [a][b]=true;  
                      matrix.show();
                      count4++;
                    }
                 
              }
              
          if (count4>255) {
                      matrix.fillRect(0, 0, 32, 8, colors[0]);
                      count4=0;
                      for (x4 = 0; x4 <= 31; x4++) {
                          for ( y4 = 0; y4 <= 7; y4++) {
                            pixels_status4 [x4][y4] = false;
                          }
          
                      }
                    }
          
          
                    
           if (trigger5) {

                    matrix.setTextColor(colors[color5]);
                    matrix.setCursor(0, 8);
                    matrix.print("P");
                    
                
                    matrix.setTextColor(colors[color5+1]);
                    matrix.setCursor(6, 8);
                    matrix.print("E");
                    
                
                    matrix.setTextColor(colors[color5+2]);
                    matrix.setCursor(12, 8);
                    matrix.print("A");
                    
               
                    matrix.setTextColor(colors[color5+3]);
                    matrix.setCursor(18, 8);
                    matrix.print("C");
                    
                
                    matrix.setTextColor(colors[color5+4]);
                    matrix.setCursor(24, 8);
                    matrix.print("E");
                    color5++;

                    if (color5>14) {color5 = 1; }
                                        
                    trigger5 = false;
                    
                 }
              }    
                  
//----------------------------------------------------------------------------------------------------------------------------
//"Continents" animation program   

 if (prog==3) {
          prog1 = false;
          prog2 = false;
          prog3 = true;
          prog4 = false;
          
          if (prog3_p) {
              speed6 = 250;
              step7 = 0;
              speed8 = 80;
              j8 = matrix.width();
              text8 = "North America";
              color8 = 9;
              matrix.fillRect(0, 0, 32, 16, colors[0]); 
              matrix.show();
            
           
          }

          time1_q = TON (!time1_q, 10000, time1_elapsed, time1_count);

          if (time1_q) {
                step7++;
                if (step7 > 7) {
                  step7 = 1;
                  speed8 = 80;
                  j8 = matrix.width();
                  text8 = "North America";
                  color8 = 9;
                  matrix.fillRect(0, 0, 32, 16, colors[0]); 
                  matrix.show();
                  }
            }  
         
          if (trigger8) {//scrolling text
                      int lung = text8.length();
                      matrix.fillRect(0, 8, 32, 16, colors[0]);
                      matrix.setTextColor(colors[color8]);
                      matrix.setCursor(j8, 8);
                      matrix.print(text8);
                      j8--;
                      if(j8 < (-lung*6)) {
                        complete8 = true;
                        j8 = matrix.width();                        
                        }
                     matrix.show();
                     trigger8 = false;
                    }
                    
          if (step7==1) { //North America           
                      if (osc6_p) {
                        matrix.drawBitmap(0, 0, continents[0], 8, 8, colors[9]);
                        matrix.show(); 
                        }
                      if (osc6_n) {
                        matrix.drawBitmap(0, 0, continents[0], 8, 8, colors[0]);
                        matrix.show(); 
                        }

                      
                        
                  }
          
          if (step7==2) { //South America             
                      if (time1_q) {
                        matrix.fillRect(0, 8, 32, 16, colors[0]); 
                        matrix.drawBitmap(0, 0, continents[0], 8, 8, colors[9]);
                        matrix.show();
                        j8 = matrix.width();
                        text8 = "South America";
                        color8 = 3;                
                        }
                      if (osc6_p) {
                        matrix.drawBitmap(0, 0, continents[1], 8, 8, colors[3]);
                        matrix.show(); 
                        }
                      if (osc6_n) {
                        matrix.drawBitmap(0, 0, continents[1], 8, 8, colors[0]);
                        matrix.show(); 
                        }

                      


                        
                  }
           if (step7==3) { //Europe            
                      if (time1_q) {
                        matrix.fillRect(0, 8, 32, 16, colors[0]); 
                        matrix.drawBitmap(0, 0, continents[1], 8, 8, colors[3]);
                        matrix.show();
                        j8 = matrix.width();
                        text8 = "Europe";
                        color8 = 1;
                        }
                      if (osc6_p) {
                        matrix.drawBitmap(8, 0, continents[2], 8, 8, colors[1]);
                        matrix.show(); 
                        }
                      if (osc6_n) {
                        matrix.drawBitmap(8, 0, continents[2], 8, 8, colors[0]);
                        matrix.show(); 
                        }
                  }      
           if (step7==4) { //Africa            
                      if (time1_q) {
                        matrix.fillRect(0, 8, 32, 16, colors[0]);
                        matrix.drawBitmap(8, 0, continents[2], 8, 8, colors[1]);
                        matrix.show();
                        j8 = matrix.width();
                        text8 = "Africa";
                        color8 = 5;
                        }
                      if (osc6_p) {
                        matrix.drawBitmap(16, 0, continents[3], 8, 8, colors[5]);
                        matrix.show(); 
                        }
                      if (osc6_n) {
                        matrix.drawBitmap(16, 0, continents[3], 8, 8, colors[0]);
                        matrix.show(); 
                        }
                  }   
            if (step7==5) { //Asia          
                      if (time1_q) {
                        matrix.fillRect(0, 8, 32, 16, colors[0]);
                        matrix.drawBitmap(16, 0, continents[3], 8, 8, colors[5]);
                        matrix.show();
                        j8 = matrix.width();
                        text8 = "Asia";
                        color8 = 13;
                        }
                      if (osc6_p) {
                        matrix.drawBitmap(8, 0, continents[4], 8, 8, colors[13]);
                        matrix.drawBitmap(16, 0, continents[5], 8, 8, colors[13]);
                        matrix.drawBitmap(24, 0, continents[6], 8, 8, colors[13]);
                        matrix.show(); 
                        }
                      if (osc6_n) {
                        matrix.drawBitmap(8, 0, continents[4], 8, 8, colors[0]);
                        matrix.drawBitmap(16, 0, continents[5], 8, 8, colors[0]);
                        matrix.drawBitmap(24, 0, continents[6], 8, 8, colors[0]);
                        matrix.show(); 
                        }
                  }   
             if (step7==6) { //Oceania           
                      if (time1_q) {
                        matrix.fillRect(0, 8, 32, 16, colors[0]);
                        matrix.drawBitmap(8, 0, continents[4], 8, 8, colors[13]);
                        matrix.drawBitmap(16, 0, continents[5], 8, 8, colors[13]);
                        matrix.drawBitmap(24, 0, continents[6], 8, 8, colors[13]);
                        matrix.show(); 
                        j8 = matrix.width();
                        text8 = "Oceania";
                        color8 = 8;                        
                        }
                      if (osc6_p) {
                        matrix.drawBitmap(24, 0, continents[7], 8, 8, colors[8]);
                        matrix.show(); 
                        }
                      if (osc6_n) {
                        matrix.drawBitmap(24, 0, continents[7], 8, 8, colors[0]);
                        matrix.show(); 
                        }
                  }    
              if (step7==7) { //For a united world!          
                      if (time1_q) {
                        matrix.fillRect(0, 8, 32, 16, colors[0]);
                        matrix.show(); 
                        j8 = matrix.width();
                        text8 = "FOR A UNITED WORLD!";
                        color8 = 16;                        
                        }
                      if (osc6_p) {
                        matrix.fillRect(0, 0, 32, 8, colors[16]);
                        matrix.show(); 
                        }
                      if (osc6_n) {
                        matrix.fillRect(0, 0, 32, 8, colors[0]);
                        matrix.show(); 
                        }
                  }                  
    }


//----------------------------------------------------------------------------------------------------------------------------
//"Cities" animation program   

  if (prog==4) {
          prog1 = false;
          prog2 = false;
          prog3 = false;
          prog4 = true;
          
            
          if (prog4_p) {
              
              matrix.fillRect(0, 0, 32, 16, colors[0]); 
              matrix.show(); 
              speed9 = 40;

              for (x9 = 0; x9 <= 31; x9++) {
                          for ( y9 = 0; y9 <= 7; y9++) {
                            pixels_status9 [x9][y9] = false;
                          }
              }
              count9 = 0;
              complete9 = true; 
          }
  
           if (complete9) {
                     
                     matrix.show();
                     a9 = random(0, 32);
                     b9 = random(0, 8);
                     
                    
                     
                
                     if  (!pixels_status9 [a9][b9]) {
                            pixels_status9 [a9][b9] = true;
                            count9++;
                            text9 = city [a9] [b9];
                            complete9 = false;
                         }
                 
              }
              else {
                  
                  if (osc6_p) {
                        matrix.drawPixel(a9, b9, colors[c9]);
                        matrix.show(); 
                        }
                      if (osc6_n) {
                        matrix.drawPixel(a9, b9, colors[0]);
                        matrix.show(); 
                        }
                  
               if (count9>255) {
                      matrix.fillRect(0, 0, 32, 8, colors[0]);
                      count9=0;
                      for (x9 = 0; x9 <= 31; x9++) {
                          for ( y9 = 0; y9 <= 7; y9++) {
                            pixels_status9 [x9][y9] = false;
                          }
          
                      }
                    }  
                  
                if (!stop9) {
                   
                      if (da_p) { unlock = true;}
                      if (unlock && da_n) {
                      unlock = false;
                      stop9 = true;
                      }
                
                      if (trigger9) {//scrolling text
                          int lung = text9.length();
                          matrix.fillRect(0, 8, 32, 16, colors[0]);
                          matrix.setTextColor(colors[c9]);
                          matrix.setCursor(j9, 8);
                          matrix.print(text9);
                          j9--;
                          if(j9 < (-lung*6)) {
                              j9 = matrix.width();
                              matrix.fillRect(0, 8, 32, 16, colors[0]);
                              matrix.drawPixel(a9, b9, colors[17]);
                              complete9 = true;                     
                            }
                         matrix.show();
                         trigger9 = false;
                        } 
                   }
                 
                  
                  
                  
                  Serial.println (unlock);
                  
                  if (stop9) {
                    if (da_p) { unlock = true;}
                    if (unlock && da_n) {
                      unlock = false;
                      stop9 = false;
                      }
                   }
                
                        

              }

         }

              
      
          
                
                
               
          
           
          

   



   
}
