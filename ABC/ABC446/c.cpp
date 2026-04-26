#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll T;
    cin >> T;
    while (T--)
    {
        ll N, D;
        cin >> N >> D;
        vector<ll> A(N+1), B(N+1);
        for (int i = 1; i <= N; i++) cin >> A[i];
        for (int i = 1; i <= N; i++) cin >> B[i];

        //  (expir, count)
        deque<pair<ll, ll>> q;
        ll total = 0;
        for (int day = 1; day <= N; day++){
            // 仕入れ
            q.push_back({day + D, A[day]});
            total += A[day];

            // 使用
            ll need = B[day];
            while(need > 0){
                auto &f = q.front();
                ll take = min(f.second, need);
                f.second -= take;
                need -= take;
                total -= take;
                if (f.second == 0) q.pop_front();
            }

            // 処分
            while(!q.empty() && q.front().first <= day){
                total -= q.front().second;
                q.pop_front();
            }

        }
        cout << total << '\n';
    }
    
   
}

