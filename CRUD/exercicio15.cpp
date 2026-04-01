// Sistema completo de estoque com CRUD, salvar em arquivo e carregar arquivo
// Programa deve usar matrizes, funções, estrutura de repetição e condicionais, menu de interação e arquivos externos

#include <iostream>
#include <fstream>
using namespace std;

const int MAX_ALUNOS = 10;
int produtos[MAX_ALUNOS][3]; // [0]: Código, [1]: Preço, [2]: Quantidade
int total_alunos = 0;

void cadastrarProduto() {
    if (total_alunos >= MAX_ALUNOS) {
        cout << "Estoque cheio! Não é possível cadastrar mais produtos." << endl;
        return;
    }

    int codigo;
    cout << "Digite o código do produto: ";
    cin >> codigo;

    // Verifica se o código já existe
    for (int i = 0; i < total_alunos; i++) {
        if (produtos[i][0] == codigo) {
            cout << "Erro: Produto com este código já existe." << endl;
            return;
        }
    }

    produtos[total_alunos][0] = codigo;
    cout << "Digite o preço do produto: ";
    cin >> produtos[total_alunos][1];
    cout << "Digite a quantidade do produto: ";
    cin >> produtos[total_alunos][2];

    total_alunos++;
    cout << "Produto cadastrado com sucesso!" << endl;
}

void consultarProduto() {
    if (total_alunos == 0) {
        cout << "Nenhum produto cadastrado no estoque." << endl;
        return;
    }

    int codigo;
    cout << "Digite o código do produto para consultar: ";
    cin >> codigo;

    bool encontrado = false;
    for (int i = 0; i < total_alunos; i++) {
        if (produtos[i][0] == codigo) {
            cout << "--- Dados do Produto ---" << endl;
            cout << "Código: " << produtos[i][0] << endl;
            cout << "Preço: R$ " << produtos[i][1] << endl;
            cout << "Quantidade: " << produtos[i][2] << endl;
            encontrado = true;
            break;
        }
    }
    if (encontrado == false) {
        cout << "Produto não encontrado." << endl;
    }
}

void alterarProduto() {
    if (total_alunos == 0) {
        cout << "Nenhum produto cadastrado no estoque." << endl;
        return;
    }

    int codigo;
    cout << "Digite o código do produto que deseja alterar: ";
    cin >> codigo;

    for (int i = 0; i < total_alunos; i++) {
        if (produtos[i][0] == codigo) {
            cout << "Novo preço (atual: " << produtos[i][1] << "): ";
            cin >> produtos[i][1];
            cout << "Nova quantidade (atual: " << produtos[i][2] << "): ";
            cin >> produtos[i][2];
            cout << "Produto alterado com sucesso!" << endl;
            return;
        }
    }
    cout << "Produto não encontrado." << endl;
}

void excluirProduto() {
    if (total_alunos == 0) {
        cout << "Nenhum produto cadastrado no estoque." << endl;
        return;
    }

    int codigo;
    cout << "Digite o código do produto que deseja excluir: ";
    cin >> codigo;

    for (int i = 0; i < total_alunos; i++) {
        if (produtos[i][0] == codigo) {
            // Desloca os produtos para preencher o espaço vazio
            for (int j = i; j < total_alunos - 1; j++) {
                produtos[j][0] = produtos[j + 1][0];
                produtos[j][1] = produtos[j + 1][1];
                produtos[j][2] = produtos[j + 1][2];
            }
            total_alunos--;
            cout << "Produto excluído com sucesso!" << endl;
            return;
        }
    }
    cout << "Produto não encontrado." << endl;
}

void listarProdutos() {
    if (total_alunos == 0) {
        cout << "Nenhum produto cadastrado no estoque." << endl;
        return;
    }

    cout << "--- Lista de Produtos ---" << endl;
    cout << "Código\tPreço\tQuantidade" << endl;
    for (int i = 0; i < total_alunos; i++) {
        cout << produtos[i][0] << "\tR$ " << produtos[i][1] << "\t" << produtos[i][2] << endl;
    }
}

void salvarEmArquivo() {
    ofstream arquivo("estoque.txt");
    if (arquivo.is_open()) {
        arquivo << total_alunos << endl; // Salva a quantidade total de produtos na primeira linha
        for (int i = 0; i < total_alunos; i++) {
            arquivo << produtos[i][0] << " " << produtos[i][1] << " " << produtos[i][2] << endl;
        }
        arquivo.close();
        cout << "Dados salvos no arquivo 'estoque.txt' com sucesso!" << endl;
    } else {
        cout << "Erro ao abrir o arquivo para salvar." << endl;
    }
}

void carregarDeArquivo() {
    ifstream arquivo("estoque.txt");
    if (arquivo.is_open()) {
        arquivo >> total_alunos; // Lê a quantidade total de produtos
        for (int i = 0; i < total_alunos; i++) {
            arquivo >> produtos[i][0] >> produtos[i][1] >> produtos[i][2];
        }
        arquivo.close();
        cout << "Dados carregados do arquivo 'estoque.txt' com sucesso!" << endl;
    } else {
        cout << "Arquivo 'estoque.txt' não encontrado ou erro ao abrir." << endl;
    }
}

int main() {
    int opcao = -1;

    while (opcao != 0) {
        cout << "<---MENU DE ESTOQUE--->" << endl;
        cout << "1 - Cadastrar produto" << endl;
        cout << "2 - Consultar produto" << endl;
        cout << "3 - Alterar produto" << endl;
        cout << "4 - Excluir produto" << endl;
        cout << "5 - Listar produtos" << endl;
        cout << "6 - Salvar em arquivo" << endl;
        cout << "7 - Carregar arquivo" << endl;
        cout << "0 - Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1: cadastrarProduto(); break;
            case 2: consultarProduto(); break;
            case 3: alterarProduto(); break;
            case 4: excluirProduto(); break;
            case 5: listarProdutos(); break;
            case 6: salvarEmArquivo(); break;
            case 7: carregarDeArquivo(); break;
            case 0: cout << "Saindo do sistema..." << endl; break;
            default: cout << "Opção inválida! Tente novamente." << endl;
        }
    }

    return 0;
}