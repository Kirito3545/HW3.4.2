#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Address {
    string city, street;
    int house, flat;
};

bool cmp(const Address& a, const Address& b) {
    return a.city < b.city;
}

int main() {
    ifstream fin("in.txt");
    ofstream fout("out.txt");

    int n;
    fin >> n;

    vector<Address> addresses(n);
    for (int i = 0; i < n; i++) {
        fin >> addresses[i].city >> addresses[i].street >> addresses[i].house >> addresses[i].flat;
    }

    sort(addresses.begin(), addresses.end(), cmp);

    fout << n << endl;
    for (int i = 0; i < n; i++) {
        fout << addresses[i].city << ", " << addresses[i].street << ", " << addresses[i].house << ", " << addresses[i].flat << endl;
    }

    fin.close();
    fout.close();

    return 0;
}