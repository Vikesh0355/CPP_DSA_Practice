#include <iostream>
using namespace std;

template<typename T1, typename T2>
class Calculator 
{
public:
    auto add(T1 a, T2 b) { return a + b; }
    auto sub(T1 a, T2 b) { return a - b; }
};

int main()
{
    Calculator<int, int> calc1;       // specify types
    cout << calc1.add(3, 4) << endl;

    Calculator<double, double> calc2;
    cout << calc2.add(5.6, 4.5) << endl;

    return 0;
}
