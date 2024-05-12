#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;
struct Ucenik
{
    string ime;
    string prezime;
    double prosjekOcjena;
};
bool usporedbaProsjeka(const Ucenik &a,const Ucenik &b){
    return a.prosjekOcjena > b.prosjekOcjena;
}
int main()
{
    vector<Ucenik> ucenici;
    ifstream input("ucenici.dat", ios::binary);
    if(!input){
        cerr << "Neuspjelo otvaranje datoteke!" << endl;
        return 1;
    }
    Ucenik temp;
    while(input.read(reinterpret_cast<char *>(&temp),sizeof(Ucenik))){
        ucenici.push_back(temp);
    }
    input.close();
    int n;
    cout << "Unesite broj novih ucenika: ";
    cin >> n;
    for (int i = 0; i < n;i++)
    {
        cout << "Unesite ime,prezime i prosjek ocjena za ucenika " << i + 1 << ": ";
        Ucenik noviUcenik;
        cin >> noviUcenik.ime >> noviUcenik.prezime >> noviUcenik.prosjekOcjena;
        ucenici.push_back(noviUcenik);
    }
    sort(ucenici.begin(), ucenici.end(), usporedbaProsjeka);
    ofstream output("ucenici.dat", ios::binary);
    if(!output)
    {
        cerr << "Datoteka se nije uspjela otvoriti!" << endl;
        return 1;
    }
    for(const auto &ucenik:ucenici){
        output.write(reinterpret_cast<const char *>(&ucenik), sizeof(Ucenik));
    }
    output.close();
    cout << "Podaci su uspjesno zapisani u datoteku." << endl;
    return 0;
}