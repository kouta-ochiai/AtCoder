#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    set<int> A;
    for (int i = 0; i < N; i++) {int tmp; cin >> tmp; A.insert(tmp);}
    int sum;
    sum = N - A.size();
    cout << sum << endl;
    for (int i = 1; i <= N; i++) {
        if (A.count(i)){continue;}
        cout << i << " ";
    }
    cout << endl;
}