//Time Complexity: O(n)   Space Complexity: O(n) 

#include <iostream> // needed to input output operations
#include <vector> // needed to use vector
#include <unordered_set>
using namespace std; // needed to avoid write std:: every time

class Solution {
public:
    static int longestConsecutive(vector<int>& nums) {
      unordered_set<int> copyNums(nums.begin(), nums.end()); // Space O(n)

      int result = 0;
      for (auto &c: copyNums) // Time O(n)
        {
         if (copyNums.count(c-1)) continue;
         
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
   // vector<int> nums = {1,2,3,4};

   int result = Solution::longestConsecutive(nums);

   cout << result << '\n';

   return 0;
}