//implementation of BFS 
//Contributor Moinul Islam Tanvir(MIT)

#include <bits/stdc++.h>
using namespace std ;

#define sz 100
#define inf 10000


vector <int> adj[sz];
int visited[sz];
int parent[sz];
int dis[sz];

void bfs(int vertex,int startingNode);
void printpath(int s , int v);

int main() {

    int vertex ;
    int edge ;

    cin >> vertex >> edge ;

    cout << "Vertex is : " << vertex << endl ;
    cout << "Edge is : " << edge << endl ;

    int node1,node2 ;

    for ( int i = 0 ; i < edge ; i++) {

    	//taking input of all the edges
        cin >> node1 >> node2 ;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }

    for(int i = 0 ; i < vertex ; i++)
    {
        cout << i << "-->" ;
        for(int j = 0 ; j < adj[i].size() ; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }


    int source,destination;
    scanf("%d %d",&source,&destination);
    bfs(vertex,source);
    cout << endl ;
    printpath(source,destination);
}

void bfs(int vertex,int startingNode) {

	//initializing values of all arrays
    for ( int i = 0 ; i < vertex ; i++) {
        if ( i != startingNode) {
            visited[i] = 0 ;
            parent[i] = -1 ;
            dis[i] = inf ;
        }
    }

    visited[startingNode] = 1 ;
    dis[startingNode] = 0 ;
    parent[startingNode] = -1 ;
    queue <int> bfsQueue ;
    bfsQueue.push(startingNode);
    cout << "BFS IS :" ;
    while (!bfsQueue.empty()) {
    	//stores the top element of the queue
        int u = bfsQueue.front();
        cout << u << " ";
        bfsQueue.pop();

        //searching for all the nodes that can be rached from node u
        for ( int i = 0 ; i < adj[u].size() ; i++) {
        	//if the node is not visited before we push it to the queue 
            if ( visited[adj[u][i]] == 0 ) {
                        visited[adj[u][i]] = 1 ;
                        parent[adj[u][i]] = u ;
                        dis[adj[u][i]] = dis[u]+1 ;
                        bfsQueue.push(adj[u][i]);
                }
            }
        }
  cout << endl;
  return ;
}

void printpath(int s , int v) {
    vector<int> path;
    int x = v ;
    path.push_back(x);
    while (parent[x] != -1) {
        path.push_back(parent[x]);
        x = parent[x];
    }
    reverse(path.begin(),path.end());
    int fact = 0 ;
    for ( int i = 0 ; i < path.size() ; i++ ) {
        if ( path[i] == -1 ) {
            fact = 1 ;
            break ;
        }
    }
    if ( fact == 1 ) cout << "NO PATH EXIST!!" << endl;
    else {
        for ( int i = 0 ; i < path.size() ; i++ ) cout << path[i] << " ";
    }
    cout << endl;
    if ( dis[v] != inf) cout << "PATH DISTANCE FROM SOURCE TO DESTINATION IS : " << dis[v] << endl;
    else cout << "CAN NOT BE DETERMINE" << endl;
}

