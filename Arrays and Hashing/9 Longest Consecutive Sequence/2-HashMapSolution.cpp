//Time Complexity: O(n)  Space Complexity: O(n) 

#include <iostream> // needed to input output operations
#include <vector> // needed to use vector
#include <unordered_map>
using namespace std; // needed to avoid write std:: every time

class Solution {
public:
    static int longestConsecutive(vector<int>& nums) {
      unordered_map<int,int> map; // Space: O(n)
      int result = 0;

      for (int &n : nums) // Time O(n)
      {
         if(!map[n]){
            map[n] = map[n-1] + 1 + map[n+1];
            map[n - map[n-1]] = map[n];
            map[n + map[n+1]] = map[n];
         }
         result = max(result, map[n]);
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