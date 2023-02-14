#ifndef __MATRIX_H
#define __MATRIX_H
#include<stdlib.h>
#include<stdio.h>
#define ERR_FLAG -99
#define IDZero 0.00
#define IDOne 1.00

int matrixAdd(int size, int** A, int** B);
int matrixSub(int size, int** A, int** B);
int matrixMult(int size, int** A, int** B);
int matrixDet(int size, int** A);
int matrixTran(int size, int** A);
int matrixInv(int size, int** A);
void printMat(int row, int col, int** A);
void printMatDouble(int row, int col, double** print);
int** resize(int size, int** A, int row, int col);
int powCalc(int base, int power);
void elemMatOp(double** A, double** I, int size);
#endif