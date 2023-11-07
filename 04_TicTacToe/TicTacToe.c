#include <stdio.h>

char BOARD[3][3];
char PLAYER = 'X';

void initializeBoard();
void printBoard();
void playerMove();
int checkWin();

int main() 
{
    int turns = 0;
    initializeBoard();
    printBoard();
    while (turns <= 9)
    {
        playerMove();
        printBoard();
        if (checkWin(PLAYER) == 1)
        {
            printf("Player %c wins!\n", PLAYER);
            break;
        }
        turns++;
        if (turns == 9)
        {
            printf("It's a tie!\n");
            break;
        }
        PLAYER = (PLAYER == 'X') ? 'O' : 'X';
    }
    return 0;
}

void initializeBoard()
{
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            BOARD[i][j] = ' ';
        }
    }
}

void printBoard()
{
    printf(" %c | %c | %c ", BOARD[0][0], BOARD[0][1], BOARD[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", BOARD[1][0], BOARD[1][1], BOARD[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", BOARD[2][0], BOARD[2][1], BOARD[2][2]);
    printf("\n");
}

void playerMove()
{
    int row, col;
    do
    {
    printf("Please enter a row (1-3): ");
    scanf("%d", &row);
    row--;      //array index starts at 0
    printf("Please enter a column (1-3): ");
    scanf("%d", &col);
    col--;      //array index starts at 0
    if (BOARD[row][col] != ' ')
    {
        printf("Invalid entry, please enter again.\n");
    }
    } while (BOARD[row][col] != ' ');
    BOARD[row][col] = PLAYER;
}

int checkWin()
{
   //check rows
   for (int i = 0; i < 3; i++)
   {
      if (BOARD[i][0] == PLAYER && BOARD[i][1] == PLAYER && BOARD[i][2] == PLAYER)
      {
        return 1;
      }
   }

   //check columns
   for (int i = 0; i < 3; i++)
   {
      if (BOARD[0][i] == PLAYER && BOARD[1][i] == PLAYER && BOARD[2][i] == PLAYER)
      {
         return 1;
      }
   }

   //check diagonals
   if (BOARD[0][0] == PLAYER && BOARD[1][1] == PLAYER && BOARD[2][2] == PLAYER)
   {
      return 1;
   }

   if (BOARD[0][2] == PLAYER && BOARD[1][1] == PLAYER && BOARD[2][0] == PLAYER)
   {
      return 1;
   }
   return 0;
}