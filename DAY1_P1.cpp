// LEETCODE : 2573
// Author : AMAN KUMAR
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(string &s, vector<vector<int>>& lcp) {
        int n = s.size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int k = 0;

                while(i + k < n && j + k < n && s[i + k] == s[j + k]){
                    k++;
                }

                if(k != lcp[i][j]){
                    return false;
                }
            }
        }
        return true;
    }

    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        int k = n;

        for(int i = 0; i < n; i++){
            if(lcp[i][i] != k){
                return "";
            }
            k--;
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(lcp[i][j] != lcp[j][i]){
                    return "";
                }
            }
        }

        string s = "";
        vector<set<char>> v(n);
        string a = "abcdefghijklmnopqrstuvwxyz";
        set<char> st;

        for(int i = 0; i < 26; i++){
            st.insert(a[i]);
        }

        for(int i = 0; i < n; i++){
            v[i] = st;
        }

        for(int i = 0; i < n; i++){
            if(!v[i].empty()){
                s += *v[i].begin();
            }
            else return "";

            for(int j = i + 1; j < n; j++){
                if(lcp[i][j] == 0){
                    if(!v[j].empty()) v[j].erase(s[i]);
                    else return "";
                }
            }
        }

        if(!check(s, lcp)) return "";
        return s;
    }
};

int main() {
    int n;
    cin >> n;

    vector<vector<int>> lcp(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> lcp[i][j];
        }
    }

    Solution obj;
    string result = obj.findTheString(lcp);

    if(result == "") cout << -1 << endl;
    else cout << result << endl;

    return 0;
}