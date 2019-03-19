#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

#include<time.h>
clock_t cstart, cend;
double cpu_time_used;

using namespace std;

struct AvlNode 
{
    AvlNode* left;
    AvlNode* right;
    int data;
    int height;
    int count;
};

void trav_inorder(AvlNode *tree);
AvlNode* GetNewNode(int);
AvlNode* Insert(AvlNode*,int);
AvlNode* Delete(AvlNode*,int);
int inorder(AvlNode*,int);
int height(AvlNode*);
int Count(AvlNode*);
AvlNode* rotateright(AvlNode*);
AvlNode* rotateleft(AvlNode*);
AvlNode* LR(AvlNode*);
AvlNode* RL(AvlNode*);
int BalanceFactor(AvlNode* );
bool Search(AvlNode*,int);

int main(int argc, char * argv[])
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    AvlNode* root = NULL;
    
    int n,m;
    //cin>>n;
    // cin>>m;
    
    int k,res,l;
    ifstream inFile,outFile,Files;
   int x;
   string s;
   cout<<"Enter Filename:-\n";
   cin>>s;
   inFile.open(s);
   int numberofvalue;
   cout<<"\nEnter number of values to insert or search or delete from file:-\n";
   cin>>numberofvalue;
   int mm=0;

 cstart = clock(); 
  while (inFile >> x) {
  if(mm==numberofvalue)
  {
    break;
  }
  // cout<<x;
        root=Insert(root,x);
         mm=mm+1;
}
cstart = clock()-cstart;
double time_taken = ((double)cstart)/CLOCKS_PER_SEC; 
printf("My function took %f seconds to insert! \n", time_taken);



int ss=0;
Files.open(s);
cstart = clock();  
while (Files >> x) 
{
  if(ss==numberofvalue)
  {
    break;
  }
  // np = create_node(x);
  Search(root, x);
  //cout<<"element deleted"<<i;
  ss=ss+1;
 // i++;
  // cout<<y;
}
cstart = clock()-cstart;
time_taken = ((double)cstart)/CLOCKS_PER_SEC; 
printf("My function took %f seconds to search! \n", time_taken);



mm=0;
outFile.open(s);
cstart = clock();  
while (outFile >> x) 
{
  if(mm==numberofvalue)
  {
    break;
  }
  // np = create_node(x);
  Delete(root, x);
  //cout<<"element deleted"<<i;
  mm=mm+1;
 // i++;
}
cstart = clock()-cstart;
time_taken = ((double)cstart)/CLOCKS_PER_SEC; 
printf("My function took %f seconds to delete! \n", time_taken);





    // while(n--)
    // {
    //     cin>>k;
    //     root=Insert(root,k);
    // }
    
    while(m--)
    {
        int q,a;
        cout<<"\nPress 1 space number to insert \nPress 2 space number to search \nPress 3 space number to delete:  ";
        cin>>q>>a;
        
        switch(q)
        {
            case 1: 
                    root=Insert(root,a);
                    break;
            case 2: 
                    if(Search(root,a)==true)
                        cout<<"1"<<endl;
                    else
                        cout<<"0"<<endl;
                    break;
            case 3: 
                    l=inorder(root,1);
                    cout<<l<<endl;
                    root=Delete(root,l);
                    break;
                
            default:
                    break;
        }        
        
    }
    // trav_inorder(root);
    
    return 0;
}

int height(AvlNode* T)
{
    int lheight,rheight;
    if(T==NULL)
        return 0;
    
    if(T->left==NULL)
        lheight=0;
    else
        lheight=1+T->left->height;
    
    if(T->right==NULL)
        rheight=0;
    else
        rheight=1+T->right->height;
    
    if(lheight>rheight)
        return lheight;
    else
    return rheight;
}

int Count(AvlNode* T)
{
    if(T==NULL)
        return 0;
    else if(T->left==NULL && T->right==NULL)
        T->count=1;
    else if(T->left==NULL)
        T->count=1+T->right->count;
    else if(T->right==NULL)
        T->count=1+T->left->count;
    else
        T->count=1+T->left->count+T->right->count;
    
    return T->count;
    
}

int BalanceFactor(AvlNode* T)
{
    int lheight,rheight;
    if(T==NULL)
        return 0;
    
    if(T->left==NULL)
        lheight=0;
    else
        lheight=1+T->left->height;
    
    if(T->right==NULL)
        rheight=0;
    else
        rheight=1+T->right->height;
    
    return lheight-rheight;
}

AvlNode* rotateleft(AvlNode *x)
{
    AvlNode *y;
    y=x->right;
    x->right=y->left;
    y->left=x;
    x->height=height(x);
    x->count=Count(x);
    y->height=height(y);
    y->count=Count(y);  
    return y;
}

AvlNode* rotateright(AvlNode *x)
{
    AvlNode *y;
    y=x->left;
    x->left=y->right;
    y->right=x;
    x->height=height(x);
    x->count=Count(x);
    y->height=height(y);
    y->count=Count(y);
    return y;
}

AvlNode* LR(AvlNode* T)
{
    T->left=rotateleft(T->left);
    T=rotateright(T);
    return T;
}

AvlNode* RL(AvlNode* T)
{
    T->right=rotateright(T->right);
    T=rotateleft(T);
    return T;
}

AvlNode* GetNewNode(int data)
{
    AvlNode* newNode = new AvlNode();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// To insert data in BST, returns address of root node
AvlNode* Insert(AvlNode* root,int data)
{
    if(root == NULL)
    { // empty tree
        root = GetNewNode(data);
    }
    else if(data > root->data)        // insert in right subtree
    {
        root->right=Insert(root->right,data);
        if(BalanceFactor(root)==-2)
        {
            if(data >root->right->data)
                root=rotateleft(root);
            else
                root=RL(root);
        }
        
    }
    else if(data<root->data)
        
    {
        root->left=Insert(root->left,data);
        if(BalanceFactor(root)==2)
        {
            if(data < root->left->data)
                root=rotateright(root);
            else
                root=LR(root);
        }
    }
    
    root->height=height(root);
    root->count=Count(root);
    
    return root;
}

AvlNode * Delete(AvlNode *root,int x)
{
    AvlNode *p;
    
    if(root==NULL)
    {
        return NULL;
    }
    else if(x > root->data)        // insert in right subtree
        {
            root->right=Delete(root->right,x);
            if(BalanceFactor(root)==2)
            {
                if(BalanceFactor(root->left)>=0)
                    root=rotateright(root);
                else
                    root=LR(root);
            }
        }
        else if(x<root->data)
            {
                root->left=Delete(root->left,x);
                if(BalanceFactor(root)==-2)    //Rebalancing
                {
                    if(BalanceFactor(root->right)<=0)
                        root=rotateleft(root);
                    else
                        root=RL(root);
                }
            }
            else
            {
                if(root->right!=NULL)   //data to be deleted is found
                {
                    p=root->right;    //delete its inorder succesor
                    
                    while(p->left!= NULL)
                        p=p->left;
                    
                    root->data=p->data;
                    root->right=Delete(root->right,root->data);
                    
                    if(BalanceFactor(root)==2)   //Rebalancing
                    {
                        if(BalanceFactor(root->left)>=0)
                            
                            root=rotateright(root);
                        else
                            root=LR(root);
                    }
                    
                }
                else
                    return(root->left);
            }
    root->height=height(root);
    root->count=Count(root);
    return root;
}


int inorder(AvlNode* root,int k)
{
    AvlNode* current = root;
    
    if(root==NULL)
    {
        return 1;
    }
    
    if(k==Count(current->left)+1)
    {
        return current->data;
    }
    else if(k>Count(current->left))
    {
        k=k-Count(current->left)-1;
        return inorder(current->right,k);
    }
    else
    {
        return inorder(current->left,k);
    }
}

void trav_inorder(AvlNode *tree)
{
    if (tree == NULL)
        return;
    trav_inorder (tree->left);
    cout<<tree->data<<"  ";
    trav_inorder (tree->right);
}

bool Search(AvlNode* root,int data)
{
    if(root == NULL)
    {
        return false;
    }
    else if(root->data == data)
    {
        return true;
    }
    else if(data <= root->data)
    {
        return Search(root->left,data);
    }
    else
    {
        return Search(root->right,data);
    }
}
