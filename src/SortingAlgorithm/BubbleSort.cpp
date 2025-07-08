#include<iostream>
#include<vector>
using namespace std;

vector<int> BubbleSort(vector<int>arr)
{
    int n = arr.size();
    bool flag = false;
    for(int i = 0; i<n-1; i++)
    {
        for(int j = 0; j<n-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                flag = true;
            }
        }
        if(!flag)
        break;
        
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
    vector<int> result = BubbleSort(arr);
    display(result);
    return 0;
}