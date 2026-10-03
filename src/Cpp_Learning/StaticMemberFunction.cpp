/* A Static member function belong to the class rather than to individual objects*/
/*Important points about static member functions
They belong to the class, not a particular object.

You can call them using the class name:

Student::showCount();
You don't need to create an object to call them.
A static member function can directly access only static data members.  */

#include <iostream>
using namespace std;

class Student
{
    public:
    static int count;
    Student()
    {
        count++;
    }
    static void showcount()
    {
        cout<<"Number of students = "<<count<<endl;
        // cout << rollNo; // ❌ Not allowed
    }
};
int Student::count = 0;
int main()
{
    Student s1;
    Student s2;
    Student s3;
    Student::showcount();
    return 0;
}