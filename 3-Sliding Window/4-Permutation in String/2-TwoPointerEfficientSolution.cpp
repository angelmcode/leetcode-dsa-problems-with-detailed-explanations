// Time Complexity: O(n)  Space Complexity: O(1)
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size())return false;
        unordered_map<char, int> count; // Space: O(1)
        for (char &c : s1) // Time: O(n)
        {
         count[c]++;
        }
        
        int l=0, r=s1.size()-1;
        unordered_map<char, int> countW; // Space: O(1)
        for (int i = l; i <= r; i++) // Time: O(n)
        {
         countW[s2[i]]++;
        }
        
        while (r<s2.size()) // Time: O(n)
        {
         if (count == countW)
         {
            return true;
            
         } else {
            countW[s2[l]]--;
            if(countW[s2[l]] == 0) countW.erase(s2[l]);
               l++;
               r++;
            if(r<s2.size()){
               countW[s2[r]]++;
            } 
         }
        }
        
        return false;
    }
};

int main (){
   string s1 = "abc", s2 = "lecabee";
   Solution r;
   cout << r.checkInclusion(s1,s2) << '\n';

   return 0;
}