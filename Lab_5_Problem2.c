//EECS 348 Lab 5 Problem 2
//Purpose: C code that allows user input and prints all possible combinations of scoring plays.
//Author: Anna Lin
//Last Modified: 14 Oct 2023

#include <stdio.h>
#include <math.h> //Used for flooring numeric values
#include <stdbool.h>

void possible_combo(int score){ 
    //Computes and prints all possible combinations of scoring plays for inputted score.

    printf("\nPossible Combinations of Scoring Play: \n");

    for (int a = 0; a <= floor(score/8); a++){  //iterates through each possible scoring for TD + 2pt
        for (int b = 0; b <= floor(score/7); b++){  //iterates through each possible scoring for TD + FG
            for (int c = 0; c <= floor(score/6); c++){  //iterates through each possible scoring for TB
                for (int d = 0; d <= floor(score/3); d++){  //iterates though each possible scoring for 3pt FG
                    for (int e = 0; e <= floor(score/2); e++){  //iterates though each possible scroing for Safety
                        if (8*a + 7*b + 6*c + 3*d + 2*e == score){  //prints scoring plays if the combination adds to the inputted score
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety \n", a, b, c, d, e);
                        }
                    }
                }
            }
        }
    }
    printf("\n");
}


int main(){
    int score;
    bool i = true;

    while (i){  //loop runs while i = True
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);    //stores user imput to the variable score

        if (score >= 2){
            possible_combo(score);  //computes possible combinations if score is greater or equal to 2
        }
        else{
            i = false;  //loop ends
        }
    }   
    return 0;
}