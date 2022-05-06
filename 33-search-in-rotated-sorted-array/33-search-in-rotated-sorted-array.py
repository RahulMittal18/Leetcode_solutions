class Solution:
    def search(self, A: List[int], target: int) -> int:
        left, right = 0, len(A) - 1
        while left <= right:
            mid = left + (right - left) // 2
            if A[mid] == target: return mid

            # inflection point is to the right of mid i.e. Left part is strictly increasing
            if A[mid] >= A[left]:
                if A[left] <= target < A[mid]:
                    right = mid - 1
                else:
                    left = mid + 1

            # inflection point is to the left of mid i.e. Right part is strictly increasing
            else:
                if A[mid] < target <= A[right]:
                    left = mid + 1
                else:
                    right = mid - 1

        return -1