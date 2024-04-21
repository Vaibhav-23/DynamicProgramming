#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(a) (a).rbegin(), (a).rend()
#define lb lower_bound
#define ub upper_bound
using vi = vector<long long>;
using vpi = vector<pair<ll, ll>>;
using v2d = vector<vector<long long>>;
using v3d = vector<vector<vector<long long>>>;
using pii = pair<ll,ll>;
#define ps(x, y) fixed << setprecision(y) << x
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);}

//Operations in array
ll maxx(vi &a){return (*max_element(a.begin(), a.end()));}
ll minn(vi &a){return (*min_element(a.begin(), a.end()));}
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

void input1(ll s,ll end,vi &arr){
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
pii secMin(vi &a){
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
void solve(){
    ll n,m,k;
    cin>>n>>m>>k;
    // v2d c(n,vi(m,0));
    vi col(n+1,0);
    input1(1,n,col);
    v2d cost(n+1,vi(m+1,0));
    for(ll i=1;i<=n;i++){
        input1(1,m,cost[i]);
    }
    v3d dp(n+1,v2d(k+1,vi(m+1,1e12)));
    //index,beauty,color
    // what will be base case??
	if(col[1]==0){
        for(ll i=1;i<=m;i++){
            dp[1][1][i]=cost[1][i];
        }
    }
    else dp[1][1][col[1]]=0;
    dp[0][0][0]=0;
    for(ll i=2;i<=n;i++){
        for(ll j=1;j<=k;j++){
            if(col[i]==0){
                for(ll a=1;a<=m;a++){
                    dp[i][j][a] = min(dp[i][j][a], dp[i-1][j][a] + cost[i][a]);
                    for(ll prev=1;prev<=m;prev++){
                        if(prev!=a) dp[i][j][a]=min(dp[i][j][a],dp[i-1][j-1][prev]+cost[i][a]);
                    }
                }
            }
            else{
                dp[i][j][col[i]]=min(dp[i][j][col[i]],dp[i-1][j][col[i]]);
                for(ll a=1;a<=m;a++){
                    if(a!=col[i]){
                        dp[i][j][col[i]]=min(dp[i][j][col[i]],dp[i-1][j-1][a]);
                    }
                }
            }
        }
    }
    ll mini=1e12;
    for(ll i=0;i<=m;i++){
        mini=min(mini,dp[n][k][i]);
    }
    if(mini>=1e12) print(-1);
    else print(mini);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t){
        t--;
        solve();
    }
}