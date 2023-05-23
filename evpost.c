#include<stdio.h>
#include<ctype.h>
#define size 10
struct stack
{
    int top;
    char stk[size];
};
typedef struct stack stck;
stck s;
void push(stck *s,char ch)
{
 s->top++;
 s->stk[s->top];
}
char pop(stck *s)
{
  char ch=s->stk[s->top];
  s->top++;
  return ch;
}
int evaluate(int op1,char ch,int op2)
{
    switch(ch)
    {
        
        case '+':return op1+op2;
        case '-':return op1-op2;
        case '*':return op1*op2;
        case '/':return op1/op2;

    }
}
main()
{
    char ch,post[size];
    int i,op1,op2,res;
    printf("Enter postfix expression\n");
    scanf("%s",post);
    while(post[i]!='\0')
    {
        ch=post[i];
        if(isdigit(ch))
        push(&s,ch-'0');
        else
        {
          op1=pop(&s);
          op2=pop(&s);
          res=evaluate(op1,post[i],op2);
          push(&s,res);
        }
    }

    printf("Result:%d\n",pop(&s));
}