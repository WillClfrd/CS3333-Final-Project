#ifndef __PROGRAM_H
#define __PROGRAM_H
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include "matrix.h"
#include "factor.h"

typedef enum USER_CHOICE_OPTIONS{
        exitVal = 0,
        opt1,
        opt2
}userOpt;

void matrixMenu();
void factMenu();
#endif