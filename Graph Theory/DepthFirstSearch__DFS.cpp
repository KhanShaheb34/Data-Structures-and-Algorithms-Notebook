//Depth First Search
//Contributor Moinul Islam Tanvir(MIT)

#include <bits/stdc++.h>
using namespace std ;

//decla
#define sz 100
#define minimum -1000
#define WHITE 0
#define GREY 1
#define BLACK 2

int adj[sz][sz];
int parent[sz];
int color[sz];
int distant[sz];

void dfs( int vertex);
void dfsvisit(int u , int vertex);

int main() {
    int vertex,edge ;
    int node1,node2 ;

    cin >> vertex >> edge ;

    for ( int i = 0 ; i < edge ; i++ ) {
        cin >> node1 >> node2 ;

        adj[node1][node2] = 1 ;
        adj[node2][node1] = 1 ;
    }

    for ( int i = 0 ; i < vertex ; i++) {
        for ( int j = 0 ; j < vertex ; j++) {
            cout << adj[i][j] << " " ;
        }
        cout << endl ;
    }

    dfs(vertex) ;
}

void dfs( int vertex) {
    for ( int i = 0 ; i < vertex ; i++) color[i] = WHITE ;

    cout << "DFS is " << endl ;

    for ( int i = 0 ; i < vertex ; i++) {
        if (color[i] == WHITE) {
                dfsvisit(i,vertex);
        }
    }}

void dfsvisit(int u , int vertex) {
   color[u] = GREY ;
   for ( int i = 0 ; i < vertex ; i++) {
    if ( adj[u][i] == 1 ) {
        int v = i ;
        if ( color[v] == WHITE) {
            parent[v] = u ;
            dfsvisit(v,vertex);
        }
    }
   }
   color[u] = BLACK ;
   cout << u << " " ;
}

