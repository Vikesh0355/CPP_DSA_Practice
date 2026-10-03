/* Template: The simple idea is to pass the data type as a pramaeter so that we don't need to write the same code for different data types*/
#include <iostream>
using namespace std;
template<typename t>
t sum(t a, t b)
{
    return a+b;
}

int main()
{
    cout<<"int sum: "<<sum(1,2)<<endl;
    cout<<"float sum: "<<sum(1.2, 3.4)<<endl;
    return 0;
}

/* template function in array*/
#include <iostream>
using namespace std;

template <typename T>
T sum(T a[], int size)
{
    T s = 0;

    for (int count = 0; count < size; count++)
    {
        s = s + a[count];
    }

    return s;
}

int main()
{
    int x[5] = {10, 20, 30, 40, 50};
    float y[3] = {1.2, 2.5, 4.6};

    cout << "int sum: " << sum(x, 5) << endl;
    cout << "float sum: " << sum(y, 3) << endl;

    return 0;
}