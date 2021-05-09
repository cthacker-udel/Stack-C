#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct node{

    int value;
    struct node *next;


};

struct node *HEAD = NULL;


int numNodes(){

    int count = 0;
    if(HEAD == NULL){
        return count;
    }
    else{
        struct node *currNode = HEAD;
        while(currNode != NULL){
            count++;
            currNode = currNode->next;
        }
        return count;
    }

}

void printStack(){

    if(HEAD == NULL){
        printf("\nStack is empty, no nodes to print\n");
    }
    else{
        struct node *currNode = HEAD;
        int nodeNum = 0;
        while(currNode != NULL){
            printf("\n\nNODE %d : %d\n\n",nodeNum++,currNode->value);
            currNode = currNode->next;
        }
    }

}


void push(int value){

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->value = value;
    if(HEAD == NULL){
        HEAD = newNode;
        newNode->next = NULL;
    }
    else{
        newNode->next = HEAD;
        HEAD = newNode;
    }
}


struct node * pop(){

    if(HEAD == NULL){
        printf("\nStack is empty, no contents to pop\n");
    }
    else if(numNodes() == 1){
        struct node *temp = HEAD;
        HEAD = NULL;
        return temp;
    }
    else{
        struct node *temp = HEAD->next;
        struct node *popped = HEAD;
        HEAD = NULL;
        HEAD = temp;
        return popped;
    }

}

void sumValuesOfStack(){

    if(HEAD == NULL){
        return;
    }
    else{
        int sum = 0;
        struct node *currHead = HEAD;
        while(currHead != NULL){
            sum += currHead->value;
            currHead = currHead->next;
        }
        printf("\nThe sum of the values of the nodes in the list is : %d\n",sum);
    }

}

void displayOdd(){

    int nodeCount = 0;
    struct node *currHead = HEAD;
    while(currHead != NULL){
        int nodeVal = currHead->value;
        if(nodeVal % 2 != 0){
            printf("\nNode %d has an odd value of %d\n",nodeCount,nodeVal);
        }
        nodeCount++;
        currHead = currHead->next;
    }

}

void displayEven(){

    int nodeCount = 0;
    struct node *currHead = HEAD;
    while(currHead != NULL){
        if(currHead->value % 2 == 0){
            printf("\nNODE %d has an even value of %d",nodeCount,currHead->value);
            nodeCount++;
            currHead = currHead->next;
        }
        else{
            nodeCount++;
            currHead = currHead->next;
        }
    }

}

void printMenu(){

    printf("\n\n~=~=~=MENU~=~=~=\n1)Display list\n2)Push node to stack\n3)Pop node from stack\n4)Exit program");

}


int main(void){

    int choice = 0;
    int nodevalue = 0;
    struct node *popresult;
    while(1){

        printMenu();
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printStack();
                break;
            case 2:
                printf("\nEnter the value to insert at the beginning of the stack\n");
                scanf("%d",&nodevalue);
                push(nodevalue);
                break;
            case 3:
                popresult = pop();
                printf("\nResult of pop was : %d\n",popresult->value);
                break;
            default:
                return 0;
        }

    }


}
