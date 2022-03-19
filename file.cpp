#include "bits/stdc++.h"

using namespace std;

template<typename T>
void print(T t)
{
    for (const auto &e : t) cout << e << " ";
    cout << "\n";
}

#define ll long long int
#define mp make_pair
#define all(v) v.begin(),v.end()
#define eb emplace_back
#define pb push_back
#define len(v) ((ll)(v.size()))

const ll MAX_SIZE = 1000005;
const ll ninf = (-1) * (1ll << 60);
const ll inf = 1ll << 60;
const ll mod = 1000000007;

bool subsetsum(ll a[], ll sum, ll n)
{
    bool t[n][sum + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        t[i][0] = 1;
    }
    t[0][a[0]] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (t[i - 1][j])
            {
                t[i][j] = 1;
                if (j + a[i] < sum + 1) t[i][j + a[i]] = 1;
            }
        }
    }
    return t[n - 1][sum];
}

void solve(ll TC)
{
    ll a[6] = {2, 5, 6, 9, 7, 3};
    cout << subsetsum(a, 14, 6);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    ll Tc = 1;
    //cin >> Tc;

    for (ll tc = 1; tc <= Tc; tc++)
    {
        solve(tc);
    }

    return 0;
}