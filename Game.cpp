// Game.cpp
#include "Game.h"
using namespace std;

Game::Game() : dokho(0), sl(3), x(50), y(13), check(2), xqua(0), yqua(0) {}

void Game::batdau() {
    SetColor(14);
    cout << setw(190) << "----- GAME RAN SAN MOI -----" << endl << endl << endl << endl;
    SetColor(11);
    cout << setw(60) << "Huong dan: Di chuyen bang 4 phim w, a, s, d. Ban se thua khi ran" << endl;
    cout << setw(67) << "cham phai chuong ngai vat hoac cham tuong hoac can duoi." << endl;
    SetColor(4);
    cout << setw(20) << "Luu y: Vui long tat UNIKEY va CAPS LOCK truoc khi choi game de co trai nghiem tot nhat !!!" << endl << endl;
    SetColor(11);
    cout << "Co 3 muc do:" << endl << endl;
    SetColor(2);
    cout << "1. DE" << endl;
    SetColor(6);
    cout << "2. TRUNG BINH" << endl;
    SetColor(4);
    cout << "3. CAO" << endl << endl;
    SetColor(11);
    cout << "Chon do kho: ";
    bool nhapdung = false;
    do {
        cin >> dokho;
        if (dokho < 1 || dokho > 3) {
            cout << "Nhap sai! Vui long nhap lai" << endl;
            cin.clear(); 
            cin.ignore();
            cout << "Chon do kho: ";
        }
        else {
            nhapdung = true;
        }
    } while (!nhapdung);

    if (dokho == 1) {
        dokho = 300;
    }
    else if (dokho == 2) {
        dokho = 150;
    }
    else if (dokho == 3) {
        dokho = 100;
    }
    cout << "Ban da chon do kho: " << endl << endl;
    if (dokho == 100) {
        SetColor(4);
        cout << "---- CAO ----" << endl;
    }
    if (dokho == 150) {
        SetColor(6);
        cout << "---- TRUNG BINH ----" << endl;
    }
    if (dokho == 300) {
        SetColor(2);
        cout << "---- THAP ----" << endl;
    }
    SetColor(9);
    cout << "\nTro choi se bat dau sau giay lat" << endl << endl;
    SetColor(9);
    cout << setw(16) << "3\t";
    Sleep(1000);
    cout << setw(16) << "2\t";
    Sleep(1000);
    cout << setw(16) << "1\t";
    Sleep(250);
    cout << setw(16) << ".\t";
    Sleep(250);
    cout << setw(16) << ".\t";
    Sleep(250);
    cout << setw(16) << ".\t";
    Sleep(250);
    SetColor(7);
    system("cls");
}

void Game::gotoXY(int x, int y) {
    HANDLE hConsoleOutput;
    COORD Cursor_an_Pos = { x, y };
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

void Game::SetColor(WORD color) {
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

void Game::xoacontro() {
    CONSOLE_CURSOR_INFO Info;
    Info.bVisible = FALSE;
    Info.dwSize = 20;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

void Game::vesnake() {
    for (int i = 0; i < sl; i++) {
        gotoXY(ToaDoX[i], ToaDoY[i]);
        if (i == 0) {
            SetColor(4);
            cout << "O";
            SetColor(7);
        }
        else {
            cout << "o";
        }
    }
}

void Game::xoadulieucu() {
    for (int i = 0; i < sl; i++) {
        gotoXY(ToaDoX[i], ToaDoY[i]);
        cout << " ";
    }
}

bool Game::checkrananqua(int xqua, int yqua, int x0, int y0) {
    if (x0 == xqua && y0 == yqua) {
        return true;
    }
    return false;
}

bool Game::checktrung(int xqua, int yqua) {
    for (int i = 0; i < sl; i++) {
        if (ToaDoX[i] == xqua && ToaDoY[i] == yqua) {
            return true;
        }
    }

    for (int i = 0; i < 60; i++) {
        if (ChuongNgaiX[i] == xqua && ChuongNgaiY[i] == yqua) {
            return true;
        }
    }
    return false;
}

void Game::taoqua() {
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

void Game::them(int a[], int gt) {
    for (int i = sl; i > 0; i--) {
        a[i] = a[i - 1];
    }
    a[0] = gt;
    sl++;
}

void Game::xoa(int a[], int vt) {
    for (int i = vt; i < sl; i++) {
        a[i] = a[i + 1];
    }
    sl--;
}

void Game::xulyran() {
    them(ToaDoX, x);
    them(ToaDoY, y);
    
    if (checkrananqua(xqua, yqua, ToaDoX[0], ToaDoY[0]) == false) {
        xoa(ToaDoX, sl - 1);
        xoa(ToaDoY, sl - 1);
        }
    else {
        taoqua();
    }
    vesnake();
}
void Game::Khoitaoso_nach() {
    srand(time(NULL));

    int startX = rand() % (80 - 12 + 1) + 12;
    int startY = rand() % (23 - 3 + 1) + 3;

    for (int i = 0; i < sl; i++) {
        ToaDoX[i] = startX;
        ToaDoY[i] = startY;
        x--;
    }
}

void Game::Khung() {
    int x = 10, y = 0;
    SetColor(11);
    while (y != 28) {
        gotoXY(x, y);
        cout << "x";
        y++;
        Sleep(10);
    }
    while (x != 100) {
        gotoXY(x, y - 1);
        cout << "x";
        x++;
        Sleep(10);
    }
    while (y != 0) {
        gotoXY(x, y - 1);
        cout << "x";
        y--;
        Sleep(10);
    }
    while (x != 10) {
        gotoXY(x, y);
        cout << "x";
        x--;
        Sleep(10);
    }
    SetColor(6);
    Sleep(300);
}

void Game::Chuongngai() {
    int x1 = 20, y1 = 8;
    for (int i = 0; i < 3; i++) {
        ChuongNgaiX[i] = x1;
        ChuongNgaiY[i] = y1;
        y1--;
    }
    for (int i = 3; i < 15; i++) {
        ChuongNgaiX[i] = x1;
        ChuongNgaiY[i] = y1;
        x1++;
    }
    int x2 = 90, y2 = 8;
    for (int i = 15; i < 18; i++) {
        ChuongNgaiX[i] = x2;
        ChuongNgaiY[i] = y2;
        y2--;
    }
    for (int i = 18; i < 30; i++) {
        ChuongNgaiX[i] = x2;
        ChuongNgaiY[i] = y2;
        x2--;
    }
    int x3 = 20, y3 = 18;
    for (int i = 30; i < 33; i++) {
        ChuongNgaiX[i] = x3;
        ChuongNgaiY[i] = y3;
        y3++;
    }
    for (int i = 33; i < 45; i++) {
        ChuongNgaiX[i] = x3;
        ChuongNgaiY[i] = y3;
        x3++;
    }
    int x4 = 90, y4 = 18;
    for (int i = 45; i < 48; i++) {
        ChuongNgaiX[i] = x4;
        ChuongNgaiY[i] = y4;
        y4++;
    }
    for (int i = 48; i < 60; i++) {
        ChuongNgaiX[i] = x4;
        ChuongNgaiY[i] = y4;
        x4--;
    }
    for (int i = 0; i < 60; i++) {
        gotoXY(ChuongNgaiX[i], ChuongNgaiY[i]);
        cout << "o";
    }
}

bool Game::checkchamtuong(int x0, int y0) {
    if (y0 == 0 || y0 == 27 || x0 == 10 || x0 == 100) {
        return true;
    }
    else return false;
}

bool Game::checkrancan() {
    for (int i = 1; i < sl; i++) {
        if (ToaDoX[0] == ToaDoX[i] && ToaDoY[0] == ToaDoY[i]) {
            return true;
        }
    }

    for (int i = 0; i < 60; i++) {
        if (ChuongNgaiX[i] == ToaDoX[0] && ChuongNgaiY[i] == ToaDoY[0]) {
            return true;
        }
    }
    return false;
}

bool Game::checkdie() {
    bool kt1 = checkchamtuong(x, y);
    bool kt2 = checkrancan();
    if (kt1 == true || kt2 == true) {
        return true;
    }
    return false;
}

void Game::ketthuc() {
    system("cls");
    SetColor(6);
    gotoXY(40, 12);
    cout << "CAM ON BAN DA CHOI GAME <3";
    Sleep(1000);
    gotoXY(37, 14);
    cout << "Game se tu dong thoat sau 3s !!!";
    gotoXY(20, 16);
    SetColor(9);
    cout << setw(16) << "3\t";
    Sleep(1000);
    cout << setw(16) << "2\t";
    Sleep(1000);
    cout << setw(16) << "1\t";
    Sleep(250);
    cout << setw(16) << ".\t";
    Sleep(250);
    cout << setw(16) << ".\t";
    Sleep(250);
    cout << setw(16) << ".\t";
    Sleep(250);
    SetColor(7);
    system("cls");
}

void Game::reset() {
    sl = 3;
    x = 50; //dat lai toa do x,y cua dau ran
    y = 13;
    check = 2; //dat lai huong di chuyen ban dau cua ran (2 la qua phai)
}

void Game::start() {
    do {
        reset();
        xoacontro();
        batdau();
        srand(time(NULL));
        bool gameover = false;
        Khung();
        Chuongngai();
        Khoitaoso_nach();
        vesnake();
        taoqua();
            
        int prevX = x;
        int prevY = y;
            
        while (!gameover) {
            xoadulieucu();
            if (_kbhit()) {
                char kytu = _getch();
                if (kytu == 'w' && check != 0) {
                    check = 1;
                }
                else if (kytu == 's' && check != 1) {
                    check = 0;
                }
                else if (kytu == 'a' && check != 2) {
                    check = 3;
                }
                else if (kytu == 'd' && check != 3) {
                    check = 2;
                }
            }
                
            prevX = x;
            prevY = y;
                
            if (check == 0) {
                y++;
            }
            else if (check == 1) {
                y--;
            }
            else if (check == 2) {
                x++;
            }
            else if (check == 3) {
                x--;
            }
                
            if(x<=10 || x>=100 || y<=0 || y>=27 || checkrancan()){
                x = prevX;
                y = prevY;
                gameover = true;
            }
                
            xulyran();
            gameover = checkdie();
            Sleep(dokho);
        }
        Sleep(3000);
        system("cls");

        bool over = true;
        if (over) {
            SetColor(4);
            gotoXY(10,1);
            cout << "GAME OVER!";
        }
        SetColor(11);

        gotoXY(10,3);
        cout<<"Bam phim 1 de choi lai"<<endl;
        gotoXY(10,4);
        cout<<"Bam phim 'x' de thoat";
        gotoXY(10,5);
        cout << "Nhap lua chon cua ban: ";
        cin.ignore();
        int i=6;
        do {
            getline(cin, replay);
            if (replay=="x" || replay=="1") {
                break;
            }
            if (replay!="x" && replay !="x") {
                gotoXY(10,i);
                cout <<"Nhap sai! Vui long nhap lai: ";
                i++;
            }
        } while (replay!="1" && replay!="x");

        if (replay=="x") {
            ketthuc();
            return;
        } else {
            system("cls");
        }
    } while (replay == "1");
        
    ketthuc();
}
