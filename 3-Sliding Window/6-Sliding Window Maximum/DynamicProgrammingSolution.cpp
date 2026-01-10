// Time Complexity: O(n)  Space Complexity: O(n)
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      int n = nums.size();
      vector<int> left(n); // space O(n)
      vector<int> right(n); // space O(n)
      for (int i = 0; i < n; i++) // time O(n)
      {
         if (i%k == 0)
         {
            right[i] = nums[i];
         } else {
            right[i] = max(nums[i],right[i-1]);
         }
      }

      left[n-1] = nums[n-1];
      for (int i = n-2; i >= 0; i--) // time O(n)
      {
         if (i%k == k-1)
         {
            left[i] = nums[i];
         } else {
            left[i] = max(nums[i],left[i+1]);
         }
      }

      vector<int> result;
      for (int i = 0; i <= n-k; i++) // time O(n)
      {
         int maxValue = max(left[i], right[i+k-1]);
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