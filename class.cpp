class Solution {
private:
    bool isLawful(long num){
        if(num < 256)
            return true;
        else
            return false;
    }
    long string_to_int(string s){
        long sum = 0;
        for(int i = 0; i < s.size(); i++){
            int num = s[i] -'0';
            sum = sum * 10 + num;
        }
        return sum;
    }
public:
    /**
     * 
     * @param s string字符串 
     * @return string字符串vector
     */
    vector<string> restoreIpAddresses(string s) {
        // write code here
        vector<string> ans;
        for(int i = 1; i < s.size() - 2; i++){
            string s1 = s.substr(0, i); 
            for(int j = i + 1; j < s.size() - 1; j++){
                string s2 = s.substr(i, j);
                for(int k = j + 1; k < s.size(); k++){
                    string s3 = s.substr(j, k);
                    string s4 = s.substr(k, s.size());
                    long num1 = string_to_int(s1);
                    long num2 = string_to_int(s2);
                    long num3 = string_to_int(s3);
                    long num4 = string_to_int(s4);
                    if(isLawful(num1) && isLawful(num2) && isLawful(num3) && isLawful(num4)){
                        string s = s1 + "." + s2 + "." + s3 + "." + s4;
                        ans.push_back(s);
                    }
                }
            }
        }
        return ans;
        
    }
};
