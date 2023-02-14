#include "matrix.h"
#include<stdbool.h>

void printMat(int row, int col, int** A){
        int i;
        int j;
        bool hasNegative = false;

        for(i = 0; i < row; ++i){
                for(j = 0; j < col; ++j){
                        if(A[i][j] < 0){
                                hasNegative = true;
                        }
                }
        }
        if(hasNegative == true){
                for(i = 0; i < row; ++i){
                        printf("|");
                        for(j = 0; j < col; ++j){
                                if(j == col - 1){
                                        if(A[i][j] < 0){
                                                printf("%d", A[i][j]);
                                        }
                                        else{
                                               printf(" %d", A[i][j]); 
                                        }
                                }
                                else if(j == 0){
                                        if(A[i][j] < 0){
                                                printf("%d ", A[i][j]);
                                        }
                                        else{
                                               printf("%d  ", A[i][j]); 
                                        }
                                }
                                else{
                                        if(A[i][j] < 0){
                                                printf("%d ", A[i][j]);
                                        }
                                        else{
                                               printf(" %d ", A[i][j]); 
                                        }
                                }
                        }
                        printf("|\n");
                }
        }
        else{
                for(i = 0; i < row; ++i){
                        printf("|");
                        for(j = 0; j < col; ++j){
                                if(j == col - 1){
                                        printf("%d", A[i][j]);
                                }
                                else{
                                        printf("%d ", A[i][j]);
                                }
                        }
                        printf("|\n");
                }
        }
        printf("\n");
}

void printMatDouble(int row, int col, double** A){
        int i;
        int j;

        if(A[0][0]/A[0][0] != 1){
                printf("Inverse Does Not Exist\n\n");
                return;
        }

        for(i = 0; i < row; ++i){
                printf("|");
                for(j = 0; j < col; ++j){
                        if(j == 0){
                                printf("%lf", A[i][j]);
                        }
                        else{
                                printf("\t%lf", A[i][j]);
                        }
                }
                printf("|\n");
        }
        printf("\n");
}

int matrixAdd(int size, int** A, int** B){
        int** C = (int**)malloc(sizeof(int*) * size);
        int i;
        int j;
        for(i = 0; i < size; ++i){
                C[i] = (int*)malloc(sizeof(int) * size);
        }  

        for(i = 0; i < size; ++i){
                for(j = 0; j < size; ++j){
                        C[i][j] = A[i][j] + B[i][j];
                }
        }
        printMat(size, size, C);

        for(i = 0; i < size; ++i){
                free(C[i]);
        }
        free(C);
        return 0;
}

int matrixSub(int size, int** A, int** B){
        int** C = (int**)malloc(sizeof(int*) * size);
        int i;
        int j;
        for(i = 0; i < size; ++i){
                C[i] = (int*)malloc(sizeof(int) * size);
        }   

        for(i = 0; i < size; ++i){
                for(j = 0; j < size; ++j){
                        C[i][j] = A[i][j] - B[i][j];
                }
        }
        printMat(size, size, C);

        for(i = 0; i < size; ++i){
                free(C[i]);
        }
        free(C);
        return 0;
}

int matrixMult(int size, int** A, int** B){
        int** C = (int**)malloc(sizeof(int*) * size);
        int i;
        int j;
        int z;
        int sum;
        for(i = 0; i < size; ++i){
                C[i] = (int*)malloc(sizeof(int) * size);
        } 

        for(i = 0; i < size; ++i){
                for(z = 0; z < size; ++z){
                        sum = 0;
                        for(j = 0; j < size; ++j){
                                sum += A[i][j] * B[j][z];
                        }
                        C[i][z] = sum;
                }
        }
        printMat(size, size, C);

        for(i = 0; i < size; ++i){
                free(C[i]);
        }
        free(C);
        return 0;
}

int matrixDet(int size, int** A){
        int j;
        int det = 0;
        if(size > 2){
                for(j = 0; j < size; ++j){
                        det += A[0][j] * powCalc(-1, 0 + j) * matrixDet(size - 1, resize(size, A, 0, j));
                }
        }
        else if(size == 1){
                det = A[0][0];
        }
        else{
                det = (A[0][0] * A[1][1]) - (A[0][1] * A[1][0]);
        }
        return det;
}

int matrixTran(int size, int** A){
        int i;
        int j;
        int** B = (int**)malloc(sizeof(int*) * size);
        for(i = 0; i < size; ++i){
                B[i] = (int*)malloc(sizeof(int) * size);
        }
        for(i = 0; i < size; ++i){
                for(j = 0; j < size; ++j){
                        B[j][i] = A[i][j];
                }
        }
        printMat(size, size, B);
        return 0;
}

int matrixInv(int size, int** A){
        double** I = (double**)malloc(sizeof(double*) * size);
        double** B = (double**)malloc(sizeof(double*) * size);
        int i;
        int j;
        bool swapFlag;

        for(i = 0; i < size; ++i){
                for(j = 0; j < size; ++j){
                        B[i] = (double*)malloc(sizeof(double) * size);
                        I[i] = (double*)malloc(sizeof(double) * size);
                }
        }
        for(i = 0; i < size; ++i){
                for(j = 0; j < size; ++j){
                        B[i][j] = A[i][j];
                        if(i == j){
                                I[i][j] = (double)1;
                        }
                        else{
                                I[i][j] = (double)0;
                        }
                }
        }

        do{
                swapFlag = false;
                for(i = 0; i < size; ++i){
                        for(j = 0; j < size; ++j){
                                if(i == j){
                                        if((B[i][j] - 1.00000 > 0.00001) || (B[i][j] - 1.00000 < -0.00001)){
                                                elemMatOp(B, I, size);
                                                swapFlag = true;
                                        }
                                }
                                else{
                                        if((B[i][j] > 0.00001) || (B[i][j] < -0.00001)){
                                                elemMatOp(B, I, size);
                                                swapFlag = true;
                                        }
                                }
                        }
                }
        }while(swapFlag);

        printMatDouble(size, size, I);
}

int** resize(int size, int** A, int row, int col){
        int i;
        int j;
        int y = 0;
        int z = 0;
        int** B = malloc(sizeof(int*) * (size - 1));
        for(i = 0; i < size; ++i){
                B[i] = (int*)malloc(sizeof(int) * (size - 1));
        }
        for(i = 0; i < size; ++i){
                z = 0;
                for(j = 0; j < size; ++j){
                        if((i != row) && (j != col)){
                                B[y][z] = A[i][j];
                                ++z;
                        }
                }
                if((i != row) && (j != col)){
                        ++y;
                }
        }
        return B;
}

int powCalc(int base, int power){
        int i;
        int prod = base;

        if(power == 0){
                return 1;
        }

        for(i = 1; i < power; ++i){
                prod *= base;
        }
        return prod;
}

void elemMatOp(double** A, double** I, int size){
        int y;
        int z;
        int n;
        double temp;
        double temp2;

        for(y = 0; y < size; ++y){
                temp = A[y][y];
                for(z = 0; z < size; ++z){
                        A[y][z] *= (1/temp);
                        I[y][z] *= (1/temp);
                }
                for(n = 0; n < size; ++n){
                        temp2 = A[n][y];
                        for(z = 0; z < size; ++z){
                                if(n == y){
                                        continue;
                                }
                                else{
                                        A[n][z] -= (A[y][z] * temp2); 
                                        I[n][z] -= (I[y][z] * temp2);
                                }
                        }
                }
        }
}