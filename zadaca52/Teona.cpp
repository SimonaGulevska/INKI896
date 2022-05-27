#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;
struct Covek
{
	int CovekRedenBRoj;
	string CovekIme;
	float CovekPoeni;
 	
};
void FunkVnesCovek(struct Covek covek[],int n);
bool Sortiranje(const Covek &c1,const Covek &c2);
int main()
{
	struct Covek covek[100];
	vector<struct Covek> vekCovek(100);
	
	int n;
	cout<<"\n VNESETE BROJ  ";
	cin>>n;
	FunkVnesCovek(covek,n);
	for(int i=0;i<n;i++)
		vekCovek.push_back(covek[i]);
	sort(vekCovek.begin(),vekCovek.end(),Sortiranje);
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
	ofstream DatotekaTeona("INKI896.TeonaBojoska.txt");
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
bool Sortiranje(const Covek &c1,const Covek &c2){
 		return c1.CovekPoeni>c2.CovekPoeni;
	 }

