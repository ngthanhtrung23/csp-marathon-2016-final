#include <bits/stdc++.h>

#define reset(a, b) memset(a, b, sizeof(a))
#define REP(i, a) for (int i = 0; i < a.size(); i++)

using namespace std;

const int N = 100100;
const int INF = 1000000007;

const int NUM_TEST = 11;

string toString(int s) {
    string r = "";
    if (s == 0) return "0";
    while (s > 0) {
        r = char(s % 10 + 48) + r;
        s /= 10;
    }
    return r;
}

void make(int test_no){
    string cmd = "mkdir TEST" + toString(test_no);
    string url = "TEST" + toString(test_no);
    string file_in = toString(test_no) + ".in";
    string file_out = toString(test_no) + ".out";

    system(cmd.c_str());
    system(("move " + file_in + " " + url + "\\birds.inp").c_str());
    system(("move " + file_out + " " + url + "\\birds.out").c_str());

}

int main() {
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    for (int i = 1; i <= NUM_TEST; i++)
        make(i);
}
