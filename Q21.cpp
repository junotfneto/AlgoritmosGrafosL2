using namespace std;

#include<stdio.h>
#include<vector>
#include <algorithm>

int main(){
	int capacidade;
	vector<int> arquivos;
	int arquivosUsados = 0;
	printf("Digite a capacidade do pendrive\n");
	scanf("%d\n", &capacidade);
	printf("Digite os tamanhos dos arquivos. Digite 0 para encerrar\n");
	int leitura;
	scanf("%d", &leitura);
	while(leitura > 0){
		arquivos.push_back(leitura);
		scanf("%d", &leitura);
	}
	sort(arquivos.begin(), arquivos.end());
	for(int i = 0; i < arquivos.size(); i++){
		if(capacidade >= arquivos[i]){
			arquivosUsados++;
			capacidade -= arquivos[i];
		}
	}
	printf("Arquivos salvos no pendrive: %d\n", arquivosUsados);
}