// Time Complexity: O(n log n)  Space Complexity: O(n)
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      unordered_map<int, int> window; // space: O(k)
      priority_queue<int> maxNumber; // space: O(n)

      for (int i = 0; i < k-1; i++) //time: O(k)
      {
         window[nums[i]]++;
      }

      for (int i = 0; i < k-1; i++) //time: O(k)
      {
         maxNumber.push(nums[i]);
      }
      
      vector<int> result;
      int l = 0;
      for (int r = k-1; r < nums.size(); r++) //time: O(n log n)
      {
         window[nums[r]]++;
         maxNumber.push(nums[r]);

         int top = maxNumber.top();

         while (!window.count(top))
         {
            maxNumber.pop();
            top = maxNumber.top();
         }
         
         result.push_back(top);

         if (window[nums[l]] > 1)
         {
            window[nums[l]]--;
         } else {
            window.erase(nums[l]);
         }
         
         l++;
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