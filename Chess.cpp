#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <vector>

using namespace std;

void color(int a){
	switch(a){
		case 4:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			break;
		case 6:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
			break;
		case 3:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			break;
		case 5:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
			break;
		case 2:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			break;
		case 1:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			break;
	}
}

void encode(char s){
	switch (s){
		case 'c':
			color(1);
			cout << (char)127; break;
		case 'k':
			color(1);
			cout << (char) 20; break;
		case 'b':
			color(1);
			cout << (char)173; break;
		case 'v':
			color(1);
			cout << (char) 11; break;
		case 'h':
			color(1);	
			cout << (char) 12; break;
		case 'p':
			color(1);
			cout << (char) 25; break; //down
		case 'C':
			color(3);
			cout << (char)127; break;
		case 'K':
			color(3);	
			cout << (char) 20; break;
		case 'B':
			color(3);
			cout << (char) 33; break;
		case 'V':
			color(3);
			cout << (char) 11; break;
		case 'H':
			color(3);
			cout << (char) 12; break;
		case 'P':
			color(3);
			cout << (char) 24; break; //up
		case 'c'-10:
			color(5);
			cout << (char)127; break;
		case 'k'-10:
			color(5);
			cout << (char) 20; break;
		case 'b'-10:
			color(5);
			cout << (char)173; break;
		case 'v'-10:
			color(5);
			cout << (char) 11; break;
		case 'h'-10:
			color(5);	
			cout << (char) 12; break;
		case 'p'-10:
			color(5);
			cout << (char) 25; break; //down
		case 'C'-10:
			color(5);
			cout << (char)127; break;
		case 'K'-10:
			color(5);	
			cout << (char) 20; break;
		case 'B'-10:
			color(5);
			cout << (char) 33; break;
		case 'V'-10:
			color(5);
			cout << (char) 11; break;
		case 'H'-10:
			color(5);
			cout << (char) 12; break;
		case 'P'-10:
			color(5);
			cout << (char) 24; break; //up
		case '.':
			color(2);
			cout << (char)177; break;
		case '*':
			color(5);
			cout << (char)176; break;
		case '!':
			color(5);
			cout << (char)176; break;
		case ' ':
			cout << ' '; break;
		default :
			color(4);
			cout << s;
	}
}

void space(char a[8][8]){
	for(int i=0;i<8;i++)
	for(int j=0;j<8;j++){
		int k=i+j;
		if(k%2==1&&a[i][j]==' ') a[i][j] = '.';
	}
}

bool may_replace(char s){
	if(s==56||s==57||s==62||s==65||s==70||s==76) return 1;
	if(s==88||s==89||s==94||s==97||s==102||s==108) return 1;
	return 0;
}

void print(char a[8][8]){
	char c='a';
	color(2);
	cout << "                  Chess Game" << endl;
	color(6);
	cout << endl << "         1   2   3   4   5   6   7   8" << endl << endl;
	color(2);
	cout << "       ---------------------------------" << endl;
	for(int i=0;i<8;i++){
		color(6);
		cout << "   " << c++;
		color(2);
		cout << "   [ ";
		for(int j=0;j<7;j++){
			encode(a[i][j]);
			color(2);
			cout << " | ";
		} encode(a[i][7]);
		color(2);
		cout << " ]" << endl;
		std::cout << "       ---------------------------------" << endl;
	}
	color(2); cout << " ";
}

void scan(string& s,int &num){
	int m;
	while(1){
		m=0;
		cin >> s;
		if(s=="Back"||s=="back") if(num==1) break;
		if(s=="new"||s=="New") break;
		if(s[0]<'a'||s[0]>'h'||s[1]<'1'||s[1]>'8'){
			m=1;
			cout << endl << "     Nhap sai, nhap lai: ";
		} else break;
	}
}

void update(char& a){
	string s;
	cout << "     Update to:" << endl;
	cout << "     - Queen  (Q)"<< endl;
	cout << "     - Bishop (B)"<< endl;
	cout << "     - Knight (K)"<< endl;
	cout << "     - Castle (C)"<< endl;
	while(1){
		cin >> s;
		if(s!="Q"&&s!="B"&&s!="K"&&s!="C"&&s!="q"&&s!="b"&&s!="k"&&s!="c"){
			cout << "     Don't want to update?";
			continue;
		} break;
	} if(s[0]=='q'||s[0]=='Q') a=='p'? a = 'h' : a = 'H';
	else if(s[0]=='b'||s[0]=='B') a=='p'? a = 'b' : a = 'B';
	else if(s[0]=='k'||s[0]=='K') a=='p'? a = 'k' : a = 'K';
	else a=='p'? a = 'c' : a = 'C';
}

int who(char s){
	if(s==56||s==57||s==62||s==65||s==70||s==76) return 1;
	else if(s==88||s==89||s==94||s==97||s==102||s==108) return 2;
	else if(s==66||s==67||s==72||s==75||s==80||s==86) return 1;
	else if(s==98||s==99||s==104||s==107||s==112||s==118) return 2;
	else return 0;
}

void who_turn(string s1, string s2, int k){
	if(k%2==0){ 
		color(1);
		cout << endl << "     " << s1 << "'s ";
		color(2);
		cout << "turn ";
		color(1);
		cout << "(Yellow)" << endl;
		color(2);
	} else{
		color(3);
		cout << endl << "     " << s2 << "'s ";
		color(2);
		cout << "turn ";
		color(3);
		cout << "(Green)" << endl;
		color(2);
	}
}

void may_kill(char a[8][8],int m,int n){
	//replace + delete //use move()
	if(a[m][n]=='C'||a[m][n]=='c'){
		for(int i=1;i<8;i++)
			if(m+i<=6) if(a[m+i][n] == '*'&&a[m+i+1][n]!='*') 
				if(who(a[m][n]) != who(a[m+i+1][n])){
					a[m+i+1][n] -= 10; break;
		} for(int i=1;i<8;i++)
			if(m-i>=1) if(a[m-i][n] == '*'&&a[m-i-1][n]!='*')
				if(who(a[m][n]) != who(a[m-i-1][n])){
					a[m-i-1][n] -= 10; break;
		} for(int i=1;i<8;i++)
			if(n+i<=6) if(a[m][n+i] == '*'&&a[m][n+i+1]!='*')
				if(who(a[m][n]) != who(a[m][n+i+1])){
					a[m][n+i+1] -= 10; break;
		} for(int i=1;i<8;i++)
			if(n-i>=1) if(a[m][n-i] == '*'&&a[m][n-i-1]!='*')
				if(who(a[m][n]) != who(a[m][n-i-1])){
					a[m][n-i-1] -= 10; break;
		} if(m<=6) if(a[m+1][n]!='*')
			if(who(a[m][n]) != who(a[m+1][n])) a[m+1][n] -= 10;
		if(n<=6) if(a[m][n+1]!='*')
			if(who(a[m][n]) != who(a[m][n+1])) a[m][n+1] -= 10;
		if(m>=1) if(a[m-1][n]!='*')
			if(who(a[m][n]) != who(a[m-1][n])) a[m-1][n] -= 10;
		if(n>=1) if(a[m][n-1]!='*')
			if(who(a[m][n]) != who(a[m][n-1])) a[m][n-1] -= 10;
	} else if(a[m][n]=='B'||a[m][n]=='b'){
		for(int i=1;i<8;i++)
			if(m+i<=6&&n+i<=6) if(a[m+i][n+i] == '*'&&a[m+i+1][n+i+1] != '*')
				if(who(a[m][n]) != who(a[m+i+1][n+i+1])){
					a[m+i+1][n+i+1] -= 10; break;
		} for(int i=1;i<8;i++)
			if(m-i>=1&&n+i<=6) if(a[m-i][n+i] == '*'&&a[m-i-1][n+i+1] != '*')
				if(who(a[m][n]) != who(a[m-i-1][n+i+1])){
					a[m-i-1][n+i+1] -= 10; break;
		} for(int i=1;i<8;i++)
			if(m+i<=6&&n-i>=1) if(a[m+i][n-i] == '*'&&a[m+i+1][n-i-1] != '*')
				if(who(a[m][n]) != who(a[m+i+1][n-i-1])){
					a[m+i+1][n-i-1] -= 10; break;
		} for(int i=1;i<8;i++)
			if(m-i>=1&&n-i>=1) if(a[m-i][n-i] == '*'&&a[m-i-1][n-i-1] != '*')
				if(who(a[m][n]) != who(a[m-i-1][n-i-1])){
					a[m-i-1][n-i-1] -= 10; break;
		} if(m<=6&&n<=6) if(a[m+1][n+1]!='*')
			if(who(a[m][n]) != who(a[m+1][n+1])) a[m+1][n+1] -= 10;
		if(m<=6&&n>=1) if(a[m+1][n-1]!='*')
			if(who(a[m][n]) != who(a[m+1][n-1])) a[m+1][n-1] -= 10;
		if(m>=1&&n<=6) if(a[m-1][n+1]!='*')
			if(who(a[m][n]) != who(a[m-1][n+1])) a[m-1][n+1] -= 10;
		if(m>=1&&n>=1) if(a[m-1][n-1]!='*')
			if(who(a[m][n]) != who(a[m-1][n-1])) a[m-1][n-1] -= 10;
	} else if(a[m][n]=='H'||a[m][n]=='h'){
		for(int i=1;i<8;i++)
			if(m+i<=6&&n+i<=6) if(a[m+i][n+i] == '*'&&a[m+i+1][n+i+1] != '*')
				if(who(a[m][n]) != who(a[m+i+1][n+i+1])){
					a[m+i+1][n+i+1] -= 10; break;
		} for(int i=1;i<8;i++)
			if(m-i>=1&&n+i<=6) if(a[m-i][n+i] == '*'&&a[m-i-1][n+i+1] != '*')
				if(who(a[m][n]) != who(a[m-i-1][n+i+1])){
					a[m-i-1][n+i+1] -= 10; break;
		} for(int i=1;i<8;i++)
			if(m+i<=6&&n-i>=1) if(a[m+i][n-i] == '*'&&a[m+i+1][n-i-1] != '*')
				if(who(a[m][n]) != who(a[m+i+1][n-i-1])){
					a[m+i+1][n-i-1] -= 10; break;
		} for(int i=1;i<8;i++)
			if(m-i>=1&&n-i>=1) if(a[m-i][n-i] == '*'&&a[m-i-1][n-i-1] != '*')
				if(who(a[m][n]) != who(a[m-i-1][n-i-1])){
					a[m-i-1][n-i-1] -= 10; break;
		} for(int i=1;i<8;i++)
			if(m+i<=6) if(a[m+i][n] == '*'&&a[m+i+1][n]!='*') 
				if(who(a[m][n]) != who(a[m+i+1][n])){
					a[m+i+1][n] -= 10; break;
		} for(int i=1;i<8;i++)
			if(m-i>=1) if(a[m-i][n] == '*'&&a[m-i-1][n]!='*')
				if(who(a[m][n]) != who(a[m-i-1][n])){
					a[m-i-1][n] -= 10; break;
		} for(int i=1;i<8;i++)
			if(n+i<=6) if(a[m][n+i] == '*'&&a[m][n+i+1]!='*')
				if(who(a[m][n]) != who(a[m][n+i+1])){
					a[m][n+i+1] -= 10; break;
		} for(int i=1;i<8;i++)
			if(n-i>=1) if(a[m][n-i] == '*'&&a[m][n-i-1]!='*')
				if(who(a[m][n]) != who(a[m][n-i-1])){
					a[m][n-i-1] -= 10; break;
		} if(m<=6&&n<=6) if(a[m+1][n+1]!='*')
			if(who(a[m][n]) != who(a[m+1][n+1])) a[m+1][n+1] -= 10;
		if(m<=6&&n>=1) if(a[m+1][n-1]!='*')
			if(who(a[m][n]) != who(a[m+1][n-1])) a[m+1][n-1] -= 10;
		if(m>=1&&n<=6) if(a[m-1][n+1]!='*')
			if(who(a[m][n]) != who(a[m-1][n+1])) a[m-1][n+1] -= 10;
		if(m>=1&&n>=1) if(a[m-1][n-1]!='*')
			if(who(a[m][n]) != who(a[m-1][n-1])) a[m-1][n-1] -= 10;
		if(m<=6) if(a[m+1][n]!='*')
			if(who(a[m][n]) != who(a[m+1][n])) a[m+1][n] -= 10;
		if(n<=6) if(a[m][n+1]!='*')
			if(who(a[m][n]) != who(a[m][n+1])) a[m][n+1] -= 10;
		if(m>=1) if(a[m-1][n]!='*')
			if(who(a[m][n]) != who(a[m-1][n])) a[m-1][n] -= 10;
		if(n>=1) if(a[m][n-1]!='*')
			if(who(a[m][n]) != who(a[m][n-1])) a[m][n-1] -= 10;
		}
}

bool move(char a[8][8],int m,int n){
	//move + possible //use color()
	if(a[m][n]=='C'||a[m][n]=='c') 
		{
		for(int i=1;i<8;i++){
			if(a[m+i][n]!=' '&&a[m+i][n]!='.') break;
			if(m+i<=7) a[m+i][n] = '*';
		} for(int i=1;i<8;i++){	
			if(a[m-i][n]!=' '&&a[m-i][n]!='.') break;
			if(m-i>=0) a[m-i][n] = '*';
		} for(int i=1;i<8;i++){
			if(a[m][n+i]!=' '&&a[m][n+i]!='.') break;
			if(n+i<=7) a[m][n+i] = '*';
		} for(int i=1;i<8;i++){
			if(a[m][n-i]!=' '&&a[m][n-i]!='.') break;
			if(n-i>=0) a[m][n-i] = '*';
		} may_kill(a,m,n);
	} else if(a[m][n]=='K'||a[m][n]=='k'){
			if(m<=5&&n<=6) if(a[m+2][n+1]==' '||a[m+2][n+1]=='.') a[m+2][n+1] = '*';
			else{ if(who(a[m+2][n+1]) != who(a[m][n])) a[m+2][n+1] -= 10;}
			if(m>=2&&n>=1) if(a[m-2][n-1]==' '||a[m-2][n-1]=='.') a[m-2][n-1] = '*';
			else{ if(who(a[m][n]) != who(a[m-2][n-1])) a[m-2][n-1] -= 10;}
			if(n>=1&&m<=5) if(a[m+2][n-1]==' '||a[m+2][n-1]=='.') a[m+2][n-1] = '*';
			else{ if(who(a[m][n]) != who(a[m+2][n-1])) a[m+2][n-1] -= 10;}
			if(m>=2&&n<=6) if(a[m-2][n+1]==' '||a[m-2][n+1]=='.') a[m-2][n+1] = '*';
			else{ if(who(a[m][n]) != who(a[m-2][n+1])) a[m-2][n+1] -= 10;}
			if(m<=6&&n<=5)if(a[m+1][n+2]==' '||a[m+1][n+2]=='.') a[m+1][n+2] = '*';
			else{ if(who(a[m][n]) != who(a[m+1][n+2])) a[m+1][n+2] -= 10;}
			if(m>=1&&n<=5) if(a[m-1][n+2]==' '||a[m-1][n+2]=='.') a[m-1][n+2] = '*';
			else{ if(who(a[m][n]) != who(a[m-1][n+2])) a[m-1][n+2] -= 10;}
			if(n>=2&&m<=6) if(a[m+1][n-2]==' '||a[m+1][n-2]=='.') a[m+1][n-2] = '*';
			else{ if(who(a[m][n]) != who(a[m+1][n-2])) a[m+1][n-2] -= 10;}
			if(m>=1&&n>=2) if(a[m-1][n-2]==' '||a[m-1][n-2]=='.') a[m-1][n-2] = '*';
			else{ if(who(a[m][n]) != who(a[m-1][n-2])) a[m-1][n-2] -= 10;}
	} else if(a[m][n]=='B'||a[m][n]=='b'){
		for(int i=1;i<8;i++){
			if(a[m+i][n+i]!=' '&&a[m+i][n+i]!='.') break;
			if(m+i<=7&&n+i<=7) a[m+i][n+i] = '*';
		} for(int i=1;i<8;i++){
			if(a[m-i][n+i]!=' '&&a[m-i][n+i]!='.') break;
			if(m-i>=0&&n+i<=7) a[m-i][n+i] = '*';
		} for(int i=1;i<8;i++){
			if(a[m+i][n-i]!=' '&&a[m+i][n-i]!='.') break;
			if(m+i<=7&&n-i>=0) a[m+i][n-i] = '*';
		} for(int i=1;i<8;i++){
			if(a[m-i][n-i]!=' '&&a[m-i][n-i]!='.') break;
			if(m-i>=0&&n-i>=0) a[m-i][n-i] = '*';
		} may_kill(a,m,n);	
	} else if(a[m][n]=='V'||a[m][n]=='v'){
			if(m<=6&&n<=6) if(a[m+1][n+1]==' '||a[m+1][n+1]=='.') a[m+1][n+1] = '*';
			else{ if(who(a[m][n]) != who(a[m+1][n+1])) a[m+1][n+1] -= 10;}
			if(m>=1&&n>=1) if(a[m-1][n-1]==' '||a[m-1][n-1]=='.') a[m-1][n-1] = '*';
			else{ if(who(a[m][n]) != who(a[m-1][n-1])) a[m-1][n-1] -= 10;}
			if(m<=6&&n>=1) if(a[m+1][n-1]==' '||a[m+1][n-1]=='.') a[m+1][n-1] = '*';
			else{ if(who(a[m][n]) != who(a[m+1][n-1])) a[m+1][n-1] -= 10;}
			if(m>=1&&n<=6) if(a[m-1][n+1]==' '||a[m-1][n+1]=='.') a[m-1][n+1] = '*';
			else{ if(who(a[m][n]) != who(a[m-1][n+1])) a[m-1][n+1] -= 10;}
			if(m<=6) if(a[m+1][n]==' '||a[m+1][n]=='.') a[m+1][n] = '*';
			else{ if(who(a[m][n]) != who(a[m+1][n])) a[m+1][n] -= 10;}
			if(m>=1) if(a[m-1][n]==' '||a[m-1][n]=='.') a[m-1][n] = '*';
			else{ if(who(a[m][n]) != who(a[m-1][n])) a[m-1][n] -= 10;}		
			if(n<=6) if(a[m][n+1]==' '||a[m][n+1]=='.') a[m][n+1] = '*';
			else{ if(who(a[m][n]) != who(a[m][n+1])) a[m][n+1] -= 10;}
			if(n>=1) if(a[m][n-1]==' '||a[m][n-1]=='.') a[m][n-1] = '*';
			else{ if(who(a[m][n]) != who(a[m][n-1])) a[m][n-1] -= 10;}
	} else if(a[m][n]=='H'||a[m][n]=='h'){
		for(int i=1;i<8;i++){
			if(m+i>7||n+i>7) break;
			if(a[m+i][n+i]!=' '&&a[m+i][n+i]!='.') break;
			a[m+i][n+i] = '*';
		} for(int i=1;i<8;i++){
			if(m-i<0||n+i>7) break;
			if(a[m-i][n+i]!=' '&&a[m-i][n+i]!='.') break;
			a[m-i][n+i] = '*';
		} for(int i=1;i<8;i++){
			if(m+i>7||n-i<0) break;
			if(a[m+i][n-i]!=' '&&a[m+i][n-i]!='.') break;
			a[m+i][n-i] = '*';
		} for(int i=1;i<8;i++){
			if(m-i<0||n-i<0) break;
			if(a[m-i][n-i]!=' '&&a[m-i][n-i]!='.') break;
			a[m-i][n-i] = '*';
		} for(int i=1;i<8;i++){
			if(m+i>7) break;
			if(a[m+i][n]!=' '&&a[m+i][n]!='.') break;
			a[m+i][n] = '*';
		} for(int i=1;i<8;i++){
			if(m-i<0) break;
			if(a[m-i][n]!=' '&&a[m-i][n]!='.') break;
			a[m-i][n] = '*';
		} for(int i=1;i<8;i++){
			if(n+i>7) break;
			if(a[m][n+i]!=' '&&a[m][n+i]!='.') break;
			a[m][n+i] = '*';
		} for(int i=1;i<8;i++){
			if(n-i<0) break;
			if(a[m][n-i]!=' '&&a[m][n-i]!='.') break;
			a[m][n-i] = '*';
		} may_kill(a,m,n);	
	} else if(a[m][n]=='p'){ //special + update
			if(m==1) if(a[2][n]==' '||a[2][n]=='.')
				if(a[3][n]==' '||a[3][n]=='.') a[3][n] = '*';
			if(m<=6) if(a[m+1][n]==' '||a[m+1][n]=='.') a[m+1][n] = '*';		
			if(m<=6&&n<=6) if(a[m+1][n+1]!=' '&&a[m+1][n+1]!='.')
				if(who(a[m][n]) != who(a[m+1][n+1])) a[m+1][n+1] -= 10;
			if(m<=6&&n>=1) if(a[m+1][n-1]!=' '&&a[m+1][n-1]!='.')
				if(who(a[m][n]) != who(a[m+1][n-1])) a[m+1][n-1] -= 10;
			if(m==4){
				if(a[m][n-1]=='P')
					if(a[m+1][n-1]==' '||a[m+1][n-1]=='.')
						a[m+1][n+1]=='!';
				if(a[m][n+1]=='P')
					if(a[m+1][n+1]==' '||a[m+1][n+1]=='.')
						a[m+1][n+1]=='!';
	}} else if(a[m][n]=='P'){
			if(m==6) if(a[5][n]==' '||a[5][n]=='.')
				if(a[4][n]==' '||a[4][n]=='.') a[4][n] = '*';
			if(m>=1) if(a[m-1][n]==' '||a[m-1][n]=='.') a[m-1][n] = '*';		
			if(m>=1&&n>=1) if(a[m-1][n-1]!=' '&&a[m-1][n-1]!='.')
				if(who(a[m][n]) != who(a[m-1][n-1])) a[m-1][n-1] -= 10;
			if(m>=1&&n<=6) if(a[m-1][n+1]!=' '&&a[m-1][n+1]!='.')
				if(who(a[m][n]) != who(a[m-1][n+1])) a[m-1][n+1] -= 10;
			if(m==3){
				if(a[m][n-1]=='p')
					if(a[m-1][n-1]==' '||a[m-1][n-1]=='.')
						a[m-1][n-1]='!';
				if(a[m][n+1]=='p')
					if(a[m-1][n+1]==' '||a[m-1][n+1]=='.')
						a[m-1][n+1]='!';
	}} for(int i=0;i<8;i++)
	for(int j=0;j<8;j++)
	if(a[i][j]=='*'||may_replace(a[i][j])) return 1;
	cout << "     Dm, choose again: ";
	space(a);
	return 0;
}

bool ismoving(int a[6], int team){
	int x = team%10,
	y = team/10;
	return y==1? a[1]==1? 0: x==1? a[0]==1? 0:1 : a[2]==1? 0:1 : a[4]==1? 0: x==1? a[3]==1? 0:1 : a[5]==1? 0:1;
}

void replace(char& s1, char& s2, char a[8][8]){
	s2 = s1;
	s1 = '*';
	for(int i=0;i<8;i++)
	for(int j=0;j<8;j++){
		if(a[i][j]=='*'||a[i][j]=='!') a[i][j] = ' ';
		if(may_replace(a[i][j])==1) a[i][j] += 10;
	} space(a);
}

bool safe(int m, int n, int wh, char arr[8][8]){
	int k = who(arr[m][n]);
	char t = arr[m][n];
	if(k==0) k = wh;
	char a=' ';
	replace(a,a,arr);
	for(int i=0;i<8;i++)
	for(int j=0;j<8;j++){
		if(arr[i][j]!=' '&&arr[i][j]!='.')
		if(who(arr[i][j])!=k){
			move(arr,i,j);
				if(arr[m][n]==t-10||arr[m][n]=='*'){
					replace(a,a,arr);
					return 0;
			}
		} replace(a,a,arr);
	} return 1;
}

bool may_castling(char s, char a[8][8], int z[6]){
	int k,wh=who(s),cast1=1,cast2=1,w=0;
	char arr[8][8];
	for(int i=0;i<8;i++)
	for(int j=0;j<8;j++)
		arr[i][j] = a[i][j];
	if(wh==2){
		w=1; k=0;
	} else if(wh==1){
		w=4; k=7;
	}{
		if(a[k][1]!='.'&&a[k][1]!=' ') cast1 = 0;
		if(a[k][2]!='*') cast1 = 0;
		if(a[k][4]!='*') cast2 = 0;
		if(a[k][5]!='.'&&a[k][5]!=' ') cast2 = 0;
		if(a[k][6]!='.'&&a[k][6]!=' ') cast2 = 0;
	} if(cast1==0&&cast2==0) return 0;
		int test0 = safe(k,0,wh,arr), test4 = safe(k,4,wh,arr),
			test1 = safe(k,1,wh,arr), test5 = safe(k,5,wh,arr),
			test2 = safe(k,2,wh,arr), test6 = safe(k,6,wh,arr),
			test3 = safe(k,3,wh,arr), test7 = safe(k,7,wh,arr);
	if(test3==0) return 0;
	if(test0==0&&test7==0) return 0;
	if(cast1!=0) if(test1!=0&&test2!=0&&test0!=0){
		int nope = wh==1? 21:11;
		if(ismoving(z,nope)){
			{
				a[k][1] = '*';
				return 1;
	}}} if(cast2!=0) if(test4!=0&&test5!=0&&test6!=0&&test7!=0){
		int nope = wh==1? 22:12;
		if(ismoving(z,nope)){
			{
			a[k][5] = '*';
			return 1;
	}}} return 0;
}


int castling(char s1, int k, char a[8][8]){
	if(s1=='v'){
		if(k==1){
			a[0][2] = a[0][0];	a[0][0] = ' ';
			a[0][1] = a[0][3];	a[0][3] = ' ';
		} else if(k==2){
			a[0][5] = a[0][3];	a[0][3] = ' ';
			a[0][4] = a[0][7];	a[0][7] = ' ';
		} return 1;
	} else{
		if(k==1){
			a[7][2] = a[7][0];	a[7][0] = ' ';
			a[7][1] = a[7][3];	a[7][3] = ' ';
		} else if(k==2){
			a[7][5] = a[7][3];	a[7][3] = ' ';
			a[7][4] = a[7][7];	a[7][7] = ' ';
		} return 1;
	} space(a);	
	return 0;
}

int input(char arr[8][8],int& stt, int& x, int k[6], string s1, string s2){
	string s;
	int m1,n1,m2,n2,check,num,t=0,dm=0;
	char a=' ';
	while(1){
		system("cls");
		print(arr);
		num=0;
		who_turn(s1,s2,stt);
		cout << endl << "     Choose piece: ";
		scan(s,num);
		if(stt<50) while(s=="New"||s=="new"){
			cout << "     No!" << endl << "     Choose piece: ";
			scan(s,num);
		}
		if(stt>=50) if(s=="New"||s=="new")
		 	if(stt%2==0){
		 		color(1);
		 		cout << "     Ok" << endl;
		 		color(3);
		 		while(1){
		 			cout << "     Hey " << s2 << ", want to play again now?" << endl;
		 			cout << "         Y / N" << endl << "            ";
		 			string s3; cin >> s3;
		 			if(s3=="Y"||s3=="y") return 1;
		 			else if(s3=="N"||s3=="n") break;
		 			else{
		 				system("cls");
		 				color(2);
		 				cout << endl << "     Choose piece: ";
						scan(s,num);
		 		}}
		 	}
		m1 = (int)s[0] - 97;
		n1 = (int)s[1] - 49;
		int test=who(arr[m1][n1]);
		if(stt%2==0) if(who(arr[m1][n1])==1){
			cout << "     Are you cheating?";
			Sleep(2000);
			continue;
		} if(stt%2==1) if(who(arr[m1][n1])==2){
			cout << "     Are you cheating?";
			Sleep(2000);
			continue;
		} check = move(arr,m1,n1);
		if(arr[m1][n1]=='V'||arr[m1][n1]=='v')
				may_castling(arr[m1][n1],arr,k);
		system("cls");
		print(arr);
		if(check == 1) break;
		cout << "     Biet choi ko?";
		Sleep(2000);
	} cout << endl << "     Move to: ";
	cout << endl << "     ('Back' to choose again) ";
	while(1){
		num=1;
		scan(s,num);
		if(s=="Back"||s=="back"){
			stt--;
			replace(a,a,arr);
			space(arr);
			break;	
		} m2 = (int)s[0] - 97;
		  n2 = (int)s[1] - 49;
		if(arr[m2][n2]=='*'||arr[m2][n2]=='!'||may_replace(arr[m2][n2])==1){
			check = 0;
			if(arr[m1][n1]=='v')
				if(k[1]==0){
					k[1]=1;
					t=10;
			} if(arr[m1][n1]=='V')
				if(k[4]==0){
					k[4]=1;
					t=10;
			} if(t==10) if(arr[m2][n2]=='*'){
				if(n2==1) t=1;
				else if(n2==5) t=2;	
				else t=0;
			} if(t!=0){
				castling(arr[m1][n1],t,arr);
				dm=1;
			} if(dm==0){
				if(arr[m1][n1]=='c'||arr[m1][n1]=='C'){
					if(n1==0) arr[m1][n1]=='c'? k[0]=1:k[2]=1;
					else if(n1==7) arr[m1][n1]=='c'? k[3]=1:k[5]=1;
				} if(arr[m2][n2]=='!') 	arr[m1][n2] = ' ';
				replace(arr[m1][n1],arr[m2][n2],arr);
				space(arr);
				for(int i=0;i<8;i++){
					if(arr[7][i]=='p') update(arr[7][i]);
					if(arr[0][i]=='P') update(arr[0][i]);
			}}
		}
		if(check == 0) break;
		cout << "     Chon ngu, chon lai: ";
	} stt++;
	return 0;
}

int checkWinner(char a[8][8]){
	int v1=0,v2=0;
	for(int i=0;i<8;i++)
	for(int j=0;j<8;j++){
		if(a[i][j]=='v') v1=1;
		if(a[i][j]=='V') v2=1;
	} return v1==v2? 0: v1==1? 1:2;
}

void end(int& gg,int& out){
	Sleep(3000);
		while(1){
			if(gg++!=0) cout << endl << "   Cay cu a :)" << endl;
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

void start(char a[8][8]){
	vector<char>map(32,' ');
	{ 
	  map[0]  = 'c'; map[1]  = 'k'; map[2]  = 'b'; map[3]  = 'v';
	  map[4]  = 'h'; map[5]  = 'b'; map[6]  = 'k'; map[7]  = 'c';
	  for(int i=8;i<16;i++) 		map[i]  = 'p';
	  map[16] = 'C'; map[17] = 'K'; map[18] = 'B'; map[19] = 'V';
	  map[20] = 'H'; map[21] = 'B'; map[22] = 'K'; map[23] = 'C';
	  for(int i=24;i<32;i++) 		map[i]  = 'P';
	} for(int i=0;i<8;i++)
	  for(int j=0;j<8;j++)
		a[i][j] = ' ';
	for(int i=0;i<8;i++){
		a[0][i] = map[i];
		a[1][i] = map[i+8];	
		a[6][i] = map[i+24];
		a[7][i] = map[i+16];	
	} 
	space(a);
}

int main(){
	char a[8][8]; int k,stt=1,out=0;
	string name1,name2;
	int pl1=0,pl2=0,gg=0,x=0;
	int p[6];
	for(int i=0;i<6;i++) p[i] = 0;
	color(2);
	{
		cout << endl << "                  Chess Game" << endl << endl;
		color(1); cout << "     Player 1: "; cin >> name1;
		color(3); cout << endl << "     Player 2: "; cin >> name2;
		color(2);
	} system("cls");
	while(1){
		start(a);
		while(1){
			if(stt == 50){
				string newgame;
				system("cls");
				print(a);
				cout << "Press 'New' to start new game." << endl;
				Sleep(1000);
			} system("cls");
			gg=0;
			int time = input(a,stt,x,p,name1,name2);
			if(time==1) break;
			system("cls");
			print(a);
			k=checkWinner(a);
			if(k!=0) break;
		} if(k==1){
			color(1);
			cout << endl << "   The winner is: " << name1 << " (";
			color(2);
			cout << "Yellow";
			color(1);
			cout << ")" << endl;
		} else if(k==2){
			color(3);
			cout << endl << "   The winner is: " << name2 << " (";
			color(2);
			cout << "Green";
			color(3);
			cout << ")" << endl;
		} else cout << endl << "         No winner" << endl;
		if(k!=0) k==1? pl1++:pl2++;
		color(1);
		cout << endl << "     " << name1;
		color(2);
		cout << ": ";	color(1);
		cout << pl1;	color(3);
		cout << "     "<< name2;
		color(2);
		cout << ": ";	color(3);
		cout << pl2;	color(2);
		end(gg,out);
		if(out!=0) break;
	} //end game
	system("cls");
	cout << endl << "                  Chess Game" << endl << endl;
	if(pl1>pl2) color(1);
	else if(pl2>pl1) color(3);
	cout << endl << "     " << name1 << ": " << pl1 << "     "<< name2 << ": " << pl2 << endl << endl;
	system("pause");
}