#include<iostream>
using namespace std;

#define N 5
int queue[N];

int front  = -1;
int rear   = -1;

void Enqueue(int x)
{
    /* check if queue is full*/
    /* if rear +1  == front */
    if((rear+1)%N == front)
    {
        cout<<"Queue is full\n";
    }
    else if(front == -1 && rear == -1) // check if queue is empty
    {
        front = rear = 0;
        queue[rear] = x;

    }
    else
    {
        rear = (rear+1)%N; // increment the rear first then store the value. 
        queue[rear] = x;
    }
}

void Dequeue(void)
{
    /*check if queue is empty*/
    if(front == -1 && rear == -1)
    {
        cout<<"Queue is empty\n";
    }
    else if(front == rear)// if there is only one element
    {
      
      cout <<"Dequeud element is "<<queue[front]<<endl;
      front = rear = -1;
    }
    else
    {
        cout <<"Dequeud element is "<<queue[front]<<endl;
        front = (front+1)%N; // incerement the front
    }
}

void Display()
{
    /*check if the queue is empty*/
    if(front == -1 && rear == -1)
    {
        cout<<"Queue is empty\n";
    }
    else
    {
        int i = front;
        // print the element from front till rear. But since it is circular so we can't write i<rear
        // while loop will print from front till rear -1. then in last just print rear element
        while(i!= rear) 
        {
            cout<<queue[i]<<" ";  
            i = (i+1)%N;
        }
        cout<<queue[rear]<<endl;

    }
}

void peak()
{
        /*check if the queue is empty*/
    if(front == -1 && rear == -1)
    {
        cout<<"Queue is empty\n";
    }
    else
    {
        cout<<"peak is: "<<queue[front]<<endl;
    }
}

int main()
{
    Enqueue(10);
    Enqueue(20);
    Enqueue(30);
    Display();
    peak();
    Dequeue();
    Dequeue();
    Display();
    return 0;
}