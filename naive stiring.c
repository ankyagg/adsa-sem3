#include <stdio.h>
#include <string.h>

void naive_string(char text[],char pat[]) {
    int n = strlen(text);
	int m = strlen(pat);
	int i, j;
	for(i=0; i<=n-m; i++) {
		for(j=0; j<m; j++) {
			if(text[i+j]!=pat[j]) {
				break;
			}
		}
		if(j==m) {
			printf("Pattern found at index %d",i);
		}
	}
}

int main(){
    char text[100],pat[100];
    printf("Enter the text:");
    gets(text);
    
    printf("Enter the patern to be checked: ");
    gets(pat);
    
    naive_string(text,pat);
    return 0;
}
