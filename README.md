

# MatrixCalculator207 [1.0]

A matrix calculator using an Arduino mega and a TFT touchscreen :grinning:

  

# About

  

The project is a touchscreen calculator for matrixes. The project consists only of a TFT touchscreen connected to an Arduino mega. The hardware is easier to set up leaving the software aspect the demanding task of the project. The software involves:

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

 * Software (the code)

   * Explaining the code

   *  How it works

       * Display 
           * settings.h
           *  Common Functions,
           * Drawing the Screen

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

  

<p>In the project proposal, I identified my project as a modification to a normal calculator made with Arduino. I got the inspiration for the project from https://www.allaboutcircuits.com/projects/simple-arduino-based-calculator/ who made a calculator using Arduino. However, due to the modifications that I made there is little resemblance to his idea, hardware or code.

  

In the proposal, I offered modifications that would make the calculator perform computations like matrixes and differential calculus. The original project was going to be made using an LCD screen for the output and a keypad for the input. However, after discovering that touchscreens can also be used with Arduino the project took a turn. The project was going to be a hybrid of a touchscreen and a keypad (like a blackberry) where the touchscreen could be used to display the output and have a few buttons for special commands. In gathering materials for the project, I purchased the wrong keypad. The keypad purchased needed soldering to be connected to the Arduino but since I lack the skills and materials to achieve that the keypad was rendered mute. Consequently, I had to modify the project by designing a keypad on the touch screen. This shift of workload from getting data from the keypad to designing a keypad with data on a touchscreen meant that more time was spent coding the interface rather than the logic of the calculations. This cutback forced me to abandon the original idea of the calculator being able to perform matrix and differential calculations and to limit it to only matrix calculations.</P>

  

## Hardware

### Materials and Links

There are only two materials required for the project. They can be found here:

<div align="center"><strong>From Amazon:</strong> </div><br>

3.5" TFT LCD: https://www.amazon.ca/gp/product/B07NWH47PV/ref=ppx_yo_dt_b_asin_title_o00_s00?ie=UTF8&psc=1 <br>

Arduino Mega: https://www.amazon.ca/gp/product/B016JWNYBE/ref=ppx_yo_dt_b_asin_title_o00_s00?ie=UTF8&psc=1 <br>

<div align="center"><strong>From the Arduino Store:</strong> </div><br>

Arduino Mega: https://store.arduino.cc/usa/mega-2560-r3?queryID=undefined <br>

  

### Schematics

![20210317_144831](https://user-images.githubusercontent.com/54193310/114350872-0d0e4180-9b27-11eb-9126-d7edbb7a9a6d.jpg)

### Notes/Extras

  

* The TFT LCD was designed to easily assemble with an Arduino Mega or Uno<br>

What this means is that all you need to do is to plug the TFT LCD into the mega or Uno and you are ready to go

* The mega can be replaced with an Uno: https://store.arduino.cc/usa/arduino-uno-rev3?queryID=undefined

## Software (Setting up)

  

To run and develop the program I used the Arduino IDE.

You can download and install it here: https://www.arduino.cc/en/software <br>

You could also use the online editor: https://create.arduino.cc/editor/chukwunonso_j/d243d4f5-0f02-4887-9fd4-5465835f67ca <br>

  

### Libraries

  

To use the TFT touch screen you need to get two libraries <br>

* MCUFRIEND_kbv libraries: https://github.com/prenticedavid/MCUFRIEND_kbv

* Adafruit_TouchScreen library: https://github.com/adafruit/Adafruit_TouchScreen

  

### Installation

  

After downloading the zip files to install them click on Sketch then click on include Library and then add .ZIP Library<br>

![image](https://user-images.githubusercontent.com/54193310/113666110-eefa9a00-966b-11eb-8ecd-815960018320.png)<br>

  

The Adafruit_TouchScreen library can be installed without downloading the zip file<br>

To do that open the Arduino library manager and then search for Adafruit_TouchScreen library<br>

  

![image](https://user-images.githubusercontent.com/54193310/113666409-7b0cc180-966c-11eb-936f-6394d338b88a.png)<br>

![image](https://user-images.githubusercontent.com/54193310/113666346-64666a80-966c-11eb-9b6d-07707cf00077.png)<br>

  

### Notes/Extras

  

The documentation for the Adafruit library can be found here: http://adafruit.github.io/Adafruit-GFX-Library/html/class_adafruit___g_f_x___button.html#a932228d686e6dec88b8b99d03fdb59a7 <br>

This write up is a good reference for the MCUFRIEND_kbv library: https://electropeak.com/learn/absolute-beginners-guide-to-tft-lcd-displays-by-arduino/ <br>

All the code was written by me except for the function Touch_getXY(void). this was gotten from the MCUFRIEND_kbv library examples.

## Software (The code)

<p> I divided the workload for the code into three parts The first part involves designing the interface, the second part is getting input from the user and the last part is calculating the result and then displaying it back</p>

<p> The original plan was to use a physical keypad to get the input but the wrong keypad was delivered </p>

<p> Designing the interface involves some workarounds because the functions of the libraries used are limited to only drawing buttons, shapes and lines. There are no text fields or inputs so I needed to create a workaround for this </p>

The project has four files/parts that are used for specific functions <br>

  

* main(This was used for the design)<br>

* settings (This was used to define libraries used, macros, global variables and arrays,)<br>

* Touchscreen (This was used to get were was clicked on the screen and the actions to be performed after)<br>

* logic (This was used to calculate the matrix functions)<br>

  
  

### How it works

<p> -We have the first set of keypad buttons, the numerical ones (from 1-9) that when clicked are added to a global variable(mimicking a keypad from a calculator) and is then is displayed on a designed text field (we also have special buttons in the keypad) </p>

<p> -There is a text field at the top that holds the global variable and displays it</p>

<p> -There are three matrixes. The first two are the matrixes that get input are displayed from the beginning </p>

<p> -The third matrix holds the result and is displayed after the calculation is done</p>

<p> -I designed the first two matrixes so that each cell has a button that when clicked the text from the text field is stored in the matrix cell </p>

<p> -When the whole matrix is filled depending on which special character is clicked, the calculation is done and is stored in the third matrix.. When the result button is clicked the third matrix is drawn over the two matrixes </p>

  

### Display

In settings.h I included libraries for the touchscreen and I defined macros for the colours, pins and pressure<br>

  

#### settings.h

Including libraries for using the touchscreen

``` java

#include "Adafruit_GFX.h" // Core graphics library

#include "MCUFRIEND_kbv.h" // Hardware-specific library

#include <stdint.h>

#include "TouchScreen.h"

```

Assigning variables for the pins of the touchscreen, and for the pressure

``` java

// These are the pins for the shield!

#define YP A1 // must be an analog pin, use "An" notation!

#define XM A2 // must be an analog pin, use "An" notation!

#define YM 7 // can be a digital pin

#define XP 6 // can be a digital pin

//Pressure

#define MINPRESSURE 1

#define MAXPRESSURE 1000

```

Defining colours that would be used and fonts

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

#### Common Functions

There are some common codes that I used throughout the project

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

initButton(gfx,  x, y,w,h,outline, fill,textcolor,*label,textsize_x,textsize_y);// initializes the button,the x and y location,the width,height and the color of the outline,color the button, the text of the button, and the text size

drawButton(true);//draws the button

```

<div align="center"><strong>Clicking On Button</strong> </div><br>

  

``` java

contains(x,y); //checks if the x and y location are within the bounds of the button

press();//sets wat triggers the button

justPressed();//Checks if the button was just pressed

```

  

### Drawing the Screen

These two functions were used often throughout the code <br>

<div align="center"><strong>writeText(String text, int textSize, int x, int y, bool isLine)</strong> </div><br>

<p>This function when called takes in parameters for drawing a text like the x and y location of the text, the text size and whether or not the text should be on a line or not. I decided to put all these in function because to write a text takes up a number lines so this functions simplifies that</p>

  

``` java

//function takes in an x and y location, a string and bool and draws the text

//the bool signifies if it is a line text or not

void writeText(String text, int textSize, int x, int y, bool isLine) {

tft.setCursor(x, y);//sets the location

tft.setTextSize(textSize);

if (isLine)

tft.println(text);

else

tft.print(text);

}

```

<div align="center"><strong>storeMatrixData(int x, int y, buttonsStruct* store, char * text, int colour)</strong> </div><br>

<p>This function when called takes in parameters for drawing a button and stores its data in a struct. As explained earlier we are going to store the text of a button and its location along with the button itself in a struct. In this function we are going to pass in the struct by reference and then store the values and initialize the button using a pointer. As with the first function this is done to avoid writing the same thing every time as the proccess is used often throughout the code. </p>

  

``` java

/* This function stores the data of the matrix cell and then displays it

its store the text, and then x and y location of the button

Except for the text, the x and y location are not neccesary in this version of the code but would be useful for future updates*/

void storeMatrixData(int x, int y, buttonsStruct* store, char * text, int colour) {

//using pointers

//store the data

store->x = x ;

store->y = y ;

store->text = text;

//drawing the buttons

store->button.initButton(&tft, store->x, store->y, 55, 30, WHITE, BLACK, colour, text, 2);

store->button.drawButton(true);

}

```

<div align="center"><strong>keypadDesign()</strong> </div><br>

<p>This function is used to draw the keypad. It starts by drawing two borders (This is not necessary, its mostly for aesthetics) and then setting the location for the first button. The location or coordinates that you choose to use would be determined by the screen that you use. The offset variable is used for accessing the data in the array

that stores the text, it works by adding the location of the struct to the offset to get to the keypad text.

Next, we loop through the first 10 buttons (The numerical buttons) and then call the storeMatrixData()

function to store and draw the button. the same process is then repeated for the first 4 special buttons.

For the next buttons, either one of their coordinates are not derived from a progression but rather are unique. We store the equals button next and then we store the x coordinates of the remaining buttons and when we

repeat the process of looping the x coordinate is gotten from the array.</p>

  

``` java

void keypadDesign() {

//Border design

tft.drawFastVLine(260, 0, 500, BLACK); //vertical line close to keypad buttons

tft.drawFastHLine(1, 447, 350, BLACK); //horizontal line close to keypad button

//button design

int x = 290;

int y = 13;

int offset;// used for accesing the data in keypadText[]

// draw the buttons 1-9

for (int i = 0; i < 10; i++) {

storeMatrixData(x, (y + (i * 30)), &keypadButtonArray[i], keypadText[i], CYAN);

}

//draw the calculations buttons (+,-,x,*,CLR)

for (int i = 0; i < 5; i++) {

offset = i + 10;//used to access the data in keypadText[]

storeMatrixData(x, (y + (offset * 30)), &specialButtonArray[i], keypadText[offset], GREEN);

}

//This buttons were designed with differnt coordinates on the screen

int temp[] = {40, 120, 210};// the location x locations of the buttons

y = (y + (15 * 30 ));

storeMatrixData(x, y , &specialButtonArray[5], "=", RED);// draw the equals button

x = 1;

//draw the matrix number buttons

for (int i = 6; i < 9; i++) {

offset = i + 10;

storeMatrixData((x + temp[i - 6]), y , &specialButtonArray[i], keypadText[offset], GREEN);

}

}

```

  

<div align="center"><strong> buttonsStructDesign(int xLocation, int yLocation, int matrixNo, int location)</strong> </div><br>

<p>This function is used to draw a single matrix cell. It takes in the information for the row and column number of the cell, which matrix it is being drawn to, and its location in the array. It starts by setting the coordinates and the bounds for the cell. Next, depending on the matrix a switch used so that (1,2,3) represents matrix A, B, and the

result. Depending on which number is supplied into the parameter the matrix is drawn. All cases are similar, they all display a text which is the heading of the matrix, then they call the storeMatrixData() to

draw to store and draw the button. The difference is in their y location and which matrix is sent in the parameters. Next, a rectangle is drawn around the button to give it the matrix design </p>

  

``` java

//Design the cell of a matrix

void buttonsStructDesign(int xLocation, int yLocation, int matrixNo, int location) {

//locations

int y; int x = 10;

int w = 50;//width

int h = 40;//height

char * text = "";

//Cell spacing

int cellOffset = 40;

int buttonOffset = 46;

tft.setTextColor(BLACK, WHITE);//subsequent text would be set to this color

switch (matrixNo) {

case 1://first matrix

writeText("A", 3, 100, 20, false ); //design for the matrix heading

y = 10;

storeMatrixData((x + (buttonOffset * xLocation)), (y + (buttonOffset * yLocation)), &matrixA[location], text, WHITE);

break;

case 2://second matrix

y = ((35 * buttonsStructAmount) + 80);

writeText("B", 3, 100, y, false );//design for the matrix heading

storeMatrixData((x + (buttonOffset * xLocation)), (y + (buttonOffset * yLocation)), &matrixB[location], text, WHITE);

break;

case 3://result matrix

y = 30;

writeText("RESULT", 2, 40, 20, false );//design for the matrix heading

writeText( matrixC[location].text, 1, (x + (buttonOffset * xLocation)), ( y + (buttonOffset * yLocation)), false);

break;

}

x = 10;

//draw the cell

tft.drawRect(x + (cellOffset * xLocation), y + (cellOffset * yLocation), cellOffset, h, BLACK);

}

}

```

  

<div align="center"><strong> textFieldDesign()</strong> </div><br>

<p>This function is used to draw the textField It draws a rectangle and writes the text from global variable textFieldtext that stores which keypad buttons were clicked on</p>

  

``` java

void textFieldDesign() {

tft.drawRect(195, 1, 60, 30, BLACK);

tft.setTextColor(BLACK, WHITE);//used for writing over charcters(similar to erasing)

writeText(textFieldText, 2, 195, 1, false);

}

```

  

<div align="center"><strong> void calculationType(String text)</strong> </div><br>

<p>This function is used to draw the symbol of which calculation was performed when the result is drawn. Its height is also drawn relative to the height of the first matrix</p>

  

``` java

void calculationType(String text) {

tft.setTextColor(BLACK, WHITE);//used for writing over charcters(similar to erasing)

writeText(text, 3, 40, ((35 * buttonsStructAmount) + 80), false);

}

  

```

<div align="center"><strong> drawMatrix(int matrixNumber)</strong> </div><br>

<p>This function is used to draw a matrix. It has two for loops that are used to signify the row and colomn. It takes in a number that signifies which matrix is to be drawn. The number is then sent to the function buttonsStructDesign(a, i, matrixNumber, location) along with the row and column of the matrix cell.</p>

  

``` java

//Used to draw the matrix

void drawMatrix(int matrixNumber) {

int location = 0;

for (int a = 1; a < buttonsStructAmount + 1; a++) {

for (int i = 1; i < buttonsStructAmount + 1; i++) {

buttonsStructDesign(a, i, matrixNumber, location);

location++;

}

}

}

```

<div align="center"><strong> void setup()</strong> </div><br>

<p>This function is called at the start of the program. The first part sets the display with information like its orientation, id and background. The second part is calling other functions to draw the keypad and the two matrixes </p>

  

``` java

//setting up the display

uint16_t ID = tft.readID();

tft.begin(ID);

tft.setRotation(0);//potrait

tft.fillScreen(WHITE);//background colour

//calling functions that design the screen

keypadDesign();//draw the keypad

textFieldDesign();//draw the text input field

//draw the input matrixes

drawMatrix(1);

drawMatrix(2);

```
### Touch Functions
This part of the code is used to get a touch input, and query the buttons on what to do if clicked. 
<div align="center"><strong> bool Touch_getXY(void)</strong> </div><br>

<p>This function was gotten from the examples from the "button simple" code from the MCUFRIEND_KBV library. How to find it  </p>
![image](https://user-images.githubusercontent.com/54193310/114343745-cbc46480-9b1b-11eb-9796-3497cd18e1f3.png)

``` java
//setting up touch parameters
const int TS_LEFT = 931, TS_RT = 185, TS_TOP = 968, TS_BOT = 183;
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);
//this function Touch_getXY() was gotten from the button examples on the "MCUFRIEND_kbv.h" library
//the function returns a bool depending on if the screen was touched or not
//it also maps variables pixel_x, pixel_y to where was touched
bool Touch_getXY(void)
{
  TSPoint p = ts.getPoint();
  pinMode(YP, OUTPUT);      //restore shared pins
  pinMode(XM, OUTPUT);
  digitalWrite(YP, HIGH);   //because TFT control pins
  digitalWrite(XM, HIGH);
  bool pressed = (p.z > MINPRESSURE && p.z < MAXPRESSURE);
  if (pressed) {
    pixel_x = map(p.x, TS_LEFT, TS_RT, 0, tft.width()); //.kbv makes sense to me
    pixel_y = map(p.y, TS_TOP, TS_BOT, 0, tft.height());
  }
  return pressed;
}
```
<div align="center"><strong>void keypadNumbersClicked()</strong> </div><br>

<p>This function checks if a button on the keypad was clicked. It does this by looping through all the buttons and setting the parameters that activate their press function. This parameters are gotten from the Touch_getXY(void) function that checks if the an area on the screen was clicked and if so maps out the area. 
<br>If a numerical  button was clicked and the the textField length is not reached, the text on the keypad is added to the global variable textFieldText. The function textFieldDesign() is called to redraw the textfield
<br>If a special  button was clicked, the function matrixCalculations is called. This function perfroms the calculations for the matrix </p>

``` java
//checks if a numerical button or special button on the keypad was clicked
//If clicked the number is added to the text field
void keypadNumbersClicked() {
  for (int i = 0; i < 10; i++) {
    bool down = Touch_getXY();
    //initialize  parameters for recieving touch
    keypadButtonArray[i].button.press(down && keypadButtonArray[i].button.contains(pixel_x, pixel_y));
    specialButtonArray[i].button.press(down && specialButtonArray[i].button.contains(pixel_x, pixel_y));
    //check if a numerical button was clicked and the maximum number digit is reached
    if (keypadButtonArray[i].button.justPressed() && textFieldText.length() < 4)
      textFieldText = textFieldText + keypadButtonArray[i].text;
    //check if a special button was clicked 
    else if (specialButtonArray[i].button.justPressed())
      matrixCalculations(i);
  }
  textFieldDesign();//update the text field
}
```
<div align="center"><strong>void matrixCellClicked()</strong> </div><br>

<p>This function is similar to the keypadNumbersClicked() function. The function checks if a button(cell) on the matrix was clicked. It does this by looping through all the buttons and setting the parameters that activate their press function. This parameters are gotten from the Touch_getXY(void) function that checks if the an area on the screen was clicked and if so maps out the area. 
<br>Here if a button was clicked a white rectangle is drawn to cover up previous text, if any. Next, it sets the text of the matrix cell struct to the text in the text field, and then it displays it.  
</p>

``` java
//checks if a button on either matrixes was clicked
void matrixCellClicked() {
  for (int i = 0; i < buttonsStructAmount  * buttonsStructAmount ; i++) {
    bool down = Touch_getXY();
    //initialize  parameters for recieving touch
    matrixB[i].button.press(down && matrixB[i].button.contains(pixel_x, pixel_y));
    matrixA[i].button.press(down && matrixA[i].button.contains(pixel_x, pixel_y));
    
    if (matrixB[i].button.justPressed()) {
      tft.fillRect(matrixB[i].x, matrixB[i].y, 35, 30, WHITE);
      matrixB[i].text = textFieldText;
      writeText( matrixB[i].text, 1, matrixB[i].x, matrixB[i].y, false);//draw the text from the text field
    }
    if (matrixA[i].button.justPressed()) {
      tft.fillRect(matrixA[i].x, matrixA[i].y, 35, 30, WHITE);
      matrixA[i].text = textFieldText;
      writeText( matrixA[i].text, 1, matrixA[i].x, matrixA[i].y, false);//draw the text from the text field
    }
  }
}
```

### Calculation
There is only one function that is used for calculation. It is the  matrixCalculations(int choice) function. These first two functions are functions related to the calculation function.
<div align="center"><strong>drawResult()</strong> </div><br>
<p>This function when called draws a white rectangle over the previous matrixes and then draws the back button.
</p>

``` java
//draw the result matrix
void drawResult() {
  tft.fillRect(0, 0, 260, 420, WHITE);
  backButton.initButton(&tft, 100 , 280 , 55, 30, WHITE, BLACK, RED,  "<- " , 2);
  backButton.drawButton(true);//enable the back button
}
```
<div align="center"><strong>backButtonClicked()</strong> </div><br>
<p> This function initializes and draws the back button. It then sets the parameters for the button. If the button is clicked it updates the variable that enables the other buttons and then calls the setup() function to redraw  the screen</p>

``` java
//Check is back button is clicked
void backButtonClicked() {
  bool down = Touch_getXY();
  backButton.press(down && backButton.contains(pixel_x, pixel_y));
  if (backButton.justPressed())
  {
    ON_OFF = 1;//enable the other buttons
    setup();//redraw the original screen
  }
}
```

<div align="center"><strong>void matrixCalculations(int choice)</strong> </div><br>

<P> This function takes in number that signifies which calculation should be done. In this function there are two switches, the first one is used for matrix calculations while the second is used for special functions. 
<br> For the first switch a loop is done around it for the amount of the matrix cell that are present.  To perfrom the calculation the text of the corresponding matrix is gotten and converted nto an int and is then performed the calculation. After that the result is converted back into a string and stored in the result matrix. The calculation for the first three cases are addition, subtraction,  and harmadad multiplication. For the fourth multiplication(matrx multiplication) the calculation involves matrix multiplication this can help</P> https://www.mathsisfun.com/algebra/matrix-multiplying.html
<P>The second switch is used for operations like drawing the result, redrawing the matrixes cell and column </p> 

``` java
void matrixCalculations(int choice) {
  //takes in a int performs an action based on the number
  int i = 4;
  for (int n = 0; (n < (buttonsStructAmount  * buttonsStructAmount )); n++)
  {
    switch (choice) {
      //we convert both matrixes text to int, perform a calculation.
      //After the calculation the int is then converted to a string and stored in the result matrix 
      case 0://matrix addition
        calculationType("+");
        matrixC[n].text = String((matrixA[n].text.toInt() + matrixB[n].text.toInt()), DEC);
        break;
      case 1://matrix subtraction
        calculationType("-");
        matrixC[n].text = String((matrixA[n].text.toInt() - matrixB[n].text.toInt()), DEC);
        break;
      case 2://matrix hamadad multiplication
        calculationType("x");
        matrixC[n].text = String((matrixA[n].text.toInt() * matrixB[n].text.toInt()), DEC);
        break;
      case 3://matrix multiplication
        calculationType("*");
        if ((n + 1) / (buttonsStructAmount ) == 0)
          i++;
        matrixC[n].text = String((matrixA[i].text.toInt() * matrixB[n + buttonsStructAmount ].text.toInt()) + (matrixA[i + 1].text.toInt() * matrixB[n + (buttonsStructAmount  * 2)].text.toInt()) + (matrixA[i + 1].text.toInt() * matrixB[n + (buttonsStructAmount  * 3)].text.toInt()) + (matrixA[i + 1].text.toInt() * matrixB[n + (buttonsStructAmount  * 4)].text.toInt()), DEC);
        break;
    }
  }
  //Non computational cases
  switch (choice) {
    case 4:// used to erase numbers from the text field by drawing a rectangle over it
      tft.fillRect(195, 1, 60, 30, WHITE);
      textFieldText = "";//reset the text to nothing
      textFieldDesign();
      break;
    case 5://display result
        ON_OFF = 0;//disable other buttons
        drawResult();
        drawMatrix(3);
      break;
    case 6:// redraw the matrixes as a 2x2 matrix
      buttonsStructAmount = 2;
      setup();
      break;
    case 7://redraw the matrixes as a 3x3 matrix
      buttonsStructAmount = 3;
      setup();
      break;
    case 8://redraw the matrixes as a 4x4 mtrix
      buttonsStructAmount = 4;
      setup();
      break;
  }
}
```
<div align="center"><strong>void loop()</strong> </div><br>

<P> The final part of the code is the loop. The loop continues running over and over. In the loop the function theat checks if the keypad is clicked and the function that checks if the matrix is clicked is called. The back button is also called in the loop </p> 

``` java
//this keeps on running
void loop(void) {
 //if the keypad and matrix are enabled
  if (ON_OFF) {
    keypadNumbersClicked();//checks if a keypad button was clicked on
    matrixCellClicked();//checks if a matrix cell was clicked on
  }
  //enable back Button
  else
    backButtonClicked();
}
```
### Updates
Almost everything worked, the main bug is how the buttons are drawn and the + button clicked 



### Notes/Extras
