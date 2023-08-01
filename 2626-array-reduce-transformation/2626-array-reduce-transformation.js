/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    var ans=init;
    for(a of nums)
        ans=fn(ans,a);
    return ans;
};