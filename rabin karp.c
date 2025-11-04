#include <stdio.h>
#include <string.h>

#define prime_modulo 101

void rabin_karp(char T[],char P[]){
    int n = strlen(T);
    int m = strlen(P);
    int i,j;

    if(m>n || m==0){
        printf("the text is smaller than pattern or it is no");
        return;
    }

    int d = 256;

    int h =1;
    for (i=0;i<m-1;i++){
        h = (h*d) %
    }

}
