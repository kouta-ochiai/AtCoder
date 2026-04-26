#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    set<int> st;
    while(N--){
        int a;
        cin >> a;
        st.insert(a);
    }
    cout << st.size() << '\n';
   
}

