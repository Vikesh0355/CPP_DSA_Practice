#include <iostream>
#include <unistd.h>
#include <cstring>
#include <sys/types.h>
using namespace std;

struct node
{
    int data;
    struct node* next;
};

struct node* newnode = NULL;
struct node* temp = NULL;
struct node* head = NULL;
 
void create_SingleLinkedList(void)
{
    int choice = 1;
    while(choice)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        if(newnode==NULL)
        {
            cout<<" memory creation failed\n"<<endl;
            
        }
        cout<<"Enter the data\n"<<endl;
        cin>>newnode->data;
        if(head== NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        cout<<"do you want to continue: press 1 to conitnue : 0 for exit\n"<<endl;
        cin>>choice;
    }

}

 void display()
 {
    temp = head;
    while(temp != NULL)
    {
        cout <<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
 }
 
 void insert_atbeginning(void)
 {
    newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL)
    {
        exit(1);
    }
    cout<<"Enter the data you want to insert at beginning\n"<<endl;
    cin>>newnode->data;
    temp = head;
    head = newnode;
    head->next = temp;
    display();
 }
 
 void insert_atEnd(void)
 {
    newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL)
    {
        exit(1);
    }
    
    cout<<"Enter the data you want to insert at end\n";
    cin>>newnode->data;
    newnode->next = NULL;
    
    temp = head; // assign temp to head for traversal to last
    while(temp->next!=NULL)
    {
            
            temp = temp->next; // moved the temp till last node;
    }
    temp->next = newnode; // now assigned temp->next to newnode
    display();
 }
 
 void insert_atPosition()
 {
    int position, i = 1;
    newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL)
    {
         exit(1);
    }
     
    cout<<"Enter the  new poition\n";
    cin>>position;
    cout<<"Enter the data for new position\n";
    cin>>newnode->data;
    newnode->next = NULL;
        
    temp = head; // assign temp to head for traversal to last
    while ( i < position-1)
    {
        temp = temp->next;
        i++;
    }
    newnode->next = temp->next; // in newnode->next assign nextnode
    temp->next = newnode; // link the given postion node
    display();
 }
 
 int main()
 {
    create_SingleLinkedList();
    display();
    insert_atbeginning();
    insert_atEnd();
    insert_atPosition();
    return 0;
 }