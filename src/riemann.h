#pragma once

#include <string>
#include <iostream>
#include "function.h"

// riemann integral
// jordy chetty

namespace spivak
{
    class riemann 
    {
        private:

        public:
            riemann() {}
            /**
             * riemann sum for a function f
             * @param f function
             * @param a closed interval start bound
             * @param b closed interval end bound
             * @param p_size partition size
             */
            float left_sum(spivak::function f, float a, float b, float p_size) 
            {
                assert(b > a);
                float sum = 0.0f;
                float p_offset = (b - a) / p_size;
                for (float i = a; i < b; i+=p_offset)
                {
                    float vars []= {i};
                    sum+=p_offset*f.eval(vars);
                } 
                return sum;
            }

            float right_sum(spivak::function f, float a, float b, float p_size) 
            {
                assert(b > a);
                float sum = 0.0f;
                float p_offset = (b - a) / p_size;
                for (float i = a; i <= b; i+=p_offset) // TODO change params
                {
                    float vars []= {i};
                    // sum+=p_offset*f.eval(vars);
                } 
                return sum;
            }

            float middle_sum(spivak::function f, float a, float b, float p_size) 
            {
                assert(b > a);
                float sum = 0.0f;
                float p_offset = (b - a) / p_size;
                for (float i = a; i <= b; i+=p_offset) // TODO change params
                {
                    float vars []= {i};
                    // sum+=p_offset*f.eval(vars);
                } 
                return sum;
            }
    };
}