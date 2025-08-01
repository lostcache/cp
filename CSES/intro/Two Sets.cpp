#include <iostream>
#include <set>
#include <utility>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <cmath>

#define ll long long
#define vi vector<int>
#define vl vector<long long>
#define pb push_back
using namespace std;

int main() {
    long long n; cin >> n;
    long long sum = n * (n + 1) / 2;
    if (sum % 2 != 0) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    long long target = sum / 2;
    vector<int> set1, set2;

    for (long long i = n; i >= 1; --i) {
        if (i <= target) {
            set1.pb(i);
            target -= i;
        } else {
            set2.pb(i);
        }
    }

    cout << set1.size() << "\n";
    for (int x : set1) cout << x << " ";
    cout << "\n";

    cout << set2.size() << "\n";
    for (int x : set2) cout << x << " ";
    cout << "\n";

    return 0;
}

