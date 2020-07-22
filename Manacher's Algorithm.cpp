class Solution {
public:
    string longestPalindrome(string s) {
        string newStr = "$#";
        for(char c : s) {
            newStr += c;
            newStr += "#";
        }
        newStr += "@";
        
        int c, r, ans;
        c = r = 1;
        ans = 0;
        int arr[newStr.size()];
        memset(arr, 0, sizeof(arr));
        int si, len;
        si = len = 0;
        
        for(int i = 1; i < newStr.size() - 1; i++) {
            int mirr = 2*c - i;
            
            if(i < r) {
                arr[i] = min(arr[mirr], r - i);
            }
            
            while(newStr[i - (1 + arr[i])] == newStr[i + (1 + arr[i])]) {
                arr[i]++;
            }
            if(i + arr[i] > r) {
                r = i + arr[i];
                c = i;
                if(arr[i] > len) {
                    si = i;
                    len = arr[i];
                }
            }
            
        }
        return s.substr((si - len)/2, len);
    }
};