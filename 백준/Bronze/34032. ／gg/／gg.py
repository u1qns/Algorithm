N = int(input())
S = input()

cnt = S.count('O')

if cnt >= (N + 1) // 2:
    print("Yes")
else:
    print("No")