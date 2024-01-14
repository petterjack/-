#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<conio.h>//接受键盘的输入
#include<stdbool.h>//使用返回值bool类型的函数
#include<easyx.h>
#include<windows.h>//下面这三个都是为了实现播放音乐功能而定义的头文件
#include<Mmsystem.h>
#pragma comment(lib,"winmm.lib")
//全局变量 
ExMessage msg = { 0 };
int level = 0;//表示关卡
bool isArea(int mx, int my, int x, int y, int w, int h) {
	if (mx > x && mx<x + w && my>y && my < y + h) {
		return 1;
	}
	return 0;
}//判断你鼠标是否在你绘制的按键范围内
bool button(int x, int y, int w, int h, const char* text) {
	//设置一个按钮，并且判断是否被访问
	if (isArea(msg.x, msg.y, x, y, w, h))
		setfillcolor(RGB(66, 66, 66));
	else
		setfillcolor(RGB(46, 46, 46));
	//绘制按钮

	fillrectangle(x, y, x + w, y + h);
	//绘制文本
	int hspace = (w - textwidth(text)) / 2;
	int vspace = (h - textheight(text)) / 2;
	settextcolor(WHITE);
	settextstyle(20, 0, "黑体");
	outtextxy(x + hspace, y + vspace, text);
	//判断是否被点击
	if (msg.message == WM_LBUTTONDOWN && isArea(msg.x, msg.y, x, y, w, h)) {
		return 1;
	}
	return 0;
}//绘制按钮并判断被点击了
//黑体白色
bool buttontwo(int x, int y, int w, int h, const char* text) {
	//设置一个按钮，并且判断是否被访问
	if (isArea(msg.x, msg.y, x, y, w, h))
		setfillcolor(BLUE);
	else
		setfillcolor(BROWN);
	//绘制按钮

	fillrectangle(x, y, x + w, y + h);
	//绘制文本
	int hspace = (w - textwidth(text)) / 2;
	int vspace = (h - textheight(text)) / 2;
	settextcolor(YELLOW);
	settextstyle(20, 0, "华文行楷");
	outtextxy(x + hspace, y + vspace, text);
	//判断是否被点击
	if (msg.message == WM_LBUTTONDOWN && isArea(msg.x, msg.y, x, y, w, h)) {
		return 1;
	}
	return 0;
}//绘制按钮并判断被点击了
//行楷蓝色
int i, k;//在其他函数出现循环，循环里面用
enum elements{ space, wall, dest, box, player};//枚举，使用文字代替数字方便后面表示
int map[3][10][10] = {
{
{7,7,7,7,7,7,7,7,7,7},
{7,7,7,1,1,1,7,7,7,7},
{7,7,7,1,2,1,1,1,1,7},
{7,1,1,1,3,3,0,2,1,7},
{7,1,2,3,4,0,1,1,1,7},
{7,1,1,1,1,3,1,7,7,7},
{7,7,7,7,1,2,1,7,7,7},
{7,7,7,7,1,1,1,7,7,7},
{7,7,7,7,7,7,7,7,7,7},
{7,7,7,7,7,7,7,7,7,7},
},

{
{8,8,8,8,8,8,8,8,8,8},
{8,8,8,8,8,8,8,8,8,8},
{8,8,8,1,1,1,1,1,1,8},
{8,1,1,1,0,0,0,0,1,8},
{1,1,2,0,3,1,0,0,1,1},
{1,2,2,3,0,3,0,0,4,1},
{1,2,2,0,3,0,3,0,1,1},
{1,1,1,1,1,1,0,0,1,8},
{8,8,8,8,8,8,1,1,1,8},
{8,8,8,8,8,8,8,8,8,8},
},
{
{0,0,1,1,0,0,1,1,0,0},
{0,1,0,0,1,1,0,0,1,0},
{1,0,0,0,0,0,0,0,0,1},
{1,0,0,3,0,0,3,3,0,1},
{1,2,2,3,4,0,0,2,2,1},
{1,2,0,3,1,0,0,3,2,1},
{0,1,0,0,1,0,0,0,1,0},
{0,0,1,0,0,0,0,1,0,0},
{0,0,0,1,0,0,1,0,0,0},
{0,0,0,0,1,1,0,0,0,0},
}
};//第一关地图
//空地0,space 墙1,wall 目的地2,dest 箱子3,box 玩家4,player 箱子在目的地5,box+dest 玩家在目的地6player+dest(图片和玩家的图片一样)
IMAGE img_all[12];//保存需要用到的图片，总共11个，space, wall, dest, box, player，box+dest，player+dest,7草原地图，8岩浆地图，11代表冰原
//----------------------------------service---------------------------------------------

//--------------------------函数声明部分----------------------------------------------------
/*
负责人：小手冰凉
功能：打印菜单界面包含开始游戏，游戏说明，设置，退出游戏四个按钮
点击开始游戏可以进入gameview()，点击游戏说明可以进入游戏说明gamerule()
点击退出游戏可以退出程序，点击设置进入gameset()
参数：void
返回值：void
*/void menuview();



/*
负责人：白枫
功能：展示游戏规则以及开发人员，含有返回首页按钮，点击可以返回首页menuview()
参数：void
返回值：void
*/ void gamerule();



/*
负责人:徐大铁
功能：打印设置界面，含有音乐开关和返回首页按钮，点击音乐会播放音乐，点击返回首页按钮会返回首页menuview()
参数：void
返回值：void
*/ void gameset();


/*
负责人:白枫
功能：加载游戏地图界面用到的的图片，loadimage加载地图界面图片
参数：void
返回值：void
*/ void pictureload();



/*
负责人:白枫
功能：打印游戏界面，并含有按键返回首页，点击可进入游戏菜单menuview()
参数：void
返回值：void
*/ void mapdraw();



/*
负责人:白枫
功能：判断游戏是否赢了，赢了就进入游戏胜利界面gamewinprint()
参数：void
返回值：true or false
*/ bool wingame();



/*
负责人:永琪
功能:_getch()接收玩家按下的键，玩家按下四个键可以向对应位置移动
参数:void
返回值:void
*/ void gamemove();



/*
负责人:永琪
功能:打印游戏胜利界面，含有返回主页按钮点击可以返回菜单menuview()
参数:void
返回值:void
*/ void gamewinprint();



/*
负责人:枫叶
功能:介绍本游戏发生的背景故事,点击继续切换下一张图片，最后一张图片点击返回首页可以回到菜单；
参数:void
返回值:void
*/ void gamestory();



 
/*
负责人:白枫
功能:
while(1)
	{pictureload()；//加载图片
		mapdraw();
		if (wingame())//判断是否胜利，返回值为true,如赢了打印胜利界面
		{
		if(level>2)
		关卡大于2的时候也就是闯关到最后一关的时候会打印胜利界面
		并播放胜利音乐
		gamewinprint();
		}
		gamemove();否则继续移动

}
参数:void
返回值:void
*/
void gameview();





//-------------------------------------------------------主函数-----------------------------------------------------------


int main()
{
	initgraph(10 * 75, 10 * 75);//加载easyx界面
	pictureload();
	BeginBatchDraw();
	menuview();
	EndBatchDraw();
	gameview();
	return 0;
}


//-------------------------------------------------------函数定义部分-----------------------------------------------------
void menuview() {
	IMAGE img_start;
	loadimage(&img_start, "./images/推箱子开始界面1.jpg",750,750);
	putimage(0, 0, &img_start);
	setbkmode(TRANSPARENT);
	while (1) {
		peekmessage(&msg, EX_MOUSE);
		BeginBatchDraw();
		if (button(295, 350, 150, 30, "开始游戏")) {
			mciSendString("open ./images/musci_6.mp3 alias f", NULL, 0, NULL);
			mciSendString("play f from 0", NULL, 0, NULL);//原神启动音效
			break;
		}
		if (buttontwo(295, 400, 150, 30, "游戏说明")) {
			mciSendString("open ./images/musci_8.mp3 alias h", NULL, 0, NULL);
			mciSendString("play h from 0", NULL, 0, NULL);//原来，你也玩原神
			gamerule();
		}
		if (buttontwo(295, 450, 150, 30, "游戏设置")) {
			mciSendString("open ./images/musci_9.mp3 alias k", NULL, 0, NULL);
			mciSendString("play k from 0", NULL, 0, NULL);//原来，你也玩原神
			gameset();
		}
		if (buttontwo(295, 500, 150, 30, "游戏背景")) {
			mciSendString("open ./images/musci_8.mp3 alias h", NULL, 0, NULL);
			mciSendString("play h from 0", NULL, 0, NULL);//原来，你也玩原神
			gamestory();
		}
		if (button(295, 550, 150, 30, "退出游戏")) {
			exit(0);
		}
		EndBatchDraw();
	}

}
void pictureload()
{
	for (i = 0; i < 12; i++)
	{
		char file[40] = "";
		sprintf(file, "./images/%d.bmp", i);
		loadimage(img_all + i, file, 64, 64);
	}
}
void mapdraw()
{
	
	for(i = 0; i < 10; i++)
	{   
		for (k = 0; k < 10; k++)
		{
			int x =( k+1)* 64; int  y = (i+1) * 64;//让地图在屏幕中间打印
			if (level == 0)//第1关
			{
				switch (map[level][i][k])
				{
				case space: putimage(x, y, img_all); break;
				case wall:putimage(x, y, img_all + 1); break;
				case dest:putimage(x, y, img_all + 2); break;
				case box:putimage(x, y, img_all + 3); break;
				case player:putimage(x, y, img_all + 4); break;
				case player + dest:putimage(x, y, img_all+4); break;
				case box + dest:putimage(x, y, img_all + 5); break;
				case 7:putimage(x, y, img_all + 7); break;
				
				}
			}
				if (level == 1)//第2关
				{
					switch (map[level][i][k])
					{
					case space: putimage(x, y, img_all); break;
					case wall:putimage(x, y, img_all + 1); break;
					case dest:putimage(x, y, img_all + 2); break;
					case box:putimage(x, y, img_all + 3); break;
					case player:putimage(x, y, img_all + 9); break;
					case player + dest:putimage(x, y, img_all+9); break;
					case box + dest:putimage(x, y, img_all + 10); break;
					case 8:putimage(x, y, img_all + 8); break;
					}
				}
					if (level == 2)//第3关
					{
						switch (map[level][i][k])
						{
						case space: putimage(x, y, img_all+11); break;
						case wall:putimage(x, y, img_all + 1); break;
						case dest:putimage(x, y, img_all + 2); break;
						case box:putimage(x, y, img_all + 3); break;
						case player:putimage(x, y, img_all + 10); break;
						case player + dest:putimage(x, y, img_all+10); break;
						case box + dest:putimage(x, y, img_all + 9); break;
						}
			        }
		   }
	     }
	
}


void gamemove()
{//找到玩家
	
	for (i = 0; i < 10; i++)
	{
		for (k = 0; k < 10; k++)
		{
			if (map[level][i][k] == player|| map[level][i][k] ==player+dest)
			{
				goto end;
			}
		}
	}

end:;
	char ch = _getch();
		
	switch (ch)
	{
	case 72:
	case'w':
	case'W'://不同关卡播放不同的音效，其他几个同理
		if (level == 0)
		{
			mciSendString("open ./images/musci_4.mp3 alias d", NULL, 0, NULL);
			mciSendString("play d from 0", NULL, 0, NULL);
		}//实现人物移动的音效问题 
		if (level == 1)
		{
			mciSendString("open ./images/musci_5.mp3 alias e", NULL, 0, NULL);
			mciSendString("play e from 0", NULL, 0, NULL);
		}
		if (level == 2)
		{
			mciSendString("open ./images/musci_7.mp3 alias g", NULL, 0, NULL);
			mciSendString("play g from 0", NULL, 0, NULL);
		}
		if (map[level][i - 1][k] == space || map[level][i - 1][k] == dest)
		{
			map[level][i - 1][k] += player;
			map[level][i][k] -= player;
			
		}
		else if (map[level][i - 1][k] == box || map[level][i - 1][k] == box + dest)
		{
			if (map[level][i - 2][k] == space || map[level][i - 2][k] == dest)
			{
				map[level][i - 2][k] += box;//箱子移动到前面一个位置
				map[level][i - 1][k] = map[level][i - 1][k] - box + player;//让箱子原来的位置减去箱子加上玩家
				map[level][i][k] -= player;//玩家原来的位置玩家消失
			}
		}
		
		break;
	case 80:
	case's':
	case'S':if (level == 0)
	{
		mciSendString("open ./images/musci_4.mp3 alias d", NULL, 0, NULL);
		mciSendString("play d from 0", NULL, 0, NULL);
	}//实现人物移动的音效问题 
	if (level == 1)
	{
		mciSendString("open ./images/musci_5.mp3 alias e", NULL, 0, NULL);
		mciSendString("play e from 0", NULL, 0, NULL);
	}
	if (level == 2)
	{
		mciSendString("open ./images/musci_7.mp3 alias g", NULL, 0, NULL);
		mciSendString("play g from 0", NULL, 0, NULL);
	}
		if (map[level][i + 1][k] == space || map[level][i + 1][k] == dest)
	{
		map[level][i + 1][k] += player;
		map[level][i][k] -= player;
	}
		   else if (map[level][i + 1][k] == box || map[level][i + 1][k] == box + dest)
	{
		if (map[level][i + 2][k] == space || map[level][i + 2][k] == dest)
		{
			map[level][i + 2][k] += box;//箱子移动到前面一个位置
			map[level][i + 1][k] = map[level][i + 1][k] - box + player;//让箱子原来的位置减去箱子加上玩家
			map[level][i][k] -= player;//玩家原来的位置玩家消失
		}
	}
		   break;
	case 75:
	case'a':
	case'A':if (level == 0)
	{
		mciSendString("open ./images/musci_4.mp3 alias d", NULL, 0, NULL);
		mciSendString("play d from 0", NULL, 0, NULL);
	}//实现人物移动的音效问题 
		   if (level == 1)
		   {
			   mciSendString("open ./images/musci_5.mp3 alias e", NULL, 0, NULL);
			   mciSendString("play e from 0", NULL, 0, NULL);
		   }
		   if (level == 2)
		   {
			   mciSendString("open ./images/musci_7.mp3 alias g", NULL, 0, NULL);
			   mciSendString("play g from 0", NULL, 0, NULL);
		   }
		if (map[level][i][k - 1] == space || map[level][i][k - 1] == dest)
	{
		map[level][i][k - 1] += player;
		map[level][i][k] -= player;
	}
		   else if (map[level][i][k - 1] == box || map[level][i][k - 1] == box + dest)
	{
		if (map[level][i][k - 2] == space || map[level][i][k - 2] == dest)
		{
			map[level][i][k - 2] += box;//箱子移动到前面一个位置
			map[level][i][k - 1] = map[level][i][k - 1] - box + player;//让箱子原来的位置减去箱子加上玩家
			map[level][i][k] -= player;//玩家原来的位置玩家消失
		}
	}
		   break;
	case 77:
	case'd':
	case'D':if (level == 0)
	{
		mciSendString("open ./images/musci_4.mp3 alias d", NULL, 0, NULL);
		mciSendString("play d from 0", NULL, 0, NULL);
	}//实现人物移动的音效问题 
		   if (level == 1)
		   {
			   mciSendString("open ./images/musci_5.mp3 alias e", NULL, 0, NULL);
			   mciSendString("play e from 0", NULL, 0, NULL);
		   }
		   if (level == 2)
		   {
			   mciSendString("open ./images/musci_7.mp3 alias g", NULL, 0, NULL);
			   mciSendString("play g from 0", NULL, 0, NULL);
		   }
		if (map[level][i][k + 1] == space || map[level][i][k + 1] == dest)
	{
		map[level][i][k + 1] += player;
		map[level][i][k] -= player;
	}
		   else if (map[level][i][k + 1] == box || map[level][i][k + 1] == box + dest)
	{
		if (map[level][i][k + 2] == space || map[level][i][k + 2] == dest)
		{
			map[level][i][k + 2] += box;//箱子移动到前面一个位置
			map[level][i][k + 1] = map[level][i][k + 1] - box + player;//让箱子原来的位置减去箱子加上玩家
			map[level][i][k] -= player;//玩家原来的位置玩家消失
		}
	}
		break;
	}
}




void gameview()
{
	IMAGE img_start;
	loadimage(&img_start, "./images/推箱子开始界面1.jpg", 750, 750);
	putimage(0, 0, &img_start);
	while (true)
	{
		mapdraw();
		
		if (wingame())
		{
			level++;
			if (level > 2)
			{
				mciSendString("open ./images/musci_10.mp3 alias l", NULL, 0, NULL);
				mciSendString("play l from 0", NULL, 0, NULL);//胜利音效
				gamewinprint();
				
			}
		}
		gamemove();
	}
	
}



bool wingame()
{
	for (int i = 0; i < 10; i++)
	{
		for (int k = 0; k < 10; k++)
		{
			if (map[level][i][k] == box)
			{
				return false;
			}
		}

	}

	return true;
}



void gamewinprint()
{
	IMAGE img_end;
	loadimage(&img_end, "./images/OIP-C.jpg",750,750);
	putimage(0, 0, &img_end);
	while (1) {
		peekmessage(&msg, EX_MOUSE);
		BeginBatchDraw();
		if (button(295, 350, 150, 70, "退出游戏")) {
			 goto end5;
		}
		EndBatchDraw();
	}
end5: exit(0);
}



void gameset() {
	IMAGE img_rules;
	loadimage(&img_rules, "./images/set.png", 10 * 75, 10 * 75);
	putimage(0, 0, &img_rules);//绘制背景
	int x = 250, y1 = 100, y2 = 250, y3 = 400;
	int wx = 250, wy = 100;
	int m = 1, n = 1;
	int q = 1;
	while (true) {
		msg.message = 0;
		peekmessage(&msg, EX_MOUSE);
		BeginBatchDraw();
		if (button(x, y1, wx, wy, "返回首页")) {
			menuview();
			break;
		}
		if (button(x, y2, wx, wy, "音乐1开/关") && m == 1) {
			mciSendString("open ./images/musci_1.mp3 alias a", NULL, 0, NULL);
			mciSendString("play a ", NULL, 0, NULL);
			m = 0;
			msg.message = 0;
		}
		if (button(x, y2, wx, wy, "音乐1开/关") && m == 0) {
			mciSendString("stop a", NULL, 0, NULL);
			m = 1;
			msg.message = 0;
		}
		if (buttontwo(x, y3, wx, wy, "音乐2开/关") && n == 1) {
			mciSendString("open ./images/musci_2.mp3 alias b", NULL, 0, NULL);
			mciSendString("play b", NULL, 0, NULL);
			n = 0;
			msg.message = 0;
		}
		if (buttontwo(x, y3, wx, wy, "音乐2开/关") && n == 0) {
			mciSendString("stop b", NULL, 0, NULL);
			n = 1;
			msg.message = 0;
		}
		if (buttontwo(x,550, wx, wy, "音乐3开/关") && q == 1) {
			mciSendString("open ./images/musci_3.mp3 alias c", NULL, 0, NULL);
			mciSendString("play c", NULL, 0, NULL);
			q = 0;
			msg.message = 0;
		}
		if (buttontwo(x,550, wx, wy, "音乐3开/关") && q == 0) {
			mciSendString("stop c", NULL, 0, NULL);
			q= 1;
			msg.message = 0;
		}
		EndBatchDraw();
	}
	
}



void gamerule() {
	IMAGE img_rules;
	cleardevice();
	loadimage(&img_rules, "./images/pi.png", 10 * 75, 10 * 75);
	putimage(0, 0, &img_rules);//绘制背景
	int x = 400, y = 500;
	int wx = 200, wy = 100;
	while (true) {
		peekmessage(&msg, EX_MOUSE);
		BeginBatchDraw();
		if (button(x, y, wx, wy, "返回首页")) {
			menuview();
			break;
		}
		EndBatchDraw();
		
	}
	
}




void gamestory()
{
	IMAGE img_a;
	loadimage(&img_a, "./images/0.jpg",750,750);
	putimage(0, 0, &img_a);
	IMAGE img[5];
	for (i = 1; i < 5; i++)
	{
		char file[40] = "";
		sprintf(file, "./images/%d.jpg", i);
		loadimage(img + i, file, 750, 750);
	}
	while (1) {
		peekmessage(&msg, EX_MOUSE);

		BeginBatchDraw();
		
		if (button(295, 550, 150, 30, "继续")) {
			
				putimage(0, 0, img + 1);
				msg.message = 0;	
				goto two;
		}
		EndBatchDraw();
	}

two:;
	cleardevice();
	putimage(0, 0, img + 1);
	while (1) {
		peekmessage(&msg, EX_MOUSE);
		BeginBatchDraw();

		if (button(295, 550, 150, 30, "继续")) {

			putimage(0, 0, img + 2);
			msg.message = 0;
			goto three;
			
		}
		EndBatchDraw();
	}
three:;
	cleardevice();
	putimage(0, 0, img + 2);
	while (1) {
		peekmessage(&msg, EX_MOUSE);
		BeginBatchDraw();

		if (button(295, 550, 150, 30, "继续")) {

			putimage(0, 0, img + 3);
			msg.message = 0;
			goto four;
		}
		EndBatchDraw();
	}
four:;
	cleardevice();
	putimage(0, 0, img + 3);
	while (1) {
		peekmessage(&msg, EX_MOUSE);
		BeginBatchDraw();

		if (button(295, 550, 150, 30, "继续")) {

			putimage(0, 0, img + 4);
			msg.message = 0;
			goto five;

		}
		EndBatchDraw();
	}
five:;
	cleardevice();
	putimage(0, 0, img + 4);
	while (1) {
		peekmessage(&msg, EX_MOUSE);
		BeginBatchDraw();
		if (button(295, 550, 150, 30, "返回首页")) {
			putimage(0, 0, img + 5);
			msg.message = 0;
			goto six;
		}
		EndBatchDraw();
	}
six:menuview();
}