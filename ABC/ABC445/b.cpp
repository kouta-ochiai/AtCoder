#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N;
    cin >> N;
    vector<string> S(N);
    int m = 0;
    for (int i = 0; i < N; i++){
        cin >> S.at(i);
        int tmp = int(S.at(i).length());
        m = max(m, tmp);
    }

    for (int i = 0; i < N; i++){
        int tmp = (m- int(S.at(i).length()))/2;
        string dot = "";
        for (int j = 0; j < tmp; j++){
            dot += ".";
        }
        cout << dot << S.at(i) << dot << endl;
    }

}
