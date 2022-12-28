
#include "micromouseserver.h"
#include <cstdlib>

int count = 0; //count the amount of right turns in order to stay out of loop
int lTurns = 0;
int rTurns = 0; //in a 2x2 square, 3 turns are made in the same direction

void microMouseServer::studentAI()
{
    if ((lTurns==3)||(rTurns==3)) {
        foundFinish();
        lTurns = 0; //reseting variables after end is found
        rTurns = 0;
    }
    else if ((isWallLeft()==true)&&(isWallRight()==true)&&(isWallForward()==true)) {
        turnLeft(); //making a 180 degree turn
        turnLeft();
        moveForward();
        lTurns = 0; // reseting turn variables to zero because it wasn't 3 times in a row
        rTurns = 0;
    }
    else if ((isWallRight()==true)&&(isWallForward()==true)) { //if this condition is met 3 times in a row, the 2x2 square is found
        turnLeft();
        moveForward();
        lTurns++;
        rTurns=0;
    }
    else if ((isWallLeft()==true)&&(isWallForward()==true)) { //if this condition is met 3 times in a row, the 2x2 square is found
        turnRight();
        moveForward();
        rTurns++;
        lTurns=0;
    }
    else if ((isWallRight()==true)&&(isWallLeft()==false)) {
        if (count>20) { //keeping the mouse out of a loop
            turnLeft();
            moveForward();
            count=0;
        }
        else {
            count++;
            moveForward();
        }
    }
    else if ((isWallRight()==false)&&(isWallLeft()==false)) {
        if (count>20) { //keeping the mouse out of a loop
            turnLeft();
            moveForward();
            count=0;
        }
        else {
            count++;
            turnRight();
            moveForward();
        }
    }
    else if (isWallRight()==true) {
        moveForward();
        lTurns = 0; // reseting turn variables to zero because it wasn't 3 times in a row
        rTurns = 0;
    }
    else if (isWallRight()==false) {
        turnRight();
        moveForward();
        lTurns = 0; // reseting turn variables to zero because it wasn't 3 times in a row
        rTurns = 0;
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
