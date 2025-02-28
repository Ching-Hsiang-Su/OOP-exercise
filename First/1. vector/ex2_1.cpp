#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int a[n];  // Create an array of size n

    for (int i = 0; i < n; i++) {
        cin >> a[i];  // Initialize the array with user input
    }

    for (int i = 0; i < k; i++) {
        string c;
        int m;
        cin >> c >> m;

        if (c == "sum") {  // sum request
            int sum = 0;
            for (int j = 0; j < m; j++) {
                sum += a[j];
            }
            cout << sum << endl;

        } else if (c == "del") {  // del request
            for (int j = m-1; j < n-1; j++) {
                a[j] = a[j+1];
            }
            n--; 

        } else if (c == "pap") {  // pap request
            int temp[n+1];
            for (int j = 0; j < m; j++) {
                temp[j] = a[j];
            }
            temp[m] = 2 * m;
            for (int j = m+1; j < n+1; j++) {
                temp[j] = a[j-1];
            }
            n++; 
            for (int j = 0; j < n; j++) {
                a[j] = temp[j];
            }
        }
    }

    return 0;
}
