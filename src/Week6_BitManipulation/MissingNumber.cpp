class Solution 
{
   public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();  // Since nums contains numbers in the range [0, n], the length of the array is n.
        
        // Calculate the expected sum of numbers from 0 to n.
        int expectedSum = (n * (n + 1)) / 2;
        
        // Calculate the actual sum of elements in nums.
        int actualSum = 0;
        for (int num : nums) {
            actualSum += num;
        }
        
        // The missing number is the difference between the expected sum and the actual sum.
        return expectedSum - actualSum;
    }
};
