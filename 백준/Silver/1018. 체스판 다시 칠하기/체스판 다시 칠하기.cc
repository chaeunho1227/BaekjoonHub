#include <iostream>

namespace ChessBoard {
using namespace std;
string WB[8] = {
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW"
};

string BW[8] = {
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB"
};

char** board = nullptr;

//null로 들어오기에 참조자를 사용
void init_board(char**& board,int Row, int Col){
    board = new char*[Row];
    for (int i = 0; i < Row; i++) {
        board[i] = new char[Col];
    }
}

void read_board(char** board,int Row,int Col){
    for (int i = 0; i < Row; i++) {
        for (int j = 0; j < Col; j++) {
            cin >> board[i][j];
        }
    }
}

void del_board(char** board,int Row,int Col){
    for (int i = 0; i < Row; i++) {
        delete[] board[i];
    }
    delete[] board;
}

int count_change_case(char** board,int row_start,int col_start){
    int WB_cnt = 0,BW_cnt = 0;
    //WB
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            if (board[row_start+i][col_start+j] != WB[i][j])
                WB_cnt++;
    
    //BW
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            if (board[row_start+i][col_start+j] != BW[i][j])
                BW_cnt++;
    
    return (BW_cnt < WB_cnt)? BW_cnt : WB_cnt;
}
}

int main(){
    using namespace ChessBoard;
    int M,N,min,tmp;
    cin >> M >> N;
    min = M*N;
    init_board(board, M, N);
    read_board(board, M, N);
    for (int i = 0; i < M - 7; i++) {
        for (int j = 0; j < N - 7; j++) {
            tmp = count_change_case(board, i, j);
            if(min > tmp)
                min = tmp;
        }
    }
    cout << min;
    del_board(board, M, N);
    return 0;
}
