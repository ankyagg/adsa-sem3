#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>

#define V 6

int min(int a, int b) {
    return (a < b) ? a : b;
}

int queue[V];
int head = 0, tail=0;

void enqueue(int x){
    queue[tail++]=x;
}

void dequeue(){
    return queue[head++];
}

