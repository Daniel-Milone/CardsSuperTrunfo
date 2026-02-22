#include <stdio.h>
#include <string.h>

// ======================================================================
// Nível Mestre - Super Trunfo 2.0 com escolha de DOIS atributos + soma
// ======================================================================

typedef struct {
    char estado[3];              // ex: "SP", "RJ" 
    char codigo[4];              // ex: "01", "02"
    char nome[50];
    unsigned long populacao;
    float area;                  // km²
    float pib;                   // em bilhões de reais
    int pontos_turisticos;
    float densidade;             // calculado
    float pib_per_capita;        // calculado
} Carta;

// Função auxiliar para limpar buffer de entrada
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Mostra menu de atributos e retorna a escolha (1 a 6)
// Retorna 0 se escolha inválida
int mostrarMenuAtributos(int atributoProibido) {
    printf("\nEscolha o atributo para comparacao:\n");
    printf("1 - Populacao\n");
    printf("2 - Area (km²)\n");
    printf("3 - PIB (bilhoes)\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Populacional (menor vence)\n");
    printf("6 - PIB per Capita\n");

    if (atributoProibido != 0) {
        printf("(opcao %d ja foi escolhida anteriormente)\n", atributoProibido);
    }

    printf("Digite sua opcao (1-6): ");

    int opcao;
    if (scanf("%d", &opcao) != 1) {
        limparBuffer();
        return 0;
    }
    limparBuffer();

    if (opcao < 1 || opcao > 6 || opcao == atributoProibido) {
        return 0;
    }

    return opcao;
}

// Retorna o valor numérico do atributo escolhido
float getValorAtributo(const Carta* carta, int atributo) {
    switch (atributo) {
        case 1: return (float)carta->populacao;
        case 2: return carta->area;
        case 3: return carta->pib;
        case 4: return (float)carta->pontos_turisticos;
        case 5: return carta->densidade;
        case 6: return carta->pib_per_capita;
        default: return 0.0f;
    }
}

// Retorna nome descritivo do atributo
const char* getNomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "Populacao";
        case 2: return "Area (km²)";
        case 3: return "PIB (bilhoes)";
        case 4: return "Pontos Turisticos";
        case 5: return "Densidade Populacional (hab/km²)";
        case 6: return "PIB per Capita";
        default: return "Desconhecido";
    }
}

// Mostra uma carta de forma bonita
void mostrarCarta(const Carta* c, const char* titulo) {
    printf("\n%s\n", titulo);
    printf("  Cidade/Estado.....: %s (%s)\n", c->nome, c->estado);
    printf("  Codigo............: %s\n", c->codigo);
    printf("  Populacao.........: %lu habitantes\n", c->populacao);
    printf("  Area..............: %.2f km²\n", c->area);
    printf("  PIB...............: %.2f bilhoes de reais\n", c->pib);
    printf("  Pontos Turisticos.: %d\n", c->pontos_turisticos);
    printf("  Densidade.........: %.2f hab/km²\n", c->densidade);
    printf("  PIB per Capita....: %.2f reais\n", c->pib_per_capita);
}

int main() {
    Carta carta1 = {0};
    Carta carta2 = {0};

    // =================================================================
    // Cadastro das duas cartas
    // =================================================================
    printf("=== CADASTRO DA CARTA 1 ===\n");

    printf("Estado (sigla): ");
    scanf("%2s", carta1.estado);
    limparBuffer();

    printf("Codigo (ex: 01): ");
    scanf("%3s", carta1.codigo);
    limparBuffer();

    printf("Nome da cidade: ");
    fgets(carta1.nome, sizeof(carta1.nome), stdin);
    carta1.nome[strcspn(carta1.nome, "\n")] = 0;

    printf("Populacao: ");
    scanf("%lu", &carta1.populacao);

    printf("Area (km²): ");
    scanf("%f", &carta1.area);

    printf("PIB (bilhoes de reais): ");
    scanf("%f", &carta1.pib);

    printf("Pontos turisticos: ");
    scanf("%d", &carta1.pontos_turisticos);

    // Cálculos
    carta1.densidade     = (float)carta1.populacao / carta1.area;
    carta1.pib_per_capita = (carta1.pib * 1e9f) / (float)carta1.populacao;

    // ------------------ Carta 2 ------------------
    printf("\n=== CADASTRO DA CARTA 2 ===\n");

    printf("Estado (sigla): ");
    scanf("%2s", carta2.estado);
    limparBuffer();

    printf("Codigo (ex: 02): ");
    scanf("%3s", carta2.codigo);
    limparBuffer();

    printf("Nome da cidade: ");
    fgets(carta2.nome, sizeof(carta2.nome), stdin);
    carta2.nome[strcspn(carta2.nome, "\n")] = 0;

    printf("Populacao: ");
    scanf("%lu", &carta2.populacao);

    printf("Area (km²): ");
    scanf("%f", &carta2.area);

    printf("PIB (bilhoes de reais): ");
    scanf("%f", &carta2.pib);

    printf("Pontos turisticos: ");
    scanf("%d", &carta2.pontos_turisticos);

    carta2.densidade     = (float)carta2.populacao / carta2.area;
    carta2.pib_per_capita = (carta2.pib * 1e9f) / (float)carta2.populacao;

    // Mostrar as cartas cadastradas
    mostrarCarta(&carta1, "CARTA 1 CADASTRADA");
    mostrarCarta(&carta2, "CARTA 2 CADASTRADA");

    // =================================================================
    // Nível Aventureiro / Mestre - Escolha interativa de atributos
    // =================================================================

    int atributo1 = 0;
    int atributo2 = 0;

    printf("\n=== ESCOLHA OS ATRIBUTOS PARA A RODADA ===\n");

    // Primeiro atributo
    do {
        atributo1 = mostrarMenuAtributos(0);
        if (atributo1 == 0) {
            printf("Opcao invalida! Tente novamente.\n");
        }
    } while (atributo1 == 0);

    // Segundo atributo (não pode ser igual ao primeiro)
    do {
        atributo2 = mostrarMenuAtributos(atributo1);
        if (atributo2 == 0) {
            printf("Opcao invalida ou ja escolhida! Tente novamente.\n");
        }
    } while (atributo2 == 0);

    // =================================================================
    // Comparação dos dois atributos + soma
    // =================================================================

    float valor1_attr1 = getValorAtributo(&carta1, atributo1);
    float valor2_attr1 = getValorAtributo(&carta2, atributo1);

    float valor1_attr2 = getValorAtributo(&carta1, atributo2);
    float valor2_attr2 = getValorAtributo(&carta2, atributo2);

    // Pontos para cada carta (1 = vitória, 0 = empate, -1 = derrota)
    int pontos_attr1 = 0;
    int pontos_attr2 = 0;

    // Atributo 1
    if (atributo1 == 5) { // Densidade → menor vence
        if (valor1_attr1 < valor2_attr1) pontos_attr1 = 1;
        else if (valor1_attr1 > valor2_attr1) pontos_attr1 = -1;
    } else {
        if (valor1_attr1 > valor2_attr1) pontos_attr1 = 1;
        else if (valor1_attr1 < valor2_attr1) pontos_attr1 = -1;
    }

    // Atributo 2
    if (atributo2 == 5) {
        if (valor1_attr2 < valor2_attr2) pontos_attr2 = 1;
        else if (valor1_attr2 > valor2_attr2) pontos_attr2 = -1;
    } else {
        if (valor1_attr2 > valor2_attr2) pontos_attr2 = 1;
        else if (valor1_attr2 < valor2_attr2) pontos_attr2 = -1;
    }

    // Soma dos valores normalizados? Não — o desafio pede soma direta
    float soma1 = valor1_attr1 + valor1_attr2;
    float soma2 = valor2_attr1 + valor2_attr2;

    // Resultado final baseado na soma
    const char* resultado;
    if (soma1 > soma2) {
        resultado = "Carta 1 venceu a rodada!";
    } else if (soma2 > soma1) {
        resultado = "Carta 2 venceu a rodada!";
    } else {
        resultado = "Empate!";
    }

    // =================================================================
    // Exibição do resultado (bem organizada)
    // =================================================================

    printf("\n======================================\n");
    printf("       RESULTADO DA RODADA\n");
    printf("======================================\n");

    printf("Atributos escolhidos:\n");
    printf("  1) %s\n", getNomeAtributo(atributo1));
    printf("  2) %s\n\n", getNomeAtributo(atributo2));

    printf("Carta 1: %s (%s)\n", carta1.nome, carta1.estado);
    printf("  %s: %.2f\n", getNomeAtributo(atributo1), valor1_attr1);
    printf("  %s: %.2f\n", getNomeAtributo(atributo2), valor1_attr2);
    printf("  Soma: %.2f\n\n", soma1);

    printf("Carta 2: %s (%s)\n", carta2.nome, carta2.estado);
    printf("  %s: %.2f\n", getNomeAtributo(atributo1), valor2_attr1);
    printf("  %s: %.2f\n", getNomeAtributo(atributo2), valor2_attr2);
    printf("  Soma: %.2f\n\n", soma2);

    printf("Resultado: %s\n", resultado);
    printf("======================================\n");

    return 0;
}