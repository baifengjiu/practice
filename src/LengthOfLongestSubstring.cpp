#include <iostream>
#include <string>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        if (s.size() < 2) return s.size();
        int preIndex = 0;
        int index = 1;
        int maxLength = 0;

        auto maxFunc = [&index,&preIndex,&maxLength](){
            if (index - preIndex > maxLength) {
                maxLength = index - preIndex;
                if (preIndex == 0) {
                    maxLength += 1;
                }
            }
        };


        while (index< s.size()) {
            char &ch = s[index];
            bool contains = false;
            for (int i = preIndex; i < index; i++) {
                if (s[i] == ch) {
                    maxFunc();
                    preIndex++;
                    contains = true;
                    break;
                }

            }
            if (!contains)
                index++;
        }
        index++;
        preIndex++;
        maxFunc();
        return maxLength;
    }
};
//int main(int argc, char* argv[]){
//    Solution solution;
//    std::cout<< solution.lengthOfLongestSubstring("au");
//    return 0;
//}