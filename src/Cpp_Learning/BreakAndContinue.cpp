/*The break statement can also be used to jump out of a loop.*/

#include <iostream>
using namespace std;

int main()
{
    for(int i = 0; i<10; i++)
    {
        if(i == 4)
        {
            break;
        }
        cout<<i<<endl;
    }
    return 0;
}

/*The continue statement breaks one iteration (in the loop), if a specified condition occurs, and continues with the next iteration in the loop.*/

#include <iostream>
using namespace std;
int main()
{
    for(int i = 0; i<10; i++)
    {
        if(i == 4)
        {
            continue;
        }
        cout<<i<<endl;
    }
    return 0;
}