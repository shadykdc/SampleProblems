/*

Given a crossword puzzle (in this case, I've hard-coded it to be an 8x8 matrix)
where each box is either a 1 or 0 (1 = white square, 0 = black square),
determine if it is a valid crossword puzzle or not.

*/

#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

struct Coord{
    int x,y;
    Coord(int _x, int _y){
        x = _x;
        y = _y;
    }
};

void bfs(int input[][8], int visited[][8], const int x, const int y){
    visited[x][y] = 1;
    queue<Coord> q;
    q.push(Coord(x,y));
    Coord current = q.front();
    
    while (!q.empty()){
        current = q.front();
        for (int i = 0; i < 8; i++){
            for (int j = 0; j < 8; j++){
                if (abs(current.x - i) + abs(current.y - j) == 1 && input[i][j] == 1 && visited[i][j] == 0){
                    q.push(Coord(i,j));
                    visited[i][j] = 1;
                }
            }
        }
        q.pop();
    }
    return;
}

bool valid_crossword(int input[][8]){
    bool bfs_done = false;
    int visited[8][8] = {
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
    };

    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if (input[i][j] == 1 && bfs_done == false){
                bfs(input, visited, i, j);
                bfs_done = true;
            }
            else if(input[i][j] == 1 && bfs_done == true && visited[i][j] == 0){
                return false;
            }
        }
    }
    return true;
}

int main(){
    
    int crossword[8][8] = {
        {1, 0, 0, 0, 1, 1, 0, 1},
        {1, 0, 0, 0, 1, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 1, 1, 0, 1},
        {1, 0, 0, 0, 1, 1, 0, 1},
        {1, 0, 0, 0, 1, 1, 1, 1},
        {1, 0, 0, 0, 1, 1, 1, 0},
        {1, 0, 0, 0, 1, 1, 1, 1},
    };
    
    bool valid = valid_crossword(crossword);
    
    if (valid) {
        cout << "It's good!" << endl;
    }
    else {
        cout << ":(" << endl;
    }
    
    return 0;
}

