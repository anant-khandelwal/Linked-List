#include <iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* next;

    /*
    node ke andar 2 cheeze - ek data, ek agle node ka pointer
    ab data ko data likh diya aur next node ke pointer ko next boldiya
    */

    //constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL; //assume kr rhe hai ki aage kuch nahi isliye null
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
    void insertAtHead (Node* &head, int d) //head kyuki idhar next ki value head hai
    //reference isliye kyuki copy LL nahi chahta jo original LL hai usme hi ho
    {
        //new node create
        Node* temp = new Node(d); //dynamic mvem allocated coz of new keyword
        temp -> next = head; //temp ka next voh current head pe hona chaiye jo node pehele 1st tha
        head = temp; //ab finally head temp mein hoga kyuki voh first hai
    }

    //Insert at tail
    void insertAtTail (Node* &tail, int d)
    {
        Node *temp = new Node(d);
        tail -> next = temp; //kyuki tail ka jo pointer hai voh ab temp mein point karega
        tail = temp; //temp nayi tail ban jayega
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

    //beech mein ghusane ke liye
    while (count < position)
    {
        previous = previous -> next;
        count ++;
    }

    //creating a node
    Node *temp = new Node (d);
    //previous wali node ka next temp ke next ko dega apni value kyuki ab naya banda hai beech mein
    previous -> next = temp;
    //nayi node mangega pehele wale se uske next ki value kyuki voh uski jagah hai
    temp -> next = previous -> next; 

    //ab tail ke case ke liye agar mujhe length de rakhi hoti linked list ki
    /* tab toh
    if (position + 1  = length){
        insertAtTail (tail, d);
        return;
    }    
    *///par apan ko length nahi pata 

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
    void print(Node* &head){ //head pass karunga taaki pata chale kaha se shuru krna hai
        Node* temp = head; // maine ek pointer bana diya traverse krne ke liye
        while (temp!=NULL) //jab tak mera temp null ke qual nahi hota chalne de
        {
            cout << temp -> data << " ";
            //cout << temp << " ";
            temp = temp -> next; //temp ko aage badhane ke liye next node ka pointer banjaa jo ki next mein stored hai
        }
        cout << endl;
    }

int main(){
    Node *node1 = new Node(10); //pointer banaya node1 fir new ki madad se dynamilcally mem allocate ki

    Node *head = node1; //pointer head ke andar node1 ka address store krwa diya
    Node *tail = node1; //similarly for tail kyuki jab ek node hoti hai tab head aur tail same hote hai

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