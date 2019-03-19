
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <math.h>
#include<bits/stdc++.h>
#define MAX 100000000

clock_t cstart, cend;
 double cpu_time_used;
using namespace std;

//Edge structure
struct edge
{
	int v_start;
	int v_end;
	int weight;
};

struct node
{
	int key;
	int degree;
	node * parent;
	node * child;
	node * sibling; 
	int i; 
};

struct vertex
{
	vertex()
	{
		visited = false;
		selected = 0; 
		inHeap = 0; 
		i = 0;
	}

	bool visited; 
	edge * selected;
	node * inHeap;
	vector <edge*> connect; 
	int i;
};


vector <vertex> ver; 
void mergeTree(node * y, node * z)
{
		y->parent = z;
		y->sibling = z->child;
		z->child = y;
		z->degree++;
}


node* simply_merging(node * h1, node * h2)
{
	if (h1 == NULL)
		return h2;

	if (h2 == NULL)
		return h1;
	node * newH;
	node * newH_head;
	if (h1->degree < h2->degree)
	{
		newH = h1;
		h1 = h1->sibling;
	}
	else 
	{
		newH = h2;
		h2 = h2->sibling;
	}

	newH_head = newH;

	while (h1 != NULL && h2 != NULL)
	{
		if (h1->degree < h2->degree)
		{
			newH->sibling = h1;
			h1 = h1->sibling;
			newH = newH->sibling;
		}
		else
		{
			newH->sibling = h2;
			h2 = h2->sibling;
			newH = newH->sibling;
		}
	}
	while (h1 != NULL)
	{
		newH->sibling = h1;
		h1 = h1->sibling;
		newH = newH->sibling;
	}

	while (h2 != NULL)
	{
		newH->sibling = h2;
		h2 = h2->sibling;
		newH = newH->sibling;
	}

	return newH_head;

}

node* mergeHeap(node * h1, node * h2)
{
	node * newH = simply_merging(h1, h2);
	if (newH == NULL)
		return newH;

	node * x = NULL; 
	node * nextval = NULL; 
	node * prevval = NULL; 
	x = newH;
	nextval = newH->sibling;

	while (nextval != NULL)
	{

		if (x->degree != nextval->degree || nextval->sibling != NULL && nextval->sibling->degree == x->degree )
		{
			prevval = x;
			x = nextval;
		}

		else
		{
			if (x->key <= nextval->key )
			{
				x->sibling = nextval->sibling;
				mergeTree(nextval, x);
			}
			else 
			{
				if (prevval == NULL)
					newH = nextval;
				else 
					prevval->sibling = nextval;
				mergeTree(x, nextval);
				x = nextval;
			}
		}

		nextval = x->sibling;
	}
	return newH;
}

void initNode(node * a)
{
	memset(a, 0, sizeof(node));
}

node * insert(node * destination, node * source)
{
	node * heapAfterInsert = mergeHeap(destination, source);
	return heapAfterInsert;
}

node * findMinimum(node * heap)
{

	node * current;
	node * sibling;
	node * min;

	current = heap;
	sibling = heap->sibling;
	min = current;

	if (sibling == NULL)
		return current;

	while (sibling != NULL)
	{
		if (current->key < min->key)
			min = current;

		current = sibling;
		sibling = current->sibling;
	}

	if (current->key < min->key)
		min = current;

	return min;
}
node * extractMin(node * heap)
{
	node * x = findMinimum(heap);
	node * previous = NULL;
	node * iter = heap;
	while (iter != x)
	{
		previous = iter;
		iter = iter->sibling;
	}
	if (previous == NULL) {
		heap = x->sibling;
	}
	else {
		previous->sibling = x->sibling;
	}
	node * fils = x->child;

	if (fils == NULL) 
	{
		return heap;
	}

	node * curr;
	node * prev = 0;
	node * tempnode1;
	int i = 0;
	curr = fils;
	while ( curr != NULL)
	{
		if (prev > 0)
		{
			curr->parent = NULL; 
			tempnode1 = curr->sibling; 
			curr->sibling = prev;
			prev = curr;
			curr = tempnode1;
		}
		//1ere itération
		else
		{
		prev = curr;
		curr = curr->sibling;
		prev->sibling = NULL;
		prev->parent = NULL;
		}
	}
	
	node * finalnode = prev;

	node * resultat =  mergeHeap( heap, finalnode);
	return resultat;
}

void swap_parent_child(node * child, node * parent)
{
	int tmp = child->key;
	child->key = parent->key; 
	parent->key = tmp;
	int Ipar = parent->i;
	int Ich = child->i;
	ver[Ipar].inHeap = child;
	ver[Ich].inHeap = parent;

	child->i = Ipar;
	parent->i = Ich;

}

void decreaseKey(node * element, int Insertnewval)
{
	element->key = Insertnewval;
	node * i = element;

	if (i->parent == NULL)
		return ;

	while (i->parent != NULL)
	{
		int tempvar = i->parent->key;
		if (tempvar > i->key )
		{
			swap_parent_child(i, i->parent);
		}
		else 
			break;
		i = i->parent;
	}
}

int main(int argc, char * argv[])
{
	// string s;
	// cout<<"Enter sample graph file name:- \n";
	// cin>>s;
	printf("\nThe MST of the given graph is:\n");
	FILE* infile;

	if (argc == 2) {
		infile = fopen(argv[1], "r");
	}

	else 
		cout<<"Error in opening file..! ";

    static char x1[50]; 
	bool file1line = false; 
	int aa;
	int bb;

	node * heap = NULL;

    while (fgets(x1, 50, infile) != NULL) 
    {
        if (file1line == false) {

            sscanf(x1, "%d %d", &aa, &bb );

			ver.resize(aa); 

			for (int i = 0; i < aa; i++) {
				node *tmp = new node;
				initNode(tmp);
				tmp->key = INT_MAX;
				tmp->i = i;

				ver[i].inHeap = tmp;
				ver[i].i = i;
				heap = mergeHeap(heap, tmp);
			}
            file1line = true;
            continue;
        }

		int p1, p2, edge_weight;
		sscanf(x1, "%d %d %d", &p1, &p2, &edge_weight);

		edge * e1 = new edge;

		e1->v_start = p1;
		e1->v_end = p2;
		e1->weight = edge_weight;

		ver[p1].connect.push_back(e1);
		ver[p2].connect.push_back(e1);

    }
	vertex * min;
	node * heap_min;
	decreaseKey(ver[0].inHeap, 0);
	//printAllHeap(heap);
	min = &ver[0];

	min->visited = true;

	// min->primsparent=NULL;




    map<int,int> pmap;
    pmap[0]=MAX;
		cstart = clock();  
	while (1)
	{
		heap = extractMin(heap);
		if (heap == NULL)
			break;
		for (int i = 0; i < min->connect.size() ; i++)
		{
			edge * tmp = min->connect[i];

			int destination;
			if ( min->i == tmp->v_start)
				destination = tmp->v_end;
			else destination = tmp->v_start;

			vertex * vertex_destination = &ver[destination];
			if (!vertex_destination->visited)
			{
				if (vertex_destination->selected == NULL) {
					pmap[destination]=tmp->v_start;
					vertex_destination->selected = tmp;
					decreaseKey(  vertex_destination->inHeap, tmp->weight);
				}
				else if (vertex_destination->selected->weight > tmp->weight )
				{
					vertex_destination->selected = tmp;
					pmap[destination]=tmp->v_start;
					decreaseKey(  vertex_destination->inHeap, tmp->weight);
				}

			}

		}

		heap_min = findMinimum(heap);
		min = &ver[heap_min->i];
		min->visited = true;
	}

	cstart = clock()-cstart;
double time_taken = ((double)cstart)/CLOCKS_PER_SEC; 
printf("My function took %f seconds to find MST! \n", time_taken);


	int edge_weightTotal = 0;
	for (int i = 1; i < aa; i++)
	{
		edge_weightTotal += ver[i].selected->weight;
	}
	for(auto it:pmap)
	{
		if(it.first!=0)
		cout<<it.first<<" "<<it.second<<endl;
	}

	printf("\nTotal weight of edges in MST : %d\n", edge_weightTotal);

	return 0;
}