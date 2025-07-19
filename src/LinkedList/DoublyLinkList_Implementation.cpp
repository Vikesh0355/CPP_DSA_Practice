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
void ReverseLinkedList() 
{
    node* currentnode = head;
    node* prevnode = nullptr;
    node* nextnode = nullptr;

    // Iterate through the list until the next node is NULL (end of the list)
    while (currentnode != NULL) 
    {
        // Store the next node temporarily
        nextnode = currentnode->next;

        // Reverse the 'next' pointer of the current node to point to the previous node
        currentnode->next = currentnode->prev;

        // Move the previous node pointer forward to the current node
        currentnode->prev = nextnode;
        
        // Move prev to current node
        prevnode = currentnode;
        
        // Move the current node pointer forward to the next node
        currentnode = nextnode;
 
    }

    // Once the loop finishes, prevnode will be pointing to the new head of the reversed list
    head = prevnode;

    // Display the reversed linked list (you need a display function to print the list)
    display();
}

void delete_FromBeginning(void)
{
    cout<<"delete from beginning is called\n";
    
    node* ToDelete = nullptr;
    node* nextnode = nullptr;
    
    nextnode = head->next; // move nextnode one position forward to head node
    nextnode->prev = NULL; // now assigned nextnode->prev with NULL. since first node from list will be deleted
    delete(ToDelete);
    head = nextnode;
    display();
    
}

void delete_FromEnd(void)
{
    cout << "delete from End is called\n";

    // If the list is empty, nothing to delete
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    node* ToDelete = nullptr;
    node* currentnode = head;

    // If there is only one node
    if (currentnode->next == NULL) {
        ToDelete = currentnode;  // Only one node to delete
        head = NULL;              // Set head to NULL since the list will be empty now
        delete ToDelete;          // Delete the only node
        display();
        return;
    }

    // Traverse to the last node
    while (currentnode->next != NULL) {
        currentnode = currentnode->next;
    }

    // currentnode is now the last node
    ToDelete = currentnode;         // ToDelete will be the last node
    currentnode->prev->next = NULL; // Set second-to-last node's next to NULL
    delete ToDelete;                // Delete the last node

    display();
}

void delete_FromPosition(void)
{
    cout << "delete from position is called\n";
    
    node* ToDelete = nullptr;
    node* currentnode = head;
    int pos, i = 1;
    
    cout << "Enter the position which you want to delete\n";
    cin >> pos;
    
    // Check for an invalid position (either less than 1 or greater than list length)
    int length = getLength();
    if (pos < 1 || pos > length) {
        cout << "Invalid position!\n";
        return;
    }
    
    // If deleting the first node (head)
    if (pos == 1) {
      delete_atBeginning();          
    }
    else {
        // Traverse the list to find the node at the given position
        while (i < pos) {
            currentnode = currentnode->next;
            i++;
        }

        // currentnode now points to the node at position 'pos'
        ToDelete = currentnode;

        // If deleting the last node
        if (currentnode->next == nullptr) {
            delete_FromEnd();
        }
        else {
            // Update the pointers for the node before and after the one to delete
            currentnode->prev->next = currentnode->next;
            currentnode->next->prev = currentnode->prev;
            delete ToDelete;  // Delete the node
            display();  // Display the updated list
        }

        
    }
    
    
}

int main()
{
    Create_DoublyLinkedList();  // Create the list
    display();  // Display the list
    Insert_atBeginning();
    Insert_atEnd();
    Insert_atPosition();
    ReverseLinkedList();
    delete_FromBeginning();
    delete_FromEnd();
    delete_FromPosition();
    return 0;
}
