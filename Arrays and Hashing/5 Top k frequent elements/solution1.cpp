#include <iostream> // needed to use input output operations
#include <vector> // needed to use the dynamic array
#include <unordered_map> // neede to use the hash map
#include <algorithm>
using namespace std; // needed to not write std:: everytime

class Solution {
public:
    static vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count; // 1:3, 2:3, 3:2

        for (int i = 0; i < nums.size(); i++)
        {
         count[nums[i]]++;
        }

        vector<pair<int, int>> tops; // 2:3, 3:1 ,3:2
        for (auto &c : count)
        {
         tops.push_back({c.second,c.first});
        }
        
        sort(tops.begin(),tops.end());
        
        vector<int> result;
        for (int i = tops.size() - k; i < tops.size(); i++)
        {
         result.push_back(tops[i].second);
        }

        return result;
    
    };
};

int main() {

   vector<int> nums = {1,1,1,2,2,2,3,3};
   int k = 2;

   vector<int> result = Solution::topKFrequent(nums, k);
   
   for (int r : result)
   {
      cout << r << '\n';
   }
   return 0;
}