#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <complex>
#include <locale>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <bitset>
using namespace std;
int n, k;
int start, finish;
vector<int> ansA, ansB, ansC;
set<long long> st;

string Str(long long x)
{
    stringstream ss;
    ss << x;
    return ss.str();
}

bool Check(long long a, int b, int c)
{
    string sA = Str(a), sBC = Str(b) + Str(c);
    sort(sA.begin(), sA.end());
    sort(sBC.begin(), sBC.end());
    if(sA != sBC)
    {
        return false;
    }
    if(st.find(a) != st.end())
    {
        return false;
    }
    st.insert(a);
    return true;
}

int main()
{
    //ifstream cin("xnum.inp");
    //ofstream cout("xnum.out");
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> k;
    start = 1;
    for(int i = 2; i <= n; i++)
    {
        start *= 10;
    }
    finish = start * 10 - 1;
    for(int b = start; b <= finish; b++)
    {
        for(int c = start; c <= finish; c++)
        {
            if(Check(b * c, b, c))
            {
                ansA.push_back(b * c);
                ansB.push_back(b);
                ansC.push_back(c);
            }
            if(ansA.size() == k)
            {
                for(int i = 0; i < k; i++)
                {
                    cout << ansA[i] << "=" << ansB[i] << "*" << ansC[i] << "\n";
                }
                return 0;
            }
        }
    }
    return 0;
}
