#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(a) (a).rbegin(), (a).rend()
#define lb lower_bound
#define ub upper_bound
using vi = vector<int>;
using vpi = vector<pair<int, int>>;
using v2d = vector<vector<int>>;
using v3d = vector<vector<vector<int>>>;
using pii = pair<int,int>;
#define ps(x, y) fixed << setprecision(y) << x
const int INF = 1e18;
const int MOD = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int getRandomNumber(int l, int r) {return uniform_int_distribution<int>(l, r)(rng);}

//Operations in array
int maxx(vi &a){return (*max_element(a.begin(), a.end()));}
int minn(vi &a){return (*min_element(a.begin(), a.end()));}
int gcd(int a, int b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
long long lcm(int a, int b){return (a / gcd(a, b)) * b;}
bool isPrime(int n)
{
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}

void getInput(vector<int> &arr){
    for(int i=0;i<arr.size();i++){
        cin>>arr[i];
    }
}

void input1(int s,int end,vi &arr){
    for(int i=s;i<=end;i++){
        cin>>arr[i];
    }
}

//debuging part
void debug(vector<int> &arr){
    for(auto &it : arr){
        cout<<it<<" ";
    }
    cout<<"\n";
}
void print(int res){cout<<res<<"\n";}
void prints(string &res){cout<<res<<"\n";}
void yes(){cout<<"Yes"<<"\n";}
void no(){cout<<"No"<<"\n";}
pii secMin(vi &a){
    int first=INT_MAX,second=INT_MAX;
    for(int i=0;i<a.size();i++){
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
int ceil_div(int a, int b) {
    return (a + b - 1) / b;
}
//modular arithmetic stuff here
long long mod(long long x){return ((x % MOD + MOD) % MOD);}
long long add(long long a, long long b){return mod(mod(a) + mod(b));}
long long mul(long long a, long long b){return mod(mod(a) * mod(b));}
int power(int a, int b, int mod)
{
    if (b == 0)
    {
        return 1;
    }
    int ans = power(a, b / 2, mod);
    ans *= ans;
    ans %= mod;
    if (b % 2)
    {
        ans *= a;
    }
    return ans % mod;
}
int modularInverse(int number, int mod){return power(number, mod - 2, mod);}
//end of modular stuff
#define TYPEMAX(type)   std::numeric_limits<type>::max()
int dp[5000][5000][2];

void solve(){
    int n;
    cin>>n;
    vi a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    //v3d dp(n,v2d(n,vi(2)));
    for (int i = 0; i != n; ++i)
        for (int j = 0; j != n; ++j)
            dp[i][j][0] = dp[i][j][1] = (i == j ? 0 : TYPEMAX(int) / 2);     
    for(int r=0;r<n;r++){
        for(int l=r;l>=0;l--){
            for(int k=0;k<2;k++){
                int val = (k==0)?a[l]:a[r];
                if(l) dp[l-1][r][0] = min(dp[l-1][r][0],dp[l][r][k]+(val!=a[l-1]));
                if(r<n-1) dp[l][r+1][1] = min(dp[l][r + 1][1], dp[l][r][k] + (val!=a[r + 1]));
            }
        }
    }
    print(min(dp[0][n-1][0],dp[0][n-1][1]));
    //l to r flooded 
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