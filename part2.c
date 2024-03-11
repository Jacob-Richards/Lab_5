#include <stdio.h>

// Function to print all possible combinations of scoring plays for a given score
void print_combinations(int score) {
    // Iterate through all possible combinations of touchdowns, field goals, and safeties
    for (int touchdown = 0; touchdown <= score / 6; touchdown++) {
        for (int field_goal = 0; field_goal <= score / 3; field_goal++) {
            for (int safety = 0; safety <= score / 2; safety++) {
                // Iterate through all possible combinations of two-point conversions after touchdowns
                for (int touchdown_2pt = 0; touchdown_2pt <= (score - (touchdown * 6 + field_goal * 3 + safety * 2)) / 8; touchdown_2pt++) {
                    // Iterate through all possible combinations of one-point field goals after touchdowns
                    for (int touchdown_fg = 0; touchdown_fg <= (score - (touchdown * 6 + field_goal * 3 + safety * 2 + touchdown_2pt * 8)) / 7; touchdown_fg++) {
                        // Calculate the remaining score after considering touchdowns, field goals, safeties, and conversions
                        int remaining_score = score - (touchdown * 6 + field_goal * 3 + safety * 2 + touchdown_2pt * 8 + touchdown_fg * 7);
                        // If remaining score is 0, print the combination
                        if (remaining_score == 0) {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", touchdown_2pt, touchdown_fg, touchdown, field_goal, safety);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int score;
    
    // Prompt user for score until a value less than or equal to 1 is entered
    while (1) {
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);
        
        // If the score is less than or equal to 1, stop the program
        if (score <= 1) {
            break;
        }
        
        printf("Possible combinations of scoring plays:\n");
        // Print all possible combinations of scoring plays for the given score
        print_combinations(score);
    }

    return 0;
}
