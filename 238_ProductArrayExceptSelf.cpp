#include<iostream>
#include<vector>
using namespace std;

// Brute Force: Time Complexity O(n^2)
vector<int> BruteForce(int* arr, int n) {
    vector<int> ans(n);
    for(int i = 0; i < n; i++) {
        int product = 1;
        for(int j = 0; j < n; j++) { // Fixed: j < n
            if(i != j) {
                product *= arr[j];
            }
        }
        ans[i] = product; // Store product for each index
    }
    return ans;
}

// Optimal Solution: Time Complexity O(n), Space Complexity O(1)
vector<int> Optimal(int* arr, int n) {
    vector<int> ans(n, 1);
    
    // Step 1: Prefix Products
    int prefix = 1;
    for(int i = 0; i < n; i++) {
        ans[i] = prefix;
        prefix *= arr[i];
    }
    
    // Step 2: Suffix Products
    int suffix = 1;
    for(int i = n - 1; i >= 0; i--) {
        ans[i] *= suffix;
        suffix *= arr[i];
    }
    
    return ans;
}

// Helper function to print vectors
void printVector(vector<int> v) {
    for(int x : v) cout << x << " ";
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Brute Force Output: ";
    vector<int> res1 = BruteForce(arr, n);
    printVector(res1);

    cout << "Optimal Output: ";
    vector<int> res2 = Optimal(arr, n);
    printVector(res2);
    return 0;
}