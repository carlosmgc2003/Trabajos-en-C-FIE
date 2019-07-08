
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node{
    int data;
    struct node * next;
};

typedef struct node Node;

typedef Node * NodePtr;

void createNode(NodePtr * stack,int data){
    NodePtr new = (NodePtr)malloc(sizeof(Node));
    new->data = data;
    if((*stack) == NULL){
        (*stack) = new;
    }
    else {
        new->next = (*stack);
        (*stack) = new;
    }
}

void deleteNode (NodePtr * stack){
    NodePtr garbage = *stack;
    *stack = (*stack)->next;
    free(garbage);
}

void printMax (NodePtr stack){
    if(stack != NULL){
        int aux = stack->data;
        stack = stack->next;
        while (stack != NULL){
            if (stack->data > aux)
                aux = stack->data;
        }
        printf("%d\n",aux);
    }
}

int main() {
    int opc, queries,data;
    NodePtr stack = NULL;
    scanf("%d",&queries);
    for(int i = 0; i < queries;i ++){
        scanf("%d",&opc);
        if(opc == 1)
            scanf("%d",&data);
        switch(opc){
            case 1: createNode(&stack,data);
                break;
            case 2: deleteNode(&stack);
                break;
            case 3: printMax(stack);
                break;
        }
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
