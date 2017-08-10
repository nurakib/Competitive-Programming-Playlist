#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100005
ll n, k, stall[MAX];
bool chk(ll val){
    ll cnt = 1, tmp = stall[0];
    for(int i = 1; i < n; i++){
        if(stall[i] - tmp >= val){
            tmp = stall[i];
            cnt++;
            if(cnt >= k) return true;
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 0; i < n; i++) cin >> stall[i];
        sort(stall, stall + n);
        ll low = stall[0], high = stall[n - 1] + 5, mid;
        while(high - low > 1){
            mid = (low + high) / 2;
            if(chk(mid)) low = mid;
            else high = mid;
        }
        cout << (high + low) / 2 << "\n";
    }
    return 0;
}
