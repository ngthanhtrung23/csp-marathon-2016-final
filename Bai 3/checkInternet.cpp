#include <bits/stdc++.h>

using namespace std;

const int N = 500005;

string outputPath, resultPath;
int n, result, output;
vector<int> edge[N];
vector<bool> oldEdge[N];
int num[N], low[N], parent[N];
int Count;

void addEdge(int u, int v, bool old) {
    edge[u].push_back(v);
    oldEdge[u].push_back(old);
    edge[v].push_back(u);
    oldEdge[v].push_back(old);
}

void visit(int u) {
    num[u] = ++Count;
    low[u] = N;
    for(int i = 0; i < edge[u].size(); i++) {
        int v = edge[u][i];
        if (v != parent[u]) {
            if (num[v] == 0) {
                parent[v] = u;
                visit(v);
                low[u] = min(low[u], low[v]);
            } else if (num[v] < num[u])
                low[u] = min(low[u], num[v]);
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    getline(cin, resultPath);
    getline(cin, outputPath);

    fstream fs;
    fs.open( (resultPath + "internet.inp").c_str());
    fs >> n;
    int u, v;
    for (int i = 0; i < n - 1; i++) {
        fs >> u >> v;
        addEdge(u, v, 1);
    }
    fs.close();

    fs.open( (resultPath + "internet.out").c_str());
    fs >> result;
    fs.close();

    fs.open( (outputPath + "internet.out").c_str());
    fs >> output;
    cout << n << endl;
    if (output != result) {
        cout << "Ket qua sai" << endl;
        cout << 0;
        return 0;
    }
    for (int i = 0; i < output; i++) {
        fs >> u >> v;
        addEdge(u, v, 0);
    }
    fs.close();
    visit(1);
    for(int u = 1; u <= n; u++) if (parent[u] != 0 && low[u] >= num[u]) {
        for(int i = 0; i < edge[u].size(); i++) {
            int v = edge[u][i];
            if (v == parent[u] && oldEdge[u][i]) {
                cout << "Cac canh them vao sai" << endl;
                cout << 0;
                return 0;
            }
        }
    }
    cout << "Ket qua dung" << endl;
    cout << 1;
    return 0;
}
