//Program to implement doubnly
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left,*right;
};
typedef struct node *NODE;
NODE create_node()
{
    NODE ptr=(NODE)malloc(sizeof(struct node));
    return ptr;
}
NODE insertrear(NODE first,int ele)
{
 NODE temp=create_node();
 temp->data=ele;
 temp->left=NULL;
 temp->right=NULL;
 NODE cur=first;
 if(cur==NULL)
 return temp;
 while(cur->right!=NULL)
 cur=cur->right;
 cur->right=temp;
 temp->left=cur;
 return first;
}
NODE insertfront(NODE first,int ele)
{
    NODE temp=create_node();
    temp->data=ele;
    temp->left=NULL;
    temp->right=NULL;
    if(first==NULL)
    return temp;
    temp->right=first;
    first->left=temp;
    return temp;
}
NODE deleterear(NODE first)
{
    NODE cur=NULL;
    NODE prev=NULL;
    if(cur==NULL)
    {
      printf("List is empty\n");
      return NULL;
    }
    while(cur->right!=NULL)
    {
      prev=cur;
      cur=cur->right;
    }
    prev->right=NULL;
    cur->left=NULL;
    printf("Element deleted is %d\n",cur->data);
    free(cur);
}
NODE deletefront(NODE first)
{
  NODE temp=first;
  if(first==NULL)
  {
    printf("List is empty\n");
    return NULL;
  }
  if(first->right==NULL)
  {
    printf("Element deleted is %d\n",first->data);
    free(first);
    return NULL;
  }
  first=first->right;
  first->left=NULL;
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
        cur=cur->right;
    }
    printf("\n");
}

NODE insertleft(NODE first,int key,int ele)
{
  NODE cur=first;
  NODE prev=NULL;
  NODE temp=create_node();
  temp->data=ele;
  if(first->right==NULL)
  return first;
  if(first==NULL)
  return NULL;
  while(cur->right!=NULL)
  {
    if(cur->data==key)
    break;
    prev=cur;
    cur=cur->right;
  }
  if(cur->data==key)
  {
    prev->right=temp;
    temp->left=prev;
    temp->right=cur;
    cur->left=temp;
    printf("Element inserted\n");
    return first;
  }
  else{
  printf("Element not inserted\n"); 
  return first;}
}
NODE insertright(NODE first,int key,int ele)
{
  NODE cur=first;
  NODE next=first->right;
  NODE temp=create_node();
  temp->data=ele;
  while(cur->right!=NULL)
  {
    if(cur->data==key)
    break;
    cur=cur->right;
  }
  next=cur->right;
  if(cur->data==key)
  {
    cur->right=temp;
    temp->left=cur;
    next->left=temp;
    temp->right=next;
    printf("Element inserted\n");
    return first;
  }
  else{
  printf("Element not inserted\n");
  return first;
  }
}
main()
{
    NODE first=NULL;
    int choice,ele,key;
    while(1)
    {
      printf("Enter choice\n");
      scanf("%d",&choice);
      switch(choice)
      {
        case 1:printf("Enter element to insert\n");
               scanf("%d",&ele);
               first=insertrear(first,ele);
               break;
        case 2:first=deletefront(first);                                              
                break;
        case 3:printf("Contents are\n");
               display(first);
               break;
        case 4:printf("Enter element to insert\n");
               scanf("%d",&ele);
               first=insertfront(first,ele);
               break;
        case 5:first=deleterear(first);                                              
                break;
        case 6:printf("Enter element to search\n");
               scanf("%d",&key);
               printf("Enter element to insert\n");
               scanf("%d",&ele);
               first=insertleft(first,key,ele);
               break;     
        case 7:printf("Enter element to search\n");
               scanf("%d",&key);
               printf("Enter element to insert\n");
               scanf("%d",&ele);
               first=insertright(first,key,ele);
               break;    
        case 8:exit(1);
        default:printf("Invalid\n");
      }
    }
}