#include<iostream>
using namespace std;

#define N 5

// Defining s1, s2 for arrays and top1, top2 for stack pointers
int s1[N];
int s2[N];
int top1 = -1;
int top2 = -1;

// Function Declarations
void enqueue();
void dequeue();
void push1(int a);
void push2(int a);
int pop1();
int pop2();
void display();
void peak();

void enqueue()
{
    int data;
    if(top1 == N-1)
    {
        cout << "Overflow: Queue is full\n";
    }
    else
    {
        cout << "Enter the data: ";
        cin >> data;
        push1(data);  // Pushing data onto stack 1
    }
}

void dequeue()
{
    if(top1 == -1 && top2 == -1)
    {
        cout << "The queue is empty\n";
    }
    else
    {
        // Transfer all elements from stack1 to stack2
        while(top1 != -1)
        {
            int temp = pop1();
            push2(temp);
        }
        
        // Pop the top element from stack2 (dequeue operation)
        int dequeuedElement = pop2();
        cout << "The dequeued element is: " << dequeuedElement << endl;

        // Transfer elements back from stack2 to stack1
        while(top2 != -1)
        {
            int temp = pop2();
            push1(temp);
        }
    }
}

void peak()
{
    if(top1 == -1 && top2 == -1)
    {
        cout << "The queue is empty\n";
    }
    else
    {
        // If stack2 is empty, transfer all elements from stack1 to stack2
        while(top1 != -1)
        {
            int temp = pop1();
            push2(temp);
        }

        // The top of stack2 is the front of the queue
        cout << "The front element (Peak) is: " << s2[top2] << endl;

        // Transfer elements back from stack2 to stack1
        while(top2 != -1)
        {
            int temp = pop2();
            push1(temp);
        }
    }
}

int pop1()
{
    return s1[top1--];
}

int pop2()
{
    return s2[top2--];
}

void push1(int a)
{
    if(top1 == N-1)
    {
        cout << "Overflow: Stack 1 is full\n";
    }
    else
    {
        s1[++top1] = a;
    }
}

void push2(int a)
{
    if(top2 == N-1)
    {
        cout << "Overflow: Stack 2 is full\n";
    }
    else
    {
        s2[++top2] = a;
    }
}

void display()
{
    if(top1 == -1 && top2 == -1)
    {
        cout << "There are no elements in the queue.\n";
        return;
    }

    // Display elements from stack2 (dequeue side)
    for(int i = top2; i >= 0; i--)
    {
        cout << s2[i] << " ";
    }

    // Display elements from stack1 (enqueue side)
    for(int i = 0; i <= top1; i++)
    {
        cout << s1[i] << " ";
    }

    cout << endl;
}

int main()
{
    int choice;
    
    // Menu
    cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Peak\n5. Exit\n";
    
    while(1)
    {
        cout << "Enter the choice: ";
        cin >> choice;
        
        switch(choice)
        {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                peak();
                break;
            case 5:
                return 0;  // Exit the program
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
