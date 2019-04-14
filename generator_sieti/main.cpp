#include <unistd.h>
#include "NetworkCreator.h"

using namespace std;

// N - number of nodes
// Q - number of nodes 1 particular node trust
// K - number of nodes that can persuade 1 particular node
int N,Q,K;

void validate_input(int argc, char **argv){
    if(argc!=2){
        cout <<"Specify type of network!\n";
        exit(0);
    }
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    srand (getpid());

    validate_input(argc, argv);

    string networkType = string(argv[1]);

    NetworkCreator networkCreator;
    networkCreator.setStrategy(networkType);

    cin>>N>>Q>>K;

    networkCreator.create(N,Q,K);

    return 0;
}