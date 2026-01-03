// Time Complexity: O(n^2 + n*m)  Space Complexity: O(n+m)
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
      unordered_map<char, int> target; //space: O(m)
      
      unordered_map<int, pair<int, int>> tracking; //space: O(n)
      for (int i = 0; i < s.size(); i++) // time: O(n^2 + n*m)
      {
         for (char &c : t)
         {
            target[c]++;
         }
         int start = -1;
         int end = -1;
         for (int j = i; j < s.size(); j++)
         {
            if (start == -1 && target.count(s[j]))
            {
               start = j;
               if (target[s[j]] > 1)
               {
                  target[s[j]]--;
               } else {
                  target.erase(s[j]);
               }
            } else if(target.count(s[j]) && target.size() == 1 && target[s[j]] == 1){
               end = j;
               target.erase(s[j]);
            } else if(target.count(s[j])){
               if (target[s[j]] > 1)
               {
                  target[s[j]]--;
               } else {
                  target.erase(s[j]);
               }
            }
         }
         if (target.empty())
         {
            if(end==-1) return s.substr(start,1);
            tracking[end - start] = {start, end};
         }
         target.clear();
      }
      
      if(tracking.size() == 0) return "";

      int minimum = s.size(); 
      for (auto &t : tracking)
      {
         minimum = min(t.first, minimum);
      }
      pair<int, int> result = tracking[minimum];
      int start = result.first;
      int size = result.second - result.first;
      string substring = s.substr(start, size+1);
      return substring;
    }
};

int main (){
   string s = "OUZODYXAZV", t = "XYZ";
   Solution r;
   cout << r.minWindow(s,t) << '\n';

   return 0;
}