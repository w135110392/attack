#include<iostream>
#include<windows.h>
#include<conio.h>
#include<string>
#include "hacker.h"
using namespace std;
#define WIDTH 80
#define HEIGHT 40
/*
 
 ÿ���
 ��¼����
 �˵���ʾ����
 ��¼�����빦��

*/

//���ж��빦��
void tiltleCenter(string msg){
	int intSpace;
	intSpace = (WIDTH - msg.length()) / 2;    //����ַ������ж���
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
//��¼����
void login(void){   
		string name;
		
		char pwd[32];
		while (1){
			system("cls");
			cout << "�������û�����" ;
			cin >> name;
			cout << "�������룺";
			inputPwd(pwd,sizeof(pwd));
			cout<<"\n";
				if (name =="jack"&&!strcmp(pwd ,"123456")){
					break;
				}else {
					cout << "�û���������������������룡\n";
					system("pause");
					  }
		}
}
//�˵���ʾ
void menuShow(void){
	/*
	system("cls");
	cout << "1.��վ404����" << endl;
	cout << "2.��վ�۸Ĺ���" << endl;
	cout << "3.��վ������¼" << endl;
	cout << "4.DNS����" << endl;
	cout << "5.��վ��������������" << endl;
	cout << "6.�˳�" << endl;
	*/
	
	
	string menu[] = {
		"1.��վ404����",
		"2.��վ�۸Ĺ���",
		"3.��վ������¼",
		"4.DNS����",
		"5.��վ��������������",
		"6.�˳�"
	};

	unsigned int max = 0;
	int i = 0;
	int intSpace = 0;
	int menuCount = sizeof(menu) / sizeof(menu[0]);
	for (i = 0; i<menuCount; i++){   //ȡ���ַ�����Ĳ˵���
		if (menu[i].length()>max){
			max = menu[i].length();
		}
	}

	intSpace = (WIDTH - max) / 2;    //����ַ������ж���
	system("cls");
	string msg = "---�ڿ͹���ϵͳ---";
	tiltleCenter(msg);
	for (int i = 0; i < menuCount; i++){
		for (int j = 0; j < intSpace; j++){
			cout << " ";
		}
		cout << menu[i] << endl;
	}
}
//���빦��
int menuChoise(void){

	int n=0;
	while (1){
		cout << "��������Ҫ�Ĺ���(1-6):";
		cin >> n;
		if (cin.fail()){
			cin.clear();
			cin.sync();
			cout << "��Ч���룬������ѡ��";
			system("pause");
		}else{
			break;
			}
	}
				
	return n;
}
//1.404����
void attack404(void){
	
		
		char id[32]; 
		char response[4096]; //�������ؽ��
	
			tiltleCenter("------��վ404����------");
	
				cout << "����ִ��404����...";
				hk_404(id,response);
				string retStr = UTF8ToGBK(response);
				cout << retStr;
			system("pause");
		

}
//2.��վ�۸�
void siteEdit(void){
	system("cls");
	cout << "2.��վ�۸Ĺ���" << endl;
	system("pause");

}
//3.������¼
void attcakLog(void){
	system("cls");
	cout << "3.��վ������¼" << endl;
	system("pause");

}
//4.DNS����
void attackDns(void){
	system("cls");
	cout << "4.DNS����" << endl;
	system("pause");

}
//5.�������޸�
void attackRepair(void){
	system("cls");
	cout << "5.��վ�����޸�" << endl;
	system("pause");

}
//�����ʼ��
void init(void){
 //�����ն˴��ڴ�С
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
			case 6:		   //��������Ŀ���		
			return 0
					;			
			default:			//����ѡ��Ŀ���
				cout << "��Ч���룬����������";
				system("pause");
				break;

		}
	}
		
		
system("pause");

	return 0;
}