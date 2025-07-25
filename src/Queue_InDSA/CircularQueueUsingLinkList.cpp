#include <iostream>
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
    
    if (newnode == nullptr)
    {
        cout << "Node creation failed\n";
        return;  // Stop execution if allocation fails
    }

    newnode->data = x;
    newnode->next = nullptr;

    if (front == nullptr && rear == nullptr)  // Check if the queue is empty
    {
        front = rear = newnode;
        rear->next = front;  // Make the queue circular by connecting rear to front
    }
    else
    {
        rear->next = newnode;  // Rear points to the new node
        rear = newnode;        // Move rear to the new node
        rear->next = front;    // Make the queue circular
    }
}

void Dequeue(void)
{
    if (front == nullptr && rear == nullptr)
    {
        cout << "Queue is empty" << endl;
        return;
    }

    struct ListNode* temp = front;
    if (front == rear)  // Only one element in the queue
    {
        front = rear = nullptr;  // The queue becomes empty
    }
    else
    {
        front = front->next;
        rear->next = front;  // Maintain the circular link
    }
    
    cout << "Dequeued element is: " << temp->data << endl;
    delete temp;  // Free the dequeued node
}

void display(void)
{
    if (front == nullptr && rear == nullptr)
    {
        cout << "Queue is empty" << endl;
        return;
    }
    
    struct ListNode* temp = front;
    do
    {
        cout << temp->data << " ";  // Print the element with a space
        temp = temp->next;  // Move to the next node
    } while (temp != front);  // Stop when we've looped back to the front
    
    cout << endl;  // Print a newline after displaying all elements
}

void peak(void)
{
    if (front == nullptr && rear == nullptr)
    {
        cout << "Queue is empty" << endl;
        return;
    }
    
    cout << "Peak is: " << front->data << endl;
}

int main()
{
    Enqueue(10);
    Enqueue(20);
    Enqueue(30);
    display();   // Display queue
    Dequeue();   // Dequeue an element
    peak();      // Peak at the front element
    display();   // Display queue after dequeue
    return 0;
}
