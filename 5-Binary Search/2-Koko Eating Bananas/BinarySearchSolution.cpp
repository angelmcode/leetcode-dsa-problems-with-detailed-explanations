// Time Complexity: O(n log m) Space Complexity: O(1)
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

        int l = 1;
        int r = maxPile;
        while (l<=r)
        {
         int middle = l + ((r-l)/2);
         long long hours = 0;
         for (int i = 0; i < piles.size(); i++)
         {
            int s = ceil((double)piles[i] / middle);
            hours += s;
         }
         if (hours <= h)
         {
            minSpeed = min(minSpeed, middle);
            r = middle-1;
         }
         else
         {
            l=middle+1;
         }
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