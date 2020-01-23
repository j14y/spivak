#pragma once

#include <string>
#include "lib/fparser/fparser.cc"
#include "lib/fparser/fpoptimizer.cc"
#include "lib/fparser/fparser.hh"

/**
 * Single variable function
 */

namespace spivak
{
    class function 
    {
        private:
            std::string f; // function f
            FunctionParser_f fparser;

        public:
            function(std::string fx)
            {
                f = fx;
                fparser.Parse(fx, "x");
            }

            float eval(float * v)
            {
                return fparser.Eval(v);
            }

            void set_f(std::string ff) { f = ff; }


    };

    class function_mv
    {
        public:
            function_mv() {}
    };
}