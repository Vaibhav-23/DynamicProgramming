#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(a) (a).rbegin(), (a).rend()
#define lb lower_bound
#define ub upper_bound
#define int long long
#define ld long double
using v1d = vector<ld>;
using vpi = vector<pair<ll, ll>>;
using v2d = vector<vector<ld>>;
using v3d = vector<vector<vector<ld>>>;
using pii = pair<ll,ll>;
#define ps(x, y) fixed << setprecision(y) << x
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);}

//Operations in array
ll maxx(v1d &a){return (*max_element(a.begin(), a.end()));}
ll minn(v1d &a){return (*min_element(a.begin(), a.end()));}
ll gcd(ll a, ll b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
long long lcm(ll a, ll b){return (a / gcd(a, b)) * b;}
bool isPrime(ll n)
{
    if (n <= 1) return false;
    for (ll i = 2; i * i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}

void getInput(vector<ll> &arr){
    for(ll i=0;i<arr.size();i++){
        cin>>arr[i];
    }
}

void input1(ll s,ll end,v1d &arr){
    for(ll i=s;i<=end;i++){
        cin>>arr[i];
    }
}

//debuging part
void debug(vector<ll> &arr){
    for(auto &it : arr){
        cout<<it<<" ";
    }
    cout<<"\n";
}
void print(ll res){cout<<res<<"\n";}
void prints(string &res){cout<<res<<"\n";}
void yes(){cout<<"Yes"<<"\n";}
void no(){cout<<"No"<<"\n";}
pii secMin(v1d &a){
    ll first=INT_MAX,second=INT_MAX;
    for(ll i=0;i<a.size();i++){
        if(first>=a[i]){
            second=first;
            first=a[i];
        }
        else if(second>a[i] && first!=second){
            second=a[i];
        }
    }
    return {first,second};
}
//xor from 1 to n
int xortilln(int n){ 
    if (n % 4 == 0) return n; 
    else if (n % 4 == 1) return 1; 
    else if (n % 4 == 2) return n + 1; 
    else return 0; 
} 

//ceildivision
ll ceil_div(ll a, ll b) {
    return (a + b - 1) / b;
}
//modular arithmetic stuff here
long long mod(long long x){return ((x % MOD + MOD) % MOD);}
long long add(long long a, long long b){return mod(mod(a) + mod(b));}
long long mul(long long a, long long b){return mod(mod(a) * mod(b));}
long long sub(ll a,ll b){
    return ((a-b)%MOD + MOD)%MOD;
}
ll power(ll a, ll b, ll mod)
{
    if (b == 0)
    {
        return 1;
    }
    ll ans = power(a, b / 2, mod);
    ans *= ans;
    ans %= mod;
    if (b % 2)
    {
        ans *= a;
    }
    return ans % mod;
}
ll modularInverse(ll number, ll mod){return power(number, mod - 2, mod);}
//end of modular stuff
int n;
long double f(int ones,int two,int threes,v3d &dp){
    if(ones+two+threes==0) return 0;

    if(dp[ones][two][threes]!=-1.0) return dp[ones][two][threes];
    int zeros = n-(ones+two+threes);
    ld p_zeros = ((ld)zeros)/n;
    ld p_ones = ((ld)ones)/n;
    ld p_twos = ((ld)two)/n;
    ld p_threes = ((ld)threes)/n;
    ld val=1;
    if(ones>0){
        val += p_ones*(f(ones-1,two,threes,dp));
    }
    if(two>0){
        val += p_twos*(f(ones+1,two-1,threes,dp));
    }
    if(threes>0){
        val += p_threes*(f(ones,two+1,threes-1,dp));
    }

    return dp[ones][two][threes]=val/(1-p_zeros);

}
void solve(){
    cin>>n;
    vector<ll> a(n);
    int ones=0,two=0,threes=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==1) ones++;
        else if(a[i]==2) two++;
        else if(a[i]==3) threes++;
    }
    v3d dp(n+1,v2d(n+1,v1d(n+1,-1.0)));
    cout<<fixed<<setprecision(15)<<f(ones,two,threes,dp)<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t){
        t--;
        solve();
    }
}