

#pragma once
#include <vector>

namespace spivak
{
    class vector 
    {
        private:
            std::vector<float> c;
            vector(std::vector<float> cc) 
            {
                c = cc;
            }

            spivak::vector add(spivak::vector w)
            {
                std::vector<float> temp;
                assert(dim() == w.dim());
                for (int i = 0; i < dim(); i++)
                {
                    temp.push_back(get(i)+w.get(i));
                }
                return spivak::vector(temp);
            }

            float get(int i) { return c[i]; }
            int dim() { return c.size(); }
    };
}