#include<iostream>
#include<vector>
using namespace std;

vector<int> SelectionSort(vector<int> arr)
{
    for(int i = 0; i<arr.size(); i++)
    {
        int min = i;
        for(int j = i+1; j<arr.size(); j++)
        {
            if(arr[j]<arr[min])
            {
               min = j;
            }
        }
        if(min!=i)
        {
          swap(arr[i], arr[min]);
        }
        else
        {
            /*Do nothing*/
        }
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
    vector<int> result = SelectionSort(arr);
    display(result);
    return 0;
}