#include <stdio.h>

#define MAX 100

typedef struct Job{
    char id[6];
    int deadline;
    int profit;
};

int minValue(int x,int y){
    if(x<y) return x;
}

int main(){
    int i,j;

    Job jobs[5] = {
    {"j1", 4, 200},
    {"j2", 5, 100},
    {"j3", 3,  20},
    {"j4", 2,  40},
    {"j5", 1,  20},
};

Job temp;

//no of jobs
int n = 5;

//sorting
for(i=0;i<n;i++){
    for(j=0;j<n-i;j++){
        if(jobs[j+1].profit>jobs[j].profit){
            temp = jobs[j+1];
            jobs[j+1] = jobs[j];
            jobs[j] = temp;
        }
    }
}

jobSequencingWithDeadline(jobs, n);
return 0;
}
void jobSequencingWithDeadlines(Job jobs[], int n){
    int i , j , k;
    int timeslot[MAX];
    int filledtimeslot = 0;

    int dmax=0;
    //to find maximum deadline
    for(i=0;i<n;i++){
        if(jobs[i].deadline>dmax){
            dmax = jobs[i].deadline;
        }
    }
    printf("dmax : %d",dmax);

    for(i=0;i<dmax;i++){
        timeslot[i+1] = -1;
    }

    for(i=1;i<= n ; i++){
        k = minValue(dmax,job[i-1].deadline);
    }

}
