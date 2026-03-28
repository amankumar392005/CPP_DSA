#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        map<long long, vector<long long>> a, b;

        long long k = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                a[grid[i][j]].push_back(k);
                k++;
            }
        }

        k = 1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                b[grid[j][i]].push_back(k);
                k++;
            }
        }

        vector<long long> row(n), col(m);
        long long tsum = 0;

        for(int i = 0; i < n; i++){
            long long sum = 0;
            for(int j = 0; j < m; j++){
                sum += grid[i][j];
                tsum += grid[i][j];
            }
            row[i] = sum;
        }

        for(int i = 0; i < m; i++){
            long long sum = 0;
            for(int j = 0; j < n; j++){
                sum += grid[j][i];
            }
            col[i] = sum;
        }

        long long prev = row[0];
        for(int i = 1; i < n; i++){
            long long temp = tsum - prev;

            if(temp == prev) return true;

            if(prev > temp){
                long long z = prev - temp;
                if(a[z].size()){
                    if(a[z][0] <= (i * m)){
                        if(i >= 2 && m >= 2) return true;

                        if(i == 1){
                            if(a[z][0] == 1 || a[z][0] == m) return true;
                        }

                        if(m == 1){
                            if(a[z][0] == i || a[z][0] == 1) return true;
                        }
                    }
                }
            }
            else{
                long long z = temp - prev;
                if(a[z].size()){
                    if(a[z].back() > (i * m)){
                        if((n - i >= 2) && m >= 2) return true;

                        if(i == 1){
                            if(a[z].back() == m * n || a[z].back() == ((n - 1) * m + 1)) return true;
                        }

                        if(m == 1){
                            if(a[z].back() == i + 1 || a[z].back() == n) return true;
                        }
                    }
                }
            }

            prev += row[i];
        }

        prev = col[0];
        for(int i = 1; i < m; i++){
            long long temp = tsum - prev;

            if(temp == prev) return true;

            if(prev > temp){
                long long z = prev - temp;
                if(b[z].size()){
                    if(b[z][0] <= (i * n)){
                        if(i >= 2 && n >= 2) return true;

                        if(i == 1){
                            if(b[z][0] == 1 || b[z][0] == n) return true;
                        }

                        if(n == 1){
                            if(b[z][0] == i || b[z][0] == 1) return true;
                        }
                    }
                }
            }
            else{
                long long z = temp - prev;
                if(b[z].size()){
                    if(b[z].back() > (i * n)){
                        if((m - i >= 2) && n >= 2) return true;

                        if(i == 1){
                            if(b[z].back() == m * n || b[z].back() == ((m - 1) * n + 1)) return true;
                        }

                        if(n == 1){
                            if(b[z].back() == i + 1 || b[z].back() == m) return true;
                        }
                    }
                }
            }

            prev += col[i];
        }

        return false;
    }
};

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }

    Solution obj;
    bool ans = obj.canPartitionGrid(grid);

    if(ans) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}