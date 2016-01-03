#include <iostream>
#include <cstdlib>

using namespace std;

// Résolution d'un système linéaire d'entiers, par la méthode du pivot de Gauss

void afficherMatrice(int matrice[], int nbInc, int nbElem)
{
    cout << endl;
    for(int i = 0 ; i < nbElem ; i++)
    {
        cout << matrice[i] << " ";
        if((i - nbElem + 2) % (nbInc + 1) == 0)
        {
            cout << "| ";
        }
        if((i + 1) % (nbInc + 1) == 0)
        {
            cout << endl;
        }
    }
}

void saisirMatrice(int matrice[], int nbInc, int nbElem)
{
    char nomInc[nbInc + 1];
    for(int i = 0 ; i < nbInc ; i++)
    {
        nomInc[i] = i + 97;
    }
    nomInc[nbInc] = '?';

    int elemSaisis = 0;
    while(elemSaisis < nbElem)
    {
        cout << nomInc[elemSaisis % (nbInc + 1)] << " = ";
        cin >> matrice[elemSaisis];
        cout << endl;

        elemSaisis++;
    }
    return;
}

int main()
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

    afficherMatrice(matrice, nbInc, nbElem);

    return EXIT_SUCCESS;
}
