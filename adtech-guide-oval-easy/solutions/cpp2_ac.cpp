#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N - i; j++) {
            cout << "-";
        }
        for(int j = 0; j < 2 * (N + i); j++) {
            cout << "#";
        }
        for(int j = 0; j < N - i; j++) {
            cout << "-";
        }
        cout << "\n";
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << "#";
        }
        for(int j = 0; j < 2 * N; j++) {
            cout << "-";
        }
        for(int j = 0; j < N; j++) {
            cout << "#";
        }
        cout << "\n";
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < i + 1; j++) {
            cout << "-";
        }
        for(int j = 0; j < 4 * N - 2 * (i + 1); j++) {
            cout << "#";
        }
        for(int j = 0; j < i + 1; j++) {
            cout << "-";
        }
        cout << "\n";
    }

    cout << flush;
    return 0;
}