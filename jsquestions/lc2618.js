/**
 * @param {*} obj
 * @param {*} classFunction
 * @return {boolean}  
 * js internally uses prototypal inheritance, so we can use Object.getPrototypeOf to get the prototype of the object and then compare it to the prototype of the classFunction
 * Use Object.getPrototypeOf to get the prototype of the object and then compare it to the prototype of the classFunction
 */
var checkIfInstanceOf = function(obj, classFunction) {
    if(classFunction == null) return false; // catches both null and undefined

    while(obj != null){ 
        obj = Object.getPrototypeOf(obj);
        if(obj === classFunction.prototype){ 
            return true;
        }
    }
    return false;
};

/**
 * checkIfInstanceOf(new Date(), Date); // true
 */