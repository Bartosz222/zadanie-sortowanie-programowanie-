#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class sortowanie{
	public:
		ifstream plik1;
		ofstream plik2;
		vector <string> tab;
		vector <int> t;
		string napis;
		int liczba;
		int liczba2;
		
	sortowanie();
	~sortowanie();
	void menu();
	void wMenu(int x);
	void wypisz();
	void wczytajPlik();
	void sortowanieA();
	void sortowanieB();
	void sortowanieC();
	void sortowanieD();
};
sortowanie::sortowanie(){
	plik1.open("wejscie.txt");
	plik2.open("wyjscie.txt");
}
sortowanie::~sortowanie(){
	plik1.close();
	plik2.close();
}
void sortowanie::menu(){
	int x;
	cout<<"1.Wycztaj plik"<<endl;
	cout<<"2.Sortuj alfabetycznie"<<endl;
	cout<<"3.Sortuj w koljenosci odwrotnej"<<endl;
	cout<<"4.Sortuj wedlug dlugosci wyrazow"<<endl;
	cout<<"5.Sortuj wedlug wagi wyrazu"<<endl;
	cout<<"Twoj wybor:";
	cin>>x;
	system("cls");
	wMenu(x);
}
void sortowanie::wMenu(int x){
	switch(x){
		case 1:
			wczytajPlik();
			break;
		case 2:
			sortowanieA();
			break;
		case 3:
			sortowanieB();
			break;
		case 4:
			sortowanieC();
			break;
		case 5:
			sortowanieD();
			break;
	}
}
void sortowanie::wczytajPlik(){
	if(!plik1.good()&&plik2.good()){
		cout<<"Blad"<<endl;
		exit(0);
	}
	else{
		string napis;
		while(!plik1.eof()){
			getline(plik1,napis);
			tab.push_back(napis);
		}
		cout<<"Wczytano wyrazy z pliku!"<<endl;
		system("pause");
		system("cls");
		menu();
	}
}
void sortowanie::sortowanieA(){
	sort(tab.begin(),tab.end());
	for(int i=0;i<tab.size();i++){
        cout<<tab[i]<<endl;
    }
    wypisz();
	system("pause");
	system("cls");
	menu();
}
void sortowanie::sortowanieB(){
	
	sort(tab.begin(),tab.end(),greater<string>());
	for(int i=0;i<tab.size();i++){
        cout<<tab[i]<<endl;
    }
    wypisz();
	system("pause");
	system("cls");
	menu();
}
void sortowanie::sortowanieC(){
	t.clear();
	for(int i=0;i<=tab.size();i++){
		napis = tab[i];
		t.push_back(napis.length());
		napis="";
	}
	sort(t.begin(),t.end());
	for(int i=0;i<=t.size()-2;i++){
		cout<<t[i]<<endl;
	}
    system("pause");
	system("cls");
	menu();
}
void sortowanie::sortowanieD(){
	t.clear();
	for(int i=0;i<=tab.size();i++){
		napis = tab[i];
		for(int j=0;j<=napis.length();j++){
			liczba = (int)napis[i]-96;
			
		}
	}
}
void sortowanie::wypisz(){
	for(int i=0;i<tab.size();i++){
        plik2<<tab[i]<<endl;
    }
}
int main() {
	sortowanie s1;
	s1.menu();
	return 0;
}
