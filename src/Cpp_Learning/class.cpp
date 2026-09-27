/*In C++, a class is a user-defined data type that acts as a blueprint or template for creating objects. It bundles related variables (called data members or attributes) 
and functions (called member functions or methods) into a single, cohesive unit*/

//Class
#include <iostream>
using namespace std;
class stu
{
    private:
    int id;
    char name[20];
    float fee;
	
    public:
    void get()  //inline function
    {
        cout<<"Enter id"<<endl;
        cin>>id;
        cout<<"Enter Name"<<endl;
        cin>>name;
        cout<<"fee"<<endl;
        cin>>fee;
        cout<<"id= " <<id<<endl;
		cout<<"Name= "<<name<<endl;
		cout<<"Fee= "<<fee<<endl;
    }
};

int main() 
{
    stu obj;
    obj.get();
    return 0;
}


//Function Definition is outside class
#include <iostream>
using namespace std;
class stu
{
    private:
    int id;
    char name[20];
    float fee;
	
    public:
    void get() ; 

};

void stu::get() 
{
    cout<<"Enter id, Name and fee"<<endl;
    cin>>id >> name >>fee;
    cout<<"id= " <<id<<ends<<"name = " <<name<<ends<<"Fee = "<<fee;
}
    
int main() 
{
    stu obj;
    obj.get();
    return 0;
}


/*Encapsulation:bundling data and function members into a single unit, i.e., a class.