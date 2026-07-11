/**
 * @param {number} n
 * @return {Function} counter
 * first create an instance of the function and then return it
 * this saves the value of n in the closure and then increments it by 1 each time the function is called
 */
var createCounter = function(n) {
    return function() {
        return n++;
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */