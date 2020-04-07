#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>
extern void color(int a);
extern void gto(int x, int y);
extern int DrawMain();
#define PutSpace printf("  ")
#define ErrorPictrue(a) \
    color(15 * 16 + 0), \
        gto(2, 0 + a),  \
        PutSpace,       \
        gto(8, 0 + a),  \
        PutSpace,       \
        gto(5, 5 + a),  \
        PutSpace,       \
        gto(4, 5 + a),  \
        PutSpace,       \
        gto(6, 5 + a),  \
        PutSpace,       \
        gto(3, 6 + a),  \
        PutSpace,       \
        gto(7, 6 + a),  \
        PutSpace,       \
        gto(2, 6 + a),  \
        PutSpace,       \
        gto(8, 6 + a),  \
        PutSpace,       \
        gto(1, 7 + a),  \
        PutSpace,       \
        gto(9, 7 + a),  \
        PutSpace,       \
        gto(1, 8 + a),  \
        PutSpace,       \
        gto(9, 8 + a),  \
        PutSpace
using namespace std;
int main()
{
    int RunState = DrawMain();
    system("color 07");
    system("cls");
    color(0 * 16 + 7);
    gto(3, 3);
    switch (RunState)
    {
    case 0:
        puts("The program is about to be closed in a planned way.");
        break;
    case -1:
        puts("There is an irreparable error in the program. It will be restarted for you.");
        break;
    default:
        system("color 17");
        gto(11, 3);
        puts("!!!Unknown Error!!!");
        gto(12, 1);
        printf("---------------------------------------------------------");
        gto(13, 1);
        printf(" Error Number is %d ", RunState);
        gto(14, 1);
        printf(" Error reason : Unknown | Error type : UKE.");
        gto(15, 1);
        printf(" Press any key to continue...");
        ErrorPictrue(3);
        gto(16, 1);
        getchar();
        break;
    }
    return 0;
}