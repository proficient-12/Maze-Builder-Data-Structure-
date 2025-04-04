#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 5
#define COLS 5

// Structure for stack node to store coordinates
struct Node {
    int row, col;
    struct Node* next;
};

// Stack operations
struct Node* top = NULL;

void push(int row, int col) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->row = row;
    newNode->col = col;
    newNode->next = top;
    top = newNode;
}

void pop() {
    if (top == NULL) return;
    struct Node* temp = top;
    top = top->next;
    free(temp);
}

int isEmpty() {
    return top == NULL;
}

// Maze and visited array
char maze[ROWS][COLS];
int visited[ROWS][COLS];

// Directions: up, right, down, left
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void initializeMaze() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j] = '0'; // Default empty maze
            visited[i][j] = 0;
        }
    }
}

void displayMaze() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

int inputMaze() {
    char input[COLS + 2]; // Extra for newline and null terminator
    int startCount = 0, endCount = 0;
    printf("Enter a 5x5 maze (use 0 for path, 1 for wall, S for start, E for end):\n");
    for (int i = 0; i < ROWS; i++) {
        printf("Enter row %d (5 chars: 0,1,S,E): ", i + 1);
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0; // Remove newline
        if (strlen(input) != COLS) {
            printf("Invalid input! Each row must have exactly 5 characters.\n");
            return 0;
        }
        for (int j = 0; j < COLS; j++) {
            if (input[j] != '0' && input[j] != '1' && input[j] != 'S' && input[j] != 'E') {
                printf("Invalid character! Use only 0, 1, S, or E.\n");
                return 0;
            }
            maze[i][j] = input[j];
            if (input[j] == 'S') startCount++;
            if (input[j] == 'E') endCount++;
        }
    }
    if (startCount != 1 || endCount != 1) {
        printf("Maze must contain exactly one 'S' and one 'E'!\n");
        return 0;
    }
    return 1;
}

int isValid(int row, int col) {
    return (row >= 0 && row < ROWS && col >= 0 && col < COLS && 
            maze[row][col] != '1' && !visited[row][col]);
}

void solveMaze() {
    int startRow, startCol, endRow, endCol;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] == 'S') {
                startRow = i;
                startCol = j;
            }
            if (maze[i][j] == 'E') {
                endRow = i;
                endCol = j;
            }
            visited[i][j] = 0; // Reset visited array
        }
    }

    push(startRow, startCol);
    visited[startRow][startCol] = 1;

    while (!isEmpty()) {
        int row = top->row;
        int col = top->col;
        pop();

        if (row == endRow && col == endCol) {
            printf("Solution found!\n");
            displayMaze();
            return;
        }

        for (int i = 0; i < 4; i++) {
            int newRow = row + dr[i];
            int newCol = col + dc[i];
            if (isValid(newRow, newCol)) {
                push(newRow, newCol);
                visited[newRow][newCol] = 1;
                if (maze[newRow][newCol] != 'E') maze[newRow][newCol] = '*';
            }
        }
    }
    printf("No solution found.\n");
}

int main() {
    int choice;
    initializeMaze(); // Initialize with default empty maze
    do {
        printf("\nMain Menu:\n");
        printf("1: Input and Solve Maze  2: Display Current Maze  0: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline from input buffer

        switch (choice) {
            case 1:
                if (inputMaze()) {
                    solveMaze();
                } else {
                    printf("Maze input failed. Try again.\n");
                }
                break;
            case 2:
                displayMaze();
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 0);

    // Free stack memory
    while (!isEmpty()) pop();
    return 0;
}