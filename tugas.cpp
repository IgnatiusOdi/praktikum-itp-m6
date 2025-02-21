#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void UpperCase(string &temp,string kata){
    temp="";
	for(int i=0;i<kata.size();i++){
        temp+=toupper(kata[i]);
	}
}

void PP(string playertemp, int scoretemp, int wordtemp, vector<vector<char> > papan,int ukuran){
	system("cls");

	cout<<"Player : "<<playertemp<<endl;
	cout<<"Score : "<<scoretemp<<endl;
	cout<<"Word : "<<wordtemp<<endl;

	for(int y=0;y<ukuran;y++){
		for(int x=0;x<ukuran*2+1;x++){
			if(x%2==0) cout<<'+';
			else cout<<'-';
		}
		cout<<endl;
		for(int x=0;x<ukuran;x++){
            cout<<'|';
            cout<<papan[y][x];
		}
        cout<<'|';
        cout<<endl;
	}
	for(int x=0;x<ukuran*2+1;x++){
        if(x%2==0) cout<<'+';
        else cout<<'-';
	}
	cout<<endl;
}

void MainMenu(){
	system("cls");
	cout<<"=== PLAY WITH WORDS ==="<<endl;
	cout<<"1. Play"<<endl;
	cout<<"2. Dictionary"<<endl;
	cout<<"3. High Score"<<endl;
	cout<<"0. Quit"<<endl;
	cout<<">>> ";
}

void Dictionary(){
	system("cls");
	cout<<"=== DICTIONARY ==="<<endl;
	cout<<"1. Lihat Kata"<<endl;
	cout<<"2. Tambah Kata"<<endl;
	cout<<"3. Hapus Kata"<<endl;
	cout<<"0. Back"<<endl;
	cout<<">>> ";
}

void LihatKata(vector<string> book){
	system("cls");
	cout<<"=== LIHAT KATA ==="<<endl;
	for(int i=0;i<book.size();i++){
		if(i+1<10) cout<<"0"<<i+1<<". "<<book[i]<<endl;
		else cout<<i+1<<". "<<book[i]<<endl;
	}
	system("pause");
}

void TambahKata(){
	system("cls");
	cout<<"=== TAMBAH KATA ==="<<endl;
	cout<<"Kata : ";
}

void HapusKata(){
	system("cls");
	cout<<"=== HAPUS KATA ==="<<endl;
	cout<<"Kata : ";
}

void Highscore(vector<string> player, vector<int> score, vector<int> word){
	system("cls");
	cout<<"=== HIGH SCORE ==="<<endl;
	for(int i=0;i<player.size();i++){
        cout<<i+1<<". "<<player[i]<<endl;
        cout<<"   Score : "<<score[i]<<endl;
        cout<<"   Word  : "<<word[i]<<endl;
        cout<<endl;
	}
	system("pause");
}

int main(){
	int menu;
	bool quit,play,back;

	string playertemp;
	int scoretemp;
	int wordtemp;

	string kata;
	string temp;
	vector<string> katatemp;
	char tempkata;

	vector<string> book {"PRAKTIKUM","WEEK","ENAM","LAB","EMPAT","MATERI","TUGAS","TENTANG","ARRAY","STRING"};
	int menu1;
	bool boleh;

	vector<string> player;
	vector<int> score;
	vector<int> word;

	do{
		menu=0;
		quit=false;

		MainMenu(); cin>>menu;
		if(menu==1){
            int ukuran=0;
            for(int i=0;i<book.size();i++){
                if(ukuran<book[i].size()) ukuran=book[i].size();
            }
            vector<vector<char>>papan (ukuran, vector<char>(ukuran,' '));
            scoretemp=0;
            wordtemp=0;
            play=true;

            system("cls");
            cout<<"Masukkan Nama Player : "; cin.ignore(); getline(cin,playertemp);
            while(play){
                bool format=true;
                int syarat=0;
                boleh=false;

                PP(playertemp,scoretemp,wordtemp,papan,ukuran);
                cout<<">>> "; getline(cin,kata);
                UpperCase(temp,kata);
                kata=temp;
                temp="";

                //Cek Format Penulisan
                for(int i=0;i<kata.size();i++){
                    if( (kata[i]=='_' && (syarat==0||syarat==2)) || (kata[i]==',' && syarat==1) )
                        syarat+=1;
                }
                if(syarat!=3){
                    format=false;
                }

                //Potong Inputan
                if(kata=="EXIT GAME") play=false;
                else if(!format){
                    cout<<"Format penulisan salah"<<endl;
                }
                else{
                    kata+="_";
                    for(int i=0;i<kata.size();i++){
                        if(kata[i]=='_' || kata[i]==','){
                            katatemp.push_back(temp);
                            temp="";
                        }
                        else temp+=kata[i];
                    }

                    //Mengubah koordinat menjadi int
                    stringstream ubahx(katatemp[1]);
                    int x=0;
                    ubahx>>x;
                    x-=1;
                    stringstream ubahy(katatemp[2]);
                    int y=0;
                    ubahy>>y;
                    y-=1;

                    //Cek kata di book
                    for(int i=0;i<book.size();i++){
                        if(katatemp[0]==book[i]) boleh=true;
                    }
                    if(!boleh) cout<<"Gagal menginputkan kata (kata tidak terdaftar di dalam dictionary)!"<<endl;

                    boleh=false;

                    //Cek posisi
                    if(katatemp[3]=="DOWN"){
                        if(x>-1 && x<ukuran && y>-1 && y<ukuran){
                            if(y+katatemp[0].size()-1<ukuran) boleh=true; //cek ukuran
                        }
                        if(boleh){
                            tempkata=' ';
                            int tempy=y;
                            bool oke=true;
                            //Cek kata cocok
                            for(int i=0;i<katatemp[0].size();i++){
                                tempkata=katatemp[0][i];
                                if(papan[tempy][x]==' ' || papan[tempy][x]==tempkata){
                                    tempy+=1;
                                }
                                else oke=false;
                            }
                            if(oke){
                                for(int i=0;i<katatemp[0].size();i++){
                                    tempkata=katatemp[0][i];
                                    papan[y][x]=tempkata;
                                    y+=1;
                                    scoretemp+=20;
                                }
                                wordtemp+=1;
                            }
                            else cout<<"Gagal menginputkan kata (kata tidak cocok)!"<<endl;
                        }
                        if(!boleh) cout<<"Gagal menginputkan kata (koordinat salah)!"<<endl;
                    }
                    else if(katatemp[3]=="RIGHT"){
                        if(x>-1 && x<ukuran && y>-1 && y<ukuran){
                            if(x+katatemp[0].size()-1<ukuran) boleh=true;
                        }
                        if(boleh){
                            tempkata=' ';
                            int tempx=x;
                            bool oke=true;

                            for(int i=0;i<katatemp[0].size();i++){
                                tempkata=katatemp[0][i];
                                if(papan[y][tempx]==' ' || papan[y][tempx]==tempkata){
                                    tempx+=1;
                                }
                                else oke=false;
                            }
                            if(oke){
                                for(int i=0;i<katatemp[0].size();i++){
                                    tempkata=katatemp[0][i];
                                    papan[y][x]=tempkata;
                                    x+=1;
                                    scoretemp+=20;
                                }
                                wordtemp+=1;
                            }
                            else cout<<"Gagal menginputkan kata (kata tidak cocok)!"<<endl;

                        }
                        if(!boleh) cout<<"Gagal menginputkan kata (koordinat salah)!"<<endl;
                    }
                    else cout<<"Gagal menginputkan kata (arah salah)"<<endl;

                    katatemp.clear();
                }
                system("pause");
            }
            player.push_back(playertemp);
            score.push_back(scoretemp);
            word.push_back(wordtemp);
            for(int i=0;i<player.size();i++){
                if(scoretemp > score[i]){
                    for(int j=player.size()-1;j>i;j++){
                        player[j] = player[j-1];
                        score[j] = score[j-1];
                        word[j] = word[j-1];
                    }
                    player[i]=playertemp;
                    score[i]=scoretemp;
                    word[i]=wordtemp;
                    i = player.size();
                }
            }
		}
		else if(menu==2){
			do{
				menu1=0;
				back=false;

				Dictionary(); cin>>menu1;
				if(menu1==1){
					LihatKata(book);
				}
				else if(menu1==2){
					boleh=true;
					TambahKata(); cin.ignore(); getline(cin,kata);

					UpperCase(temp,kata);

                    if(kata.size()==0) boleh=false;

					for(int i=0;i<kata.size();i++){
						if ((kata[i]<'A'||kata[i]>'Z')&&(kata[i]<'a'||kata[i]>'z')) boleh=false;
					}

					if(boleh){
						for(int i=0;i<book.size();i++){
							if(book[i]==temp) boleh=false;
						}
						if(boleh){
                            book.push_back(temp);
                            cout<<"Kata "<<kata<<" berhasil ditambahkan!"<<endl;
						}
						else cout<<"Gagal tambah kata! Kata "+kata+" sudah terdaftar."<<endl;
					}
					else cout<<"Gagal tambah kata! Kata "+kata+" mengandung spasi atau karakter lain selain huruf."<<endl;

					system("pause");
				}
				else if(menu1==3){
					int pos=-1;
					HapusKata(); cin.ignore(); getline(cin,kata);

					UpperCase(temp,kata);

					for(int i=0;i<book.size();i++){
						if(temp==book[i]){
		                    pos=i;
		                    book.erase(book.begin()+pos);
						}
					}

					if(pos>=0) cout<<"Kata "<<kata<<" berhasil dihapus!"<<endl;
					else cout<<"Gagal hapus kata! Kata "<<kata<<" tidak ditemukan."<<endl;

					system("pause");
				}
				else if(menu1==0){
					back=true;
				}
				else{
					cout<<"Invalid!"<<endl;
					system("pause");
				}
			}while(!back);
		}
		else if(menu==3){
			Highscore(player,score,word);
		}
		else if(menu==0){
			quit=true;
		}
		else{
			cout<<"Invalid!"<<endl;
			system("pause");
		}
	}while(!quit);

	return 0;
}
