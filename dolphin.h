#ifndef DOLPHIN
#define DOLPHIN

#include <list> 
#include <iterator>


class Dolphin {
    private:
        int id;
    public:
        std::list <Dolphin> conexoes;
        int totalConexoes;
        Dolphin() {
            id = 0;
            totalConexoes = 0;
        }
        void setId(int id) {
            this->id = id;
        }
        int getId() {
            return this->id;
        }
        void setConnection(Dolphin idRef) {
            this->conexoes.push_back(idRef);
        } 
};

class Graph {
    private: 
    public: 
        std::list <Dolphin> listaTotal;
        void setGraph(Dolphin dolphin){
            listaTotal.push_back(dolphin);
        }
};
#endif