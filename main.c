#include <stdio.h>

#define ROWS 20
#define COLS 50

char canvas[ROWS][COLS];

void initializeCanvas() {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            canvas[i][j] = '_';
        }
    }
}

void drawRectangle(int x, int y, int width, int height) {
    int i, j;
    for(i = y; i < y + height; i++) {
        for(j = x; j < x + width; j++) {
            canvas[i][j] = '*';
        }
    }
}

void displayCanvas() {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
}

int main() {
    initializeCanvas();

    drawRectangle(5, 3, 10, 5);

    displayCanvas();

    return 0;
}