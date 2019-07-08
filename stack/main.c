#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct stack{
    int data;
    struct stack * next;
};

typedef struct stack node;

typedef node * nodePtr;

nodePtr createNode (int data){
    nodePtr new = (nodePtr)malloc(sizeof(node));
    new->data = data;
    new->next = NULL;
    return new;
}

nodePtr push (nodePtr stack, int data,int * max){
    nodePtr newNode = createNode(data);
    newNode->next = stack;
    if (data >= * max){
        *max = data;
    }
    return newNode;
}

nodePtr pop (nodePtr stack){
    int aux = stack->data;
    nodePtr newTop = stack->next;
    //printf("%d",aux);
    free (stack);
    return newTop;
}

void printMax (int max){
    printf("%d",max);
}



int main() {

    int operations, option, data, max = 0;
    nodePtr head = NULL;
    scanf("%d",&operations);
    for (int i = 0;i < operations;i++){
        scanf("%d",&option);
        switch (option){
            case 1: scanf("%d",&data);
                head = push(head,data,&max);
                break;
            case 2: head = pop(head);
                break;
            case 3: printMax(max);
        }
    }
    return 0;
}
