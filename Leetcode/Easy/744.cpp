class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {

        for(auto &letter : letters){
            if((int)letter > (int)target){
                return letter;
            }
        }  

        return letters[0];
    }
};