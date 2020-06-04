#include<iostream>
#include<windows.h>
#include<conio.h>
#include<string>
#include "hacker.h"
using namespace std;
#define WIDTH 80
#define HEIGHT 40
/*
 
 每项功能
 登录功能
 菜单显示功能
 登录后输入功能

*/

//居中对齐功能
void tiltleCenter(string msg){
	int intSpace;
	intSpace = (WIDTH - msg.length()) / 2;    //以最长字符串居中对齐
	for (int j = 0; j < intSpace; j++){
			cout << " ";
		}
		cout << msg << endl;
	}

void inputPwd(char pwd[],int size){
	char c;
	int i=0;
	while (1){
		c = _getch();
		if (c=='\r'||i>=size){
			pwd[i] = '\0';
			break;
		
		}
		else{
			
			pwd[i++] = c;
			cout << "*";
		}
	}
	
}
//登录功能
void login(void){   
		string name;
		
		char pwd[32];
		while (1){
			system("cls");
			cout << "请输入用户名：" ;
			cin >> name;
			cout << "请输密码：";
			inputPwd(pwd,sizeof(pwd));
			cout<<"\n";
				if (name =="jack"&&!strcmp(pwd ,"123456")){
					break;
				}else {
					cout << "用户名或密码错误，请重新输入！\n";
					system("pause");
					  }
		}
}
//菜单显示
void menuShow(void){
	/*
	system("cls");
	cout << "1.网站404攻击" << endl;
	cout << "2.网站篡改攻击" << endl;
	cout << "3.网站攻击记录" << endl;
	cout << "4.DNS攻击" << endl;
	cout << "5.网站服务器重启攻击" << endl;
	cout << "6.退出" << endl;
	*/
	
	
	string menu[] = {
		"1.网站404攻击",
		"2.网站篡改攻击",
		"3.网站攻击记录",
		"4.DNS攻击",
		"5.网站服务器重启攻击",
		"6.退出"
	};

	unsigned int max = 0;
	int i = 0;
	int intSpace = 0;
	int menuCount = sizeof(menu) / sizeof(menu[0]);
	for (i = 0; i<menuCount; i++){   //取得字符串最长的菜单项
		if (menu[i].length()>max){
			max = menu[i].length();
		}
	}

	intSpace = (WIDTH - max) / 2;    //以最长字符串居中对齐
	system("cls");
	string msg = "---黑客攻击系统---";
	tiltleCenter(msg);
	for (int i = 0; i < menuCount; i++){
		for (int j = 0; j < intSpace; j++){
			cout << " ";
		}
		cout << menu[i] << endl;
	}
}
//输入功能
int menuChoise(void){

	int n=0;
	while (1){
		cout << "请输入你要的功能(1-6):";
		cin >> n;
		if (cin.fail()){
			cin.clear();
			cin.sync();
			cout << "无效输入，请重新选择！";
			system("pause");
		}else{
			break;
			}
	}
				
	return n;
}
//1.404攻击
void attack404(void){
	
		
		char id[32]; 
		char response[4096]; //攻击返回结果
	
			tiltleCenter("------网站404攻击------");
	
				cout << "正在执行404攻击...";
				hk_404(id,response);
				string retStr = UTF8ToGBK(response);
				cout << retStr;
			system("pause");
		

}
//2.网站篡改
void siteEdit(void){
	system("cls");
	cout << "2.网站篡改攻击" << endl;
	system("pause");

}
//3.攻击记录
void attcakLog(void){
	system("cls");
	cout << "3.网站攻击记录" << endl;
	system("pause");

}
//4.DNS攻击
void attackDns(void){
	system("cls");
	cout << "4.DNS攻击" << endl;
	system("pause");

}
//5.攻击后修复
void attackRepair(void){
	system("cls");
	cout << "5.网站攻击修复" << endl;
	system("pause");

}
//程序初始化
void init(void){
 //设置终端窗口大小
	char cmd[128];
	sprintf_s(cmd, "mode con cols=%d lines=%d", WIDTH, HEIGHT, cmd,sizeof(cmd));
	system(cmd);
}

int main(void){
	init();
	login();
	
	while (1){
		
		menuShow();
		int n = menuChoise();;
			
			switch (n){
			case 1:
				attack404();
				break;
			case 2:
				siteEdit();
				break;
			case 3:
				attcakLog();
				break;
			case 4:
				attackDns();
				break;
			case 5:
				attackRepair();
				break;
			case 6:		   //程序结束的口子		
			return 0
					;			
			default:			//重新选择的口子
				cout << "无效输入，请重新输入";
				system("pause");
				break;

		}
	}
		
		
system("pause");

	return 0;
}