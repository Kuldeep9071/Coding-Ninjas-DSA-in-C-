int countWaysToMakeChange(int arr[], int n, int value, int **temp){
    if (n == 0) return 0;
    if (value == 0) return 1;
    if (value < 0) return 0;
    if (temp[n][value] > 0) return temp[n][value];

    int ans1 = countWaysToMakeChange(arr + 1, n - 1, value, temp);
    int ans2 = countWaysToMakeChange(arr, n, value - arr[0], temp);
    temp[n][value] = ans1 + ans2;
    return ans1 + ans2;
}
int countWaysToMakeChange(int denominations[], int numDenominations, int value){
    int **output = new int *[11];
    for (int i = 0; i < 11; i++){
        output[i] = new int[1001];
        for (int j = 0; j < 1001; j++)
            output[i][j] = 0;
    }
    int ans = countWaysToMakeChange(denominations, numDenominations, value, output);
    for (int i = 0; i < 11; i++){
        delete[] output[i];
    }
    delete[] output;
    return ans;
}

/*
Problem statement
For the given infinite supply of coins of each of denominations, D = {D0, D1, D2, D3, ...... Dn-1}.
 You need to figure out the total number of ways W, in which you can make the change for Value
  V using coins of denominations D.

Return 0 if the change isn't possible.

Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
3
1 2 3
4
Sample Output 1 :
4
Explanation to Sample Input 1 :
Number of ways are - 4 total i.e. (1,1,1,1), (1,1, 2), (1, 3) and (2, 2).
Sample Input 2 :
6
1 2 3 4 5 6
250
Sample Output 2 :
13868903
*/