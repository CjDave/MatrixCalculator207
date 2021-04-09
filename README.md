# MatrixCalculator207 [1.0] 
A matrix calculator using an Arduino mega and a TFT touchscreen :grinning: 

# About

The project is a touchscreen caclulator for matrixes. The project consists only of a tft touchscreen connected to an arduino mega. 
The hardware is easier to set up leaving the software aspect the task demanding of the project.
The software invloves: 
* The design for the display
* The touch function
* The logic for calculating the matrixes

## Table of Contents

* Respository Contents
* Preamble
* Hardware
   * Materials and Links
   * Schematics
   * Notes/Extras
* Software (Setting up)
   * Libraries
   * Notes/Extras
* Software (The code)
   * Explaining the code
   * How it works
     * Display-> [settings.h,how to,main] 
     * Touch Functions
     * Calculation
   * Notes/Extras
   
## Repository Contents

Even though a number of this files will be in this readme, I have still created folders for the files/links for easy navigation  
* **/src** - The source codes and header files(.ino, .h).  
* **/hardware** - List of materials and their design (.ftz,.jpg).
* **/libraries** - Links to download the libraries that are needed. 
* **/img** - This is where the image files for this readme are! Yay!
* **/LICENSE** - The license file.
## Preamble
<p>In the project proposal, I identified my project as a modification to a normal calculator made with Arduino. In the proposal, I offered modifications that would make the calculator perform computations like matrixes and differential calculus. The original project was going to made using an LCD screen for the output and a keypad for the input. However, after discovering that touchscreens can also be used with Arduino the project took a turn. The project was going to be a hybrid of a touchscreen and a keypad (like a blackberry) where the touchscreen could be used to display the output and also have a few buttons for special commands.
I purcahesed the wrong keypad. The keypad I'd gotten needed soldering to be connected to the Arduino but since I lack the skills and materials to achieve that the keypad was rendered mute. The modification that resulted from this was having to design a keypad on the touch screen. This shift of workload from only getting data from the keypad to designing one on a touchscreen and also getting data from it meant that more time had to be spent coding the interface rather than the logic of the calculations. This cutback meant that the original idea of being able to perform matrix and differential calculations was reduced to only matrix calculations </P>

## Hardware
### Materials and Links
There are only two materials required for the project they can be found here  
<div align="center"><strong>From Amazon:</strong> </div><br>
3.5" TFT LCD: https://www.amazon.ca/gp/product/B07NWH47PV/ref=ppx_yo_dt_b_asin_title_o00_s00?ie=UTF8&psc=1  <br>
Arduino Mega: https://www.amazon.ca/gp/product/B016JWNYBE/ref=ppx_yo_dt_b_asin_title_o00_s00?ie=UTF8&psc=1  <br>
<div align="center"><strong>From the Arduino Store:</strong> </div><br>
Arduino Mega: https://store.arduino.cc/usa/mega-2560-r3?queryID=undefined  <br> 

### Schematics

### Notes/Extras

* The tft LCD was designed so easily assembled with an arduino mega or Uno<br>
  What this means is that all you need to do is to plug the TFT LCD into the mega or Uno and you are ready to go
* The mega can be replaced with an Uno :https://store.arduino.cc/usa/arduino-uno-rev3?queryID=undefined 
## Software (Setting up)

To run and devlop the program I used the Arduino IDE.
You can download and install it here: https://www.arduino.cc/en/software <br>
You could also use the online editor: https://create.arduino.cc/editor/chukwunonso_j/d243d4f5-0f02-4887-9fd4-5465835f67ca <br>

### Libraries

To use the TFT touch screen you need to get two libraries <br>
* MCUFRIEND_kbv library: https://github.com/prenticedavid/MCUFRIEND_kbv
* Adafruit_TouchScreen library: https://github.com/adafruit/Adafruit_TouchScreen

### Installation

After downloading the zip files to install them click on Sketch then click on include Library and then add .ZIP Library<br>
![image](https://user-images.githubusercontent.com/54193310/113666110-eefa9a00-966b-11eb-8ecd-815960018320.png)<br>

The Adafruit_TouchScreen library can be installed without downloading the zip file<br>
To do that open the Arduino library manager and then search for Adafruit_TouchScreen library<br>

![image](https://user-images.githubusercontent.com/54193310/113666409-7b0cc180-966c-11eb-936f-6394d338b88a.png)<br>
![image](https://user-images.githubusercontent.com/54193310/113666346-64666a80-966c-11eb-9b6d-07707cf00077.png)<br>

### Notes/Extras

The documentation for the adafruit library can be found here: http://adafruit.github.io/Adafruit-GFX-Library/html/class_adafruit___g_f_x___button.html#a932228d686e6dec88b8b99d03fdb59a7 <br>
This write up is a good reference for the MCUFRIEND_kbv library:  https://electropeak.com/learn/absolute-beginners-guide-to-tft-lcd-displays-by-arduino/ <br>

## Software (The code)
<p> The code was divided into three parts The first part involves designing the interface, the second part is getting an input from the user and the last part is calculating the result and then displaying it back</p>
<p> The original plan was to use a physical keypad to get the input but the wrong keypad was delivered </p> 
<p> Designing the interface involves some work arounds becaues the functions of the library used are reduced to only fdrawing buttons, shapes and lines. There are no text fields or inputs so I needed to create a work around for this </p>
The project has four files/parts that are used for specific functions <br>

* Igaveup (This was used for the design)<br>
* settings (This was used to define libraries used, macros, global variables and arrays,)<br>
* Touchscreen (This was used to get were was clicked and the actions to be perfomed)<br>
* logic (This was used to calculate the matrix functions)<br>


 ### How it works
<p> -First we have buttons (from 1-9) that when clicked are added to a global vairiable(mimicking a keypad from a calculator) and is then is   displayed on a designed textfield   (we also have special buttons in the keypad) </p>  
<p> -The is a textfield at the top that holds the global variable and displays it</p>
<p> -There are three matrixes the first two are the matrixes that get input are displayed from the beginning </p>
<p> -The third matrix holds the result and is displayed after the calculation is done</p>
<p> -I designed the first two matrix so that each cell has a button that when clicked the text from the text field is stored in the matrix cell </p>
<p> -When the whole matrix is filled depending on which special charcter is clicked, the calculation is done and is stored in the third   matrix.. When the result button is clicked the third matrix is drawn over the first matrixes  </p>

### Display 
In settings.h I included libraries for the touchscreen and I defined macros for the colors, pins and pressure<br>

#### settings.h
Including libraries for using the touchscreen
``` java
#include "Adafruit_GFX.h"   // Core graphics library
#include "MCUFRIEND_kbv.h" // Hardware-specific library 
#include <stdint.h>
#include "TouchScreen.h"
```
Assigning variables for the pins of the touchscreen, and for the pressure
``` java
// These are the pins for the shield!
#define YP A1  // must be an analog pin, use "An" notation!
#define XM A2  // must be an analog pin, use "An" notation!
#define YM 7   // can be a digital pin
#define XP 6   // can be a digital pin
//Pressurre
#define MINPRESSURE 1
#define MAXPRESSURE 1000
```
Defining colours That would be used and fonts
``` java
//Colours
#define BLACK 0x0000
#define GREEN 0x07E0
#define CYAN 0x07FF
#define RED 0xF800
#define WHITE 0xFFF
//fonts used
#include "Fonts/FreeSans9pt7b.h"
#include "Fonts/FreeSans12pt7b.h"
#include "Fonts/FreeSerif12pt7b.h"
#include "FreeDefaultFonts.h"
``` 
global variables used
``` java
int pixel_x, pixel_y;
bool ON_OFF=1;  
int buttonsStructAmount = 4;
String textFieldText = "";
```
This struct is used to store the x and y location, the text and a button<br>
This is what is used to define each button
``` java
struct buttonsStruct {
  int x, y;
  Adafruit_GFX_Button button;
  String text;
};
```
Array that stores the text for the keypad buttons
``` java
char *keypadText[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "+", "-", "*", "x","CLR", "=", "2x2", "3x3", "4x4"};
```
Creating buttons for the keypad and matrix cells and storing them in an array
``` java
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
```
#### How to
There some common code that I used throughout the project
<div align="center"><strong>Drawing Lines</strong> </div><br>

``` java
drawFastVLine(x,y,h,t); //draws a vertical line with the x and y location, the height and the color 
drawFastHLine(x,y,w,t); //draws a Horizontal line with the x and y location, the height and the color 
```
<div align="center"><strong>Drawing rectangles</strong> </div><br>

``` java
fillRect(x,y,w,h,t); // draw the rectangle with the x and y location, the width,height and the color of the rectangle
drawRect(x,y,w,h,t); // draw the outline of a rectangle with the x and y location, the width,height and the color of the outline

```
<div align="center"><strong>Writing Texts</strong> </div><br>

``` java
setCursor(x, y);//sets the location of the text
setTextSize(textSize);/sets the size of the texr
setTextColor(t,b); // set the textcolor and the background color of a text
println(" line text");//print the text on aline
print("not line text");//print the text
```
<div align="center"><strong>Drawing Buttons</strong> </div><br>

``` java
initButton(gfx,	x, y,w,h,outline, fill,textcolor,*label,textsize_x,textsize_y);// initializes the button,the x and y location,the width,height and the color of the outline,color the button, the text of the button, and the text size
drawButton(true);//draws the button
```
<div align="center"><strong>Clicking On Button</strong> </div><br>

``` java
contains(x,y); //checks if the x and y loaction are within the bounds of the button
press();//sets wat triggers the button
justPressed();//Checks if the button was just pressed
```

### Touch
``` java
```
``` java
```
``` java
```
### Calculation

### Explaining the code
there are less repetitive ways to do this but I have limited knowledge on Java
### Notes/Extras
