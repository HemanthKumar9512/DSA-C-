/*
You are given an integer array height of length n. There are n vertical lines drawn such that 
the two endpoints of the ith line are (i, 0) and (i, height[i]). Find two lines that together 
with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.
Notice that you may not slant the container. 

Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
Example 2:
Input: height = [1,1]
Output: 1
*/
#include<iostream>
using namespace std;
// Brute Force:   Time Complexity: O(n^2)
int bruteForce(int* heights, int n){          
    int maxWater=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int width=j-i;
            int height=min(heights[i], heights[j]);
            int area= height*width;
            maxWater=max(maxWater,area);
        }
    }
    return maxWater;
}
// Two Pointer Approach:   Time Complexity: O(n)
int TwoPointer(int* heights, int n){
    int lp=0, rp=n-1, maxWater=0;    // lp=left_pointer, rp=right_pointer
    while(lp<rp){
        int width=rp-lp;
        int height=min(heights[lp],heights[rp]);
        int area=width*height;
        maxWater=max(maxWater,area);
        heights[lp]<heights[rp]? lp++: rp--;
    }
    return maxWater;
}
int main(){
    int heights[]={1,8,6,2,5,4,8,3,7};
    int n=sizeof(heights)/sizeof(heights[0]);
    cout<<"Brute Force: "<<bruteForce(heights, n)<<endl;
    cout<<"TwoPOinter: "<<TwoPointer(heights, n)<<endl;
    return 0;
}