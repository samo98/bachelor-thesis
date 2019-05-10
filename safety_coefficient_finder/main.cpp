#include <iostream>
#include "QuorumFinder.h"
#include "IntersectionFinder.h"

using namespace std;

//number of nodes
int N;
vector<pair<int,vector<int> > > quorumSlices;
bool printDebug = false;

bool validate_params(int argc, char **argv){
    if(argc < 2){
        cerr <<"Specify type of search!\n";
        exit(0);
    }
}

void load_network(){
    cin>>N;
    quorumSlices.resize(N);

    for(int i=0;i<N;i++){
        int trustedNodesNumber;
        cin>>trustedNodesNumber>>quorumSlices[i].first;
        for(int j=0;j<trustedNodesNumber;j++){
            int node;cin>>node;

            quorumSlices[i].second.push_back(node);
        }
    }
}

int main(int argc, char **argv) {
    validate_params(argc, argv);

    string finderType = string(argv[1]);

    QuorumFinder quorumFinder;
    quorumFinder.setStrategy(finderType);

    load_network();

    vector<vector<int> > quorums;

    quorumFinder.find(quorumSlices, quorums);

    if(printDebug){
        cout <<quorums.size()<<endl;

        for(const vector<int>& quorum:quorums)printQuorum(quorum);
    }

    cout <<findSmallestIntersection(quorums)<<endl;
    return 0;
}
