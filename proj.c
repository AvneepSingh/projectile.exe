#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<unistd.h>

double speed;
double angle;
const double pi = 3.14;

int grid[40][100];

int px=0;
int py=39;

void printgrid()
{
    for(int i=0;i<40;i++)
    {
        for(int j=0;j<100;j++)
        {
            printf("%s",grid[i][j]==0?" ":"*");
        }
        printf("\n");
    }
}

void projection(double speed,double angle)
{
    double vx = speed*(cos((angle*pi)/180));
    double vy = speed*(sin((angle*pi)/180));
    
    double totaltime = vy/5;
    double t = 0;
    
    while(t <= totaltime)
    {
        system("clear");
        px = (int)((vx)*t);
        py = 39 - ((int)((vy)*t - 5*t*t));
        if(py > 0)
        {
            grid[py][px] = 1;
        }
        printgrid();
        t = t + 0.02;
        usleep(20000);
    }
}

int main(int argc,char* argv[])
{
    if(argc != 3)
    {
        printf("invalid command\ntry: >> ./proj <speed> <angle>\n");
        return 0;
    }
    speed = atoi(argv[1]);
    angle = atoi(argv[2]);
    
    //printf("%f\n",sin((angle*pi)/180));
    projection(speed,angle);
}
