#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

int evaluateExpression(const string& expression) {
    stack<int> stk;
    int currentNumber = 0;
    char operation = '+';  // Initial operation is '+' because we consider the first number as positive

    for (int i = 0; i < expression.size(); ++i) {
        char ch = expression[i];

        if (isdigit(ch)) {
            currentNumber = currentNumber * 10 + (ch - '0');
        }

        // If it's an operator or it's the last character of the string
        if ((!isdigit(ch) && ch != ' ') || i == expression.size() - 1) {
            if (operation == '+') {
                stk.push(currentNumber);
            } else if (operation == '-') {
                stk.push(-currentNumber);
            } else if (operation == '*') {
                int top = stk.top();
                stk.pop();
                stk.push(top * currentNumber);
            } else if (operation == '/') {
                int top = stk.top();
                stk.pop();
                stk.push(top / currentNumber);
            }

            // Update the operation and reset current number
            operation = ch;
            currentNumber = 0;
        }
    }

    // Sum up all the values in the stack
    int result = 0;
    while (!stk.empty()) {
        result += stk.top();
        stk.pop();
    }

    return result;
}

int main() {
    string expression = "2*3+5";  // Example expression
    cout << "The result of the expression is: " << evaluateExpression(expression) << endl;

    return 0;
}
