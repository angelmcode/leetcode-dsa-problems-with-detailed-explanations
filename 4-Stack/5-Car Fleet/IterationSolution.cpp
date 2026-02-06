// Time Complexity: O(n log n) Space Complexity: O(n)
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>> pair; // space O(n)

        for (int i = 0; i < n; i++) // time O(n)
        {
            pair.push_back({position[i],speed[i]});
        }
        sort(pair.rbegin(), pair.rend()); // time O(n log n)

        double prev = (double)(target - pair[0].first) / pair[0].second;
        int fleets = 1;
        for (int i = 1; i < n; i++) // time O(n)
        {
            double current = (target - pair[i].first) / pair[i].second;
            if (current > prev)
            {
                fleets++;
                prev=current;
            }
        }
        return fleets;
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