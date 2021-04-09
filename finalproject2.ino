
//most of this part is for the design of the touchscreen
#include "settings.h"
MCUFRIEND_kbv tft;
void setup()
{
  //setting up the display
  uint16_t ID = tft.readID();
  tft.begin(ID);
  tft.setRotation(0);//potrait
  tft.fillScreen(WHITE);//background colour
  Serial.begin(9600);
  //calling functions that design the screen
  keypadDesign();//draw the keypad
  textFieldDesign();//fraw the text inout field
  //draw the matrixes
  drawMatrix(1);
  drawMatrix(2);
}
//function takes in the an x and y location, string
//the bool  signifies if it is a line text or not
void writeText(String text, int textSize, int x, int y, bool isLine) {
  tft.setCursor(x, y);//sets the location
  tft.setTextSize(textSize);
  if (isLine)
    tft.println(text);
  else
    tft.print(text);
}

void loop(void) {
  if (ON_OFF) {
    keypadNumbersClicked();//checks if a keypad button was clicked on
    matrixCellClicked();//checks if a matrix cell was clicked on
  }
  else
    backButtonClicked();
}
//function draws the input button
//the display is designed to simulate a keypad
void keypadDesign() {
  //Border design
  tft.drawFastVLine(260, 0, 500, BLACK); //vertical line close to buttons
  tft.drawFastHLine(1, 447, 350, BLACK); //horizontal line close to button
  //button design
  int x = 290;
  int y = 13;
  int offset;
  // draw the buttons 1-9
  for (int i = 0; i < 10; i++) {
    storeMatrixData(x, (y + (i * 30)), &keypadButtonArray[i], keypadText[i], CYAN);
  }
  //draw the calculations buttons (+,-,x,*,CLR)
  for (int i = 0; i < 5; i++) {
    offset = i + 10;
    storeMatrixData(x, (y + (offset * 30)), &specialButtonArray[i], keypadText[offset], GREEN);
  }
  //This buttons were designed with differnt coordinates on the screen
  int temp[] = {40, 120, 210};
  y = (y +  (15 * 30 ));
  storeMatrixData(x, y , &specialButtonArray[5], "=", RED);// draw the equals button
  x = 1;
  for (int i = 6; i < 9; i++) {
    offset = i + 10;
    storeMatrixData((x + temp[i - 6]), y , &specialButtonArray[i], keypadText[offset], GREEN);
  }
}

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
//Design the cell of a matrix
void buttonsStructDesign(int xLocation, int yLocation, int matrixNo, int location) {
  int y, y_2; int x = 10;
  int w = 50;//width
  int h = 40;//height
  char * text = "";
  //Cell spacing
  int cellOffset = 40;
  int buttonOffset = 46;
  tft.setTextColor(BLACK, WHITE);
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
    case 3://result
      y = 30;
      writeText("RESULT", 2, 40, 20, false );//design for the matrix heading
      writeText( matrixC[location].text, 1, (x + (buttonOffset * xLocation)), ( y + (buttonOffset * yLocation)), false);
      break;
  }
  x = 10;
  //draw the cell
  tft.drawRect(x + (cellOffset * xLocation), y + (cellOffset * yLocation), cellOffset, h, BLACK);
}
//store the data of the matrix and display it
//store the text,x and y data of the button
//Except for the text x and y are not used in this code but would be useful for future updates
void storeMatrixData(int x, int y, buttonsStruct* store, char * text, int colour) {
  store->x = x ;
  store->y = y ;
  store->text = text;
  store->button.initButton(&tft, store->x,  store->y, 55, 30, WHITE, BLACK, colour, text, 2);
  store->button.drawButton(true);
}
//design for the textField
//used to display the numbers clicked on the keypad
void textFieldDesign() {
  tft.drawRect(195, 1, 60, 30, BLACK);
  tft.setTextColor(BLACK, WHITE);//used for writing over charcters(similar to erasing)
  writeText(textFieldText, 2, 195, 1, false);
}
void calculationType(String text) {
  tft.setTextColor(BLACK, WHITE);//used for writing over charcters(similar to erasing)
  writeText(text, 3, 40, ((35 * buttonsStructAmount) + 80), false);

}
//draws a button for the matrix
//we use buttons as the text input field since there are  no built in ones
void drawMatrixButton(Adafruit_GFX_Button button, int x, int y, char *text) {
  button.initButton(&tft, x, y, 55, 30, WHITE, BLACK, WHITE, text, 2);
  button.drawButton(true);
}
