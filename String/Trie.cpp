#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define MOD 100000007
#define INF INT_MAX
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)
#define pii pair<int, int>
#define pdd pair<double, double>
#define mem(name, value) memset(name, value, sizeof(name))
#define all(name) name.begin(),name.end()

typedef long long ll;
typedef unsigned long long ull;

struct node
{
    bool endmark;
    int prefix;
    node* next[27];
    node()
    {
        for(int i=0;i<27;i++)
            next[i] = NULL;
        prefix = 0;
        endmark = false;
    }
} *root;

void insert_word(char s[])
{
    node* curr = root;
    for(int i=0;s[i];i++)
    {
        int id = s[i]-'a';
        if(curr->next[id]==NULL)
            curr->next[id] = new node();
        curr = curr->next[id];
        curr->prefix++; // Important
    }
}

int prefixes(char s[])
{
    node* curr = root;
    int last;
    for(int i=0;s[i];i++)
    {
        int id = s[i]-'a';
        if(curr->next[id]==NULL)    return 0;
        curr = curr->next[id];
    }
    return curr->prefix; // Important
}

void del(node *curr)
{
    for(int i=0;i<27;i++)
        if(curr->next[i])
            del(curr->next[i]);
    delete (curr);
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    root = new node();
    scanf("%d",&n);
    char q[500],s[500];
    while(n--)
    {
        scanf("%s%s",q,s);
        if(q[0]=='a')
            insert_word(s);
        else
            printf("%d\n",prefixes(s));
    }
    del(root);
    return 0;
}
