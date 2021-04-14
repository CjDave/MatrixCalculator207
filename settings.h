#include "Adafruit_GFX.h"   // Core graphics library
#include "MCUFRIEND_kbv.h" // Hardware-specific library 
#include <stdint.h>
#include "TouchScreen.h"
//fonts used
#include "Fonts/FreeSans9pt7b.h"
#include "Fonts/FreeSans12pt7b.h"
#include "Fonts/FreeSerif12pt7b.h"
#include "FreeDefaultFonts.h"
// These are the pins for the shield!
#define YP A1  // must be an analog pin, use "An" notation!
#define XM A2  // must be an analog pin, use "An" notation!
#define YM 7   // can be a digital pin
#define XP 6   // can be a digital pin
//Pressurre
#define MINPRESSURE 200
#define MAXPRESSURE 1000


//colors I used
#define BLACK 0x0000
#define GREEN 0x07E0
#define CYAN 0x07FF
#define RED 0xF800
#define WHITE 0xFFFF

// global variables
int pixel_x, pixel_y;
bool ON_OFF=1;
int buttonsStructAmount = 4;
String textFieldText = "";
//
Adafruit_GFX_Button backButton;
//stores the text of the keypad
char *keypadText[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "+", "-", "*", "x","CLR", "=", "2x2", "3x3", "4x4"};
struct buttonsStruct {
  int x, y;
  Adafruit_GFX_Button button;
  String text;
};
//Keypad Buttons
buttonsStruct button1, button2, button3, button4, button5, button6, button7, button8, button9, button_plus, button_minus, button_multiplication, button_harmadad, button_Clr,buttonEquals, buttonMatrix2, buttonMatrix3, buttonMatrix4;
buttonsStruct keypadButtonArray[] = {button1, button2, button3, button4, button5, button6, button7, button8, button9};
buttonsStruct specialButtonArray[] = {button_plus, button_minus, button_multiplication, button_harmadad, button_Clr, buttonEquals, buttonMatrix2, buttonMatrix3, buttonMatrix4};
//matrix Buttons
buttonsStruct a11, a12, a13, a14, a21, a22, a23, a24, a31, a32, a33, a34, a41, a42, a43, a44;
buttonsStruct b11, b12, b13, b14, b21, b22, b23, b24, b31, b32, b33, b34, b41, b42, b43, b44;
buttonsStruct c11, c12, c13, c14, c21, c22, c23, c24, c31, c32, c33, c34, c41, c42, c43, c44;
buttonsStruct matrixA[] = {a11, a12, a13, a14, a21, a22, a23, a24, a31, a32, a33, a34, a41, a42, a43, a44};
buttonsStruct matrixB[] = {b11, b12, b13, b14, b21, b22, b23, b24, b31, b32, b33, b34, b41, b42, b43, b44};
buttonsStruct matrixC[] = {c11, c12, c13, c14, c21, c22, c23, c24, c31, c32, c33, c34, c41, c42, c43, c44};
