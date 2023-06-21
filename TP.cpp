#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdio.h>

using namespace std;

struct Cliente {
    string codigo;
    string nome;
    string endereco;
    string telefone;
    string dataNascimento;
};

struct Fornecedor {
    string codigo;
    string nome;
    string telefone;
};

struct Festa {
    string codigo;
    int quantidadeConvidados;
    string data;
    string diaSemana;
    string horarioInicio;
    string horarioTermino;
    string tema;
    string codigoCliente;
    string codigoFornecedor;
};

struct Contrato {
    string numero;
    double valorTotal;
    double desconto;
    double valorFinal;
    string formaPagamento;
    string status;
    string codigoFesta;
};

vector<Cliente> clientes;
vector<Fornecedor> fornecedores;
vector<Festa> festas;
vector<Contrato> contratos;

//void para cadastro do cliente
void cadastrarCliente() {
    Cliente cliente;
    cout << "C�digo do cliente: ";
    cin >> cliente.codigo;

    for (const auto& c : clientes) {
        if (c.codigo == cliente.codigo) {
            cout << "Cliente j� cadastrado." << endl;
            return;
        }
    }

    cout << "Nome: ";
    cin.ignore();
    getline(cin, cliente.nome);

    cout << "Endere�o: ";
    getline(cin, cliente.endereco);

    cout << "Telefone: ";
    getline(cin, cliente.telefone);

    cout << "Data de nascimento: ";
    getline(cin, cliente.dataNascimento);

    clientes.push_back(cliente);
    cout << "Cliente cadastrado com sucesso." << endl;
}


void cadastrarFornecedor() {
    Fornecedor fornecedor;
    cout << "C�digo do fornecedor: ";
    cin >> fornecedor.codigo;

    for (const auto& f : fornecedores) {
        if (f.codigo == fornecedor.codigo) {
            cout << "Fornecedor j� cadastrado." << endl;
            return;
        }
    }

    cout << "Nome do buffet: ";
    cin.ignore();
    getline(cin, fornecedor.nome);

    cout << "Telefone: ";
    getline(cin, fornecedor.telefone);

    fornecedores.push_back(fornecedor);
    cout << "Fornecedor cadastrado com sucesso." << endl;
}


void cadastrarFesta() {
    Festa festa;
    cout << "C�digo da festa: ";
    cin >> festa.codigo;

    for (const auto& f : festas) {
        if (f.codigo == festa.codigo) {
            cout << "Festa j� cadastrada." << endl;
            return;
        }
    }

    cout << "C�digo do cliente: ";
    cin >> festa.codigoCliente;

    bool clienteEncontrado = false;
    for (const auto& c : clientes) {
        if (c.codigo == festa.codigoCliente) {
            clienteEncontrado = true;
            break;
        }
    }

    if (!clienteEncontrado) {
        cout << "Cliente n�o encontrado." << endl;
        return;
    }

    cout << "Quantidade de convidados: ";
    cin >> festa.quantidadeConvidados;

    cout << "Data: ";
    cin.ignore();
    getline(cin, festa.data);

    cout << "Hor�rio de in�cio (HH:MM): ";
    getline(cin, festa.horarioInicio);

    cout << "Hor�rio de t�rmino (HH:MM): ";
    getline(cin, festa.horarioTermino);

    cout << "Tema: ";
    getline(cin, festa.tema);

    cout << "C�digo do fornecedor: ";
    cin >> festa.codigoFornecedor;

    bool fornecedorEncontrado = false;
    for (const auto& f : fornecedores) {
        if (f.codigo == festa.codigoFornecedor) {
            fornecedorEncontrado = true;
            break;
        }
    }

    if (!fornecedorEncontrado) {
        cout << "Fornecedor n�o encontrado." << endl;
        return;
    }

    
    for (const auto& f : festas) {
        if (f.data == festa.data && f.horarioInicio == festa.horarioInicio) {
            cout << "J� existe uma festa marcada para essa data e hor�rio." << endl;
            return;
        }
    }

    festa.diaSemana = "";  
    festas.push_back(festa);
    cout << "Festa cadastrada com sucesso." << endl;
}


void calcularValorContrato() {
    string codigoFesta;
    cout << "C�digo da festa: ";
    cin >> codigoFesta;

    bool festaEncontrada = false;
    for (const auto& festa : festas) {
        if (festa.codigo == codigoFesta) {
            festaEncontrada = true;

            Contrato contrato;
            contrato.codigoFesta = festa.codigo;

            if (festa.quantidadeConvidados <= 30) {
                if (festa.diaSemana == "Sexta" || festa.diaSemana == "S�bado" || festa.diaSemana == "Domingo") {
                    contrato.valorTotal = 2099.0;
                } else {
                    contrato.valorTotal = 1899.0;
                }
            } else if (festa.quantidadeConvidados <= 50) {
                if (festa.diaSemana == "Sexta" || festa.diaSemana == "S�bado" || festa.diaSemana == "Domingo") {
                    contrato.valorTotal = 2299.0;
                } else {
                    contrato.valorTotal = 2199.0;
                }
            } else if (festa.quantidadeConvidados <= 80) {
                if (festa.diaSemana == "Sexta" || festa.diaSemana == "S�bado" || festa.diaSemana == "Domingo") {
                    contrato.valorTotal = 3499.0;
                } else {
                    contrato.valorTotal = 3199.0;
                }
            } else if (festa.quantidadeConvidados <= 100) {
                if (festa.diaSemana == "Sexta" || festa.diaSemana == "S�bado" || festa.diaSemana == "Domingo") {
                    contrato.valorTotal = 3999.0;
                } else {
                    contrato.valorTotal = 3799.0;
                }
            }

            
            string formaPagamento;
            cout << "Forma de pagamento (A vista, Duas vezes, Tr�s vezes, Quatro ou mais vezes): ";
            cin.ignore();
            getline(cin, formaPagamento);

            if (formaPagamento == "A vista") {
                contrato.desconto = contrato.valorTotal * 0.1;
            } else if (formaPagamento == "Duas vezes") {
                contrato.desconto = contrato.valorTotal * 0.05;
            } else if (formaPagamento == "Tr�s vezes") {
                contrato.desconto = contrato.valorTotal * 0.02;
            } else {
                contrato.desconto = 0.0;
            }

            contrato.valorFinal = contrato.valorTotal - contrato.desconto;
            contrato.status = "a pagar";

            contratos.push_back(contrato);

            cout << "Valor total: " << contrato.valorTotal << endl;
            cout << "Valor final: " << contrato.valorFinal << endl;
            cout << "Contrato gerado com sucesso." << endl;

            break;
        }
    }

    if (!festaEncontrada) {
        cout << "Festa n�o encontrada." << endl;
    }
}


void atualizarStatusContrato() {
    string codigoFesta;
    cout << "C�digo da festa: ";
    cin >> codigoFesta;

    bool festaEncontrada = false;
    for (auto& contrato : contratos) {
        if (contrato.codigoFesta == codigoFesta) {
            festaEncontrada = true;

            string status;
            cout << "Novo status (pago ou cancelado): ";
            cin.ignore();
            getline(cin, status);

            if (status == "pago" || status == "cancelado") {
                contrato.status = status;
                cout << "Status atualizado com sucesso." << endl;
            } else {
                cout << "Status inv�lido." << endl;
            }

            break;
        }
    }

    if (!festaEncontrada) {
        cout << "Festa n�o encontrada." << endl;
    }
}


void pesquisarCliente() {
    string termo;
    cout << "Nome ou c�digo do cliente: ";
    cin.ignore();
    getline(cin, termo);

    bool clienteEncontrado = false;
    for (const auto& cliente : clientes) {
        if (cliente.nome == termo || cliente.codigo == termo) {
            cout << "C�digo: " << cliente.codigo << endl;
            cout << "Nome: " << cliente.nome << endl;
            cout << "Endere�o: " << cliente.endereco << endl;
            cout << "Telefone: " << cliente.telefone << endl;
            cout << "Data de nascimento: " << cliente.dataNascimento << endl;
            cout << endl;

            clienteEncontrado = true;
        }
    }

    if (!clienteEncontrado) {
        cout << "Cliente n�o encontrado." << endl;
    }
}


void pesquisarFornecedor() {
    string termo;
    cout << "Nome ou c�digo do fornecedor: ";
    cin.ignore();
    getline(cin, termo);

    bool fornecedorEncontrado = false;
    for (const auto& fornecedor : fornecedores) {
        if (fornecedor.nome == termo || fornecedor.codigo == termo) {
            cout << "C�digo: " << fornecedor.codigo << endl;
            cout << "Nome: " << fornecedor.nome << endl;
            cout << "Telefone: " << fornecedor.telefone << endl;
            cout << endl;

            fornecedorEncontrado = true;
        }
    }

    if (!fornecedorEncontrado) {
        cout << "Fornecedor n�o encontrado." << endl;
    }
}


void pesquisarFesta() {
    string codigoFesta;
    cout << "C�digo da festa: ";
    cin >> codigoFesta;

    bool festaEncontrada = false;
    for (const auto& festa : festas) {
        if (festa.codigo == codigoFesta) {
            cout << "C�digo: " << festa.codigo << endl;
            cout << "Quantidade de convidados: " << festa.quantidadeConvidados << endl;
            cout << "Data: " << festa.data << endl;
            cout << "Dia da semana: " << festa.diaSemana << endl;
            cout << "Hor�rio de in�cio: " << festa.horarioInicio << endl;
            cout << "Hor�rio de t�rmino: " << festa.horarioTermino << endl;
            cout << "Tema: " << festa.tema << endl;
            cout << "C�digo do cliente: " << festa.codigoCliente << endl;
            cout << "C�digo do fornecedor: " << festa.codigoFornecedor << endl;
            cout << endl;

            festaEncontrada = true;
        }
    }

    if (!festaEncontrada) {
        cout << "Festa n�o encontrada." << endl;
    }
}


void pesquisarContrato() {
    string codigoFesta;
    cout << "C�digo da festa: ";
    cin >> codigoFesta;

    bool contratoEncontrado = false;
    for (const auto& contrato : contratos) {
        if (contrato.codigoFesta == codigoFesta) {
            cout << "N�mero: " << contrato.numero << endl;
            cout << "Valor total: " << contrato.valorTotal << endl;
            cout << "Desconto: " << contrato.desconto << endl;
            cout << "Valor final: " << contrato.valorFinal << endl;
            cout << "Forma de pagamento: " << contrato.formaPagamento << endl;
            cout << "Status: " << contrato.status << endl;
            cout << "C�digo da festa: " << contrato.codigoFesta << endl;
            cout << endl;

            contratoEncontrado = true;
        }
    }

    if (!contratoEncontrado) {
        cout << "Contrato n�o encontrado." << endl;
    }
}

int main() {
    int opcao;
    setlocale(LC_ALL, "Portuguese_Brazil");
    do {
        cout << "========== MENU ==========" << endl;
        cout << "1. Cadastrar cliente" << endl;
        cout << "2. Cadastrar fornecedor" << endl;
        cout << "3. Cadastrar festa" << endl;
        cout << "4. Calcular valor do contrato" << endl;
        cout << "5. Atualizar status do contrato" << endl;
        cout << "6. Pesquisar informa��es de cliente" << endl;
        cout << "7. Pesquisar informa��es de fornecedor" << endl;
        cout << "8. Pesquisar informa��es de festa" << endl;
        cout << "9. Pesquisar informa��es de contrato" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma op��o: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cadastrarCliente();
                break;
            case 2:
                               cadastrarFornecedor();
                break;
            case 3:
                cadastrarFesta();
                break;
            case 4:
                calcularValorContrato();
                break;
            case 5:
                atualizarStatusContrato();
                break;
            case 6:
                pesquisarCliente();
                break;
            case 7:
                pesquisarFornecedor();
                break;
            case 8:
                pesquisarFesta();
                break;
            case 9:
                pesquisarContrato();
                break;
            case 0:
                cout << "Encerrando o programa." << endl;
                break;
            default:
                cout << "Op��o inv�lida. Tente novamente." << endl;
                break;
        }

        cout << endl;
    } while (opcao != 0);

    return 0;
}

