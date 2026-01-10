// Time Complexity: O(n*k)  Space Complexity: O(n-k+1)
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      vector<int> result; // space O(n-k+1)
      for (int window = 0; window <= nums.size()-k; window++) // time O(n*k)
      {
         int maxValue = nums[window];
         for (int i = window; i < window + k; i++)
         {
            maxValue = max(maxValue, nums[i]);
         }
         result.push_back(maxValue);
      }
      return result;
    }
};

int main (){
   vector<int>nums = {1,2,1,0,4,2,6};
   int k = 3;
   Solution r;
   auto result = r.maxSlidingWindow(nums,k);
   for (int &n : result)
   {
      cout << n << '\n';  
   }

   return 0;
}