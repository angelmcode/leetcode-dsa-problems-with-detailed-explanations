// Time Complexity: O(n), Space Complexity: O(1)
#include <iostream> // needed to input output operations
#include <vector> // needed to use vector
using namespace std; // needed to avoid write std:: every time

class Solution {
public:
    int trap(vector<int>& height) {
      // Space O(1)
      if(height.empty()) return 0;
      int l = 0;
      int r = height.size()-1;
      int sumWater = 0;
      
      int MaxLeft = 0;
      int MaxRight = 0;
      while (l<r) // Time: O(n)
      {
         if (height[l] <= height[r])
         {
            int Trappedwater = MaxLeft - height[l];
            MaxLeft = max(MaxLeft, height[l]);
            if(Trappedwater > 0) sumWater += Trappedwater;
            l++;
         } else {
            int Trappedwater = MaxRight - height[r];
            MaxRight = max(MaxRight, height[r]);
            if(Trappedwater > 0) sumWater += Trappedwater;
            r--;
         }
      }
      return sumWater;
    }
};

int main(){
   // vector<int> numbers = {0,2,0,3,1,0,1,3,2,1};
   vector<int> numbers = {4,2,0,3,2,5};

   Solution r;

   int result = r.trap(numbers);

   
   cout << result << "\n";
}