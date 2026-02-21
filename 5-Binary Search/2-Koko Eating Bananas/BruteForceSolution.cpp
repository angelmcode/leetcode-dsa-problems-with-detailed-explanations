// Time Complexity: O(n*m) Space Complexity: O(1)
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = 0;

        for (int &p : piles)
        {
            maxPile = max(maxPile, p);
        }
        int minSpeed = maxPile + 1;

        for (int i = maxPile; i > 0; i--)
        {
            int hours = 0;
            for (int j = 0; j < piles.size(); j++)
            {
                int s = ceil((double)piles[j] / i);
                hours += s;
            }
            if (hours <= h ) minSpeed = min(minSpeed, i);
        }
        
        return minSpeed;
    }
};


int main (){
   Solution s;

   vector<int> piles = {1,4,3,2};
   int h = 9;
   
   int result = s.minEatingSpeed(piles, h);

   cout << result << '\n';

   return 0;
}