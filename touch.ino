//This part is for the input
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
