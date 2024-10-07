#include <stdio.h>
#include <stdlib.h>
#include "suite.h"
#include <CUnit/Basic.h>

#define TAILLE_SUITE 5
#define TRUE 1
#define FALSE 0

float *creerSuite()
{
    float *suite = (float *)malloc(TAILLE_SUITE * sizeof(float));
    return suite;
}
void initSuite(float *suite)
{
    for (int i = 0; i < TAILLE_SUITE; i++)
    {
        suite[i] = -1.0f;
    }
}
void ajouterEnTeteApresDecalage(float *suite, float *stat)
{
    for (int i = TAILLE_SUITE - 1; i > 0; i--)
    {
        suite[i] = suite[i - 1];
    }
    suite[0] = *stat;
}
void afficheSuite(float *suite)
{
    for (int i = 0; i < TAILLE_SUITE; i++)
    {
        printf("Index %02d Valeur %f \n", i, suite[i]);
    }
}
void moyenne(float *suite)
{
    float somme = 0;
    for (int i = 0; i < TAILLE_SUITE; i++)
    {
        somme += suite[i];
    }
    printf("Moyenne : %f \n", somme / TAILLE_SUITE);
}
void plusPetitElement(float *suite)
{
    float min = suite[0];
    for (int i = 1; i < TAILLE_SUITE; i++)
    {
        if (suite[i] < min)
        {
            min = suite[i];
        }
    }
    printf("Plus petit element : %f \n", min);
}
void plusGrandElement(float *suite)
{
    float max = suite[0];
    for (int i = 1; i < TAILLE_SUITE; i++)
    {
        if (suite[i] > max)
        {
            max = suite[i];
        }
    }
    printf("Plus grand element : %f \n", max);
}
int nombreElementsRenseignesDansSuite(float *suite)
{
    int nbreElement = 0;
    for (int i = 0; i < TAILLE_SUITE; i++)
    {
        if (suite[i] != 0)
        {
            nbreElement++;
        }
    }
    return nbreElement;
}

void tu_initialisation(void)
{
    CU_ASSERT_PTR_NOT_NULL(creerSuite());
}