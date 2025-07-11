int partition(vector<int>&arr, int lb, int ub)
{
    int pivot = arr[lb];
    int start = lb;
    int end = ub;
    while(start<end)
    {
        while(arr[start]<=pivot)
        {
            start++;
        }
        while(arr[end]>pivot)
        {
            end--;
        }
        if(start<end)
        {
            swap(arr[start], arr[end]);   
        }
    }
    if(start>end)
    {
        swap(arr[lb], arr[end]);
    }
    return end;
    
}

void QuickSort(vector<int> &arr, int lb, int ub)
{
    
    if(lb<ub)
    {
        int loc = partition(arr, lb, ub);
        QuickSort(arr, lb, loc-1);
        QuickSort(arr,  loc+1, ub);
    }
    
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

     QuickSort(arr, 0, arr.size()-1);
    
    display(arr);
    return 0;
}