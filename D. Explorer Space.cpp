#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(a) (a).rbegin(), (a).rend()
#define lb lower_bound
#define ub upper_bound
#define int long long
using v1d = vector<long long>;
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
int n,m,k;
bool isValid(int newi,int newj,int k){
    if(newi>=0 && newi<n && newj>=0 && newj<m && k>=2) return true;
    return false;
}
void solve(){
    cin>>n>>m>>k;
    v2d hor(n,v1d(m-1)),ver(n-1,v1d(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m-1;j++){
            cin>>hor[i][j];
        }
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m;j++){
            cin>>ver[i][j];
        }
    }

    //dp[i][j][k] here represents we are at the coordinate (i,j) and the minimum cost in k steps where we can come back
    //initializing everything to inf as we are taking minimum

    v3d dp(n,v2d(m,v1d(21,1e9)));
    
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    for(int k1=0;k1<=20;k1++){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(k1==0){
                    //base case
                    dp[i][j][k1]=0;
                }
                else if(k1&1){
                    dp[i][j][k1]=-1;
                }
                else{
                    for(int cases = 0; cases < 4; cases++){
                            int newI = i + dx[cases];
                            int newJ = j + dy[cases];
                            if(isValid(newI, newJ,k)){
                                int edgeWeight = 0;
                                if(newI != i){
                                    edgeWeight = ver[min(newI, i)][j];
                                }else{
                                    edgeWeight = hor[i][min(newJ, j)];
                                }
                                dp[i][j][k1] = min(dp[i][j][k1], dp[newI][newJ][k1 - 2] + 2 * edgeWeight);
                            }
                        }
                    }
                }
            }
        }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << dp[i][j][k] << " ";
        }
        cout << "\n";
    }
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