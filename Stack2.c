//Program to stack operations
#include<stdio.h>
#include<stdlib.h>
#define size 8
int s[size],top;
void push(int item)
{
    if(top==size-1) {
    printf("Stack is overflow\n");
    return;
     }
     top++;
    s[top]=item;
}
int pop()
{
   int item;
   if(top==-1)
   {
    printf("Stack is underflow\n");
    exit;
   }
   item=s[top];
   top--;
   return item;
}
void display()
{
    int i;
    for(i=top;i>=0;i--)
    printf(" %d",s[i]);
}
main()
{
    int choice,ele;
    while(1)
    {
        printf("Enter choice\n1-push 2-pop 3-print 4-Exit\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:printf("Enter element\n");
                   scanf("%d",&ele);
                   push(ele);
                   break;
            case 2:printf("Poped element is %d",pop());
                   break;
            case 3:printf("Elements of stack is\n");
                   display();
                   break;
            case 4:exit;
            default:printf("EROR\n");
        }
    }
}