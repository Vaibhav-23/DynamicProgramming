#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(a) (a).rbegin(), (a).rend()
#define lb lower_bound
#define ub upper_bound
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
int main(){
    v1d cost(1001,1e9);
    cost[1]=0;
    for(ll i=1;i<=1000;i++){
        for(ll x=1;x<=i;x++){
            ll j = (i+i/x);
            if(j<=1000){
                cost[j]=min(cost[j],1+cost[i]);
            }
        }
    }
    int t;
    cin>>t;
    while(t){
        ll n,cap;
        cin>>n>>cap;
        v1d b(n+1),cost(n+1);
        ll sum=0;
        for(ll i=1;i<=n;i++){
            cin>>b[i];
            b[i]=cost[b[i]];
            sum+=b[i];
        }
        for(ll i=1;i<=n;i++){
            cin>>cost[i];
        }
        cap=min(cap,sum);
        v1d prev(cap+1,0);
        for(ll i=1;i<=n;i++){
            v1d curr(cap+1,0);
            for(ll j=0;j<=cap;j++){
                //nottake
                curr[j]=prev[j];
                //take here
                if(j>=b[i]){
                    curr[j]=max(curr[j],prev[j-b[i]]+cost[i]);
                }
            }
            prev=curr;
        }
        cout<<prev[cap]<<"\n";
        t--;
    }
}