#include <iostream>

using namespace std;

void print_array(int a[], int n)
{
    cout << "array: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int search(int a[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (x == a[i])
        {
            return i;
        }
    }
    return - 1;
}

void insert(int arr[], int size, int num, int pos)
{
    //elements at end will get discarded
    if (pos >= size || pos < 0) return;
    //shift the elements to the right
    for (int i = size - 1; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[pos] = num;
}

void delete_num(int arr[], int size, int num)
{
    int index = search(arr, size, num);
    if (index < 0) return;
    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr[size - 1] = -1; //filling last element with -1
}

int main()
{
    int arr[] = { 1,8,3,4,2,9,6,5,7 };
    int siz = sizeof(arr) / sizeof(arr[0]);
    print_array(arr, siz);
    cout << "5 is at " << search(arr, siz, 5) << endl;
    insert(arr, siz, 10, 8);
    print_array(arr, siz);
    delete_num(arr, siz, 6);
    print_array(arr, siz);
    insert(arr, siz, 12, 8);
    print_array(arr, siz);
}
