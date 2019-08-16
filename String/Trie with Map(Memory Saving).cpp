#include<bits/stdc++.h>

using namespace std;

struct trie
{
    int end_mark = 0;
    unordered_map<char,trie* >next;
    trie()
    {
        end_mark = 0;
    }
}*root;

void insert_word(string w)
{
    trie* current = root;
    for(int i=0;w[i];i++)
    {
        if(current->next[w[i]]==NULL)
            current->next[w[i]]= new trie();
        current = current->next[w[i]];
    }
    ++current->end_mark;
}

int query(string w)
{
    trie* current = root;
    for(int i=0;w[i];i++)
    {
        if(current->next[w[i]]==NULL)    return 0;
        current = current->next[w[i]];
    }
    return current->end_mark;
}

void del(trie *root)
{
    for(auto it : root->next)
        if(it.second!=NULL)
            del(it.second);
    delete(root);
}

int main()
{
    /// Suck my dick! HACKER -_-
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);


    return 0;
}
