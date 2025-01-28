#include <iostream>
#include "ler_rp.hpp"
int particao(int* prioridade, int* tempo, std::string* nome, int min, int max)
{
    int aux1, aux2;
    std::string aux3;
    int pivo1 = prioridade[max];
    int pivo2 = tempo[max];
    int i = min - 1;
    
    for(int j = min; j <= max - 1; j++)
    {
        if(prioridade[j] > pivo1)
        {
            i++;
            aux1 = prioridade[i];
            prioridade[i] = prioridade[j];
            prioridade[j] = aux1;

            aux2 = tempo[i];
            tempo[i] = tempo[j];
            tempo[j] = aux2;

            aux3 = nome[i];
            nome[i] = nome[j];
            nome[j] = aux3;

        }
        else if(prioridade[j] == pivo1)
            if(tempo[j] < pivo2)
            {
                i++;
                aux1 = prioridade[i];
                prioridade[i] = prioridade[j];
                prioridade[j] = aux1;

                aux2 = tempo[i];
                tempo[i] = tempo[j];
                tempo[j] = aux2;

                aux3 = nome[i];
                nome[i] = nome[j];
                nome[j] = aux3;

                
            }
    }
    aux1 = prioridade[i + 1];
    prioridade[i + 1] = prioridade[max];
    prioridade[max] = aux1;

    aux2 = tempo[i + 1];
    tempo[i + 1] = tempo[max];
    tempo[max] = aux2;

    aux3 = nome[i + 1];
    nome[i + 1] = nome[max];
    nome[max] = aux3;

    return i + 1;
}

void quicksort(int* prioridade, int* tempo, std::string* nome, int min, int max)
{
    if(min < max)
    {
        int pi = particao(prioridade, tempo, nome, min, max);
        quicksort(prioridade, tempo, nome, min, pi - 1);
        quicksort(prioridade, tempo, nome, pi + 1, max);
    }
}

int main()
{
    restaurante_pratos bubble("restaurante_pratos.csv");
    std::cout<<"Leitura Pronta! ";
    int* prioridade = bubble.get_prioridade();
    int* tempo = bubble.get_tempo();
    std::string* nome = bubble.get_nome(); 
    int max = bubble.get_linhas_max();
    max--;
    quicksort(prioridade, tempo, nome, 0, max);
    for(int i = 0; i <= max; i++)
    {
        std::cout<< prioridade[i] << " " << nome[i] << "\n";
    }
    return 0;
}
