//Time Complexity: O(n log n)  Space Complexity: O(log n)

#include <iostream> // needed to input output operations
#include <vector> // needed to use vector
#include <unordered_set> // needed to use the hash set
#include <algorithm> // to use sort function
using namespace std; // needed to avoid write std:: every time

class Solution {
public:
    static int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        sort(nums.begin(), nums.end()); // Time: O(n log n), Space: O(log n)
        int result = 1;
        int current = 1;

        for (int i = 1; i < nums.size(); i++) { // Time: O(n)
            if (nums[i] == nums[i - 1]) continue;// skip duplicates
            if (nums[i] == nums[i - 1] + 1) {
                current++;
            } else {
                result = max(result, current);
                current = 1;
            }
        }

        return max(result, current); // if result is not upadate this allow reuturn the correct result
    }
};


int main(){

   vector<int> nums = {9,1,4,7,3,-1,0,5,8,-1,6}; 

   int result = Solution::longestConsecutive(nums);

   cout << result << '\n';

   return 0;
}