class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        //isme ek arr bnani pdegi vo btaegi that if i choose my power of changing character of word1 then kya mujhe age leftover matching charaters milenge (suffix arr)
        int n = word1.size();
        int m = word2.size();
        vector<int> rightMatchingChar(n);
        int i = n-1;
        int j = m-1; 
        int matched = 0;
        while(i >= 0 && j >= 0){
            if(word1[i] == word2[j]){
                matched++;
                rightMatchingChar[i] = matched;
                i--;
                j--;
            }
            else{
                rightMatchingChar[i] = matched;
                i--;
            }
        }
        while(i >= 0){
            rightMatchingChar[i] = rightMatchingChar[i+1];
            i--;
        }
        // for(auto it : rightMatchingChar){
        //     cout<<it<<" ";
        // }
        i =0;
        j =0;
        vector<int> indices;
        bool changingPower = true;
        while(i < n && j < m){
            if(word1[i] == word2[j]){
                indices.push_back(i);
                i++;
                j++;
            }
            //age changing power h and jo rightmatching ka i+1 ki val agr remaining unmatched char ki ho toh use krlo changing power
            else if(changingPower && i < n-1 && rightMatchingChar[i+1] >= m - j-1){
                indices.push_back(i);
                changingPower = false;
                i++;
                j++;
                
            }
            else{
                i++;
            }
        }
        if(indices.size() == m){
            return indices;
        }
        return {};
    }
};