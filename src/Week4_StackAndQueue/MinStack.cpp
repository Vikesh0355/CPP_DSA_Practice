
#include <stack> // Include the stack header
class MinStack
{
    private:
        std::stack<int> stack;   // Main stack
        std::stack<int> minStack; // Stack to track the minimum values
    public:
        MinStack() {
            // Constructor to initialize the stack and minStack
        }
        
        void push(int val) {
            // Push the value onto the main stack
            stack.push(val);
            
            // If minStack is empty or the current value is smaller than or equal to the top of minStack,
            // push the value onto the minStack
            if (minStack.empty() || val <= minStack.top()) {
                minStack.push(val);
            }
        }
        
        void pop() {
            // Pop the value from the main stack
            int val = stack.top();
            stack.pop();
            
            // If the value being popped is the same as the top of minStack, pop from minStack as well
            if (val == minStack.top()) {
                minStack.pop();
            }
        }
        
        int top() {
            // Return the top value of the main stack
            return stack.top();
        }
        
        int getMin() {
            // Return the top value of the minStack, which is the minimum value in the stack
            return minStack.top();
        }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
