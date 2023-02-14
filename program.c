#include "program.h"

int main(){
        userOpt userChoice;
        int matSize;
        int i;
        int a, b;

        do{
                printf("Main Menu:\n\tMatrix Operations - 1\n\tPrime, GCD, LCM - 2\n\tExit Program - 0\nSelection: ");
                scanf(" %d", &userChoice);
                switch(userChoice){
                        case opt1:
                                matrixMenu();
                                break;
                        case opt2:
                                factMenu();
                                break;
                        case exitVal:
                                break;
                        default:
                                printf("Invalid Entry");
                                break;
                }
        }while(userChoice != exitVal);
}

void matrixMenu(){
        int matSize;

        printf("Enter Matrix Size: ");
        scanf(" %d", &matSize);
        printf("\n");

        int** matA = (int**)malloc(sizeof(int*) * matSize);
        int** matB = (int**)malloc(sizeof(int*) * matSize);
        int i;
        int j;
        int x;
        char matFlag = 'A';
        for(i = 0; i < matSize; ++i){
                matA[i] = (int*)malloc(sizeof(int) * matSize);
                matB[i] = (int*)malloc(sizeof(int) * matSize);
        }       

        for(x = 0; x < 2; ++x){
                for(i = 0; i < matSize; ++i){
                        for(j = 0; j < matSize; ++j){
                                if(matFlag == 'A'){
                                        printf("Matrix %c[%d,%d]: ", matFlag, i, j);
                                        scanf(" %d", &matA[i][j]);
                                }
                                else{
                                        printf("Matrix %c[%d,%d]: ", matFlag, i, j);
                                        scanf(" %d", &matB[i][j]);
                                }
                        }
                }
                printf("\n");
                matFlag = 'B';
        }
        printf("\nA + B: \n");
        matrixAdd(matSize, matA, matB);
        printf("A - B: \n");
        matrixSub(matSize, matA, matB);
        printf("A * B: \n");
        matrixMult(matSize, matA, matB);
        printf("Determinant of A: %d\n\n", matrixDet(matSize, matA));
        printf("Determinant of B: %d\n\n", matrixDet(matSize, matB));
        printf("A Transverse: \n");
        matrixTran(matSize, matA);
        printf("B Transverse: \n");
        matrixTran(matSize, matB);
        printf("A Inverse: \n");
        matrixInv(matSize, matA);
        printf("B Inverse: \n");
        matrixInv(matSize, matB);

        for(i = 0; i < matSize; ++i){
                free(matA[i]);
                free(matB[i]);
        }  
        free(matA);
        free(matB);
}

void factMenu(){
        int a;
        int b;
        
        printf("A Value: ");
        scanf(" %d", &a);
        printf("B Value: ");
        scanf(" %d", &b);
        printf("\n");

        primeFact(a);
        primeFact(b);
        GCD(a,b);
        LCM(a,b);
}