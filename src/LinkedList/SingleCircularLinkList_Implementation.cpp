#include <iostream>
#include <unistd.h>
#include <cstring>

using namespace std;

struct node
{
    int data;
    struct node* next;
};
struct node* head = nullptr;
struct node* tail = nullptr;
struct node* newnode = NULL;

void create_SingleCLL()
{
    int choice = 1;
    while(choice)
    {
        newnode = new struct node;
        if(newnode== nullptr)
        {
            cout<<"newnode creation failed\n"<<endl;
        }
        cout<<"Enter the data for newnode\n"<<endl;
        cin>>newnode->data;
        newnode->next = nullptr;
        if(head == nullptr)
        {
            head = tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        tail->next = head;
        cout<<"do you want to continue: press 1 to conitnue : 0 for exit\n"<<endl;
        cin>>choice;

    }
}

void display()
{
    
    if (head == nullptr) return;  // In case the list is empty
    
    struct node* temp = head;
    
    do
    {
        cout <<temp->data<<" ";
        temp = temp->next;
    }while(temp!= head);
    cout<<endl;
}

void insert_atBeginning()
{   
    cout<<"insert at beginning is called\n";
    struct node* newnode = new struct node;


    if(newnode == nullptr)
    {
        cout<<"newnode creation failed\n"<<endl;
    }
    cout<<"Enter the data for newnode\n"<<endl;
    cin>>newnode->data;
    newnode->next = head;
    head = newnode;
    tail->next = head;

    display();

}

void insert_atEnd()
{   
    cout<<"insert at End is called\n";
    struct node* newnode = new struct node;


    if(newnode == nullptr)
    {
        cout<<"newnode creation failed\n"<<endl;
    }
    cout<<"Enter the data for newnode\n"<<endl;
    cin>>newnode->data;
    tail->next = newnode;
    newnode->next = head;

    display();

}
void insert_atPos()
{   
    
    int position, i =1;
    cout<<"Enter the position where newnode will be inserted?\n";
    cin>>position;
    struct node* ToPosition = head;
    while(i<position-1)
    {
       ToPosition = ToPosition->next;
       i++;
    }
    
    struct node* newnode = new struct node;
    
    if(newnode == nullptr)
    {
        cout<<"newnode creation failed\n"<<endl;
    }
    cout<<"Enter the data for newnode\n"<<endl;
    cin>>newnode->data;
    
    newnode->next = ToPosition->next;
    ToPosition->next = newnode;

    display();

}
void Deleted_FromBeginning()
{
    cout<<"Delete from Beginning\n";
    struct node* ToDelete = head;
    
    head = head->next;
    tail->next = head;
    delete(ToDelete);
    display();
    
}

void Delete_fromEnd()
{
    cout << "Delete from end is called\n";
    
    if (head == nullptr)  // Case: empty list
    {
        cout << "The list is already empty.\n";
        return;
    }

    if (head == tail)  // Case: only one node in the list
    {
        delete head;  // Delete the only node
        head = tail = nullptr;  // Set head and tail to nullptr (empty list)
        cout << "The only node has been deleted.\n";
        display();
        return;
    }
    // Case: More than one node in the list
    struct node* prevnode = head;
    while (prevnode->next != tail)  // Find the node before the tail
    {
        prevnode = prevnode->next;
    }
    delete(tail);
    tail = prevnode;
    prevnode->next = head;
    display();
   
}

void Delete_fromPos()
{
    struct node* Todelete = nullptr;
    struct node* temp = head;
    int pos = 0, i = 1;
    
    cout<<" delete from position is called\n";
    cin>>pos;
    if(pos==1)
    {
        Delete_FromBeginning();
        return ;
    }
    else
    {
        
        // Traverse to the node just before the position
        while (temp != nullptr && i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        if(temp->next == tail)
        {
            Delete_fromEnd();
            return ;
        }
        else
        {
            Todelete = temp->next;
            temp->next = temp->next->next;
            delete(Todelete);
            
        }
    }
    display();
}

void ReverseCLL()
{
    cout << "ReverseCLL is called\n";
    if (head == NULL)  // Check if the list is empty
    {
        cout << "List is empty\n";
        return;
    }

    struct node *current, *nextnode, *prev;
    current = head;
    prev = nullptr;
    nextnode = nullptr;
    
    do
    {
        nextnode = current->next;  // Save the next node
        current->next = prev;  // Reverse the 'next' pointer
        prev = current;  // Move prev to current
        current = nextnode;  // Move current to next
    } while (current != head);  // Continue until we come back to the head

    // After the loop, prev will be the new head, so update it
    head = prev;

    // Update the tail, which was originally the head
    tail = head;
    // Traverse to the original tail to set the correct next pointer
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }
    tail->next = head;  // Maintain the circular structure

    display();  // Show the reversed list
}
int main()
{
   create_SingleCLL();
   display();
   insert_atBeginning();
   insert_atEnd();
   insert_atPos();
   Deleted_FromBeginning();
   Delete_fromEnd();
   Delete_fromPos();
   ReverseCLL();
   return 0;
}