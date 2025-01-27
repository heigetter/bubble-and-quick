#include <iostream>
#include <iomanip>

class somar_e_dividir{
    public:
    virtual void somar(float x, float y){
        float soma;
        soma = x + y;
        std::cout<< soma << "\n";
    }
    virtual void dividir(float x, float y){
        float divisao;
        divisao = x/y;
        std::cout<< divisao << "\n";
    }
};

class somar_e_dividir_2c : public somar_e_dividir{
    public:
    void somar(float x, float y){
        float soma;
        soma = x + y;
        std::cout<< std::setprecision (2) << std::fixed << soma << "\n";
    }
    void dividir(float x, float y){
        float divisao;
        divisao = x/y;
        std::cout << std::setprecision(2) << std::fixed << divisao << "\n";
    }
};


int main(){
    somar_e_dividir *sd[2];
    sd[0] = new somar_e_dividir;
    sd[1] = new somar_e_dividir_2c;

    for(int i = 0; i < 2; i++)
    {
        sd[i]->somar(4,17);
        sd[i]->dividir(4,17);
    }
    return 0;
}