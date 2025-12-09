// Time Complexity: O(n), Space Complexity: O(1)
#include <iostream> // needed to input output operations
#include <vector> // needed to use vector
using namespace std; // needed to avoid write std:: every time

class Solution {
public:
    int maxProfit(vector<int>& prices) {
      // Space: O(1)
      int l = 0;
      int r = 1;
      int maxProfit = 0;

      while (r<prices.size()) // Time: O(n)
      {
         if (prices[l]<prices[r])
         {
            int profit = prices[r] - prices[l];
            maxProfit = max(maxProfit,profit);
            r++;
         } else {
            l=r;
            r++;
         }  
      }
      return maxProfit;
    }
};

int main(){
   // vector<int> prices = {10,8,7,5,2};
   vector<int> prices = {10,1,5,6,7,1};
   

   Solution r;

   int result = r.maxProfit(prices);

   
   cout << result << "\n";
}