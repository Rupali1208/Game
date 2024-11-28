#include<stdio.h>
 

char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};


void removeNumber()
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}  


void draw()
{
    printf("\t\t\t\t\t\t"),
    printf(" %c %c %c %c %c \n",board[0][0],186,board[0][1],186,board[0][2]);
    printf("\t\t\t\t\t\t"),
    printf("%c%c%c%c%c%c%c%c%c%c%c\n",205,205,205,206,205,205,205,206,205,205,205);
    printf("\t\t\t\t\t\t"),
    printf(" %c %c %c %c %c \n",board[1][0],186,board[1][1],186,board[1][2]);
    printf("\t\t\t\t\t\t"),
    printf("%c%c%c%c%c%c%c%c%c%c%c\n",205,205,205,206,205,205,205,206,205,205,205);
    printf("\t\t\t\t\t\t"),
    printf(" %c %c %c %c %c \n",board[2][0],186,board[2][1],186,board[2][2]);
}

int check()
{


    // return 1 win
    // check for X
    // horizontal
    if((board[0][0] =='X') && (board[0][1] == 'X') && (board[0][2] == 'X'))
    {
        return 1;
    }
    else if((board[1][0] =='X') && (board[1][1] == 'X') && (board[1][2] == 'X'))
    {
        return 1;
    }
    else if((board[2][0] =='X') && (board[2][1] == 'X') && (board[2][2] == 'X'))
    {
        return 1;
    }


    // verticle


    else if((board[0][0] =='X') && (board[1][0] == 'X') && (board[2][0] == 'X'))
    {
        return 1;
    }
    else if((board[0][1] =='X') && (board[1][1] == 'X') && (board[2][1] == 'X'))
    {
        return 1;
    }
    else if((board[0][2] =='X') && (board[1][2] == 'X') && (board[2][2] == 'X'))
    {
        return 1;
    }


    // cross


    else if((board[0][0] =='X') && (board[1][1] == 'X') && (board[2][2] == 'X'))
    {
        return 1;
    }
    else if((board[0][2] =='X') && (board[1][1] == 'X') && (board[2][0] == 'X'))
    {
        return 1;
    }


    // check for O
    // horizontal
    if((board[0][0] =='O') && (board[0][1] == 'O') && (board[0][2] == 'O'))
    {
        return 1;
    }
    else if((board[1][0] =='O') && (board[1][1] == 'O') && (board[1][2] == 'O'))
    {
        return 1;
    }
    else if((board[2][0] =='O') && (board[2][1] == 'O') && (board[2][2] == 'O'))
    {
        return 1;
    }


    // verticle
    else if((board[0][0] =='O') && (board[1][0] == 'O') && (board[2][0] == 'O'))
    {
        return 1;
    }
    else if((board[0][1] =='O') && (board[1][1] == 'O') && (board[2][1] == 'O'))
    {
        return 1;
    }
    else if((board[0][2] =='O') && (board[1][2] == 'O') && (board[2][2] == 'O'))
    {
        return 1;
    }


    // cross
    else if((board[0][0] =='O') && (board[1][1] == 'O') && (board[2][2] == 'O'))
    {
        return 1;
    }
    else if((board[0][2] =='O') && (board[1][1] == 'O') && (board[2][0] == 'O'))
    {
        return 1;
    }
    return 0;
}



// int inputValue(int input, int player)
// {
//     char ch;
//     if(player == 1)
//     {
//         ch = 'X';
//     }
//     else
//     {
//         ch = 'O';
//     }
//     if(input == 1)
//     {
//         board[0][0] = ch;
//     }
//     else if(input == 2)
//     {
//         board[0][1] = ch;
//     }
//     else if(input == 3)
//     {
//         board[0][2] = ch;
//     }
//     else if(input == 4)
//     {
//         board[1][0] = ch;
//     }
//     else if(input == 5)
//     {
//         board[1][1] = ch;
//     }
//     else if(input == 6)
//     {
//         board[1][2] = ch;
//     }
//     else if(input == 7)
//     {
//         board[2][0] = ch;
//     }
//     else if(input == 8)
//     {
//         board[2][1] = ch;
//     }
//     else if(input == 9)
//     {
//         board[2][2] = ch;
//     }
// }


void inputValue(int input, char player)
{
    int row = (input - 1) / 3;
    int column = (input - 1) % 3;
    board[row][column] = player;
}

int isValidMove(int input)
{
    int row = (input - 1) / 3;
    int column = (input - 1) % 3;
    return(input >= 1 && input <= 9 && board[row][column] == ' ');
}

int computerMove() {
    int move;
    do {
        
        move = (rand() % 9) + 1; // Random number between 1 and 9
    } while (!isValidMove(move));
    return move;
}

int main()
{
    int input;
    char player = 'X'; // Player starts with 'X'
    int status = 0;

    srand(time(0)); // Seed for random number generation

    draw();
    printf("Press any key to start!\n");
    getch();

    system("cls");
    removeNumber();

    for (int i = 0; i < 9; i++)
    {
        draw();

        if (player == 'X')
        {
            // Human player
            printf("Your turn! Enter a number (1-9): ");
            scanf("%d", &input);
            while (!isValidMove(input))
            {
                printf("Invalid move! Enter a valid number (1-9): ");
                scanf("%d", &input);
            }
        }
        else
        {
            // Computer's turn
            sleep(2); // Add delay for realism
            input = computerMove(); // Generate computer's move
            printf("Computer chooses: %d\n", input);
        }

        inputValue(input, player); // Update the board
        if (check())
        {
            system("cls");
            draw();
            if (player == 'X')
                printf("You win!\n");
            else
                printf("Computer wins!\n");
            return 0;
        }

        player = (player == 'X') ? 'O' : 'X'; // Switch turns
        system("cls");
    }

    draw();
    printf("It's a draw!\n");
    return 0;
}
