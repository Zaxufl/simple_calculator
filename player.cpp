// #include <algorithm>
// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;

// int bs(const vector<int> arr, const int target)
// {
//     int low{}, high{static_cast<int>(arr.size() - 1)};

//     while (low <= high) {
//         if (int mid{low + (high - low) / 2}; arr[mid] == target) {
//             return arr[mid];
//         } else if (arr[mid] > target) {
//             high = mid - 1;
//         } else {
//             low = mid + 1;
//         }
//     }
//     return -1;
// }

// int dc(int a, int b)
// {
//     if (b == 0) {
//         return a;
//     } else {
//         return dc(b, a % b);
//     }
// }

// void merge(vector<int> &arr, int left, int mid, int right)
// {
//     int n1{mid - left + 1};
//     int n2{right - mid};

//     vector<int> L(n1), R(n2);

//     // kopiowanie danych do tablic pomocniczych
//     for (int i{}; i < n1; ++i)
//         L[i] = arr[left + i];
//     for (int j{}; j < n2; ++j)
//         R[j] = arr[mid + 1 + j];

//     int i{}, j{}, k{left};

//     // scalanie
//     while (i < n1 && j < n2) {
//         if (L[i] <= R[j]) {
//             arr[k] = L[i];
//             ++i;
//         } else {
//             arr[k] = R[j];
//             ++j;
//         }
//         ++k;
//     }

//     // reszta elementów
//     while (i < n1)
//         arr[++k] = L[++i];
//     while (j < n2)
//         arr[++k] = R[++j];
// }

// void merge_sort(vector<int> &arr, int left, int right)
// {
//     if (left >= right)
//         return; // baza rekurencji
//     int mid{left + (right - left) / 2};

//     merge_sort(arr, left, mid);      // sortuj lewą połowę
//     merge_sort(arr, mid + 1, right); // sortuj prawą połowę
//     merge(arr, left, mid, right);    // scal
// }

// int main()
// {
//     vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

//     merge_sort(arr, 0, arr.size() - 1);

//     return 0;
// }
