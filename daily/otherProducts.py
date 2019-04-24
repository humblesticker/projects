# 
# linear using stats from left and right
#
def otherProduct(nums):
    product = 1
    for n in nums: product *= n
    for i, n in enumerate(nums): nums[i] = product/n

# binary search factor such that n * factor = product
def findFactor(product, n):
    print(n)

nums = [1, 2, 3, 4, 5]
otherProduct(nums)
for n in nums: print(n)