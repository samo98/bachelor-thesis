#ifndef NETWORK_GENERATOR_CREATINGSTRATEGY_H
#define NETWORK_GENERATOR_CREATINGSTRATEGY_H

#include <iostream>
#include <vector>

using namespace std;


class CreatingStrategy {
    public:
        CreatingStrategy() = default;

        virtual void createNetwork(int N, int Q, vector<vector<int> > &quorumSlices) = 0;
};

class CyclicStrategy: public CreatingStrategy {
    public:
        CyclicStrategy() = default;

        void createNetwork(int N, int Q, vector<vector<int> > &quorumSlices) override {
            for(int i=0;i<N;i++) {
                for(int j=1;j<=Q;j++)quorumSlices[i].push_back((i+j)%N);
            }
        }
};

class ChainStrategy: public CreatingStrategy {
    public:
        ChainStrategy() = default;

        void createNetwork(int N, int Q, vector<vector<int> > &quorumSlices) override {
            for(int i=0;i<N;i++) {
                if(i+Q>=N) {
                    for(int j=N-Q-1;j<N;j++){
                        if(j!=i)quorumSlices[i].push_back(j);
                    }
                }
                else for(int j=1;j<=Q;j++)quorumSlices[i].push_back(i+j);
            }
        }
};

class RandomStrategy: public CreatingStrategy {
    public:
        RandomStrategy() = default;

        void createNetwork(int N, int Q, vector<vector<int> > &quorumSlices) override {
            //fisher-yates algorithm
            for(int i=0;i<N;i++) {
                vector<int> availableNodes;
                for(int j=0;j<N;j++){
                    if(i!=j)availableNodes.push_back(j);
                }

                for(int j=0;j<Q;j++){
                    int index = rand()%(N-1-j);
                    quorumSlices[i].push_back(availableNodes[index]);
                    swap(availableNodes[index], availableNodes[N-2-j]);
                }
            }
        }
};

#endif //NETWORK_GENERATOR_CREATINGSTRATEGY_H
