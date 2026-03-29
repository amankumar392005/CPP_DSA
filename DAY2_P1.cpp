#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll mod = 1e9 + 7;

ll powexp(ll a){
    ll b = mod - 2;
    ll ans = 1;
    while(b){
        if(b & 1){
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

ll find_val(ll n, ll k){
    ll ans = 1;

    for(ll i = n; i > n - k; i--){
        ans = (ans * i) % mod;
    }

    for(ll i = 2; i <= k; i++){
        ans = (ans * powexp(i)) % mod;
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        ll n, pos, k;
        cin >> n >> pos >> k;

        ll ans = find_val(n - 1, k);
        ans = (ans * 2) % mod;

        cout << ans << "\n";
    }

    return 0;
}