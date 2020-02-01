#pragma once

#include <cmath>
#include <utility>

namespace spivak
{

    enum Operation
    {
        ADD, SUB
    };
    // a complex number is a number that can be expresses in the form

    // a+ bi, a, b e R
    // i is a solution to x^2 = -1
    class complex
    {
        private:
            float a, b;
            float i;
            spivak::Operation op;

        public:

            complex (float a, float b) 
            {
                this->a = a;
                this->b = b;
            }

            complex (float a, float b, spivak::Operation o)
            {
                this->a = a;
                this->b = b;
                this->op = o;
            }

            complex (float a, float b, float i)
            {
                this->a = a;
                this->b = b;
                this->i = i;
            }

            complex(float a, float b, float i, spivak::Operation o)
            {
                this->a = a;
                this->b = b;
                this->i = i;
                this->op = o;
            }

            // Two complex numbers a and b are most easily added by separately adding 
            // their real and imaginary parts of the summands.
            spivak::complex add(spivak::complex c)
            {
               return spivak::complex(re() + c.re(), im() + c.im(), Operation::ADD);
            }

            spivak::complex sub(spivak::complex c) 
            {
                return spivak::complex(re() - c.re(), im() - c.im(), Operation::ADD);
            }

            spivak::complex mult(spivak::complex c) 
            {

            }
            spivak::complex div(spivak::complex c) {} 

            spivak::complex reciprocal() 
            {
                float denom = std::pow(re(), 2.0f) + std::pow(im(), 2.0f);
                return spivak::complex(re()/denom, im()/denom, Operation::SUB);
            }

            std::pair<spivak::complex, spivak::complex> sqr_root()
            {
                std::make_pair();
            }


            // relations and operations
            // src: https://en.wikipedia.org/wiki/Complex_number#Definition

            // Two complex numbers are equal if and only if both their real and imaginary parts are equal
            bool equal(spivak::complex n)
            {
                return (re() == n.re()) && (im() == n.im());
            }

            spivak::complex conjugate()
            {
                return (this->op == Operation::ADD) ? 
                    spivak::complex(re(), im(), Operation::SUB): 
                    spivak::complex(re(), im(), Operation::ADD);
            }

            // mutate 
            void set_re(float a) { this->a = a; }
            void set_im(float b) { this->b = b; }

            // accessors
            float re() { return a; }
            float im() { return b; }
    };
}