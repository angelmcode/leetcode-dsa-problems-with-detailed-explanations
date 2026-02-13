// Time Complexity: O(n^2) Space Complexity: O(1)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
      int largest = 0;
      for (int i = 0; i < heights.size(); i++)
      {
         largest = max(largest, heights[i]);
         int smallest = heights[i];
         for (int j = i+1; j < heights.size(); j++)
         {
            smallest = min(smallest, heights[j]);
            int gap = j-i+1;
            int rectangle = smallest*gap;
            largest = max(largest, rectangle);
         }
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