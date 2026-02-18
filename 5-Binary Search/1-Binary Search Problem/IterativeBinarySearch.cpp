// Time Complexity: O(log n) Space Complexity: O(1)
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
      int l = 0;
      int r = nums.size()-1;

      while (l<=r)
      {
         int middle = l + ((r-l)/2);
         if (nums[middle] < target)
         {
            l = middle+1;
         } else if (nums[middle] > target)
         {
            r = middle-1;
         }
         else
         {
            return middle;
         }
      }
      return -1;
    }
};


int main (){
   Solution s;

   vector<int> nums = {-1,0,3,5,9,12};
   int target = 9;
   
   int result = s.search(nums, target);

   cout << result << '\n';

   return 0;
}