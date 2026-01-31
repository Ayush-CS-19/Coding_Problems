class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters[0];
        int count = INT_MAX;
        char ans = letters[0];
        for(int i = 0; i < letters.size(); i++){
            if(letters[i] - target >= 1){
                int c = letters[i] - target;
                if(count > c){
                    count = c;
                    ans = letters[i];
                }
            } 
        }
        return ans;
    }
};