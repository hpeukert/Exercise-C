#include <stdio.h>
#include <ctype.h>

typedef struct
{
    int x;
    int y;
} Point;

void printPoint(Point p)
{
    printf("Point is at (%i,%i)\n", p.x, p.y);
}

void movePoint(Point *p)
{
    printf("Where do you want to move the point?\nPlease enter x coordinate: ");
    scanf("%d", &p->x);
    printf("Please enter y coordinate: ");
    scanf("%d",&p->y);
}

void printNewPoint(Point p)
{
    printf("New coordinates of point are: (%i,%i)\n", p.x, p.y);
}

int main()
{
    char answer;
    Point p = {1, 1};
    printPoint(p);

    while (1)
    {
        printf("Do you want to move the point? (Y/N): ");
        scanf(" %c", &answer); // space before "%c" to accomodate for pressing of enter button
        answer = toupper(answer);
        if (answer == 'Y')
        {
            movePoint(&p);
            printNewPoint(p);
            continue;
        }
        else if (answer == 'N')
        {
            printPoint(p);
            break;
        }
        else
        {
            printf("Wrong entry\n");
            continue;
        }
    }
    return 0;
}
