#include<bits/stdc++.h> 

clock_t cstart, cend;
 double cpu_time_used;

using namespace std; 
# define INF 0x3f3f3f3f 
  
// iPair ==>  Integer Pair 
typedef pair<int, int> iPair; 
  
// This class represents a directed graph using 
// adjacency list representation 
class Graph 
{ 
    int V;    // No. of vertices 
  
    list< pair<int, int> > *adj; 
  
public: 
    Graph(int V);   
  
    void addEdge(int u, int v, int w); 
  
    void primMST(); 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<iPair> [V]; 
} 
  
void Graph::addEdge(int u, int v, int w) 
{ 
    adj[u].push_back(make_pair(v, w)); 
    adj[v].push_back(make_pair(u, w)); 
} 
  
void Graph::primMST() 
{ 
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq; 
  
    int src = 0; // Taking vertex 0 as source 
  
    vector<int> key(V, INF); 
  
    vector<int> parent(V, -1); 
  
    vector<bool> inMST(V, false); 
  
    pq.push(make_pair(0, src)); 
    key[src] = 0; 
  
    while (!pq.empty()) 
    { 
        int u = pq.top().second; 
        pq.pop(); 
  
        inMST[u] = true;   
  
        list< pair<int, int> >::iterator i; 
        for (i = adj[u].begin(); i != adj[u].end(); ++i) 
        { 
            int v = (*i).first; 
            int weight = (*i).second; 
  
            if (inMST[v] == false && key[v] > weight) 
            { 
                key[v] = weight; 
                pq.push(make_pair(key[v], v)); 
                parent[v] = u; 
            } 
        } 
    } 
  cout<<"\n";
    for (int i = 1; i < V; ++i) 
        printf("%d - %d\n", parent[i], i); 
} 
  
int main() 
{ 

    int v,e;
    printf("Enter no of verties :\n");
    cin>>v;

    printf("Enter no of edges :\n");
    cin>>e;
    
    Graph g(v); 
     
    int v1,v2,w;
    for(int i=0;i<e;i++)
    {
        // cout<<"\n Enter v1 v2 weight :\n";
        cin>>v1>>v2>>w;
        g.addEdge(v1,v2,w);
    }


  cstart = clock(); 
    g.primMST(); 
  
  cstart = clock()-cstart;
double time_taken = ((double)cstart)/CLOCKS_PER_SEC; 
printf("My function took %f seconds to find MST! \n", time_taken);
    return 0; 
} 