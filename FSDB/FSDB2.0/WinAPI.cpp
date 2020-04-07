#include <windows.h>
/*      Begin      *
 * Windows #Define *
 *                 */
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1 : 0)
#define CLS color(112), system("cls")
#define Ctrl_Delete 147
#define Alt_Delete 163
#define Ctrl_W 23
#define Alt_F4 107
#define PutSpace putchar(' '), putchar(' ')
/*                 *
 * Windows #Define *
 *       End       */

/*      Begin      *
 *   Windows API   *
 *                 */
void GetPos(POINT &pt)
{
    HWND hwnd = GetForegroundWindow();
    GetCursorPos(&pt);
    ScreenToClient(hwnd, &pt);
    pt.y = pt.y / 16;
    pt.x = pt.x / 16;
}
void color(int a)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
}
void gto(int x, int y)
{
    COORD pos;
    pos.X = y * 2;
    pos.Y = x;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
/*                 *
 *   Windows API   *
 *       End       */