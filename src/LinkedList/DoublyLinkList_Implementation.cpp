#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node* next;
    struct node* prev;
};

struct node* newnode = NULL;
struct node* temp = NULL;
struct node* head = NULL;

void Create_DoublyLinkedList(void)
{
    int choice = 1;
    while(choice)
    {
        newnode = new struct node;  // Creating new node
        if(newnode == NULL)  // Check for memory allocation failure
        {
            cout << "newnode creation failed\n";
            return;  // Exit if memory allocation fails
        }

        cout << "Enter the data\n";
        cin >> newnode->data;

        // Initialize next and prev pointers to NULL
        newnode->next = NULL;
        newnode->prev = NULL;

        // If head is NULL, make this the first node
        if(head == NULL)
        {
            head = temp = newnode;
        }
        else
        {    
            temp->next = newnode;  // Set the next of the last node to the new node
            newnode->prev = temp;  // Set the previous of the new node to the last node
            temp = newnode;        // Move temp to the new node
        }

        cout << "Do you want to continue? Press 1 to continue, 0 to exit: ";
        cin >> choice;
    }
}

void display()
{
    temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void Insert_atBeginning(void)
{       temp = head; // initialize the temp with head
        newnode = new struct node;
        if(newnode == NULL)
        {
            cout<<"newnode creation failed\n";
            return;
        }
        cout<<"Enter the data to insert at beginning of node\n"<<endl;
        cin>>newnode->data;
        
        head = newnode; //shift the head to newnode
        newnode->prev = NULL;// assign newnode->prev to NULL since it will be first node in updated list
        newnode->next = temp; // connect the original node with newnode->next 
        display();
}


void Insert_atEnd(void)
{       temp = head; // initialize the temp with head
        newnode = new struct node;
        if(newnode == NULL)
        {
            cout<<"newnode creation failed\n";
            return;
        }
        cout<<"Enter the data to insert at end of the node\n"<<endl;
        cin>>newnode->data;
        
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;// connnect this new node as last node of update list
        newnode->prev = temp;//assign address of original list, last node to newnode->prev
        newnode->next = NULL; // assign null to newnode->next since it is last node of updated list

        display();
}

int getLength()
{
    int count =0;
    struct node *temp;
    temp = head;
    while(temp!=NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void Insert_atPosition(void)
{       
    int pos, len;
    int i =1;
    cout<<"Enter the position\n";
    cin>>pos;
    len = getLength();

    if((pos<0 ) || (pos>len))
    {
        printf("Invalid position\n");
    }
    else if(pos ==1)
    {
        Insert_atBeginning(); 
    }
    else
    {
      
        temp = head; // initialize the temp with head
        newnode = new struct node;
	    cout<<"Enter the data you want to insert at Pos\n";
	    cin>>newnode->data; 
	    while(i<pos-1)
	    {
	     temp = temp->next;
	     i++;
	    }
	   newnode->prev = temp; // assign newnode->prev with temp since it is holding pos-1 node address
	   newnode->next = temp->next;// assign newnode->next with temp->next since it is holding pos+1 node address
	   temp->next = newnode; // connect temp->next to newnode
	   newnode->next->prev = newnode; // connect pos+1 node prev to newnode
    }

    display();
}

int main()
{
    Create_DoublyLinkedList();  // Create the list
    display();  // Display the list
    return 0;
}
