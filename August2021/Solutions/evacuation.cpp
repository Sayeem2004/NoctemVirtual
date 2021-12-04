#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

vector<vector<ll>> A(100005);
vector<ll> DP(100005, 1);

void dfs(ll n, ll p, ll k) {
    if (A[n].size() > 1 || n == 0) {
        vector<ll> T;
        for (auto x : A[n]) {
            if (x != p) {
                dfs(x, n, k);
                T.push_back(DP[x]);
            }
        }
        sort(T.rbegin(),T.rend());
        for (int i = 0; i < T.size() && i < k; i++)
            DP[n] += T[i];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n, m, k; cin >> n >> m >> k;
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        A[a-1].push_back(b-1);
        A[b-1].push_back(a-1);
    }
    dfs(0, -1, k);
    cout << (m+DP[0]-1)/DP[0] << "\n";
}
