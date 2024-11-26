#include <stdio.h>

#define MAX 10  // Maximum size of the maze

int maze[MAX][MAX];
int visited[MAX][MAX];
int rows, cols;

// Directions: down, up, right, left
int rowDir[] = {1, -1, 0, 0};
int colDir[] = {0, 0, 1, -1};

// Function to print the maze with the path
void printMaze() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (maze[i][j] == 2) {
                printf("S ");
            } else if (maze[i][j] == 3) {
                printf("E ");
            } else if (visited[i][j]) {
                printf("* ");  // Path
            } else if (maze[i][j] == 1) {
                printf("| ");  // Wall
            } else {
                printf(". ");  // Empty space
            }
        }
        printf("\n");
    }
}

// Depth-first search function
int dfs(int x, int y) {
    if (x < 0 || x >= rows || y < 0 || y >= cols || maze[x][y] == 1 || visited[x][y])
        return 0;

    visited[x][y] = 1;

    if (maze[x][y] == 3) {  // Reached the end
        return 1;
    }

    // Explore all 4 directions
    for (int i = 0; i < 4; i++) {
        if (dfs(x + rowDir[i], y + colDir[i])) {
            return 1;
        }
    }

    // Backtrack: unmark this cell if it doesn't lead to the end
    visited[x][y] = 0;
    return 0;
}

int main() {
    printf("Made by : Arya Mali,Krish Parmar,Abhishek Patel\n");
    printf("Enter the number of rows and columns (max %d): ", MAX);
    scanf("%d %d", &rows, &cols);

    printf("Enter the maze as a matrix (0: path, 1: wall, 2: start, 3: end):\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &maze[i][j]);
        }
    }

    // Find the start position
    int startX, startY;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (maze[i][j] == 2) {
                startX = i;
                startY = j;
            }
        }
    }

    // Initialize visited array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            visited[i][j] = 0;
        }
    }

    if (dfs(startX, startY)) {
        printf("\nPath found:\n");
        printMaze();
    } else {
        printf("\nNo path found!\n");
    }

    return 0;
}
