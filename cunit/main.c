#include <stdio.h>
#include <stdlib.h>
#include "suite.h"
#include <CUnit/Basic.h>

int main()
{
    // Init de CUnit
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error(); // Initialisation du registre de tests
    CU_pSuite pSuite = NULL;   // Déclaration d'une pSuite de tests
    pSuite = CU_add_suite("Mes tests unitaires", NULL, NULL);
    if (pSuite == NULL)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    float *suite = creerSuite();
    initSuite(suite);
    float stat = 7;
    ajouterEnTeteApresDecalage(suite, &stat);
    stat = 6;
    ajouterEnTeteApresDecalage(suite, &stat);
    stat = 5;
    ajouterEnTeteApresDecalage(suite, &stat);
    stat = 4;
    ajouterEnTeteApresDecalage(suite, &stat);
    stat = 3;
    ajouterEnTeteApresDecalage(suite, &stat);
    afficheSuite(suite);
    stat = 2;
    ajouterEnTeteApresDecalage(suite, &stat);
    stat = 1;
    ajouterEnTeteApresDecalage(suite, &stat);
    afficheSuite(suite);
    moyenne(suite);
    plusPetitElement(suite);
    plusGrandElement(suite);
    printf("Nbre element renseignés %d \n", nombreElementsRenseignesDansSuite(suite));
    free(suite);

    if (CU_add_test(pSuite, "Init de la suite", tu_initialisation) == NULL) // Ajout test unitaire dans la pSuite
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    CU_basic_set_mode(CU_BRM_VERBOSE); // Lancement des tests
    CU_basic_run_tests();
    CU_basic_show_failures(CU_get_failure_list());
    CU_cleanup_registry(); // Clean up des registres et autres data de CUnit
    return CU_get_error();
}
