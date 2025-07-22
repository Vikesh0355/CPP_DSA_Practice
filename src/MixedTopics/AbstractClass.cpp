using namespace std;
#include <iostream>

class shape  /*Abstract Base Class*/
{
	protected:
	float d1, d2;
	public:
	void getdata()
	{
		cin>>d1>>d2;
	}
	virtual float area()=0;  /*pure virtual function*/	
};

class Triangle:public shape
{
	public:
	 float area()   /* No need to add virtual keyword before are func */
	{
		return (0.5*d1*d2);
	}
	
};

class Rectangle: public shape
{
	public:
	 float area()  /* No need to add virtual keyword before are func */
	{
		return (d1*d2);
	}	
};

int main()
{  
  Triangle T;
  /*shape S;  */ /*Error becuase shape is Abstract base class so obj can't be created */
  cout<<"Enter Triangle base and height"<<endl;
  T.getdata();
  cout<<"Triangle Are="<<T.area()<<endl;
  Rectangle R;
  cout<<"Enetr Rectangle length and Breadth"<<endl;
  R.getdata();
  cout<<"Rectangle Are="<<R.area()<<endl;
  return 0;
}

/*  g++ -std=c++14 AbstractClass.cpp -o AbstractClass -pthread */
/* ./AbstractClass  */