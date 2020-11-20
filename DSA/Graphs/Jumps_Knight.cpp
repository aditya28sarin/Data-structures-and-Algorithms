#include<bits/stdc++.h>
using namespace std;

class Cell
{
public:
    int x;
    int y;
    int step;

    Cell(){}

    Cell(int x, int y, int step)
    {
        this->x=x;
        this->y=y;
        this->step=step;
    }
};

bool isInside( int x, int y, int N)
{
    if((x>=1 && x<=N)  &&  (y>=1 && y<=N))
        return true;
    return false;
}

int minStepToReachTarget(int knightPos[], int targetPos[], int N)
{
    int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 }; 
    int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 }; 

    queue<Cell> q;

    q.push(Cell(knightPos[0],knightPos[1],0));

    int x,y;

    bool visited[N+1][N+1]{false};

    while(!q.empty())
    {
        Cell t= q.front();
        q.pop();

        if (t.x == targetPos[0] && t.y == targetPos[1]) 
            return t.step;

        for(int i=0; i<8;i++)
        {
            x=t.x+dx[i];
            y=t.y+dy[i];

            if(isInside(x,y,N) && !visited[x][y])
            {
                visited[x][y]=true;
                q.push(Cell(x,y,t.step+1));
            }
        }
    }
}

int main()
{
    int cases;
    cin>>cases;
    
    while(cases--)
    {
    int N;
    int knightPos[2];
    int targetPos[2];
    cin>>N;
    for(int i=0;i<2;i++)
    {
        cin>>knightPos[i];
    }
    for(int i=0;i<2;i++)
    {
        cin>>targetPos[i];
    }
    cout << minStepToReachTarget(knightPos, targetPos, N)<<endl; 
    }
   

}