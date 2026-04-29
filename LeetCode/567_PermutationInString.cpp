#include<iostream>
using namespace std;
/*
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.
Example 1:
Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:
Input: s1 = "ab", s2 = "eidboaoo"
Output: false
*/

bool isFreqSame(int freq1[], int freq2[]){   // O(1)~26
    for(int i=0;i<26;i++){
        if(freq1[i]!=freq2[i]){
            return false;
        }
    }
    return true;
}
bool checkInclusion(string s1, string s2){   //O(n^2)
    int freq[26]={0};
    for(int i=0;i<s1.length();i++){
        freq[s1[i]-'a']++;
    }
    int windSize=s1.length();
    for(int i=0;i<s2.length();i++){
        int windIdx=0, idx=i;
        int windfreq[26]={0};
        while(windIdx<windSize && idx<s2.length()){
            windfreq[s2[idx]-'a']++;
            windIdx++;
            idx++;
        }
        if(isFreqSame(freq,windfreq)){
            return true;   // Found
        }
    }
    return false;   // Not Found
}

int main(){
    string s1="ab";
    string s2="bcbacbc";
    cout<<checkInclusion(s1,s2);
}