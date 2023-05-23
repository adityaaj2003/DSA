//Program to implement list
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
    NODE ptr=(NODE)malloc(sizeof(struct node));
    return ptr;
}
NODE insert(NODE first,int ele)
{
 NODE temp=create_node();
 temp->data=ele;
 temp->link=NULL;
 NODE cur=first;
 if(cur==NULL)
 return temp;
 while(cur->link!=NULL)
 cur=cur->link;
 cur->link=temp;
 return first;
}
NODE delete(NODE first)
{
  NODE temp=first;
  if(first==NULL)
  {
    printf("List is empty\n");
    return NULL;
  }
  if(first->link==NULL)
  return NULL;
  first=first->link;
  printf("Element deleted is %d\n",temp->data);
  free(temp);
  return first;
}
void display(NODE first)
{
    NODE cur=first;
    if(first==NULL)
    {
        printf("List is empty\n");
        return;
    }
    while(cur!=NULL)
    {
        printf("%d--",cur->data);
        cur=cur->link;
    }
    printf("\n");
}
main()
{
    NODE first=NULL;
    int choice,ele;
    while(1)
    {
      printf("Enter choice\n");
      scanf("%d",&choice);
      switch(choice)
      {
        case 1:printf("Enter element to insert\n");
               scanf("%d",&ele);
               first=insert(first,ele);
               break;
        case 2:first=delete(first);                                              
                break;
        case 3:printf("Contents are\n");
               display(first);
               break;
        case 4:exit(1);
        default:printf("Invalid\n");
      }
    }
}