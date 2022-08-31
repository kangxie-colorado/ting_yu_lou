class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        buckets = [[]]*(len(nums)+1)
        for i in range(len(buckets)):
            buckets[i] = []

        C = Counter(nums)

        for num, count in C.items():
            buckets[count].append(num)

        res = []
        for i in range(len(nums), -1, -1):
            res.extend((buckets[i]))
            # because the answer is guranteed to be unique so no need to consider half
            # of the set can be used and left the other half
            # because that would make the answer non-uniq
            k -= len(buckets[i])
            if k == 0:
                break

        return res
