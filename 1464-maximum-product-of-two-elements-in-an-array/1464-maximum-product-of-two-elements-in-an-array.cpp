class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int max1 = -1; // Largest number
        int max2 = -1; // Second-largest number

        // Find the two largest numbers in one pass
        for (int n : nums) {

            // Current number becomes the new maximum
            if (n >= max1) {
                max2 = max1;
                max1 = n;
            }

            // Current number becomes the second maximum
            else if (n >= max2) {
                max2 = n;
            }
        }

        // Maximum product is obtained from the two largest numbers
        return (max1 - 1) * (max2 - 1);
    }
};