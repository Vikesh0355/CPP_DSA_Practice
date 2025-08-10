class Solution
{
    public:
    int singleNumber(vector<int>& nums)
    {
        int result = 0;
        for(auto num:nums)
        {
            result^= num;
        }
        return result;   
    }
};

OR 
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> freqMap;
        
        // Step 1: Count the frequency of each element
        for (int num : nums) {
            freqMap[num]++;
        }
        
        // Step 2: Find the element with frequency 1
        for (auto& entry : freqMap) {
            if (entry.second == 1) {
                return entry.first;  // The element that appears only once
            }
        }
        
        return -1;  // Just a fallback, although not necessary since the problem guarantees a single number.
    }
};
