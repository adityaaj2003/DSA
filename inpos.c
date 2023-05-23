//Program to convert infix to postfix expression
#include<stdio.h>
#include<ctype.h>
#define size 15
struct stack
{
    int s[size],top;
};
struct stack st;
void push(struct stack *st,char ele)
{
    st->s[++(st->top)]=ele;
}
char pop(struct stack *st)
{
    return(st->s[(st->top)--]);
}
int precedence(char op)
{
    switch(op)
    {
        case '(':return 1;
        case '+':
        case '-':return 2;
        case '*':
        case '/':return 3;
    }
}
main()
{
    char post[size],in[size];
    st.top=-1;
    char ch,c;
    int i,j=0;
    printf("Enter infix expression\n");
    scanf("%s",in);
    i=0;
    while(in[i]!='\0')
    {
        ch=in[i++];
        if(ch=='(')
        push(&st,ch);
        else if(ch==')')
        {
            while(c=pop(&st)!='(')
            post[j++]=c;
        }
        else if(isalpha(ch)||isdigit(ch))
        post[j++]=ch;
        else
        {
            while((precedence(ch)<=precedence(st.s[st.top]))&&st.top!=-1)
              post[j++]=pop(&st);
            push(&st,ch);
        }
    }
    while(st.top!=-1)
      post[j++]=pop(&st);
    post[j]='\0';
    printf("Post fix expression is %s",post);
}