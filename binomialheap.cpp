#include<stdio.h>
#include<malloc.h>
#include<time.h>

#include<bits/stdc++.h>
clock_t cstart, cend;
 double cpu_time_used;
using namespace std;


//node structure
struct node 
{
    int n;
    int degree;
    struct node* parent;
    struct node* child;
    struct node* sibling;
}*H=NULL,*Hr=NULL;


//node creation 
struct node* create_node(int k) 
{
    struct node* p;
    //p = (struct node*) malloc(sizeof(struct node));
    p=new node;
    p->n = k;
    return p;
}


//heap initialisation 
struct node* initialise_heap() 
{
    struct node* np;
    np = NULL;
    return np;
}


// print function for Binomial Tree 
void printTree(node *h) 
{ 
    while (h) 
    { 
        cout << h->n << " "; 
        printTree(h->child); 
        h = h->sibling; 
    }
  //  cout<<endl; 
} 
 
//merging two heaps 
struct node* simply_merging(struct node* H1, struct node* H2) 
{
	

    // cout<<"\nin simply merging\n";
    // cout<<"unmerged (H1): ";
    //             printTree(H1);

    // cout<<"unmerged (Hr): ";
    //             printTree(H2);
     
    // cout<<endl;


    struct node* H = initialise_heap();
    struct node* y;
    struct node* z;
    struct node* a;
    struct node* b;
    y = H1;
    z = H2;
   
        if (y!=NULL && z != NULL && y->degree <= z->degree)
            H = y;
        else if (y!=NULL && z != NULL && y->degree > z->degree)
            H = z;
        else if (z==NULL )
            H = y;
        else
            H = z;
    
    while (y != NULL && z != NULL) 
    {
        if (y->degree < z->degree) 
        {
            y = y->sibling;
        }
        else if(z->sibling && z->degree<z->sibling->degree && z->sibling->degree < y->degree)
        {
           z = z->sibling;	
        } 
        else if (y->degree == z->degree) 
        {
            a = y->sibling;
            y->sibling = z;
            y = a;
        } 
        else 
        {
            b = z->sibling;
            z->sibling = y;
            z = b;
        }
    }


    
     // cout<<"\nin simply merging\n";
    //cout<<"merged heap is (H1+Hr): ";
            //    printTree(H);
            //    cout<<endl;

  

   
    return H;
}

//merging two same degree nodes
int linking_same_degnodes(struct node* y, struct node* z) 
{
    y->parent = z;
    y->sibling = z->child;
    z->child = y;
    z->degree = z->degree + 1;
}
 

// union of two heaps 
struct node* union_of_heaps (struct node* H1, struct node* H2) 
{
   // cout<<"union_of_heaps";
    
    struct node* prev_x;
    struct node* next_x;
    struct node* x;
    struct node* H = initialise_heap();
    // struct node* H = new node;
    H = simply_merging(H1, H2);
    if (H == NULL)
        return H;
   
    prev_x = NULL;
    x = H;
    next_x = x->sibling;
   
    while (next_x != NULL) 
    {
        if ((x->degree != next_x->degree) ) 
        {
            prev_x = x;
            x = next_x;
        } 
        else if ((x->degree == next_x->degree) && (next_x->sibling != NULL) && (next_x->sibling)->degree == x->degree)
        {
             prev_x = x;
             x = next_x;
        }
        else 
        {
            if (x->n <= next_x->n) 
            {
                x->sibling = next_x->sibling;
                linking_same_degnodes(next_x, x);
            } 
            else 
            {
                if (prev_x == NULL)
                { 
                    H = next_x;
                }
                else
                {
                    prev_x->sibling = next_x;
                }

                linking_same_degnodes(x, next_x);
                x = next_x;
            }
        }
        
        next_x = x->sibling;
    }
    return H;
}

//insert operation 
struct node* insert(struct node* H, struct node* x) 
{
     struct node* H1 = initialise_heap();
    // struct node* H1 = new node;

    x->parent = NULL;
    x->child = NULL;
    x->sibling = NULL;
    x->degree = 0;
    H1 = x;
    H = union_of_heaps(H, H1);
    return H;
}


//printing only root elements 
int display_root_elements(struct node* H) 
{
    struct node* p;
    if (H == NULL) {
        printf("\nheap is empty");
        return 0;
    }
    printf("\nroots are-\n");
    p = H;
    while (p != NULL) {
        printf("%d", p->n);
        cout<<"("<<p->degree<<")";
        if (p->sibling != NULL)
            printf("-->");
        p = p->sibling;
    }
    printf("\n");
}
 
//reverting children in list once root deleted 
void reverting_list(struct node* y) 
{
    if (y->sibling != NULL) {
        reverting_list(y->sibling);
        (y->sibling)->sibling = y;
    } 
    else 
    {
        Hr = y;
    }
}


//extracting min node operation 
struct node* extract_min_node(struct node* H1) 
{
    int min;
    struct node* t = NULL;
    struct node* x = H1;
    //struct node *Hr;
    struct node* p;
  
    Hr = NULL;
    if (x == NULL) 
    {
        printf("\nNode not found");
        return x;
    }

    p = x;
    
    ///
    min=p->n;

    while (p->sibling != NULL) 
    {
        if ((p->sibling)->n < min) 
        {
            min = (p->sibling)->n;
            t = p;
            x = p->sibling;
        }

        p = p->sibling;
    }
    
  
    ///removing the extracred node from sibling
    ///and making next to extracted as sibling
    if (t == NULL && x->sibling == NULL)
        H1 = NULL;
    else if (t == NULL)
        H1 = x->sibling;
    else if (t->sibling == NULL)
        t = NULL;
    else
        t->sibling = x->sibling;


   
    
    if (x->child != NULL) 
    {
        reverting_list(x->child);
        (x->child)->sibling = NULL;

    }

    

     if(!H1)
     {
     	swap(H1,Hr);
     }

     // cout<<"extracted heap is (Hr): ";
     //            printTree(Hr);
     //            cout<<endl;

     // cout<<"extracted heap is (H1): ";
     //            printTree(H1);
     //            cout<<endl;


    
     H = union_of_heaps(H1, Hr);

    return x;
}
 
//search operation 
struct node* search_element(struct node* H, int k) 
{
    struct node* x = H;
    struct node* p = NULL;
    if (x->n == k) {
        p = x;
        return p;
    }
    if (x->child != NULL && p == NULL) {
        p = search_element(x->child, k);
    }
 
    if (x->sibling != NULL && p == NULL) {
        p = search_element(x->sibling, k);
    }
    return p;
}
 
int decrease_key(struct node* H, int i, int k) 
{
    int temp;
    struct node* p;
    struct node* y;
    struct node* z;
    p = search_element(H, i);
    if (p == NULL) {
        // printf("\ninvalid choice\n");
        return 0;
    }
    if (k > p->n) {
        printf("\nnew key cannot be greater than previous key ");
        return 0;
    }
    p->n = k;
    y = p;
    z = p->parent;
    while (z != NULL && y->n < z->n) {
        temp = y->n;
        y->n = z->n;
        z->n = temp;
        y = z;
        z = z->parent;
    }
    // printf("\nkey reduced!");
}
 
int delete_key(struct node* H, int k) 
{
    struct node* np;
    if (H == NULL) {
        printf("\nheap is empty");
        return 0;
    }
 
    decrease_key(H, k, -1000);
    np = extract_min_node(H);
    if (np != NULL)
    {
        // printf("\nnode deleted");
    }
}
  
// print function for binomial heap 
void printHeap(struct node *H) 
{ 
    while(H!=NULL)
    {
      
            printTree(H); 
        

        H=H->sibling; 
    }
} 


int main(int argc, char * argv[]) {
    int i, n, m, option,nkey;
    struct node* p;
    struct node* np;
    char ch;
    ifstream inFile,outFile,Files;
   int x;
   string s;
   cout<<"Enter Filename:-\n";
   cin>>s;
   // if (argc == 2) {
        inFile.open(s);
    // }
   // inFile.open("samplerand.txt");
    cout<<"\nEnter number of values to insert or search or delete from file:-\n";
   int numberofvalue;
   cin>>numberofvalue;
   int mm=0;
  

cstart = clock();  
while (inFile >> x) 
{
  if(mm==numberofvalue)
  {
    break;
  }
  np = create_node(x);
  H = insert(H, np);
  mm=mm+1;
}
cstart = clock()-cstart;
double time_taken = ((double)cstart)/CLOCKS_PER_SEC; 
printf("My function took %f seconds to insert! \n", time_taken);


// Files.open(s);
//  i=0;
// cstart = clock(); 
// mm=0; 
// while (Files >> x) 
// {
//   if(mm==numberofvalue)
//   {
//     break;
//   }
//   search_element(H, x);
//   mm=mm+1;
//  // i++;
// }
// cstart = clock()-cstart;
// time_taken = ((double)cstart)/CLOCKS_PER_SEC; 
// printf("My function took %f seconds to search! \n", time_taken);


outFile.open(s);

 i=0;
cstart = clock(); 
mm=0; 
while (outFile >> x) 
{
  if(mm==numberofvalue)
  {
    break;
  }
  // np = create_node(x);
  delete_key(H, x);
  //cout<<"element deleted"<<i;
  mm=mm+1;
 // i++;
}
cstart = clock()-cstart;
time_taken = ((double)cstart)/CLOCKS_PER_SEC; 
printf("My function took %f seconds to delete! \n", time_taken);

    // cout<<"enter initial number of elements :";
   // cin>>n;
    //cout<<"enter elements :\n";
    //for (i = 1; i <= n; i++) 
    //{
       // cin>>m;
       //cout<<i<<" ";
      
    //}

    // display_root_elements(H);
    // cout<<"\nCurrent heap is: ";
    // printTree(H);
    // cout<<endl;

    do 
    {
        // printf("My function took %f seconds to execute! \n", time_taken);
        cout<<"Enter choice: \n";
        cout<<"1)Insert \n2)Extract min\n3)Decrease key \n4)Delete \n5)Quit \n6)Print heap \n";
        cin>>option;
        switch (option) {
        case 1:
            do {
                cout<<"Enter element:";
                cin>>m;
                p = create_node(m);
                H = insert(H, p);
                display_root_elements(H);
                cout<<"Current heap is: ";
                printTree(H);
                cout<<endl;
                cout<<"\nInsert more(y): \n";
                // fflush(stdin);
                cin>>ch;
            } while (ch == 'Y' || ch == 'y');
         break;
        case 2:
            do {
                p = extract_min_node(H);
                if (p != NULL)
                    cout<<"\nExtracted min node is : "<<p->n;
                display_root_elements(H);
                cout<<"Current heap is: ";
                printTree(H);
                cout<<endl;
                cout<<"\nExtract more(y): \n";
                cin>>ch;
            } while (ch == 'Y' || ch == 'y');
            break;
        case 3:
            do {
                cout<<"Enter old key : ";
                cin>>m;
                cout<<"Enter new key : ";
                cin>>nkey;
                decrease_key(H, m, nkey);
                cout<<"Root elements are :\n ";
                display_root_elements(H);
                cout<<"Current heap is: ";
                printTree(H);
                cout<<endl;
                cout<<"\ndecrease key more(y): \n";
                cin>>ch;
            } while (ch == 'Y' || ch == 'y');
            break;
        case 4:
            do {
                cout<<"Enter key : ";
                cin>>m;
                delete_key(H, m);
                display_root_elements(H);
                cout<<"Current heap is: ";
                printTree(H);
                cout<<endl;
                printf("\ndelete more(y/Y)\n");

                //fflush(stdin);
                scanf("%c", &ch);
            } while (ch == 'y' || ch == 'Y');
            break;
        case 5:
            printf("\nExited\n");
            break;
        case 6:
                cout<<"Current heap is: ";
                printTree(H);
                cout<<endl;
             break;
        default:
            printf("\nWrong choice\n");
        }
    } while (option!= 5);


}