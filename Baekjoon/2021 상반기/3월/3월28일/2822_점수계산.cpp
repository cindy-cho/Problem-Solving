#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}
int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int val, i;
    int sum = 0;
    vector<int> s(5);
    vector<pair<int, int> > vv(8);
    for (i = 1; i <= 8; i++)
    {
        cin >> val;
        vv[i - 1].first = i;
        vv[i - 1].second = val;
    }
    sort(vv.begin(), vv.end(), cmp);
    for (i = 1; i <= 5; i++)
    {
        sum += vv[i - 1].second;
    }
    cout << sum << endl;
    for (i = 1; i <= 5; i++)
    {
        s[i - 1] = vv[i - 1].first;
    }
    sort(s.begin(), s.end());
    for (i = 0; i < 5; i++)
        cout << s[i] << " ";
    cout << endl;
    return 0;
}