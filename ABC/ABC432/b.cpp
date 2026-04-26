#include <bits/stdc++.h>
using namespace std;

int main(){
    int X;
    cin >> X;
    vector<int> R;
    while (X > 0) {
        R.push_back(X%10);
        X /= 10;
    }
    sort(R.begin(), R.end());
    int ind = 0;
    if (R[0] == 0){
        for (int i = 0; i < R.size(); i++) {
            if (R[i] != 0){
                ind = i;
                break;
            }
        }
        int tmp;
        tmp = R[ind];
        R[ind] = 0;
        R[0] = tmp;
    }
    for (int i = 0; i < R.size(); i++){
        cout << R[i];
    }
    cout << endl;
}