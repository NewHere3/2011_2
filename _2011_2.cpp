#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

struct pora
{
    string vardai = "Error"; // 20 poziciju
    int technika[10] = {0};
    int artistiskumas[10] = {0};
    int technika_suma = 0;
    int artistiskumas_suma = 0;
};

void read(int& n, int& k, pora dalyviai[100]);
int balu_suma(int k, int balai[]);
void rusiavimas(int n, pora dalyviai[100]);
void write(int n, int k, pora dalyviai[100]);

int main()
{
    int n, k;
    pora dalyviai[100];
    read(n, k, dalyviai);
    rusiavimas(n, dalyviai);
    write(n, k, dalyviai);
    return 0;
}

void rusiavimas(int n, pora dalyviai[100])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (dalyviai[i].artistiskumas_suma + dalyviai[i].technika_suma < dalyviai[j].artistiskumas_suma + dalyviai[j].technika_suma)
            {
                //pora temp = dalyviai[i];
                //dalyviai[i] = dalyviai[j];
                //dalyviai[j] = temp;
                swap(dalyviai[i], dalyviai[j]);
            }
        }
    }
}

void read(int& n, int& k, pora dalyviai[100])
{
    ifstream duom("Duomenys.txt");
    duom >> n >> k;
    for (int i = 0; i < n; i++)
    {
        duom.ignore();
        char temp[21];
        duom.get(temp, 20);
        dalyviai[i].vardai=temp;
        for (int j = 0; j < k; j++)
        {
            duom >> dalyviai[i].technika[j];
        }
        for (int j = 0; j < k; j++)
        {
            duom >> dalyviai[i].artistiskumas[j];
        }
        dalyviai[i].technika_suma = balu_suma(k, dalyviai[i].technika);
        dalyviai[i].artistiskumas_suma = balu_suma(k, dalyviai[i].artistiskumas);
    }
}

int balu_suma(int k, int balai[])
{
    int suma = 0, maz = 100, didz = 0;
    for (int i = 0; i < k; i++)
    {
        suma += balai[i];
        if (maz > balai[i])maz = balai[i];
        if (didz < balai[i])didz = balai[i];
    }
    return suma-maz-didz;
}

void write(int n, int k, pora dalyviai[100])
{
    ofstream rez("Rezultatai.txt");
    for (int i = 0; i < n; i++)
    {
        rez << dalyviai[i].vardai << dalyviai[i].technika_suma + dalyviai[i].artistiskumas_suma << '\n';
    }
    rez.close();
}