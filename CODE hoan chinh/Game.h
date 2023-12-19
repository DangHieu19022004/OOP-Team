// Game.h
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <iomanip>
#include <ctime>
#include <windows.h>

using namespace std;

class Game {
protected:
    int dokho;      
    int sl; //Bien do dai cua ran
    int ToaDoX[100];       
    int ToaDoY[100];       
    int ChuongNgaiX[100]; 
    int ChuongNgaiY[100];  
    int x;                
    int y;                 
    int check; //Bien kiem tra huong di chuyen cua ran
    int xqua;             
    int yqua;              
    std::string replay; //Bien lua chon choi lai

public:
	// Constructor cua class Game
    Game();           
	//Phuong thuc bat dau tro choi     
    virtual void batdau(); 
    
    //Di chuyen con tro den toa do (x,y) tren ma hinh console
    void gotoXY(int x, int y); 
    
    //phuong thuc thiet lap mau sac cho van ban tren man hinh console
    void SetColor(WORD color); 
    
    //phuong thuc an con tro tren man hinh
    void xoacontro();           
    
    //ve ran len man hinh
    void vesnake();      
	        
    //xoa du lieu cu cua ran tren man hinh
    void xoadulieucu();   
	       
    //kiem tra xem ran co an qua khong
    bool checkrananqua(int xqua, int yqua, int x0, int y0);
    
    //kiem tra xem qua co trung voi ran hoac chuong ngai vat khong
	bool checktrung(int xqua, int yqua);                
	 
	//tao mot qua moi sau khi ran an qua hoac khi bat dau tro choi
    void taoqua();            
	 
    //them mot gia tri moi vao mang
    void them(int a[], int gt); 
    
    //xoa mot gia tri tu mang tai vi tri vt
    void xoa(int a[], int vt); 
    
    //xu ly logic cua ran trong moi frame
    void xulyran();             
    
    //khoi tao toa do ban dau cua ran
    void Khoitaoso_nach(); 
	     
    //ve khung choi
    void Khung();    
	           
    //tao chuong ngai vat
    void Chuongngai(); 
	        
    //kiem tra xem ran co va cham voi tuong khong
    bool checkchamtuong(int x0, int y0);  
    
    //kiem tra xem ran co va cham voi chinh no khong
    bool checkrancan();             
	    
    //kiem tra xem ran da thua cuoc chua
    bool checkdie();              
	       
    //hien thi thong bao ket thuc tro choi
    void ketthuc();  

    //Phuong thuc reset de khoi tao lai trang thai ban dau cua tro choi   
    void reset();     
	          
    //phuong thuc chinh de bat dau tro choi
    void start();                       
};

#endif // GAME_H
