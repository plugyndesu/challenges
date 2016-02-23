#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* this program pretends a child is running back and forth on a wall of light switches.
As he passes the wall he flips them either on or off. They all start in the off position.
This calculates how many are on at the end of 4 rounds. */

int main(){
    //generate the seed for pseudorandom nums
    srand(time(NULL));
    char switchesInp[60];
    int switches;
    int rounds = 4;
    int switchesOn = 0;


    printf("How many light switches are on the wall? (including 0)\n");

    //grab input
    if (fgets(switchesInp, 60, stdin) != NULL){
        //convert input from str to int
        sscanf(switchesInp, "%d", &switches);

    }
    //declare arrays outside of if statement (compiler needs facts not chances)
    //also declare i, compiler doesn't allow for-loop declarations
    int switchesAmount[switches];
    int switchesCheck[switches];
    int i;

    //get the amount of switches and store Check for later use
    for (i = 0; i <= switches; i++){
        switchesAmount[i] = i;
        switchesCheck[i] = 0;
    }
    //declare f, unique to this for loop.
    int f = 0;
    for (f; f <= rounds; f++){
        int firstNum = rand() % switches;
        int secondNum = rand() % switches;

        //just for protection against errors
        //add if/else statement for cleaner use
        if  (firstNum > secondNum){
            //print out the first round of nums (forward and back)
            printf("%d---%d\n", secondNum, firstNum);

            //this is kinda cool,
            //use binary to count on or off!
            //oldskool l33t h4x0r
            //"You're either a one or zero, alive or dead."
            i = secondNum;
            for (i; i <= firstNum; i++){

                if (switchesCheck[i] == 0){
                    switchesCheck[i] = 1;
                }else{
                    switchesCheck[i] = 0;
                }
            }
        //same shit as the if statement, just checked if
        //second num is greater or equal to first num.
        }else{
            printf("%d---%d\n", firstNum, secondNum);

            i = firstNum;
            for (i; i <= secondNum; i++){
                if (switchesCheck[i] == 0){
                    switchesCheck[i] = 1;
                }else{
                    switchesCheck[i] = 0;
                }
            }
        }
    }
    //declare i again for this itty bitty
    //baby loop.
    i = 0;
    //grab the amount of switches that are on.
    for (i; i <= switches; i++){
        if (switchesCheck[i] == 1){
            switchesOn += 1;
        }
    }
    //print the on switches and end.
    printf("switches on:%d\n", switchesOn);
    return 0;
}
