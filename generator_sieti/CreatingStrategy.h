//
// Created by samuel on 4.4.2019.
//

#ifndef GENERATOR_SIETI_CREATINGSTRATEGY_H
#define GENERATOR_SIETI_CREATINGSTRATEGY_H

#include <iostream>
#include <vector>

using namespace std;


class CreatingStrategy {
    public:
        CreatingStrategy() = default;

        virtual void createNetwork(int N, int Q, int K) = 0;
};

class CyclicStrategy: public CreatingStrategy {
    public:
        CyclicStrategy() = default;

        void createNetwork(int N, int Q, int K) override {
            cout <<N<<endl;

            for(int i=0;i<N;i++) {
                cout <<Q<<" "<<K;
                for(int j=1;j<=Q;j++)cout <<" "<<(i+j)%N;
                cout <<endl;
            }
        }
};

class ChainStrategy: public CreatingStrategy {
    public:
        ChainStrategy() = default;

        void createNetwork(int N, int Q, int K) override {
            cout <<N<<endl;

            for(int i=0;i<N;i++) {
                cout <<Q<<" "<<K;
                if(i+Q>=N) {
                    for(int j=N-Q-1;j<N;j++){
                        if(j!=i)cout <<" "<<j;
                    }
                }
                else for(int j=1;j<=Q;j++)cout <<" "<<(i+j);

                cout <<endl;
            }
        }
};

class RandomStrategy: public CreatingStrategy {
    public:
        RandomStrategy() = default;

        void createNetwork(int N, int Q, int K) override {
            //fisher-yates algorithm
            cout <<N<<endl;

            for(int i=0;i<N;i++) {
                cout <<Q<<" "<<K;
                vector<int> nodeNumbers;
                for(int j=0;j<N;j++){
                    if(i!=j)nodeNumbers.push_back(j);
                }

                for(int j=0;j<Q;j++){
                    int index = rand()%(N-1-j);
                    cout <<" "<<nodeNumbers[index];
                    swap(nodeNumbers[index], nodeNumbers[N-2-j]);
                }

                cout <<endl;
            }
        }
};


class BiChainStrategy: public CreatingStrategy {
    public:
        BiChainStrategy() = default;

        void createNetwork(int N, int Q, int K) override {
            cout <<N<<endl;

            for(int i=0;i<N;i++) {
                vector<int> quorum;

                for(int j=max(i-Q/2,0);j<=min(i+Q/2+(Q%2!=0),N-1);j++){
                    if(i!=j)quorum.push_back(j);
                }

                int pocet_postacujucich = K - (Q-int(quorum.size()));

                cout <<quorum.size()<<" "<< max(1,pocet_postacujucich);
                for(int uzol : quorum)cout <<" "<<uzol;

                cout <<endl;
            }
        }
};

class BiCyclicStrategy: public CreatingStrategy {
    public:
        BiCyclicStrategy() = default;

        void createNetwork(int N, int Q, int K) override {
            cout <<N<<endl;

            for(int i=0;i<N;i++) {
                cout <<Q<<" "<<K;
                for(int j=0;j<=Q;j++){
                    int nodeNumber=i+j-Q/2;
                    if(nodeNumber>=N)nodeNumber-=N;
                    else if(nodeNumber<0)nodeNumber+=N;

                    if(nodeNumber!=i)cout <<" "<<nodeNumber;

                }
                cout <<endl;
            }
        }
};

#endif //GENERATOR_SIETI_CREATINGSTRATEGY_H
