unsortedNum = input()

nums = []
for num in unsortedNum:
    nums.append(int(num))

nums = sorted(nums, reverse=True)

for num in nums:
    print(num,end="")

print()