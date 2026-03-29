#include <bits/stdc++.h>
using namespace std;

int sortableIntegers(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;

    vector<int> v = nums;
    sort(v.begin(), v.end());

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {

            int j = 0, f = 0;

            // check for block size = i
            while (j < n) {
                int count = 0;
                vector<int> temp;

                for (int k = 0; k < i; k++) {
                    if (nums[j + k] > nums[j + (k + 1) % i])
                        count++;
                    temp.push_back(nums[j + k]);
                }

                sort(temp.begin(), temp.end());

                int z = 0;
                for (int k = 0; k < i; k++) {
                    if (temp[z++] != v[j + k]) {
                        f = 1;
                        break;
                    }
                }

                if (count > 1) {
                    f = 1;
                    break;
                }

                j += i;
            }

            if (f == 0)
                sum += i;

            // check for block size = n / i
            if (i != n / i) {
                j = 0;
                f = 0;
                int len = n / i;

                while (j < n) {
                    int count = 0;
                    vector<int> temp;

                    for (int k = 0; k < len; k++) {
                        if (nums[j + k] > nums[j + (k + 1) % len])
                            count++;
                        temp.push_back(nums[j + k]);
                    }

                    sort(temp.begin(), temp.end());

                    int z = 0;
                    for (int k = 0; k < len; k++) {
                        if (temp[z++] != v[j + k]) {
                            f = 1;
                            break;
                        }
                    }

                    if (count > 1) {
                        f = 1;
                        break;
                    }

                    j += len;
                }

                if (f == 0)
                    sum += len;
            }
        }
    }

    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        cout << sortableIntegers(nums) << "\n";
    }

    return 0;
}