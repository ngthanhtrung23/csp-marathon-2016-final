#include <bits/stdc++.h>
using namespace std;
typedef vector<int> bignum;
const int BASE = 1000000000;
string dirTest, dirProg;
ifstream inp, out;
int n, k;
set<string> st;

int Int(string s)
{
    stringstream ss(s);
    int res;
    ss >> res;
    return res;
}

bignum Bignum(string s)
{
    bignum res;
    for(int i = (int)s.size() - 1; i >= 0; i -= 9)
    {
        if(i >= 8)
        {
            res.push_back(Int(s.substr(i - 8, 9)));
        }
        else
        {
            res.push_back(Int(s.substr(0, i + 1)));
        }
    }
    return res;
}

bignum operator +(bignum a, bignum b)
{
    while(a.size() < b.size())
    {
        a.push_back(0);
    }
    while(a.size() > b.size())
    {
        b.push_back(0);
    }
    bignum res;
    int tmp = 0;
    for(int i = 0; i < a.size(); i++)
    {
        tmp += a[i] + b[i];
        res.push_back(tmp % BASE);
        tmp /= BASE;
    }
    if(tmp > 0)
    {
        res.push_back(tmp);
    }
    return res;
}

bignum operator *(bignum a, bignum b)
{
    bignum res;
    for(int i = 0; i < a.size(); i++)
    {
        bignum tmp1;
        for(int j = 0; j < i; j++)
        {
            tmp1.push_back(0);
        }
        long long tmp2 = 0;
        for(int j = 0; j < b.size(); j++)
        {
            tmp2 += (long long)a[i] * b[j];
            tmp1.push_back(tmp2 % BASE);
            tmp2 /= BASE;
        }
        if(tmp2 > 0)
        {
            tmp1.push_back(tmp2);
        }
        res = res + tmp1;
    }
    return res;
}

bool Valid(string s)
{
    if(s.size() != n * 4 + 2)
    {
        return false;
    }
    for(int i = 0; i < s.size(); i++)
    {
        if(i == n * 2)
        {
            if(s[i] != '=')
            {
                return false;
            }
        }
        else if(i == n * 3 + 1)
        {
            if(s[i] != '*')
            {
                return false;
            }
        }
        else
        {
            if(!(s[i] >= '0' && s[i] <= '9'))
            {
                return false;
            }
            if(i == 0 || i == n * 2 + 1 || i == n * 3 + 2)
            {
                if(s[i] == '0')
                {
                    return false;
                }
            }
        }
    }
    return true;
}

bool Check(string s)
{
    string sA = s.substr(0, n * 2), sB = s.substr(n * 2 + 1, n), sC = s.substr(n * 3 + 2, n);
    bignum a = Bignum(sA), b = Bignum(sB), c = Bignum(sC);
    if(st.find(sA) != st.end())
    {
        return false;
    }
    st.insert(sA);
    string sBC = sB + sC;
    sort(sA.begin(), sA.end());
    sort(sBC.begin(), sBC.end());
    if(sA != sBC)
    {
        return false;
    }
    if(a != b * c)
    {
        return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    getline(cin, dirTest);
    getline(cin, dirProg);
    inp.open((dirTest + "/xnum.inp").c_str());
    out.open((dirProg + "/xnum.out").c_str());
    inp >> n >> k;
    string line;
    int cntLine = 0;
    while(getline(out, line))
    {
        cntLine++;
        if(cntLine > k)
        {
            break;
        }
        if(!Valid(line))
        {
            cout << "Wrong Answer!\n";
            cout << "0\n";
            return 0;
        }
        if(!Check(line))
        {
            cout << "Wrong Answer!\n";
            cout << "0\n";
            return 0;
        }
    }
    if(cntLine != k)
    {
        cout << "Wrong Answer!\n";
        cout << "0\n";
        return 0;
    }
    cout << "Correct!\n";
    cout << "1\n";
    return 0;
}
