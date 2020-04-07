#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXN 10
char px[MAXN + 5][MAXN * 2 + 1] = {{}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {' ', 'S', 'c', 'o', 'r', 'e', ':', ' ', '%', 'd', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}};
struct Body
{
    int timer;
    int x, y;
    char BodyCh[2];
};
struct Body NewBody(int n, int x, int y, char ch[2])
{
    struct Body a;
    a.timer = n;
    a.x = x, a.y = y;
    a.BodyCh[0] = ch[0];
    a.BodyCh[1] = ch[1];
    return a;
}
struct Snake
{
    int way;
    /* list: *  map:   *
     * 1.N ^ *   1^    *
     * 2.E < * 4<   >2 *
     * 3.S v *   3v    *
     * 4.W > *         */
    int lenth;
    int x, y;
    const char *HeadCh;
    struct Body snakebody[85];
} snake;
struct Snake NewSnake(int n, int x, int y, const char *ch)
{
    struct Snake a;
    a.lenth = n;
    a.x = x, a.y = y;
    a.HeadCh = ch;
    return a;
}
struct Apple
{
    int x, y;
    int AddScore;
} apple1;
char DrawBody(int n)
{
    switch (n)
    {
    case 1:
        return '|';
        break;
    case 2:
        return '>';
        break;
    case 3:
        return '!';
        break;
    case 4:
        return '<';
        break;
    default:
        break;
    }
}

int i, j;
int main()
{
    srand(time(NULL));
    printf("\n\n\n    ##############    \n    ##Snake Game##    \n    ##############    \n    ##Type Enter##    \n    ## To Start ##    \n                      \n");
    for (i = 0; i < MAXN; ++i)
    {
        for (j = 0; j < MAXN; ++j)
        {
            if ((i == 0 || i == 9) && !(j == 0 || j == 9))
                px[i][j * 2] = '=', px[i][j * 2 + 1] = '=';
            else if ((j == 0 || j == 9) && !(i == 0 || i == 9))
                px[i][j * 2] = '|', px[i][j * 2 + 1] = '|';
            else if ((j == 0 || j == 9) && (i == 0 || i == 9))
                px[i][j * 2] = '#', px[i][j * 2 + 1] = '#';
            else
                px[i][j * 2] = ' ', px[i][j * 2 + 1] = ' ';
        }
        px[i][MAXN * 2] = '\n';
    }
    printf("\n\n\n    ##############    \n    ##Snake Game##    \n    ##############    \n    ##Type Enter##    \n    ## To Start ##    \n    >                 \n");
    for (i = 1; i <= 50000000; ++i)
        ;
    system("cls");
    printf("\n\n\n    ##############    \n    ##Snake Game##    \n    ##############    \n    ##Type Enter##    \n    ## To Start ##    \n    >>                \n");
    for (i = 1; i <= 5000000; ++i)
        ;
    system("cls");
    printf("\n\n\n    ##############    \n    ##Snake Game##    \n    ##############    \n    ##Type Enter##    \n    ## To Start ##    \n    >>>               \n");
    for (i = 1; i <= 5000000; ++i)
        ;
    system("cls");
    printf("\n\n\n    ##############    \n    ##Snake Game##    \n    ##############    \n    ##Type Enter##    \n    ## To Start ##    \n    >>>>              \n");
    for (i = 1; i <= 50000000; ++i)
        ;
    apple1.AddScore = 3;
    apple1.x = rand() % 5 + 2, apple1.y = rand() % 5 + 2;
    system("cls");
    snake = NewSnake(5, /* rand() % 5 + 2*/ 8, rand() % 5 + 2, "::");
    printf("\n\n\n    ##############    \n    ##Snake Game##    \n    ##############    \n    ##Type Enter##    \n    ## To Start ##    \n    >>>>>>>           \n");
    for (i = 1; i <= 500000; ++i)
        ;
    system("cls");
    for (i = 1; i <= 81; ++i)
    {
        snake.snakebody[i] = NewBody(i, 10, 9, "::");
    }
    printf("\n\n\n    ##############    \n    ##Snake Game##    \n    ##############    \n    ##Type Enter##    \n    ## To Start ##    \n    >>>>>>>>>         \n");
    for (i = 1; i <= 500000; ++i)
        ;
    system("cls"); /*
    for (i = 1; i <= snake.lenth; ++i)
    {
        snake.snakebody[i] = NewBody(i, snake.x, snake.y, "::");
    }*/
    printf("\n\n\n    ##############    \n    ##Snake Game##    \n    ##############    \n    ##Type Enter##    \n    ## To Start ##    \n    >>>>>>>>>>>>>>    \n");
    getchar(); //In windows,this can puash the program ( if you not type chars ) --but JC need the different.

    while (1)
    {
        /*Codes Begin*/
        px[apple1.x][apple1.y * 2] = '(', px[apple1.x][apple1.y * 2 + 1] = ')';
        if (snake.x == apple1.x && snake.y == apple1.y)
            snake.lenth += apple1.AddScore, apple1.x = rand() % 5 + 2, apple1.y = rand() % 5 + 2;
        for (i = 1; i <= snake.lenth; ++i)
        {
            snake.snakebody[i].timer--;
            if (snake.snakebody[i].timer > 0)
            {
                px[snake.snakebody[i].x][snake.snakebody[i].y * 2] = snake.snakebody[i].BodyCh[0];
                px[snake.snakebody[i].x][snake.snakebody[i].y * 2 + 1] = snake.snakebody[i].BodyCh[1];
            }
            else
            {
                snake.snakebody[i].BodyCh[0] = DrawBody(snake.way);
                snake.snakebody[i].BodyCh[1] = DrawBody(snake.way);
                px[snake.snakebody[i].x][snake.snakebody[i].y * 2] = ' ';
                px[snake.snakebody[i].x][snake.snakebody[i].y * 2 + 1] = ' ';
                snake.snakebody[i].x = snake.x, snake.snakebody[i].y = snake.y;
                snake.snakebody[i].timer = snake.lenth;
                px[snake.snakebody[i].x][snake.snakebody[i].y * 2] = snake.snakebody[i].BodyCh[0];
                px[snake.snakebody[i].x][snake.snakebody[i].y * 2 + 1] = snake.snakebody[i].BodyCh[1];
            }
        }
        if (kbhit())
        {
            int ch = getch();
            if (ch >= 'A' && ch <= 'Z')
                ch += 'a' - 'A';
            switch (ch)
            {
            case 'a':
                snake.way--;
                if (snake.way < 1)
                    snake.way = 4;
                break;
            case 'd':
                snake.way++;
                if (snake.way > 4)
                    snake.way = 1;
                break;
            default:
                ch = getch();
            }
        }
        switch (snake.way)
        {
        case 1:
            if (snake.x > 1)
                snake.x--;
            else
            {
                printf("\n\n\n## You Lost! ##\n###Game Over###\n\n\n\n");
                return 0;
            }
            break;
        case 2:
            if (snake.y < 8)
                snake.y++;
            else
            {
                printf("\n\n\n## You Lost! ##\n###Game Over###\n\n\n\n");
                return 0;
            }
            break;
        case 3:
            if (snake.x < 8)
                snake.x++;
            else
            {
                printf("\n\n\n## You Lost! ##\n###Game Over###\n\n\n\n");
                return 0;
            }
            break;
        case 4:
            if (snake.y > 1)
                snake.y--;
            else
            {
                printf("\n\n\n## You Lost! ##\n###Game Over###\n\n\n\n");
                return 0;
            }
            break;
        default:
            snake.way = 1;
            if (snake.x > 1)
                snake.x--;
            else
            {
                printf("\n\n\n## You Lost! ##\n###Game Over###\n\n\n\n");
                return 0;
            }
            break;
        }
        px[snake.x][snake.y * 2] = snake.HeadCh[0];
        px[snake.x][snake.y * 2 + 1] = snake.HeadCh[1];
        /*Codes End*/
        printf((char *)px, snake.lenth);
        for (i = 1; i <= 500000000; ++i)
            ;
        system("cls"); //In windows,this can clean the window --but JC not need.
    }
}