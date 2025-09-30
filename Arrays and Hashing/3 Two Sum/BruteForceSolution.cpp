#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    static vector<int> twoSum(vector<int>& nums, int target) {

      vector<int> indexes(2,0);
      for (int i = 0; i < nums.size(); i++)
      {
         for (int j = 0; j < nums.size(); j++)
         {
            if (nums[i] + nums[j] == target && i != j)
            {
               indexes[0] = i;
               indexes[1] = j;
               return indexes;
            }
            
         }
         
      }
      
    }
};