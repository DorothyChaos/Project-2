#include <iostream>
#include <fstream>
#include <string>
#include <ncurses.h>
/**
* Prototype of main
*/
int main(const int argc, const char * argv []);
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
      //Window printed with file contents and functionalities implemented here
    }
    else {
     //error message or potentially blank file pulled up here
    } 
}
