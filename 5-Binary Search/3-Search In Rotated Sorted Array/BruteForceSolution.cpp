// Time Complexity: O(n) Space Complexity: O(1)
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == target)
            {
                return i;
            }
        }
        return -1;
    }
};

int main (){
   Solution s;

   vector<int> nums = {3,4,5,6,1,2};
   int target = 2;
   
   int result = s.search(nums, target);

   cout << result << '\n';

   return 0;
}