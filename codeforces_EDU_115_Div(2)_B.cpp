///Bismillahir Rahmanir Rahim
#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define ld long double
#define pll pair<ll, ll>
#define vpp vector<pair<ll, ll>>
#define pb push_back
#define ff first
#define ss second
#define case_(tc) cout << "Case " << tc << ": ";
#define mem(a, b) memset(a, b, sizeof(a))
#define all(vtor) vtor.begin(), vtor.end()
#define rall(vtor) vtor.rbegin(), vtor.rend()

#define pi 2 * acos(0.0)
#define tani(a) atan(a) / (pi / 180)
#define sini(a) asin(a) / (pi / 180)
#define cosi(a) cos(a) / (pi / 180)
#define cos(a) cos(a *pi / 180)
#define sin(a) sin(a *pi / 180)
#define tan(a) tan(a *pi / 180)
const ll mod = 1e9 + 7;

#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;

#define EPS 1e-13
#define maxii 32000
ll Pow(ll c, ll d)
{
    return d == 0 ? 1 : c * pow(c, d - 1);
}
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return ((a * b) / gcd(a, b)); }

ll egcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll gcd = egcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return gcd;
}
ll bigMod(ll a, ll b)
{
    a %= mod;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

inline ll MOD(ll a) { return (a % mod + mod) % mod; }
inline ll modAdd(ll a, ll b) { return MOD(MOD(a) + MOD(b)); }
inline ll modSub(ll a, ll b) { return MOD(MOD(a) - MOD(b)); }
inline ll modMul(ll a, ll b) { return MOD(MOD(a) * MOD(b)); }
inline ll modInv(ll a) { return bigMod(a, mod - 2); }
inline ll modDiv(ll a, ll b)
{
    a = MOD(a);
    b = modInv(b);
    return (a * b) % mod;
}

vector<string> v;
map<char, ll> mp;

set<string> vs;

void permute(string str, string out)
{
    // When size of str becomes 0, out has a
    // permutation (length of out is n)
    if (str.size() == 0)
    {
        vs.insert(out);
        return;
    }

    // One be one move all characters at
    // the beginning of out (or result)
    for (int i = 0; i < str.size(); i++)
    {
        // Remove first character from str and
        // add it to out
        permute(str.substr(1), out + str[0]);

        // Rotate string in a way second character
        // moves to the beginning.
        rotate(str.begin(), str.begin() + 1, str.end());
    }
}
bool isPrime(ll n)
{
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
ll ncr(ll nn, ll rr)
{
    if (rr > nn)
        return 0;
    if (rr == 0)
        return 1;
    if (rr == 1)
        return nn;
    if (nn == rr)
        return 1;
    return ncr(nn - 1, rr - 1) + ncr(nn - 1, rr);
}
bool compare(pair<ll, ll> p1, pair<ll, ll> p2)
{
    ll ans1, ans2;
    ans1 = min(2 * p1.ff, p1.ss) - min(p1.ff, p1.ss);
    ans2 = min(2 * p2.ff, p2.ss) - min(p2.ff, p2.ss);
    if (ans1 > ans2)
        return true;
    else
        return false;
}

int main()
{
    // ll c=0;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // avoiding collision using unordered_map only in CF
    //map_name.load_factor(0.25);
    //map_name.reserve(1024);

    // #ifndef ONLINE_JUDGE
    //     freopen("D:/Code_c++/input.txt", "r", stdin);
    //     freopen("D:/Code_c++/output.txt", "w", stdout);
    // #endif
    ll t;
    cin>>t;
   for(ll i=1;i<=t;i++)
   {
     ll cnt=0;
     map<ll,ll>mp;
     ll n;
     cin>>n;
     ll arr[n][5];
     for(ll i=0;i<n;i++)
     {
         for(ll j=0;j<5;j++)
          cin>>arr[i][j];
     }
     bool found = 0;
     for(ll i=0;i<5;i++)
     {
         for(ll j=i+1;j<5;j++)
         {
             ll b=0,x=0,y=0;
             for(ll k=0;k<n;k++)
             {
                 if(arr[k][i]==1 and arr[k][j]==1)
                 b++;
                 else if(arr[k][i]==1)
                 x++;
                 else if(arr[k][j]==1)
                 y++;
             }
             if(x+y+b==n and x<=n/2 and y<=n/2)
             found = 1;
             if(found)
             {
                 cout<<"YES\n";
             break;
             }
         }
         if(found)
         break;
     }
     if(!found)
    cout<<"NO\n";
   }

    return 0;
}
//1000000007