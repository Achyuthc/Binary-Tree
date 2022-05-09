
/*Given an input stream of N integers. The task is to insert these numbers into a new stream and find the median of the stream formed by each insertion of X to 
the new stream.*/

class Solution
{
    public:
    //Function to insert heap.
    priority_queue<int> maxhp;
    priority_queue<int,vector<int>,greater<int>>minhp;
    int n=0;
    void insertHeap(int &x)
    {
        maxhp.push(x);
        minhp.push(maxhp.top());
        maxhp.pop();
        n++;
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        while(maxhp.size()<minhp.size())
        {
            maxhp.push(minhp.top());
            minhp.pop();
        }
       
    }
    
    //Function to return Median.
    double getMedian()
    {
        
       if(n%2==0)
       {
           return ((double)maxhp.top()+(double)minhp.top())/(double)2;
       }
       else
       {
           return (double)maxhp.top();
       }
    }
};
