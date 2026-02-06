// Time Complexity: O(n log n) Space Complexity: O(n)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pairs; // space O(n)
        for (int i = 0; i < position.size(); i++) // time O(n)
        {
            pairs.push_back({position[i],speed[i]});
        }
        
        sort(pairs.rbegin(),pairs.rend()); // time O(n log n)
        vector<double> stack; // space O(n)

        for (auto &p : pairs) // time O(n)
        {
            stack.push_back((double)(target - p.first) / p.second);
            if (stack.size() >= 2 && stack.back() <= stack[stack.size()-2])
            {
                stack.pop_back();
            }   
        }
        return stack.size();
    }
};


int main (){
   Solution s;

   vector<int> position = {4,1,0,7};
   vector<int> speed = {2,2,1,1};
   int target = 10;
   
   int result = s.carFleet(target, position, speed);

   cout << result << '\n';

   return 0;
}