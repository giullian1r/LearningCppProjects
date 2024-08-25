#include<iostream>
#include<vector>
#include <cstdlib>
#include <ctime>
using namespace std;

char imprimir_forca(vector<char>& vetor, vector<char>& vetorDeErros, int erros){
    system("cls");
    
    cout << "|-";
    for(int i = 0; i < erros; i++){
        cout << vetorDeErros[i];
    }
    cout << endl;
    cout << "|" ;
    for(int i= 0; i < vetor.size(); i ++){
        cout << vetor[i];
    }
}

char seperar_letras(string& palavra, vector<char>& letras){
    for(int i= 0; i < palavra.size(); i++){
            letras.push_back(palavra[i]);
        }
}

char iniciar_forca(string& palavra, vector<char>& forca){
    for(int i= 0; i < palavra.size(); i++){
        forca.push_back('_');
    }
}

bool verificar_tentativa(vector<char>& letras, vector<char>& forca, char x){
    bool acertou = false;
    for(int i= 0; i < letras.size(); i++){
        if(x == letras[i]){
            cout << "Acertou a letra!" << endl;
            forca[i] = x;
            acertou = true;
        }
    }
    system("cls");
    return acertou;
}

bool verificar_vitoria(vector<char>& letras,vector<char>& forca){
int letrasIguais = 0;
    for(int i = 0; i < forca.size(); i++){
        if(forca[i] == letras[i]){
            letrasIguais = letrasIguais + 1;
        }
        if (letrasIguais == letras.size()){
            return true;
        }
    }
    return false;
}

bool verificar_derrota(vector<char>& vErros,int erros){
    if(vErros.size() + 1 == erros) { 
        return true;
    }
    return false;
}

int main(){
    vector<string> bancoDePalavras({"vampiro","batman","shrek","gato","dragao"});
    vector<char> vetorDeErros({'o','-',')','-','-','('});
    vector<char> letras;
    vector<char> forca;

    srand(time(0)); 
    int numeroAleatorio = rand() % bancoDePalavras.size();

    string palavraAtual = bancoDePalavras[numeroAleatorio];
    seperar_letras(palavraAtual, letras);
    iniciar_forca(palavraAtual, forca);

    bool ganhou = false;
    bool perdeu = false;
    int erros = 0;
    while(!ganhou && !perdeu){
        char tentativa;

        imprimir_forca(forca,vetorDeErros,erros);
        if (erros == vetorDeErros.size()){
            cout <<endl << "Ultima chance!";
        } 
        cout << endl << "digite uma letra: ";
        cin >> tentativa;    

        if(!verificar_tentativa(letras,forca,tentativa)){
            erros = erros + 1;
        }
        ganhou = verificar_vitoria(letras,forca);
        perdeu = verificar_derrota(vetorDeErros, erros);

    }
    if(ganhou){
        imprimir_forca(forca,vetorDeErros,erros);
        cout << endl;
        cout << "Parabens!!! Voce fugiu da forca :)";
    }
    if(perdeu){
        imprimir_forca(forca,vetorDeErros,erros - 1);
        cout << endl;
        cout << "Voce ficou na forca :/";
    }

    cout << endl << "Deseja jogar novamente? s/n : ";
    char jogarNovamente;
    cin >> jogarNovamente;
    if(jogarNovamente == 's'){
        main();
    }
}