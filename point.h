#pragma once

#include <vector>

namespace spivak
{
    class point 
    {
        public:
            int d;
            std::vector<int> c; // point components
            point(int degree)
            {
                d=degree;
            }

            int dim () { return c.size(); }
    };
}