#include <iostream>
#include <vector>
using namespace std;

vector<int> Dobra (vector<int> vetor, int k){
    vector<int> resposta;
    vector<int> aux1, aux2;

    if (vetor.size() == k || k == 0){
        for (int i=vetor.size()-1; i>=0; i--) resposta.push_back(vetor[i]);
        return resposta;
    }

    for (int i=0; i<k; i++){
        aux1.push_back(vetor[i]);
    }
    for (int i=k; i<vetor.size(); i++){
        aux2.push_back(vetor[i]);
    }

    if (aux1.size() > aux2.size()){
        for (int i=0; i<aux2.size(); i++){
            resposta.push_back(aux2[i] + aux1[aux1.size()-i-1]);
        }
        for (int i=0; i<(aux1.size()-aux2.size()); i++){
            resposta.push_back(aux1[i]);
        }
    }
    else{
        for (int i=0; i<aux1.size(); i++){
            resposta.push_back(aux2[i] + aux1[aux1.size()-i-1]);
        }
        for (int i=aux1.size(); i<aux2.size(); i++){
            resposta.push_back(aux2[i]);
        }
    }

    return resposta;
}

bool Backtracking (vector<int> original, vector<int> resposta){
    vector<int> auxiliar;
    vector<int> invertido;

    if (original.size() == resposta.size()){
        if (original == resposta){
            cout << 'S';
            return true;
        }
        else{
            for (int i=0; i<original.size(); i++){
                if (original[i] == resposta[resposta.size()-1-i])
                    invertido.push_back(original[original.size()-i-1]);
                else return false;
            }
            cout << 'S';
            return true;
        }
    }

    bool flag = false;

    for (int i=1; i<original.size(); i++){
        auxiliar = Dobra(original, i);
        flag = flag || Backtracking(auxiliar, resposta);
        if (flag) break;
    }
    return flag;
}

int main(){
    int N, M;
    int val;
    vector<int> seq_original;
    vector<int> seq;

    cin >> N;

    for (int i=0; i<N; i++){
        cin >> val;
        seq_original.push_back(val);
    }

    cin >> M;

    for (int i=0; i<M; i++){
        cin >> val;
        seq.push_back(val);
    }

    if (!Backtracking(seq_original, seq)) cout << 'N';

    return 0;
}
