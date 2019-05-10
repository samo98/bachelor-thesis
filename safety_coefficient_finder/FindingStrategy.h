#ifndef SAFETY_COEFFICIENT_FINDER_FINDINGSTRATEGY_H
#define SAFETY_COEFFICIENT_FINDER_FINDINGSTRATEGY_H

#include <utility>
#include <vector>
#include <iostream>
#include <stack>
#include <set>
#include <queue>
#include <unistd.h>
#include "helpers.h"

using namespace std;

extern int N;


class FindingStrategy {
public:
    FindingStrategy() = default;

    virtual void findQuorums(vector<pair<int, vector<int> > > &quorumSlices, vector<vector<int> >&quorums) = 0;
};

class AllStrategy: public FindingStrategy {
public:
    AllStrategy() = default;

    void findQuorums(vector<pair<int, vector<int> > > &quorumSlices, vector<vector<int>>&result) override {
        vector<int> quorums;
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

            if (isQuorum)quorums.push_back(i);
        }

        for(int quorum:quorums){
            result.push_back(intToQuorum(N, quorum));
        }
    }
};

class MinimalStrategy: public FindingStrategy {
public:
    MinimalStrategy() = default;

    void findQuorums(vector<pair<int, vector<int> > > &quorumSlices, vector<vector<int> >&result) override {
        vector<bool> is_quorum((1 << N), false);
        vector<int> quorums;

        for (int i = 1; i < (1 << N); i++) {
            //verify if subset isn't already quorum
            for (int j = 0; j < N; j++) {
                if (isInSet(i, j)) {
                    if (is_quorum[i - (1 << j)]) {
                        is_quorum[i] = true;
                        break;
                    }
                }
            }

            if (is_quorum[i])continue;

            //verify if it is quorum
            is_quorum[i] = true;
            for (int j = 0; j < N; j++) {
                if (isInSet(i, j)) {
                    if (!hasQuorumSlice(quorumSlices[j], i)) {
                        is_quorum[i] = false;
                        break;
                    }
                }
            }

            if (is_quorum[i])quorums.push_back(i);
        }

        for(int quorum:quorums){
            result.push_back(intToQuorum(N, quorum));
        }
    }
};

class RandomStrategy: public FindingStrategy {
public:
    RandomStrategy(){
        srand (getpid());
    }

    void findQuorums(vector<pair<int, vector<int> > > &quorumSlices, vector<vector<int> >& result) override {
        set<vector<int> > quorums;
        int numberOfTries = 1000;
        while(numberOfTries--){
            int vertex = rand()%N;
            vector<int> quorum;
            vector<bool> inQuorum(N,false);
            quorum.push_back(vertex);inQuorum[vertex]=true;

            queue<int> Q;Q.push(vertex);
            while(!Q.empty()){
                int actual=Q.front();Q.pop();
                int remaining=quorumSlices[actual].first;
                vector<int> moznosti;
                for(int quorumNeighbour: quorumSlices[actual].second){
                    if(inQuorum[quorumNeighbour])remaining--;
                    else moznosti.push_back(quorumNeighbour);
                }

                for(int j=0;j<remaining;j++){
                    int index = rand()%(moznosti.size()-j);
                    quorum.push_back(moznosti[index]);
                    inQuorum[moznosti[index]]=true;
                    Q.push(moznosti[index]);
                    swap(moznosti[index], moznosti[moznosti.size()-1-j]);
                }
            }

            quorums.insert(quorum);
        }

        for(const vector<int>& quorum: quorums) {
            result.push_back(quorum);
        }
    }
};

#endif //SAFETY_COEFFICIENT_FINDER_FINDINGSTRATEGY_H
