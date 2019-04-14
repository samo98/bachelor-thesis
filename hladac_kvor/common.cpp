#include <iostream>
#include <vector>


using namespace std;

bool isInSet(int set, int position) {
    return ((1 << position) & set) != 0;
}

bool hasQuorumSlice(pair<int, vector<int> > &X, int set) {
    int isInQuorum = 0;

    for (int position : X.second) {
        if (isInSet(set, position))isInQuorum++;
    }

    return X.first <= isInQuorum;
}

void printQuorum(int N, int set) {
    vector<int> quorum;

    for (int j = 0; j < N; j++) {
        if (isInSet(set, j)) {
            quorum.push_back(j);
        }
    }

    cout <<quorum.size()<<endl;

    cout <<quorum[0];

    for(int i=1;i<quorum.size();i++)cout <<" "<<quorum[i];

    cout << endl;
}
