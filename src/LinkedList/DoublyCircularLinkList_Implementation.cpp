#include<iostream>
#include<cstring>
using namespace std;

struct node
{
    int data;
    struct node* next;
    struct node* prev;  
};

struct node* head = nullptr;
struct node* tail = nullptr;

void display();

void create_DoublyCLL()
{
    int choice = 1;
    while(choice)
    {
        struct node* newnode = new struct node;
        if(newnode == nullptr)
        {
            cout<<"New node creation failed\n";
            exit(1);
        }
        cout<<"Enter the data for newnode\n";
        cin>>newnode->data;

        if(head == nullptr)
        {
            head = tail = newnode;
            newnode->prev = nullptr;
            newnode->next = nullptr;
        }
        else
        {
           
            tail->next = newnode; // assign newnode address to tail node
            newnode->prev = tail; // assign nenode->prev with tail address
            tail = newnode; // shift tail to newnode
        
        }
        tail->next = head; // assigned tail->next with head address
        cout << "Do you want to continue? Press 1 to continue, 0 to exit: ";
        cin >> choice;

    }
    display();
}

void display()
{
    struct node* temp = head;
    if (head == nullptr) return;  // In case the list is empty
    
    do
    {
        cout <<temp->data<<" ";
        temp = temp->next;
    }while(temp!= head);
    cout<<endl;

}

int getLength_DoublyCLL()
{
    int count = 0;
    
    struct node* temp = head;
    if (head == nullptr) return count;  // In case the list is empty
    do
    {
        count++;
        temp = temp->next;
    }while(temp!= head);
    cout<<"total number of node in the list is: "<<count<<endl;
   return count;
}

void insert_atBeginning()
{
    struct node* newnode = new struct node;
    if(newnode == nullptr)
    {
        cout<<"New node creation failed\n";
        exit(1);
    }
    cout<<"Enter the data for to insert at beginning of the node\n";
    cin>>newnode->data;
    newnode->next = head;
    newnode->prev = nullptr;
    head->prev = newnode;
    head = newnode;
    tail->next = head;
    display();
    (void)getLength_DoublyCLL();

}

void insert_atEnd()
{
    struct node* newnode = new struct node;
    if(newnode == nullptr)
    {
        cout<<"New node creation failed\n";
        exit(1);
    }
    cout<<"Enter the data for to insert at end of the node\n";
    cin>>newnode->data;
    newnode->next = head; // since here newnode will be the last node in the list. so newnode->next will hold address of head
    newnode->prev = tail; // and newnode->prev will connect to tail of  existing node
    tail->next = newnode; // connect tail_next with last  newnode of the list
    tail = newnode; // move the tail pointer to newnode;
    display();
    (void)getLength_DoublyCLL();
      
}

void insert_atPosition()
{
    int pos = 0, length = 0, i = 0;
    
    struct node* newnode = new struct node;

    struct node* ToPosition = head;
    
    if(newnode == nullptr)
    {
        cout<<"New node creation failed\n";
        exit(1);
    }
    cout<<"enter the postion where you want to add newnode\n";
    cin>>pos;
    length = getLength_DoublyCLL();
    if(pos<=0 || pos>length)
    {
        cout<<"invalidlength\n";
    }
    else if(pos == 1)
    {
       insert_atBeginning();
    }
    else if(pos == length)
    {
     
       insert_atEnd(); 
    }
    else
    {
        while(i<pos-1)
        {
            ToPosition = ToPosition->next; // here ToPosition is holding the address of pos-1 node
            i++;
        }
        cout<<"Enter the data of positional node\n";
        cin>>newnode->data;
        
        newnode->next = ToPosition->next->next; // store newnode->next with address of pos+1 node 
        newnode->prev = ToPosition->next; //store newnode->prev with address of pos
        ToPosition->next = newnode; // store pos  node->next with address of newnode;
        ToPosition->next->prev = newnode; // store pos+1 node->prev with newnode;
        display();       
    }
      
}

int main()
{
    create_DoublyCLL();
    insert_atBeginning();
    insert_atEnd();
    insert_atPosition();
    
    return 0;
}