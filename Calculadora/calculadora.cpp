#include<iostream>
#include <cstdlib>

using namespace std;

float somar(float a,float b){
    return a + b;    
}

float subtrair(float a, float b){
    return a - b;
}

float multiplicar(float a, float b){
    return a * b;
}

float dividir(float a, float b){
    if (b == 0){
        cout << "Erro, divisao por zero" << endl;
        return 0;
    }
    return a / b;
}

char menu_opcoes() {
    float n1, n2;
    float result;
    char continuar = 's';
    char operacao;
    bool sequencia = false;

    system("cls");
    cout << "*** Calculadora 3000 ***" << endl;
    cout << "Digite um numero: ";
    cin >> n1;

    while (continuar == 's') {
        if (sequencia) {
            n1 = result;
            cout << "Resultado atual: " << result << endl;
        }

        cout << "Escolha uma operacao (+, -, *, /): ";
        cin >> operacao;

        if (operacao != '+' && operacao != '-' && operacao != '*' && operacao != '/') {
            cout << "Operação invalida!" << endl;
        }

        cout << "Digite mais um numero: ";
        cin >> n2;

         switch (operacao) {
            case '+':
                result = somar(n1, n2);
                break;
            case '-':
                result = subtrair(n1, n2);
                break;
            case '*':
                result = multiplicar(n1, n2);
                break;
            case '/':
                result = dividir(n1, n2);
                break;
        }

        cout << "Resultado: " << result << endl;
        cout << "Continuar Conta? s/n: ";
        cin >> continuar;

        if (continuar == 's') {
            sequencia = true;
        }
        system("cls");
    }
}

int main(){
    menu_opcoes();
}