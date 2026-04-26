#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> A(N);
    for(int &a: A) cin >> a;

    vector<int> st;
    st.reserve(N);

    for(int i = 0; i < N; i++){
        while(!st.empty() && A[st.back()]<=A[i]) st.pop_back();
        cout << (st.empty() ? -1 : st.back() + 1) << '\n';
        st.push_back(i);
    }
    return 0;
}

