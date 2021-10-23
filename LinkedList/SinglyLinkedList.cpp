// This is menu driven program of singly linked list!
// User has to enter the choice to do any kind of operation on the linked list!
// In this program we can't have duplicates elements!
// copyright © 2021 Purshottam Kumar (purshottam2001  <--  GithubID)

#include<bits/stdc++.h>
using namespace std;

class node{  // This is Used to create the user defined node Data Type for the linked list!
    public:
    int data;
    node *next;
};

void emptyList(){ // To check if the linked list is Empty or not!
    cout << "\nEmpty linked list, first insert elements in the linked list.\n";
}

int countNodes(node *head){ // To count the number of the nodes in the linked list!
    if(head == NULL){
        return 0;
    }
    node *t = head;
    int cnt = 0;
    while(t != NULL){
        cnt++;
        t = t->next;
    }
    return cnt;
}

void display(node *head){ // To display the elements of the linked list iteratively!
    if(head == NULL){
        emptyList();
        return ;
    }
    node *t = head;
    cout << "\nElements are: ";
    while(t != NULL){
        cout << t->data << " ";
        t = t->next;
    }
    cout << endl;
}

int searchList(node *head, int key){ // To search the key in the linked list!
    int pos = 1;
    node *t = head;
    if(head == NULL){
        return 0;
    }
    while(t != NULL && t->data != key){
        t = t->next;
        pos++;
    }
    if(t){ 
        return pos;
    }
    return -1;
}

node* addAtBeg(node *head, int data){ // To insert at beginning!
    node *p;
    p = new node;
    p->data = data;
    p->next = NULL;

    if(head == NULL){
        head = p;
        return head; 
    }

    p->next = head;
    head = p;
    return head;
}

node* addAtEnd(node *head, int data){ // To insert at end!
    node *p;
    p = new node; 
    p->data = data;
    p->next = NULL;

    if(head == NULL){
        head = p;
        return head;
    }

    node *tmp;
    tmp = head;
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = p;
    return head;
}

node* addAtPos(node *head, int pos, int data){ // To insert the element at specific position!
    // Position starts from 1 onwards!
    if(pos < 1 || pos > countNodes(head)){
        cout << "Invalid Position!\n";
        return head;
    }

    node *p;
    p= new node;
    p->data = data;
    p->next = NULL;

    // to insert at position 1 !
    if(pos == 1){
        p->next = head;
        head = p;
        return head;
    }

    // for other positions!
    int t = 2;
    node *tmp = head;
    while(tmp != NULL && t < pos){
        tmp = tmp->next;
        t++;
    }

    p->next = tmp->next;
    tmp->next = p;
    return head;

}

node* addAfter(node *head, int item, int data){ // To insert after a specific element!
    node *p;
    p = new node;
    p->data = data;
    p->next = NULL;

    node *tmp = head;
    while(tmp != NULL){
        if(tmp->data == item){
            p->next = tmp->next;
            tmp->next = p;
            return head;
        }
        tmp = tmp->next;
    }
    cout << item << " not present in the linked list.\n";
    return head;
}

node* addBefore(node *head, int item, int data){ // To insert before a specific element!
    node *p;
    p = new node;
    p->data = data;
    p->next = NULL;

    // if linked list is Empty!
    if(!head){
        emptyList();
        return head;
    }

    // to insert in the beginning i.e. item is the first element in the linked list!
    if(head->data == item){
        head = addAtBeg(head, data);
        return head;
    }

    // if the given item element is not present in the list!
    if(searchList(head, item) == -1){
        cout << "\n" << item << " not present in the linked list.\n";
        return head;
    }
    
    // for other cases!
    node *tmp = head;
    while(tmp != NULL && tmp->next->data != item){
        tmp = tmp->next;
    }

    p->next = tmp->next;
    tmp->next = p;
    return head;
}

node *del(node *head, int data){ // Used to delete the elements from the linked list!
    if(!head){
        emptyList();
        return head;
    }

    // if first node is to be deleted!
    if(head->data == data){
        node *tmp = head;
        head = head->next;
        int key = tmp->data;
        cout << "\n" << key << " deleted!\n";
        free(tmp);
        return head;
    }

    // if element not present in the linked list!
    if(searchList(head, data) == -1){
        cout << "\nElement not present in the linked list.\n";
        return head;
    }

    // deleting other nodes!
    node *tmp = head;
    while(tmp != NULL && tmp->next->data != data){
        tmp = tmp->next;
    }

    node *t = tmp->next;
    int key = t->data;
    tmp->next = t->next;
    cout << "\n" << key << " deleted!\n";
    free(t);
    return head;
}

node *Rdel(node *head){ // Used to completely delete the linked list!
    if(head == NULL){
        return head;
    }
    node *t;
    t = Rdel(head->next);
    free(head);
    return t;
}

node* reverseList(node *head){ // To reverse the linked list!
    node *ptr, *prev, *next;
    prev = NULL;
    ptr = head;
    while(ptr != NULL){
        next = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = next;
    }
    head = prev;
    return head;
}

node* createList(node *head){ // To create a new linked list!
    if(head != NULL){
        head = Rdel(head);
    }
    int n ,data;
    cout << "\nEnter the number of nodes: ";
    cin >> n;
    if(n == 0){
        return head;
    }
    cout << "\nEnter the element " << "1: ";
    cin >> data;
    head = addAtBeg(head, data);
    for(int i = 2; i <= n; i++){
        cout << "Enter the element " << i << ": ";
        cin >> data;
        head = addAtEnd(head, data);
    }
    return head;
}

int main(){

    int choice, data, pos;
    int t;
    node *head = NULL;
    cout << "\nThese are the choices: \n";
    
    while(1){
        cout << "\n1.Create a new Linked List.\n";
        cout << "2.Display the linked list.\n";
        cout << "3.Count the number of nodes in the linked list.\n";
        cout << "4.Search any key in the linked list.\n";
        cout << "5.Add at beginning / Add to Empty List.\n";
        cout << "6.Add at end.\n";
        cout << "7.Add after node.\n";
        cout << "8.Add before node.\n";
        cout << "9.Add at position.\n";
        cout << "10.Delete an element in the linked list.\n";
        cout << "11.Completely delete the linked list.\n";
        cout << "12.Reverse the linked list.\n";
        cout << "13.Quit from the program.\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1: 
            head = createList(head);
            break;

            case 2:
            display(head);
            break;

            case 3:
            cout << "\nCount: " << countNodes(head) << "\n";
            break;

            case 4:
            cout << "\nEnter the element to search: ";
            cin >> data;
            t = searchList(head, data);
            if(t == -1){
                cout << "\nElement not present in the linked list.\n";
            }
            else if(t > 0){
                cout << "\nElement present at location " << t <<"!\n";
            }
            else{
                emptyList();
            }
            break;

            case 5:
            cout << "\nEnter the element to add at beginning: ";
            cin >> data;
            head = addAtBeg(head, data);
            break;

            case 6:
            cout << "\nEnter the element to add at end: ";
            cin >> data;
            head = addAtEnd(head, data);
            break;

            case 7:
            cout << "\nEnter the element to insert: ";
            cin >> data;
            cout << "Enter the element after which to insert: ";
            cin >> pos;
            head = addAfter(head, pos, data);
            break;

            case 8:
            cout << "\nEnter the element to insert: ";
            cin >> data;
            cout << "Enter the element before which to insert: ";
            cin >> pos;
            head = addBefore(head, pos, data);
            break;

            case 9:
            cout << "\nEnter the position: ";
            cin >> pos;
            cout << "Enter the element to add at a given position: ";
            cin >> data;
            head = addAtPos(head, pos, data);
            break;

            case 10:
            cout << "\nEnter the element to delete: ";
            cin >> data;
            head = del(head, data);
            break;

            case 11:
            head = Rdel(head);
            break;

            case 12:
            head = reverseList(head);
            break;

            case 13:
            exit(1);
            break;

            default:
            cout << "\nWrong Choice.\n";
        }
    }
    return 0;
}