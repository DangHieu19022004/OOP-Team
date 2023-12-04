#include <iostream>
#include <stdio.h>
#include <conio.h>
#include<ctime> 
#include <windows.h>
#define KEY_NONE	-1
using namespace std;
//viet ham ho tro


void gotoXY(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

void SetColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
//
//
// code ran
int sl=3;

void xoacontro()
{
 CONSOLE_CURSOR_INFO Info;
 Info.bVisible = FALSE;
 Info.dwSize = 20;
 SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

void vesnake(int ToaDoX[], int ToaDoY[]){
	for(int i=0; i<sl; i++){
		gotoXY(ToaDoX[i], ToaDoY[i]);
		if(i==0){
			SetColor(10);
			cout<<"O";
			SetColor(7);
		}
		else{
			cout<<"o";
		}
	}
}

void xoadulieucu(int ToaDoX[], int ToaDoY[]){
	for(int i=0; i<sl; i++){
		gotoXY(ToaDoX[i], ToaDoY[i]);
		cout<<" ";
	}
}

bool checkrananqua(int xqua, int yqua, int x0, int y0){
	if(x0==xqua && y0==yqua){
		return true;
	}
	return false;
}

bool checktrung(int ToaDoX[], int ToaDoY[], int xqua, int yqua){
	for(int i=0; i<sl; i++){
		if(ToaDoX[i]==xqua && ToaDoY[i]==yqua){
			return true;
		}
	}
	return false;
}

void taoqua(int ToaDoX[], int ToaDoY[], int &xqua, int &yqua){
	int i=rand()%(15-1+1)+1;
	SetColor(i);
	do{
		xqua = rand() % (99-11+1) + 11;
		yqua = rand() % (25-2+1) + 2;
	}while(checktrung(ToaDoX, ToaDoY, xqua, yqua)==true);
	gotoXY(xqua, yqua);	
	cout<<"*";
	SetColor(7);
}

void them(int a[], int gt){
	for(int i = sl; i>0; i--){
		a[i]=a[i-1];
	}
	a[0]=gt;
	sl++;
}

void xoa(int a[], int vt){
	for(int i=vt; i<sl; i++){
		a[i]=a[i+1];
	}
	sl--;
}

void xulyran(int ToaDoX[], int ToaDoY[], int x, int y, int &xqua, int &yqua){
	//
	them(ToaDoX, x);
	them(ToaDoY, y);
	
	if(checkrananqua(xqua, yqua, ToaDoX[0], ToaDoY[0]) == false){
		xoa(ToaDoX, sl-1);
		xoa(ToaDoY, sl-1);	
	}else{
		taoqua(ToaDoX, ToaDoY, xqua, yqua);
	}
	vesnake(ToaDoX,ToaDoY);
	
}

void Khoitaoso_nach(int ToaDoX[], int ToaDoY[]){
	int x=50, y=13;
	
	for(int i=0; i<sl; i++){
		ToaDoX[i]=x; 
		ToaDoY[i]=y;	
		x--;
	}
}


void Khung(){
	int x=10, y=0;
	SetColor(11);
	while(y!=28){
		gotoXY(x,y);
		cout<<"|";
		y++;
	}
	while(x!=100){
		gotoXY(x,y-1);
		cout<<"-";
		x++;
	}
	while(y!=0){
		gotoXY(x,y-1);
		cout<<"|";
		y--;		
	}
	while(x!=10){
		gotoXY(x,y);
		cout<<"-";  
		x--;
	}
	SetColor(7);
}

bool checkchamtuong(int x0, int y0){
	if(y0==0 || y0==26 || x0==10 || x0==100){
		return true;
	}
	else return false;
}

bool checkrancan(int ToaDoX[], int ToaDoY[]){
	for(int i=1; i<sl; i++){
		if(ToaDoX[0]==ToaDoX[i] && ToaDoY[0]==ToaDoY[i]){
			return true;
		}
	}
	return false;
}

bool checkdie(int ToaDoX[], int ToaDoY[], int x, int y){
	bool kt1=checkchamtuong(x,y);
	bool kt2=checkrancan(ToaDoX,ToaDoY);
	if(kt1 == true || kt2 ==true){
		return true;
	}
	return false;
}

int main() {
	srand(time(NULL));
	bool gameover=false;
	xoacontro();
	int ToaDoX[100], ToaDoY[100];
	int x=50, y=13, check=2;
	int xqua=0, yqua=0;
	Khung();
	Khoitaoso_nach(ToaDoX,ToaDoY);
	vesnake(ToaDoX, ToaDoY);
	taoqua(ToaDoX, ToaDoY, xqua, yqua);
	while(gameover==false){
		xoadulieucu(ToaDoX,ToaDoY);
		if(_kbhit()){
			char kytu=_getch();
			if(kytu=='w' && check != 0){
				check=1;
			}else if(kytu=='s' && check != 1){
				check=0;
			}else if(kytu=='a' && check != 2){
				check=3;
			}else if(kytu=='d' && check != 3){
				check=2;
			}
		}
		if(check==0){
			y++;
		}else if(check==1){
			y--;
		}else if(check==2){
			x++;
		}else if(check==3){
			x--;
		}
		xulyran(ToaDoX, ToaDoY, x, y, xqua, yqua);
		gameover=checkdie(ToaDoX, ToaDoY, x, y);
		Sleep(150);
	}
	_getch();
    return 0;
}

