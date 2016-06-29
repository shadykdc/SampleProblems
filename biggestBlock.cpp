#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

const int M = 5;
const int N = 10;

struct Coord{
    int x, y;
    Coord(int _x, int _y){
        x = _x;
        y = _y;
    }
};

int bfs(int board[M][N], int visited[M][N], int x, int y){
    int size = 1;
    queue<Coord> q;
    q.push(Coord(x,y));
    int curr_x, curr_y;
    visited[x][y] = 1;
    
    while (!q.empty()){
        Coord current = q.front();
        
        for (int i = -1; i <= 1; i++){
            for (int j = -1; j <= 1; j++){
                if (current.x+i >= 0 && current.y+j >= 0 && current.x+i < M && current.y+j < N &&
                board[current.x+i][current.y+j] == 1 && visited[current.x+i][current.y+j] == 0){
                    q.push(Coord(current.x+i,current.y+j));
                    visited[current.x+i][current.y+j] = 1;
                    size++;
                }
            }
        }
        
        q.pop();
    }
    
    return size;
}

int find_biggest_size(int board[M][N]){
    int biggest_size = 0;
    int size = 0;
    
    int visited[M][N] = {
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
    };
    
    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            if (board[i][j] == 1 && visited[i][j] == 0){
                size = bfs(board, visited, i, j);
                biggest_size = max(size, biggest_size);
            }
        }
    }
    
    return biggest_size;
}

int main(){
    
    int board[M][N] = { 
        {1,1,0,0,1,0,0,0,0,0},
        {0,1,0,0,0,0,0,0,0,0},
        {0,1,1,1,1,0,0,0,0,0},
        {1,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
    };
    
    int biggest_block_size = find_biggest_size(board);
    
    cout << "The biggest block size is " << biggest_block_size << endl;
    
    return 0;
}
