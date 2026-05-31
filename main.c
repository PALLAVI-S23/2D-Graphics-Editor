#include <stdio.h>
#include <math.h>

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
void drawLine(int x1, int x2, int y) {
    int i;
    for(i = x1; i <= x2; i++) {
        canvas[y][i] = '*';
    }
}
void drawTriangle(int x, int y, int height) {
    int i, j;

    for(i = 0; i < height; i++) {
        for(j = 0; j <= i; j++) {
            canvas[y + i][x + j] = '*';
        }
    }
}

void drawCircle(int centerX, int centerY, int radius) {
    int x, y;

    for(y = 0; y < ROWS; y++) {
        for(x = 0; x < COLS; x++) {
            int dx = x - centerX;
            int dy = y - centerY;

            if(dx * dx + dy * dy <= radius * radius) {
                canvas[y][x] = '*';
            }
        }
    }
}

void clearCanvas() {
    int i, j;

    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            canvas[i][j] = '_';
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
int main(){
int choice;

initializeCanvas();

printf("1. Draw Shapes\n");
printf("2. Delete All Shapes\n");
printf("3. Modify Rectangle\n");
printf("Enter choice: ");
scanf("%d", &choice);

if(choice == 1) {
    drawRectangle(5, 3, 10, 5);
    drawLine(20, 35, 10);
    drawTriangle(30, 2, 5);
    drawCircle(40, 15, 3);
}
else if(choice == 2) {
    clearCanvas();
}
else if(choice == 3) {
    drawRectangle(5, 3, 15, 8);
}

displayCanvas();

return 0;
}
