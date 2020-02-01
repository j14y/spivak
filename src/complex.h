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
            
            /**
             * exponential function, defined as the power series sum^{n}_{0} z^n/n!.
             * @param n upper summation limit
             * @param c current index
             * @param s sum
             * @param r given radius of convergence
             * @return value of exponential function within given radius of convergence
             */
            float exp(int n, int c, float s, float r)
            {
                if ((s = std::pow()/))
                {

                } else return exp(n, c++, s, r);
            }

        public:
            complex() {}

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

            /**
             * complex square root
             */
            std::pair<spivak::complex, spivak::complex> sqr_root()
            {
                float gamma = std::sqrt((re() + std::sqrt(std::pow(re(), 2.0f) + std::pow(im(), 2.0f)))/2.0f);
                float delta = sgn(this->b) * std::sqrt(( -re() + std::sqrt(std::pow(re(), 2.0f) + std::pow(im(), 2.0f)))/2.0f);
                std::pair<spivak::complex, spivak::complex> sol = std::make_pair(spivak::complex(gamma, delta, Operation::ADD), spivak::complex(gamma, delta, Operation::SUB));
            }

            /**
             * complex modulus 
             * sqrt(a^2 + b^2)
             */
            float modulus ()
            {
                return std::sqrt(std::pow(re(), 2.0f) + std::pow(im(), 2.0f));
            }
            
            /**
             * exponential function. Calls {@link exp(int, int, float, float)} internally.
             * @param n upper summation limit
             * @param r radius of convergence
             */
            float exp(int n, float r)
            {
                exp(n, 0.0f, 0.0f, r);
            }

            // relations and operations
            // src: https://en.wikipedia.org/wiki/Complex_number#Definition

            /**
             * complex equality
             * @param n complex number
             */
            bool equal(spivak::complex n)
            {
                return (re() == n.re()) && (im() == n.im());
            }

            /**
             * finds and returns the complex conjugate of the complex object
             */
            spivak::complex conjugate()
            {
                return (this->op == Operation::ADD) ? 
                    spivak::complex(re(), im(), Operation::SUB): 
                    spivak::complex(re(), im(), Operation::ADD);
            }

            /*********************
             * utility functions *
             *********************/

            /**
             * factorial function
             * @param n factorial
             * @param factorial value of n
             */
            inline int factorial(int n)
            {
                return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
            }

            /**
             * sign function/signum
             * @param a nonnegative real number
             * @return signum of a
             */
            inline float sgn(float a) 
            {
                if (a < 0)          return -1.0f;
                else if (a == 0.0f) return 0.0f;
                else                return 1.0f;
            }

            inline void set_re(float a) { this->a = a; }
            inline void set_im(float b) { this->b = b; }
            inline float re() { return a; }
            inline float im() { return b; }
    };
}