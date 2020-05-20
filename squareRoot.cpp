#include <bits/stdc++.h>

using namespace std;

double squareRootHelper(double *arr, int N)
{
    double ans;
    int s = 0, e = 9;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (arr[mid] * arr[mid] == N)
            return arr[mid];
        else if (arr[mid] * arr[mid] < N)
        {
            s = mid + 1;
            ans = arr[mid];
        }
        else
        {
            e = mid - 1;
        }
    }

    return ans;
}

double squareRoot(int N, int P)
{
    int s = 0, e = N;
    double ans, mid;
    while (s <= e)
    {
        mid = (s + e) / 2;
        if (mid * mid == N)
            return mid;
        else if (mid * mid < N)
        {
            s = mid + 1;
            ans = mid;
        }
        else
            e = mid - 1;
    }

    // fractional part
    double result = ans * 1.0;
    double arr[10];

    for (int i = 1; i <= P; i++)
    {
        for (int j = 0; j < 10; j++)
            arr[j] = double(ans) + (double(j) / double(pow(10.0, i)));
        cout << "\ndisplaying the array\n";
        for (int j = 0; j < 10; j++)
            cout << setprecision(P + 1) << arr[j] << " ";
        int capacity = sizeof(arr) / sizeof(int);
        ans = squareRootHelper(arr, N);
        cout << "\nvalue of ans is\t" << ans;
    }

    return ans;
}

int main()
{
    int N, P;
    cin >> N >> P;

    double result = 0;
    double p = squareRoot(N, P);
    cout << "\nsquare root of " << N << " is  " << setprecision(P + 1) << p;

    return EXIT_SUCCESS;
}