#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;
//definiranje na stuktura
struct Covek
{
	int CovekRedenBRoj;
	string CovekIme;
	float CovekPoeni;
 	
};
//deklaracija na funkcii
void FunkVnesCovek(struct Covek covek[],int n);
bool Sortiranje(const Covek &c1,const Covek &c2);
int main()
{
	//kreiranje na instanca
	struct Covek covek[100];
	//deklariranje na vektor
	vector<struct Covek> vekCovek(100);
	
	int n;
	cout<<"\n VNESETE BROJ  ";
	cin>>n;
	//povik na funkicjata za vnes na podatoci
	FunkVnesCovek(covek,n);
	//dodeluvanje na niza od struktura vo vektor
	for(int i=0;i<n;i++)
		vekCovek.push_back(covek[i]);
	//povik na metoda sortiranje
	sort(vekCovek.begin(),vekCovek.end(),Sortiranje);
	//prikaz na podatoci sortirani
	cout<<"\n ....................................................";
	cout<<"\n Podatocite sortirani po poeni ";
	cout<<"\n ....................................................";
	for(vector<Covek>::iterator itr=vekCovek.begin();itr<vekCovek.end();++itr)
	{
		if(itr->CovekRedenBRoj!=0)
		{
			cout<<endl;
			cout<<"\t"<<itr->CovekRedenBRoj<<"  "<<itr->CovekIme<<"  "<<itr->CovekPoeni;
		}
	}
	//zapisuvanje na podatocite vo datoteka
	ofstream DatotekaTeona("INKI611.Milica.txt");
	DatotekaTeona<<"\n ....................................................";
	DatotekaTeona<<"Podatocite sortirani po poeni ";
	DatotekaTeona<<"\n ....................................................";
	for(vector<Covek>::iterator itr=vekCovek.begin();itr<vekCovek.end();++itr)
	{
		if(itr->CovekRedenBRoj!=0)
		{
			DatotekaTeona<<endl;
			DatotekaTeona<<"\t"<<itr->CovekRedenBRoj<<"  "<<itr->CovekIme<<"  "<<itr->CovekPoeni;
		}
	}
	DatotekaTeona.close();
}
//definicija za vnesuvanje na podatoci vo niza od struktura
void FunkVnesCovek(struct Covek covek[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"\n Reden broj => ";
		cin>>covek[i].CovekRedenBRoj;
		cout<<"\n Covek Ime => ";
		cin>>covek[i].CovekIme;
		cout<<"\n Covek Poeni => ";
		cin>>covek[i].CovekPoeni;
	}
}
//definiranje na metoda za sortiranje po broj na poeni
bool Sortiranje(const Covek &c1,const Covek &c2){
 		return c1.CovekPoeni>c2.CovekPoeni;
	 }

