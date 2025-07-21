class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;  // Stack to store opening brackets
        
        for (auto c : s) {
            if (c == '(' || c == '{' || c == '[')
            {
                stk.push(c);  // Push opening brackets onto the stack
            } 
            else 
            {
                if (stk.empty())
                {
                    return false;  // Closing bracket without a matching opening bracket
                }
                
                char top = stk.top();  // Get the top of the stack
                stk.pop();
                
                // Check if the closing bracket matches the top opening bracket
                if ((c == ')' && top != '(') || 
                    (c == '}' && top != '{') || 
                    (c == ']' && top != '[')) {
                    return false;
                }
            }
        }
        
        return stk.empty();  // If the stack is empty, all brackets are matched
    }
};
