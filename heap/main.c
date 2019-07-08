#include <stdio.h>
#include <stdlib.h>

struct heap{
    long DATA[10000000];
    int last;
};

typedef struct heap minHeap;

void swap (long * A, long * B){
long aux;
aux = *A;
*A = *B;
*B = aux;
return;
}

void addData (minHeap * heap,long data){
heap->DATA[heap->last] = data;
int auxA = heap->last;
int auxB = auxA / 2;
while (auxA != auxB){
    if(heap->DATA[auxB] > heap->DATA[auxA]){
        swap (&heap->DATA[auxB],&heap->DATA[auxA]);
    }
    else {
        auxA = auxB;
        auxB = auxB / 2;
    }
}
heap->last ++;
return;
}

int searchData (minHeap * heap, long data,int pos){
   if (heap->DATA[pos] != data && pos < heap->last){
       return searchData(heap,data,pos = pos*2+1);
       return searchData(heap,data,pos = pos*2+2);
   }
   else{
        return pos;
   }
}


void delData (minHeap * heap, long data){
    int i;
    int oldLast = heap->last;
    i = searchData(heap,data,0);
    heap->last = i;
    while (i < oldLast - 1){
        addData(heap,heap->DATA[i + 1]);
        i ++;
    }
    return;
}


void printMin (minHeap * heap){
printf("%li\n",heap->DATA[0]);
return;
}

int main()
{
    minHeap * H = (minHeap *)malloc(sizeof(minHeap));
    H->last = 0;
    int  opt;
    long j,data,queries;
    scanf("%li",&queries);
    for (j = 0;j < queries; j ++){
        scanf("%d",&opt);
        switch (opt){
        case 1: scanf("%li",&data);
        addData(H,data);
        break;
        case 2: scanf("%li",&data);
        delData(H,data);
        break;
        case 3: printMin(H);
        break;
        }
    }
    return 0;
}
