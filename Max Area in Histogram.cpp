int hist[100];
int grid[100][100];

int maxAreaInHistogram(int len)
{
    stack<int>s;
    s.push(0);
    int i,top,area,maxArea=-1;
    for(i=1; i<=len; i++)
    {
        if(i==len)
        {
            while(s.size())
            {
                top = s.top();
                s.pop();
                if(s.size()==0)
                    area = hist[top]*i;
                else
                {
                    int stackTop = s.top();
                    area = hist[top]*(i-1-stackTop);
                }
                maxArea = max(area,maxArea);
            }
        }
        else
        {
            if(hist[i]>=hist[s.top()])
                s.push(i);
            else
            {
                while(s.size())
                {
                    if(hist[s.top()]<=hist[i])
                    {
                        s.push(i);
                        break;
                    }
                    top = s.top();
                    s.pop();
                    if(s.size()==0)
                        area = hist[top]*i;
                    else
                    {
                        int stackTop = s.top();
                        area = hist[top]*(i-1-stackTop);
                    }
                    maxArea = max(area,maxArea);
                }
                if(s.size()==0) s.push(i);
            }
        }
    }
    return maxArea;
}
