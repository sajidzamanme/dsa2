#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

int WHITE = 1;
int GRAY = 2;
int BLACK = 3;

int dist[100];
int parent[100];
int color[100];

void BFS(vector <vector <int>> adjList, int V, int E, int s){
    for(int i=1;i<=V;i++){
        dist[i]=INT_MAX;
        parent[i]=-1;
        color[i]=WHITE;
    }
    dist[s]=0;
    parent[s]=-1;
    color[s]=GRAY;

    queue <int> Q;
    Q.push(s);

    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        color[u]=BLACK;
        for(int v:adjList[u]){
            if(color[v]==WHITE){
                color[v]=GRAY;
                Q.push(v);
                dist[v]=1+dist[u];
                parent[v]=u;
            }
        }

    }
    cout<<"Vertex properties after BFS"<<endl;
    for(int v=1;v<=V;v++){
        cout<<"v="<<v<<"color="<<color[v]<<"dist="<<dist[v]<<"parent="<<parent[v]<<endl;
    }

}

int main(){
    int V,E;
    cout<<"Enter the number of vertices and edges"<<endl;
    cin>>V>>E;

    vector <vector <int>> adjList;

    for(int i=0;i<=V;i++){
        vector<int > v;
        adjList.push_back(v);
    }

    cout<<"Enter the edges (u,v)"<<endl;
    for(int i=1;i<=E;i++){
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    cout<<"**********Adj List **************"<<endl;
    for(int i=1;i<=V;i++){
        for(int v :adjList[i]){
            cout<<"->"<<v;
        }
        cout<<endl;
    }
    cout<<"\n**********Adj List **************"<<endl;
    BFS(adjList,V,E,2);
    return 0;
}

/*
8 9
1 2
1 5
6 2
6 3
6 7
3 7
7 8
3 4
4 8
*/
