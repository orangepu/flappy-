//FILE */C/CodeBlocksProject/Game_test/Game_test.cpp

# include <stdio.h>
# include <string.h>
# include <windows.h>
# include <conio.h>
# include <time.h>

#define dead 1
#define live 0
#define row 80		//�����ͼ�� 
#define line 20		//�����ͼ�� 
#define EASY 75		// �Ѷ� 
#define NORMAL 50
#define HARD 30
#define PLAYER_POS 20	//��ҳ�ʼ���� 
//����
int play(int n); //��Ϸwִ�к���
void player(int x);  //���Ƶ�����
void printall();	//��ӡȫ����Ϸ���� 
void barrier(int x1,int y);		//�����ϰ��� 
void mapmove(int n);		//��ͼ���ƶ� 
int judge(int x);			//�ж������Ƿ����� 
char map[line][row]={{0}};		//����ȫ����ͼ 
int start();			//��ʼ���� 
void result(int score);		//�������� 
void gotoxy(int x, int y);		//�ƶ���� 
void hidden();				//���ع�� 
struct circlemap{				//ÿ���ϰ��� 
	int m;
	int y;
}y[5]={{0}};

int main()				//������ 
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

void hidden()//���ع��
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    GetConsoleCursorInfo(hOut,&cci);
    cci.bVisible=0;//��1Ϊ��ʾ����0Ϊ����
    SetConsoleCursorInfo(hOut,&cci);
}






				//��Ϸ���� 


int p=0;

void mapmove(int n)
{

		if(n%20==0)
		{
		int s;                       
		srand(time(NULL));	                  //�������������ʾ�ϰ��������仯 
		s=rand()%11;
			y[p].m=s;
			y[p].y=70;
			p++;
			if(p==5)
				p=0;
		}
}




void barrier(int x1,int y)				//�ϰ��� 
{
	int i,k;
	for(i=x1;i>=0;i--){
		if(y>=10){
		
		gotoxy(y-10,i);
		printf("��");
	}
		gotoxy(y,i);
		printf("  ");
		}

	for(i=x1+8;i<line;i++){
			if(y>=10){
		
		gotoxy(y-10,i);
		printf("��");
	}
		gotoxy(y,i);
		printf("  ");
		}
}

void gotoxy(int x, int y)				//�ƶ���� 
{
    CONSOLE_SCREEN_BUFFER_INFO    csbiInfo;
    HANDLE    hConsoleOut;
    hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsoleOut,&csbiInfo);
    csbiInfo.dwCursorPosition.X = x;
    csbiInfo.dwCursorPosition.Y = y;
    SetConsoleCursorPosition(hConsoleOut,csbiInfo.dwCursorPosition);
}

