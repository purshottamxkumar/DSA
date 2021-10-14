// This is a perfectly working program it is menu based/driven program, user has to enter the choice to perform any kind of the operation!
// This program is about BST(Binary Search Tree)!
// All functions in the program are the Iterative Functions!
// ©copyright 2021 Purshottam Kumar (purshottam2001  <--  GithubID)

#include<bits/stdc++.h>
using namespace std;
class node{ // Nodes will contain the key-data and the links for the other nodes!
    public:
    int data;
    node *lchild;
    node *rchild;
};

int CountNodes(node *root){ // This functions will be used to count the number of the nodes in the Tree!
    int cnt = 0;
    node *p = root;
    if(root == NULL){
        return 0;
    }
    stack<node *> s;
    while(p != NULL || !s.empty()){
        if(p != NULL){
            cnt++;
            s.push(p);
            p = p->lchild;
        }
        else{
            p = s.top();
            s.pop();
            p = p->rchild;
        }
    }
    return cnt;
}

node *IteInsert(node *root, int data){
    node *tmp;
    tmp = new node;
    tmp->data = data;
    tmp->lchild = tmp->rchild = NULL;
    if(root == NULL){
        root = tmp;
        return root;
    }
    node *ptr = root;
    node *prev = NULL;
    while(ptr){
        prev = ptr;
        if(data < ptr->data){
            ptr = ptr->lchild;
        }
        else if(data > ptr->data){
            ptr = ptr->rchild; 
        }
        else{
            cout<<"\nDuplicate Key--> "<<data<<"\n";
            return root;
        }
    }
    if(data > prev->data){
        prev->rchild = tmp;
    }
    else{
        prev->lchild = tmp;
    }
    return root;
}

void PreorderIterativeDisplay(node *root){
    node *p = root;
    stack<node *> s;
    while(p != NULL || !s.empty()){
        if(p != NULL){
            cout<<p->data<<" ";
            s.push(p);
            p = p->lchild;
        }
        else{
            p = s.top();
            s.pop();
            p = p->rchild;
        }
    }
}

void InorderIterativeDisplay(node *root){
    node *p = root;
    stack<node *> s;
    while(p!=NULL || !s.empty()){ //here we have to include p!=NULL as we have to enter into the while loop even if the stack is empty!
        if(p != NULL){
            s.push(p);
            p = p->lchild;
        }
        else{
            p = s.top();
            s.pop();
            cout<<p->data<<" ";
            p = p->rchild;
        }
    }
}

void PostorderIterativeDisplay(node *root){
    node *p = root;
    node *q = root;
    stack<node *> s;
    while(1){
        while(p->lchild != NULL){
            s.push(p);
            p = p->lchild;
        }

        while(p->rchild == NULL || p->rchild == q){
            cout<<p->data<<" ";
            q = p;
            if(s.empty()){
                return ;
            }
            p = s.top();
            s.pop();
        }
        s.push(p);
        p = p->rchild;
    }
}

node* IterativeDel(node *root, int key){ // This function Iteratively delete the keys from the Tree!
    node *par, *ptr, *child, *succ, *parsucc;
    ptr = root;
    par = NULL;
    while(ptr != NULL){
        if(key == ptr->data){
            break;
        }
        par = ptr;
        if(key < ptr->data){
            ptr = ptr->lchild;
        }
        else ptr = ptr->rchild;
    }
    if(ptr == NULL){
        cout<<"\nKey not Present!\n";
        return root;
    }
    if(ptr->lchild != NULL && ptr->rchild != NULL){
        parsucc = ptr;
        succ = ptr->rchild;
        while(succ->lchild){
            parsucc = succ;
            succ = succ->lchild;
        }
        ptr->data = succ->data;
        ptr = succ;
        par = parsucc;
    }

    if(ptr->lchild != NULL){
        child = ptr->lchild;
    }
    else child = ptr->rchild;

    if(par == NULL){
        root = child;
    }
    else if(ptr == par->lchild){
        par->lchild = child;
    }
    else{
        par->rchild = child;
    }
    delete ptr;
    return root;
}

node* IterativeSearch(node *root, int key){ // This function Iteratively search the key in the Tree!
    while(root != NULL){
        if(key < root->data){
            root = root->lchild;
        }
        else if(key > root->data){
            root = root->rchild;
        }
        else return root;
    }
    return NULL;
}

int IterativeHeight(node *root){ // This function Iteratively prints the height of the Tree!
    int cnt = 0;
    int height = 0;
    node *Front;
    queue<node *> Q;

    if(root == NULL){
        return 0;
    }

    Q.push(root);

    while(!Q.empty()){
        height++;
        cnt = Q.size();
        
        while(cnt--){
            Front = Q.front();
            if(Front->lchild != NULL){
                Q.push(Front->lchild);
            }
            if(Front->rchild != NULL){
                Q.push(Front->rchild);
            }
            Q.pop();
        }
    }
    return height;
}

node* Min(node *root){ // This function Iteratively prints smallest element present in the Tree!
    if(root == NULL) return NULL;
    if(root != NULL){
        while(root->lchild != NULL){
            root = root->lchild;
        }
    }
    return root;
}

node* Max(node *root){ // This function Iteratively prints largest element present in the Tree!
    if(root == NULL) return NULL;
    if(root != NULL){
        while(root->rchild != NULL){
            root = root->rchild;
        }
    }
    return root;
}

int main(){ // Program execution starts from here!
    node *root = NULL, *ptr;
    int choice, data, item;
    cout<<"\nThese are the choices: \n";
    while(1){ // Following are the choices provided to the user!
        cout<<"\n\n";
        cout<<"1.Insert.\n";
        cout<<"2.Delete.\n";
        cout<<"3.Preorder Traversal.\n";
        cout<<"4.Inorder Traversal.\n";
        cout<<"5.Postorder Traversal.\n";
        cout<<"6.Search.\n";
        cout<<"7.Height of Tree. (Height starts from 1 Onwards!)\n";
        cout<<"8.Find minimum and maximum.\n";
        cout<<"9.Quit.\n";
        cout<<"10.Number of Nodes in the Tree.\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 1: cout<<"\nEnter the key to be inserted: ";
            cin>>data;
            root = IteInsert(root, data);
            break;

            case 2: if(root == NULL){
                cout<<"\nNo Elements Present!\n";
                break;
            } 
            cout<<"\nEnter the key to be deleted: ";
            cin>>data;
            root = IterativeDel(root, data);
            break;

            case 3: if(root == NULL){
                cout<<"\nNo Elements Present!\n";
                break;
            } 
            cout<<"\nPreorder Traversal: \n"; 
            PreorderIterativeDisplay(root);
            cout<<"\n";
            break;

            case 4: if(root == NULL){
                cout<<"\nNo Elements Present!\n";
                break;
            }  
            cout<<"\nInorder Traversal: \n";
            InorderIterativeDisplay(root);
            cout<<"\n";
            break;

            case 5: if(root == NULL){
                cout<<"\nNo Elements Present!\n";
                break;
            } 
            cout<<"\nPostorder Traversal: \n";
            PostorderIterativeDisplay(root);
            cout<<"\n";
            break;

            case 6: if(root == NULL){
                cout<<"\nNo Elements Present!\n";
                break;
            }
            cout<<"\nEnter the key to search: "; cin>>data;
            ptr = IterativeSearch(root, data);
            if(ptr != NULL){
                cout<<"Key Present.\n";
            } 
            else{
                cout<<"Key not Present.\n";
            }
            break;

            case 7: if(root == NULL){
                cout<<"\nNo Elements Present!\n";
                break;
            }
            cout<<"\nThe height of the tree is: "<<IterativeHeight(root);
            cout<<"\n";
            break;

            case 8: if(root == NULL){
                cout<<"\nNo Elements Present!\n";
                break;
            }
            ptr = Min(root);
            cout<<"\n";
            if(ptr != NULL){
                cout<<"The minimum key is: "<<ptr->data<<"\n";
            }
            ptr = Max(root);
            if(ptr != NULL){
                cout<<"The maximum key is: "<<ptr->data<<"\n";
            }
            break;

            case 9: exit(1);
            break;

            case 10: cout<<"\nNumber of Nodes in the Tree = "<<CountNodes(root)<<"\n";
            break;

            default:
            cout<<"\nWrong Choice.\n\n";
        }
    }
    return 0;
} // Termination of the Program!