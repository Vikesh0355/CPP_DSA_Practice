/* Static Data Member in a C++ Class
A static data member is a data member that is shared by all objects of a class. 
There is only one copy of a static data member, regardless of how many objects are created. */

#include <iostream>
using namespace std;

class Student
{
public:
    int rollNo;
    static int count;  // Static data member

    Student()
    {
        count++;
    }
};

// Definition of static data member
int Student::count = 0;

int main()
{
    Student s1;
    Student s2;
    Student s3;

    cout << "Number of students = " << Student::count << endl;

    return 0;
}

/* Important points
A static data member is common to all objects.
It is created only once.

It must traditionally be defined outside the class:

int Student::count = 0;

It can be accessed using the class name:

Student::count */