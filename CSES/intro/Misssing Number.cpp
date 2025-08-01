#include <iostream>
#include <set>
#include <utility>
#include <unordered_set>
#include <vector>
#include <algorithm>

#define ll long long
using namespace std;

int main() {
    ll n; cin >> n;
    ll sum = n * (n + 1)/2;
    for (ll i = 0; i < n - 1; i++) {
        ll ni; cin >> ni;
        sum-=ni;
    }

    cout << sum << endl;
    return 0;
}


