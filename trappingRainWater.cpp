#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;
int trap(vector<int>& height) {
        int n=height.size();
        vector<int>leftmax(n);
        vector<int>rightmax(n);
        leftmax[0]=0;
        for(int i=1;i<n;i++)
        {
            leftmax[i]=max(leftmax[i-1],height[i-1]);
        }
        rightmax[n-1]=0;
        for(int i=n-2;i>=0;i--)
        {
            rightmax[i]=max(rightmax[i+1],height[i+1]);
        }
        int water=0;
        for(int i=0;i<n;i++)
        {
            int miniheight=min(leftmax[i],rightmax[i]);
            if(miniheight-height[i]>=0)
            water+=miniheight-height[i];
        }
        return water;
    }
int main()
{
    int n;
    cin>>n;
    vector<int>height(n);
    for(int i=0;i<n;i++)
    {
        cin>>height[i];
    }
    cout<<trap(height)<<endl;
}