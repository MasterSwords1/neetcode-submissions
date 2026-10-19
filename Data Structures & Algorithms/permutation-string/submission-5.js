class Solution {
    /**
     * @param {string} s1
     * @param {string} s2
     * @return {boolean}
     */
    checkInclusion(s1, s2) {
        if (s1.length > s2.length)
            return false;
        let right = 0;
        let left = 0;
        let charSum = 0;
        for (let i = 0; i < s1.length; i++) {
            charSum += s1.charCodeAt(i)
        }
        // console.log(`charSum: ${charSum}`)
        let sum = 0;
        for (; right < s2.length; right++) {
            sum += s2.charCodeAt(right);
            if (right - left >= s1.length) {
                sum -= s2.charCodeAt(left);
                left += 1;
            }
            // console.log(`window: ${right - left}`)
            // console.log(`right ${right} left ${left}`)
            // console.log(`sum ${sum}`)
            // console.log(`right: ${right}`)
            // console.log(`left: ${left}`)
            // console.log(`===`)
            const lookaheads = [...s1]
    .map(escapedChar => `(?=.*${escapedChar})`)
    .join('');
            let reg = new RegExp(`${[lookaheads]}`);
            let target = s2.substring(left, right + 1);
            if (sum === charSum && reg.test(target || ""))
                return true;
        }
        return false;
    }
}
