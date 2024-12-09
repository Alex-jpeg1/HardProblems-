///This is a solution to the problem https://vjudge.net/problem/CodeForces-12D
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
///#include<fstream>

using namespace std;

/*ifstream cin("date.in");
ofstream cout("date.out");
ofstream fout("debug.out");
*/
struct Lady {
    int beauty, intellect, richness;
};

bool compare(const Lady& a, const Lady& b) {
    if (a.beauty != b.beauty) return a.beauty > b.beauty;
    if (a.intellect != b.intellect) return a.intellect > b.intellect;
    return a.richness > b.richness;
}


 void update(int index, int value ,vector<int>&tree) {
        while (index > 0) {
            tree[index] = max(tree[index], value);
            index -= index & -index;
        }
    }
    vector<int>tree;

    int query(int index) {
        int max_val = -1;
        int k=1;
        while (index < tree.size() && k<tree.size()) {
            max_val = max(max_val, tree[index]);
            index+=index&-index;
        }
        return max_val;
    }
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;

    vector<Lady> ladies(N);
    vector<int> all_intellects;
    for (int i = 0; i < N; i++) 
        cin >> ladies[i].beauty;
    for(int i=0;i<N;i++)
        {
            cin >> ladies[i].intellect;
            all_intellects.push_back(ladies[i].intellect);
        }
    for(int i=0;i<N;i++)
        cin >> ladies[i].richness;

    sort(all_intellects.begin(), all_intellects.end());

    all_intellects.erase(unique(all_intellects.begin(), all_intellects.end()), all_intellects.end());

    auto compress = [](int value, const vector<int>& compressed) {

        return lower_bound(compressed.begin(), compressed.end(), value) - compressed.begin() + 1;

    };
    int maxim=0;
    for (auto& lady : ladies) {
        lady.intellect = compress(lady.intellect, all_intellects);
        maxim=max(maxim,lady.intellect);
    }
    maxim++;
    sort(ladies.begin(), ladies.end(), compare);

    int probable_self_murderers = 0;

    tree.resize(2*N);
    int last=ladies[0].beauty;
    int curr=0;
    
    vector<vector<pair<int,pair<int,bool>>>>toate;
    
    toate.resize(1);

    for (const auto& lady : ladies) 
    {
        if(lady.beauty==last)
        {
            toate[curr].push_back( { lady.intellect , { lady.richness , false } } );
        }
        else 
        {
            last=lady.beauty;
            toate.resize(toate.size()+1);
            toate[++curr].push_back( { lady.intellect , { lady.richness , false } } );
        }
    }
    for(int i=0;i<=curr;i++)
    {
        for(int j=0;j<toate[i].size();j++)
        {
            if(query(toate[i][j].first+1)>toate[i][j].second.first)
            {
                probable_self_murderers++;
                toate[i][j].second.second=true;
            }
        }
        for(int j=0;j<toate[i].size();j++)
        {
            if(toate[i][j].second.second==false)
            {
                update(toate[i][j].first,toate[i][j].second.first,tree);
            }
        }
    }
    cout << probable_self_murderers;

    return 0;
}
