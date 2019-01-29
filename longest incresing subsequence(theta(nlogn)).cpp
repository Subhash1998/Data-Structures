#include <bits/stdc++.h>

using namespace std;

// Complete the longestIncreasingSubsequence function below.

int longestIncreasingSubsequence(vector<int> arr) {

    if(arr.size()==0)return 0;

    int n,i,length=1;
    n = arr.size();
    
    vector<int> v(n,0);

    v[0] = arr[0];
    for(i=1;i<n;i++)
    {
        if(v[length-1]<arr[i])
            v[length++] = arr[i];
        else
        {
                auto it = find(v.begin(), v.begin() + length, arr[i]); 
                if (it != v.begin() + length) { 
                    continue; 
            }
            else{
                it = upper_bound(v.begin(), v.begin() + length, arr[i]); 
                *it = arr[i]; 
            }
        }
    }

    return length;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    int result = longestIncreasingSubsequence(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
