
#include "micromouseserver.h"

void microMouseServer::studentAI()
{
  if ((isWallLeft()==true)&&(isWallRight()==true)&&(isWallForward()==true)) {
        turnLeft(); //making a 180 degree turn
        turnLeft();
        moveForward();
  }
  else if ((isWallRight()==true)&&(isWallForward()==true)) { //if this condition is met 3 times in a row, the 2x2 square is found
        turnLeft();
        moveForward();
  }
  else if ((isWallLeft()==true)&&(isWallForward()==true)) { //if this condition is met 3 times in a row, the 2x2 square is found
        turnRight();
        moveForward();
        rTurns++;
  }
  else if (isWallRight()==true) {
        moveForward();
  }
  else if (isWallRight()==false) {
        turnRight();
        moveForward();
  }
  else {
        microMouseServer::studentAI(); //recursing to find the end of the maze
  } 
/*
 * The following are the eight functions that you can call. Feel free to create your own fuctions as well.
 * Remember that any solution that calls moveForward more than once per call of studentAI() will have points deducted.
 *
 *The following functions return if there is a wall in their respective directions
 *bool isWallLeft();
 *bool isWallRight();
 *bool isWallForward();
 *
 *The following functions move the mouse. Move forward returns if the mouse was able to move forward and can be used for error checking
 *bool moveForward();
 *void turnLeft();
 *void turnRight();
 *
 * The following functions are called when you need to output something to the UI or when you have finished the maze
 * void foundFinish();
 * void printUI(const char *mesg);
*/

}
