#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <locale.h>
using namespace std;

class Cliente {
public:
    string codigo;
    string nome;
    string endereco;
    string telefone;
    string dataNascimento;

    Cliente(const string& codigo, const string& nome, const string& endereco, const string& telefone, const string& dataNascimento)
        : codigo(codigo), nome(nome), endereco(endereco), telefone(telefone), dataNascimento(dataNascimento) {}
};

class Fornecedor {
public:
    string codigo;
    string nome;
    string telefone;

    Fornecedor(const string& codigo, const string& nome, const string& telefone)
        : codigo(codigo), nome(nome), telefone(telefone) {}
};

class Festa {
public:
    string codigo;
    int quantidadeConvidados;
    string data;
    string diaSemana;
    string horarioInicio;
    string horarioTermino;
    string tema;
    string codigoCliente;
    string codigoFornecedor;

    Festa(const string& codigo, int quantidadeConvidados, const string& data, const string& diaSemana,
          const string& horarioInicio, const string& horarioTermino, const string& tema, const string& codigoCliente, const string& codigoFornecedor)
        : codigo(codigo), quantidadeConvidados(quantidadeConvidados), data(data), diaSemana(diaSemana),
          horarioInicio(horarioInicio), horarioTermino(horarioTermino), tema(tema), codigoCliente(codigoCliente), codigoFornecedor(codigoFornecedor) {}
};

class Contrato {
public:
    string numero;
    double valorTotal;
    double desconto;
    double valorFinal;
    string formaPagamento;
    string status;
    string codigoFesta;

    Contrato(const string& numero, double valorTotal, double desconto, double valorFinal,
             const string& formaPagamento, const string& status, const string& codigoFesta)
        : numero(numero), valorTotal(valorTotal), desconto(desconto), valorFinal(valorFinal),
          formaPagamento(formaPagamento), status(status), codigoFesta(codigoFesta) {}
};

vector<Cliente> clientes;
vector<Fornecedor> fornecedores;
vector<Festa> festas;
vector<Contrato> contratos;

// Fun��o auxiliar para verificar se um cliente com o mesmo c�digo j� existe
bool clienteExiste(const string& codigo) {
    return find_if(clientes.begin(), clientes.end(), [&](const Cliente& cliente) {
        return cliente.codigo == codigo;
    }) != clientes.end();
}

// Fun��o auxiliar para verificar se um fornecedor com o mesmo c�digo j� existe
bool fornecedorExiste(const string& codigo) {
    return find_if(fornecedores.begin(), fornecedores.end(), [&](const Fornecedor& fornecedor) {
        return fornecedor.codigo == codigo;
    }) != fornecedores.end();
}

// Fun��o auxiliar para verificar se uma festa com o mesmo c�digo j� existe
bool festaExiste(const string& codigo) {
    return find_if(festas.begin(), festas.end(), [&](const Festa& festa) {
        return festa.codigo == codigo;
    }) != festas.end();
}

// Fun��o auxiliar para verificar se um contrato com o mesmo c�digo da festa j� existe
bool contratoExiste(const string& codigoFesta) {
    return find_if(contratos.begin(), contratos.end(), [&](const Contrato& contrato) {
        return contrato.codigoFesta == codigoFesta;
    }) != contratos.end();
}

// Fun��o para adicionar um novo cliente
void adicionarCliente() {
    string codigo, nome, endereco, telefone, dataNascimento;

    cout << "Adicionar Cliente" << endl;
    cout << "C�digo: ";
    getline(cin, codigo);

    if (clienteExiste(codigo)) {
        cout << "Cliente com c�digo " << codigo << " j� existe." << endl;
        return;
    }

    cout << "Nome: ";
    getline(cin, nome);
    cout << "Endere�o: ";
    getline(cin, endereco);
    cout << "Telefone: ";
    getline(cin, telefone);
    cout << "Data de Nascimento: ";
    getline(cin, dataNascimento);

    clientes.push_back(Cliente(codigo, nome, endereco, telefone, dataNascimento));
    cout << "Cliente adicionado com sucesso." << endl;
}

// Fun��o para adicionar um novo fornecedor
void adicionarFornecedor() {
    string codigo, nome, telefone;

    cout << "Adicionar Fornecedor" << endl;
    cout << "C�digo: ";
    getline(cin, codigo);

    if (fornecedorExiste(codigo)) {
        cout << "Fornecedor com c�digo " << codigo << " j� existe." << endl;
        return;
    }

    cout << "Nome: ";
    getline(cin, nome);
    cout << "Telefone: ";
    getline(cin, telefone);

    fornecedores.push_back(Fornecedor(codigo, nome, telefone));
    cout << "Fornecedor adicionado com sucesso." << endl;
}

// Fun��o para adicionar uma nova festa
void adicionarFesta() {
    string codigo, data, diaSemana, horarioInicio, horarioTermino, tema, codigoCliente, codigoFornecedor;
    int quantidadeConvidados;

    cout << "Adicionar Festa" << endl;
    cout << "C�digo: ";
    getline(cin, codigo);

    if (festaExiste(codigo)) {
        cout << "Festa com c�digo " << codigo << " j� existe." << endl;
        return;
    }

    cout << "Quantidade de Convidados: ";
    cin >> quantidadeConvidados;
    cin.ignore(); // Limpa o buffer do teclado
    cout << "Data: ";
    getline(cin, data);
    cout << "Dia da Semana: ";
    getline(cin, diaSemana);
    cout << "Hor�rio de In�cio: ";
    getline(cin, horarioInicio);
    cout << "Hor�rio de T�rmino: ";
    getline(cin, horarioTermino);
    cout << "Tema: ";
    getline(cin, tema);
    cout << "C�digo do Cliente: ";
    getline(cin, codigoCliente);

    if (!clienteExiste(codigoCliente)) {
        cout << "Cliente com c�digo " << codigoCliente << " n�o existe." << endl;
        return;
    }

    cout << "C�digo do Fornecedor: ";
    getline(cin, codigoFornecedor);

    if (!fornecedorExiste(codigoFornecedor)) {
        cout << "Fornecedor com c�digo " << codigoFornecedor << " n�o existe." << endl;
        return;
    }

    festas.push_back(Festa(codigo, quantidadeConvidados, data, diaSemana, horarioInicio, horarioTermino, tema, codigoCliente, codigoFornecedor));
    cout << "Festa adicionada com sucesso." << endl;
}

// Fun��o para adicionar um novo contrato
void adicionarContrato() {
    string numero, formaPagamento, status, codigoFesta;
    double valorTotal, desconto, valorFinal;

    cout << "Adicionar Contrato" << endl;
    cout << "N�mero: ";
    getline(cin, numero);

    if (contratoExiste(numero)) {
        cout << "Contrato com n�mero " << numero << " j� existe." << endl;
        return;
    }

    cout << "Valor Total: ";
    cin >> valorTotal;
    cout << "Desconto: ";
    cin >> desconto;
    valorFinal = valorTotal - desconto;
    cin.ignore(); // Limpa o buffer do teclado
    cout << "Forma de Pagamento: ";
    getline(cin, formaPagamento);
    cout << "Status: ";
    getline(cin, status);
    cout << "C�digo da Festa: ";
    getline(cin, codigoFesta);

    if (!festaExiste(codigoFesta)) {
        cout << "Festa com c�digo " << codigoFesta << " n�o existe." << endl;
        return;
    }

    contratos.push_back(Contrato(numero, valorTotal, desconto, valorFinal, formaPagamento, status, codigoFesta));
    cout << "Contrato adicionado com sucesso." << endl;
}

// Fun��o para exibir a lista de clientes
void listarClientes() {
    if (clientes.empty()) {
        cout << "N�o h� clientes cadastrados." << endl;
        return;
    }

    cout << "Lista de Clientes" << endl;
    for (const auto& cliente : clientes) {
        cout << "C�digo: " << cliente.codigo << endl;
        cout << "Nome: " << cliente.nome << endl;
        cout << "Endere�o: " << cliente.endereco << endl;
        cout << "Telefone: " << cliente.telefone << endl;
        cout << "Data de Nascimento: " << cliente.dataNascimento << endl;
        cout << "------------------------" << endl;
    }
}

// Fun��o para exibir a lista de fornecedores
void listarFornecedores() {
    if (fornecedores.empty()) {
        cout << "N�o h� fornecedores cadastrados." << endl;
        return;
    }

    cout << "Lista de Fornecedores" << endl;
    for (const auto& fornecedor : fornecedores) {
        cout << "C�digo: " << fornecedor.codigo << endl;
        cout << "Nome: " << fornecedor.nome << endl;
        cout << "Telefone: " << fornecedor.telefone << endl;
        cout << "------------------------" << endl;
    }
}

// Fun��o para exibir a lista de festas
void listarFestas() {
    if (festas.empty()) {
        cout << "N�o h� festas cadastradas." << endl;
        return;
    }

    cout << "Lista de Festas" << endl;
    for (const auto& festa : festas) {
        cout << "C�digo: " << festa.codigo << endl;
        cout << "Quantidade de Convidados: " << festa.quantidadeConvidados << endl;
        cout << "Data: " << festa.data << endl;
        cout << "Dia da Semana: " << festa.diaSemana << endl;
        cout << "Hor�rio de In�cio: " << festa.horarioInicio << endl;
        cout << "Hor�rio de T�rmino: " << festa.horarioTermino << endl;
        cout << "Tema: " << festa.tema << endl;
        cout << "C�digo do Cliente: " << festa.codigoCliente << endl;
        cout << "C�digo do Fornecedor: " << festa.codigoFornecedor << endl;
        cout << "------------------------" << endl;
    }
}

// Fun��o para exibir a lista de contratos
void listarContratos() {
    if (contratos.empty()) {
        cout << "N�o h� contratos cadastrados." << endl;
        return;
    }

    cout << "Lista de Contratos" << endl;
    for (const auto& contrato : contratos) {
        cout << "N�mero: " << contrato.numero << endl;
        cout << "Valor Total: " << fixed << setprecision(2) << contrato.valorTotal << endl;
        cout << "Desconto: " << fixed << setprecision(2) << contrato.desconto << endl;
        cout << "Valor Final: " << fixed << setprecision(2) << contrato.valorFinal << endl;
        cout << "Forma de Pagamento: " << contrato.formaPagamento << endl;
        cout << "Status: " << contrato.status << endl;
        cout << "C�digo da Festa: " << contrato.codigoFesta << endl;
        cout << "------------------------" << endl;
    }
}

int main() {
    int opcao;
    setlocale(LC_ALL, "Portuguese_Brazil");

    do {
        cout << "Sistema de Gerenciamento de Festas" << endl;
        cout << "1. Adicionar Cliente" << endl;
        cout << "2. Adicionar Fornecedor" << endl;
        cout << "3. Adicionar Festa" << endl;
        cout << "4. Adicionar Contrato" << endl;
        cout << "5. Listar Clientes" << endl;
        cout << "6. Listar Fornecedores" << endl;
        cout << "7. Listar Festas" << endl;
        cout << "8. Listar Contratos" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma op��o: ";
        cin >> opcao;
        cin.ignore(); // Limpa o buffer do teclado

        switch (opcao) {
            case 1:
                adicionarCliente();
                break;
            case 2:
                adicionarFornecedor();
                break;
            case 3:
                adicionarFesta();
                break;
            case 4:
                adicionarContrato();
                break;
            case 5:
                listarClientes();
                break;
            case 6:
                listarFornecedores();
                break;
            case 7:
                listarFestas();
                break;
            case 8:
                listarContratos();
                break;
            case 0:
                cout << "Saindo do programa." << endl;
                break;
            default:
                cout << "Op��o inv�lida." << endl;
                break;
        }

        cout << "------------------------" << endl;
    } while (opcao != 0);

    return 0;
}
