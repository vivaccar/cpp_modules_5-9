#include "../includes/Whatever.hpp"

int main(void)
{
    std::cout << RED << "Tests for SWAP\n" << std::endl;
    {
        std::cout << GREEN << "\nINT SWAP" << RESET << std::endl;
        int iX = 10, iY = 42;
        std::cout << "iX Value --> " << iX << std::endl;
        std::cout << "iY Value --> " << iY << std::endl;
        ::swap(iX, iY);
        std::cout << "\nAfter SWAP\n" << std::endl;
        std::cout << "iX Value --> " << iX << std::endl;
        std::cout << "iY Value --> " << iY << std::endl;

        std::cout << GREEN << "\n\nFLOAT SWAP" << RESET << std::endl;
        float fX = 1.12, fY = 0.20;
        std::cout << "fX Value --> " << fX << std::endl;
        std::cout << "fY Value --> " << fY << std::endl;
        ::swap(fX, fY);
        std::cout << "\nAfter SWAP\n" << std::endl;
        std::cout << "fX Value --> " << fX << std::endl;
        std::cout << "fY Value --> " << fY << std::endl;

        std::cout << GREEN << "\n\nSTRING SWAP" << RESET << std::endl;
        std::string sX = "Vinicius", sY = "Vivaccar";
        std::cout << "sX Value --> " << sX << std::endl;
        std::cout << "sY Value --> " << sY << std::endl;
        ::swap(sX, sY);
        std::cout << "\nAfter SWAP\n" << std::endl;
        std::cout << "sX Value --> " << sX << std::endl;
        std::cout << "sY Value --> " << sY << std::endl;
    }

    /*{
        std::cout << RED << "Tests for MIN" << std::endl;
        
        int iX = -10, iY = -2;
        float fX = 2.23f, fY = 1.22f;
        std::string s1 = "Hello", s2 = "Bye";
        
        std::cout << GREEN << "\nINT MIN" << RESET << std::endl;
        std::cout << "min( iX, iY ) = " << ::min( iX, iY ) << std::endl;
        std::cout << GREEN << "\nFLOAT MIN" << RESET << std::endl;
        std::cout << "min( fX, fY ) = " << ::min( fX, fY ) << std::endl;

        std::cout << RED << "\nTests for MAX" << std::endl;
        std::cout << GREEN << "\nINT MAX" << RESET << std::endl;
        std::cout << "max( iX, iY ) = " << ::max( iX, iY ) << std::endl;
        std::cout << GREEN << "\nSTRING MAX" << RESET << std::endl;
        std::cout << "max( s1, s2 ) = " << ::max( s1, s2 ) << std::endl;
    }   */
}