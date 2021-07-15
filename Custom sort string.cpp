//Time = O(n)
//Spacce = O(1)
class Solution {
public:
    string customSortString(string order, string str) {
        
        map<char,int> charCount;
        
        for(auto c:str){
            charCount[c]++;
        }
        int idx = 0;
        for(auto c:order){
            while(charCount[c]>0){
                str[idx++] = c;
                charCount[c]--;
            }
        }
        
        for(char c= 'a'; c<='z'; c++){
            while(charCount[c]>0){
                str[idx++] = c;
                charCount[c]--;
            }
        }
        
        return str;
    }
};
