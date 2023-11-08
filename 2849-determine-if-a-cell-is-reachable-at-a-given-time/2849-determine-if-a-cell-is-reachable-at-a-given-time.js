/**
 * @param {number} sx
 * @param {number} sy
 * @param {number} fx
 * @param {number} fy
 * @param {number} t
 * @return {boolean}
 */
var isReachableAtTime = function(sx, sy, fx, fy, t) {
    let xD = Math.abs(fx - sx);
    let yD = Math.abs(fy - sy);

    let minD = Math.min(xD, yD) + Math.abs(yD - xD);
    if(minD == 0)
        return t != 1;

    return t >= minD;
};