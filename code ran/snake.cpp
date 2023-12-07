#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <iomanip>
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

void batdau(int &dokho){
	SetColor(13);
	cout<<setw(180)<<"GAME RAN SAN MOI"<<endl<<endl<<endl<<endl;
	SetColor(11);
	cout<<setw(60)<<"Huong dan: Di chuyen bang 4 phim w, a, s, d. Ban se thua khi ran"<<endl;
	cout<<setw(67)<<"cham phai chuong ngai vat hoac cham tuong hoac can duoi."<< endl;
	SetColor(4);
	cout<<setw(20)<<"Luu y: Vui long tat Unikey va Caps Lock truoc khi choi game de co trai nghiem tot nhat !!!"<< endl<<endl;
	SetColor(11);
	cout<<"Co 3 muc do:"<<endl<<endl;
	SetColor(2);
	cout<<"1. De"<<endl;
	SetColor(6);
	cout<<"2. Trung binh"<<endl;
	SetColor(4);
	cout<<"3. Cao"<<endl<<endl;
	SetColor(11);
	cout<<"Chon do kho: ";
	do{
		cin>>dokho;
		if(dokho<1 || dokho>3){
			cout<<"Nhap sai! Vui long nhap lai"<<endl;
			cout<<"Chon do kho: ";
		}else{
			break;
		}
	}while(dokho<1 || dokho>3);
	
	if(dokho==1){
		dokho=300;
	}else if(dokho==2){
		dokho=150;
	}else if(dokho==3){
		dokho=100;
	}
	cout<<"Ban da chon do kho ";
	if(dokho==100){
		cout<<"thap"<<endl; 
	}else if(dokho==150){
		cout<<"trung binh"<<endl;
	}else if(dokho==300){
		cout<<"cao"<<endl;
	}
	cout<<endl<<"Tro choi se bat dau sau 3s !!!"<<endl;
	SetColor(9);
	cout<<setw(16)<<"3\t";
	Sleep(1000);
	cout<<setw(16)<<"2\t";
	Sleep(1000);
	cout<<setw(16)<<"1\t";
	Sleep(250);
	cout<<setw(16)<<".\t";
	Sleep(250);
	cout<<setw(16)<<".\t";
	Sleep(250);
	cout<<setw(16)<<".\t";
	Sleep(250);
	SetColor(7);
	system("cls");
}


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
			SetColor(4);
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
		cout<<"+";
		y++;
		Sleep(10);
	}
	while(x!=100){
		gotoXY(x,y-1);
		cout<<"+";
		x++;
		Sleep(10);
	}
	while(y!=0){
		gotoXY(x,y-1);
		cout<<"+";
		y--;		
		Sleep(10);
	}
	while(x!=10){
		gotoXY(x,y);
		cout<<"+";  
		x--;
		Sleep(10);
	}
	SetColor(7);
	Sleep(300);
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

//	int dokho=0;
//	xoacontro();
//	batdau(dokho);	
//	srand(time(NULL));
//	bool gameover=false;
//	int ToaDoX[100], ToaDoY[100];
//	int x=50, y=13, check=2;
//	int xqua=0, yqua=0;
//	Khung();
//	Khoitaoso_nach(ToaDoX,ToaDoY);
//	vesnake(ToaDoX, ToaDoY);
//	taoqua(ToaDoX, ToaDoY, xqua, yqua);
//	Sleep(1000);
//	while(gameover==false){
//		xoadulieucu(ToaDoX,ToaDoY);
//		if(_kbhit()){
//			char kytu=_getch();
//			if(kytu=='w'&& check != 0){
//				check=1;
//			}else if(kytu=='s' && check != 1){
//				check=0;
//			}else if(kytu=='a' && check != 2){
//				check=3;
//			}else if(kytu=='d' && check != 3){
//				check=2;
//			}
//		}
//		if(check==0){
//			y++;
//		}else if(check==1){
//			y--;
//		}else if(check==2){
//			x++;
//		}else if(check==3){
//			x--;
//		}
//		xulyran(ToaDoX, ToaDoY, x, y, xqua, yqua);
//		gameover=checkdie(ToaDoX, ToaDoY, x, y);
//		Sleep(dokho);
//	}
//	Sleep(300);
//	system("cls");	
	bool gameover=true;
	if(gameover==true){
		SetColor(4);	
		gotoXY(55,10);
		cout<<"Gameover";
	}
	Sleep(2000);
	gotoXY(10,1);
	cout<<"Bam phim 1 de choi lai"<<endl;
	cout<<"Bam phim 'x' de thoat";
	if(_getch()){
		char out;
		if(out=='1'){
			
		}
	}
	_getch();
    return 0;
}


// De day bao gio hieu giuc thi lam tiep
/*class SnakeGame {
private:
    int sl;
    int ToaDoX[100], ToaDoY[100];
    int xqua, yqua;
public:
    SnakeGame() {
        sl = 3;
    }

    void gotoXY(int x, int y) {
        HANDLE hConsoleOutput;
        COORD Cursor_an_Pos = { x, y };
        hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
    }

    void SetColor(WORD color) {
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

    void xoacontro() {
        CONSOLE_CURSOR_INFO Info;
        Info.bVisible = FALSE;
        Info.dwSize = 20;
        SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
    }

    void vesnake() {
        for (int i = 0; i < sl; i++) {
            gotoXY(ToaDoX[i], ToaDoY[i]);
            if (i == 0) {
                SetColor(10);
                cout << "O";
                SetColor(7);
            }
            else {
                cout << "o";
            }
        }
    }

    void xoadulieucu() {
        for (int i = 0; i < sl; i++) {
            gotoXY(ToaDoX[i], ToaDoY[i]);
            cout << " ";
        }
    }

    bool checkrananqua(int xqua, int yqua, int x0, int y0) {
        if (x0 == xqua && y0 == yqua) {
            return true;
        }
        return false;
    }

    bool checktrung(int xqua, int yqua) {
        for (int i = 0; i < sl; i++) {
            if (ToaDoX[i] == xqua && ToaDoY[i] == yqua) {
                return true;
            }
        }
        return false;
    }

    void taoqua() {
        int i = rand() % (15 - 1 + 1) + 1;
        SetColor(i);
        do {
            xqua = rand() % (99 - 11 + 1) + 11;
            yqua = rand() % (25 - 2 + 1) + 2;
        } while (checktrung(xqua, yqua) == true);
        gotoXY(xqua, yqua);
        cout << "*";
        SetColor(7);
    }

    void them(int gt) {
        for (int i = sl; i > 0; i--) {
            ToaDoX[i] = ToaDoX[i - 1];
            ToaDoY[i] = ToaDoY[i - 1];
        }
        ToaDoX[0] = gt;
        sl++;
    }

    void xoa(int vt) {
        for (int i = vt; i < sl; i++) {
            ToaDoX[i] = ToaDoX[i + 1];
            ToaDoY[i] = ToaDoY[i + 1];
        }
        sl--;
    }

    void xulyran(int x, int y) {
        them(x);
        them(y);

        if (checkrananqua(xqua, yqua, ToaDoX[0], ToaDoY[0]) == false) {
            xoa(sl - 1);
        }
        else {
            taoqua();
        }
        vesnake();
    }

    void Khoitaoso_nach() {
        int x = 50, y = 13;

        for (int i = 0; i < sl; i++) {
            ToaDoX[i] = x;
            ToaDoY[i] = y;
            x--;
        }
    }

    void Khung() {
        int x = 10, y = 0;
        SetColor(11);
        while (y != 28) {
            gotoXY(x, y);
            cout << "|";
            y++;
        }
        while (x != 100) {
            gotoXY(x, y - 1);
            cout << "-";
            x++;
        }
        while (y != 0) {
            gotoXY(x, y - 1);
            cout << "|";
            y--;
        }
        while (x != 10) {
            gotoXY(x, y);
            cout << "-";
            x--;
        }
        SetColor(7);
    }

    bool checkchamtuong(int x0, int y0) {
        if (y0 == 0 || y0 == 26 || x0 == 10 || x0 == 100) {
            return true;
        }
        else return false;
    }

    bool checkrancan() {
        for (int i = 1; i < sl; i++) {
            if (ToaDoX[0] == ToaDoX[i] && ToaDoY[0] == ToaDoY[i]) {
                return true;
            }
        }
        return false;
    }

    bool checkdie(int x, int y) {
        bool kt1 = checkchamtuong(x, y);
        bool kt2 = checkrancan();
        if (kt1 == true || kt2 == true) {
            return true;
        }
        return false;
    }

    void play() {
        xoacontro();
        Khoitaoso_nach();
        taoqua();
        vesnake();

        int x = -1, y = 0;
        int x0 = ToaDoX[0], y0 = ToaDoY[0];
        int t = 100;
        int score = 0;

        while (true) {
            if (_kbhit()) {
                int key = _getch();
                if (key == 'A' || key == 'a') {
                    if (x != 1) {
                        x = -1; y = 0;
                    }
                }
                else if (key == 'D' || key == 'd') {
                    if (x != -1) {
                        x = 1; y = 0;
                    }
                }
                else if (key == 'W' || key == 'w') {
                    if (y != 1) {
                        x = 0; y = -1;
                    }
                }
                else if (key == 'S' || key == 's') {
                    if (y != -1) {
                        x = 0; y = 1;
                    }
                }
            }

            if (t == 100) {
                x0 = ToaDoX[0];
                y0 = ToaDoY[0];
                if (checkdie(x0 + x, y0 + y) == true) {
                    break;
                }
                xulyran(x0 + x, y0 + y);
                t = 0;
            }
            else {
                t++;
            }

            Sleep(10);
        }

        gotoXY(50, 14);
        cout << "Game Over! Your score: " << score << endl;
    }
};*/

