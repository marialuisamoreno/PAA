#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int main(){
    string A;
    string B;

    getline(cin, A);
    getline(cin, B);

    int m = A.length()+1;
    int n = B.length()+1;
    int M[m][n];
    int C;
/*
    cout << m << '\n';
    cout << n << '\n';
*/
    for (int i=0; i<m; i++){
        M[i][0] = i;
	}
	for (int i=0; i<n; i++){
        M[0][i] = i;
	}
	for (int i=1; i<m; i++){
        for (int j=1; j<n; j++){
            if (A[i-1] == B[j-1]){
                C = 0;
            }
            else{
                C = 1;
            }
            int aux = min(M[i-1][j-1]+C, M[i-1][j]+1);
            M[i][j] = min(aux, M[i][j-1]+1);

            //cout << A[i-1] << ' ';
            //cout << B[j-1] << '\n';

            if (i == m-1 && j == n-1) cout <<M[i][j];
        }
	}
/*
	for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            cout << M[i][j] << " ";
        }
        cout << "\n";
	}
*/
    return 0;
}
