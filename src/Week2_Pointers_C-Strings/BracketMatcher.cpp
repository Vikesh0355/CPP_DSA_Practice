string BracketMatcher(string str) {
    int count = 0;

    for (char c : str) {
        if (c == '(') {
            count++;
        } else if (c == ')') {
            count--;
            if (count < 0) {
                return "0";  // unmatched closing bracket
            }
        }
    }

    return (count == 0) ? "1" : "0";  // if count != 0, unmatched opening bracket
}
