#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin >> n;
    vector<pair<int, int>> vp;
    for(int i = 1; i<= n; i++){
        int a;
        cin >> a;
        vp.push_back({a, i});
    }
    sort(vp.begin(), vp.end());
    vector<int>p(n+1), q(n+1);
    set<int> avail_p, avail_q;
    for(int i = 1; i<= n; i++){
        avail_q.insert(i);
        avail_p.insert(i);
    }
    for(const auto &[a, b]:vp){
        if(avail_p.count(a)) {
            p[b] = a;
            avail_p.erase(a);
            if(*avail_q.begin() <= a) {
                q[b] = *avail_q.begin();
                avail_q.erase(avail_q.begin());
            } else {
                cout << "NO\n";
                return;
            }
        } else if(avail_q.count(a)) {
            q[b] = a;
            avail_q.erase(a);
            if(*avail_p.begin() <= a) {
                p[b] = *avail_p.begin();
                avail_p.erase(avail_p.begin());
            } else {
                cout << "NO\n";
                return;
            }
        } else {
            cout << "NO\n";
            return;
        }

    }
    assert(avail_p.empty() and avail_q.empty());

    cout << "YES\n";
    for(int i = 1; i <= n; i++) cout << p[i] << " "; cout << "\n";
    for(int i = 1; i <= n; i++) cout << q[i] << " "; cout << "\n";
    
}
signed main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int tt;
    cin >> tt;
    while(tt--){
    solve();
    }

    
}