#include <bits/stdc++.h>
using namespace std;

int main(void){
    double X, Y, Z;
    cin >> X >> Y >> Z;
    double k;
    k = (X-Z*Y)/(Z-1);
    if (floor(k)==k && (X-Z*Y)>=0){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

}