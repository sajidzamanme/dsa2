#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int key[100];
int parent[100];
bool intMST[100];

struct AdjListNode
{
    int vertex;
    int weight;
};

struct PQNode
{
    int vertex;
    int key;
};

struct comparator
{
    bool operator()(PQNode a, PQNode b)
    {
        return (a.key < b.key);
    }
};

void printAdjList(vector<vector<AdjListNode>> adjList, int V)
{
    cout << "******AdjList*****" << endl;
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
    for (int i = 1; i <= V; i++)
    {
        key[i] = INT_MIN;
        parent[i] = -1;
        intMST[i] = false;
    }

    key[s] = 0;
    priority_queue<PQNode, vector<PQNode>, comparator> pq;
    pq.push(PQNode{s, 0});

    while (!pq.empty())
    {
        PQNode n = pq.top();
        pq.pop();

        cout << "Vertex = " << n.vertex << "key = " << n.key << endl;

        int u = n.vertex;

        if (intMST[u] == true)
            continue;
        intMST[u] = true;

        for (AdjListNode node : adjList[u])
        {
            int v = node.vertex;
            int w = node.weight;

            if (intMST[v] == false && w > key[v])
            {
                key[v] = w;
                parent[v] = u;

                pq.push(PQNode{v, key[v]});
            }
        }
    }
    cout << "key array:" << endl;
    for (int i = 1; i <= V; i++)
    {
        cout << key[i] << " ";
    }
    cout << "\nparent array:" << endl;
    for (int i = 1; i <= V; i++)
    {
        cout << parent[i] << " ";
    }
    cout << "\nin mst array:" << endl;
    for (int i = 1; i <= V; i++)
    {
        cout << intMST[i] << " ";
    }

    // Print MST edges
    cout << "\n\nEdges in MST:\n";
    int totalWeight = 0;
    for (int i = 1; i <= V; i++)
    {
        if (parent[i] != -1)
        { // skip source
            cout << parent[i] << " - " << i << "  (weight = " << key[i] << ")\n";
            totalWeight += key[i];
        }
    }

    cout << "Total weight of MST = " << totalWeight << "\n";
}

int main()
{
    int V, E;
    cout << "Enter Vertexes and Edges :";
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
    cout << "Enter the edges connected with weight :" << endl;
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
