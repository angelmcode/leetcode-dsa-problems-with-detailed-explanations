#include <iostream> // needed to use input output operations
#include <vector> // needed to use the dynamic array
#include <algorithm>
using namespace std; // needed to not write std:: everytime

class Solution {
public:
    static vector<vector<string>> groupAnagrams(vector<string>& strs) {

      if (strs.size() == 1) return {{strs[0]}};
      
      vector<vector<string>> result;
      vector <pair<string,int>> orderedStrs;

      for (int i = 0; i < strs.size(); i++)
      {
         orderedStrs.push_back({strs[i],i});
      }
      
      for (int i = 0; i < strs.size(); i++)
      {
         sort(orderedStrs[i].first.begin(),orderedStrs[i].first.end());
      }

      sort(orderedStrs.begin(), orderedStrs.end());

      int i = 0;
      while (i<strs.size())
      {
         vector<string> group;
         group.push_back(strs[orderedStrs[i].second]);

         while (i+1 < strs.size() && orderedStrs[i].first == orderedStrs[i+1].first)
         {
            group.push_back(strs[orderedStrs[i+1].second]);
            i++;
         }
         
         result.push_back(group);
         i++;
      }
      
      
      // for (int i = 0; i < strs.size(); i++)
      // {
      //    cout << orderedStrs[i].first << "->" << orderedStrs[i].second << '\n';
      // }
      
      return result;
    }   
};

int main() {

   vector<string> strs {"a"};

   vector<vector<string>> result = Solution::groupAnagrams(strs);

   for (const auto &row : result) {
        std::cout << '[';
        for (int i = 0; i < row.size(); ++i) {
            std::cout << row[i];
            if (i + 1 < row.size()) std::cout << ", ";
        }
        std::cout << "]\n";
    }
    return 0;
}