#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

//x and y are two pointers to the starting of memory of string arrays and m and n are their respective lenghths
void lcs_length(char *X, char *Y, int m , int n , int **dp){
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
            else if(X[i-1]==Y[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    printf("length of LCS = %d\n",dp[m][n]);
}

void print_lcs(char *X,char *Y, int m,int n, int **dp){
    int length = dp[m][n];
    if(length==0){
        printf("Dosen't Exist");
        return;
    }
    char *lcs=(char*)malloc((length+1)*sizeof(char));
    if(lcs==NULL) return;
    lcs[length] = '\0';
    int i = m, j = n;
    int index = length - 1;
    while(i>0 && j>0){
        if(X[i-1]==Y[j-1]){
            lcs[index] = X[i-1];
            i--;
            j--;
            index--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    printf("LCS: %s\n", lcs);
    free(lcs);
}

void solve_lcs(char* X, char* Y){
    int m = strlen(X);
    int n = strlen(Y);

    int **dp = (int **)malloc((m+1)*sizeof(int *));
    if(dp==NULL) return 1;
    for(int i = 0;i<=m;i++){
        dp[i] = (int **)malloc((n+1)*sizeof(int *));
    }
    lcs_length(X,Y,m,n,dp);
    print_lcs(X,Y,m,n,dp);
}

int main() {
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    int m = strlen(X);
    int n = strlen(Y);
    solve_lcs(X,Y);

}
