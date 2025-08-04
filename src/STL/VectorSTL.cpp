✅ 1. Constructors & Initialization
vector<T> v; → Creates an empty vector.

vector<T> v(n); → Creates vector with n elements (default initialized).

vector<T> v(n, val); → Creates vector with n elements, all val.

vector<T> v2(v1); → Copy constructor.

vector<T> v = {1,2,3}; → Initializer list.

✅ 2. Capacity
v.size() → Returns number of elements.

v.capacity() → Returns allocated storage.

v.max_size() → Maximum possible size.

v.empty() → Checks if vector is empty.

v.resize(n) → Changes size to n.

v.reserve(n) → Reserves capacity for at least n elements.

v.shrink_to_fit() → Reduces capacity to fit size.

✅ 3. Element Access
v[i] → Access element at index i.

v.at(i) → Access element with bounds check (throws out_of_range if invalid).

v.front() → First element.

v.back() → Last element.

v.data() → Returns pointer to underlying array.

✅ 4. Modifiers
v.push_back(x) → Add element at end.

v.pop_back() → Remove last element.

v.insert(pos, val) → Insert before pos.

v.insert(pos, count, val) → Insert count times.

v.erase(pos) → Remove element at pos.

v.erase(start, end) → Remove range [start, end).

v.clear() → Remove all elements.

v.assign(n, val) → Assign new values.

v.emplace(pos, args...) → Construct element in place at pos.

v.emplace_back(args...) → Construct element at end.

✅ 5. Iterators
v.begin() → Iterator to first element.

v.end() → Iterator to past-the-end element.

v.rbegin() → Reverse iterator to last element.

v.rend() → Reverse iterator to before first element.

v.cbegin(), v.cend() → Const iterators.

v.crbegin(), v.crend() → Const reverse iterators.


#include <algorithm>
sort(v.begin(), v.end());      // Ascending
sort(v.rbegin(), v.rend());    // Descending

sort(v.begin(), v.end());      // Ascending
sort(v.rbegin(), v.rend());    // Descending

reverse(v.begin(), v.end());

/*Binary search*/
if (binary_search(v.begin(), v.end(), 30)) cout << "Exists";

/*count*/
int cnt = count(v.begin(), v.end(), 30);

cout << *min_element(v.begin(), v.end());
cout << *max_element(v.begin(), v.end());

/*sum of element*/
#include <numeric>
int sum = accumulate(v.begin(), v.end(), 0);


/*Unique (Remove duplicates in sorted vector)*/
v.erase(unique(v.begin(), v.end()), v.end());



#include <iostream>
#include<list>
#include<vector>
using namespace std;

int main()
{
    vector<int> arr;
    vector<int> data(5);
    vector<int> player = {1, 2, 3, 4, 5, 3};
    
    sort(player.begin(), player.end()); // Step 1: sort the array first
    player.erase(unique(player.begin(), player.end()), player.end()); // Step 2: erase duplicates
    cout<<"player array is:" <<endl;
    for(auto it = player.begin(); it != player.end(); it++)
    {
        cout<<*it<<" "<<endl;
    }
    for(auto it = player.cbegin(); it != player.cend(); it++)
    {
        *it = 20; // since we used cbegin and cend so it is constant iterators. So here we can't change value
    }
    arr.push_back(2);

    cout<<"array size:"<<arr.size()<<endl;
    cout<<"array capacity"<<arr.capacity()<<endl;
    cout<<"front value is "<<arr.front()<<endl;
    cout<<"back value is "<<arr.back()<<endl;

     return 0;
}