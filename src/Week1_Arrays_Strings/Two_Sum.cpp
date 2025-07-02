#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
 public:
  vector<int> twoSum(vector<int>& nums, int target)
  {
    unordered_map<int, int> seen;
    for(int i = 0; i<nums.size(); i++)
    {
        int x = target-nums[i];
        if(seen.find(x)!= seen.end())
        {
            return {seen[x], i};
        }
        seen[nums[i]] = i;
    }
    return {};
  }

};

/*  g++ -std=c++14 Two_Sum.cpp -o AbstTwo_SumractClass -pthread */
/* ./Two_Sum  */