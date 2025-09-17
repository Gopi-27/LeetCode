/**
 * @param {Object|Array} obj
 * @return {boolean}
 */
var isEmpty = function(obj) {
    for(var key in obj){
        return false;
    }
    return true;
};