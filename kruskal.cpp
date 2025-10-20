#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Edge{
    int u;
    int v;
    int w;
    Edge(int u,int v,int w){
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

int parent[100];

void makeSet(int v){
    parent[v]=v;
}
bool comparator(Edge e1,Edge e2){
    if(e1.w<e2.w){
        return true;
    }else{
        return false;
    }
}

int findSet(int v){
    if(v==parent[v]){
        return v;
    }else{
        return findSet(parent[v]);
    }
}

void Union(int a, int b){
    int x=findSet(a);
    int y=findSet(b);
    if(x==y){
        cout<<"Under the same set"<<endl;
    }else{
        parent[x]=y;
    }
}

void Kruskal(vector <Edge> allGraphEdges,int V, int E){
    vector <Edge> selectedEdges;
    for(int v=1;v<=V;v++){
        makeSet(v);
    }
    sort(allGraphEdges.begin(),allGraphEdges.end(),comparator);

//    cout<<"After sorting"<<endl;
//    for(Edge edge:allGraphEdges ){
//        cout<<"("<<edge.u<<","<<edge.v<<","<<edge.w<<")"<<endl;
//    }

    for(Edge edge:allGraphEdges){
        int u = edge.u;
        int v = edge.v;
        int w = edge.w;

        if(findSet(u)!=findSet(v)){
            selectedEdges.push_back(edge);
            Union(u,v);
        }

    }

   cout<<"Selected edges"<<endl;
    for(Edge edge:selectedEdges ){
        cout<<"("<<edge.u<<","<<edge.v<<","<<edge.w<<")"<<endl;
    }
}

int main(){
    vector <Edge> allGraphEdges;
    int V,E;
    cout<<"Enter the number of vertices and edges"<<endl;
    cin>>V>>E;
    cout<<"Enter the edges (u,v,w)\n";
    for(int i=1;i<=E;i++){
        int u,v,w;
        cin>>u>>v>>w;
        Edge edge(u,v,w);
        allGraphEdges.push_back(edge);
    }

    for(Edge edge:allGraphEdges ){
        cout<<"("<<edge.u<<","<<edge.v<<","<<edge.w<<")"<<endl;
    }
    Kruskal(allGraphEdges,V,E);
    return 0;
}

/*
7 11
1 2 2
2 3 19
1 7 8
7 6 21
1 6 14
2 6 25
6 3 17
6 5 13
3 5 5
3 4 9
5 4 1
*/
