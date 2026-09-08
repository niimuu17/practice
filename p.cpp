#include<bits/stdc++.h>
using namespace std;
const int inf=1e5;
const int v= 33;

void f(vector<vector<int>>&p)
{
    for(int k=0; k<v; k++)
    {
        for(int i=0; i<v; i++)
        {
            for(int j=0; j<v; j++)
            {
                p[i][j]=min(p[i][j], p[i][k]+p[k][j]);
            }
        }
    }
}

void djk(int s, vector<vector<pair<int, int>>>&g, vector<int>&d)
{
    d[s]=0;
}

int main()
{
    srand(time(0));
    vector<vector<int>>p(v, vector<int>(v, inf));
    vector<vector<pair<int, int>>>g(inf);

    for(int i=0; i<v; i++)
    {
        int w;
        for(int j=0; j<v; j++)
        {
           if(i==j)
           {
              w=0;
           }else
           {
              w= rand()%100 +1;
           }
           p[i][j]=w;
           g[i].push_back({w, j});
        }
    }
    f(p);
    freopen("output.txt", "w", stdout);
    for(int i=0; i<v; i++)
    {
        for(int j=0; j<v; j++)
        {
            if(p[i][j]==inf)
            {
                cout<<"inf"<<" ";
            }else{
            cout<<p[i][j]<<" ";
            }
        }
        cout<<endl;
    }

    int u=10, vv=20;

    vector<int>d1(v, inf);
    djk(u, g, d1);

    vector<int>d2(v, inf);
    djk(vv, g, d2);

    vector<vector<int>>sto(v, vector<int>(v, inf));

    freopen("input.txt", "r", stdin);
}
