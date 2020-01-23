

#pragma once
#include <vector>
#include <cmath>

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

            /**
             * vector addition
             */
            spivak::vector add(spivak::vector w)
            {
                std::vector<float> temp;
                assert(dim() == w.dim());
                for (int i = 0; i < c.size(); i++)
                {
                    temp.push_back(get(i)+w.get(i));
                }
                return spivak::vector(temp);
            }

            /**
             * vector subtraction
             */
            spivak::vector sub(spivak::vector w)
            {
                                std::vector<float> temp;
                assert(dim() == w.dim());
                for (int i = 0; i < c.size(); i++)
                {
                    temp.push_back(get(i)-w.get(i));
                }
                return spivak::vector(temp);   
            }

            spivak::vector mult(float a)
            {
                std::vector <float> t;
                for (int i = 0; i < c.size(); i++)
                {
                    t.push_back(get(i) * a);
                }
                return spivak::vector(t);
            }

            spivak::vector div(float a)
            {
                std::vector <float> t;
                for (int i = 0; i < c.size(); i++)
                {
                    t.push_back(get(i) / a);
                }
                return spivak::vector(t);   
            }

            float mag()
            {
                float t = 0.0f;
                for (float a : c)
                {
                    t+= std::pow(a, 2.0f);
                }
                return std::sqrt(t);
            }

            float dot (spivak::vector w)
            {
                assert(dim() == w.dim());
                float t = 0.0f;
                for (int i=0; i < c.size(); c++)
                {
                    t += get(i) * w.get(i);
                }
                return t;
            }

            float dot(spivak::vector w, float theta)
            {
                return mag() * w.mag() * std::cos(theta);
            }

            spivak::vector cross(spivak::vector w)
            {
                // stub
            }

            float cross_mag(spivak::vector w, float theta)
            {
                return mag() * w.mag() * std::sin(theta);
            }



            spivak::vector projection(spivak::vector w)
            {
                return mult(dot(w) / std::pow(mag(), 2.0f));
            }

            spivak::vector unit()
            {
                std::vector<float> temp;
                for (float a : c)
                {
                    temp.push_back(a / mag());
                }
                return spivak::vector(temp);
            }


            float get(int i) { return c[i]; }
            int dim() { return c.size() + 1; }
            int dim() { return c.size() + 1; }
    };
}