#include <stdio.h>

typedef struct {
    int hit_count;
    int run_count;
    int bat_number;
} Player;

int main() {
    Player players[9];
    int N;
    int i, j;

    for (i = 0; i < 9; i++) {
        scanf("%d", &players[i].hit_count);
        players[i].run_count = 0;
        players[i].bat_number = i + 1;
        for (j = 0; j < players[i].hit_count; j++) {
            char result;
            scanf(" %c", &result);
            if (result != 'O') {
                players[i].run_count += result - '0';
            }
        }
    }

    scanf("%d", &N);

    int total_score = 0;
    Player top_three[3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}; // Initialize top three players

    int current_player = 0;
    int out_count = 0;
    while (out_count < N) {
        // Calculate score for current player
        total_score += players[current_player].run_count / 4;
        players[current_player].run_count %= 4;

        // Update top three players if needed
        for (i = 0; i < 3; i++) {
            if (players[current_player].run_count > top_three[i].run_count) {
                for (j = 2; j > i; j--) {
                    top_three[j] = top_three[j - 1];
                }
                top_three[i] = players[current_player];
                break;
            }
        }

        // Move to next player or restart if three outs reached
        current_player = (current_player + 1) % 9;
        out_count = (out_count + 1) % 3; // Increment out count and reset after 3 outs
    }

    // Output results
    printf("%d\n", total_score); // Output total score
    for (i = 0; i < 3; i++) {
        printf("%d %d %d\n", top_three[i].bat_number, top_three[i].hit_count, top_three[i].run_count);
    }

    return 0;
}
