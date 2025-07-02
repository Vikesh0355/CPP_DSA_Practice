/*e.g Deep copy*/
/*https://www.youtube.com/watch?v=nCAVr_T4DbM */
// C++ program to implement the

#include <iostream>
#include <vector>
using namespace std;

class Dummy
{
    private:
    int a, b;
    int *p;
    public:
    Dummy()
    {
        p = new int;
    }
    void SetData(int x, int y, int z)
    {
        a = x;
        b = y;
        *p = z;
    }  
    void ShowData()
    {
        cout<<"\na ="<<a<<" b = "<<b<<" p = "<<(*p)<<endl;
    }
    Dummy(Dummy &d)
    {
        a = d.a;
        b = d.b;
        p = new int; /*To assign new memory for pointer for deep copy*/
        *p = *(d.p); //deep copy
    }
    ~Dummy()
    {
        delete p;
    }
};

int main()
{
    Dummy d1;
    d1.SetData(1,2,3);
    Dummy d2 =d1;
    d1.ShowData();
    d2.ShowData();
    return 0;
}

/*  g++ -std=c++14 Deep_copy.cpp -o Deep_copy -pthread */
/* ./Deep_copy  */