/*alio by supr10.*/


#include "Filewriter.h"
#include "Fileopener.h"
#include <conio.h>
#include <string>
#include <windows.h>
#include <windows.h>
#include <shellapi.h>

#define maxSize 100

using namespace std;
using namespace fileSystem;

int main(int argc,char *argv[]){
	//variables declarations
	if(argc==2){
		cout<<openFile(argv[1]);
		system("pause");
	}
	char cmd;
	int lines;
	char fileName[maxSize];
	
	//main
	cout<<"welcome to alio!"<<endl<<"press h for the help menu."<<endl;
	getch();
	system("cls");
	while(true){
		cmd=getch();
		switch (cmd){
			case 'n':
				cout<<"file name: ";
				cin>>fileName;
				cout<<"press 'q' to quit"<<endl;
				writeFile(fileName);
				break;
			case 'q':{
				int chc=MessageBox(0,"are you sure?","quit",MB_YESNO);
				if(chc==6){exit(0);}
				break;}
			case 'h':
				cout<<"help on commands:"<<endl<<"press:"<<endl<<"h to display help"
				<<" (this!)"<<endl<<"n to write a new file"<<endl<<"o to open a file("
				<<"read only)"<<endl<<"c to enter a cmd command"<<endl
				<<"m to clear screen"<<endl<<"f to freeze the screen"<<endl<<"t to make sound"
				<<endl<<"w to shearch something on stack overflow"<<endl<<"q to quit"<<endl;
				system("pause");
				system("cls");
				break;
			case 'm':
				system("cls");
				break;
			case 'f':
				cout<<"press 'q' to unfreeze"<<endl;
				char cmd;
				while(cmd!='q'){cmd=getch();} 
			case 't':
				cout<<"\a";
				break;
			case 'o':
				char path[maxSize];
				cout<<"file path: ";
				cin>>path;
				cout<<endl;
				cout<<openFile(path);
				system("pause");
				break;
			case 'w':{
				ShellExecuteW(0, 0, L"http://stackoverflow.com/", 0, 0 , SW_SHOW );
				break;
			}
			case 'c':
				string C;
				cout<<"enter a command: ";
				getline(cin,C);
				const char* C2 = C.c_str();
				system(C2);
				break;
			//to mod it,please put the rest of the code here.
			
		}
	}
	
	//end
	return 0;
}
