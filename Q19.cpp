#include<stdio.h>

int main(){
	printf("Digite o valor em dinheiro usando virgula pra separar as casas decimais\n");
	int reais,centavos;
	scanf("%d,%d",&reais, &centavos);

	int moedas[6] = {1, 50, 25, 10, 5, 1};
	int moedasUsadas[6] = {0,0,0,0,0,0};
	moedasUsadas[0] = reais; //Moedas de 1 real
	for(int i = 1; i < 6; i++){
		moedasUsadas[i] = centavos/moedas[i];
		centavos = centavos%moedas[i];
	}

	printf("Moedas do troco:\n");
	for(int i = 0; i < 6; i++){
		printf("%d moedas de %d\n", moedasUsadas[i], moedas[i]);
	}

}