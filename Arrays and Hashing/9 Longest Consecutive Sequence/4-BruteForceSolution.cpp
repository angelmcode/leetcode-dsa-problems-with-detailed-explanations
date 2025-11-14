//Time Complexity: O(n^2)   Space Complexity: O(n) 

#include <iostream> // needed to input output operations
#include <vector> // needed to use vector
#include <unordered_set>
using namespace std; // needed to avoid write std:: every time

class Solution {
public:
    static int longestConsecutive(vector<int>& nums) {
        unordered_set<int> copyNums(nums.begin(), nums.end()); // Space: O(n)
        
        int result = 0;

        for (const int &c: copyNums) //Time: O(n^2) 
        {
            int struck = 0;
            int curr = c;
            while (copyNums.count(curr))
            {
                curr++;
                struck++;
            }
            result = max(result, struck);
        }

        return result;
        
    }
};

int main(){

   vector<int> nums = {9,1,4,7,3,-1,0,5,8,-1,6};

   int result = Solution::longestConsecutive(nums);

   cout << result << '\n';

   return 0;
}