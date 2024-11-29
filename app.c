#include<stdio.h>

char board[3][3];
char currentplayer='X';

void initializeBoard()
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            board [i][j] = ' ';
        }
    }
}

void printBoard()
{
    printf("\n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%c",board[i][j]);
            if (j<2) printf("|");
            
        }
          if(i<2)   printf("\n---|---|---\n");
    }
     printf("\n");
}

int checkWin()
{
    for(int i=0;i<3;i++)
    {
        if(board[i][0]==currentplayer && board[i][1]==currentplayer && board[i][2]==currentplayer) return 1;
        if(board[0][i]==currentplayer && board[1][i]==currentplayer && board[2][i]==currentplayer) return 1;
    }

    if(board[0][0]==currentplayer && board[1][1]==currentplayer && board[2][2]==currentplayer) return 1;
    if(board[0][2]== currentplayer && board[1][1]==currentplayer && board[2][0]==currentplayer) return 1;
    return 0;
}

int isBoardFull()
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i][j]==' ') return 0;
        }
    }
    return 1;
}

void switchPlayer()
{
    currentplayer=(currentplayer=='X') ? 'O' : 'X';
}

int main()
{
    int row, col;

    initializeBoard();

    printf("Welcome to Tic Tac Toe!");
    printBoard();

    while(1)
    {
    printf("Player %c, enter row (1-3), enter column (1-3):");
    scanf("%d%d",&row,&col);

    if(row < 1 || row > 3 || col < 1 || col > 3 || board [row - 1] [col -1] !=' ')
    {
        printf("Invalid move.Please Try Again");
        continue;
    }
    

    board[row - 1] [col -1]=  currentplayer;
    printBoard();

    if(checkWin())
    {
        printf("Player %c wins:",currentplayer);
        break;
    }

    if(isBoardFull())
    {
        printf("It's a Tie!");
        break;
    }

    switchPlayer();

    }

    return 0;
}