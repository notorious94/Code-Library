#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define MX 100005
#define MN 55
using namespace std;

int alpha[MX][MN];
int end_point[MX];
int node;

void insert_word(string w)
{
    int c = 0;
    for(int i=0;w[i];i++)
    {
        int id = (w[i]>'Z') ? (w[i]-'a'+26) : (w[i]-'A');
        if(alpha[c][id]==-1)    alpha[c][id] = ++node;
        c = alpha[c][id];
    }
    end_point[c]++;
}

// Returns the occurrence of a string
int query(string w)
{
    int c = 0;
    for(int i=0;w[i];i++)
    {
        int id = (w[i]>'Z') ? (w[i]-'a'+26) : (w[i]-'A');
        if(alpha[c][id]==-1)  return 0;
        c = alpha[c][id];
    }
    return end_point[c];
}

int main()
{

    return 0;
}
