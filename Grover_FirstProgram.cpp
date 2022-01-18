/* Arizona State University
* EGR 201 Final Project.
* Team 6: Erin Grover, Jared Gates, Jakob Holder, Junda Gao, and Reem Bo Khamsheen.
* Random Question Generator for the STEM Bingo Game.
*/

/* Written by: Erin Grover

* This code contains the randomly generated questions, as well as the code for the Olimex 16x2
LCD screen.

* Changes can be made to this code to allow the changing of the questions.

* With more coding experience or thorough reading of the comments in this code, one will be
easily able to add new questions or even change the topics all together.

* In this code anything following "//" OR greyed out text like this text is considered a comment,
and will describe what that section of code is doing.
*/

/*
Due to the Olimex 16x2 LCD screen being of poor design and quality, the questions
themselves must be displayed in the Serial Monitor as the screen is incapable of a scroll
Function.

* This means that this Bingo Game Prototype WILL REQUIRE THE USE OF A COMPUTER
WITH THE ARDUINO IDE. (Open Serial monitor with the magnifying glass in the corner of the
Arduino IDE)

* If a second prototype was made, then a major change would be to use a more capable LCD
screen.
*/

/*
* TABLE OF CONTENTS
*
* CTRL+F to jump to the section by entering the code after the section title.
*
* Main Setup and Global Variables
* Game Setup Process
* Category Selection Process
* Topic 1 Questions
* Topic 2 Questions (Disabled to save memory)
* Topic 3 Questions (Disabled to save memory)
* Topic 4 Questions (Disabled to save memory)
* LCD Startup
* Welcome Message Function
* Game Menu Function
* Category Function (Game Process)
* Check Buttons Function
* Number Generator Function
* Question Asker Function
* Questions Number Display Function
* Question Write Function
*/

// This code is not perfected and could likely be changed for efficiency

/////////////////////////////////////////////////////////////////
// Main Setup and Global Variables
/////////////////////////////////////////////////////////////////

/*
This section of code is the setup of the code, and is used to initialize libraries and variables
used by the Arduino.
* All of these processes begin IMMEDIATELY once the Arduino is running.
* Other than the "NUMOFQUESTIONS" constant variable, DO NOT CHANGE ANYTHING IN
THIS SECTION.
*/

//This will include the library provided by the Olimex company that is REQUIRED for the LCD to run.
#include <LCD16x2.h>
//This will include the library provided by the Arduino IDE that is REQUIRED for the code to run.
#include <Wire.h>
//This initializes the LCD screen as the variable "lcd". Do not change this variable.
LCD16x2 lcd;
//This initializes the variable buttons, but does not contain a value. Do not change this variable.
int buttons;
//This initializes the constant, containing the number of questions per "round" the game will ask.
//Changing this is fine, but will require further changes listed throughout the code below.
const int NUMOFQUESTIONS = 25;
//This initializes the array "numbers[]" with a size equal to the "NUMOFQUESTIONS" Constant. Do not change this Array.
int numbers[NUMOFQUESTIONS];
//This initializes the "topic" variable and sets it equal to 0. This will be used later to determine the chosen topic. Do not change this variable.
int topic = 0;
//This initializes the "questionNum" variable and sets it equal to 1. This will be used later to determine what question the game is on. Do not change this variable.
int questionNum = 1;
//This initializes the array "questionsArray[]" with the size equal to the "NUMOFQUESTIONS" Constant. Do not change this Array.
char* questionsArray[NUMOFQUESTIONS];

/////////////////////////////////////////////////////////////////
// Game Setup Process
/////////////////////////////////////////////////////////////////

/*This section in the code is run first. It is the setup of the game menus and the LCD itself. DO
NOT CHANGE ANYTHING IN THIS SECTION.
*This Functions in this section are described in a later part of the code below.
*/
//This begins the setup Function and runs the other Functions below it.
void setup() {
    //This Function runs the lcdStart set of code, this process is explained below.
    lcdStart();
    //This Function runs the welcomeMenu set of code, this process is explained below.
    welcomeMessage();
    //This Function runs the runMenuScreen set of code, this process is explained below.
    runMenuScreen();
}
//End of the setup, move on to "void loop()" (Category Selection Process).

/////////////////////////////////////////////////////////////////
// Category Selection Process
/////////////////////////////////////////////////////////////////

/*This section of code begins after the "void setup()" Function from above.
*This code will continuously loop and contains every Function that runs the bingo game within
it.
*There are changes that can be made to this section in order to change the topics that the
game uses, and will be explained below.
*/

//This begins the loop Function that will run repeatedly, and contains the code for all of the game processes. Be careful when making changes. CTRL+Z to undo last change.
void loop() {
    //Initializes "buttons" variable to read the button state for each button. These button states are in Binary.
    //"& B1111" makes the Arduino read the binary values for the buttons with no extra numbers ("1" for button 1 rather than "0001"). Do not change this variable.
    buttons = (~lcd.readButtons()) & B1111;
    //This is a switch case, what it does is take the state of the buttons, and depending on which button is pressed, runs that set of code.
    switch (buttons) {
        //If button 1 is pressed.
        case B0001:
            //Run the runCategory Function. This is the first selectable topic.
            //Change what is INSIDE the parenthesis to change the topic.
            //What is inside the parenthesis is the "category" variable, and will be used later. If this topic is changed, some minor changes below will need to be done.
            //The numeric value is the length of the word inside the parenthesis (Including spaces and special characters). Example change below.
            //If the topic needs to be the human body then change "runCategory("Science?", 8);" to "runCategory("Human Body?", 11);".
            runCategory("Science?", 8);
            //Exits the switch case after the runCategory Function has completed.
            break;
        //If button 2 is pressed.
        case B0010:
            //Run the runCategory Function. This is the second selectable topic.
            //Change what is INSIDE the parenthesis to change the topic.
            //What is inside the parenthesis is the "category" variable, and will be used later. If this topic is changed, some minor changes below will need to be done.
            //The numeric value is the length of the word inside the parenthesis (Including spaces and special characters). Example change below.
            //If the topic needs to be the human body then change "runCategory("Technology?", 11);" to "runCategory("Human Body?", 11);".
            runCategory("Technology?", 11);
            //Exits the switch case after the runCategory Function has completed.
            break;
        //If button 3 is pressed.
        case B0100:
            //Run the runCategory Function. This is the third selectable topic.
            //Change what is INSIDE the parenthesis to change the topic.
            //What is inside the parenthesis is the "category" variable, and will be used later. If this topic is changed, some minor changes below will need to be done.
            //The numeric value is the length of the word inside the parenthesis (Including spaces and special characters). Example change below.
            //If the topic needs to be the human body then change "runCategory("Engineering?", 11);" to "runCategory("Human Body?", 11);".
            runCategory("Engineering?", 11);
            //Exits the switch case after the runCategory Function has completed.
            break;
        //If button 4 is pressed.
        case B1000:
            //Run the runCategory Function. This is the fourth/last selectable topic.
            //Change what is INSIDE the parenthesis to change the topic.
            //What is inside the parenthesis is the "category" variable, and will be used later. If this topic is changed, some minor changes below will need to be done.
            //The numeric value is the length of the word inside the parenthesis (Including spaces and special characters). Example change below.
            //If the topic needs to be the human body then change "runCategory("Math?", 5);" to "runCategory("Human Body?", 11);"
            runCategory("Math?", 5);
            //Exits the switch case after the runCategory Function has completed.
            break;
        //If multiple buttons are pressed simultaniously.
        default:
            //Exit Function. (Do nothing)
            break;
    }
}
//This will then begin again in a loop forever.

/////////////////////////////////////////////////////////////////
// Topic 1 Questions
/////////////////////////////////////////////////////////////////

/*This is the section of code that determines the questions that are asked based on the first
topic.
*If there have been changes based on the topics from the above Category Selection Process
Function, then changes here need to reflect the topics".
*/

//This begins the Function for the first topic questions.
void topicOneQuestions(){
    //This array "questionsArray[]" contains the questions that will be asked randomly. questionsArray[0] is the first possible question, questionsArray[1] is the second question, etc...
    //These questions are NOT asked in this order.
    //Change what is inside the parenthesis to change the questions.
    //Example change: questionsArray[0] = "How do you tie your shoes?";.
    questionsArray[0] = "What are the bumps on your tongue?";
    questionsArray[1] = "Which bones help chew food?";
    questionsArray[2] = "What is the 2nd part of the digestive system?";
    questionsArray[3] = "What is the largest organ?";
    questionsArray[4] = "Which organ carries oxygenated blood?";
    questionsArray[5] = "Which sense allows us to feel?";
    questionsArray[6] = "What is the 5th part of the Digestive system?";
    questionsArray[7] = "What are the two holes in your nose?";
    questionsArray[8] = "Which body parts allow smell?";
    questionsArray[9] = "Which body parts allow hearing?";
    questionsArray[10] = "What is the 1st part of the digestive system?";
    questionsArray[12] = "Which organ carries oxygen poor blood?";
    questionsArray[12] = "What side of your body is the stomach on?";
    questionsArray[13] = "Which side of your body is the liver on?";
    questionsArray[14] = "How many seconds does it take for food to go to the stomach?";
    questionsArray[15] = "What is the 4th part of the digestive system?";
    questionsArray[16] = "What shape is DNA?";
    questionsArray[17] = "How many lungs do we have?";
    questionsArray[18] = "Which organs allow sight?";
    questionsArray[19] = "Which organ pumps blood?";
    questionsArray[20] = "Which organ controls movement?";
    questionsArray[21] = "Which part of the body carries air to the lungs?";
    questionsArray[22] = "What is the 3rd part of the digestive system?";
    questionsArray[23] = "Which part of the body carries air to the lungs?";
}

/////////////////////////////////////////////////////////////////
// Topic 2 Questions (Disabled to save memory)
/////////////////////////////////////////////////////////////////

/*This is the section of code that determines the questions that are asked based on the first
topic.
*If there have been changes based on the topics from the above Category Selection Process
Function, then changes here need to reflect the topics".

//This begins the Function for the second topic questions.
void topicTwoQuestions(){
    //This array "questionsArray[]" contains the questions that will be asked randomly.
    questionsArray[0] is the first possible question, questionsArray[1] is the second question, etc...
    //These questions are NOT asked in this order.
    //Change what is inside the parenthesis to change the questions.
    //Example change: questionsArray[0] = "How do you tie your shoes?";.
    questionsArray[0] = "Technology#1";
    questionsArray[1] = "Technology#2";
    questionsArray[2] = "Technology#3";
    questionsArray[3] = "Technology#4";
    questionsArray[4] = "Technology#5";
    questionsArray[5] = "Technology#6";
    questionsArray[6] = "Technology#7";
    questionsArray[7] = "Technology#8";
    questionsArray[8] = "Technology#9";
    questionsArray[9] = "Technology#10";
    questionsArray[10] = "Technology#11";
    questionsArray[11] = "Technology#12";
    questionsArray[12] = "Technology#13";
    questionsArray[13] = "Technology#14";
    questionsArray[14] = "Technology#15";
    questionsArray[15] = "Technology#16";
    questionsArray[16] = "Technology#17";
    questionsArray[17] = "Technology#18";
    questionsArray[18] = "Technology#19";
    questionsArray[19] = "Technology#20";
    questionsArray[20] = "Technology#21";
    questionsArray[21] = "Technology#22";
    questionsArray[22] = "Technology#23";
    questionsArray[23] = "Technology#24";
}
*/

/////////////////////////////////////////////////////////////////
// Topic 3 Questions (Disabled to save memory)
/////////////////////////////////////////////////////////////////

/*This is the section of code that determines the questions that are asked based on the first
topic.
*If there have been changes based on the topics from the above Category Selection Process
Function, then changes here need to reflect the topics".

//This begins the Function for the third topic questions.
void topicThreeQuestions(){
    //This array "questionsArray[]" contains the questions that will be asked randomly.
    questionsArray[0] is the first possible question, questionsArray[1] is the second question, etc...
    //These questions are NOT asked in this order.
    //Change what is inside the parenthesis to change the questions.
    //Example change: questionsArray[0] = "How do you tie your shoes?";.
    questionsArray[0] = "Engineering#1";
    questionsArray[1] = "Engineering#2";
    questionsArray[2] = "Engineering#3";
    questionsArray[3] = "Engineering#4";
    questionsArray[4] = "Engineering#5";
    questionsArray[5] = "Engineering#6";
    questionsArray[6] = "Engineering#7";
    questionsArray[7] = "Engineering#8";
    questionsArray[8] = "Engineering#9";
    questionsArray[9] = "Engineering#10";
    questionsArray[10] = "Engineering#11";
    questionsArray[11] = "Engineering#12";
    questionsArray[12] = "Engineering#13";
    questionsArray[13] = "Engineering#14";
    questionsArray[14] = "Engineering#15";
    questionsArray[15] = "Engineering#16";
    questionsArray[16] = "Engineering#17";
    questionsArray[17] = "Engineering#18";
    questionsArray[18] = "Engineering#19";
    questionsArray[19] = "Engineering#20";
    questionsArray[20] = "Engineering#21";
    questionsArray[21] = "Engineering#22";
    questionsArray[22] = "Engineering#23";
    questionsArray[23] = "Engineering#24";
}
*/

/////////////////////////////////////////////////////////////////
// Topic 4 Questions (Disabled to save memory)
/////////////////////////////////////////////////////////////////

/*This is the section of code that determines the questions that are asked based on the first
topic.
*If there have been changes based on the topics from the above Category Selection Process
Function, then changes here need to reflect the topics".

//This begins the Function for the fourth/last topic questions.
void topicFourQuestions(){
    //This array "questionsArray[]" contains the questions that will be asked randomly.
    questionsArray[0] is the first possible question, questionsArray[1] is the second question, etc...
    //These questions are NOT asked in this order.
    //Change what is inside the parenthesis to change the questions.
    //Example change: questionsArray[0] = "How do you tie your shoes?";.
    questionsArray[0] = "Math#1";
    questionsArray[1] = "Math#2";
    questionsArray[2] = "Math#3";
    questionsArray[3] = "Math#4";
    questionsArray[4] = "Math#5";
    questionsArray[5] = "Math#6";
    questionsArray[6] = "Math#7";
    questionsArray[7] = "Math#8";
    questionsArray[8] = "Math#9";
    questionsArray[9] = "Math#10";
    questionsArray[10] = "Math#11";
    questionsArray[11] = "Math#12";
    questionsArray[12] = "Math#13";
    questionsArray[13] = "Math#14";
    questionsArray[14] = "Math#15";
    questionsArray[15] = "Math#16";
    questionsArray[16] = "Math#17";
    questionsArray[17] = "Math#18";
    questionsArray[18] = "Math#19";
    questionsArray[19] = "Math#20";
    questionsArray[20] = "Math#21";
    questionsArray[21] = "Math#22";
    questionsArray[22] = "Math#23";
    questionsArray[23] = "Math#24";
}
*/

/////////////////////////////////////////////////////////////////
// LCD Startup
/////////////////////////////////////////////////////////////////

/*This is the section of code that defines the lcdStart() Function.
*This Function is run IMMEDIATELY at the start of the "void setup()" Function.
*/

//This begins the Function for the Start-up of the LCD Screen and Serial Monitor.
void lcdStart(){
    //Delay changes the LCD startup time in milliseconds.
    delay(500);
    //Initializes the Wire Library.
    Wire.begin();
    //Sets the bitrate that the Arduino communicates with the PC at for the Serial Monitor.
    Serial.begin(9600);
    //Turns on the LCD backlight to full brightness.
    //Brightness is the values 0 to 255, 0 being off and 255 being fully bright.
    //This number can be adjusted to desired brightness.
    lcd.lcdSetBlacklight(255);
}

/*After this has completed, the next step inside of the "void setup()" is run, which will be the
Welcome Message Function (welcomeMessage();).
*/

/////////////////////////////////////////////////////////////////
// Welcome Message Function
/////////////////////////////////////////////////////////////////

/*This is the section of code that defines the welcomeMessage() Function.
*Any text in this section can be changed to suit the user.
*This Function is run IMMEDIATELY after the lcdStart Function.
*/

//This initializes the Function for the Welcome Message.
void welcomeMessage(){
    //Go to LCD location (1,1). This is the Top-Left corner.
    lcd.lcdGoToXY(1,1);
    //Print to LCD "Welcome to ASU's".
    //This text can be changed to anything that is less than or equal to 16 characters long (spaces and special characters included).
    lcd.lcdWrite("Welcome to ASU's");
    //Go to LCD location (1,2). This is the Bottom-Left corner.
    lcd.lcdGoToXY(1,2);
    //Print to LCD "STEM Bingo Game!".
    //This text can be changed to anything that is less than or equal to 16 characters long (spaces and special characters included).
    lcd.lcdWrite("STEM Bingo Game!");
    //Hold (Delay) for set interval in milliseconds.
    delay(1000);
}

/*After this has completed, the next step inside of the "void setup()" is run, which will be the
Game Menu Function (runMenuScreen();).
*/

/////////////////////////////////////////////////////////////////
// Game Menu Function
/////////////////////////////////////////////////////////////////

/*This is the section of code that defines the runMenuScreen() Function.
*SOME text in this section can be changed to suit the user.
*This Function is run IMMEDIATELY after the welcomeMessage Function.
*/

//Initialize Function for the menu screen.
void runMenuScreen() {
    // Clears the LCD.
    lcd.lcdClear();
    //Go to LCD location (7,1). This is the Top-Center.
    lcd.lcdGoToXY(7,1);
    //Print to LCD "Menu".
    lcd.lcdWrite("Menu");
    //Go to LCD location (1,2). This is above button 1.
    lcd.lcdGoToXY(1,2);
    //Print to LCD "S".
    //You can change this to the FIRST INITIAL of the Topics you have changed previously.
    lcd.lcdWrite("S");
    //Go to LCD location (6,2). This is above button 2.
    lcd.lcdGoToXY(6,2);
    //Print to LCD "T".
    //You can change this to the FIRST INITIAL of the Topics you have changed previously.
    lcd.lcdWrite("T");
    //Go to LCD location (11,2). This above button 3.
    lcd.lcdGoToXY(11,2);
    //Print to LCD "E".
    //You can change this to the FIRST INITIAL of the Topics you have changed previously.
    lcd.lcdWrite("E");
    //Go to LCD location (16,2). This is above button 4.
    lcd.lcdGoToXY(16,2);
    //Print to LCD "M".
    //You can change this to the FIRST INITIAL of the Topics you have changed previously.
    lcd.lcdWrite("M");
}

/*After this has completed, the next step inside of the "void setup()" is run, However, there is
nothing left to run, so the Arduino moves to the "void loop()" Function.
*/

/////////////////////////////////////////////////////////////////
// Category Function (Game Process)
/////////////////////////////////////////////////////////////////

/*This is the section of code that defines the runCategory() Function.
*It is here that the code starts to become more technical. Please pay careful attention to the
comments.
*SOME text in this section can be changed to suit the user.
*If changes were made previously in the code above, the some changes here are REQUIRED
in order to reflect that.
*This Function is run after a specific button press in the Category Selection Process or "void
loop()".
*/

//Initialize the runCategory Function.
//The parenthesis defines the format, in that the word is stored into the variable "category" and the integer is that words length (for screen location purposes) stored into the "len" variable.
void runCategory(char* category, int len) {
    //Clears the LCD.
    lcd.lcdClear();
    //Hold (Delay) for set interval in milliseconds.
    delay(500);
    //Go to the LCD location of X = [ (Total max character length for LCD (16) - Category word length / 2) + 1 ], Y = [ 1 ].
    //This prepares the "Cursor" location to center the Category word in the top row of the LCD. Do not change these values.
    lcd.lcdGoToXY(((16 - len) / 2) + 1,1);
    //Displays the word stored int the "category" variable that is given by the selected button in the Category Selection Process - Switch Case.
    //Example if the button 1 was pressed then the switch case runs with the Function "runCategory("Science?", 8);". Making category = "Science?" and len = 8.
    lcd.lcdWrite(category);
    //Go to LCD location (1,2). This is above button 1.
    lcd.lcdGoToXY(1,2);
    //Print to LCD "Yes".
    lcd.lcdWrite("Yes");
    //Go to LCD location (15,2). This is above button 4.
    lcd.lcdGoToXY(15,2);
    //Print to LCD "No".
    lcd.lcdWrite("No");
    //Hold (Delay) for set interval in milliseconds.
    delay(500);
    //Sets the buttons no equal not being pressed.
    buttons = B0000;
    //This while loop will check which category you have selected and begin the generation of questions based on your selection.
    while(buttons != B1000) {
        //Initialize the Function to check the button's state.
        //The loop will not continue until the checkButtons() Function is satisfied (A button is pressed).
        checkButtons();
        //If button 4 is not the button that ends the checkButtons() Function.
        //If "No" is not selected.
        if(buttons != B1000) {
            //If button 1 ended the checkbuttons() Function.
            //If selected "Yes".
            if(buttons == B0001) {
                //If the chosen category was Science.
                //The word inside the quotes need to reflect EXACTLY what changes you've made previously.
                //For example: if you changed runCategory("Science?", 8); to runCategory("Human Body?", 11);, then you also need to change "if(category == "Science?")" to if(category == "Human Body?").
                if(category == "Science?"){
                    //Set "topic" variable equal to 1.
                    //This will be used later.
                    topic = 1;
                    //Initialize the Number Generator Function that is detailed below.
                    numberGenerator();
                    //Initialize the topic one questions, listed above.
                    //This sets the questionsArray to contain the questions regarding topic one.
                    topicOneQuestions();
                    //Initialize the Function that will produce the questions, detailed below.
                    questionAsker();
                    //Exit Function.
                    break;
                }
                //If the chosen category was Technology.
                //The word inside the quotes need to reflect EXACTLY what changes you've made previously.
                //For example: if you changed runCategory("Technology?", 11); to runCategory("Human Body?", 11);, then you also need to change "if(category == "Technology?")" to if(category == "Human Body?").
                else if(category == "Technology?"){
                    //Set "topic" variable equal to 11.
                    //This will be used later.
                    topic = 11;
                    //Initialize the Number Generator Function that is described below.
                    numberGenerator();
                    //Initialize the topic two questions, listed above.
                    //This sets the questionsArray to contain the questions regarding topic two.
                    //Disabled to conserve memory.
                    //topicTwoQuestions();
                    //Initialize the Function that will produce the questions, detailed below.
                    questionAsker();
                    //Exit Function.
                    break;
                }
                //If the chosen category was Engineering.
                //The word inside the quotes need to reflect EXACTLY what changes you've made previously.
                //For example: if you changed runCategory("Engineering?", 11); to runCategory("Human Body?", 11);, then you also need to change "if(category == "Engineering?")" to if(category == "Human Body?").
                else if(category == "Engineering?"){
                    //Set "topic" variable equal to 111.
                    //This will be used later.
                    topic = 111;
                    //Initialize the Number Generator Function that is described below.
                    numberGenerator();
                    //Initialize the topic three questions, listed above.
                    //This sets the questionsArray to contain the questions regarding topic three.
                    //Disabled to conserve memory.
                    //topicThreeQuestions();
                    //Initialize the Function that will produce the questions, detailed below.
                    questionAsker();
                    //Exit Function.
                    break;
                }
                //If the chosen category was Math.
                //The word inside the quotes need to reflect EXACTLY what changes you've made previously.
                //For example: if you changed runCategory("Math?", 5); to runCategory("Human Body?", 11);, then you also need to change "if(category == "Math?")" to if(category == "Human Body?").
                else if(category == "Math?"){
                    //Set "topic" variable equal to 1111.
                    //This will be used later.
                    topic = 1111;
                    //Initialize the Number Generator Function that is described below.
                    numberGenerator();
                    //Initialize the topic four questions, listed above.
                    //This sets the questionsArray to contain the questions regarding topic four.
                    //Disabled to conserve memory.
                    //topicFourQuestions();
                    //Initialize the Function that will produce the questions, detailed below.
                    questionAsker();
                    //Exit Function.
                    break;
                }
                //Exit Function.
                break;
            }
            //If button 1 is NOT the button that ended the checkButtons() Function.
            //If the two middle buttons are pressed.
            //This Else statement will essentially reset the runCategory Function. (Return to top of this section)
            else {
                //Clears the LCD.
                lcd.lcdClear();
                //Go to LCD location (1,1). This is the Top-Left corner.
                lcd.lcdGoToXY(1,1);
                //Print to LCD "Invalid button".
                lcd.lcdWrite("Invalid button");
                //Go to LCD location (1,2). This is the Bottom-Left corner.
                lcd.lcdGoToXY(1,2);
                //Print to LCD "try again!".
                lcd.lcdWrite("try again!");
                //Hold (Delay) for set interval in milliseconds.
                delay(500);
                //Clears the LCD.
                lcd.lcdClear();
                //Hold (Delay) for set interval in milliseconds.
                delay(500);
                //Go to the LCD location of X = [ (Total max character length for LCD (16) - Category word length / 2) + 1 ], Y = [ 1 ].
                //This prepares the "Cursor" location to center the Category word in the top row of the LCD. Do not change these values.
                lcd.lcdGoToXY(((16 - len) / 2) + 1,1);
                //Displays the word stored int the "category" variable that is given by the selected button in the Category Selection Process - Switch Case.
                //Example if the button 1 was pressed then the switch case runs with the Function "runCategory("Science?", 8);". Making category = "Science?" and len = 8.
                lcd.lcdWrite(category);
                //Go to LCD location (1,2). This is above button 1.
                lcd.lcdGoToXY(1,2);
                //Print to LCD "Yes".
                lcd.lcdWrite("Yes");
                //Go to LCD location (15,2). This is above button 4.
                lcd.lcdGoToXY(15,2);
                //Print to LCD "No".
                lcd.lcdWrite("No");
                //Hold (Delay) for set interval in milliseconds.
                delay(500);
            }
        }
    }
    //If "No" is selected.
    //If Button 4 ends the While loop.
    //Rerun the Menu Screen Function.
    runMenuScreen();
    //Set the questionNum variable equal to 1.
    //This will essential restart the "void loop()" section.
    questionNum = 1;
}

/*The sections below are all referenced in the previous code.
*Some changes below are required if changes have been made above.
*/

/////////////////////////////////////////////////////////////////
// Check Buttons Function
/////////////////////////////////////////////////////////////////

/*This Function causes the code above to pause and check for a button to be pressed.
* The Function will not continue UNTIL a button is pressed.
* DO NOT CHANGE THIS SECTION.
*/

//Initializes the checkbuttons Function.
void checkButtons(){
    //Sets buttonstate to equal not pressed.
    buttons = B0000;
    //While loop will cycle until the buttonstate has a value (a button is pressed).
    while(!buttons) {
        //"& B1111" makes the Arduino read the binary values for the buttons with no extra numbers ("1" for button 1 rather than "0001"). Do not change this variable.
        buttons = (~lcd.readButtons()) & B1111;
    }
}

/////////////////////////////////////////////////////////////////
// Number Generator Function
/////////////////////////////////////////////////////////////////

/*This is the Function that generates the order in which the questions will be asked.
* It is done by randomly shuffling an array.
* DO NOT CHANGE THIS SECTION.
*/

//Array Shuffle code taken from http://stackoverflow.com/questions/33019637/arduino-language-shuffle-order-of-an-array
void numberGenerator() {
    unsigned char chosen[NUMOFQUESTIONS];
    unsigned char index, i2;
    for (index = 0; index < NUMOFQUESTIONS; index++)
        chosen[index] = 0;
    randomSeed(analogRead(A0));
    for (index = 0; index < NUMOFQUESTIONS; index++){
        int r = random(NUMOFQUESTIONS-index);
        for (i2 = 0; i2 <= r; i2++){
            r += chosen[i2];
        }
        chosen[r] = 1;
        numbers[index] = r;
    }
}

/////////////////////////////////////////////////////////////////
// Question Asker Function
/////////////////////////////////////////////////////////////////

/*This section will run to display the topic chosen and the question number that the game is on.
* It is what cycles between each question.
*/

//Initialize the Function that displays the Question Number and begins the generation of questions.
void questionAsker(){
    //While the question number does not equal the value of NUMOFQUESTIONS+1.
    while (questionNum != (NUMOFQUESTIONS+1)){
        //Created a Switch Case for the selected Topics.
        switch (topic){
            //If the topic variable is equal to 1 (Topic One).
            case 1:
                //Clears the LCD.
                lcd.lcdClear();
                //Go to LCD location (1,1). This is the Top-Left corner.
                lcd.lcdGoToXY(1,1);
                //Hold (Delay) for set interval in milliseconds.
                delay(100);
                //Write "Science Question ".
                //If changes above regarding the topics have changed then this needs to change reflecting that.
                //The phrase printed on this line must be less than 16 characters long (Including spaces and special characters).
                //Example: "Science Question " to "Humn Bdy Question".
                lcd.lcdWrite("Science Question ");
                //Go to LCD location (8,2). This is the Bottom-Center.
                lcd.lcdGoToXY(8,2);
                //Print to LCD the value stored in "questionNum".
                lcd.lcdWrite(questionNum);
                //Hold (Delay) for set interval in milliseconds.
                delay(1000);
                //Clears the LCD.
                lcd.lcdClear();
                //Hold (Delay) for set interval in milliseconds.
                delay(100);
                //Calls the questionNumGenerator Function detailed below.
                questionNumGenerator();
                //Exit Function.
                break;
            //If the topic variable is equal to 11 (Topic Two).
            case 11:
                //Clears the LCD.
                lcd.lcdClear();
                //Go to LCD location (1,1). This is the Top-Left corner.
                lcd.lcdGoToXY(1,1);
                //Hold (Delay) for set interval in milliseconds.
                delay(100);
                //Write "Tech Question ".
                //If changes above regarding the topics have changed then this needs to change reflecting that.
                //The phrase printed on this line must be less than 16 characters long (Including spaces and special characters).
                //Example: "Tech Question " to "Humn Bdy Question".
                lcd.lcdWrite("Tech Question ");
                //Go to LCD location (8,2). This is the Bottom-Center.
                lcd.lcdGoToXY(8,2);
                //Print to LCD the value stored in "questionNum".
                lcd.lcdWrite(questionNum);
                //Hold (Delay) for set interval in milliseconds.
                delay(1000);
                //Clears the LCD.
                lcd.lcdClear();
                //Hold (Delay) for set interval in milliseconds.
                delay(100);
                //Go to LCD location (1,1). This is the Top-Left corner.
                lcd.lcdGoToXY(1,1);
                //Hold (Delay) for set interval in milliseconds.
                delay(100);
                //Calls the questionNumGenerator Function detailed below.
                questionNumGenerator();
                //Exit Function.
                break;
            //If the topic variable is equal to 111 (Topic Three).
            case 111:
                //Clears the LCD.
                lcd.lcdClear();
                //Go to LCD location (1,1). This is the Top-Left corner.
                lcd.lcdGoToXY(1,1);
                //Hold (Delay) for set interval in milliseconds.
                delay(100);
                //Write "Eng Question ".
                //If changes above regarding the topics have changed then this needs to change reflecting that.
                //The phrase printed on this line must be less than 16 characters long (Including spaces and special characters).
                //Example: "Eng Question " to "Humn Bdy Question".
                lcd.lcdWrite("Eng Question ");
                //Go to LCD location (8,2). This is the Bottom-Center.
                lcd.lcdGoToXY(8,2);
                //Print to LCD the value stored in "questionNum".
                lcd.lcdWrite(questionNum);
                //Hold (Delay) for set interval in milliseconds.
                delay(1000);
                //Clears the LCD.
                lcd.lcdClear();
                //Hold (Delay) for set interval in milliseconds.
                delay(100);
                //Go to LCD location (1,1). This is the Top-Left corner.
                lcd.lcdGoToXY(1,1);
                //Hold (Delay) for set interval in milliseconds.
                delay(100);
                //Calls the questionNumGenerator Function detailed below.
                questionNumGenerator();
                //Exit Function.
                break;
            //If the topic variable is equal to 1111 (Topic Four).
            case 1111:
                //Clears the LCD.
                lcd.lcdClear();
                //Go to LCD location (1,1). This is the Top-Left corner.
                lcd.lcdGoToXY(1,1);
                //Hold (Delay) for set interval in milliseconds.
                delay(100);
                //Write "Math Question ".
                //If changes above regarding the topics have changed then this needs to change reflecting that.
                //The phrase printed on this line must be less than 16 characters long (Including spaces and special characters).
                //Example: "Math Question " to "Humn Bdy Question".
                lcd.lcdWrite("Math Question ");
                //Go to LCD location (8,2). This is the Bottom-Center.
                lcd.lcdGoToXY(8,2);
                //Print to LCD the value stored in "questionNum".
                lcd.lcdWrite(questionNum);
                //Hold (Delay) for set interval in milliseconds.
                delay(1000);
                //Clears the LCD.
                lcd.lcdClear();
                //Hold (Delay) for set interval in milliseconds.
                delay(100);
                //Go to LCD location (1,1). This is the Top-Left corner.
                lcd.lcdGoToXY(1,1);
                //Hold (Delay) for set interval in milliseconds.
                delay(100);
                //Calls the questionNumGenerator Function detailed below.
                questionNumGenerator();
                //Exit Function.
                break;
            //If no topic is selected (NOT POSSIBLE).
            default:
                //Exit Function.
                break;
        }
    }
}

/////////////////////////////////////////////////////////////////
// Questions Number Display Function
/////////////////////////////////////////////////////////////////

/*This Function will display the "Next, Prev, and End" buttons.
* It will also either end the game or move forward and backward, while displaying the
corresponding question.
*/

//Initialize the question number display Function.
void questionNumGenerator(){
    //Go to LCD location (13,2). This is above button 4.
    lcd.lcdGoToXY(13,2);
    //Print to LCD "Next".
    lcd.lcdWrite("Next");
    //If the "questionNum" variable is NOT equal to 1.
    if(questionNum != 1){
        //Go to LCD location (1,2). This is above button 1.
        lcd.lcdGoToXY(1,2);
        //Print to LCD "Prev".
        lcd.lcdWrite("Prev");
    }
    //If the "questionNum" variable is equal to 1.
    else{
        //Go to LCD location (1,2). This is above button 1.
        lcd.lcdGoToXY(1,2);
        //Print to LCD "End".
        lcd.lcdWrite("End");
    }
    //Run the questionWrite() Function.
    questionWrite();
    //Sets the button's equal to not being pressed.
    buttons = B0000;
    //This while loop will check which selected and begin the generation of questions based on your selection.
    while(buttons != B0001){
        //Initialize the Function to check the button's state.
        //The loop will not continue until the checkButtons() Function is satisfied (A button is pressed).
        checkButtons();
        //If button 1 is not the button that ends the checkButtons() Function.
        //If "End" is not selected.
        if(buttons != B0001){
            //If button 4 ends the checkbuttons() Function.
            if(buttons == B1000){
                //Add 1 to the variable "questionsNum".
                questionNum++;
                //Exit Function.
                break;
            }
            //If button 2 or 3 ends the checkButtons() Function.
            else{
                //Clears the LCD.
                lcd.lcdClear();
                //Go to LCD location (1,1). This is the Top-Left corner.
                lcd.lcdGoToXY(1,1);
                //Print to LCD "Invalid button".
                lcd.lcdWrite("Invalid button");
                //Go to LCD location (1,2). This is the Bottom-Left corner.
                lcd.lcdGoToXY(1,2);
                //Print to LCD "try again!".
                lcd.lcdWrite("try again!");
                //Hold (Delay) for set interval in milliseconds
                delay(500);
                //Clears the LCD.
                lcd.lcdClear();
                //Exit Function.
                break;
            }
        }
        //If button 1 is pressed AND the "questionNum" is not equal to 1.
        //This is the "Prev" loop.
        else if(questionNum != 1){
            //Subtract 1 from the variable "questionNum".
            questionNum--;
            }
            //If button 1 is pressed AND the "questionNum" variable is equal to 1.
            else{
            //Set questionNum equal to NUMOFQUESTIONS+1.
            //This will end the while loop, and the game will return to the menu screen.
            questionNum = NUMOFQUESTIONS+1;
        }
    }
}

/////////////////////////////////////////////////////////////////
// Question Write Function
/////////////////////////////////////////////////////////////////

//Initialize the Function that Writes the question in the Serial Monitor.
void questionWrite(){
    //Go to LCD location (1,1). This is the Top-Left corner.
    lcd.lcdGoToXY(1,1);
    //Print to LCD "ChkSerialMonitor".
    lcd.lcdWrite("ChkSerialMonitor");
    Serial.println(questionsArray[numbers[questionNum-1]]);
    //Hold (Delay) for set interval in milliseconds
    delay(500);
}