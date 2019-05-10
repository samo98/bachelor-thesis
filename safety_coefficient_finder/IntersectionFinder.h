#ifndef SAFETY_COEFFICIENT_FINDER_INTERSECTIONFINDER_H
#define SAFETY_COEFFICIENT_FINDER_INTERSECTIONFINDER_H

#include <algorithm>

using namespace std;

vector<int> prienik(vector<int> &v1, vector<int> &v2){
    vector<int> v3;

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    set_intersection(v1.begin(),v1.end(), v2.begin(),v2.end(), back_inserter(v3));
    return v3;
}

int findSmallestIntersection(vector<vector<int> > &quorums) {
    vector<vector<int> > intersections;

    for(int i=0;i<quorums.size();i++){
        for(int j=i+1;j<quorums.size();j++){
            intersections.push_back(prienik(quorums[i], quorums[j]));
        }
    }

    //handle special case
    if(quorums.size()==1) return quorums[0].size();

    sort(
            intersections.begin(),
            intersections.end(),
            [](const vector<int> &a, const vector<int> &b){return a.size() < b.size();}
    );

    return intersections[0].size();
}

#endif //SAFETY_COEFFICIENT_FINDER_INTERSECTIONFINDER_H
