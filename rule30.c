#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GEN 100
#define ARR_LENGTH 181

void generation();
int ruleSet(int pos, int gen[]);

int currGeneration[ARR_LENGTH] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                                 ,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                                 ,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; 

int main() {
    //int length = sizeof(currGeneration) / sizeof(currGeneration[0]);
    int gen = 0;

    while (gen < MAX_GEN) {
        generation();
        gen++;
    }    

}

void generation() {
    int nextGeneration[ARR_LENGTH];
    int length = sizeof(currGeneration) / sizeof(currGeneration[0]);
    char str[182];

    for (int i = 1; i < length - 1; i++) {
        nextGeneration[i] = ruleSet(i, currGeneration);
    }

    memcpy(currGeneration, nextGeneration, sizeof(currGeneration));

    for (int i = 0; i < length; i++) {
        if (nextGeneration[i] == 0 || currGeneration[i] == 0) {
            char dot = '.';
            str[i] = dot;
        }
        else if (nextGeneration[i] == 1 || currGeneration[i] == 1) {
            char plus = '#';
            str[i] = plus;
        }
        printf("%c", str[i]);

    }
    printf("\n");
    
}

int ruleSet(int pos, int gen[]) {
    int result;
    int l = pos - 1;
    int c = pos;
    int r = pos + 1;

    if (gen[l] == 1 && gen[c] == 1 && gen[r] == 1) {
        result = 0;
    }
    else if (gen[l] == 1 && gen[c] == 1 && gen[r] == 0) {
        result = 0;
    }
    else if (gen[l] == 1 && gen[c] == 0 && gen[r] == 1) {
        result = 0;
    }
    else if (gen[l] == 1 && gen[c] == 0 && gen[r] == 0) {
        result = 1;
    }
    else if (gen[l] == 0 && gen[c] == 1 && gen[r] == 1) {
        result = 1;
    }
    else if (gen[l] == 0 && gen[c] == 1 && gen[r] == 0) {
        result = 1;
    }
    else if (gen[l] == 0 && gen[c] == 0 && gen[r] == 1) {
        result = 1;
    }
    else if (gen[l] == 0 && gen[c] == 0 && gen[r] == 0) {
        result = 0;
    }
    return result;
}
