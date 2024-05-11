#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    fstream imenik_ip;
    imenik_ip.open("imenik.txt");
    string ispisDatoteke;
    int n;
    cout << "Unesite broj ucenika:" << endl;
    cin >> n;
    cin.ignore();
    int brojac = 0;
    cout << "Ispis podataka:" << endl;
    while (getline(imenik_ip, ispisDatoteke))
    {
        cout << ispisDatoteke << endl;
        brojac++;
    }
    string *imena_ucenika = new string[brojac + n];
    imenik_ip.clear();
    imenik_ip.seekg(0, ios::beg);
    for (int i = 0; i < brojac; i++)
    {
        getline(imenik_ip, imena_ucenika[i]);
    }
    imenik_ip.close();
    for (int i = brojac; i < brojac + n; i++)
    {
        cout << "Unesite ime i prezime " << i + 1 << ". ucenika:" << endl;
        getline(cin, imena_ucenika[i]);
    }
    sort(imena_ucenika, imena_ucenika + brojac + n);
    imenik_ip.open("imenik.txt", ios::out);
    for (int i = 0; i < brojac + n; i++)
    {
        imenik_ip << imena_ucenika[i] << endl;
    }
    imenik_ip.close();
    delete[] imena_ucenika;
    return 0;
}
