/* Program to play chess between 2 players. */
#include <iostream>
#include <vector>

using namespace std;

enum {
    PAWNS = 6,
    BISHOP = 1,
    ROOK = 2,
    KNIGHT = 3,
    QUEEN = 4,
    KING = 5,
    INVALID = 0
} PIECES;

// Name of the piece.
struct p {
    int pie;
} piece_t;

// Cordinates in chess board.
struct cordi {
    int x;
    int y;
} cordinates_t;

// Position of the piece to be moved. 
struct posit {
    cordinates_t from;
    cordinates_t to;
} position_t;

struct player {
    string name;
    string color;
    vector <int> pieces_left(16);
} player;

struct loca {
    int color;
    int piece;
} location_t;

class Chess {
    private:
        vector<vector <location_t>> chess_board(9, vector<location_t>(9));
        player player1, player2;
    public:
        board_init(string name1, string color1, string name2, string color2) {
            player1.name = name1;
            player1.color = color1;
            player1.pieces_left.push_back(PAWN);
            player1.pieces_left.push_back(PAWN);
            player1.pieces_left.push_back(PAWN);
            player1.pieces_left.push_back(PAWN);
            player1.pieces_left.push_back(PAWN);
            player1.pieces_left.push_back(PAWN);
            player1.pieces_left.push_back(PAWN);
            player1.pieces_left.push_back(PAWN);
            player1.pieces_left.push_back(BISHOP);
            player1.pieces_left.push_back(BISHOP);
            player1.pieces_left.push_back(ROOK);
            player1.pieces_left.push_back(ROOK);
            player1.pieces_left.push_back(KNIGHT);
            player1.pieces_left.push_back(KNIGHT);
            player1.pieces_left.push_back(KING);
            player1.pieces_left.push_back(QUEEN);

            player2.name = name2;
            player2.color = color2;
            player2.pieces_left.push_back(PAWN);
            player2.pieces_left.push_back(PAWN);
            player2.pieces_left.push_back(PAWN);
            player2.pieces_left.push_back(PAWN);
            player2.pieces_left.push_back(PAWN);
            player2.pieces_left.push_back(PAWN);
            player2.pieces_left.push_back(PAWN);
            player2.pieces_left.push_back(PAWN);
            player2.pieces_left.push_back(BISHOP);
            player2.pieces_left.push_back(BISHOP);
            player2.pieces_left.push_back(ROOK);
            player2.pieces_left.push_back(ROOK);
            player2.pieces_left.push_back(KNIGHT);
            player2.pieces_left.push_back(KNIGHT);
            player2.pieces_left.push_back(KING);
            player2.pieces_left.push_back(QUEEN);

            chess_board
        }
        
        bool isValidMove() {
        
        }

        // The following fuction moves piece between positions.
        void move (piece_t piece, position_t pos) {
            board_remove(pos.from);
            board_add(piece, pos.to);
        }
        
        // Removes the position form the given coordinates.
        void board_remove(cordinates_t corfrom) {
            chess_board[corfrom.x][corfrom.y] = 'x';
        }
        
        // Adds the piece at the given coordinate.
        void board_add(piece_t piece, cordinates_t corto) {
            chess_board[corto.x][corto.y] = piece.a;
        }
        

};

int main() {
    Chess chess;
    string player1, player2;
    cin >> player1;
    cin >> player2;
    chess.board_init(player1, player2);
    return 0;
}

