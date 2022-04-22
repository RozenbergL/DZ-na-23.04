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
    vector <int> seq(n);
    for (int i = 0; i < n; i++){
        fin >> seq[i];
    }
    int answer = 0;
    int maxi = 0;
    for (int i = 0; i < n - 1; i++){
        if (seq[i] < seq[i + 1]){
            maxi++;
        }else{
            maxi++;
            if (maxi > answer){
                answer = maxi;
                maxi = 0;
            }
        }
    }
    fout << answer;
    return 0;
}