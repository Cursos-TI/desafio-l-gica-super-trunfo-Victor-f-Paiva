#include <stdio.h>
#include <string.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades.

int main() {
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
  int escolhaDoUsuario;
  char atributoDeComparacao[40];

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
  printf("PIB: R$ %.2f bilhões\n", pib1);
  printf("Numero de pontos Turisticos: %d\n", pontoTuristico1);
  printf("Densidade Populacional: %.2f hab/km²\n", densidadePopulacional1);
  printf("PIB per Capita: %.2f reais\n", pibPerCapita1);
  
  printf("\n\nCARTA 2:\n");
  printf("Estado: %s\n", estado2);
  printf("Código: %s\n", codigoDaCarta2);
  printf("Cidade: %s\n", cidade2);
  printf("População: %lu\n", populacao2);
  printf("Área: %.2f km²\n", area2);
  printf("PIB: R$ %.2f bilhões\n", pib2);
  printf("Numero de pontos Turisticos: %d\n", pontoTuristico2);
  printf("Densidade Populacional: %.2f hab/km²\n", densidadePopulacional2);
  printf("PIB per Capita: %.2f reais\n\n", pibPerCapita2);
  
  /* Menu Interativo
  1-Nome da Cidade (string - usado apenas para exibir informações, não para comparação direta)
  2-População (int)
  3-Área (float)
  4-PIB (float)
  5-Número de pontos turísticos (int)
  6-Densidade demográfica (float - já calculada no desafio anterior). 
  */
  printf("\n### ESCOLHA UM ITEM PARA COMPARAÇÃO ###\n");
  printf("1-Nome da Cidade\n");
  printf("2-População \n");
  printf("3-Área \n");
  printf("4-PIB \n");
  printf("5-Número de pontos turísticos\n");
  printf("6-Densidade demográfica\n\n");

  scanf("%d", &escolhaDoUsuario);
  getchar(); //para limpar o buffer do scanf

  // Comparação de Atributos: 
  switch (escolhaDoUsuario) {
    case 1: //Nome da Cidade
      strcpy(cidadeVencedora, "EMPATE");
      strcpy(atributoDeComparacao, "Nome da cidade");
      printf("\nCidade 1 = %s\n", cidade1);
      printf("Cidade 2 = %s\n", cidade2);
      printf("Atributo de comparação = %s\n", atributoDeComparacao);
      printf("Atributo %s da cidade %s = %s\n", atributoDeComparacao, cidade1, cidade1);
      printf("Atributo %s da cidade %s = %s\n", atributoDeComparacao, cidade2, cidade2);
      printf("Não houve carta vencedora = %s\n", cidadeVencedora);
      break;
    
    case 2: //População
      strcpy(atributoDeComparacao, "População");
      if (populacao1 > populacao2){
        strcpy(cidadeVencedora, cidade1);
        printf("\nCidade 1 = %s\n", cidade1);
        printf("Cidade 2 = %s\n", cidade2);
        printf("Atributo de comparação = %s\n", atributoDeComparacao);
        printf("Atributo %s da cidade %s = %d\n", atributoDeComparacao, cidade1, populacao1);
        printf("Atributo %s da cidade %s = %d\n", atributoDeComparacao, cidade2, populacao2);
        printf("Carta vencedora = %s\n", cidadeVencedora);
      } else if (populacao2 > populacao1) {
        strcpy(cidadeVencedora, cidade2);
        printf("\nCidade 1 = %s\n", cidade1);
        printf("Cidade 2 = %s\n", cidade2);
        printf("Atributo de comparação = %s\n", atributoDeComparacao);
        printf("Atributo %s da cidade %s = %d\n", atributoDeComparacao, cidade1, populacao1);
        printf("Atributo %s da cidade %s = %d\n", atributoDeComparacao, cidade2, populacao2);
        printf("Carta vencedora = %s\n", cidadeVencedora);
      } else {
        strcpy(cidadeVencedora, "EMPATE");
        printf("\nCidade 1 = %s\n", cidade1);
        printf("Cidade 2 = %s\n", cidade2);
        printf("Atributo de comparação = %s\n", atributoDeComparacao);
        printf("Atributo %s da cidade %s = %d\n", atributoDeComparacao, cidade1, populacao1);
        printf("Atributo %s da cidade %s = %d\n", atributoDeComparacao, cidade2, populacao2);
        printf("Não houve carta vencedora = %s\n", cidadeVencedora);
      }
      break;
      
    case 3: //Área
      strcpy(atributoDeComparacao, "Área");
      if (area1 > area2){
        strcpy(cidadeVencedora, cidade1);
        printf("\nCidade 1 = %s\n", cidade1);
        printf("Cidade 2 = %s\n", cidade2);
        printf("Atributo de comparação = %s\n", atributoDeComparacao);
        printf("Atributo %s da cidade %s = %.2f\n", atributoDeComparacao, cidade1, area1);
        printf("Atributo %s da cidade %s = %.2f\n", atributoDeComparacao, cidade2, area2);
        printf("Carta vencedora = %s\n", cidadeVencedora);
      } else if(area2 > area1) {
        strcpy(cidadeVencedora, cidade2);
        printf("\nCidade 1 = %s\n", cidade1);
        printf("Cidade 2 = %s\n", cidade2);
        printf("Atributo de comparação = %s\n", atributoDeComparacao);
        printf("Atributo %s da cidade %s = %.2f\n", atributoDeComparacao, cidade1, area1);
        printf("Atributo %s da cidade %s = %.2f\n", atributoDeComparacao, cidade2, area2);
        printf("Carta vencedora = %s\n", cidadeVencedora);
      } else {
        strcpy(cidadeVencedora, "EMPATE");
        printf("\nCidade 1 = %s\n", cidade1);
        printf("Cidade 2 = %s\n", cidade2);
        printf("Atributo de comparação = %s\n", atributoDeComparacao);
        printf("Atributo %s da cidade %s = %.2f\n", atributoDeComparacao, cidade1, area1);
        printf("Atributo %s da cidade %s = %.2f\n", atributoDeComparacao, cidade2, area2);
        printf("Não houve carta vencedora = %s\n", cidadeVencedora);
      }
      break;
      
    case 4: //PIB
      strcpy(atributoDeComparacao, "PIB");
      if (pib1 > pib2){
        strcpy(cidadeVencedora, cidade1);
        printf("\nCidade 1 = %s\n", cidade1);
        printf("Cidade 2 = %s\n", cidade2);
        printf("Atributo de comparação = %s\n", atributoDeComparacao);
        printf("Atributo %s da cidade %s = R$ %.2f bilhões \n", atributoDeComparacao, cidade1, pib1);
        printf("Atributo %s da cidade %s = R$ %.2f bilhões \n", atributoDeComparacao, cidade2, pib2);
        printf("Carta vencedora = %s\n", cidadeVencedora);
      } else if (pib2 > pib1) {
        strcpy(cidadeVencedora, cidade2);
        printf("\nCidade 1 = %s\n", cidade1);
        printf("Cidade 2 = %s\n", cidade2);
        printf("Atributo de comparação = %s\n", atributoDeComparacao);
        printf("Atributo %s da cidade %s = R$ %.2f bilhões \n", atributoDeComparacao, cidade1, pib1);
        printf("Atributo %s da cidade %s = R$ %.2f bilhões \n", atributoDeComparacao, cidade2, pib2);
        printf("Carta vencedora = %s\n", cidadeVencedora);
      } else {
        strcpy(cidadeVencedora, "EMPATE");
        printf("\nCidade 1 = %s\n", cidade1);
        printf("Cidade 2 = %s\n", cidade2);
        printf("Atributo de comparação = %s\n", atributoDeComparacao);
        printf("Atributo %s da cidade %s = R$ %.2f bilhões \n", atributoDeComparacao, cidade1, pib1);
        printf("Atributo %s da cidade %s = R$ %.2f bilhões \n", atributoDeComparacao, cidade2, pib2);
        printf("Não houve carta vencedora = %s\n", cidadeVencedora);
      }
      break;
      
    case 5: //Número de pontos turísticos
      strcpy(atributoDeComparacao, "Número de pontos turísticos");
      if (pontoTuristico1 > pontoTuristico2){
        strcpy(cidadeVencedora, cidade1);
        printf("\nCidade 1 = %s\n", cidade1);
        printf("Cidade 2 = %s\n", cidade2);
        printf("Atributo de comparação = %s\n", atributoDeComparacao);
        printf("Atributo %s da cidade %s = %d\n", atributoDeComparacao, cidade1, pontoTuristico1);
        printf("Atributo %s da cidade %s = %d\n", atributoDeComparacao, cidade2, pontoTuristico2);
        printf("Carta vencedora = %s\n", cidadeVencedora);
      } else if (pontoTuristico2 > pontoTuristico1) {
        strcpy(cidadeVencedora, cidade2);
        printf("\nCidade 1 = %s\n", cidade1);
        printf("Cidade 2 = %s\n", cidade2);
        printf("Atributo de comparação = %s\n", atributoDeComparacao);
        printf("Atributo %s da cidade %s = %d\n", atributoDeComparacao, cidade1, pontoTuristico1);
        printf("Atributo %s da cidade %s = %d\n", atributoDeComparacao, cidade2, pontoTuristico2);
        printf("Carta vencedora = %s\n", cidadeVencedora);
      } else {
        strcpy(cidadeVencedora, "EMPATE");
        printf("\nCidade 1 = %s\n", cidade1);
        printf("Cidade 2 = %s\n", cidade2);
        printf("Atributo de comparação = %s\n", atributoDeComparacao);
        printf("Atributo %s da cidade %s = %d\n", atributoDeComparacao, cidade1, pontoTuristico1);
        printf("Atributo %s da cidade %s = %d\n", atributoDeComparacao, cidade2, pontoTuristico2);
        printf("Não houve carta vencedora = %s\n", cidadeVencedora);
      }
      break;
      
    case 6: //Densidade demográfica
      strcpy(atributoDeComparacao, "Densidade demográfica");
      if (densidadePopulacional2 > densidadePopulacional1){
        strcpy(cidadeVencedora, cidade1);
        printf("\nCidade 1 = %s\n", cidade1);
        printf("Cidade 2 = %s\n", cidade2);
        printf("Atributo de comparação = %s\n", atributoDeComparacao);
        printf("Atributo %s da cidade %s = %.2f hab/km²\n", atributoDeComparacao, cidade1, densidadePopulacional1);
        printf("Atributo %s da cidade %s = %.2f hab/km²\n", atributoDeComparacao, cidade2, densidadePopulacional2);
        printf("Carta vencedora = %s\n", cidadeVencedora);
      } else if(densidadePopulacional1 > densidadePopulacional2) {
        strcpy(cidadeVencedora, cidade2);
        printf("\nCidade 1 = %s\n", cidade1);
        printf("Cidade 2 = %s\n", cidade2);
        printf("Atributo de comparação = %s\n", atributoDeComparacao);
        printf("Atributo %s da cidade %s = %.2f hab/km²\n", atributoDeComparacao, cidade1, densidadePopulacional1);
        printf("Atributo %s da cidade %s = %.2f hab/km²\n", atributoDeComparacao, cidade2, densidadePopulacional2);
        printf("Carta vencedora = %s\n", cidadeVencedora);
      } else {
        strcpy(cidadeVencedora, "EMPATE");
        printf("\nCidade 1 = %s\n", cidade1);
        printf("Cidade 2 = %s\n", cidade2);
        printf("Atributo de comparação = %s\n", atributoDeComparacao);
        printf("Atributo %s da cidade %s = %.2f hab/km²\n", atributoDeComparacao, cidade1, densidadePopulacional1);
        printf("Atributo %s da cidade %s = %.2f hab/km²\n", atributoDeComparacao, cidade2, densidadePopulacional2);
        printf("Não houve carta vencedora = %s\n", cidadeVencedora);
      }
      break;
    
    default:
      printf("Opção inválida\n");
      break;
    }

  return 0;
}
