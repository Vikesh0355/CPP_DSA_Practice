#include <iostream>
#include <unistd.h>
#include <cstring>
#include <sys/types.h>
using namespace std;

struct node
{
    int data ;
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

int main()
{
    create_SingleLinkedList();
    display();
    return 0;
}