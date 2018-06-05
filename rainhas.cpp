#define N 9
#include<stdio.h>
int tabuleiro[N][N];

bool seguro(int tabuleiro[N][N], int x, int y){
    //OLHANDO PARA TODO ELEMENTO (i,y), com i < x
    for(int i = 0; i < x; i++){
        if(tabuleiro[i][y]) return false;
    }
    //OLHANDO PARA TODO ELEMENTO (i,y), com i > x
    for(int i = x+1; i < N; i++){
        if(tabuleiro[i][y]) return false;
    }
    //OLHANDO PARA TODO ELEMENTO (x,i), com i < y
    for(int i = 0; i < y; i++){
        if(tabuleiro[x][i]) return false;
    }
    //OLHANDO PARA TODO ELEMENTO (x,i), com i > y
    for(int i = y+1; i < N; i++){
        if(tabuleiro[x][i]) return false;
    }
    //OLHANDO DIAGONAIS
    for(int i = 1; (i+x < N)&&(i+y < N); i++){
        if(tabuleiro[x+i][y+i]) return false;
    }
    for(int i = -1; (i+x >= 0)&&(i+y >= 0); i--){
        if(tabuleiro[x+i][y+i]) return false;
    }
    for(int i = 1, j = -1; (i+x < N)&&(j+y >= 0); i++, j--){
        if(tabuleiro[x+i][y+j]) return false;
    }
    for(int i = 1, j = -1; (j+x >= 0)&&(i+y < N); i++, j--){
        if(tabuleiro[x+j][y+i]) return false;
    }
    return true;
}

bool rainhas(int tabuleiro[N][N], int nRainhas){
    if(nRainhas == N){
        return true;
    }
    for(int i = 0; i < N; i++){
        if(seguro(tabuleiro, i, nRainhas)){
            tabuleiro[i][nRainhas] = 1;
            if(!rainhas(tabuleiro, nRainhas+1)){
                tabuleiro[i][nRainhas] = 0;
            }else{
                return true;
            }
        }
    }
    return false;
}

int main(){
    rainhas(tabuleiro, 0);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

}
