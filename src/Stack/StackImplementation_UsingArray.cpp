#include<iostream>
using namespace std;

#define SIZE_OF_STACK 5

int stack[SIZE_OF_STACK];
int top = -1;

void push(int x)
{
  if(top == SIZE_OF_STACK-1)
  {
    cout<<"stack is full\n";
    return ;
  }
  else
  {
    top++;
    stack[top] = x;
  }
}

void pop(void)
{
    if(top == -1)
    {
        cout<<"stack is empty\n";
        return ;
    }
    else
    {
        cout<<"poped element is :"<<stack[top]<<endl;
        top--;
    }
}

void peak(void)
{
    if(top == -1)
    {
        cout<<"stack is empty\n";
        return ;
    }
    else
    {
        cout<<"peak is :"<<stack[top]<<endl;
        
    }
}

void display(void)
{
    cout<<"stack element is :";
    for(int i = top; i>=0; i--)
    {
       cout<<stack[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    push(10);
    push(20);
    push(30);
    display();
    pop();
    peak();
    display();
    return 0;
}