/**
 * @param {number[]} n
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(n, fn, init) {
    for(let i = 0; i < n.length; i++) {
        init = fn(init, n[i]);
    }
    return init;
};
