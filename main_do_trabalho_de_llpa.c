#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#define QTD_ROUPAS 6

int main()
{
    // Inicialização de variaveis dos menus
    int op_menu_p = -1, op_menu_c = -1;

    // Inicialização das variáveis => Monstruário de Camisas
    char Marca[QTD_ROUPAS][30] = {"Adidas", "Overcome", "Supreme", "Channel", "Gucci", "Lacoste"};
    char Estilo[QTD_ROUPAS][30] = {"Esportivo", "Alternativo","Urban","Moda Alta","Elegante","Ecletico"};
    char Cor[QTD_ROUPAS][30] = {"Preto", "Azul, Rosa e Cinza", "Branco e Vermelho", "Preto e Dourado", "Verde e Vermelho", "Branco e Verde"};
    int Codigo[QTD_ROUPAS] = {1, 2, 3, 4, 5, 6};
    float Preco[QTD_ROUPAS] = {150, 199, 200, 550, 780, 100};

    // Inicialização de variaveis
    int i;
    int codigo_escolhido = 0, unid = 0;
    float total = 0;

    // Primeira impressão
    printf("SEJA BEM-VINDO AO TAG_CLOTHES ! :D\n\n");

    // Menu principal
    do
    {
        // Opções do menu com base em casos de switch
        printf("INICIO > MENU PRINCIPAL \n");
        printf("___________________________________\n\n");
        printf("1 - Para ver nossos produtos \n");
        printf("0 - Para sair do programa \n");
        printf("___________________________________\n");

        // Pega opção do usuário
        printf(" => Digite sua opcao \n");
        scanf("%d",&op_menu_p);
        system("cls || clear"); // Limpar tela

        switch(op_menu_p)
        {
        case 1 :
            printf("MENU PRINCIPAL > MONSTRUARIO DE CAMISAS \n\n");

            for( i = 0; i < QTD_ROUPAS; i++ ) // Imprimindo todo o monstruário pro usuário pela primeira vez
            {
                printf("Codigo do produto: %d \n", Codigo[i]);
                printf("Marca: %s \n", Marca[i]);
                printf("Cores do produto: %s \n", Cor[i]);
                printf("Estilo do produto: %s \n", Estilo[i]);
                printf("Preco do produto: R$%.2f \n",Preco[i]);
                printf("\n\n");
            }

            // Opções de menu secundário com base em casos de switch
            do
            {
                printf("MENU PRINCIPAL > MONSTRUARIO DE CAMISAS > REALIZAR COMPRAS \n");
                printf("___________________________________________________________\n\n");
                printf("2 - Realizar compra \n");
                printf("3 - Retornar ao monstruario de camisas \n");
                printf("0 - Encerrar o programa \n");
                printf("____________________________________________________________\n");

                // Pega opção do usuário
                printf(" => Digite sua opcao \n");
                scanf("%d",&op_menu_c);
                system("cls || clear"); // Limpar tela

                switch(op_menu_c)
                {

                // Menu de compras
                // Pega valor de codigo e soma o total do preço que vai sendo acumulado
                case 2:
                    printf("REALIZAR COMPRAS > MENU DE PAGAMENTO \n");
                    printf("________________________________________\n\n");
                    printf("Informe o codigo do produto: ");
                    scanf("%d",&codigo_escolhido);

                    for(i = 0; i < QTD_ROUPAS; i++)
                    {
                        if(codigo_escolhido == Codigo[i])
                            break;

                    }
                    // Condição que vai saber se o codigo é válido ou nao pra continuar
                    if (codigo_escolhido > 6 || codigo_escolhido < 1)
                    {
                        printf("Codigo invalido! \n");
                        system("pause"); // Pausar programa para o usuário poder ler antes que limpe a tela
                        system("cls || clear");// Limpar tela
                    }
                    else
                    {
                        printf("\nQuantas unidades voce deseja? ");
                        scanf("%d",&unid);

                        // Operação acumulativa
                        total = total + (Preco[i] * unid);

                        printf("\nO PRECO TOTAL ATUALIZADO EH DE: RS%.2f \n",total); // Imprime o valor total acumulado
                        printf("________________________________________\n");
                        system("pause"); // Pausar programa para o usuário poder ler antes que limpe a tela
                        system("cls || clear"); // Limpar tela
                        break;
                    }

                case 3: // Imprime o monstruário novamente ao usuário
                    printf("MENU PRINCIPAL > MONSTRUARIO DE CAMISAS \n\n");

                    for( i = 0; i < QTD_ROUPAS; i++ )
                    {
                        printf("Codigo do produto: %d \n", Codigo[i]);
                        printf("Marca: %s \n", Marca[i]);
                        printf("Cores do produto: %s \n", Cor[i]);
                        printf("Estilo do produto: %s \n", Estilo[i]);
                        printf("Preco do produto: R$%.2f \n",Preco[i]);
                        printf("\n\n");
                    }

                    break;
                // Encerra os processos no menu secundário
                case 0:
                    return 0;
                    break;
                }

            }
            while(op_menu_c != 0);
            break;
        // Encerra os processos no menu principal
        case 0:
            return 0;
            break;
        }

    }
    while (op_menu_p != 0);

    return 0;
}
