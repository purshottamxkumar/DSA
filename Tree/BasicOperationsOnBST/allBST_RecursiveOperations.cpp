// This is a perfectly working program it is menu based/driven program, user has to enter the choice to perform any kind of the operation!
// This program is about BST(Binary Search Tree)!
// All functions in the program are the Recursive Functions!
// ©copyright 2021 Purshottam Kumar (purshottam2001  <--  GithubID)

#include<bits/stdc++.h>
using namespace std;
class node{ // Nodes will contain the key-data and the links for the other nodes!
    public:
    int data;
    node *lchild;
    node *rchild;
};

int cnt = 0; // This 'cnt' will be used to count the number of the nodes in the Tree!

node* RInsert(node* root, int data){ // This function Recursively insert the key into the Tree!
    if(root == NULL){
        root = new node;
        root->data = data;
        root->lchild = root->rchild = NULL;
        cnt++;
    }
    else if(root->data > data){
        root->lchild = RInsert(root->lchild, data);
    } 
    else if(root->data < data){
        root->rchild = RInsert(root->rchild, data);
    }
    else{
        cout<<"\nDuplicate Key--> "<<data<<"\n";
    }
    return root;
}

void PreorderRecursive(node *root){ // This function Recursively prints in Preorder Manner!
    if(root == NULL){
        return ;
    }
    cout<<root->data<<" ";
    PreorderRecursive(root->lchild);
    PreorderRecursive(root->rchild);
}

void InorderRecursive(node *root){ // This function Recursively prints in Inorder Manner!
    if(root == NULL){
        return ;
    }
    InorderRecursive(root->lchild);
    cout<<root->data<<" ";
    InorderRecursive(root->rchild);
}

void PostorderRecursive(node *root){ // This function Recursively prints in Postorder Manner!
    if(root == NULL){
        return ;
    }
    PostorderRecursive(root->lchild);
    PostorderRecursive(root->rchild);
    cout<<root->data<<" ";
}

node* RSearch(node *root, int key){ // This function Recursively search the key in the Tree!
    if(root == NULL){
        return NULL;
    }
    else if(key < root->data){
        return RSearch(root->lchild, key);
    }
    else if(key > root->data){
        return RSearch(root->rchild, key);
    }
    else{
        return root;
    }
}

node* Rdel(node *root, int key){ // This function Recursively delete the keys from the Tree!
    node *tmp,*succ;
    if(root == NULL){
        cout<<"Key not Found.\n";
        return root;
    }
    if(key < root->data){
        root->lchild = Rdel(root->lchild, key);
    }
    else if(key > root->data){
        root->rchild = Rdel(root->rchild, key);
    }
    else{
        if(root->lchild != NULL && root->rchild != NULL){
            succ = root->rchild;
            while(succ->lchild){
                succ = succ->lchild;
            }
            root->data = succ->data;
            root->rchild = Rdel(root->rchild, succ->data);
        }
        else{
            tmp = root;
            if(root->lchild != NULL){
                root = root->lchild;
            }
            else if(root->rchild != NULL){
                root = root->rchild;
            }
            else{
                root = NULL;
            }
            free(tmp);
            cnt--;
        }
    }
    return root;
}

int Rheight(node *root){ // This function Recursively prints the height of the Tree!
    int l,r;
    if(root == NULL){
        return 0;
    }
    l = Rheight(root->lchild);
    r = Rheight(root->rchild);
    return max(l,r) + 1;
}

node* RMin(node *root){ // This function Recursively prints smallest element present in the Tree!
    if(root == NULL){
        return NULL;
    }
    else if(root->lchild == NULL){
        return root;
    }
    else{
        return RMin(root->lchild);
    }
}

node* RMax(node *root){ // This function Recursively prints largest element present in the Tree!
    if(root == NULL){
        return NULL;
    }
    else if(root->rchild == NULL){
        return root;
    }
    else{
        return RMax(root->rchild);
    }
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
        cout<<"7.Height of Tree.\n";
        cout<<"8.Find minimum and maximum.\n";
        cout<<"9.Quit.\n";
        cout<<"10.Number of Nodes in the Tree.\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 1: cout<<"\nEnter the key to be inserted: ";
            cin>>data;
            root = RInsert(root, data);
            break;

            case 2: if(root == NULL){
                cout<<"\nNo Elements Present!\n";
                break;
            } 
            cout<<"\nEnter the key to be deleted: ";
            cin>>data;
            root = Rdel(root, data);
            break;

            case 3: if(root == NULL){
                cout<<"\nNo Elements Present!\n";
                break;
            } 
            cout<<"\nPreorder Traversal: \n"; 
            PreorderRecursive(root);
            cout<<"\n";
            break;

            case 4: if(root == NULL){
                cout<<"\nNo Elements Present!\n";
                break;
            }  
            cout<<"\nInorder Traversal: \n";
            InorderRecursive(root);
            cout<<"\n";
            break;

            case 5: if(root == NULL){
                cout<<"\nNo Elements Present!\n";
                break;
            } 
            cout<<"\nPostorder Traversal: \n";
            PostorderRecursive(root);
            cout<<"\n";
            break;

            case 6: if(root == NULL){
                cout<<"\nNo Elements Present!\n";
                break;
            }
            cout<<"\nEnter the key to search: "; cin>>data;
            ptr = RSearch(root, data);
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
            cout<<"\nThe height of the tree is: "<<Rheight(root);
            cout<<"\n";
            break;

            case 8: if(root == NULL){
                cout<<"\nNo Elements Present!\n";
                break;
            }
            ptr = RMin(root);
            cout<<"\n";
            if(ptr != NULL){
                cout<<"The minimum key is: "<<ptr->data<<"\n";
            }
            ptr = RMax(root);
            if(ptr != NULL){
                cout<<"The maximum key is: "<<ptr->data<<"\n";
            }
            break;

            case 9: exit(1);
            break;

            case 10: cout<<"\nNumber of Nodes in the Tree = "<<cnt<<"\n";
            break;

            default:
            cout<<"\nWrong Choice.\n\n";
        }
    }
    return 0;
} // Termination of the Program!