#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

struct AdjListNode{
    int vertex;
    int weight;
    AdjListNode(int vertex,int weight){
        this->vertex=vertex;
        this->weight=weight;
    }
};

struct PQNode{
    int vertex;
    int key;
    PQNode(int vertex,int key){
        this->vertex=vertex;
        this->key=key;
    }
};

struct Comparator{
    bool operator() (PQNode a, PQNode b) {
        if(a.key<b.key){
            return false; // give more priority to a due to its smaller key
        }else{
            return true;
        }
    }
};

void printAdjList(vector < vector<AdjListNode> > adjList, int V, int E){
    cout<<"*****************Adj List*****************"<<endl;
    for(int i=1;i<=V;i++){
        for( AdjListNode n :adjList[i]){
            cout<<"("<<n.vertex<<","<<n.weight<<") ";
        }
        cout<<"\n";
    }

    cout<<"\n*****************Adj List*****************"<<endl;
}

int key[100];
int parent[100];
bool inMST[100];

void Prims(vector < vector<AdjListNode> > adjList, int V, int E, int s){
    for(int i=1;i<=V;i++){
        key[i]=INT_MAX;
        parent[i] = -1;
        inMST[i] = false;
    }

    key[s]=0;
    priority_queue <PQNode, vector<PQNode>, Comparator> pq;
    pq.push( PQNode(s,0) );
    while(!pq.empty()){
        PQNode n = pq.top();
        pq.pop();
        cout<<"vertex = "<<n.vertex<<", key =  "<<n.key<<endl;
        int u = n.vertex; // just taking the vertex name


        if(inMST[u]==true) continue;
        inMST[u]=true;

        for(AdjListNode  node: adjList[u]){
            int v = node.vertex;
            int w = node.weight;
            if(inMST[v]==false && key[v]>w){
                key[v]=w;
                parent[v]=u;

                pq.push( PQNode(v,key[v]) );
            }
        }

    }
    cout<<"key array:"<<endl;
    for(int i=1;i<=V;i++){
        cout<<key[i]<<" ";

    }
    cout<<"\nparent array:"<<endl;
    for(int i=1;i<=V;i++){
        cout<<parent[i]<<" ";
    }
    cout<<"\nin mst array:"<<endl;
    for(int i=1;i<=V;i++){
        cout<<inMST[i]<<" ";
    }

}

int main(){
    cout<<"Enter the number of vertices and edges"<<endl;
    int V,E;
    cin>>V;
    cin>>E;

    vector < vector<AdjListNode> > adjList;

    // making the 8 vectors for the 8 vertices (with an extra 1)
    for(int i=0;i<=V;i++){
        adjList.push_back( vector<AdjListNode>());
    }


    cout<<"Enter the edges"<<endl;

    for(int i=1;i<=E;i++){
        int u;
        int v;
        int w;
        cin>>u; //1
        cin>>v; // 2
        cin>>w; // 4
        AdjListNode n1(v,w);
        adjList[u].push_back(n1);

        AdjListNode n2(u,w);
        adjList[v].push_back(n2);
    }

    printAdjList(adjList,V,E);

    Prims(adjList,V,E,1);
    return 0;
}

/*
8 10
1 2 4
1 8 6
2 3 9
2 8 5
2 5 2
5 4 15
5 6 8
6 7 3
7 8 14
6 8 10
*/
