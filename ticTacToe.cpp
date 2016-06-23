/*
Devise a representation of an NxN tic-tac-toe game board,
with the variation you only need M tokens in a row to win (in any direction),
such that a win can be verified in O(1) time.  
*/

#include <iostream>
#include <vector>

using namespace std;

int N = 10; // board is nxn squares
int M = 5; // number of consecutive squares for a win

vector<vector<int>> init_board(){
    vector<vector<int>> board;
    vector<int> row;
    
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            row.push_back(0);
        }
        board.push_back(row);
    } 
    return board;
}




bool game_over(vector<vector<int>> board, int x, int y, int player){
    
    int count = 1; // counting moves in a row
    int i = 1;

    /*************** north to south ********************/
    while ((x+i < N && board[x+i][y] == player) || (x-i >= 0 && board[x-i][y] == player)){
        if (x+i < N && board[x+i][y] == player){
            count += 1;
        }
        if (x-i >= 0 && board[x-i][y] == player){
            count += 1;
        }
        i++;
    }
    if (count >= M){
        return true;
    }
    else {
        count, i = 1;
    }
    
    /************** east to west ****************/
    while ((y+i < N && board[x][y+i] == player) || (y-i >= 0 && board[x][y-i] == player)){
        
        if (y+i < N && board[x][y+i] == player){
            count += 1;
        }
        if (y-i >= 0 && board[x][y-i] == player){
            count += 1;
        }
        i++;
    }
    if (count >= M){
        return true;
    }
    else {
        count, i = 1;
    }
    
    /************ diagonal sw - ne ****************/
    while ((y+i < N && x+i < N && board[x+i][y+i] == player) || (y-i >= 0 && x-i >= 0 && board[x-i][y-i] == player)){
        if (y+i < N && x+i < N && board[x+i][y+i] == player){
            count += 1;
        }
        if (y-i >= 0 && x-i >= 0 && board[x-i][y-i] == player){
            count += 1;
        }
        i++;
    }
    if (count >= M){
        return true;
    }
    else {
        count, i = 1;
    }
    
    /****************** diagonal nw - se ***************/
    while ((y-i >= 0 && x+i < N && board[x+i][y-i] == player) || (y+i < N && x-i >= 0 && board[x-i][y+i] == player)){
        if (y-i >= 0 && x+i < N && board[x+i][y-i] == player){
            count += 1;
        }
        if (y+i < N && x-i >= 0 && board[x-i][y+i] == player){
            count += 1;
        }
        i++;
    }
    if (count >= M){
        return true;
    }
    else {
        count, i = 1;
    }
    
    /**** must not be game over */
    return false;
}




int main(){
    
    vector<vector<int>> board = init_board();

    board[5][0] = 1; // Player 1 = 1's
    board[1][0] = 2; // Player 2 = 2's
    board[2][0] = 1;
    board[1][2] = 2;
    board[3][0] = 1;
    board[4][4] = 2;
    board[4][0] = 1;
    board[8][8] = 2;
    board[6][0] = 1;
    
    // function takes in the board, the last move that occured, and the player who made the move
    bool over = game_over(board, 6, 0, 1);
    
    if (over){
        cout << "game over" << endl;
    }
    else {
        cout << "game is not over yet" << endl;
    }
    
    return 0;
}
