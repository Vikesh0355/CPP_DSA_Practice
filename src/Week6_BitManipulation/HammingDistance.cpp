class Solution {
   public:
    int hammingDistance(int x, int y) {
        int count = 0;
        // Continue until both numbers are reduced to 0
        while (x != 0 || y != 0) {
            if ((x & 1) != (y & 1)) {
                count++;  // If bits are different, increment count
            }
            x >>= 1;  // Right shift x to check the next bit
            y >>= 1;  // Right shift y to check the next bit
        }
        return count;
    }
};
