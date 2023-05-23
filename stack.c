#include<stdio.h>
#define max 10
struct stack
{
    int a[max],top;
}s;
void push(struct stack *s,int n);
void print(struct stack *s);
void pop(struct stack *s,int n);
main()
{ 
    int n,num,i;
    s.top=-1;
    printf("Enter number of elements \n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
    scanf("%d",&num);
    push(&s,num);}
    print(&s);
}
void push(struct stack*s,int n)
{
    (s->top)++;
    if((s->top)==max-1)
    printf("Stack is overflow\n");
    s->a[s->top]=n;
    printf("%d is pushed successfully\n",n);
}
void pop(struct stack*s,int n)
{  
    if(s->top==-1)
    printf("Underflow\n");
    int p;
    p=s->a[s->top];
    s->top--;
    printf("%d is popped out\n",p);
}
void print(struct stack *s)
{
    int i;
    printf("Stack is\n");
    for(i=s->top;i>=0;i--)
    printf("%d  ",s->a[i]);
}