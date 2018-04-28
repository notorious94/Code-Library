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
    bool end_mark;
    node* next[10];
    node()
    {
        end_mark = false;
        for(int i=0;i<10;i++)
            next[i] = NULL;
    }
} *root;

bool insert_word(char p[])
{
    node * c = root;
    for(int i=0;p[i];i++)
    {
        int id = p[i] - 48;
        if(c->next[id]==NULL)
            c->next[id] = new node();
        c = c->next[id];
        if(c->end_mark) return false;
    }
    for(int i=0;i<10;i++)
        if(c->next[i])  return false;
    c->end_mark = true;
    return true;
}

void del(node *curr)
{
    for(int i=0;i<10;i++)
        if(curr->next[i])
            del(curr->next[i]);
    delete(curr);
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t,n;
    char phone[50];

    scanf("%d",&t);

    for(int k=1;k<=t;k++)
    {
        scanf("%d",&n);
        root = new node();
        bool consistant = true;
        while(n--)
        {
            scanf("%s",phone);
            if(consistant)
                consistant = insert_word(phone);
        }
        //printf("Case %d: ",k);
        (consistant) ? puts("YES") : puts("NO");
        del(root);
    }
    return 0;
}
