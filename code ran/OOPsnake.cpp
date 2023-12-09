

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

