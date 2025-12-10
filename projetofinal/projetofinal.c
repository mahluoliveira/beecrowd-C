#include <stdio.h>
#include <string.h>

// Definicao de uma constante para o tamanho maximo do historico
#define MAX_HISTORICO 100

// =================================================================
// 1. ESTRUTURA DE DADOS MODIFICADA
// =================================================================

typedef struct
{
    char nome[50];   // NOVO: Campo para armazenar o nome do paciente
    int pas;         // Pressao Arterial Sistolica
    int pad;         // Pressao Arterial Diastolica
    float pp;        // Pressao de Pulso
    float pam;       // Pressao Arterial Media
    char classe[30]; // Classificacao do nivel de pressao
} pressao;

// =================================================================
// 2. FUNCOES AUXILIARES E PROCEDIMENTOS
// =================================================================

void cabecalho()
{
    printf("=====================================================\n");
    printf("   SISTEMA DE ANALISE HEMODINAMICA - PROJETO FINAL   \n");
    printf("-----------------------------------------------------\n");
    printf(" Desenvolvido por: Maria Luisa Oliveira\n");
    printf("=====================================================\n\n");
}

// Funcao: calcular pressões e classificacao
// Esta funcao recebe um ponteiro para a struct 'pressao' e preenche os campos calculados (PP, PAM e classe).
void calcularPressao(pressao *p)
{
    // Formula para Pressao de Pulso (PP)
    p->pp = p->pas - p->pad;
    // Formula para Pressao Arterial Media (PAM)
    p->pam = (p->pas + 2 * p->pad) / 3.0;

    // Logica de classificacao (padrao AHA/ACC 2017)
    if (p->pas < 120 && p->pad < 80)
    {
        strcpy(p->classe, "Normal");
    }
    else if (p->pas >= 120 && p->pas <= 129 && p->pad < 80)
    {
        strcpy(p->classe, "Elevada");
    }
    else if ((p->pas >= 130 && p->pas <= 139) || (p->pad >= 80 && p->pad <= 89))
    {
        strcpy(p->classe, "Hipertensao Estagio 1");
    }
    else if (p->pas >= 140 || p->pad >= 90)
    {
        strcpy(p->classe, "Hipertensao Estagio 2");
    }
    else
    {
        strcpy(p->classe, "Indefinida");
    }
}

// Procedimento para adicionar um novo registro ao array historico
void adicionarRegistro(pressao *novo_registro, pressao historico[], int *contador)
{
    if (*contador < MAX_HISTORICO)
    {
        // Copia a struct temporaria para a proxima posicao livre do array
        historico[*contador] = *novo_registro;
        (*contador)++; // Incrementa o contador de registros
        printf("\nRegistro adicionado ao historico com sucesso!\n\n");
    }
    else
    {
        printf("\nERRO: Historico cheio. Nao foi possivel adicionar o registro.\n\n");
    }
}

// Procedimento para exibir todos os registros no historico
void exibirHistorico(pressao historico[], int contador)
{
    if (contador == 0)
    {
        printf("\nNenhum registro no historico.\n\n");
        return;
    }

    printf("\n==== HISTORICO DE ANALISE HEMODINAMICA (%d Registros) ====\n", contador);
    for (int i = 0; i < contador; i++)
    {
        printf("--- Registro %d ---\n", i + 1);
        printf("Paciente: %s\n", historico[i].nome);
        printf("PAS: %d\n", historico[i].pas);
        printf("PAD: %d\n", historico[i].pad);
        printf("PP: %.2f\n", historico[i].pp);
        printf("PAM: %.2f\n", historico[i].pam);
        printf("Classificacao: %s\n", historico[i].classe);
        printf("-------------------\n");
    }
    printf("\n");
}

// =================================================================
// 3. NOVAS FUNCOES QUE RETORNAM VALORES
// =================================================================

// FUNCAO 1: Calcula e retorna a media das PAMs (Pressao Arterial Media) no historico.
float calcularMediaPAM(pressao historico[], int contador)
{
    if (contador == 0)
    {
        return 0.0; // Retorna 0 se nao houver dados
    }

    float soma_pam = 0.0;
    for (int i = 0; i < contador; i++)
    {
        soma_pam += historico[i].pam;
    }

    return soma_pam / contador; // Retorna a media
}

// FUNCAO 2: Conta e retorna o numero de registros que correspondem a uma classificacao especifica.
int contarClassificacao(pressao historico[], int contador, const char *classificacao)
{
    int contagem = 0;
    for (int i = 0; i < contador; i++)
    {
        // strncmp: compara strings (classe do historico vs. a classificacao buscada)
        if (strncmp(historico[i].classe, classificacao, 30) == 0)
        {
            contagem++;
        }
    }
    return contagem; // Retorna o total de ocorrencias
}

// FUNCAO 3: Encontra e retorna o INDICE do registro com a maior PAS (Pressao Arterial Sistolica).
int encontrarRegistroMaxPAS(pressao historico[], int contador)
{
    if (contador == 0)
    {
        return -1; // Retorna -1 para indicar que o historico esta vazio
    }

    int indice_max = 0;
    int max_pas = historico[0].pas; // Inicializa com o primeiro registro

    for (int i = 1; i < contador; i++) // Comeca do segundo (i=1)
    {
        if (historico[i].pas > max_pas)
        {
            max_pas = historico[i].pas;
            indice_max = i; // Armazena o indice do maior valor encontrado
        }
    }
    return indice_max; // Retorna o indice do registro com a PAS mais alta
}

// =================================================================
// 4. FUNCAO PRINCIPAL (MAIN)
// =================================================================

int main()
{
    int opcao;
    // Variavel temporaria para receber os dados antes de adicionar ao historico
    pressao temp_paciente;
    FILE *arquivo;

    // Array principal para armazenar todos os registros e contador de registros
    pressao historico[MAX_HISTORICO];
    int contador_registros = 0;

    cabecalho();

    do
    {

        printf("========== MENU ==========\n");
        printf("1 - Inserir novo registro manualmente\n");
        printf("2 - Importar dados de um arquivo TXT (dados.txt)\n");
        printf("3 - Exibir HISTORICO de registros\n");
        printf("4 - Estatisticas e Analise (Novas Funcoes)\n"); // NOVO: Opcao para usar as novas funcoes
        printf("5 - Salvar relatorio COMPLETO\n");
        printf("6 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {

        case 1: // Inserção manual
            printf("\n--- Novo Registro ---\n");
            printf("Digite o Nome do Paciente (sem espacos): ");
            scanf("%s", temp_paciente.nome); // Leitura do nome

            printf("Digite a PAS: ");
            scanf("%d", &temp_paciente.pas);

            printf("Digite a PAD: ");
            scanf("%d", &temp_paciente.pad);

            // Calcula PP, PAM e Classificacao para o registro temporario
            calcularPressao(&temp_paciente);
            // Adiciona o registro completo ao array historico
            adicionarRegistro(&temp_paciente, historico, &contador_registros);
            break;

        case 2: // Importa TXT (Ajustado para ler nome, PAS e PAD. Assume 'dados.txt' existe.)
            arquivo = fopen("dados.txt", "r");
            if (arquivo == NULL)
            {
                printf("Erro ao abrir o arquivo 'dados.txt'! Certifique-se de que ele existe e contem: Nome PAS PAD\n\n");
                break;
            }

            // Leitura: NOME PAS PAD
            if (fscanf(arquivo, "%s %d %d", temp_paciente.nome, &temp_paciente.pas, &temp_paciente.pad) == 3)
            {
                // Se a leitura foi bem-sucedida, calcula e adiciona
                calcularPressao(&temp_paciente);
                adicionarRegistro(&temp_paciente, historico, &contador_registros);
            }
            else
            {
                printf("Erro de leitura: O arquivo 'dados.txt' nao possui o formato esperado (Nome PAS PAD).\n");
            }

            fclose(arquivo);
            break;

        case 3: // Mostra Historico
            exibirHistorico(historico, contador_registros);
            break;

        case 4: // Estatisticas e Analise (NOVA OPCAO)
            if (contador_registros == 0)
            {
                printf("\nNao ha dados no historico para calcular estatisticas.\n\n");
                break;
            }

            printf("\n==== RELATORIO ESTATISTICO ====\n");

            // USO DA FUNCAO 1: calcularMediaPAM()
            float media_pam = calcularMediaPAM(historico, contador_registros);
            printf("Media da Pressao Arterial Media (PAM) de todos os registros: %.2f mmHg\n\n", media_pam);

            // USO DA FUNCAO 2: contarClassificacao()
            printf("--- Contagem por Classificacao ---\n");
            printf("Normal: %d\n", contarClassificacao(historico, contador_registros, "Normal"));
            printf("Elevada: %d\n", contarClassificacao(historico, contador_registros, "Elevada"));
            printf("Estagio 1: %d\n", contarClassificacao(historico, contador_registros, "Hipertensao Estagio 1"));
            printf("Estagio 2: %d\n", contarClassificacao(historico, contador_registros, "Hipertensao Estagio 2"));
            printf("Indefinida: %d\n\n", contarClassificacao(historico, contador_registros, "Indefinida"));

            // USO DA FUNCAO 3: encontrarRegistroMaxPAS()
            int indice_max = encontrarRegistroMaxPAS(historico, contador_registros);
            if (indice_max != -1)
            {
                printf("--- Registro com a MAIOR PAS ---\n");
                printf("Indice no Historico: %d\n", indice_max + 1);
                printf("Paciente: %s\n", historico[indice_max].nome);
                printf("PAS Maxima: %d\n", historico[indice_max].pas);
                printf("Classificacao: %s\n", historico[indice_max].classe);
            }
            printf("----------------------------------\n\n");
            break;

        case 5: // Salva relatório COMPLETO
        {
            char nomeArquivo[50];
            printf("Digite o nome do arquivo para o relatorio COMPLETO (ex: relatorio.txt): ");
            scanf("%s", nomeArquivo);

            FILE *arquivo_saida = fopen(nomeArquivo, "w");

            if (arquivo_saida == NULL)
            {
                printf("Erro ao salvar arquivo!\n\n");
                break;
            }

            // Escreve cabecalho do relatorio
            fprintf(arquivo_saida, "Relatorio de Analise Hemodinamica Completo (%d Registros)\n", contador_registros);
            fprintf(arquivo_saida, "---------------------------------------------------------\n");

            // Itera sobre o array historico para salvar todos os registros
            for (int i = 0; i < contador_registros; i++)
            {
                fprintf(arquivo_saida, "--- Registro %d ---\n", i + 1);
                fprintf(arquivo_saida, "Paciente: %s\n", historico[i].nome);
                fprintf(arquivo_saida, "PAS: %d\n", historico[i].pas);
                fprintf(arquivo_saida, "PAD: %d\n", historico[i].pad);
                fprintf(arquivo_saida, "PP: %.2f\n", historico[i].pp);
                fprintf(arquivo_saida, "PAM: %.2f\n", historico[i].pam);
                fprintf(arquivo_saida, "Classificacao: %s\n", historico[i].classe);
            }

            // Adiciona as estatísticas ao relatório de saída
            fprintf(arquivo_saida, "\n=========================================\n");
            fprintf(arquivo_saida, "ESTATISTICAS GERAIS\n");
            fprintf(arquivo_saida, "Media da PAM: %.2f\n", calcularMediaPAM(historico, contador_registros));

            fclose(arquivo_saida);

            printf("Relatorio COMPLETO salvo como '%s' com sucesso!\n\n", nomeArquivo);
        }
        break;

        case 6:
            printf("Encerrando o programa...\n");
            break;

        default:
            printf("Opcao invalida!\n\n");
        }

    } while (opcao != 6); // O loop agora termina na opcao 6

    return 0;
}