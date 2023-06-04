class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        counter=0
        counts=[0]
        for e in nums: 
            if e==1: 
                counter+=1
                counts.append(counter)
            else:
                counter= 0 
        return max(counts)