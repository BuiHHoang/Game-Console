#include <iostream>
#include <cstdlib>
#include <windows.h>

using namespace std;
										//Ham xuat ra sau moi luot di
void print(char a[10][18]){ 
	char c='a';
	cout << endl << "       ";
	for(int i=0;i<18;i++)
	cout << (char)(c++ - 32) << "   ";
	cout << endl << "     -------------------------------------------------------------------------" << endl;
	for(int i=0;i<10;i++){
		cout << "   " << (char)(c++ - 18) << " [ ";
		for(int j=0;j<17;j++) cout << a[i][j] << " | ";
		cout << a[i][17] << " ]" << endl;
		cout << "     -------------------------------------------------------------------------" << endl;
	}
}
										//Ham nhap luot di
void scan(char arr[10][18],int k,int& stt){
	cout << endl << "     Chon vi tri: ";
	string s; int m=0,n;
	do{ 					//vong lap lai neu trung
		do{ 				//vong lap nhap
			m=0;
			cin >> s;
			if(s[0]>'j'||s[0]<'a'||s[1]>'R'||s[1]<'A'){
				m=1;
				cout << endl << "     Nhap sai, nhap lai: ";
		}} while (m==1);
		m = s[0] - 97;
		n = s[1] - 65;
		if(arr[m][n]!=' ') cout << endl << "     Vi tri khong kha thi, nhap lai: ";
	} while(arr[m][n]!=' ');
	if(k==1) arr[m][n] = 'X';
	else{
		stt%2==0? arr[m][n] = 'X': arr[m][n]='O';
		stt++;				 //bien doi luot
	}
}
										//Ham AI
void AI(char arr[10][18]){
	int k=0,kk=0,b=0,q=0;
	char t='O',z;
	for(int i=0;i<3;i++) 	//toi uu danh xien
	for(int j=0;j<3;j++){
		if(arr[i][j]==' ') q++;
		if(q==8&&arr[1][1]==' '){
			arr[1][1]='O';
			b=1;
		} if(q==6) if(arr[0][0]!=' '&&arr[2][2]!=' '||arr[0][2]!=' '&&arr[2][0]!=' '){
			if(arr[1][1]=='X'){ arr[0][2] = 'O'; b=1;}
			if(arr[1][1]=='O'){ arr[0][1] = 'O'; b=1;}}}
	for(int i=0;i<3;i++){ 	//check ngang
		k=0;kk=0;
		if(b==1) break;
		for(int j=0;j<3;j++){
			if(arr[i][j]=='X') k++;
			if(arr[i][j]=='O') kk++;}
		if(k==2||kk==2) for(int m=0;m<3;m++) if(arr[i][m]==' '){
			arr[i][m]=t;
			b=1;
	}} k=0;kk=0; 			//reset bien
	for(int i=0;i<3;i++){ 	// doc
		k=0;kk=0;
		if(b==1) break;
		for(int j=0;j<3;j++){
			if(arr[j][i]=='X') k++;
			if(arr[j][i]=='O') kk++;}
		if(k==2||kk==2) for(int m=0;m<3;m++) if(arr[m][i]==' '){
			arr[m][i]=t;
			b=1;
	}}
	for(int i=0;i<3;i++){ 	//check xien
		k=0;kk=0;
		if(b==1) break;
		if(arr[0][2]=='X'||arr[2][0]=='X') for(int m=0;m<3;m++) if(arr[m][2-m]==' '){
			arr[m][2-m]=t;
			b=1;
	}} for(int i=0;i<3;i++) //danh tu do
		for(int j=0;j<3;j++){
			if(b==1) break;
			if(arr[i][j]==' '){
				arr[i][j]=t;
				b=1;
}}}

										//Winner
int checkWinner(char a[10][18]){
	int winner=0,q=0,tobecontinue=0;
	// any of the rows is same
	for (int i = 0; i < 10; i++)
		for(int j=0;j<15;i++){
			char t = a[i][j];
			if(t==' ') continue;
			for(int k=1;k<4;k++){
				if(a[i][j+k]!=t) break;
				tobecontinue++;
			} if(tobecontinue==4){
				if(j>0&&a[i][j-1]!=t&&a[i][j-1]!=' '){
					if(a[i][j+4]==t) if(a[i][j+5]==' '||a[i][j+5]==t) 
						return a[i][j]=='X'? 1:2;
				} else{
					if(a[i][j+4]==t||a[i][j+4]==' ')
						return a[i][j]=='X'? 1:2;
				}
			}
		}
	// any of the columns is same
	for (int i = 0; i < 3; i++){
		if (a[0][i]==a[1][i] && a[1][i]==a[2][i] && a[0][i]!=' '){
			return a[0][i]=='X'? 1:2;
		}
	}
	// 1st diagonal is same
	if (a[0][0]==a[1][1] && a[1][1]==a[2][2] && a[0][0]!=' '){
		return a[0][0]=='X'? 1:2;
	}
	// 2nd diagonal is same
	if (a[0][2]==a[1][1] && a[1][1]==a[2][0] && a[0][2]!=' '){
		return a[0][2]=='X'? 1:2;
	}
	for(int i=0;i<3;i++)
	for(int j=0;j<3;j++)
	if(a[i][j]!=' ') q++;
	if(q==9) winner=3;
	return winner;
}
										//1player
int game1(string s){
	char arr[10][18]; int k,stt=0;
	for(int i=0;i<10;i++) //cap phat o tro choi
	for(int j=0;j<18;j++)
	arr[i][j]=' ';
	print(arr);
	while(1){ //game start
		scan(arr,1,stt);
		system("cls");
		k = checkWinner(arr);
		if(k!=0){ print(arr); break;}
		AI(arr);
		print(arr);
		k = checkWinner(arr);
		if(k!=0) break;
	} if(k==1) cout << endl << "   The winner is: " << s << " (X)" << endl;	
	else if(k==2) cout << endl << "    The winner is: AI (O)" << endl;
	else cout << endl << "         No winner" << endl;
	return k;
}
										//2player
int game2(string s1,string s2){	
	char arr[10][18]; int stt=0,k=0;
	for(int i=0;i<10;i++)
	for(int j=0;j<18;j++)
	arr[i][j]=' ';
	print(arr);
	while(1){
		scan(arr,2,stt);
		system("cls");
		cout << endl << "                    X - O Game" << endl << endl;
		print(arr);
		k = checkWinner(arr);
		if(k!=0) break;
	} if(k==1) cout << endl << "   The winner is: " << s1 << " (X)" << endl;
	else if(k==2) cout << endl << "   The winner is: " << s2 << " (O)" << endl;
	else cout << endl << "         No winner" << endl;
	return k;
}

//Ham choi lai
void end(int& gg,int& out){
	Sleep(3000);
		while(1){
			if(gg++!=0) cout << endl << "   Cay cu a? :)" << endl;
			char s;
			Sleep(500);
			cout << endl << endl << "   Want to play again?" << endl << "         Y / N" << endl;
			cin >> s;
			if(s=='Y'||s=='y'){
				system("cls"); break;
			} else if(s=='N'||s=='n'){ out++; break;}
			else system("cls");
		}
}

int main(){
	int t,p1=0,p2=0,gg,out=0,only=0;
	string name1,name2,stt;
	system("color B");
	//menu
	while(1){
		system("cls");
		cout << endl << "                    X - O Game" << endl << endl;
		cout << "              One player or Two player?" << endl << endl;
		cout << "                    ( 1 or 2 )";
		cout << endl << endl << "                         ";
		cin >> stt;
		if(stt=="1"||stt=="2") break;
	} system("cls");
	//game play
	if(stt=="1") while(1){
		gg=0;
		if(only==0){
			name2 = "AI";
			cout << endl << "                    X - O Game" << endl << endl;
			cout << "     Player: "; cin >> name1;
		}system("cls");
		cout << endl << "                    X - O Game" << endl << endl;
		t=game1(name1);
		if(t==1) p1++;
		if(t==2) p2++;
		cout << endl << "     " << name1 << ": " << p1 << "     AI: " << p2;
		end(gg,out);
		if(out!=0) break;
		only=1;
	} if(stt=="2") while(1){
		gg=0;
		if(only==0){
			cout << endl << "                    X - O Game" << endl << endl;
			cout << "     Player 1: "; cin >> name1;
			cout << "     Player 2: "; cin >> name2;
		} system("cls");
		cout << endl << "                    X - O Game" << endl << endl;
		t=game2(name1,name2);
		if(t==1) p1++;
		if(t==2) p2++;
		cout << endl << "     " << name1 << ": " << p1 << "     "<< name2 << ": " << p2;
		end(gg,out);
		if(out!=0) break;
		only=1;
	} //end game
	system("cls");
	cout << endl << "                    X - O Game" << endl << endl;
	cout << endl << "     " << name1 << ": " << p1 << "     "<< name2 << ": " << p2 << endl << endl;
	system("pause");
}
