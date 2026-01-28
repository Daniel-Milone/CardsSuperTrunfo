#include <stdio.h>

int main() {

    /* ===== CARTA 1 ===== */
    char estado1;
    char codigo1[5];
    char nome1[50];
    unsigned long int populacao1;
    float area1;
    float pib1;
    int pontos_turisticos1;

    float densidade1;
    float pib_per_capita1;
    float super_poder1;

    /* ===== CARTA 2 ===== */
    char estado2;
    char codigo2[5];
    char nome2[50];
    unsigned long int populacao2;
    float area2;
    float pib2;
    int pontos_turisticos2;

    float densidade2;
    float pib_per_capita2;
    float super_poder2;

    /* ===== ENTRADA DE DADOS ===== */

    printf("=== CADASTRO CARTA 1 ===\n");
    printf("Estado: ");
    scanf(" %c", &estado1);

    printf("Codigo: ");
    scanf("%4s", codigo1);

    printf("Nome da cidade: ");
    scanf(" %49[^\n]", nome1);

    printf("Populacao: ");
    scanf("%lu", &populacao1);

    printf("Area (km²): ");
    scanf("%f", &area1);

    printf("PIB (em bilhoes): ");
    scanf("%f", &pib1);

    printf("Pontos turisticos: ");
    scanf("%d", &pontos_turisticos1);

    printf("\n=== CADASTRO CARTA 2 ===\n");
    printf("Estado: ");
    scanf(" %c", &estado2);

    printf("Codigo: ");
    scanf("%4s", codigo2);

    printf("Nome da cidade: ");
    scanf(" %49[^\n]", nome2);

    printf("Populacao: ");
    scanf("%lu", &populacao2);

    printf("Area (km²): ");
    scanf("%f", &area2);

    printf("PIB (em bilhoes): ");
    scanf("%f", &pib2);

    printf("Pontos turisticos: ");
    scanf("%d", &pontos_turisticos2);

    /* ===== CÁLCULOS ===== */

    densidade1 = (float) populacao1 / area1;
    densidade2 = (float) populacao2 / area2;

    pib_per_capita1 = (pib1 * 1000000000.0f) / populacao1;
    pib_per_capita2 = (pib2 * 1000000000.0f) / populacao2;

    super_poder1 =
        (float) populacao1 +
        area1 +
        pib1 +
        pontos_turisticos1 +
        pib_per_capita1 +
        (1.0f / densidade1);

    super_poder2 =
        (float) populacao2 +
        area2 +
        pib2 +
        pontos_turisticos2 +
        pib_per_capita2 +
        (1.0f / densidade2);

    /* ===== EXIBIÇÃO DAS CARTAS ===== */

    printf("\n=== CARTA 1 ===\n");
    printf("Estado: %c\n", estado1);
    printf("Codigo: %s\n", codigo1);
    printf("Cidade: %s\n", nome1);
    printf("Populacao: %lu\n", populacao1);
    printf("Area: %.2f km²\n", area1);
    printf("PIB: %.2f bilhoes\n", pib1);
    printf("Pontos Turisticos: %d\n", pontos_turisticos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per Capita: %.2f reais\n", pib_per_capita1);
    printf("Super Poder: %.2f\n", super_poder1);

    printf("\n=== CARTA 2 ===\n");
    printf("Estado: %c\n", estado2);
    printf("Codigo: %s\n", codigo2);
    printf("Cidade: %s\n", nome2);
    printf("Populacao: %lu\n", populacao2);
    printf("Area: %.2f km²\n", area2);
    printf("PIB: %.2f bilhoes\n", pib2);
    printf("Pontos Turisticos: %d\n", pontos_turisticos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per Capita: %.2f reais\n", pib_per_capita2);
    printf("Super Poder: %.2f\n", super_poder2);

    printf("\n=== RESULTADO DA BATALHA ===\n");

printf("Populacao: %s\n",
    populacao1 > populacao2 ? "Carta 1 venceu" :
    populacao2 > populacao1 ? "Carta 2 venceu" : "Empate");

printf("Area: %s\n",
    area1 > area2 ? "Carta 1 venceu" :
    area2 > area1 ? "Carta 2 venceu" : "Empate");

printf("PIB: %s\n",
    pib1 > pib2 ? "Carta 1 venceu" :
    pib2 > pib1 ? "Carta 2 venceu" : "Empate");

printf("Pontos Turisticos: %s\n",
    pontos_turisticos1 > pontos_turisticos2 ? "Carta 1 venceu" :
    pontos_turisticos2 > pontos_turisticos1 ? "Carta 2 venceu" : "Empate");

/* Densidade: menor vence */
printf("Densidade Populacional: %s\n",
    densidade1 < densidade2 ? "Carta 1 venceu" :
    densidade2 < densidade1 ? "Carta 2 venceu" : "Empate");

printf("PIB per Capita: %s\n",
    pib_per_capita1 > pib_per_capita2 ? "Carta 1 venceu" :
    pib_per_capita2 > pib_per_capita1 ? "Carta 2 venceu" : "Empate");

printf("Super Poder: %s\n",
    super_poder1 > super_poder2 ? "Carta 1 venceu" :
    super_poder2 > super_poder1 ? "Carta 2 venceu" : "Empate");
        
    return 0;

}