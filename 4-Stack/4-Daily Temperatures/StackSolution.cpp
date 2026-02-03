// Time Complexity: O(n) Space Complexity: O(n)
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
      vector<int> result(temperatures.size(),0); //space O(n)
      stack<pair<int, int>> stack; // temp, index

      for (int i = 0; i < temperatures.size(); i++) // time O(n)
      {
         int value = temperatures[i];
         while (!stack.empty() && value > stack.top().first)
         {
            result[stack.top().second] = i - stack.top().second;
            stack.pop();
         }
         stack.push({value, i});
      }
      return result;
   }
};


int main (){
   Solution s;

   vector<int> tempentures = {30,38,30,36,35,40,28};
   
   vector<int> result = s.dailyTemperatures(tempentures);

   for (auto &&i : result)
   {
      cout << i << '\n';
   }
   return 0;
}