/*#include <stdio.h>*/

/*int MAXSIZE = 8;*/
/*int stack[8];*/
/*int top = -1;*/

/*int isempty() {*/

   /*if(top == -1)*/
      /*return 1;*/
   /*else*/
      /*return 0;*/
/*}*/

/*int isfull() {*/

   /*if(top == MAXSIZE)*/
      /*return 1;*/
   /*else*/
      /*return 0;*/
/*}*/

/*int peek() {*/
   /*return stack[top];*/
/*}*/

/*int pop() {*/
   /*int data;*/

   /*if(!isempty()) {*/
      /*data = stack[top];*/
      /*top = top - 1;*/
      /*return data;*/
   /*} else {*/
      /*printf("Could not retrieve data, Stack is empty.\n");*/
   /*}*/
/*}*/

/*int push(int data) {*/

   /*if(!isfull()) {*/
      /*top = top + 1;*/
      /*stack[top] = data;*/
   /*} else {*/
      /*printf("Could not insert data, Stack is full.\n");*/
   /*}*/
/*}*/

/*int main() {*/
   /*// push items on to the stack*/
   /*push(3);*/
   /*push(5);*/
   /*push(9);*/
   /*push(1);*/
   /*push(12);*/
   /*push(15);*/

   /*printf("Element at top of the stack: %d\n" ,peek());*/
   /*printf("Elements: \n");*/

   /*// print stack data*/
   /*while(!isempty()) {*/
      /*int data = pop();*/
      /*printf("%d\n",data);*/
   /*}*/

   /*printf("Stack full: %s\n" , isfull()?"true":"false");*/
   /*printf("Stack empty: %s\n" , isempty()?"true":"false");*/

   /*return 0;*/
/*}*/





#include <stdio.h>
#include <stdlib.h>

/* Data structure to represent a stack*/
struct stack
{
    int maxsize;     //define max capacity of the stack
    int top;
    int *items;
};

/* Utility function to initialize the stack*/
struct stack* newStack(int capacity)
{
    struct stack *pt = (struct stack*)malloc(sizeof(struct stack));

    pt->maxsize = capacity;
    pt->top = -1;
    pt->items = (int*)malloc(sizeof(int) * capacity);

    return pt;
}

/*Utility function to return the size of the stack*/
int size(struct stack *pt) {
    return pt->top + 1;
}

/* Utility function to check if the stack is empty or not*/
int isEmpty(struct stack *pt) {
    return pt->top == -1;                    // or return size(pt) == 0;
}

 /*Utility function to check if the stack is full or not*/
int isFull(struct stack *pt) {
    return pt->top == pt->maxsize - 1;       // or return size(pt) == pt->maxsize;
}

 /*Utility function to add an element `x` to the stack*/
void push(struct stack *pt, int x)
{
     /*check if the stack is already full. Then inserting an element would*/
     /*lead to stack overflow*/
    if (isFull(pt))
    {
        printf("Overflow\nProgram Terminated\n");
        exit(EXIT_FAILURE);
    }

    printf("Inserting %d\n", x);

     /*add an element and increment the top's index*/
    pt->items[++pt->top] = x;
}

 /*Utility function to return the top element of the stack*/
int peek(struct stack *pt)
{
     /*check for an empty stack*/
    if (!isEmpty(pt)) {
        return pt->items[pt->top];
    }
    else {
        exit(EXIT_FAILURE);
    }
}

 /*Utility function to pop a top element from the stack*/
int pop(struct stack *pt)
{
     /*check for stack underflow*/
    if (isEmpty(pt))
    {
        printf("Underflow\nProgram Terminated\n");
        exit(EXIT_FAILURE);
    }

    printf("Removing %d\n", peek(pt));

     /*decrement stack size by 1 and (optionally) return the popped element*/
    return pt->items[pt->top--];
}

/*int main()*/
/*{*/
     /*[>create a stack of capacity 5<]*/
    /*struct stack *pt = newStack(5);*/

    /*push(pt, 1);*/
    /*push(pt, 2);*/
    /*push(pt, 3);*/

    /*printf("The top element is %d\n", peek(pt));*/
    /*printf("The stack size is %d\n", size(pt));*/

    /*pop(pt);*/
    /*pop(pt);*/
    /*pop(pt);*/

    /*if (isEmpty(pt)) {*/
        /*printf("The stack is empty");*/
    /*}*/
    /*else {*/
        /*printf("The stack is not empty");*/
    /*}*/

    /*return 0;*/
/*}*/
