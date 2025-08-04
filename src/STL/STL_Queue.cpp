#include <iostream>
#include<queue>
using namespace std;

void displayqueue(queue<int> data) // pass by value
{
    cout << "queue elements are: ";
    while(!data.empty())
    {
        cout << data.front() << " ";
        data.pop();
    }
    cout << endl;
}

int main()
{
    queue<int> data;
    for(int i = 0; i < 5; i++)
    {
        data.push(i);
    }

    data.pop(); // remove one element

    if(data.empty())
    {
        cout << "queue is empty\n";
    }
    else
    {
        cout << "size of queue is " << data.size() << endl;
        displayqueue(data);
    }
    cout<<"First Elemnt of queue is :"<<data.front()<<endl;
    cout<<"Last Element of Queue is: "<<data.back()<<endl;

    return 0;
}
