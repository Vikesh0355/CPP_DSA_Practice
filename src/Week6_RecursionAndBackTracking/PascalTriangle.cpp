class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle; // Vector to store the entire Pascal's Triangle
        
        // Loop through each row of Pascal's Triangle
        for (int i = 0; i < numRows; i++) {
            // Create a row of size (i + 1), and initialize all elements as 1
            // The first and last elements of each row are always 1 in Pascal's Triangle
            vector<int> row(i + 1, 1);
            
            // Loop through the middle elements of the row (ignoring the first and last elements)
            for (int j = 1; j < i; j++) {
                // Each middle element is the sum of the two elements directly above it from the previous row
                // triangle[i-1][j-1] is the element to the left, and triangle[i-1][j] is the element to the right
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
            
            // Push the generated row to the triangle
            triangle.push_back(row);
        }
        
        // Return the entire Pascal's Triangle with numRows rows
        return triangle;
    }
};
