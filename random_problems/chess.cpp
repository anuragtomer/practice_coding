/* Program to play chess between 2 players. */
#include <iostream>
#include <vector>

using namespace std;


// Name of the piece.
typedef struct {
    int pie;
} piece_t;

// Cordinates in chess board.
typedef struct{
    int x;
    int y;
} cordinates_t;

// Position of the piece to be moved. 
typedef struct {
    cordinates_t from;
    cordinates_t to;
} position_t;

typedef struct {
    string name;
    string color;
    vector <int> pieces_left;
} player;

typedef struct {
    int color;
    int piece;
} location_t;

class Chess {
    public:
        vector<vector <int>> chess_board(9, vector<int>(9));
        player player1, player2;
enum {
    PAWNS = 6,
    BISHOP = 1,
    ROOK = 2,
    KNIGHT = 3,
    QUEEN = 4,
    KING = 5,
    INVALID = 0
} PIECES;
        Chess(string name1, string color1, string name2, string color2) {
            player1.name = name1;
            player1.color = color1;
            player1.pieces_left.push_back(PIECES.PAWN);
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
            // Add basic checks and only then remove.
            chess_board[corfrom.x][corfrom.y] = NULL;
        }
        
        // Adds the piece at the given coordinate.
        void board_add(piece_t piece, cordinates_t corto) {
            // See that there is nothing already present on this location. If so, then first remove and then place the new piece.
            chess_board[corto.x][corto.y] = piece.a;
        }
        

};

int main() {
    string player1, player2, color1, color2;
    cin >> player1;
    cin >> color1;
    cin >> player2;
    cin >> color2;
    Chess c(player1, player2, color1, color2);
    return 0;
}

