/*Binary search will work only on sorted array*/
https://www.youtube.com/watch?v=V_T5NuccwRA&list=PLdo5W4Nhv31bbKJzrsKfMpo_grxuLl8LU&index=96

case 1: data == mid element 
case 2: data <mid elenet// move left ptr to  mid-1 position
case 3: data >mid element // move right ptr to mid+1

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class solution
{
    public:
    bool BinarySearch(vector<int> &arr, int data)
    {
        int n = arr.size();
        int left = 0;
        int right = n-1;
        while(left<=right)
        {
            int mid = (left+right)/2;
            if(data== arr[mid])
            {
                return true;
            }
            else if(data<arr[mid])
            {
                right = mid-1;
            }
            else if(data >arr[mid])
            {
                left = mid+1;
            }
        }
        return false;
    }
};

int main()
{
    solution t;
    vector<int> data = {10, 20, 30, 43, 56, 60, 20, 56};
    int n = 56;

    if (t.BinarySearch(data, n))
        cout << "Number " << n << " is Found" << endl;
    else
        cout << "Number " << n << " is Not Found" << endl;

    return 0;
}