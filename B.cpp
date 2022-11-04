#include <bits/stdc++.h>

using namespace std;

const int mxN = 250 * 250 + 5;

#define ll long long
#define pb push_back
#define F first
#define S second
#define all(x) (x).begin(), (x).end()

map<ll, ll> mp;

ll solve (ll N) {
    if (mp[N] != 0) return mp[N];

    if (N == 0) return 1;
    else if (N == 1) return 2;
    else if (N == 2) return 3;
    else if (N == 3) return 4;
    else {
        return mp[N] = solve(N / 2) + solve(N / 3);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll N; cin >> N;

    cout << solve(N);

    return 0;
}

