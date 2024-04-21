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

const ll N = 5005;
ll a[N], hot[N], cold[N], n, k;
 
ll f(ll index, ll last, v2d &dp)
{
    if(index == n) return 0;


    if(dp[index][last] != -1) return dp[index][last];
    
    //case where we are taking the last index other than aind-1
    ll option1 = f(index + 1, a[index - 1], dp) + (last == a[index] ? hot[a[index]] : cold[a[index]]);

    //case we are taking ind-1
    ll option2 = f(index + 1, last, dp) + (a[index - 1] == a[index] ? hot[a[index]] : cold[a[index]]);
 
    return dp[index][last] = min(option1, option2);
}

void solve(){
        cin >> n >> k;
        for(ll i = 0; i < n; i++) cin >> a[i];
        for(ll i = 1; i <= k; i++) cin >> cold[i];
        for(ll i = 1; i <= k; i++) cin >> hot[i];
        v2d dp(n, v1d(k + 1,-1));
    
        cout << cold[a[0]] +  f(1, 0, dp) << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t){
        t--;
        solve();
    }
}