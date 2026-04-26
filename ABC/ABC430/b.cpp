#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<char>> S(N, vector<char>(N));
    for (int i = 0; i < N; i++) for(int j = 0; j < N; j++) cin >> S[i][j];
    vector<vector<char>> T(M, vector<char>(M));
    set<string> unique_patterns;
    for (int i = 0; i <= N - M; i++) {
        for (int j = 0; j <= N - M; j++) {
            string pattern = "";
            for (int x = 0; x < M; x++) {
                for (int y = 0; y < M; y++) {
                    pattern += S[i + x][j + y];
                }
            }
            unique_patterns.insert(pattern);
        }
}

cout << unique_patterns.size() << endl;

}