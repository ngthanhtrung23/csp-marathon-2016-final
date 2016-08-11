#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; ++i)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; --i)
#define REP(i,a) for(int i=0,_a=(a); i < _a; ++i)

#define DEBUG(X) { cerr << #X << " = " << (X) << endl; }

#define sqr(x) ((x) * (x))
#define ll long long
#define __builtin_popcount __builtin_popcountll
#define SZ(x) ((int) (x).size())
using namespace std;

double safe_sqrt(double x) {
    return sqrt(max((double)0.0,x));
}
int GI(ll& x) {
    return scanf("%lld", &x);
}

int m, n;

char rev(const char& c) {
    if (c == 'L' || c == 'R') return 'L' + 'R' - c;
    if (c == 'U' || c == 'D') return 'U' + 'D' - c;
    assert(0);
}

struct Move {
    int piece;
    char dir;
    int len;

    void read() {
        cin >> piece >> dir >> len;
    }

    void print() {
        cout << (char) piece << ' ' << dir << ' ' << len << endl;
    }

    Move rev() const {
        Move res;
        res.piece = piece;
        res.dir = ::rev(dir);
        res.len = len;
        return res;
    }
};

struct State {
    char a[8][8];

    ll hash() {
        ll res = 0;
        FOR(i,1,m) FOR(j,1,n) {
            int val;
            if (a[i][j] == '.') val = 10;
            else if (a[i][j] >= '0' && a[i][j] <= '9') val = a[i][j] - '0';
            else val = a[i][j] - 'A' + 11;

            res = res * 17 + val;
        }
        return res;
    }

    void read() {
        memset(a, ' ', sizeof a);
        FOR(i,1,m) FOR(j,1,n) cin >> a[i][j];
    }

    void print() const {
        FOR(i,1,m) {
            FOR(j,1,n) cout << a[i][j];
            cout << endl;
        }
    }

    string getPieces() {
        set<char> all;
        FOR(i,1,m) FOR(j,1,n) if (a[i][j] != '.') all.insert(a[i][j]);
        string res = "";
        for(char c : all) res += c;
        return res;
    }

    int isPiece(int u, int v) const {
        if (a[u][v] == '.') return -1;
        assert((a[u][v] >= '0' && a[u][v] <= '9') || (a[u][v] >= 'A' && a[u][v] <= 'Z'));
        return a[u][v];
    }

    vector< pair<int,int> > locate(int piece) const {
        vector< pair<int,int> > res;
        FOR(i,1,m) FOR(j,1,n) {
            if (isPiece(i, j) == piece) {
                res.emplace_back(i, j);
            }
        }
        return res;
    }
} cur;

pair<int,int> getDir(char c) {
    if (c == 'L') return make_pair(0, -1);
    if (c == 'R') return make_pair(0, 1);
    if (c == 'U') return make_pair(-1, 0);
    if (c == 'D') return make_pair(1, 0);
    assert(0);
}

bool canMove(const State& s, const Move& m) {
    auto pos = s.locate(m.piece);

    assert(SZ(pos) >= 2);
    if (pos[0].first == pos[1].first) { // on same row
        if (m.dir == 'U' || m.dir == 'D') return false;
    }
    else { // on same col
        if (m.dir == 'L' || m.dir == 'R') return false;
    }

    auto dir = getDir(m.dir);

    FOR(step,1,m.len) {
        for(auto p : pos) {
            int u = p.first + dir.first * step;
            int v = p.second + dir.second * step;

            if (s.a[u][v] != '.' && s.a[u][v] != m.piece) return false;
        }
    }
    return true;
}

void makeMove(State& s, const Move& m) {
    assert(canMove(s, m));

    auto pos = s.locate(m.piece);
    auto dir = getDir(m.dir);

    for(auto p : pos) {
        s.a[p.first][p.second] = '.';
    }

    for(auto p : pos) {
        int u = p.first + dir.first * m.len;
        int v = p.second + dir.second * m.len;

        s.a[u][v] = m.piece;
    }
}

int main() {
    ios :: sync_with_stdio(0); cin.tie(0);
    cout << (fixed) << setprecision(9);
    m = n = 6;
    cur.read();
    string allDir = "LRUD";
    string allPieces = cur.getPieces();

    queue<State> qu;
    map<ll, string> visited;

    qu.push(cur);
    visited[cur.hash()] = "";

    int qsz = 0;
    while (!qu.empty()) {
        ++qsz;
        auto cur = qu.front(); qu.pop();
        ll h_cur = cur.hash();

        for(char piece : allPieces) {
            for(char dir : allDir) {
                FOR(step,1,4) {
                    Move m;
                    m.piece = piece;
                    m.dir = dir;
                    m.len = step;
                    if (canMove(cur, m)) {
                        State next = cur;
                        makeMove(next, m);

                        ll h_next = next.hash();

                        if (visited.find(h_next) == visited.end()) {
                            qu.push(next);
                            stringstream ss;
                            ss << (char) m.piece << ' ' << m.dir << ' ' << m.len << endl;
                            visited[h_next] = visited[h_cur] + ss.str();

                            if (next.a[3][6] == '0') {
                                int cnt = 0;
                                for(char c : visited[h_next])
                                    if (c == '\n')
                                        ++cnt;
                                DEBUG(qsz);
                                cout << cnt << endl;
                                cout << visited[h_next] << endl;
                                return 0;
                            }
                        }
                    }
                    else break;
                }
            }
        }
    }
    assert(0);
    cout << ":@)" << endl;
}
