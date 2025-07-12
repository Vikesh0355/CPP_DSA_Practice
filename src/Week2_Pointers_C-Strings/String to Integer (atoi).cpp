#include<iostream>
#include<climits>
#include<cstring>

class Solution 
{
    public:
    int myAtoi(string s)
    {
        int n = s.size();
        int i = 0;

        while(i<n && s[i] == ' ')
        {
           i++;
        }

        int sign  = 1;

        if(i<n && (s[i] == '+' || s[i] == '-'))
        {
            sign = (s[i]== '-')?-1:1;
            i++;
        }

        long result = 0;
        while(i<n && isdigit(s[i]))
        {
            int digit = s[i]-'0';
            result = result*10+digit;
            if (sign == 1 && result > INT_MAX) return INT_MAX;
            if (sign == -1 && -result < INT_MIN) return INT_MIN;
            i++;

        }
        return static_cast<int>(sign * result);
    }
};