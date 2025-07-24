#include<iostream>
using namespace std;

struct ListNode
{
    int data; 
    struct ListNode* next;
};

struct ListNode* front = nullptr;
struct ListNode* rear  = nullptr;

void Enqueue(int x)
{
    struct ListNode* newnode = new struct ListNode;  
    if(newnode == nullptr)
    {
        cout << "Memory creation failed\n" << endl;   
        return;  // Add return to stop execution if allocation fails
    }

    newnode->data = x;
    newnode->next = nullptr;

    if(front == nullptr && rear == nullptr)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}

void display(void)
{
    struct ListNode* temp;
    if(front == nullptr && rear == nullptr)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        temp = front;
        while(temp != nullptr)
        {
            cout << temp->data << " ";  
            temp = temp->next;
        }
        cout << endl;
    }
}

void Dequeue(void)
{
    struct ListNode* temp;
    temp = front;

    if(front == nullptr && rear == nullptr)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Dequeued element is: " << front->data << endl;
        front = front->next;
        delete temp;  // Only delete the node once
        if(front == nullptr)  // If the queue is empty after dequeue, set rear to nullptr
        {
            rear = nullptr;
        }
    }
}

void peak(void)
{
    if(front == nullptr && rear == nullptr)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Peak is: " << front->data << endl;
    }
}

int main()
{
    Enqueue(10);
    Enqueue(20);
    Enqueue(30);
    display();
    Dequeue();
    peak();
    
    return 0;
}
