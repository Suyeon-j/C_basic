#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3

int puzzle[ROW][COL];
int BlankX, BlankY;

void makePuzzle();
void printPuzzle();
int inputKey();
void movePuzzle(int);
int checkPuzzle();
void swap(int*, int*);

int main()
{
    int key;

    makePuzzle();

    do
    {
        system("cls");
        printPuzzle();
        key = inputKey();
        movePuzzle(key);
    } while (!checkPuzzle());

    printPuzzle();
    printf("Puzzle solved!\n");

    return 0;
}

void makePuzzle() {
    int i, j, row, col;
    int num = 1;

    // Initialize puzzle with values
    for (i = 0; i < ROW; i++)
        for (j = 0; j < COL; j++)
            puzzle[i][j] = num++;

    // Set blank position
    BlankX = ROW - 1;
    BlankY = COL - 1;
    puzzle[BlankX][BlankY] = 9; // Represent blank with 9

    // Shuffle the puzzle
    srand(time(NULL));
    for (i = 0; i < ROW * COL; i++) {
        row = rand() % ROW;
        col = rand() % COL;
        if (puzzle[row][col] != 9) {
            swap(&puzzle[BlankX][BlankY], &puzzle[row][col]);
            BlankX = row;
            BlankY = col;
        }
    }
}

void printPuzzle()
{
    int i, j;
    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            if (puzzle[i][j] == 9)
                printf("   ");
            else
                printf(" %d ", puzzle[i][j]);
        }
        printf("\n");
    }
}


int inputKey()
{
    int key;
    printf("입력 키 \n");
    printf("(1) ←\n");
    printf("(2) ↑\n");
    printf("(3) ↓\n");
    printf("(4) →\n");
    scanf_s("%d", &key);
    return key;
}


void movePuzzle(int key)
{
    int newX = BlankX, newY = BlankY;

    switch (key) {
    case 1: // Left
        newY--;
        break;
    case 2: // Up
        newX--;
        break;
    case 3: // Down
        newX++;
        break;
    case 4: // Right
        newY++;
        break;
    default:
        printf("Invalid move\n");
        return;
    }

    if (newX >= 0 && newX < ROW && newY >= 0 && newY < COL) {
        swap(&puzzle[BlankX][BlankY], &puzzle[newX][newY]);
        BlankX = newX;
        BlankY = newY;
    }
}

int checkPuzzle()
{
    int i, j, num = 1;
    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            if (i == ROW - 1 && j == COL - 1)
                return puzzle[i][j] == 9;
            if (puzzle[i][j] != num++)
                return 0;
        }
    }
    return 1;
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
