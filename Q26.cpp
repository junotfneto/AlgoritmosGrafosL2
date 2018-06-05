#define N 9
#include<stdio.h>
int tabuleiro[N][N];

int getQuadrado(int x){
    if(x < 3) return 0;
    if(x < 6) return 3;
    return 6;
}

bool seguro(int tabuleiro[N][N], int x, int y){
    //OLHANDO PARA TODO ELEMENTO (i,y), com i < x
    for(int i = 0; i < x; i++){
        if(tabuleiro[i][y] == tabuleiro[x][y]) return false;
    }
    //OLHANDO PARA TODO ELEMENTO (i,y), com i > x
    for(int i = x+1; i < N; i++){
        if(tabuleiro[i][y] == tabuleiro[x][y]) return false;
    }
    //OLHANDO PARA TODO ELEMENTO (x,i), com i < y
    for(int i = 0; i < y; i++){
        if(tabuleiro[x][i] == tabuleiro[x][y]) return false;
    }
    //OLHANDO PARA TODO ELEMENTO (x,i), com i > y
    for(int i = y+1; i < N; i++){
        if(tabuleiro[x][i] == tabuleiro[x][y]) return false;
    }
    //OLHANDO QUADRADO
    int quadX = getQuadrado(x);
    int quadY = getQuadrado(y);
    for(int i = quadX; i < quadX+3; i++){
        for(int j = quadY; j < quadY+3; j++){
            if((i == x)&&(j == y)) continue;
            if(tabuleiro[i][j] == tabuleiro[x][y]) return false;
        }
    }
    return true;
}

bool sudoku(int tabuleiro[N][N], int x, int y){
    if(x == N){
        return true;
    }
    for(int i = 1; i <= 9; i++){
        tabuleiro[x][y] = i;
        if(seguro(tabuleiro, x, y)){
            int x2 = x;
            int y2 = y+1;
            if(y2 == N){
                x2++;
                y2 = 0;
            }
            if(sudoku(tabuleiro, x2, y2)){
                return true;
            }

        }else{
            tabuleiro[x][y] = 0;
        }
    }
    return false;
}

int main(){
    sudoku(tabuleiro, 0, 0);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

}
