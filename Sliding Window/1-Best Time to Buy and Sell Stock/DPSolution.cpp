// Time Complexity: O(n), Space Complexity: O(1)
#include <iostream> // needed to input output operations
#include <vector> // needed to use vector
using namespace std; // needed to avoid write std:: every time

class Solution {
public:
    int maxProfit(vector<int>& prices) {
      // Space: O(1)
      int MaxPro = 0;
      int minBuyprice = prices[0];

      for (int &sell : prices) // Time: O(n)
      {
         MaxPro = max(MaxPro, sell - minBuyprice);
         minBuyprice = min(minBuyprice, sell);
      }
      return MaxPro;
    }
};

int main(){
   // vector<int> prices = {10,8,7,5,2};
   vector<int> prices = {10,1,5,6,7,1};
   

   Solution r;

   int result = r.maxProfit(prices);

   
   cout << result << "\n";
}