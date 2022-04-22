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
    vector <vector <int>> matrix;
    vector <vector <int>> matrix2;
    vector <vector <char>> answer;
    for (int i = 0; i < n; i++){
        vector <int> prov(n);
        vector <int> prov3(n);
        vector <char> prov2(n);
        for (int j = 0; j < n; j++){
            fin >> prov[j];
            prov3[j] = prov[j];
            prov2[j] = '.';
        }
        matrix.push_back(prov);
        matrix2.push_back(prov3);
        answer.push_back(prov2);
    }
    answer[n - 1][n - 1] = '#';
    answer[0][0] = '#';
    for (int i = 1; i < n; i++){
        matrix[i][0] += matrix[i - 1][0];
    }
    for (int i = 1; i < n; i++){
        matrix[0][i] += matrix[0][i - 1];
    }
    for (int i = 1; i < n; i++){
        for (int j = 1; j < n; j++){
            if (matrix[i - 1][j] < matrix[i][j - 1]){
                matrix[i][j] += matrix[i - 1][j];
            }else{
                matrix[i][j] += matrix[i][j - 1];
            }
        }
    }
    int i = n - 1;
    int j = n - 1;
    while (i != 0 && j != 0){
        if (matrix[i][j] == matrix[i - 1][j] + matrix2[i][j]){
            answer[i - 1][j] = '#';
            i--;
        }
        if (matrix[i][j] == matrix[i][j - 1] + matrix2[i][j]){
            answer[i][j - 1] = '#';
            j--;
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            fout << answer[i][j] << " ";
        }
        fout << endl;
    }
    return 0;
}