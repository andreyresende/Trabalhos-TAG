#ifndef DOLPHIN
#define DOLPHIN

#include <list> 
#include <iterator>

class Dolphin {
    private:
        int id;
        std::list <Dolphin> conexoes;
    public:
        Dolphin() {
            id = 0;
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

#endif