#include "../includes/easyfind.hpp"

int main(void) 
{
    int arr[] = {10, 20, 5, 23 ,42 , 15};
    int n = sizeof(arr)/sizeof(arr[0]);
    std::vector<int> vect(arr, arr + n);

    for (int i=0; i<n; i++)
        std::cout << vect[i] << " ";
}