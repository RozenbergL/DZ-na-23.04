#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
	ifstream fin;
	ofstream fout;
	fin.open("input.txt");
	fout.open("output.txt");
    int n;
    fin >> n;
    vector <int> sp(n);
    for (int i = 0; i < n; i++){
        fin >> sp[i];
    }
    sort(sp.begin(), sp.end());
    long long x, y;
    x = sp[n - 1] * sp[n - 2] * sp[n - 3];
    y = sp[0] * sp[1] * sp[n - 1];
    fout << max(x, y);
    return 0;
}