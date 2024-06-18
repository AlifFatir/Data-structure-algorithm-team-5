#include <iostream>
#include <vector>
using namespace std;

vector<int> a;
int maxVal, minVal;

void maxmin(int i, int j) {
    int max1, min1, mid;
    if (i == j) {
        maxVal = minVal = a[i];
    } else if (i == j - 1) {
        if (a[i] > a[j]) {
            maxVal = a[i];
            minVal = a[j];
        } else {
            maxVal = a[j];
            minVal = a[i];
        }
    } else {
        mid = (i + j) / 2;
        maxmin(i, mid);
        max1 = maxVal;
        min1 = minVal;
        maxmin(mid + 1, j);
        if (maxVal < max1) maxVal = max1;
        if (minVal > min1) minVal = min1;
    }
}

int main() {
    int num;
    cout << "\n\t\t\tMaxmin Dengan Minimum\n";
    cout << "Masukkan Banyak Angka : ";
    cin >> num;

    a.resize(num);
    cout << "\nMasukkan Angka-angkanya : ";
    for (int i = 0; i < num; i++) {
        cin >> a[i];
    }

    maxVal = a[0];
    minVal = a[0];
    maxmin(0, num - 1);
    cout << "Maximum Angka : " << maxVal << endl;
    cout << "Minimum Angka : " << minVal << endl;

    return 0;
}
