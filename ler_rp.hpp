#include <fstream>
#include <iostream>
#include <sstream>



class restaurante_pratos{
    private:
    std::string arquivo, nome;
    int linhas_max, prioridade, tempo;
    int* l_prio;
    int* l_tempo;
    std::string* l_nome;
    int pegar_linhas_max()
    {
    std::ifstream file(arquivo);
    if (!file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
    }
    std::string line;
    int row = 0;
    getline(file, line);
    while (getline(file, line)) {
        row++;
    }
    file.close();
    return row;
    }
    void criar_listas()
    {
        l_prio = new int[linhas_max];
        l_tempo = new int[linhas_max];
        l_nome = new std::string[linhas_max];
    }
    public:

    restaurante_pratos(std::string arquivo)
    {
    this->arquivo = arquivo;
    this->linhas_max = pegar_linhas_max();
    criar_listas();

    std::ifstream file(arquivo);
    
    if (!file.is_open()) {
        std::cerr << "Erro na hora de abrir o arquivo!" << std::endl;
    }

    std::string line;
    std::getline(file, line);
    int linhas = 0;

    while (std::getline(file, line) && linhas < linhas_max) 
    {
        std::stringstream ss(line);
        std::string prioridade_str, tempo_str;
        if(std::getline(ss, prioridade_str, ',') &&
           std::getline(ss, tempo_str, ',') &&
           std::getline(ss, nome, ',')){
            l_prio[linhas] = std::stoi(prioridade_str);
            l_tempo[linhas] = std::stoi(tempo_str);
            l_nome[linhas] = nome;
            linhas++;
            }
    }
    }

    std::string* get_nome()
    {
        return l_nome;
    }

    int* get_prioridade()
    {
        return l_prio;
    }

    int* get_tempo()
    {
        return l_tempo;
    }

    int get_linhas_max()
    {
        return linhas_max;
    }
    
    ~restaurante_pratos()
    {
        delete [] l_nome;
        delete [] l_prio;
        delete [] l_tempo;
    }
};