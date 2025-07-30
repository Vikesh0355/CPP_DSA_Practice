class Solution {
    public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int N = temperatures.size();
        vector<int> result(N, 0);  // Initialize result with 0 for all days.
        stack<int> stk;  // Stack to store indices of temperatures.

        for (int i = 0; i < N; ++i) {
            // Process temperatures in the stack.
            while (!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
                int idx = stk.top();  // Get the index of the cooler temperature.
                stk.pop();
                result[idx] = i - idx;  // Calculate the number of days to wait.
            }
            stk.push(i);  // Push the current day index onto the stack.
        }

        return result;
    }
};
