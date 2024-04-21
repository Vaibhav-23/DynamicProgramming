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
ll helper(ll ind,ll last,ll sl,v3d &dp,string &s,ll f,ll sec){
    ll n=s.size();
    //handling the base case here
    if(ind==n-1){
        //have to check 3 conditions here
        //condition1 1st and 2nd index
        //condition2 n-2th index,n-1th and 1st
        //condition3 n-2th and n-3th index
        ll val=1e9;

        //taking left
        if((last==1 || sl==1) && (f==1 || sec==1) && (last==1 || f==1)){
            ll cnt=0;
            if(s[n-1]=='R') cnt=1;
            val=min(val,cnt);
        }

        //taking right
        if((last==0 || sl==0) && (f==0 || sec==0) && (last==0 || f==0)){
            ll cnt=0;
            if(s[n-1]=='L') cnt=1;
            val=min(val,cnt);
        }
        return dp[ind][last][sl]=val;
    }


    if(dp[ind][last][sl]!=-1) return dp[ind][last][sl];

    ll val = 1e9;

    //taking left here to take left here we shouldn't have previous 2 values as left
    //checking the condition for previous 2 values

    if(last!=0 || sl!=0){
        ll cnt=0;
        if(s[ind]=='R') cnt=1;
        val=min(val,cnt+helper(ind+1,0,last,dp,s,f,sec));
    }

    //putting right here
    if(last!=1 || sl!=1){
        ll cnt=0;
        if(s[ind]=='L') cnt=1;
        val=min(val,cnt+helper(ind+1,1,last,dp,s,f,sec));
    }
    
    return dp[ind][last][sl]=val;

}
void solve(){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll res=n;
    for(ll i=0;i<=1;i++){
        for(ll j=0;j<=1;j++){
            //here dp state dp[index][last][secondlast]represent
            //the minimum number of flips required to make from i to n logical
            //also here we are fixing the 1st and 2nd index
            // LL,LR,RL,RR are the 4 posibilities checking here which gives the least 
            //ans also for every index we are trying whether we can put L/R in this position
            v3d dp(n,v2d(2,vi(2,-1)));
            ll cnt1=0,cnt2=0;
            //flipping the coin in the case of 1st and 2nd index
            if(i==0 && s[0]=='R') cnt1++;
            else if(i==1 && s[0]=='L') cnt1++;

            if(j==0 && s[1]=='R') cnt2++;
            else if(j==1 && s[1]=='L') cnt2++;

            res=min(cnt1+cnt2+helper(2,j,i,dp,s,i,j),res);
        }
    }
    // prints(s);
    
    print(res);

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t){
        t--;
        solve();
    }
}