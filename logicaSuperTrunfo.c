#include <stdio.h>
#include <locale.h> // Biblioteca para usar separadores de milhar com printf

int main() {

    setlocale(LC_ALL, ""); // Ativa o locale do sistema (útil para separadores de milhar)

    // Declaração das variáveis para armazenar os dados das duas cartas
    char estado1[3], estado2[3];               
    char codigo1[4], codigo2[4];               
    char cidade1[20], cidade2[20];             
    int pontoturistico1, pontoturistico2;     
    unsigned long int populacao1, populacao2;  
    float area1, area2, pib1, pib2;           
    float densidade1, densidade2, pibpercapita1, pibpercapita2; 
    float superpoder1, superpoder2;

    // Coleta de dados da carta 1
    printf("Digite o estado (UF): ");
    scanf("%2s", estado1);
    
    printf("Digite o código: ");
    scanf("%3s", codigo1);

    printf("Digite a cidade (sem espaço): ");
    scanf("%19s", cidade1);

    printf("Digite o número de habitantes: ");
    scanf("%lu", &populacao1);

    printf("Digite a área em km²: ");
    scanf("%f", &area1);

    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &pib1);

    printf("Digite a quantidade de pontos turísticos: ");
    scanf("%d", &pontoturistico1);

    // Coleta de dados da carta 2
    printf("\nAgora vamos registrar as informações da carta 2\n");

    printf("Digite o estado (UF): ");
    scanf("%2s", estado2);

    printf("Digite o código: ");
    scanf("%3s", codigo2);

    printf("Digite a cidade (sem espaço): ");
    scanf("%19s", cidade2);

    printf("Digite o número de habitantes: ");
    scanf("%lu", &populacao2);

    printf("Digite a área em km²: ");
    scanf("%f", &area2);

    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &pib2);

    printf("Digite a quantidade de pontos turísticos: ");
    scanf("%d", &pontoturistico2);


    // Cálculo dos indicadores para a carta 1
    densidade1 = (float)populacao1 / area1; // densidade populacional = população / área
    pibpercapita1 = pib1 * 1000000000 / (float)populacao1; // PIB per capita = PIB total (em reais) / população
    superpoder1 = populacao1 + area1 + (pib1 * 1000000000) + pontoturistico1 + pibpercapita1 + (1.0f / densidade1);
    // Superpoder é uma soma de vários atributos, incluindo o inverso da densidade (ex: menor densidade = maior valor aqui)

    // Cálculo dos indicadores para a carta 2
    densidade2 = (float)populacao2 / area2;
    pibpercapita2 = pib2 * 1000000000 / (float)populacao2;
    superpoder2 = populacao2 + area2 + (pib2 * 1000000000.0f) + pontoturistico2 + pibpercapita2 + (1.0f / densidade2);
  
    // Comparação entre as cartas, com base no PIB per capita
    printf("\nComparação de cartas (Atributo: Pib per Capita)\n");

    // Aqui usamos %'.0f para formatar com separador de milhar e 0 casas decimais
    printf("Carta 1 - %s (%s): %'.0f\n", cidade1, estado1, pibpercapita1);
    printf("Carta 2 - %s (%s): %'.0f\n", cidade2, estado2, pibpercapita2);

    // Verifica qual cidade vence com base no PIB per capita
    if (pibpercapita1 > pibpercapita2){
        printf ("Carta 1 (%s) venceu! \n", cidade1);
    } else {
        printf ("Carta 2 (%s) venceu! \n", cidade2);
    }

    return 0; // Fim do programa
}
