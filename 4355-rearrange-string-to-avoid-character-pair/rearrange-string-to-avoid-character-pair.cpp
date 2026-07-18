class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        string t = "";
        for(auto it : s){
            if(it != y) continue;
            t += it;
        }
        for(auto it : s){
            if(it == y) continue;
            t += it;
        }
        return t;
    }
};