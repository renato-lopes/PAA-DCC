INF = 99999999

N, C = (int(x) for x in input().replace("\n", "").split(" "))
P = [int(x) for x in input().replace("\n", "").split(" ")]

min_buy = P[0]
max_sell = P[0]
profit = 0

for i in range(1, N):
    if P[i] < min_buy:
        if max_sell - P[i] >= C:
            if max_sell - min_buy - C > 0:
                profit += max_sell - min_buy - C
        min_buy = P[i]
        max_sell = P[i]
    elif P[i] >= max_sell:
        max_sell = P[i]
    elif max_sell - P[i] >= C:
        if max_sell - min_buy - C > 0:
            profit += max_sell - min_buy - C
            min_buy = P[i]
            max_sell = P[i]

if max_sell - min_buy > 0:
    profit += max_sell - min_buy - C
print(profit)








# from collections import deque

# INF = 99999999

# N, C = (int(x) for x in input().replace("\n", "").split(" "))
# P = [int(x) for x in input().replace("\n", "").split(" ")]

# stack = deque()
# min_buy, max_sell = INF, -INF
# profit = 0
# for i in range(N):
#     if P[i] + C < min_buy:
#         if max_sell - min_buy > 0:
#             profit += max_sell - min_buy
#             stack.append((min_buy, max_sell))
#         min_buy, max_sell = P[i] + C, -INF
#     elif P[i] >= max_sell:
#         max_sell = P[i]
#     elif P[i] < max_sell:
#         cur_profit = max_sell - min_buy
#         if cur_profit < 0:
#             continue
#         if len(stack) == 0:
#             profit += cur_profit
#             min_buy, max_sell = INF, -INF
#         else:
#             last_min_buy, last_max_sell = stack.pop()
#             last_profit = last_max_sell - last_min_buy
#             undo_profit = max_sell - last_min_buy

#             if cur_profit + last_profit >= undo_profit:
#                 profit += cur_profit
#                 stack.append((min_buy, max_sell))
#                 min_buy, max_sell = INF, -INF
#             else:
#                 profit -= last_profit
#                 profit += undo_profit
#                 stack.append((last_min_buy, max_sell))
#                 min_buy, max_sell = INF, -INF

# if max_sell - min_buy > 0:
#     profit += max_sell - min_buy
# print(profit)









# INF = 99999999

# N, C = (int(x) for x in input().replace("\n", "").split(" "))
# P = [int(x) for x in input().replace("\n", "").split(" ")]

# valorAtual = P[0]
# valorFinal = P[0]
# profit = 0

# for i in range(1, N):
#     if valorAtual-P[i] >= C:
#         if valorAtual - valorFinal - C > 0:
#             profit += (valorAtual - valorFinal - C)
#         valorAtual = P[i]
#         valorFinal = P[i]
#     if P[i] > valorAtual:
#         valorAtual = P[i]
#     if P[i] < valorFinal:
#         valorFinal = P[i]
#         valorAtual = P[i]

# if (valorAtual - valorFinal - C) > 0:
#     profit += (valorAtual - valorFinal - C)
# print(profit)








# def max_sa(L, C):
#     global_max = 0
#     suffix_max = -C
#     profit = 0
#     cur_start = 0
#     for i in range(len(L)):
#         if L[i] + suffix_max > global_max:
#             print("1")
#             suffix_max = suffix_max + L[i]
#             global_max = suffix_max
#         elif L[i] + suffix_max > 0:
#             print("2")
#             suffix_max = suffix_max + L[i]
#         else:
#             print("3")
#             print(f"{cur_start =}")
#             if i - cur_start > 0:
#                 s = 0
#                 for j in range(cur_start, i):
#                     s += L[j]
#                 s -= C
#                 if s > 0:
#                     profit += s
#             suffix_max = -C
#             cur_start = i+1
#     if cur_start < len(L):
#         print("end", cur_start)
#         for j in range(cur_start, len(L)):
#             profit += L[j]
#         profit -= C
#     print("-")
#     return profit


# N, C = (int(x) for x in input().replace("\n", "").split(" "))
# P = [int(x) for x in input().replace("\n", "").split(" ")]

# L = []
# for i in range(1, len(P)):
#     L.append(P[i]-P[i-1])

# print(max_sa(L, C))
