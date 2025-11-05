#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int max(int a , int b){
    return (a>b) ? a:b;
}

void lcs_length(char *X,char *Y,int m , int n , int **dp){
    for(int i = 0 ; i<=m ; i++){
        for(int j = 0 ; j<=n;j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }
            else if(X[i-1]==Y[j-1]){
                dp[i][j] =  dp[i-1][j-1]+1;
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    printf("Length of LCS: %d",dp[m][n]);
}

void print_lcs(char *X,char *Y,int m , int n , int **dp){
    int length=dp[m][n];
    char *lcs = (char*)malloc((length+1)*sizeof(char));
    lcs[length] =  '\0';
    int i=m,j=n;
    int index=length-1;
    while(i>0 && j>0){
        if(X[i-1]==Y[j-1]){
            lcs[index]=X[i-1];
            i--,j--,index--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    printf("\nLCS: %s",lcs);
    free(lcs);
    
}

void lcs_solver(char *X,char *Y,int m , int n ){
    int **dp = (int **)malloc((m+1)*sizeof(int *));
    
    
    for(int a = 0;a<=m;a++){
        dp[a]=(int *)malloc((n+1)*sizeof(int));
    }
    lcs_length(X,Y,m,n,dp);
    print_lcs(X,Y,m,n,dp);
}

int main() {
    char X[100], Y[100]; 

    printf("Enter first string: ");
    scanf("%s", X);

    printf("Enter second string: ");
    scanf("%s", Y);
    int m = strlen(X);
    int n = strlen(Y);
    lcs_solver(X,Y,m,n);

}
