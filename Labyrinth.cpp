#include <bits/stdc++.h>

using namespace std;

const int maxn = 1005;

#define ll long long
#define pb push_back
#define F first
#define S second
#define all(x) (x).begin(), (x).end()

int disx[4] = {1, -1, 0, 0};
int disy[4] = {0, 0, 1, -1};
char dir[maxn][maxn];
char a[maxn][maxn];
char pat[4] = {'R', 'L', 'D', 'U'};
char rpat[4] = {'L', 'R', 'U', 'D'};
bool vis[maxn][maxn];
string road;

void findRoute(int x, int y) {
    if (dir[y][x] == '#') return;
    road += dir[y][x];

    int tx = x, ty = y;
    for (int i = 0; i < 4; i++) {
        if (rpat[i] == dir[y][x]) {
            ty += disy[i];
            tx += disx[i];
        }
    }

    y = ty;
    x = tx;

    findRoute(x, y);
}

void solve () {
    memset(a, 0, sizeof(a));
    memset(vis, false, sizeof(vis));
    memset(dir, '#', sizeof(dir));
    road = "";

    int n, m;
    cin >> n >> m;
    pair<int, int> posA, posB;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'A') {
                posA.F = j;
                posA.S = i;
            }
            if (a[i][j] == 'B') {
                posB.F = j;
                posB.S = i;
            }
        }
    }

    // <x, y>
    queue<pair<int, int>> q;
    q.push({posA.F, posA.S});
    bool fd = 0;

    while (q.size()) {
        pair<int, int> p = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int cx = p.F + disx[i], cy = p.S + disy[i];
            if (cx >= 0 && cx < m && cy >= 0 && cy < n && !vis[cy][cx]) {
                if (a[cy][cx] == '.') {
                    q.push({cx, cy});
                    vis[cy][cx] = true;
                    dir[cy][cx] = pat[i];
                }

                if (a[cy][cx] == 'B') {
                    dir[cy][cx] = pat[i];
                    fd = 1;
                    break;
                }
            }
        }

        if (fd) break;
    }

    findRoute(posB.F, posB.S);
    reverse(all(road));

    if (fd) {
        cout << "YES\n";
        cout << road.length() << '\n';
        cout << road << '\n';
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}

