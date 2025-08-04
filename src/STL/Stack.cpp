/*we have following  operation in stack
1. push
2. pop
3. top
4. empty
5. size*/

#include <iostream>
#include <stack>
using namespace std;

void displayStack(stack<int> data) // Pass by value (copy)
{
    cout << "Stack elements (top to bottom): ";
    while (!data.empty())
    {
        cout << data.top() << " ";
        data.pop();
    }
    cout << endl;
}

int main()
{
    stack<int> data;
    for (int i = 0; i < 5; i++)
    {
        data.push(i);
    }

    data.pop(); // remove one element

    if (data.empty())
    {
        cout << "Stack is empty\n";
    }
    else
    {
        cout << "Size of stack is " << data.size() << endl;
        displayStack(data); // original stack remains unchanged
        cout << "Size after display (still): " << data.size() << endl; // verify
    }

    return 0;
}
