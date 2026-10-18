class Solution {
    /**
     * @param {string} s
     * @param {number} k
     * @return {number}
     */
    characterReplacement(s, k) {
        let res = 0;
        
        const charMap = new Map();

        let j = 0;
        let maxFreq = 0;
        for (let i = 0; i < s.length; i++) {
            charMap.set(s[i], (charMap.get(s[i]) || 0) + 1);
            maxFreq = Math.max(maxFreq, charMap.get(s[i]));
            if (i - j + 1 - maxFreq > k) {
                charMap.set(s[j], (charMap.get(s[j]) || 1) - 1)
                j++;
            }
            res = Math.max(res, i - j + 1)
        }
        return res;
    }
}

