#include <iostream>

using namespace std;

int main() {
    int t;
    int A, B, C;
    cin >> t;
    while (t--) {
        cin >> A >> B >> C;
        int rest = 0;
        for (int i = 0; i < B && rest != C; i++) {
            rest = (rest + A) % B;
        }
        if (rest == C) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}