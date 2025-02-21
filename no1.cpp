#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

void MainMenu(){
	system("cls");
	cout<<"=== TYPE RACER ==="<<endl;
	cout<<"1. Play"<<endl;
	cout<<"2. Highscore"<<endl;
	cout<<"0. Exit"<<endl;
	cout<<">>> ";
}

void Highscore(int ctr,string player[],int timer[],int word[],int salah[]){
	system("cls");
	for(int i=0;i<ctr;i++){
		cout<<i+1<<". "<<player[i]<<endl;
		cout<<"   Timer : "<<timer[i]<<endl;
		cout<<"   Word : "<<word[i]<<endl;
		cout<<"   Salah : "<<salah[i]<<endl;
	}
	system("pause");
}

int main(){
	srand(time(0));

	string dictionary[]={"praktikum","week","enam","lab","empat","materi","tugas","tentang","array","string"};
	string soal[10];

	string player[5];
	int timer[]={0,0,0,0,0}, word[5], salah[]={0,0,0,0,0};
	int ctr=0;

	char menu;
	do{
		menu='/';
		MainMenu(); cin>>menu;
		if(menu=='0'){
			menu='0';
		}
		else if(menu=='1'){
			system("cls");
			cout<<"Nama Player : "; cin.ignore(); getline(cin, player[ctr]);

			int jawab=0;
			int ctrsoal=rand()%6+5;
			word[ctr]=ctrsoal;

			for(int i=0;i<ctrsoal;i++){
				int random=rand()%10;
				soal[i]=dictionary[random];
				for(int j=0;j<soal[i].size();j++){
					int besar=rand()%2+1;
					if(besar==1) soal[i][j]=toupper(soal[i][j]);
				}
			}

			int counter=0;
			string jumlah[20];

			while(jawab<ctrsoal)
			{
				system("cls");
				cout<<"Nama Player : "<<player[ctr]<<endl;
				cout<<endl<<"===== CIAYO GUYS! ====="<<endl;
				cout<<"Player : "<<player[ctr]<<endl;
				cout<<"Timer  : "<<timer[ctr]<<endl;
				cout<<"Salah  : "<<salah[ctr]<<endl<<endl;
				for(int i=0;i<ctrsoal;i++){
					cout<<soal[i]<<" ";
				}
				cout<<endl;
				string jawaban[ctrsoal];

				cout<<"Kata ke "<<jawab+1<<" : "; cin>>jawaban[jawab];

				string temp = to_string(jawab+1);
				jumlah[counter] = "Kata ke "+temp+" : "+jawaban[jawab];

				counter++;
				if(jawaban[jawab]!=soal[jawab]){
					salah[ctr]++;
					timer[ctr]++;
				}
				else{
					timer[ctr]++;
					jawab++;
				}
			}
			system("cls");
			cout<<"Nama Player : "<<player[ctr]<<endl;
			cout<<endl<<"===== CIAYO GUYS! ====="<<endl;
			cout<<"Player : "<<player[ctr]<<endl;
			cout<<"Timer  : "<<timer[ctr]<<endl;
			cout<<"Salah  : "<<salah[ctr]<<endl<<endl;
			for(int i=0;i<ctrsoal;i++){
				cout<<soal[i]<<" ";
			}
			cout<<endl;
			for(int i=0;i<counter;i++){
				cout<<jumlah[i]<<endl;
			}

			cout<<endl<<"Selamat "<<player[ctr]<<", anda berhasil menyelesaikan kalimat sepanjang "
				<<ctrsoal<<endl<<"kata dalam waktu "<<timer[ctr]<<" dengan kesalahan menulis sebanyak "
				<<salah[ctr]<<"x !"<<endl<<endl;
			system("pause");
			ctr++;
		}
		else if(menu=='2'){
			Highscore(ctr,player,timer,word,salah);
		}
	}while(menu!='0');

	return 0;
}
