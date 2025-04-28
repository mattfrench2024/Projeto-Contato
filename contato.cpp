#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int calcularIdade(int dia, int mes, int ano) {
    time_t t = time(0);
    struct tm* now = localtime(&t);

    int idade = (now->tm_year + 1900) - ano;  

    if ((now->tm_mon + 1) < mes || ((now->tm_mon + 1) == mes && now->tm_mday < dia)) {
        idade--;  // Ajusta a idade se ainda não fez aniversário este ano
    }

    return idade;
}

int main() {
    string nome, email, telefone;
    int dia, mes, ano;

    for (int i = 0; i < 5; i++) {
        cout << "\nCadastro do contato " << i + 1 << ":\n";
        
        cout << "Nome: ";
        getline(cin, nome);
        
        cout << "Email: ";
        getline(cin, email);
        
        cout << "Telefone: ";
        getline(cin, telefone);
        
        cout << "Dia de nascimento: (apenas o dia de 1 a 31) ";
        cin >> dia;
        
        cout << "Mês de nascimento: ";
        cin >> mes;
        
        cout << "Ano de nascimento: ";
        cin >> ano;

        int idade = calcularIdade(dia, mes, ano);

        cout << "\n--- Contato Cadastrado ---\n";
        cout << "Nome: " << nome << endl;
        cout << "Email: " << email << endl;
        cout << "Telefone: " << telefone << endl;
        cout << "Idade: " << idade << " anos" << endl;
        cout << "-----------------------------" << endl;
    }

    return 0;
}
