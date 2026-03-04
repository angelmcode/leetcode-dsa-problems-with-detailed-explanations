// Time Complexity: O(n) Space Complexity: O(n*m)
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> map; //space O(n*m)
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) { //time O(1)
        map[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) { // time O(n)
        if (map[key].empty())return "";
        int s = map[key].size();
        for (int i = 0; i < s; i++)
        {
            if (map[key][i].first == timestamp){
                return map[key][i].second;
            } else if (map[key][i].first > timestamp)
            {
                if (i==0)
                {
                    return "";
                } else{
                    return map[key][i-1].second;
                }
            }
        }
        return map[key][s-1].second;
    }
};


int main (){
   TimeMap tm;

   tm.set("alice", "happy", 1);
   string r1 = tm.get("alice", 1);

   cout << r1 << '\n';

   return 0;
}