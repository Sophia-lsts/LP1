#include <stdio.h>

int main(){

    int num;
    typedef enum {KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN} chess_pieces;

    int piece_value[6] = {
    [KING] = 200,
    [QUEEN] = 9,
    [ROOK] = 5,
    [BISHOP] = 3,
    [KNIGHT] = 3,
    [PAWN] = 1} ;

    chess_pieces piece = KING;

    switch(piece) {
        case KING:
            printf("O valor da peça KING é %d", piece_value[KING]);
            break;
        case QUEEN:
            printf("O valor da peça QUEEN é %d", piece_value[QUEEN]);
            break;
        case ROOK:
            printf("O valor da peça ROOK é %d", piece_value[ROOK]);
            break;
        case KNIGHT:
            printf("O valor da peça KNIGHT é %d", piece_value[KNIGHT]);
            break;
        case PAWN:
            printf("O valor da peça PAWN é %d", piece_value[PAWN]);
            break;
    };

    return 0;
};