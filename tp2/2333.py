N = int(input())
P = [int(x) for x in input().replace("\n", "").split(" ")]

# def max_sa(n):
#     if n < 0:
#         return (0, 0)
#     subv, suf = max_sa(n-1)
#     nsubv = max(subv, P[n]+suf)
#     nsuf = max(P[n]+suf, 0)
#     return (nsubv, nsuf)

def max_sa():
    global_max = 0
    suffix_max = 0
    for i in range(N):
        if P[i] + suffix_max > global_max:
            suffix_max = suffix_max + P[i]
            global_max = suffix_max
        elif P[i] + suffix_max > 0:
            suffix_max = suffix_max + P[i]
        else:
            suffix_max = 0 
    return max(global_max, suffix_max)


# Only in middle
m_subv = max_sa()

# Crossing the ends
sum_t = 0
for i in range(N):
    sum_t += P[i]
    P[i] = -P[i]

neg_m_subv = max_sa()

print(max(m_subv, sum_t + neg_m_subv))

