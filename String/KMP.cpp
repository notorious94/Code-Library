#include<bits/stdc++.h>
using namespace std;

void calculate_LPS(char pattern[],int LPS[]);

bool KMP(char text[], char pattern[])
{
    int size = strlen(pattern);
    int LPS[size];

    calculate_LPS(pattern, LPS);

    for(int i=0,j=0;text[i]!=0;)
    {
        if(text[i]==pattern[j])
        {
            i++;
            j++;
        }

        if(j==size)
            return true;

        else if(text[i]!=0&&text[i]!=pattern[j])
        {
            if(j!=0)
                j = LPS[j-1];
            else
                i++;
        }
    }
    return false;
}

void calculate_LPS(char pattern[],int LPS[])
{
    int len = 0, i = 1;

    LPS[0] = 0;

    while(pattern[i]!=0)
    {
        if(pattern[i]==pattern[len])
        {
            len++;
            LPS[i] = len;
            i++;
        }
        else if(len!=0)
            len = LPS[len -1];
        else
        {
            LPS[i]=0;
            i++;
        }
    }
}

int main()
{
    char text[MAX],pattern[MAX];

    int test;

    scanf("%d",&test);

    while(test--)
    {
        scanf("%s",&text);
        scanf("%s",&pattern);

        if(KMP(text,pattern))
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}
