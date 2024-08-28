#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<windows.h>
using namespace std;

//necessario para deixar as palavras coloridas no console
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
                                                                                        
char imprimir_forca(vector<char>& vetor,vector<char>& vetorDeErros,vector<char>& vetorDeUsadas, int erros){
    system("cls");
    
    cout << "|-";    
    SetConsoleTextAttribute(h,14);
    for(int i = 0; i < erros; i++){
        cout << vetorDeErros[i];
    }
    SetConsoleTextAttribute(h,7);
    cout << endl << "|";
    for(int i = 0; i < vetor.size(); i ++){
        cout << vetor[i];
    }
    cout << endl;
    for(int i = 0; i < vetorDeUsadas.size(); i++){
        cout << vetorDeUsadas[i] << " ";
    }
}

bool verifica_se_existe_no_vetor(vector<char>& vetor, char x){
    for (int i = 0; i < vetor.size(); i++)
    {
        if(x == vetor[i]){
            return false;
        }
    }
    return true;
}

char seperar_letras(vector<char>& letras,string& palavra){
    for(int i= 0; i < palavra.size(); i++){
        letras.push_back(palavra[i]);
    }
}

char iniciar_forca(vector<char>& forca,string& palavra){
    for(int i= 0; i < palavra.size(); i++){
        forca.push_back('_');
    }
}

bool verificar_tentativa(vector<char>& letras,vector<char>& forca,char x){
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

bool verificar_ultima_chance(vector<char>& vErros,int erros){
    if (erros == vErros.size()){
        cout <<endl << "Ultima chance!";
    } 
}

bool resultado_da_forca(vector<char>& forca,vector<char>& vErros,vector<char>& letrasUsadas, int erros,bool ganhou, bool perdeu,int pontos){
    if(ganhou){
        imprimir_forca(forca,vErros,letrasUsadas,erros);
        cout << endl;
        cout << "Parabens!!! Voce fugiu da forca :)";
    }
    if(perdeu){
        imprimir_forca(forca,vErros,letrasUsadas,erros - 1);
        cout << endl;
        cout << "Voce ficou na forca :/";
    }
}

int main(){
    vector<string> bancoDePalavras({"vampiro","batman","shrek","gato","dragao"});
    vector<char> vetorDeErros({'o','-',')','-','-','('});
    vector<char> letras;
    vector<char> letrasUsadas;
    vector<char> forca;

    //seleciona uma palavra aleatoria do vetor 
    srand(time(0)); 
    int numeroAleatorio = rand() % bancoDePalavras.size();
    string palavraAtual = bancoDePalavras[numeroAleatorio];

    seperar_letras(letras,palavraAtual);
    iniciar_forca(forca,palavraAtual);

    bool ganhou = false;
    bool perdeu = false;
    int erros = 0;
    int pontos = 0;

    while(!ganhou && !perdeu){
        char tentativa;

        imprimir_forca(forca,vetorDeErros,letrasUsadas,erros);
        verificar_ultima_chance(vetorDeErros,erros);

        cout << endl << "digite uma letra: ";
        SetConsoleTextAttribute(h,13);
        cout << endl << "seus pontos: " << pontos << endl;
        SetConsoleTextAttribute(h,7);
        cin >> tentativa;    

        if(verifica_se_existe_no_vetor(letrasUsadas,tentativa)){
            letrasUsadas.push_back(tentativa);
        }
        if(!verificar_tentativa(letras,forca,tentativa)){
            erros = erros + 1;
            pontos = pontos - 2;
        }
        else{
            pontos = pontos + 5;
        }

        ganhou = verificar_vitoria(letras,forca);
        perdeu = verificar_derrota(vetorDeErros, erros);
    }
    resultado_da_forca(forca,vetorDeErros,letrasUsadas,erros,ganhou,perdeu,pontos);
    SetConsoleTextAttribute(h,13);
    cout << endl << "seus pontos finais: " << pontos << endl;
    SetConsoleTextAttribute(h,7);
    
    int jogarNovamente;
    while((jogarNovamente != 1) && (jogarNovamente !=2)){
        cout << endl << "Deseja jogar novamente? 1.sim 2.nao : ";
        cin >> jogarNovamente;

        if(jogarNovamente == 1){
            main();
        }
    }
}