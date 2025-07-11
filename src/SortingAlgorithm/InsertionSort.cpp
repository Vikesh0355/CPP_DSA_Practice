#include<iostream>
#include<vector>
using namespace std;

vector<int>insertionSort(vector<int>arr)
{
     int n = arr.size();
     for(int i = 1; i<n; i++)
     {
         int temp = arr[i];
         int j = i-1;
         while(j>=0 && arr[j]>temp)
         {  arr[j+1]  = arr[j];
             j--;
         }
         arr[j+1] =  temp;
     }

    return arr;
}

void display(vector<int>arr)
{
    for(int x:arr)
    {
        cout<<x<< " ";
    }
    cout<<endl;
}

int main()
{
    vector<int>arr = {64, 25, 12, 22, 11};

    vector<int> result = insertionSort(arr);
    
    display(result);
    return 0;
}