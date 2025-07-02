#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> seen;
        for (int i = 0; i < nums.size(); i++)
        {
            int x = target - nums[i];
            if (seen.find(x) != seen.end())
            {
                return {seen[x], i};
            }
            seen[nums[i]] = i;
        }
        return {};
    }
};

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    Solution sol;
    vector<int> result = sol.twoSum(nums, target);

    if (!result.empty())
    {
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
    }
    else
    {
        cout << "No two numbers found that add up to the target." << endl;
    }

    return 0;
}


/*  g++ -std=c++14 Two_Sum.cpp -o Two_Sum -pthread */
/* ./Two_Sum  */