//FILE */C/CodeBlocksProject/Game_test/Game_test.cpp

# include <stdio.h>
# include <string.h>
# include <windows.h>
# include <conio.h>
# include <time.h>

#define dead 1
#define live 0
#define row 80		//定义地图列 
#define line 20		//定义地图行 
#define EASY 75		// 难度 
#define NORMAL 50
#define HARD 30
#define PLAYER_POS 20	//玩家初始列数 
//■★
int play(int n); //游戏w执行函数
void player(int x);  //控制的人物
void printall();	//打印全部游戏界面 
void barrier(int x1,int y);		//生成障碍物 
void mapmove(int n);		//地图的移动 
int judge(int x);			//判断人物是否死亡 
char map[line][row]={{0}};		//定义全部地图 
int start();			//开始界面 
void result(int score);		//结束界面 
void gotoxy(int x, int y);		//移动光标 
void hidden();				//隐藏光标 
struct circlemap{				//每个障碍物 
	int m;
	int y;
}y[5]={{0}};

int main()				//主函数 
{
	int i,n=0;
	while(1){
	if(n%20==0)
		mapmove(n%20);
	n++;
	for(i=0;i<5;i++)
		{
		barrier(y[i].m,y[i].y);
		y[i].y-=2;
	 if(y[i].y==-2)
		y[i].y=0;
	}
	Sleep(100);
}
	return 0;
}

void hidden()//隐藏光标
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    GetConsoleCursorInfo(hOut,&cci);
    cci.bVisible=0;//赋1为显示，赋0为隐藏
    SetConsoleCursorInfo(hOut,&cci);
}






				//游戏函数 


int p=0;

void mapmove(int n)
{

		if(n%20==0)
		{
		int s;                       
		srand(time(NULL));	                  //生成随机数来表示障碍物的随机变化 
		s=rand()%11;
			y[p].m=s;
			y[p].y=70;
			p++;
			if(p==5)
				p=0;
		}
}




void barrier(int x1,int y)				//障碍物 
{
	int i,k;
	for(i=x1;i>=0;i--){
		if(y>=10){
		
		gotoxy(y-10,i);
		printf("■");
	}
		gotoxy(y,i);
		printf("  ");
		}

	for(i=x1+8;i<line;i++){
			if(y>=10){
		
		gotoxy(y-10,i);
		printf("■");
	}
		gotoxy(y,i);
		printf("  ");
		}
}

void gotoxy(int x, int y)				//移动光标 
{
    CONSOLE_SCREEN_BUFFER_INFO    csbiInfo;
    HANDLE    hConsoleOut;
    hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsoleOut,&csbiInfo);
    csbiInfo.dwCursorPosition.X = x;
    csbiInfo.dwCursorPosition.Y = y;
    SetConsoleCursorPosition(hConsoleOut,csbiInfo.dwCursorPosition);
}

