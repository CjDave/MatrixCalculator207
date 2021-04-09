//for calculations
void matrixCalculations(int choice) {
  //takes in a int performs an action based on the number
  int i = 4;
  for (int n = 0; (n < (buttonsStructAmount  * buttonsStructAmount )); n++)
  {
    switch (choice) {
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
  switch (choice) {
    case 4://special case, used to erase numbers from the text field by darwing a rectangle over it
      tft.fillRect(195, 1, 60, 30, WHITE);
      textFieldText = "";//reset the text to nothing
      textFieldDesign();
      break;
    case 5://result
      if (checkMatrix) {
        ON_OFF = 0;
        drawResult();
        drawMatrix(3);
      }
      break;
    case 6://2x2 matrix
      buttonsStructAmount = 2;
      setup();
      break;
    case 7://3x3 matrix
      buttonsStructAmount = 3;
      setup();
      break;
    case 8://4x4 mtrix
      buttonsStructAmount = 4;
      setup();
      break;
  }
}
bool checkMatrix() {
  for (int i = 0; i < buttonsStructAmount * buttonsStructAmount; i++)
    if (matrixC[i].text.length() == 0 || matrixC[i].text == " ")
      return false;
  return true;
}
void drawResult() {
  tft.fillRect(0, 0, 260, 420, WHITE);
  backButton.initButton(&tft, 100 , 280 , 55, 30, WHITE, BLACK, RED,  "<- " , 2);
  backButton.drawButton(true);
}
void backButtonClicked() {
  bool down = Touch_getXY();
  backButton.press(down && backButton.contains(pixel_x, pixel_y));
  if (backButton.justPressed())
  {
    ON_OFF = 1;
    setup();
  }
}
