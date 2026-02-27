// Time Complexity: O(log n) Space Complexity: O(1)
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        while (l<r)
        {
            int middle = l+((r-l+1)/2);
            if (nums[l]<=nums[middle])
            {
                l=middle;
            } else {
                r=middle-1;
            }
        }
        int pivot = l;
        l=0;
        r=pivot;
        int result = binarySearch(nums, target, l, r);

        if (result != -1) return result;
        
        l=pivot+1;
        r=nums.size()-1;
        return binarySearch(nums, target, l, r);
    }
    int binarySearch(vector<int>& nums, int target, int l, int r) {    
        while (l<=r)
        {
            int middle = l+((r-l)/2);
            if (target==nums[middle])
            {
                return middle;
            } else if(target<=nums[middle]){
                r=middle-1;
            } else {
                l=middle+1;
            }
        }
        return -1;
    }
};


int main (){
   Solution s;

   vector<int> nums = {3,4,5,6,1,2};
   int target = 2;
   
   int result = s.search(nums, target);

   cout << result << '\n';

   return 0;
}