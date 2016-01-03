#include <iostream>
#include <cstdlib>

using namespace std;

// Résolution d'un système linéaire d'entiers, par la méthode du pivot de Gauss

void afficherMatrice(int matrice[], int nbInc, int nbElem);
void saisirMatrice(int matrice[], int nbInc, int nbElem);
void methodeGauss(int matrice[], int taille); // Rends la matrice triangulaire inférieure
void echangerLigne(int matrice[], int taille, int a, int b);


int main(int argc, char *argv[])
{
    int nbInc = 0;
    cout << "Combien y'a-il d'inconnues ?" << endl;
    cin >> nbInc;
    int nbElem = nbInc * (nbInc + 1);

    int matrice[nbElem];
    for(int i = 0 ; i < nbElem ; i++)
    {
        matrice[i] = 0;
    }

    saisirMatrice(matrice, nbInc, nbElem);

    methodeGauss(matrice, nbInc);

    afficherMatrice(matrice, nbInc, nbElem);

    return EXIT_SUCCESS;
}

void afficherMatrice(int matrice[], int nbInc, int nbElem)
{
    for(int i = 0 ; i < nbElem ; i++)
    {
        cout << matrice[i] << " ";
        if((i - nbElem + 2) % (nbInc + 1) == 0)
            cout << "| ";
        else if((i + 1) % (nbInc + 1) == 0)
            cout << endl;
    }
}

void saisirMatrice(int matrice[], int nbInc, int nbElem)
{
    char nomInc[nbInc + 1];
    for(int i = 0 ; i < nbInc ; i++)
        nomInc[i] = i + 97;
    nomInc[nbInc] = '?';
    for(int elemSaisis = 0 ; elemSaisis < nbElem ; elemSaisis++)
    {
        cout << nomInc[elemSaisis % (nbInc + 1)] << " = ";
        cin >> matrice[elemSaisis];
    }
}

void methodeGauss(int matrice[], int taille)
{
    int posPivot = 0;
    bool changerPivot = matrice[0] == 0;

    while(changerPivot && posPivot < taille)
    {
        posPivot++;
        changerPivot = matrice[posPivot * (taille + 1)] == 0;
    }

    if(posPivot != 0)
    {
        echangerLigne(matrice, taille, 0, posPivot);
    }

    return;
}

void echangerLigne(int matrice[], int taille, int a, int b)
{
    for(int i = 0 ; i < taille + 1 ; i++)
    {
        matrice[a * (taille + 1) + i] = matrice[b * (taille + 1) + i] + matrice[a * (taille + 1) + i];
        matrice[b * (taille + 1) + i] = matrice[a * (taille + 1) + i] - matrice[b * (taille + 1) + i];
        matrice[a * (taille + 1) + i] = matrice[a * (taille + 1) + i] - matrice[b * (taille + 1) + i];
    }
}

