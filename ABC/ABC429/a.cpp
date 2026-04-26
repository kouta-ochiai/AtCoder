#include <bits/stdc++.h>

int main(void){
    int N, M;
    std::cin >> N >> M;
    M--;
    for (int i = 0 ; i < N; i++){
        if (i <= M){
            std::cout << "OK" << std::endl;
        } else {
            std::cout << "Too Many Requests" << std::endl; 
        }
    }
}
