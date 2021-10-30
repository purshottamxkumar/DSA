// Program for Directed Graph using Adjacency List!
// This is menu driven program for Directed Graph!
// User has to enter the choice to do any kind of operation on the Directed Graph!
// copyright © 2021 Purshottam Kumar (purshottam2001  <--  GithubID)
#include<bits/stdc++.h>
using namespace std;
struct Edge;
struct Vertex{
    int info;
    struct Edge *firstEdge; // first Edge of the adjacency list of this vertex!
    struct Vertex *nextVertex; // next vertex in the linked list of vertices!
};

struct Vertex *start = NULL;

struct Edge{
    struct Vertex *destVertex; // destination vertex of the Edge!
    struct Edge *nextEdge; // next Edge of the adjacency list!
};

struct Vertex* findVertex(int u){
    struct Vertex *ptr, *loc;
    ptr = start;
    while(ptr != NULL){
        if(ptr->info == u){
            loc = ptr;
            return loc;
        }
        else{
            ptr = ptr->nextVertex;
        }
    }
    loc = NULL;
    return loc;
}

void insertVertex(int u){
    // This code will insert the new vertex at end of the vertex list only, it doesn't take the order into account!
    // So, the vertex list can be V2 -> V1 -> V3 -> V0
    struct Vertex *tmp, *ptr;
    tmp = new Vertex;
    tmp->info = u;
    tmp->nextVertex = NULL;
    tmp->firstEdge = NULL;
    if(start == NULL){
        start = tmp;
        return ;
    }
    ptr = start;
    while(ptr->nextVertex != NULL){
        ptr = ptr->nextVertex;
    }
    ptr->nextVertex = tmp;
}

void insertEdge(int u, int v){
    struct Vertex *locu, *locv;
    struct Edge *ptr, *tmp;
    locu = findVertex(u);
    locv = findVertex(v);
    if(locu == NULL){ // if the start vertex for the Edge is not present in the Graph!
        cout << "\nStart vertex not present, first insert vertex " << u << "!\n";
        return ;
    }
    if(locv == NULL){ // if the end vertex for the Edge is not present in the Graph!
        cout << "\nEnd vertex not present, first insert vertex " << v << "!\n";
        return ;
    }
    tmp = new Edge;
    tmp->destVertex = locv;
    tmp->nextEdge = NULL;

    if(locu->firstEdge == NULL){ // if start vertex is not connected to any other vertex in the Graph!
        locu->firstEdge = tmp;
        return ;
    }
    ptr = locu->firstEdge;
    while(ptr->nextEdge != NULL){
        ptr = ptr->nextEdge;
    }
    ptr->nextEdge = tmp;
}

void deleteEdge(int u, int v){
    struct Vertex *locu;
    struct Edge *tmp, *q;
    locu = findVertex(u);
    if(locu == NULL){ // if the start vertex for the Edge to be deleted is not present in the Graph!
        cout << "\nThis Edge is not present in the Graph\n";
        return ;
    }
    if(locu->firstEdge == NULL){
        cout << "\nThis Edge is not present in the Graph\n";
        return ;
    }
    if(locu->firstEdge->destVertex->info == u){
        tmp = locu->firstEdge;
        locu->firstEdge = locu->firstEdge->nextEdge;
        delete tmp;
        return ;
    }
    q = locu->firstEdge;
    while(q->nextEdge != NULL){
        if(q->nextEdge->destVertex->info == v){
            tmp = q->nextEdge;
            q->nextEdge = tmp->nextEdge;
            delete tmp;
            return ;
        }
        q = q->nextEdge;
    }
    cout << "\nThis Edge is not present in the Graph\n";
}

void deleteIncomingEdges(int u){ // to delete all the incoming Edges on the Given vertex!
    struct Vertex *ptr;
    struct Edge *q, *tmp;
    ptr = start;
    while(ptr != NULL){
        if(ptr->firstEdge == NULL){
            ptr = ptr->nextVertex;
            continue;
        }
        if(ptr->firstEdge->destVertex->info == u){
            tmp = ptr->firstEdge;
            ptr->firstEdge = ptr->firstEdge->nextEdge;
            delete tmp;
            continue;
        }
        q = ptr->firstEdge;
        while(q->nextEdge != NULL){
            if(q->nextEdge->destVertex->info == u){
                tmp = q->nextEdge;
                q->nextEdge = tmp->nextEdge;
                delete tmp;
                continue;
            }
            q = q->nextEdge;
        }
        ptr = ptr->nextVertex;
    }
}

void deleteVertex(int u){
    struct Vertex *tmp, *q;
    struct Edge *p, *temporary;
    if(start == NULL){
        cout << "\nNo vertices in the Graph, as start is NULL\n";
        return ;
    }
    if(start->info == u){
        tmp = start;
        start = start->nextVertex;
    }
    else{
        q = start;
        while(q->nextVertex != NULL){
            if(q->nextVertex->info == u){
                break;
            }
            q = q->nextVertex;
        }
        if(q->nextVertex == NULL){
            cout << "\nVertex not found\n";
            return ;
        }
        else{
            tmp = q->nextVertex;
            q->nextVertex = tmp->nextVertex;
        }
    }

    p = tmp->firstEdge;
    while(p != NULL){
        temporary = p;
        p = p->nextEdge;
        delete temporary;
    }
    delete tmp;
}

void display(){
    struct Vertex *ptr;
    struct Edge *q;
    ptr = start;
    cout << "\nList of all the Elements in the Graph-->\n";
    while(ptr != NULL){
        cout << ptr->info << " ->";
        q = ptr->firstEdge;
        while(q != NULL){
            cout << " " << q->destVertex->info;
            q = q->nextEdge;
        }
        cout << "\n";
        ptr = ptr->nextVertex;
    }
    cout << "\n";
}

int main(){

    int choice, u, origin, destin;

    while(1){
        cout << "\n1.Insert a Vertex.\n";
        cout << "2.Insert an Edge.\n";
        cout << "3.Delete a Vertex.\n";
        cout << "4.Delete an Edge.\n";
        cout << "5.Display.\n";
        cout << "6.Exit.\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "\n";
        switch(choice){
            case 1:
            cout << "Enter a vertex to be inserted: ";
            cin >> u;
            insertVertex(u);
            break;

            case 2:
            cout << "Enter the start Vertex for the Edge to be inserted: ";
            cin >> origin;
            cout << "Enter the end Vertex for the Edge to be inserted: ";
            cin >> destin;
            insertEdge(origin, destin);
            break;

            case 3:
            cout << "Enter a vertex to be deleted: ";
            cin >> u;
            deleteIncomingEdges(u);
            deleteVertex(u);
            break;

            case 4:
            cout << "Enter start Vertex for the Edge to be deleted: ";
            cin >> origin;
            cout << "Enter end Vertex for the Edge to be deleted: ";
            cin >> destin;
            deleteEdge(origin, destin);
            break;

            case 5:
            display();
            break;

            case 6:
            exit(1);

            default:
            cout << "Wrong Choice\n";
            break;
        }
    }
    return 0;
}