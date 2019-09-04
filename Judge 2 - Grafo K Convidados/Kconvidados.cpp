#include <iostream>
#include <vector>
using namespace std;

int IsSubgrafo (vector<int> degree, int K, int N){
    int contador = 0;
    for (int i=0; i<N; i++){
        if (degree[i] < K && degree[i] > -1) return 0;
    }
    return 1;
}

vector<int> Remover (vector<vector<int> > vetor, vector<int> degree, int K, int N){
    for (int i=0; i<N; i++){
        if (degree[i] < K && degree[i] > -1){
            for (int j=0; j<vetor[i].size(); j++){
                degree[vetor[i][j]] = degree[vetor[i][j]] - 1;
            }
            degree[i] = -1;
        }
    }
    return degree;
}

void MaximoSubgrafo (vector<vector<int> > vetor, vector<int> degree, int K, int N){
    if (IsSubgrafo(degree, K, N)){
        int contador = 0;
        for (int i=0; i<N; i++){
            if (degree[i] >= K) contador++;
        }
        cout << contador;
    }
    else{
        degree = Remover(vetor, degree, K, N);
        MaximoSubgrafo(vetor, degree, K, N);
    }
}

int main(){
	int N, P, K;
	int a, b;

	cin >> N;
    cin >> P;
    cin >> K;

	vector<vector<int> > convidados(N);
	vector<int> degree;

	for (int i=0; i<N; i++){
        degree.push_back(0);
	}

    for (int i=0; i<P; i++){
        cin >> a;
        cin >> b;

        convidados[a-1].push_back(b-1);
        degree[a-1] = degree[a-1] + 1;

        convidados[b-1].push_back(a-1);
        degree[b-1] = degree[b-1] + 1;
    }

    MaximoSubgrafo(convidados, degree, K, N);

	return 0;
}
