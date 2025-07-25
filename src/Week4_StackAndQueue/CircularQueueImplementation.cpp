#include<iostream>
using namespace std;

class MyCircularQueue {
    public:
    int front ;
    int rear ;
    int* queue;
    int k ;
    MyCircularQueue(int k)
    {
     
     this->k = k;
     queue = new int[k];  // Initialize the queue with size k
     front = -1;  // Queue is empty initially
     rear = -1;   // Queue is empty initially
   }

    
    bool enQueue(int value) 
    {
        bool flag = false;
        if((rear+1)%k == front)
        {
            cout<<"Queue is full\n";
            flag =  false;
        }
        else if(front == -1 && rear == -1) // check if queue is empty
        {
            front = rear = 0;
            queue[rear] = value;
            flag = true;

        }
        else
        {
            rear = (rear+1)%k; // increment the rear first then store the value. 
            queue[rear] = value;
            flag = true;
        }
        return flag;
    }
    
    bool deQueue() 
    {
         bool val = false;
        if (front == -1 && rear == -1)
        {
            val =  false;
        }
        else if(front == rear)// if there is only one element
       {
      
          cout <<"Dequeud element is "<<queue[front]<<endl;
          front = rear = -1;
          val =  true;
        }
        else
        {
            front = (front+1)%k;
            val =  true;
            
        } 
        return val;
    }
    
    int Front() 
    {
        int val = 0;
        if(front == -1 && rear == -1)
        {
            val=  -1;
        } 
        else
        {
            val =  queue[front];
        } 
        return val;
    }
    
    int Rear() 
    {
        int val = 0;
        if(front == -1 && rear == -1)
        {
            val =  -1;
        } 
        else
        {
            val =  queue[rear];
        }
        return val;
    }
    
    bool isEmpty() 
    {
        bool val = false;
        if(front == -1 && rear == -1)
        {
            val =  true;
        }
        return val;
    }
    
    bool isFull()
    {
        
        bool val = false;
        if((rear+1)%k == front)
        {
          val =  true;  
        }
        return val;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */