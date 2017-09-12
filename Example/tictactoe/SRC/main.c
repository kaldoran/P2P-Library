#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "error.h"
#include "boolean.h"

#define PAWN_J1 'X'
#define PAWN_J2 'O'
#define EMPTY_PAWN '-'
#define BOARD_WIDTH 3
#define BOARD_SIZE BOARD_WIDTH * BOARD_WIDTH
#define PLACE(X, Y) (X * BOARD_WIDTH) + Y

#define SWITCH_PLAYER(X) (X == PAWN_J1) ? PAWN_J2 : PAWN_J1;

void print_board(const char *board) {
    int i = 0;

    printf("    A  B  C\n");
    while(i < BOARD_SIZE) {
        if ( i % BOARD_WIDTH == 0 )   printf(" %d ", (i / BOARD_WIDTH) + 1);
        printf(" %c ", board[i]);
        if ( ++i % BOARD_WIDTH == 0 ) printf("\n");
    }
}

bool check_board(const char *old_board, const char *new_board) {
    int i = 0;
    char tmp_board[10];
    strcpy(tmp_board, new_board);

    for ( i = 0; i < BOARD_SIZE && old_board[i] == new_board[i]; i++ ) ; 
   
    if ( i == BOARD_SIZE) 
        return FALSE;

    tmp_board[i] = EMPTY_PAWN;
    return strcmp(old_board, tmp_board) == 0;

}

char check_win(const char *board) {
  
    if ( board[0] != EMPTY_PAWN ) {
        if ( board[0] == board[1] && board[1] == board[2] ) return board[0]; // '-' Horiz 1
        if ( board[0] == board[3] && board[3] == board[6] ) return board[0]; // '|' Verti 1
    }

    if ( board[4] != EMPTY_PAWN ) { 
        if ( board[0] == board[4] && board[4] == board[8] ) return board[0]; // '\' Diag
        if ( board[2] == board[4] && board[4] == board[6] ) return board[2]; // '/' Diag

        if ( board[1] == board[4] && board[4] == board[7] ) return board[1]; // '|' Verti 2 
        if ( board[3] == board[4] && board[4] == board[5] ) return board[3]; // '-' Horiz 2
    }

    if ( board[8] != EMPTY_PAWN ) {
        if ( board[6] == board[7] && board[7] == board[8] ) return board[6]; // '-' Horiz 3 
        if ( board[2] == board[5] && board[5] == board[8] ) return board[2]; // '|' Verti 3 
    }
    
    return EMPTY_PAWN;
}

int ask_move() {
    int val = 0;
    int good = 0;
    char c = EMPTY_PAWN;

    while ( good < 2 && (c = getc(stdin)) ) {
        if ( isalpha(c) && c - 'A' < 3 ) { 
            val += (c - 'A');
            ++good;
        }

        if ( isdigit(c) && c - '1' < 3) { 
            val += ((c - '1') * BOARD_WIDTH);
            ++good;
        }
    }

    return val;
}

int main(int argc, char *argv[]) {
    (void) argc;
    (void) argv;

    int move = 0;
    char player = PAWN_J1;
    char board[BOARD_SIZE + 1] = "---------";
    char next_board[BOARD_SIZE + 1] = "---------";

    while ( check_win(board) == EMPTY_PAWN ) {
        print_board(board);
        if ( player == PAWN_J1 ) {
            do {
                move = ask_move();
            } while ( board[move] != EMPTY_PAWN );
            
            board[move] = PAWN_J1; 
            // send 
        } else {
            ; // Recv - Check_board
        }

        player = SWITCH_PLAYER(player);
        getc(stdin);
    }
    exit(EXIT_SUCCESS);
}
