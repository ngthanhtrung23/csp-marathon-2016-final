#include "testlib.h"
#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; ++i)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; --i)
#define REP(i,a) for(int i=0,_a=(a); i < _a; ++i)
using namespace std;

int main(int argc, char* argv[]) {
	registerValidation(argc, argv);
    FOR(i,1,6) {
        FOR(j,1,6) {
            char c = inf.readChar();
            ensuref(c == '.' || (c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z'), ".09AZ");
        }
        inf.readEoln();
    }
    inf.readEof();
}
