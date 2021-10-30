// Program for Directed Graph Adjacency Matrix Representation!
// This is menu driven program for Directed Graph!
// User has to enter the choice to do any kind of operation on the Directed Graph!
// copyright © 2021 Purshottam Kumar (purshottam2001  <--  GithubID)

#include<bits/stdc++.h>
using namespace std;

#define MAX 100 // for the number of nodes in the graph (max^m = 100)
int adj[MAX][MAX];
int n;

void create_graph(){
    int i, max_edges, orig, dest;
    cout << "\nEnter the number of vertices: ";
    cin >> n;
    max_edges = n*(n-1);
    cout << endl;
    for(int i = 1; i <= max_edges; i++){
        cout << "Enter edge " << i << " (Enter -1, -1 to quit): ";
        cin >> orig >> dest;
        if( (orig == -1) && (dest == -1) ){
            break;
        }
        /* 
        -- As we are indexing the vertices from 0, we have to stop when origin and destination both become equal to the number of vertices!
        -- let's say we have 4 vertices, then the name of the vertices will be v0, v1, v2, v3 and then at n = 4, the last vertex will be v3, so the value of orig and the dest will become orig = 3, dest = 3!
        -- These will be the values of the variable 'orig' and 'dest' in the case of 4 vertices in the graph,
           orig = 0, dest = 0
           orig = 1, dest = 1
           orig = 2, dest = 2
           orig = 3, dest = 3
        -- Also we can't have negative index like -1, i.e. smaller than 0
        -- For a graph of 4 vertices the adjacency matrix will look like -->
           
        0 1 1 1
        1 0 1 1
        1 1 0 1
        1 1 1 0

        */ 
        if( orig >=n || dest >=n || orig < 0 || dest < 0){
            cout << "\nInvalid Edge!\n\n";
            i--;
        }
        else{
            if(adj[orig][dest] == 1){
                cout << "\nEdge already Exists.\n";
            }
            else adj[orig][dest] = 1;
        }
    }
}

void Insert(int orig, int dest){
    if(orig < 0 || orig >= n){
        cout << "\nOrigin Vertex does not exist.\n";
        return ;
    }
    if(dest < 0 || dest >= n){
        cout << "\nDestination Vertex does not exist.\n";
        return ;
    }
    adj[orig][dest] = 1;
}

void Delete(int orig, int dest){
    if(orig < 0 || orig <= n || dest < 0 || dest >= n || adj[orig][dest] == 0){
        cout << "\nThis Edge does not exist.\n";
        return ;
    }
    adj[orig][dest] = 0;
}

void display(){
    cout << endl;
    cout << "  ";
    for(int i = 0; i <= n-1; i++){
        cout << i << " ";
    }
    cout << endl; 
    for(int i = 0; i < n; i++){
        cout << i << " ";
        for(int j = 0; j < n; j++){
            cout << adj[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){
    int choice, orig, dest;
    // cout << endl;
    create_graph();

    while(1){
        cout << "\n1.Insert an Edge.\n";
        cout << "2.Delete an Edge.\n";
        cout << "3.Display.\n";
        cout << "4.Exit.\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        switch(choice){
            case 1:
            cout << "Enter the Edge to be inserted: ";
            cin >> orig >> dest;
            Insert(orig, dest);
            break;

            case 2:
            cout << "Enter the Edge to be deleted: ";
            cin >> orig >> dest;
            Delete(orig, dest);
            break;

            case 3:
            cout << "Elements are: ";
            display();
            cout << "\n";
            break;

            case 4:
            exit(1);

            default:
            cout << "Wrong Choice.\n";
        }
    }
    return 0;
}