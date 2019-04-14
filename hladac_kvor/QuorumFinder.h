#ifndef HLADAC_KVOR_QUORUMFINDER_H
#define HLADAC_KVOR_QUORUMFINDER_H

#include <string>
#include <stdexcept>
#include "FindingStrategy.h"

using namespace std;

class QuorumFinder {
    public:
        QuorumFinder () {
            strategy = nullptr;
        }

        void setStrategy(string &searchType){
            if (searchType == "all")
                strategy = new FindThemAllStrategy();
            else if (searchType == "minimal")
                strategy = new MinimalStrategy();
            else
                throw invalid_argument("This type of search does not exist!");
        }

        void find(int N, vector<pair<int, vector<int> > > &quorumSlices, vector<int> &result){
            strategy->findQuorums(N, quorumSlices, result);
        }

    private:
        FindingStrategy *strategy;
};


#endif //HLADAC_KVOR_QUORUMFINDER_H
