#include <iostream>
#include <string>
using namespace std;

// Definição da classe ContaBancaria
class ContaBancaria {
private:
    string nomeTitular;
    int numeroConta;
    double saldo;

public:
    // Construtor
    ContaBancaria(string nome, int numero) {
        nomeTitular = nome;
        numeroConta = numero;
        saldo = 0.0;  // Saldo inicial zero
    }

    // Método para depositar dinheiro
    void depositar(double valor) {
        if (valor > 0) {
            saldo += valor;
            cout << "Depositado: R$ " << valor << endl;
        } else {
            cout << "Valor inválido para depósito." << endl;
        }
    }

    // Método para sacar dinheiro
    void sacar(double valor) {
        if (valor > saldo) {
            cout << "Saldo insuficiente." << endl;
        } else if (valor > 0) {
            saldo -= valor;
            cout << "Sacado: R$ " << valor << endl;
        } else {
            cout << "Valor inválido para saque." << endl;
        }
    }

    // Método para consultar o saldo
    double consultarSaldo() const {
        return saldo;
    }

    // Método para exibir as informações da conta
    void exibirInfo() const {
        cout << "Titular: " << nomeTitular << endl;
        cout << "Número da Conta: " << numeroConta << endl;
        cout << "Saldo: R$ " << saldo << endl;
    }
};

int main() {
    // Criando uma conta bancária
    ContaBancaria conta1("João Silva", 12345);

    // Exibindo informações iniciais da conta
    conta1.exibirInfo();
    cout << endl;

    // Operações bancárias
    conta1.depositar(1000);  // Depósito
    conta1.sacar(300);       // Saque
    conta1.sacar(800);       // Tentativa de saque maior que o saldo
    conta1.depositar(-50);   // Tentativa de depósito inválido
    conta1.sacar(200);       // Saque válido

    // Consultar saldo
    cout << "Saldo atual: R$ " << conta1.consultarSaldo() << endl;

    return 0;
}
