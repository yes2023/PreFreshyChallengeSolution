#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct queue {
    int x;
    int y;
    char prev;
} q[10005];

struct tracking {
    int data;
    char prev;
} track[105][105];

int main()
{
	FILE * fileIn;
	FILE * fileOut;
	int i, j, k, x, y, p, m, n, qf = 0, qe = 1;

    fileIn = fopen("4.in", "r");
    fileOut = fopen("4.out", "w");

    //data in
    fscanf(fileIn, "%d %d", &m, &n);
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
            fscanf(fileIn, "%d", &track[i][j].data);
    }

    //init
    q[qf].x = 0;
    q[qf].y = 0;
    q[qf].prev = '0';

    //loop until the exit is found
    while(1)
    {
        x = q[qf].x;
        y = q[qf].y;
        p = q[qf].prev;
        qf++;

        track[x][y].prev = p;

        if(track[x][y].data == 9)
            break;

        //bfs
        //up
        if(x!=0 && p!='u' && (track[x-1][y].data == 0 || track[x-1][y].data == 9))
        {
            q[qe].x = x-1;
            q[qe].y = y;
            q[qe].prev = 'd';
            qe++;
        }
        //down
        if(x!=m-1 && p!='d' && (track[x+1][y].data == 0 || track[x+1][y].data == 9))
        {
            q[qe].x = x+1;
            q[qe].y = y;
            q[qe].prev = 'u';
            qe++;
        }
        //left
        if(y!=0 && p!='l' && (track[x][y-1].data == 0 || track[x][y-1].data == 9))
        {
            q[qe].x = x;
            q[qe].y = y-1;
            q[qe].prev = 'r';
            qe++;
        }
        //right
        if(y!=n-1 && p!='r' && (track[x][y+1].data == 0 || track[x][y+1].data == 9))
        {
            q[qe].x = x;
            q[qe].y = y+1;
            q[qe].prev = 'l';
            qe++;
        }
    }

    //reset queue pointer
    qe = 0;

    //backtracking
    printf("Exit: %d %d\n", x, y);
    while(1)
    {
        q[qe].x = x;
        q[qe].y = y;
        qe++;

        if(track[x][y].prev == 'u')
            x--;
        else if(track[x][y].prev == 'd')
            x++;
        else if(track[x][y].prev == 'l')
            y--;
        else if(track[x][y].prev == 'r')
            y++;
        else
            break;
    }

    //print result
    for(i = qe - 1; i >= 0; i--)
        fprintf(fileOut, "%d %d\n", q[i].x, q[i].y);

    fclose(fileIn);
    fclose(fileOut);

}
