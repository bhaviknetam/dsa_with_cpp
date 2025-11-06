/**
 * @param {Array} arr
 * @param {number} depth
 * @return {Array}
 */
var flat = function (arr, n) {
    const res = [];
    function helper(curr, depth){
        for(const elem of curr){
            if(Array.isArray(elem) && depth > 0){
                helper(elem, depth - 1);
            }else{
                res.push(elem);
            }
        }
    };
    helper(arr, n);
    return res;
};