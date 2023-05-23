#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define size 10
struct stack
{
    int top;
    char stk[size];
}s;
int precedence(char ch)
{
    switch(ch)
    {
        case '(':return 1;
        case '*':
        case '/':return 2;
        case '+':
        case '-':return 3;
        default:return -1;
    }
}
void push(struct stack *s,char ch)
{
    (s->top)++;
    s->stk[s->top]=ch;
}
char pop(struct stack *s)
{
    char ch=s->stk[s->top];
    (s->top)--;
    return ch;
}
main()
{
    char infix[size],post[size],ch,c;
    int i=0,p=0;
    printf("Enter the infix expression\n");
    scanf("%s",infix);
    while(infix[i]!='\0')
    {
        ch=infix[i];
        if(ch=='(')
        push(&s,ch);
        else if(isalpha(ch)||isdigit(ch))
        post[p++]=ch;
        else if(ch==')')
        {
            while(c=pop(&s)!='(')
            post[p++]=c;
        }
        else{
            while((precedence(ch)<=precedence(pop(&s)))&&(s.top)==-1)
            post[p++]=pop(&s);
        //  push(&s,infix[i]);
        }
    }i++;
        if(s.top!=-1)
        post[p++]=pop(&s);
        // post[1]='h'; 
        post[p]='\0';
        printf("Postfix expression is %s\n",post);
    
}
