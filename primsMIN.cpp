#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

int parent[100];
int key[100];
bool intMST[100];

struct AdjListNode
{
    int vertex, weight;
};

struct PQNode
{
    int vertex, key;
};

// opposite of heap:
// greater for min-heap, lesser for max-heap
struct comparator
{
    bool operator()(PQNode a, PQNode b)
    {
        return a.key > b.key;
    }
};

void printAdjList(vector<vector<AdjListNode>> adjList, int V)
{
    cout << "*****AdjList*****" << endl;
    for (int i = 1; i <= V; i++)
    {
        for (AdjListNode n : adjList[i])
        {
            cout << "(" << n.vertex << "," << n.weight << ") ";
        }
        cout << endl;
    }
    cout << "*****AdjList*****" << endl;
}


void prims(vector<vector<AdjListNode>> adjList, int V, int E, int s)
{
    // for all vertices, initially:
    // weight(key) = MAXIMUM -> Set max to find min
    // parent = -1 -> indicates no parent
    // intMST = false -> not visited
    for (int i = 1; i <= V; i++)
    {
        key[i] = INT_MAX;
        parent[i] = -1;
        intMST[i] = false;
    }

    // make given source key = 0
    key[s] = 0;

    // Priority Queue: <element_type, data structure(vector), comperator>
    priority_queue<PQNode, vector<PQNode>, comparator> pq;
    pq.push(PQNode{s, 0});

    while (!pq.empty())
    {
        // get the node with minimum weight (initially 0)
        PQNode n = pq.top();
        pq.pop();
        cout << "vertex = " << n.vertex << "key = " << n.key << endl;
        
        // get the minimum's vertex
        int u = n.vertex;
        if (intMST[u] == true)
            continue;
        intMST[u] = true;

        for (AdjListNode node : adjList[u])
        {
            int v = node.vertex; // connected vertex
            int w = node.weight; // edge weight
            if (intMST[v] == false && w < key[v])
            {
                key[v] = w; // minimum
                parent[v] = u; // new parent
                pq.push(PQNode{v, key[v]}); // register in pq
            }
        }
    }
    cout << "Key arrays";
    for (int i = 1; i <= V; i++)
    {
        cout << key[i] << " ";
    }
    cout << "\n parent arrays :";
    for (int i = 1; i <= V; i++)
    {
        cout << parent[i] << " ";
    }

    cout << "\n inMST ";
    for (int i = 1; i < V; i++)
    {
        cout << parent[i] << " ";
    }
    cout << endl;


    // IMPORTANT
    cout << "Edges in MST :" << endl;
    int TotalWeight = 0;
    for (int i = 1; i <= V; i++)
    {
        if (parent[i] != -1)
        {
            cout << parent[i] << "-" << i << "(weight =" << key[i] << ")" << endl;
            TotalWeight += key[i];
        }
    }
    cout << "Total weight in MST = " << TotalWeight << endl;
}

int main()
{
    int V, E;
    cout << "Enter vertices and edges :";
    cin >> V >> E;

    // Create and initialize a 2D vector -> Each row indicates one vertex
    // Initially each vertex has empty vector representing connected vertices and their edge weights
    // We are creating one extra vertice (just for convenience)
    vector<vector<AdjListNode>> adjList;
    for (int i = 0; i <= V; i++)
    {
        adjList.push_back(vector<AdjListNode>());
    }

    // u -> one vertice, v -> connected vertice, w -> edge weight
    // as we have undirected graph, we push to both
    cout << "Enter the Edges :" << endl;
    for (int i = 1; i <= E; i++)
    {
        int u, v, w;
        cin >> u;
        cin >> v;
        cin >> w;
        AdjListNode n1{v, w};
        adjList[u].push_back(n1);

        AdjListNode n2{u, w};
        adjList[v].push_back(n2);
    }

    printAdjList(adjList, V);
    prims(adjList, V, E, 1);

    return 0;
}
