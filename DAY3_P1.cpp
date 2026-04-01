#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> p = positions;
        map<long long int, long long int> mp1;
        map<long long int, char> mp2;

        for (int i = 0; i < n; i++) {
            mp1[positions[i]] = healths[i];
            mp2[positions[i]] = directions[i];
        }

        sort(positions.begin(), positions.end());

        string s = "";
        for (int i = 0; i < n; i++) {
            s += mp2[positions[i]];
        }

        stack<pair<char, int>> st;
        int m = s.length();

        for (int i = 0; i < m; i++) {
            if (s[i] == 'L') {
                if (!st.empty()) {
                    auto it = st.top();

                    if (mp1[positions[it.second]] > mp1[positions[i]]) {
                        mp1[positions[it.second]]--;
                        mp1[positions[i]] = -1;
                    } 
                    else if (mp1[positions[it.second]] < mp1[positions[i]]) {
                        st.pop();
                        mp1[positions[it.second]] = -1;
                        mp1[positions[i]] += -1;

                        while (!st.empty()) {
                            it = st.top();

                            if (mp1[positions[it.second]] == mp1[positions[i]]) {
                                st.pop();
                                mp1[positions[it.second]] = -1;
                                mp1[positions[i]] = -1;
                                break;
                            }

                            if (mp1[positions[it.second]] > mp1[positions[i]]) {
                                mp1[positions[it.second]]--;
                                mp1[positions[i]] = -1;
                                break;
                            } 
                            else {
                                st.pop();
                                mp1[positions[it.second]] = -1;
                                mp1[positions[i]] += -1;
                            }
                        }
                    } 
                    else {
                        st.pop();
                        mp1[positions[it.second]] = -1;
                        mp1[positions[i]] = -1;
                    }
                }
            } 
            else {
                st.push({'R', i});
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (mp1[p[i]] > 0) {
                ans.push_back(mp1[p[i]]);
            }
        }

        return ans;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> positions(n), healths(n);
    for (int i = 0; i < n; i++) cin >> positions[i];
    for (int i = 0; i < n; i++) cin >> healths[i];

    string directions;
    cin >> directions;

    Solution obj;
    vector<int> result = obj.survivedRobotsHealths(positions, healths, directions);

    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}