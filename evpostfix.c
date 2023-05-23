//Program to evaluate postfix expression
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define size 15
struct stack
{
    int top;
    char s[size];
};
void push(struct stack *st,int ele)
{
    st->s[++(st->top)]=ele;
}
int pop(struct stack *st)
{
    return(st->s[(st->top)--]);
}
int evaluate(int op1,char optr,int op2)
{
    switch(optr)
    {
        case '+':return(op1+op2);
        case '-':return(op1-op2);
        case '*':return(op1*op2);
        case '/':return(op1/op2);
    }
}
main()
{
    char ch,post[size];
    struct stack st;
    int i=0,op1,op2,res;
    st.top=-1;
    printf("Enter a postfix expression\n");
    scanf("%s",post);
    while(post[i]!='\0')
    {
        ch=post[i++];
        if(isdigit(ch))
         push(&st,ch-'0');
        else
        {
            op2=pop(&st);
            op1=pop(&st);
            res=evaluate(op1,ch,op2);
            push(&st,res);
        }
    }
    // printf("Result=%d",res);
    if(st.top==0)
    printf("Result=%d",pop(&st));
}