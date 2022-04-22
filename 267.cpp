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
    int n, x, y;
    fin >> n >> x >> y;
    int answer = 0;
    if (x > y){
        swap(x, y);
    }
    answer += x;
    n--;
    int l = 0;
    int r = y * n;
    while (l != r){
        int s = (l + r) / 2;
        if (s / x + s / y < n){
            l = s + 1;
        }else{
            r = s;
        }
    }
    answer += l;
    fout << answer;
    return 0;
}