// Time Complexity: O(n^2), Space Complexity: O(n)
#include <iostream> // needed to input output operations
#include <vector> // needed to use vector
#include <algorithm> // needed to use sort algorthm
using namespace std; // needed to avoid write std:: every time

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      sort(nums.begin(),nums.end()); // Time: O(n^2) Space: O(n)

      vector<vector<int>> result; // Space: O(m)
      for (int i = 0; i < nums.size(); i++) // Time: O(n^2)
      {
         if (nums[i] > 0) break;
         if (i > 0 && nums[i] == nums[i - 1]) continue;

         int target = 0;
         int start = i+1;
         int end = nums.size() - 1;

         int diff = target - nums[i];
         while (start < end)
         {
            if (nums[i] + nums[start] + nums[end] == target){
               result.push_back({nums[i],nums[start],nums[end]});
               start++;
               end--;
               while (start < end && nums[start] == nums[start - 1]) {
                        start++;
                    }
            } 
            if (nums[i] + nums[start] + nums[end] > target) end--;
            if (nums[i] + nums[start] + nums[end] < target) start++;
         }
      }
      return result;
    }
};

int main(){
   vector<int> nums = {0,0,0};

   Solution r;

   vector<vector<int>> result = r.threeSum(nums);

   for (auto &n : result)
   {
      for (int &i : n)
      {
         cout << i << ",";  
      }
      cout << '\n'; 
   }
}