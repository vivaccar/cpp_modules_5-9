#include "../includes/iter.hpp"

int main(void)
{
    int array[3] = {1, 2, 3};
    char c_array[3] = {'a', 'b', 'c'};
    float f_array[3] = {2.1f, 2.120f, 4.42f};
//  std::string s_array[3] = {"ola", "bom", "dia"};

    std::cout << "INT ARRAY" << std::endl;
    ::iter(array, 3, &iterate);

    std::cout << "\nCHAR ARRAY" << std::endl;
    ::iter(c_array, 3, &iterate);

    std::cout << "\nFLOAT ARRAY" << std::endl;
    ::iter(f_array, 3, &iterate);

//   std::cout << "STRING ARRAY" << std::endl;
// ::iter(s_array, 3, &iterate);
}