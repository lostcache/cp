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
#define FOR(i, a, b) for(ll i=(a); i<(b); ++i)
#define FORD(i, a, b) for(ll i=(a); i>(b); --i)
#define pll pair<long long, long long>
#define plll pair<long long, pll>

const ll MOD = 1000000007;

using namespace std;


int main() {
    string input; 
    cin >> input;

    int frequency[26] = {};
    for (char character : input) {
        frequency[character - 'A']++;
    }

    int oddCount = 0;
    int oddCharacterIndex = -1;
    for (int i = 0; i < 26; ++i) {
        if (frequency[i] % 2 != 0) {
            oddCount++;
            oddCharacterIndex = i;
        }
    }

    if ((input.size() % 2 == 0 && oddCount > 0) || 
        (input.size() % 2 == 1 && oddCount != 1)) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    string firstHalf, secondHalf;

    for (int i = 0; i < 26; ++i) {
        for (int count = 0; count < frequency[i] / 2; ++count) {
            firstHalf += char(i + 'A');
        }
    }

    string middle = "";
    if (oddCharacterIndex != -1) {
        middle += char(oddCharacterIndex + 'A');
    }

    secondHalf = firstHalf;
    reverse(secondHalf.begin(), secondHalf.end());

    cout << firstHalf + middle + secondHalf << endl;

    return 0;
}

