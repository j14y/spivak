#pragma once
#include "function.h"

namespace spivak
{
    class limit
    {
        /**
         * the function f approaches the limit l near a means:
         * 
         * for every e > 0 there is some phi > 0 such that, for all x, 
         * 
         *  if,
         * 
         *              0 < | x- a | < phi,
         * 
         * then,
         *  
         *              | f(x) - l | < e 
         */

        private:
            spivak::function f;

        public:
            limit () {}

            limit (spivak::function ff)
            {
                this->f = ff;
            }

            


    };
}