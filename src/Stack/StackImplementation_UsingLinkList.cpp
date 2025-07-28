#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node* link;
};

struct node* top = nullptr;

void push(int x)
{
    // Allocate memory for a new node
    struct node* newnode = new struct node;

    // Initialize the new node
    newnode->data = x;
    newnode->link = nullptr;

    // If the stack is empty, the new node becomes the top
    if(top == nullptr)
    {
        top = newnode;
    }
    else
    {
        // If the stack is not empty, add the new node on top
        newnode->link = top;
        top = newnode;
    }
}


void pop(void)
{
    if(top == nullptr)
    {
        cout<<"stack is empty\n";
        return;
    }
    else
    {
        struct node* temp = top;
        top = top->link;
        cout<<"Popped element is: "<<temp->data<<endl;
        delete(temp);
    }
}

void peak()
{
    if(top == nullptr)
    {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Top element is: " << top->data << endl;
}

void display()
{
    struct node* temp = top;

    if(top == nullptr)
    {
        cout << "Stack is empty\n";
        return;
    }

    while(temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp = temp->link;
    }
    cout<<endl;
}

int main()
{
    push(10);
    push(20);
    push(30);

    display();  

    peak();     

    pop();
    display();  

    return 0;
}