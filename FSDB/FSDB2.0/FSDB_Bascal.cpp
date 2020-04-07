#include "WindowDraw.hpp"
/*      Begin      *
 * FSDB DrawTool 2 *
 *                 */

using namespace WinDraw;
extern void GetPos(POINT& pt);
extern void color(int a);
extern void gto(int x, int y);
#define PutSpace printf("  ")

/*      Begin      *
 *       VAR       *
 *                 */
typedef Button Px;
typedef Button button;
Px px[100][100];
button File, Help;
button Pencil, Erasre, Box;
window DrawingBoard;
window SettingForeGroudColor, SettingBackGroudColor;
int NowTool;
short ForeGroudColor, BackGroudColor;
int DrawingState;
/*
Tool Number:
Box:0;
Pencil:1;
Ersere:2;
None:defult.
*/
/*                 *
 *       VAR       *
 *       End       */

/*      Begin      *
 *    FUNCTIONS    *
 *                 */
void PencilDraw(Px &a)
{
    a.ButtonBackgroudColor = ForeGroudColor >> 4;
    a.ButtonForegroudColor = ForeGroudColor & 15;
    a.RefreshColor();
}
void ErasreDraw(Px &a)
{
    a.ButtonBackgroudColor = BackGroudColor >> 4;
    a.ButtonForegroudColor = BackGroudColor & 15;
    a.RefreshColor();
}
void NoneDraw(Px &a)
{
    a.ButtonBackgroudColor = 0;
    a.ButtonForegroudColor = 7;
    a.RefreshColor();
}
void DrawPX(Px &a)
{
    switch (NowTool)
    {
    case 1:
        PencilDraw(a);
        break;
    case 2:
        ErasreDraw(a);
        break;
    default:
        NoneDraw(a);
        break;
    }
}
/*                 *
 *    FUNCTIONS    *
 *       End       */

/*      Begin      *
 *      MAINS      *
 *                 */
#define BeginState 1
#define LoopState 2
#define BreakState 3
#define EndState 0
#define ErrorState -1
#define SpaceDraw(x)        \
    color(0 * 16 + 15),     \
        gto(x, 1),          \
        color(7 * 16 + 0),  \
        putchar(' '),       \
        color(0 * 16 + 15), \
        putchar(' '),       \
        gto(x, 8),          \
        putchar(' ')
#define ToolUncheckedStatusDraw(x)             \
    color(7 * 16 + 0),                         \
        gto(x, 2), putchar(' '), putchar('|'), \
        gto(x, 7), putchar('|'), putchar(' ')
#define ToolSelectedStateDraw(x)               \
    color(7 * 16 + 0),                         \
        gto(x, 2), putchar(' '), putchar('-'), \
        gto(x, 7), putchar('-'), putchar(' ')
void DrawStart()
{
    /*                                                               *
     * This function will implement beginning of the FSDB DrawTool 2 *
     *                                                               */
    InitializationWindow();
    system("title Free Simple Drawing Board 2.0 / EN_UK");
    system("color 70");
    system("mode con cols=179 lines=52");
    color(8 * 16 + 0);
    for (int i = 5; i <= 46; ++i)
        gto(i, 11), PutSpace;
    for (int i = 11; i <= 52; ++i)
        gto(5, i), PutSpace;
    for (int i = 5; i <= 46; ++i)
        gto(i, 52), PutSpace;
    for (int i = 11; i <= 52; ++i)
        gto(46, i), PutSpace;
    BackGroudColor = 7 * 16 + 0;
    ForeGroudColor = 0 * 16 + 7;
    NowTool = 1;
    for (int i = 5; i <= 15; ++i)
        SpaceDraw(i);
    for (int i = 6; i <= 14; ++i)
        ToolUncheckedStatusDraw(i);
    color(7 * 16 + 0);
    for (int i = 2; i <= 7; ++i)
        gto(5, i), putchar('_'), putchar('_');
    color(7 * 16 + 0);
    gto(6, 2);
    printf("  Tool Box  ");
    Pencil = NewButton(7, 3, 8, 7, 0, " Pencil ", 1);
    Pencil.RefreshButton(1);
    Erasre = NewButton(9, 3, 8, 7, 0, " Erasre ", 1);
    Erasre.RefreshButton(1);
    Box = NewButton(11, 3, 8, 7, 0, " Box    ", 1);
    Box.RefreshButton(1);
    SettingForeGroudColor = NewWindow(14, 3, 15, 4, 0, 7, 1);
    SettingBackGroudColor = NewWindow(14, 5, 15, 6, 7, 0, 1);
    SettingBackGroudColor.RefreshWindow(1);
    SettingForeGroudColor.RefreshWindow(1);
    for (int i = 1; i <= 40; ++i)
    {
        for (int j = 1; j <= 40; ++j)
        {
            px[i][j] = NewButton(i + 5, j + 11, 1, 7, 0, " ", 1);
            px[i][j].RefreshButton(1);
        }
    }
    color(0 * 16 + 7);
    for (int i = 2; i <= 2; ++i)
    {
        for (int j = 0; j <= 88; ++j)
        {
            gto(i, j);
            putchar(' ');
            putchar(' ');
        }
    }
    putchar(' ');
}
void DrawLoop()
{
    if (Box.Preserve() == 2)
        NowTool = 0;
    if (Pencil.Preserve() == 2)
        NowTool = 1;
    if (Erasre.Preserve() == 2)
        NowTool = 2;
    if (SettingBackGroudColor.Preserve() == 2)
    {
        ;
    }
    //SettingBackGroudColor.RefreshWindow(1);
    if (SettingForeGroudColor.Preserve() == 2)
    {
        ;
    }
    //SettingForeGroudColor.RefreshWindow(1);
    for (int i = 1; i <= 40; ++i)
    {
        for (int j = 1; j <= 80; ++j)
        {
            if (px[i][j].Preserve() == 2)
            {
                DrawPX(px[i][j]);
            }
        }
    }
    Sleep(5);
}
void DrawEnd()
{
}
int DrawMain()
{
    /*                                              *
     * This is the MAIN function in FSDB DrawTool 2 *
     *                                              */
    DrawingState = BeginState;
    DrawStart();
    DrawingState = LoopState;
    while (DrawingState == LoopState)
    {
        DrawLoop();
    }
    DrawingState = EndState;
    DrawEnd();
    return DrawingState;
}
/*                 *
 *      MAINS      *
 *       End       */

/*                 *
 * FSDB DrawTool 2 *
 *       End       */
