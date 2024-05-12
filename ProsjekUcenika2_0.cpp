#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    int brUcenika;
    cout << "Unesite broj ucenika: ";
    cin >> brUcenika;
    cin.ignore();
    string imePrezime[100];
    double prosjek[100];
    for (int i = 0; i < brUcenika; i++)
    {
        cout << "Unesite prosjek " << i + 1 << ". ucenika: ";
        cin >> prosjek[i];
        cin.ignore();
        cout << "Unesite ime i prezime " << i + 1 << ". ucenika: ";
        getline(cin, imePrezime[i]);
    }
    for (int i = 0; i < brUcenika - 1; i++)
    {
        for (int j = i + 1; j < brUcenika; j++)
        {
            if (prosjek[i] < prosjek[j])
            {
                swap(prosjek[i], prosjek[j]);
                swap(imePrezime[i], imePrezime[j]);
            }
        }
    }
    fstream datOut("Ucenici.bin", ios::binary | ios::out);
    for (int i = 0; i < brUcenika; i++)
    {
        datOut.write((char *)&prosjek[i], sizeof(double));
        int len = imePrezime[i].size();
        datOut.write((char *)&len, sizeof(int));
        datOut.write((char *)&imePrezime[i], sizeof(string));
    }
    datOut.close();
    fstream datIn("Ucenici.bin", ios::binary | ios::in);
    for (int i = 0; i < brUcenika; i++)
    {
        string imePrezime;
        double prosjek;
        datIn.read((char *)&prosjek, sizeof(double));
        int len;
        datIn.read((char *)&len, sizeof(int));
        char *buffer = new char[len + 1];
        datIn.read(buffer, len);
        buffer[len] = '\0';
        imePrezime = buffer;
        delete[] buffer;
        cout << imePrezime << " " << prosjek << endl;
    }
    datIn.close();
    return 0;
}