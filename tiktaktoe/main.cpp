#include <iostream>
#include <vector>
#include <limits>
using namespace std;

const char HUMAN = 'X';
const char AI = 'O';
const char EMPTY = ' ';

void printBoard(const vector<char>& board) {
    cout << "\n";
    for (int i = 0; i < 9; ++i) {
        cout << (board[i] == EMPTY ? to_string(i+1) : string(1, board[i])) << " ";
        if ((i + 1) % 3 == 0) cout << "\n";
    }
    cout << "\n";
}

bool isMovesLeft(const vector<char>& board) {
    for (char c : board)
        if (c == EMPTY) return true;
    return false;
}

int evaluate(const vector<char>& b) {
    const int wins[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
        {0, 4, 8}, {2, 4, 6}
    };

    for (auto& line : wins) {
        if (b[line[0]] == b[line[1]] && b[line[1]] == b[line[2]]) {
            if (b[line[0]] == AI) return +10;
            else if (b[line[0]] == HUMAN) return -10;
        }
    }
    return 0;
}

int minimax(vector<char>& board, bool isMax) {
    int score = evaluate(board);
    if (score == 10 || score == -10) return score;
    if (!isMovesLeft(board)) return 0;

    if (isMax) {
        int best = numeric_limits<int>::min();
        for (int i = 0; i < 9; ++i) {
            if (board[i] == EMPTY) {
                board[i] = AI;
                best = max(best, minimax(board, false));
                board[i] = EMPTY;
            }
        }
        return best;
    } else {
        int best = numeric_limits<int>::max();
        for (int i = 0; i < 9; ++i) {
            if (board[i] == EMPTY) {
                board[i] = HUMAN;
                best = min(best, minimax(board, true));
                board[i] = EMPTY;
            }
        }
        return best;
    }
}

int findBestMove(vector<char>& board) {
    int bestVal = numeric_limits<int>::min();
    int bestMove = -1;
    for (int i = 0; i < 9; ++i) {
        if (board[i] == EMPTY) {
            board[i] = AI;
            int moveVal = minimax(board, false);
            board[i] = EMPTY;
            if (moveVal > bestVal) {
                bestMove = i;
                bestVal = moveVal;
            }
        }
    }
    return bestMove;
}

bool isGameOver(const vector<char>& board) {
    return evaluate(board) != 0 || !isMovesLeft(board);
}

int main() {
    vector<char> board(9, EMPTY);
    cout << "Tic-Tac-Toe\nYou are 'X', AI is 'O'\n";
    printBoard(board);

    while (!isGameOver(board)) {
        int move;
        cout << "Enter your move (1-9): ";
        cin >> move;
        --move;

        if (move < 0 || move > 8 || board[move] != EMPTY) {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        board[move] = HUMAN;
        printBoard(board);

        if (isGameOver(board)) break;

        int aiMove = findBestMove(board);
        board[aiMove] = AI;
        cout << "AI played at position " << aiMove + 1 << ":\n";
        printBoard(board);
    }

    int result = evaluate(board);
    if (result == 10) cout << "AI wins!\n";
    else if (result == -10) cout << "You win!\n";
    else cout << "It's a draw!\n";

    return 0;
}
