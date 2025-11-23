/*
    SNAKE GAME IN C - Cross Platform Version
    Works on Online Compilers, Linux, Mac, Windows
    This is a TURN-BASED version (press keys to move)
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define WIDTH 20
#define HEIGHT 10
#define MAX_LENGTH 50

// Game variables
int gameOver;
int score;

// Snake variables
int snakeX[MAX_LENGTH], snakeY[MAX_LENGTH];
int snakeLength;
char direction;

// Food variables
int foodX, foodY;

// Function declarations
void setup();
void draw();
void input();
void logic();
void spawnFood();

int main() {
    char playAgain;
    
    printf("\n");
    printf("  ================================\n");
    printf("       SNAKE GAME IN C\n");
    printf("  ================================\n");
    printf("  Controls:\n");
    printf("    U = Up\n");
    printf("    D = Down\n");
    printf("    L = Left\n");
    printf("    R = Right\n");
    printf("    X = Quit\n");
    printf("  ================================\n");
    printf("  Press ENTER after each move!\n");
    printf("  ================================\n\n");
    printf("  Press ENTER to start...");
    getchar();
    
    do {
        setup();
        
        while (!gameOver) {
            draw();
            input();
            logic();
        }
        
        printf("\n  ======== GAME OVER ========\n");
        printf("  Your Score: %d\n", score);
        printf("  ===========================\n");
        printf("\n  Play again? (y/n): ");
        scanf(" %c", &playAgain);
        while(getchar() != '\n');  // Clear buffer
        
    } while (playAgain == 'y' || playAgain == 'Y');
    
    printf("\n  Thanks for playing!\n\n");
    return 0;
}

void setup() {
    gameOver = 0;
    score = 0;
    direction = 'r';  // Start moving right (R)
    
    // Initialize snake in the middle
    snakeLength = 3;
    snakeX[0] = WIDTH / 2;
    snakeY[0] = HEIGHT / 2;
    
    for (int i = 1; i < snakeLength; i++) {
        snakeX[i] = snakeX[0] - i;
        snakeY[i] = snakeY[0];
    }
    
    srand(time(NULL));
    spawnFood();
}

void spawnFood() {
    int valid;
    do {
        valid = 1;
        foodX = rand() % (WIDTH - 2) + 1;
        foodY = rand() % (HEIGHT - 2) + 1;
        
        // Make sure food doesn't spawn on snake
        for (int i = 0; i < snakeLength; i++) {
            if (foodX == snakeX[i] && foodY == snakeY[i]) {
                valid = 0;
                break;
            }
        }
    } while (!valid);
}

void draw() {
    printf("\n");
    
    // Top border
    printf("  +");
    for (int i = 0; i < WIDTH; i++) printf("-");
    printf("+\n");
    
    // Game area
    for (int y = 0; y < HEIGHT; y++) {
        printf("  |");
        for (int x = 0; x < WIDTH; x++) {
            int printed = 0;
            
            // Check for snake head
            if (x == snakeX[0] && y == snakeY[0]) {
                printf("@");
                printed = 1;
            }
            
            // Check for snake body
            if (!printed) {
                for (int i = 1; i < snakeLength; i++) {
                    if (x == snakeX[i] && y == snakeY[i]) {
                        printf("o");
                        printed = 1;
                        break;
                    }
                }
            }
            
            // Check for food
            if (!printed && x == foodX && y == foodY) {
                printf("*");
                printed = 1;
            }
            
            // Empty space
            if (!printed) {
                printf(" ");
            }
        }
        printf("|\n");
    }
    
    // Bottom border
    printf("  +");
    for (int i = 0; i < WIDTH; i++) printf("-");
    printf("+\n");
    
    // Score display
    printf("  Score: %d  |  Length: %d\n", score, snakeLength);
    printf("  Direction keys: U/D/L/R (X to quit)\n");
}

void input() {
    char key;
    printf("\n  Enter move: ");
    scanf(" %c", &key);
    while(getchar() != '\n');  // Clear input buffer
    
    switch (key) {
        case 'u': case 'U':
            if (direction != 'd') direction = 'u';
            break;
        case 'd': case 'D':
            if (direction != 'u') direction = 'd';
            break;
        case 'l': case 'L':
            if (direction != 'r') direction = 'l';
            break;
        case 'r': case 'R':
            if (direction != 'l') direction = 'r';
            break;
        case 'x': case 'X':
            gameOver = 1;
            break;
    }
}

void logic() {
    if (gameOver) return;
    
    // Store previous positions
    int prevX[MAX_LENGTH], prevY[MAX_LENGTH];
    for (int i = 0; i < snakeLength; i++) {
        prevX[i] = snakeX[i];
        prevY[i] = snakeY[i];
    }
    
    // Move head based on direction
    switch (direction) {
        case 'u': snakeY[0]--; break;
        case 'd': snakeY[0]++; break;
        case 'l': snakeX[0]--; break;
        case 'r': snakeX[0]++; break;
    }
    
    // Move body
    for (int i = 1; i < snakeLength; i++) {
        snakeX[i] = prevX[i - 1];
        snakeY[i] = prevY[i - 1];
    }
    
    // Wall collision
    if (snakeX[0] < 0 || snakeX[0] >= WIDTH || 
        snakeY[0] < 0 || snakeY[0] >= HEIGHT) {
        gameOver = 1;
        printf("\n  >> You hit the wall! <<\n");
        return;
    }
    
    // Self collision
    for (int i = 1; i < snakeLength; i++) {
        if (snakeX[0] == snakeX[i] && snakeY[0] == snakeY[i]) {
            gameOver = 1;
            printf("\n  >> You hit yourself! <<\n");
            return;
        }
    }
    
    // Food collision
    if (snakeX[0] == foodX && snakeY[0] == foodY) {
        score += 10;
        snakeLength++;
        snakeX[snakeLength - 1] = prevX[snakeLength - 2];
        snakeY[snakeLength - 1] = prevY[snakeLength - 2];
        spawnFood();
        printf("\n  >> YUM! +10 points <<\n");
    }
}