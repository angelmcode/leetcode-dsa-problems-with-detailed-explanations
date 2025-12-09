// Time Complexity: O(n^2), Space Complexity: O(n)
#include <iostream> // needed to input output operations
#include <vector> // needed to use vector
#include <algorithm> // needed to use sort algorthm
using namespace std; // needed to avoid write std:: every time

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      sort(nums.begin(), nums.end()); // Time: O(n log n) Space: O(n)

      vector<vector<int>> result; // Space O(m);
      for (int i = 0; i < nums.size(); i++) // Time: O(n^2)
      {
         if(nums[i] > 0) break;
         if(i>0 && nums[i] == nums[i-1]) continue;

         int l = i+1;
         int r = nums.size()-1;
         while(l < r){
            int sum = nums[i] + nums[l] + nums[r];
            if (sum > 0) r--;
            if (sum < 0) l++;
            if (sum == 0){
               result.push_back({nums[i],nums[l], nums[r]});
               l++;
               r--;
               while (l<r && nums[l] == nums[l-1])
               {
                  l++;
               }
            }
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