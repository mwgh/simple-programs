#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标1开始存储 */
Position BinarySearch( List L, ElementType X );

int main()
{
    List L;
    ElementType X = 12;
    Position P;

    L = malloc(sizeof(struct LNode));
    L->Last = 5;
    L->Data[0] = 12;
    L->Data[1] = 31;
    L->Data[2] = 55;
    L->Data[3] = 89;
    L->Data[4] = 102;
    for (int i = 0; i < L->Last; i++) {
        printf("%d ", L->Data[i]);
    }
    putchar('\n');

    P = BinarySearch(L, X);
    printf("%d\n", P);

    return 0;
}

Position recurse(List L, ElementType X, Position start, Position end) {
    if (start > end) {
        return NotFound;
    }

    Position mid = (start + end) / 2;
    if (L->Data[mid] == X) {
        return mid;
    } else if (L->Data[mid] < X) {
        start = mid + 1;
    } else {
        end = mid - 1;
    }
    return recurse(L, X, start, end);
}

/* 你的代码将被嵌在这里 */
Position BinarySearch(List L, ElementType X) {
    Position start = 0;
    Position end = L->Last;

    return recurse(L, X, start, end);
}
