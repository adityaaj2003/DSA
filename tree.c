                //Program to implement tree
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
                NODE create_BST(NODE root,int ele)
                {
                    NODE cur=root,prev=NULL;
                    NODE temp=create_node();
                    temp->data=ele;
                    temp->right=temp->left=NULL;
                    if(root==NULL)
                    return root;
                    cur=root;
                    prev=NULL;
                    while(cur!=NULL)
                    {
                        prev=cur;
                        if(ele<cur->data)
                        cur=cur->left;
                        else
                        cur=cur->right;
                        if(ele<prev->data)
                        prev->left=temp;
                        else 
                        prev->right=temp;
                    }
                    return root;   
                }
                void inorder_BST(NODE root)
                {
                    if(root==NULL)
                    return;
                    inorder_BST(root->left);
                    printf("%d\t",root->data);
                    inorder_BST(root->right);
                }
                void postorder_BST(NODE root)
                {
                    if(root==NULL)
                    return;
                    postorder_BST(root->left);
                    postorder_BST(root->right);
                    printf("%d\t",root->data);
                }

                main()
                {
                    NODE root=NULL;
                    int choice,ele,key;
                    while(1)
                    {
                    printf("Enter choice\n");
                    scanf("%d",&choice);
                    switch(choice)
                    {
                        case 1:printf("Enter element to insert\n");
                            scanf("%d",&ele);
                            root=create_BST(root,ele);
                            break;
                        case 2: postorder_BST(root);                                              
                                break;
                        case 3:printf("Contents are\n");
                            inorder_BST(root);
                            break;
                        // case 4:printf("Enter element to insert\n");
                        //        scanf("%d",&ele);
                        //        first=insertfront(first,ele);
                        //        break;
                        // case 5:first=deleterear(first);                                              
                        //         break;
                        // case 6:printf("Enter element to search\n");
                        //        scanf("%d",&key);
                        //        printf("Enter element to insert\n");
                        //        scanf("%d",&ele);
                        //        first=insertleft(first,key,ele);
                        //        break;     
                        // case 7:printf("Enter element to search\n");
                        //        scanf("%d",&key);
                        //        printf("Enter element to insert\n");
                        //        scanf("%d",&ele);
                        //        first=insertright(first,key,ele);
                        //        break;    
                        case 8:exit(1);
                        default:printf("Invalid\n");
                    }
                    }
                }