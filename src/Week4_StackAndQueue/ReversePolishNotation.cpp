#include <stack>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<int> st;
        
        for (auto &token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();

                if (token == "+")
                    st.push(b + a);
                else if (token == "-")
                    st.push(b - a);
                else if (token == "*")
                    st.push(b * a);
                else if (token == "/")
                    st.push(b / a); // truncates toward zero by default in C++
            } else {
                st.push(stoi(token)); // convert string to int
            }
        }
        return st.top();
    }
};
