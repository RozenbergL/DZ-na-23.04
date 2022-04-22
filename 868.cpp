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
    int n, k;
    fin >> n >> k;
    vector <vector <int>> matrix;
    for (int i = 0; i < n; i++){
        vector <int> prov(k);
        for (int j = 0; j < k; j++){
            fin >> prov[j];
        }
        matrix.push_back(prov);
    }
    int maxi = 0;
    int ind1 = -1;
    int ind2 = -1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < k; j++){
            if (matrix[i][j] > maxi){
                maxi = matrix[i][j];
                ind1 = i;
                ind2 = j;
            }
        }
    }
    int ans1 = -1;
    int ans2 = -1;
    long long mini = 100000000000000;
    for (int i = 0; i < k; i++){
        if (matrix[ind1][i] < mini){
            mini = matrix[ind1][i];
            ans1 = i;
        }
    }
    mini = 10000000000000000;
    for (int i = 0; i < n; i++){
        if (matrix[i][ind2] < mini){
            mini = matrix[i][ind2];
            ans2 = i;
        }
    }
    fout << matrix[ans2][ans1];
    return 0;
}