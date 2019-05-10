#ifndef SAFETY_COEFFICIENT_FINDER_QUORUMFINDER_H
#define SAFETY_COEFFICIENT_FINDER_QUORUMFINDER_H

#include <string>
#include <stdexcept>
#include "FindingStrategy.h"

using namespace std;

class QuorumFinder {
private:
    FindingStrategy *strategy;
public:
    QuorumFinder () {
        strategy = nullptr;
    }

    void setStrategy(string &searchType){
        if (searchType == "all")
            strategy = new AllStrategy();
        else if (searchType == "minimal")
            strategy = new MinimalStrategy();
        else if (searchType == "random")
            strategy = new RandomStrategy();
        else throw invalid_argument("This type of search does not exist!");
    }

    void find(vector<pair<int, vector<int> > > &quorumSlices, vector<vector<int> >&quorums){
        strategy->findQuorums(quorumSlices, quorums);
    }
};

#endif //SAFETY_COEFFICIENT_FINDER_QUORUMFINDER_H
