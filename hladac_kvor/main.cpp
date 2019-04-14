#include <iostream>
#include "QuorumFinder.h"
#include "common.h"

using namespace std;

//number of nodes
int N;

bool validate_input(int argc, char **argv){
    if(argc!=2){
        cout <<"Specify type of search!\n";
        exit(0);
    }
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);

    validate_input(argc, argv);

    string finderType = string(argv[1]);

    QuorumFinder quorumFinder;
    quorumFinder.setStrategy(finderType);

    cin>>N;
    vector<pair<int,vector<int> > > quorumSlices(N);
    vector<int> quorums;

    for(int i=0;i<N;i++){
        int trustedNodesNumber;
        cin>>trustedNodesNumber>>quorumSlices[i].first;
        for(int j=0;j<trustedNodesNumber;j++){
            int node;cin>>node;

            quorumSlices[i].second.push_back(node);
        }
    }

    quorumFinder.find(N, quorumSlices, quorums);

    cout << quorums.size() <<endl;

    for(int quorum: quorums)printQuorum(N, quorum);

    return 0;
}
