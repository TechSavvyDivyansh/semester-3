#include<stdio.h>
#include<stdlib.h>

struct Node 
{
    int data;
    struct Node *left,*right;
}*root;


void create()
{
    struct Node *newnode,*parent,*temp;
    int n,data;
    printf("Enter the number of nodes:");
    scanf("%d",&n);
    
    for(int i=0;i<n;i++)
    {
        newnode=(struct Node*)malloc(sizeof(struct Node));
        printf("Enter data:");
        scanf("%d",&data);
        newnode->data=data;

        if(root==NULL)
        {
            root=newnode;
        }
        else
        {
            temp=root;
            while(temp!=NULL)
            {
                parent=temp;
                if(data<temp->data)
                {
                    temp=temp->left;
                }
                else
                {
                    temp=temp->right;
                }
            }
            if(parent->data>data)
            {
                parent->left=newnode;
            }
            else
            {
                parent->right=newnode;
            }
        }
    }
}

void delete()
{
    struct Node *temp,*parent,*succ,*parentsucc;
    int val;

    printf("Enter the value to be deleted:");
    scanf("%d",&val);

    temp=root;
    while(temp!=NULL && temp->data!=val)
    {
        parent=temp;
        if(temp->data>val)
        {
            temp=temp->left;
        }
        else
        {
            temp=temp->right;
        }
    }
    if(temp==NULL)
    {
        printf("Value not found\n");
    }
    else
    {
        if(temp->left==NULL && temp->right==NULL)
        {
            if(temp==parent->left)
            {
                parent->left=NULL;
            }
            else 
            {
                parent->right=NULL;
            }
            free(temp);
        }
        else if(temp->left==NULL)
        {
            if(temp==parent->left)
            {
                parent->left=temp->right;
            }
            else
            {
                parent->right=temp->right;
            }
        }
        else if(temp->right==NULL)
        {
            if(temp==parent->left)
            {
                parent->left=parent->left;
            }
            else
            {
                parent->right=temp->left;
            }
        }
        else
        {
            succ=temp->left;
            parentsucc=temp;
            while(temp->right!=NULL)
            {
                parentsucc=succ;
                succ=temp->right;
            }
            temp->data=succ->data;

            if(temp==parentsucc)
            {
                parentsucc->left=succ->left;
            }
            else
            {
                parentsucc->right=succ->left;
            }
        }
    }

}

void inorder(struct Node *temp)
{
    if(temp!=NULL)
    {
        inorder(temp->left);
        printf("%d ",temp->data);
        inorder(temp->right);
    }
}

void preorder(struct Node *temp)
{
    if(temp!=NULL)
    {
        printf("%d ",temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}
void postorder(struct Node *temp)
{
    if(temp!=NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        printf("%d ",temp->data);
    }
}

void mirror(struct Node *temp)
{
    struct Node *t1;
    if(temp!=NULL)
    {
        mirror(temp->left);
        mirror(temp->right);
        t1=temp->left;
        temp->left=temp->right;
        temp->right=t1;
    }
}

int externalNode(struct Node *temp)
{
    if(temp==NULL)
        return 0;
    else if(temp->left==NULL && temp->right==NULL)
        return 1;
    else
        return externalNode(temp->left)+externalNode(temp->right);
}

int internalNode(struct Node *temp)
{
    if(temp==NULL)
        return 0;
    else if(temp->left==NULL && temp->right==NULL)
        return 0;
    else 
        return internalNode(temp->left)+internalNode(temp->right)+1;
}

int totalNode(struct Node *temp)
{
    if(temp==NULL)
        return 0;
    else 
        return totalNode(temp->left)+totalNode(temp->right)+1;
}

int Height(struct Node *root) {
    int x, y;
    if (root == NULL) {
        return 0;
    }
    x = Height(root->left);
    y = Height(root->right);
    return x > y ? x + 1 : y + 1;
}



void main()
{
    create();
    delete();
    inorder(root);
    mirror(root);
    printf("\n");
    inorder(root);
    printf("\ninternalNode:%d\n",internalNode(root));
    printf("\nexternalNode:%d\n",externalNode(root));
    printf("\ntotalNode:%d\n",totalNode(root));
    printf("\nHeight:%d\n",Height(root));
}


