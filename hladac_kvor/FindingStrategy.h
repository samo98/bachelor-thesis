#ifndef HLADAC_KVOR_FINDINGSTRATEGY_H
#define HLADAC_KVOR_FINDINGSTRATEGY_H

#include <utility>
#include <vector>
#include <iostream>
#include "common.h"

using namespace std;


class FindingStrategy {
    public:
        FindingStrategy() = default;

        virtual void findQuorums(int N, vector<pair<int, vector<int> > > &quorumSlices, vector<int> &result) = 0;
};

class FindThemAllStrategy: public FindingStrategy {
    public:
        FindThemAllStrategy() = default;

        void findQuorums(int N, vector<pair<int, vector<int> > > &quorumSlices, vector<int> &result) override {
            for (int i = 1; i < (1 << N); i++) {
                //verify if it is quorum
                bool isQuorum = true;
                for (int j = 0; j < N; j++) {
                    if (isInSet(i, j)) {
                        if (!hasQuorumSlice(quorumSlices[j], i)) {
                            isQuorum = false;
                            break;
                        }
                    }
                }

                if (isQuorum)result.push_back(i);
            }
        }
};

class MinimalStrategy: public FindingStrategy {
    public:
        MinimalStrategy() = default;

        void findQuorums(int N, vector<pair<int, vector<int> > > &quorumSlices, vector<int> &result) override {
            vector<bool> quorum((1 << N), false);

            for (int i = 1; i < (1 << N); i++) {
                //verify if subset isn't already quorum
                for (int j = 0; j < N; j++) {
                    if (isInSet(i, j)) {
                        if (quorum[i - (1 << j)]) {
                            quorum[i] = true;
                            break;
                        }
                    }
                }

                if (quorum[i])continue;

                //verify if it is quorum
                quorum[i] = true;
                for (int j = 0; j < N; j++) {
                    if (isInSet(i, j)) {
                        if (!hasQuorumSlice(quorumSlices[j], i)) {
                            quorum[i] = false;
                            break;
                        }
                    }
                }

                if (quorum[i])result.push_back(i);
            }
        }
};

#endif //HLADAC_KVOR_FINDINGSTRATEGY_H
