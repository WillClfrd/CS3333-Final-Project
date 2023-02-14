#include "factor.h"

void primeFact(int a){
        int i;
        int primeFactCount = 0;
        printf("Prime Factors of %d: ", a);
        for(i = 1; i <= a; ++i){
                if((a%i == 0) && (primeCheck(i) == 1) && (i != 1)){
                        if(primeFactCount == 0){
                                printf("%d", i);
                                a /= i;
                                --i;
                        }
                        else{
                                printf(", %d", i);    
                                a /= i;
                                --i;    
                        }
                        ++primeFactCount;
                }
        }
        printf("\n\n");
}

void GCD(int a, int b){
        int i = a;
        int j = b;
        int r;
        int GCD;
        
        while(j != 0){
                r = i%j;
                i = j;
                j = r;
        }
        GCD = i;
        printf("GCD(%d,%d): %d\n\n", a, b, GCD);
}

void LCM(int a, int b){
        int i;
        int LCM;
        i = (a < b) ? a:b;
        for(i; i <= (a * b); ++i){
                if((i%a == 0) && (i%b == 0)){
                        printf("LCM(%d,%d): %d\n\n", a, b, i);
                        return;
                }
        }
}

int primeCheck(int a){
        int i;
        int factCount = 0;
        for(i = 1; i <= a; ++i){
                if(a%i == 0){
                        ++factCount;
                }
        }
        if(factCount > 2){
                return 0;
        }
        return 1;
}