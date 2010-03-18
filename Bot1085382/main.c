#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Reads the board from stdin
void read_board(char *board, char *row, int w, int h);
// Prints the move (LEFT, RIGHT, UP, DOWN) to stdout
void do_move(char *board, int player, int timeleft, int w, int h);
// Finds our and opponents locations
void find_locations(char *board, int player,
                    int *our_x, int *our_y, int *opp_x, int *opp_y,
                    int w, int h);

int main()
{
    char *row;
    char *board;
    int player;
    int w, h, size;
    int timeleft;

    // init
    scanf("%i %i %i %i\n", &w, &h, &player, &timeleft);
    size = w * h;
    board = malloc(w * h);
    row = malloc(w + 1);

    // main loop
    do {
        read_board(board, row, w, h);
        do_move(board, player, timeleft, w, h);

        scanf("%i %i %i %i\n", &w, &h, &player, &timeleft);
    } while (1);

    return 0;
}

void read_board(char *board, char *row, int w, int h) {
    int i;

    for (i = 0; i < h; i++) {
        gets(row);

        strncpy((board + i * h), row, w);
    }
}

void do_move(char *board, int player, int timeleft, int w, int h) {
    int our_x, our_y;
    int opp_x, opp_y;
    find_locations(board, player, &our_x, &our_y, &opp_x, &opp_y, w, h);

    if (our_y > opp_y) printf("UP\n");
    else if (our_x > opp_x) printf("LEFT\n");
    else if (our_x < opp_x) printf("RIGHT\n");
    else if (our_y < opp_y) printf("DOWN\n");
    else {
        switch (rand() % 4) {
            case 0: printf("UP\n"); break;
            case 1: printf("LEFT\n"); break;
            case 2: printf("RIGHT\n"); break;
            case 3: printf("DOWN\n"); break;
        }
    }

    fflush(stdout);
}

void find_locations(char *board, int player,
                    int *our_x, int *our_y, int *opp_x, int *opp_y,
                    int w, int h)
{
    int i;
    for (i = 0; i < w * h; i++) {
        if (board[i] == '1') {
            if (player == 1) {
                *our_x = i % w;
                *our_y = i / h;
            }
            else {
                *opp_x = i % w;
                *opp_y = i / h;
            }
        }
        else if (board[i] == '2') {
            if (player == 2) {
                *our_x = i % w;
                *our_y = i / h;
            }
            else {
                *opp_x = i % w;
                *opp_y = i / h;
            }
        }
    }
}
