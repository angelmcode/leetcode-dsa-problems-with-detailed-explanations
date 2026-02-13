// Time Complexity: O(n) Space Complexity: O(n)
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
      stack<pair<int, int>> monotoniStack; // height, index
      int largest = 0;
      monotoniStack.push({heights[0],0});
      
      for (int i = 1; i < heights.size(); i++)
      {
         int start = i;
         while(!monotoniStack.empty() && heights[i] < monotoniStack.top().first)
         {
            int indexTop = monotoniStack.top().second;
            int rectangle = (i - indexTop) * monotoniStack.top().first;
            largest = max(largest, rectangle);
            start = monotoniStack.top().second;
            monotoniStack.pop();
         }
         monotoniStack.push({heights[i],start});
      }
      int size = heights.size()-1;
      while (!monotoniStack.empty())
      {
         int witdh = size - monotoniStack.top().second + 1;
         int hight = monotoniStack.top().first;
         int rectangle = witdh * hight;
         largest = max(largest, rectangle);
         monotoniStack.pop();
      }
      return largest;
    }
};


int main (){
   Solution s;

   vector<int> heights = {4,1,0,7};
   
   int result = s.largestRectangleArea(heights);

   cout << result << '\n';

   return 0;
}