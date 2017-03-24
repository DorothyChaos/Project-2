#include <panel.h> //for formatting
#include <iostream>
#include <fstream>
#include <string>
#include <ncurses.h>
/**
* Prototype of main
*/
int main(const int argc, const char * argv []);
/**
* F1 Menu method
*/
void f1menu(){
  
}
/**
* This program will create a text user interface
*/
int main(const int argc, const char * argv []){
  
  //Will need to be adapted to writing capabilities
  //Scrolling Functionality Variables
  string file, line1, line2;
  int count = 0, maxY = 0, maxX = 0, top = 0, bottom = 0;
  bool done = FALSE;
  
    //This will check whether a filename was included as an argument
    if(argc > 1){
      file = argv[1];
      //These open the file automatically
      ifstream fileStream1(file);
      ifstream fileStream2(file);
      if(!fileStream1){
        cout << "While opening the file, an error occurred" << endl; 
      }
      else {
        initscr(); //starts ncurses 
        noecho(); //so user input won't immediately show up--you can ask Prof Coterell
        cbreak(); //so we can read each char without /n--you can ask Prof Coterell
        
        while(!fileStream1.eof()){
          getline(fileStream1, line1);
          count++; //counting number of lines
        }
        string * stringArray = new string[count];
        for(int i = 0; i < count; i++){ //fills the array with file data
          getline(fileStream2, line2);
          stringArray[i] = line2;
        }
        //this gets the max length and width of the screen
        getmaxyx([name of window], maxY, maxX);
        bottom = maxY;
        for(int i = 0; i <= bottom && i < count; i++){
          printw(stringArray[i].c_str());
          printw("\n");
        }
        refresh(); //this will display the contents of stdscr window
        keypad([name of window], TRUE); //enables reading of function keys
        
        //potentially use raw or cbreak to make getch work properly?
        //Code to take input
        while(done != TRUE){
          int action = getch();
          switch(action){
            case KEY_UP:
                break;
            case KEY_DOWN:
                break;
            case KEY_LEFT:
                break;
            case KEY_RIGHT:
                break;
            case KEY_BACKSPACE:
                break;
            case 10: //this is for the enter key
              //stuff
               break;
            case ' ': //can use 032 if this doesn't work
                break; //spacebar was pressed
            case KEY_TAB:
                break;
            case KEY_F(1):
                //this will pull up another window
                //handles open, save, save as, and exit
                break;
            default: //anything to be written
              addch(action); //this outputs the character and advances the cursor 
                break;
          }
          refresh(); //may have to change this for specific window
        }
        endwin(); //end ncurses
        delete[] stringArray;
      }
    }
    else {
     //error message or potentially blank file pulled up here
    } 
}

//if we need copy paste capabilities: scanw() 
