//
// Created by samuel on 11.3.2019.
//

#ifndef NEW_HLADAC_KVOR_COMMON_H
#define NEW_HLADAC_KVOR_COMMON_H

using namespace std;

bool isInSet(int set, int position);

bool hasQuorumSlice(pair<int, vector<int> > &X, int mnos);

void printQuorum(int N, int set);

#endif //NEW_HLADAC_KVOR_COMMON_H
