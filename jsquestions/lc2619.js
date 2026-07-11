/**
 * @return {null|boolean|number|string|Array|Object} 
 * Simply use length property to get the length of the array and then use the index to get the last element
 */
Array.prototype.last = function() {
     return this.length ? this[this.length - 1] : -1;
};

/**
 * const arr = [1, 2, 3];
 * arr.last(); // 3
 */