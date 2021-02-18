#include <iostream>
#include <string>

typedef int Cable;

class EuropeanSocket
{
    public:
        virtual int voltage() = 0;

        virtual Cable live() = 0;
        virtual Cable neutral() = 0; 
        virtual Cable earth() = 0;
};

class Socket : public EuropeanSocket
{
    public:
        int voltage() { return 230; }

        Cable live() { return 1; }
        Cable neutral() { return -1; }
        Cable earth() { return 0; }
};

class USASocket
{
    public:
        virtual int voltage() = 0;

        virtual Cable live() = 0;
        virtual Cable neutral() = 0;
};

class Adapter : public USASocket
{
    private:
        EuropeanSocket* socket;

    public:
        void plugIn(EuropeanSocket* outlet)
        {
            socket = outlet;
        }

        int voltage() { return 110; }
        Cable live() { return socket->live(); }
        Cable neutral() { return socket->neutral(); }
};

class ElectricKettle
{
    private:
        USASocket* power;

    public:
        void plugIn(USASocket* supply)
        {
            power = supply;
        }

        void boil()
        {
            if (power->voltage() > 110)
            {
                std::cout << "Kettle is on fire!" << std::endl;
                return;
            }

            if (power->live() == 1 && power->neutral() == -1)
            {
                std::cout << "Coffee time!" << std::endl;
            }
        }
};


int main()
{
    Socket* socket = new Socket;
    Adapter* adapter = new Adapter;
    ElectricKettle* kettle = new ElectricKettle;

    adapter->plugIn(socket);
    kettle->plugIn(adapter);

    kettle->boil();

    delete socket;
    delete adapter;
    delete kettle;

    return 0;
}