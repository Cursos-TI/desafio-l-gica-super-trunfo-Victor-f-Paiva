#include <stdio.h>
#include <string.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades.

int main() {
  // Área para definição das variáveis para armazenar as propriedades das cidades
  char estado1[10]= "RJ";
  char estado2[10]= "SP";
  char codigoDaCarta1[10] = "A01";
  char codigoDaCarta2[10] = "B02";
  char cidade1[20] = "Rio de Janeiro";
  char cidade2[20] = "São Paulo";
  char cidadeVencedora[20];
  unsigned long int populacao1 = 6200000;
  unsigned long int populacao2 = 11450000;
  int pontoTuristico1 = 12;
  int pontoTuristico2 = 15;
  float area1 = 1200.33;
  float area2 = 1521.11;
  float pib1 = 359.0;
  float pib2= 828.0;
  float densidadePopulacional1;
  float densidadePopulacional2;
  float pibPerCapita1, pibPerCapita2;
  int escolha1, escolha2;
  float somaCarta1 = 0;
  float somaCarta2 = 0;
  float valor1 = 0;
  float valor2 = 0;

  // PROCESSAMENTO DE DADOS
  // densidade poplacional
  densidadePopulacional1 = populacao1 / area1;
  densidadePopulacional2 = populacao2 / area2;

  // PIB per capta. o PIB deve ser convertido para bilhoes
  pibPerCapita1 = (pib1 * 1000000000) / (float)populacao1;
  pibPerCapita2 = (pib2 * 1000000000) / (float)populacao2;
  
  // DADOS IMPRESSOS DAS CARTAS
  printf("\nCARTA 1:\n");
  printf("Estado: %s\n", estado1);
  printf("Código: %s\n", codigoDaCarta1);
  printf("Cidade: %s\n", cidade1);
  printf("População: %lu\n", populacao1);
  printf("Área: %.2f km²\n", area1);
  printf("PIB: R$ %.2f bilhões\n", pib1);
  printf("Numero de pontos Turisticos: %d\n", pontoTuristico1);
  printf("Densidade Populacional: %.2f hab/km²\n", densidadePopulacional1);
  printf("PIB per Capita: %.2f reais\n", pibPerCapita1);
  
  printf("\nCARTA 2:\n");
  printf("Estado: %s\n", estado2);
  printf("Código: %s\n", codigoDaCarta2);
  printf("Cidade: %s\n", cidade2);
  printf("População: %lu\n", populacao2);
  printf("Área: %.2f km²\n", area2);
  printf("PIB: R$ %.2f bilhões\n", pib2);
  printf("Numero de pontos Turisticos: %d\n", pontoTuristico2);
  printf("Densidade Populacional: %.2f hab/km²\n", densidadePopulacional2);
  printf("PIB per Capita: %.2f reais\n", pibPerCapita2);
  
  /* Menu Interativo
  1-Nome da Cidade (string - usado apenas para exibir informações, não para comparação direta)
  2-População (int)
  3-Área (float)
  4-PIB (float)
  5-Número de pontos turísticos (int)
  6-Densidade demográfica (float - já calculada no desafio anterior). 
  */
  printf("\n### Escolha o PRIMEIRO atributo para coparação ###\n");
  printf("2-População \n");
  printf("3-Área \n");
  printf("4-PIB \n");
  printf("5-Número de pontos turísticos\n");
  printf("6-Densidade demográfica\n");
  printf("Opcao: ");
  scanf("%d", &escolha1);

  printf("\n### Escolha o SEGUNDO atributo para coparação ###\n");
  if (escolha1 != 2) printf("2-População \n");
  if (escolha1 != 3) printf("3-Área \n");
  if (escolha1 != 4) printf("4-PIB \n");
  if (escolha1 != 5) printf("5-Número de pontos turísticos \n");
  if (escolha1 != 6) printf("6-Densidade demográfica\n");
  printf("Opcao: ");
  scanf("%d", &escolha2);

  //PROCESSAMENTO E SOMA DOS ATRIBUTOS
  for (int i=0; i<=1; i++){
    int atributo = (i==0) ? escolha1 : escolha2;

    switch (atributo){
      case 2: // população
      valor1 = populacao1;
      valor2 = populacao2;
      printf("\nComparando população \n");
      break;

      case 3: // área
      valor1 = area1;
      valor2 = area2;
      printf("\nComparando área \n");
      break;

      case 4: // PIB
      valor1 = pib1 * 1000000000;
      valor2 = pib2 * 1000000000;
      printf("\nComparando PIB \n");
      break;

      case 5: // ponto turistico
      valor1 = pontoTuristico1;
      valor2 = pontoTuristico2;
      printf("\nComparando número de pontos turísticos \n");
      break;

      case 6: // densidade
      valor1 = -densidadePopulacional1;
      valor2 = -densidadePopulacional2;
      printf("\nComparando densidade demográfica \n");
      break;

      default:
      printf("\nOpcao invalida! Tente novamente\n");
      return 1;
    }

    printf("%s: %.2f\n", cidade1, (atributo == 6)? densidadePopulacional1 : valor1);
    printf("%s: %.2f\n", cidade2, (atributo == 6)? densidadePopulacional2 : valor2);

    somaCarta1 += valor1;
    somaCarta2 += valor2;
  }

  //ESCOLHA DA CARTA VENCEDORA
  if (somaCarta1 > somaCarta2){
    strcpy(cidadeVencedora, cidade1);
  } else if (somaCarta1 < somaCarta2){
    strcpy(cidadeVencedora, cidade2);
  } else {
    strcpy(cidadeVencedora, "EMPATE");
  }

  //SAIDA
  printf("\n===== RESULTADO FINAL =====\n");
  printf("%s - Soma dos atributos: %.2f\n", cidade1, somaCarta1);
  printf("%s - Soma dos atributos: %.2f\n", cidade2, somaCarta2);
  printf("Vencedor: %s\n\n", cidadeVencedora);

  return 0;
}
