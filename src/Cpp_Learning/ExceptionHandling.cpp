#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
    int age  = 15;
    try
    {   if(age>= 18)
        {
            cout<<" Access granted"<<endl;
        }
        else
        {
            throw(age);
        }
    }
    catch(int mynum)
    {
       cout<<"Access denied! You must be at least 18 years old"<<endl;
       cout<<"your age is; "<<mynum;
    }
    return 0;
    
}


/*Handle any type of exception*/
#include <iostream>
#include <stdexcept>
using namespace std;
int main()
{
	int age = 15;
	try 
	{

	  if (age >= 18)
	 {
		cout << "Access granted - you are old enough.";
	  } 
	  else
	  {
		throw 505;
	  }
	}
	catch (...)
	{
	  cout << "Access denied - You must be at least 18 years old.\n";
	}

}