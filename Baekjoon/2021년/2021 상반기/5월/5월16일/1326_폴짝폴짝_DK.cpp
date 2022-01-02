#include <iostream>

using namespace std;
typedef long long ll;
int arr[10001];
int dp[10001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    int a, b;
    int count = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    cin >> a >> b;
    for (int i = a - 1; i < N; i = i + arr[a - 1])
        dp[i] = 1;
    for (int i = a - 1; i >= 0; i = i - arr[a - 1])
        dp[i] = 1;
    /*for (int i = 0; i < N; i++)
    cout << dp[i] << "\n";*/
    for (int i = a - 1; i < N; i++)
    {
        if (dp[i] != 0)
        {
            for (int j = i; j < N; j = j + arr[i])
                if (dp[j] == 0 && dp[j] > dp[i] + 1)
                    dp[j] = dp[i] + 1;
            for (int j = i; j >= 0; j = j - arr[i])
                if (dp[j] == 0 && dp[j] > dp[i] + 1)
                    dp[j] = dp[i] + 1;
        }
    }
    /*for(int i=0;i<N;i++)
    cout << dp[i]<<"\n";*/
    if (dp[b - 1] == 0)
        cout << -1;
    else
        cout << dp[b - 1];
}