class Solution {
    
public:
    string getPermutation(int n, int k) {
        vector<int> fact(n+1, 1);
        vector<char> chars(n);

        for(int i = 1; i <= n; i++){
            fact[i] = fact[i-1] * i;
            chars[i-1] = i+'0';
        }
        
        
        k--;
        string ans;
        for(int i = 1; i <= n; i++){
            int index = k / fact[n-i];
            ans += chars[index];
            cout<<ans<<endl;
            vector<char>::iterator it=chars.begin()+index;
            chars.erase(it);
            k -= index*fact[n-i];
        }

        return ans;
    }
};