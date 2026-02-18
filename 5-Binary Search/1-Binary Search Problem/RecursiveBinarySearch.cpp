// Time Complexity: O(log n) Space Complexity: O(log n)
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int banirySearch(vector<int>& nums, int target, int l, int r) {
      if(l>r) return -1;
      int middle = l + ((r-l)/2);
      if (nums[middle] < target)
      {
         l = middle+1;
         return banirySearch(nums, target, l, r);
      } else if(nums[middle] > target){
         r = middle-1;
         return banirySearch(nums, target, l, r);
      } else {
         return middle;
      }
    }
    int search(vector<int>& nums, int target) {
      int l = 0;
      int r = nums.size()-1;
      return banirySearch(nums, target, l, r);
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