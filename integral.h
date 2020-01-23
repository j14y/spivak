#include <iostream>
#include "function.h"
#include "riemann.h"

// apache open license
// author: jordy chetty


namespace spivak
{
    class indefinite_integral
    {
        private:
            spivak::function f;
        public:
            indefinite_integral() {}
            float eval () {}
    };

    class definite_integral
    {
        private:
            float a, b;
            spivak::function f;
        public:
            definite_integral() {}
            float eval() {}
    };
}