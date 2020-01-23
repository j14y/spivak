#pragma once
#include <vector>
#include <cmath>

/**
 * Basic vector operations
 */

namespace spivak
{
    class vector 
    {
        private:
            std::vector<float> c; // vector components
            
            vector(std::vector<float> cc) 
            {
                c = cc;
            }

            /**
             * vector addition
             * @param w vector
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
             * @param w vector
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

            /**
             * scalar multiplication
             * @param a scalar value
             */
            spivak::vector mult(float a)
            {
                std::vector <float> t;
                for (int i = 0; i < c.size(); i++)
                {
                    t.push_back(get(i) * a);
                }
                return spivak::vector(t);
            }

            /**
             * vector division (shorthand for multiplication by inverse)
             * @param a divisor
             */
            spivak::vector div(float a)
            {
                std::vector <float> t;
                for (int i = 0; i < c.size(); i++)
                {
                    t.push_back(get(i) / a);
                }
                return spivak::vector(t);   
            }

            /**
             * calculates and returns magnitude
             */
            float mag()
            {
                float t = 0.0f;
                for (float a : c)
                {
                    t+= std::pow(a, 2.0f);
                }
                return std::sqrt(t);
            }

            /**
             * dot product of this vector with another vector w
             * @param w vector
             */
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

            /**
             * dot product, trigonometric formula
             * @param w vector
             * @param theta cosine angle
             */
            float dot(spivak::vector w, float theta)
            {
                return mag() * w.mag() * std::cos(theta);
            }

            /**
             * cross product
             * @param w vector
             */
            spivak::vector cross(spivak::vector w)
            {
                // stub
            }

            /**
             * cross product magnitude
             * @param w vector
             * @param theta sine angle 
             */
            float cross_mag(spivak::vector w, float theta)
            {
                return mag() * w.mag() * std::sin(theta);
            }

            /**
             * projection of vector onto another vector, w
             * @param w vector
             */
            spivak::vector projection(spivak::vector w)
            {
                return mult(dot(w) / std::pow(mag(), 2.0f));
            }

            /**
             * unit vector of this vector
             */
            spivak::vector unit()
            {
                std::vector<float> temp;
                for (float a : c)
                {
                    temp.push_back(a / mag());
                }
                return spivak::vector(temp);
            }

            /**
             * returns the i-th component of this vector
             * @param i i-th component
             */
            float get(int i) { return c[i]; }

            /**
             * returns number of dimensions of this vector
             */
            int dim() { return c.size() + 1; }
    };
}