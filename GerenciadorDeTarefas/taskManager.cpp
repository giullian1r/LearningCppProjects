#include<iostream>
#include<vector>
#include<windows.h>
using namespace std;

//deixar letras coloridas no console    
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

void create(vector<string>& vector){
    string task;
    system("cls");
    cout << "o que deseja adicionar" << endl;
    cin >> task;

    SetConsoleTextAttribute(h,2);
    cout << endl << "tarefa criada com sucesso!" << endl;
    SetConsoleTextAttribute(h,7);

    vector.push_back(task);
}

void read(vector<string>& vector){
    system("cls");

    if(vector.size() == 0){
        SetConsoleTextAttribute(h,14);
        cout << "nenhuma tarefa encontrada" << endl;
        SetConsoleTextAttribute(h,7);
        return;
    }
    cout << " Tarefas :" << endl;

    for(int i= 0; i < vector.size(); i++){
        cout << (i + 1) << ". " << vector[i] << endl;
    }
    cout << endl;
}

bool existe(vector<string>& vector, int x){
    if(x > vector.size()){
        return false;
    }
    return true;
}

void remove(vector<string>& vector){
    int del;
    cout << "que tarefa deseja remover? (numero)";
    cin >> del;
    cout << endl;

    if(existe(vector, del)){
        for(int i = del - 1; i < vector.size() - 1; i++){
            vector[i] = vector[i + 1];
        }
        vector.resize(vector.size() - 1);
        
        SetConsoleTextAttribute(h,2);
        cout << "tarefa removida com sucesso!" << endl;
        SetConsoleTextAttribute(h,7);
    }
    else{
        SetConsoleTextAttribute(h,4);
        cout << "tarefa nao encontrada!" << endl;
        SetConsoleTextAttribute(h,7);
    }
}

void menu(vector<string>& vector){
    int n;
    bool continuar = true;

    while(continuar){
        cout << "O que deseja fazer? " << endl 
        << "1. Listar tarefas " << endl
        << "2. Adicionar tarefa" << endl 
        << "3. Remover tarefa" << endl 
        << "4. sair"<< endl;

        cin >> n;
        cout << endl;

        switch (n)
        {
        case 1:
            read(vector);
            break;
        case 2:
            create(vector);
            break;
        case 3:
            remove(vector);
            break;
        case 4:
            break;
        default:
            SetConsoleTextAttribute(h, 4);
            cout << "opcao invalida!" << endl;
            SetConsoleTextAttribute(h, 7);
            break;
        }
        if(n == 4){
            continuar = false;
        }
    }
}
int main(){
    vector<string> tasks({});
    menu(tasks);
}