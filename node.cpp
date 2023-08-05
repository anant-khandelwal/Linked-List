#include <iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* next;

    
    //constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL; 
    }

    
    //destructor
~Node()
{
    int value = this -> data = data;
    
    //memory free
    if (this-> next != NULL)
    {
        delete next;
        this -> next = NULL;
    }
    cout << "Memory is free for node with data " << value << endl;
    
} 
    
     
   
};


    //Insert at head
    void insertAtHead (Node* &head, int d)
    
    {
      
        Node* temp = new Node(d);
        temp -> next = head; 
        head = temp; 
    }

    //Insert at tail
    void insertAtTail (Node* &tail, int d)
    {
        Node *temp = new Node(d);
        tail -> next = temp; 
        tail = temp; 
    }

    //now insert at middle or any position



void insertAtPosition (Node *&head, Node *&tail, int position, int d){

    //if want to insert at head
    if (position == 1)
    {
        insertAtHead (head, d);
        return;
    }   

    Node *previous = head;
    int count = 1;

    
    while (count < position)
    {
        previous = previous -> next;
        count ++;
    }

    //creating a node
    Node *temp = new Node (d);
   
    previous -> next = temp;
  
    temp -> next = previous -> next; 

    
    /* if length was given
    if (position + 1  = length){
        insertAtTail (tail, d);
        return;
    }    
    *///but length is not given,
    //so we will use this for inserting at tail
    if (temp -> next = NULL)
    {
        insertAtTail (tail, d);
        return;
    }
         
}

void deleteNode (Node *&head, int position)
{
    //deleting first or start node
    if (position == 1)
    {
        Node *temp = head;
        head = head -> next;
        //memory freeing of start node
        temp -> next = NULL;
        delete temp;
    }
    
    
    else
    {
        //deleting any middle node or last node
        Node *curr = head;
        Node *prev = NULL;

        int count = 1;
        while (count < position)
        {
            prev = curr;
            curr = curr -> next;
            count ++;            
        }

        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;        
    }
}

    //print
    void print(Node* &head){ 
        Node* temp = head;
        while (temp!=NULL) 
        {
            cout << temp -> data << " ";
            //cout << temp << " ";
            temp = temp -> next; 
        }
        cout << endl;
    }

int main(){
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1; 

    print(head);

    insertAtHead (head, 14);
    print(head);

    insertAtHead (head, 17);
    print(head);    

    insertAtTail (tail, 7);
    print(head);     

    /*insertAtPosition (head, tail, 1, 97);
    print(head); */

    deleteNode (head, 3);
    print(head); 


}
