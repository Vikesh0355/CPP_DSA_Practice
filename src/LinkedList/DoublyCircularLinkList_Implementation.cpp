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
void delete_fromBeginning()
{
    struct node* temp = head;
    cout << "Delete from beginning is called\n";

    // If there's only one node in the list
    if (head == tail) {
        delete temp;  // Delete the only node
        head = tail = nullptr;  // List is now empty
    } 
    else {
        tail->next = temp->next;  // Update tail's next to point to the head (because it's circular)
        head = temp->next;        // Move head to the next node
        head->prev = nullptr;     // Set the new head's prev to nullptr
        delete temp;              // Delete the old head node
    }

    display();  // Display the updated list
}


void delete_fromEnd()
{
    cout<<"Delete from End is called\n";
    
    // If the list is empty, nothing to delete
    if (head == nullptr)
    {
        cout << "List is empty\n";
        return;
    }
    
   struct node* ToDelete = nullptr;
   struct node* currentnode = head;
   
    // If there is only one node
    if (currentnode == tail) {
        ToDelete = head;  // Only one node to delete
        head = tail =  nullptr;              // Set head to NULL since the list will be empty now
        delete ToDelete;          // Delete the only node
        display();
        return;
    }
    
    // Traverse to the last node
    while (currentnode->next != head) 
    {
        currentnode = currentnode->next;
    }
    // currentnode is now the last node
    ToDelete = currentnode;         // ToDelete will be the last node
    currentnode->prev->next = head; // connect secondlast node->next with head 
    tail = currentnode->prev; // update the tail pointer with second last node
    delete ToDelete;                // Delete the last node

    display();
    
}

void delete_fromPosition()
{
    int pos = 0, length = 0, i = 0;
    
    struct node* ToPosition = head;
    
    cout<<"enter the node postion which you want to delete?\n";
    cin>>pos;
    length = getLength_DoublyCLL();
    if(pos<=0 || pos>length)
    {
        cout<<"invalidlength\n";
    }
    else if(pos == 1)
    {
       delete_fromBeginning();
    }
    else if(pos == length)
    {
     
       delete_fromEnd(); 
    }
    else
    {
      while(i<pos)
      {
        ToPosition = ToPosition->next;
        i++;
      }
      ToPosition->prev->next = ToPosition->next;// assign pos-1 node next part with pos+1 node address
      ToPosition->next->prev = ToPosition->prev;// assign pos+1 node prev part with pos-1 node address 
      delete(ToPosition);
      display();

    }
}

int main()
{
    create_DoublyCLL();
    insert_atBeginning();
    insert_atEnd();
    insert_atPosition();
    delete_fromBeginning();
    delete_fromEnd(); 
    delete_fromPosition();
    return 0;
}