#include <iostream>

using namespace std;

void merge(int *a, int s, int mid, int e, int &count)
{
    int rangeOne = mid - s + 1;
    int rangeTwo = e - mid;

    int *arrayOne = new int[rangeOne];
    int *arrayTwo = new int[rangeTwo];

    for (int i = 0; i < rangeOne; i++)
        arrayOne[i] = a[s + i];

    for (int i = 0; i < rangeTwo; i++)
        arrayTwo[i] = a[mid + 1 + i];

    int i = 0, j = 0, k = s;
    while (i < rangeOne && j < rangeTwo)
    {
        if (arrayOne[i] <= arrayTwo[k])
            a[k++] = arrayOne[i++];

        else if (arrayTwo[j] < arrayOne[i])
        {
            a[k++] = arrayTwo[j++];
            count += mid - i + 1;
        }
    }

    if (j == rangeTwo)
    {
        while (i < rangeOne)
            a[k++] = arrayOne[i++];
    }

    else if (i == rangeOne)
    {
        while (j < rangeTwo)
            a[k++] = arrayTwo[j++];
    }
}

void mergeSort(int *a, int s, int e, int &count)
{
    if (s <= e)
    {
        int mid = (s + e) / 2;
        mergeSort(a, s, mid, count);
        mergeSort(a, mid + 1, e, count);

        merge(a, s, mid, e, count);
    }
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int count = 0;
    mergeSort(a, 0, n - 1, count);
    cout << count;
    return EXIT_SUCCESS;
}