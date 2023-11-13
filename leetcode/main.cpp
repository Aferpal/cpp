#include <iostream>
#include<string>
#include <unordered_set>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_set<char> visitedChars;
        int max=0;
        for(int i=0; i<s.length(); i++){
            char c=(s[i]==' ')?'\n':s[i];
            if(visitedChars.find(c)!=visitedChars.end()){
                max=visitedChars.size()>max?visitedChars.size():max;
                visitedChars.clear();
            }
            
            visitedChars.insert(c);
            
        }
        max=visitedChars.size()>max?visitedChars.size():max;
        return max;
    }
};

int main(){
    Solution sol= Solution();
    int a=sol.lengthOfLongestSubstring(" ");
    std::cout<<a;
}