/**
 * @param {number} millis
 * @return {Promise} 
 * resolve and reject are inbuilt functions(acting as callbacks) that are used to resolve and reject the promise respectively.
 */
async function sleep(millis) {
    return new Promise((resolve,reject) => {
        setTimeout(() => resolve(millis), millis);
    });
}

/** 
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */