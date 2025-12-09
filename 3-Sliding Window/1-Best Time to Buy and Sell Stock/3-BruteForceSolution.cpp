// Time Complexity: O(n^2), Space Complexity: O(1)
#include <iostream> // needed to input output operations
#include <vector> // needed to use vector
using namespace std; // needed to avoid write std:: every time

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Space: O(1)
        int maxProfit = 0;
        for (int i = 0; i < prices.size(); i++) // Time: O(n^2)
        {
            for (int j = i+1; j < prices.size(); j++)
            {
                int profit = prices[j]-prices[i];
                maxProfit = max(maxProfit, profit);
            }
        }
        return maxProfit;
    }
};

int main(){
   // vector<int> prices = {10,8,7,5,2};
   vector<int> prices = {10,1,6,5,4,7,1};
   

   Solution r;

   int result = r.maxProfit(prices);

   
   cout << result << "\n";
}