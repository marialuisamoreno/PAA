#include <iostream>
#include <vector>
#define INF 1000000000

using namespace std;
long long int contador = 0;

void MergeSort(vector<int> &v){
	if(v.size()==1) return;

	vector<int> u1, u2;

	for(int i=0; i<v.size()/2; i++) u1.push_back(v[i]);
	for(int i=v.size()/2; i<v.size(); i++) u2.push_back(v[i]);

	MergeSort(u1);
	MergeSort(u2);

	u1.push_back(INF);
	u2.push_back(INF);

	int ini1=0, ini2=0;

	for(int i=0; i<v.size(); i++){
		if(u1[ini1] < u2[ini2]){
			v[i] = u1[ini1];
			ini1++;
		}

		else{
            contador += v.size()/2 -ini1;
			v[i] = u2[ini2];
			ini2++;
		}
	}
	return;
}

int main(){
    int i, aux, tamanho;
    cin >> tamanho;

    vector<int> vetor;

    for (i=0; i<tamanho; i++){
        cin >> aux;
        vetor.push_back(aux);
    }

    MergeSort(vetor);

    cout << contador;

    return 0;
}
