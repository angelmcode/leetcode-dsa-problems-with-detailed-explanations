// time complexity: O(n log k) space compexity: O(n + k)

#include <iostream> // needed to use input output operations
#include <vector> // needed to use the dynamic array
#include <unordered_map> // neede to use the hash map
#include <queue> // needed to use priority_queue
using namespace std; // needed to not write std:: everytime

class Solution {
public:
    static vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count; // 1:3 - 2:3 - 3:2   space: O(n)

        for(int &n : nums){
         count[n]++; // time: O(n)
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > minHeap; //  3:2 - 3:1 space: O(k)

        for(auto &pair : count){ // Time: O(n log k)
         minHeap.push({pair.second, pair.first});
         if (minHeap.size() > k)
         {
            minHeap.pop();
         }
        }

        vector<int> result;

        for(int i=0; i<k; i++){ // Time: O(k log k)
         result.push_back(minHeap.top().second);
         minHeap.pop();
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