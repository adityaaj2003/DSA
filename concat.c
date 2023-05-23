//Program to concatinate two lists
#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *link;
};
typedef struct node *NODE;
NODE create_node()
{
  NODE new=(NODE)malloc(sizeof(struct node));
  return new;
}
NODE insertrear(NODE first,int ele)
{
  NODE cur=first;
  NODE temp=create_node();
  temp->data=ele;
  temp->link=NULL;
   if(cur==NULL)
   return temp;
  while(cur->link!=NULL)
  {
    cur=cur->link;
  }
  cur->link=temp;
  return first;
}
void display(NODE first)
{
  NODE cur=first;
  while(cur!=NULL)
  {
    printf("%d->",cur->data);
    cur=cur->link;
  }
  printf("NULL\n");
}
NODE concatlist(NODE first,NODE second)
{
    if(first==NULL)
    {
        return second;
    }
    if(second==NULL)
    {
        return first;
    }
    NODE cur=first;
    while(cur->link!=NULL)
    {
        cur=cur->link;
    }
    cur->link=second;
    return first;
}
main()
{
    NODE first=NULL,second=NULL,result=NULL;
    int ele,choice;
    while(1)
    {
        printf("Enter the choice\n1-Insert for first 2-Insert for second 3-Display first 4-Display second 5-Concatinate 6-Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter number to insert\n");
                   scanf("%d",&ele);
                   first=insertrear(first,ele);
                   break;
            case 2:printf("Enter number to insert\n");
                   scanf("%d",&ele);
                   second=insertrear(second,ele);
                   break;
            case 3:printf("Contents are\n");
                   display(first);
                   break;
            case 4:printf("Contents are\n");
                   display(second);
                   break;
            case 5:result=concatlist(first,second);
                   printf("Contents are\n");
                   display(result);
                   break;
            case 6:exit(1);
            default:printf("Invalid choice\n");
                    break;
        }
        
    }
}