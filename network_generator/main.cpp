#include <unistd.h>
#include "NetworkCreator.h"

using namespace std;

// N - number of nodes
// Q - number of nodes 1 particular node trust
// K - number of nodes that can persuade 1 particular node
int N,Q,K;

void validate_params(int argc, char **argv){
    if(argc < 2){
        cout <<"Specify type of network!\n";
        exit(0);
    }
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    srand (getpid());

    validate_params(argc, argv);

    string networkType = string(argv[1]);

    NetworkCreator networkCreator;
    networkCreator.setStrategy(networkType);

    cin>>N>>Q>>K;

    vector<vector<int> > quorumSlices;

    networkCreator.create(N,Q,quorumSlices);

    // Print generated network to output
    cout << N << endl;

    for(int i=0;i<N;i++) {
        cout << Q << " " << K;
        for(int j=0;j<Q;j++)cout << " " << quorumSlices[i][j];
        cout << endl;
    }

    return 0;
}
