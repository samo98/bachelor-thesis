#ifndef GENERATOR_SIETI_NETWORKCREATOR_H
#define GENERATOR_SIETI_NETWORKCREATOR_H

#include <string>
#include <stdexcept>
#include "CreatingStrategy.h"

using namespace std;

class NetworkCreator {
    public:
        NetworkCreator () {
            strategy = nullptr;
        }

        void setStrategy(string &networkType){
            if (networkType == "cyclic")
                strategy = new CyclicStrategy();
            else if (networkType == "chain")
                strategy = new ChainStrategy();
            else if (networkType == "random")
                strategy = new RandomStrategy();
            else if (networkType == "bichain")
                strategy = new BiChainStrategy();
            else if (networkType == "bicyclic")
                strategy = new BiCyclicStrategy();
            else
                throw invalid_argument("Unknown network type!");
        }

        void create(int N, int Q, int K){
            strategy->createNetwork(N, Q, K);
        }

    private:
        CreatingStrategy *strategy;
};


#endif //GENERATOR_SIETI_NETWORKCREATOR_H
