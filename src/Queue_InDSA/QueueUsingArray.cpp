/*Queue is Linear data structure where insertion is perfomed from front and deleteion is performed from rear.*/
/*Insertion is known as Enqueue and Deletion is is known as Dequeue*/

/*Queue operations:
1. Enqueue
2. Dequeue
3. front/Peak
4. isFull 
5. isEmpty */

#include<iostream>
using namespace std;

#define N 5

int queue[N];
int front = -1;
int rear = -1;

void display();

void Enqueue(int x)
{
    if(rear == N-1)
    {
     cout<<" Overflow condtion\n";

    }
    else if(front == -1 && rear == -1)
    {
     front = rear = 0;
     queue[rear] = x;
    }
    else
    {
     rear++;
     queue[rear] = x;
    }

}

void Dequeue(void)
{
    if(front == -1 && rear == -1)
    {
      cout<<"queue is empty\n";
    }
    else if(front ==  rear ) /*means there is only one element in queue*/
    {
      cout<<"dequeued Elemnt is: "<<queue[front]<<endl;  
      front = rear = -1; /*now set front and rear to -1 to make queue is empty */

    }
    else
    {
      
      cout<<"dequeued Elemnt is: "<<queue[front]<<endl;  
      front++; /* move the front one element ahead */

    }

}

void display()
{
    cout<<"Element of queue is: ";
    if(front == -1 and rear == -1)
    {
        cout<<"Queue is empty\n";
    }
    else
    {
        for(int i = front; i<=rear; i++)
        {
            cout<<" "<<queue[i];
        }
        cout<<endl;
    }
}

void peak(void)
{
    if(front == -1 and rear == -1)
    {
        cout<<"Queue is empty\n";
    }
    else
    {
        cout<<"peak is "<<queue[front]<<endl;
    }

}

int main()
{
    Enqueue(10);
    Enqueue(20);
    Enqueue(30);
    display();
    Dequeue();
    display();
    peak();
    return 0;
}