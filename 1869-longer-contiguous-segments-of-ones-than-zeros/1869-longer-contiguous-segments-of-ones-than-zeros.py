class Solution:
    def checkZeroOnes(self, s: str) -> bool:
        mzc = zero_counter = 0
        moc = one_counter = 0
        for ind in range(len(s)):
            if s[ind] == '1':
                one_counter += 1
                zero_counter = 0
                moc = max(moc, one_counter)
            else:
                zero_counter += 1 
                one_counter = 0
                mzc = max(mzc, zero_counter)
        print(moc, mzc)
        return moc > mzc
            