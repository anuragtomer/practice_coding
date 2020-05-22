#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> vec(n);
    int i = 0;
    while (n)
    {
        cin >> vec[i++];
        n--;
    }
    i = 0;
    int j = vec.size() - 1;
    int s = 0, d = 0;
    bool sc = true;
    while (i <= j)
    {
        if (vec[i] > vec[j])
        {
            if (sc)
            {
                s += vec[i++];
                sc = false;
            }
            else
            {
                d += vec[i++];
                sc = true;
            }
        }
        else
        {
            if (sc)
            {
                s += vec[j--];
                sc = false;
            }
            else
            {
                d += vec[j--];
                sc = true;
            }
        }
    }
    cout << s << " " << d;
    return 0;
}
