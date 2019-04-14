#include <bits/stdc++.h>

using namespace std;

//pocet kvor
int N;

vector<int> prienik(vector<int> &v1, vector<int> &v2){
    vector<int> v3;

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    set_intersection(v1.begin(),v1.end(), v2.begin(),v2.end(), back_inserter(v3));
    return v3;
}

int main() {
    cin>>N;

    vector<vector<int> > kvora(N), prieniky;
    for(int i=0;i<N;i++){
        int velkost;cin>>velkost;
        kvora[i].resize(velkost);
        for (int j=0;j<velkost;j++)cin>>kvora[i][j];
    }

    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            prieniky.push_back(prienik(kvora[i], kvora[j]));
        }
    }

    //specialny pripad ak existuje iba jedine kvorum
    if(N==1){
        prieniky.push_back(kvora[0]);
    }

    sort(prieniky.begin(),prieniky.end(), [](const vector<int> &a, const vector<int> &b){return a.size() < b.size();});

    if(!prieniky.empty())cout <<prieniky[0].size()<<endl<<endl;
    else cout <<"0\n";

    for(vector<int>& prienik : prieniky){
        if(prienik.size()>prieniky[0].size())break;
        string separator = "";
        for(int prvok_prieniku : prienik){
            cout <<separator<<prvok_prieniku;
            separator=" ";
        }
        cout <<endl;
    }
    return 0;
}
