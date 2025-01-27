#include <iostream>
#include "ler_rp.hpp"
void bubble_sort(int* prioridade, int* tempo, std::string* nome, int max)
{
int aux1, aux2;
std::string aux3;

for(int i = 0; i < max - 1; i++)
{
    for(int j = 0; j < max - i - 1; j++)
    {
        if(prioridade[j] < prioridade[j + 1])
        {
            aux1 = prioridade[j];
            prioridade[j] = prioridade[j + 1];
            prioridade[j + 1] = aux1;

            aux2 = tempo[j];
            tempo[j] = tempo[j + 1];
            tempo[j + 1] = aux2;

            aux3 = nome[j];
            nome[j] = nome[j + 1];
            nome[j + 1] = aux3;
        }
        else if(prioridade[j] == prioridade[j + 1])
            if(tempo[j] > tempo[j + 1])
            {
              aux1 = prioridade[j];
              prioridade[j] = prioridade[j + 1];
              prioridade[j + 1] = aux1;

              aux2 = tempo[j];
              tempo[j] = tempo[j + 1];
              tempo[j + 1] = aux2;

              aux3 = nome[j];
              nome[j] = nome[j + 1];
              nome[j + 1] = aux3;  
            }
    }
}


}
int main()
{
    restaurante_pratos bubble("restaurante_pratos.csv");
    std::cout<<"Leitura Pronta!";
    int* prioridade = bubble.get_prioridade();
    int* tempo = bubble.get_tempo();
    std::string* nome = bubble.get_nome(); 
    int max = bubble.get_linhas_max();

    bubble_sort(prioridade, tempo, nome, max);
    for(int i = 0; i < max; i++)
    {
        std::cout<< prioridade[i] << " " << nome[i] << "\n";
    }
    
    return 0;
}