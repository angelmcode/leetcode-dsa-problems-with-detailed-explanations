// Time Complexity: O(n), Space Complexity: O(n)
#include <iostream> // needed to input output operations
#include <vector> // needed to use vector
#include <stack> // needed to use stack
using namespace std; // needed to avoid write std:: every time

class Solution {
public:
    int trap(vector<int>& height) {
      if(height.empty()) return 0;
      
      stack<int> stack; // Space: O(n)
      int sumWater = 0;
      for (int i = 0; i < height.size(); i++) // Time: O(n)
      {
         while (!stack.empty() && height[i] >= height[stack.top()])
         {
            int mid = height[stack.top()];
            stack.pop();
            if (!stack.empty())
            {
               int l = height[stack.top()];
               int r = height[i];
               int h = min(l,r) - mid;
               int w = i - stack.top() - 1;
               int water = h*w;
               sumWater += water;
            }
         }
         stack.push(i);
      }
      cout << '\n';
      return sumWater;
    }
};

int main(){
   // vector<int> numbers = {0,2,0,3,1,0,1,3,2,1};
   vector<int> numbers = {1,2,3,4,2,0,3,2,5};

   Solution r;

   int result = r.trap(numbers);

   
   cout << result << "\n";
}