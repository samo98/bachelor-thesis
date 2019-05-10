#ifndef NETWORK_GENERATOR_NETWORKCREATOR_H
#define NETWORK_GENERATOR_NETWORKCREATOR_H

#include <string>
#include <stdexcept>
#include "CreatingStrategy.h"

using namespace std;

class NetworkCreator {
    private:
        CreatingStrategy *strategy;

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
            else
                throw invalid_argument("Unknown network type!");
        }

        void create(int N, int Q, vector<vector<int> > &quorumSlices){
            if(Q>=N) throw invalid_argument("Q should be less than N");

            quorumSlices.resize(N);
            strategy->createNetwork(N, Q, quorumSlices);
        }
};


#endif //NETWORK_GENERATOR_NETWORKCREATOR_H
