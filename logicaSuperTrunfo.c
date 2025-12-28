#include <stdio.h>
#include <string.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades.

int main()
{
  // Área para definição das variáveis para armazenar as propriedades das cidades
  char estado1[10]= "RJ", estado2[10]= "SP";
  char codigoDaCarta1[10] = "A01", codigoDaCarta2[10] = "B02";
  char cidade1[20] = "Rio de Janeiro", cidade2[20] = "São Paulo", cidadeVencedora[20];
  unsigned long int populacao1 = 6200000, populacao2 = 11450000;
  int pontoTuristico1 = 12, pontoTuristico2 = 15;
  float area1 = 1200.33, area2 = 1521.11, pib1 = 359.0, pib2= 828.0;
  float densidadePopulacional1, densidadePopulacional2;
  float pibPerCapita1, pibPerCapita2;
  float superPoder1, superPoder2;

  /*
  // Área para entrada de dados
  printf("===== PREENCHA 2 CARTAS =====:\n\n");

  // DADOS DE ENTRADA DA CARTA 1
  printf("\n\n== CARTA 1 ==\n");
  printf("Digite a sigla do ESTADO da federação em que fica localizado a cidade. Exemplo: 'SP'\n");
  fgets(estado1, sizeof(estado1), stdin);
  estado1[strcspn(estado1, "\n")] = '\0'; //para limpar o \n que o fgets guarda
  
  printf("Digite o CÓDIGO DA CARTA (3 caracteres, exemplo: 'A01', 'B02',...): \n");
  scanf("%9s", codigoDaCarta1);
  getchar(); // para limpar o buffer do scanf para o proximo fgets
  
  printf("Digite o nome da CIDADE: \n");
  fgets(cidade1, sizeof(cidade1), stdin);
  cidade1[strcspn(cidade1, "\n")] = '\0'; //para limpar o \n que o fgets guarda
  
  printf("Digite a POPULAÇÃO da cidade (número inteiro, exemplo: '50000'): \n");
  scanf("%lu", &populacao1);
  
  printf("Digite a ÁREA da cidade (número real, exemplo: '123.345'): \n");
  scanf("%f", &area1);

  printf("Digite o PIB da cidade em BILHÕES(número real, exemplo: '12345.67'): \n");
  scanf("%f", &pib1);
  
  printf("Digite a QUANTIDADE DE PONTOS TURÍSTICOS da cidade (número inteiro): \n");
  scanf("%d", &pontoTuristico1);
  getchar(); // para limpar o buffer do scanf para o proximo fgets

  // DADOS DE ENTRADA DA CARTA 2
  printf("\n\n== CARTA 2 ==\n");
  printf("Digite a sigla do ESTADO da federação em que fica localizado a cidade. Exemplo: 'SP'\n");
  fgets(estado2, sizeof(estado2), stdin);
  estado2[strcspn(estado2, "\n")] = '\0'; //para limpar o \n que o fgets guarda
  
  printf("Digite o CÓDIGO DA CARTA (3 caracteres, exemplo: 'A01', 'B02',...): \n");
  scanf(" %9s", codigoDaCarta2);
  getchar(); // para limpar o buffer do scanf para o proximo fgets
  
  printf("Digite o nome da CIDADE: \n");
  fgets(cidade2, sizeof(cidade2), stdin);
  cidade2[strcspn(cidade2, "\n")] = '\0'; //para limpar o \n que o fgets guarda
  
  printf("Digite a POPULAÇÃO da cidade (número inteiro, exemplo: '50000'): \n");
  scanf(" %lu", &populacao2);
  
  printf("Digite a ÁREA da cidade (número real, exemplo: '123.345'): \n");
  scanf("%f", &area2);

  printf("Digite o PIB da cidade em BILHÕES(número real, exemplo: '12345.67'): \n");
  scanf("%f", &pib2);

  printf("Digite a QUANTIDADE DE PONTOS TURÍSTICOS da cidade (número inteiro): \n");
  scanf("%d", &pontoTuristico2);
  getchar(); // para limpar o buffer do scanf
  */

  // PROCESSAMENTO DE DADOS
  // densidade poplacional
  densidadePopulacional1 = populacao1 / area1;
  densidadePopulacional2 = populacao2 / area2;

  // PIB per capta. o PIB deve ser convertido para bilhoes
  pibPerCapita1 = (pib1 * 1000000000) / (float)populacao1;
  pibPerCapita2 = (pib2 * 1000000000) / (float)populacao2;

  /*
  super poder é a soma de todos os atributos numéricos
  (população, área, PIB, número de pontos turísticos, PIB per capita e
  o inverso da densidade populacional – quanto menor a densidade, maior o "poder")
  */
  superPoder1 = (float)populacao1 + area1 + pib1 + (float)pontoTuristico1 + pibPerCapita1 - densidadePopulacional1;
  superPoder2 = (float)populacao2 + area2 + pib2 + (float)pontoTuristico2 + pibPerCapita2 - densidadePopulacional2;
  
  // DADOS IMPRESSOS DAS CARTAS
  printf("\n\nCARTA 1:\n");
  printf("Estado: %s\n", estado1);
  printf("Código: %s\n", codigoDaCarta1);
  printf("Cidade: %s\n", cidade1);
  printf("População: %lu\n", populacao1);
  printf("Área: %.2f km²\n", area1);
  printf("PIB: R$ %.2f \n", pib1);
  printf("Numero de pontos Turisticos: %d\n", pontoTuristico1);
  printf("Densidade Populacional: %.2f hab/km²\n", densidadePopulacional1);
  printf("PIB per Capita: %.2f reais\n", pibPerCapita1);
  
  printf("\n\nCARTA 2:\n");
  printf("Estado: %s\n", estado2);
  printf("Código: %s\n", codigoDaCarta2);
  printf("Cidade: %s\n", cidade2);
  printf("População: %lu\n", populacao2);
  printf("Área: %.2f km²\n", area2);
  printf("PIB: R$ %.2f \n", pib2);
  printf("Numero de pontos Turisticos: %d\n", pontoTuristico2);
  printf("Densidade Populacional: %.2f hab/km²\n", densidadePopulacional2);
  printf("PIB per Capita: %.2f reais\n\n", pibPerCapita2);
  
  // Exibição dos Resultados:
  printf("Carta 1 - %s (%s): %d\n", cidade1, estado1, populacao1);
  printf("Carta 2 - %s (%s): %d\n\n", cidade2, estado2, populacao2);

    /*
    Comparação de Cartas: apenas um dos atributos numéricos
    (População, Área, PIB, Densidade Populacional ou PIB per capita) para realizar a
    comparação entre as duas cartas. Essa escolha deve ser feita diretamente no código
    */
   // atributo escolhido foi população
    if (populacao1 > populacao2){
      printf("A cidade de %s tem a maior população.\n\n", cidade1);
      strcpy(cidadeVencedora, cidade1);
    } else {
      printf("A cidade de %s tem a maior população.\n\n", cidade2);
      strcpy(cidadeVencedora, cidade2);
    }
  
  // Após realizar as comparações, exiba os resultados para o usuário.
  // Certifique-se de que o sistema mostre claramente qual carta venceu e com base em qual atributo.
  printf("A cidade vencedora é: %s\n\n", cidadeVencedora);

  return 0;
}
