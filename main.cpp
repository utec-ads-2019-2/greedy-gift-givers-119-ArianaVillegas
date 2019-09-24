#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    size_t n;
    size_t flag=0;
    vector<string> names;
    map<string,int> friends;
    string name;
    int m,money;
    while(cin>>n){
        for(size_t i=0; i<n; ++i){
            cin >> name;
            friends[name]=0;
            names.push_back(name);
        }
        for(size_t j=0; j<n; ++j){
            cin>>name;
            cin>>money>>m;
            if(!m) continue;
            int eachmoney = money / m;
            friends[name] -= (m * eachmoney);
            for (size_t i = 0; i < m; ++i) {
                cin >> name;
                friends[name] += eachmoney;
            }
        }
        if(flag++) cout << '\n';
        for(size_t i=0;i<n;++i) cout << names[i] << ' ' << friends[names[i]] << '\n';
        friends.clear();
        names.clear();
    }
    return 0;
}