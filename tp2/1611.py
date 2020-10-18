# -*- coding: utf-8 -*-

T = int(input())

for _ in range(T):
    line1 = input().replace("\n", "").split(" ")
    N, C, M = int(line1[0]), int(line1[1]), int(line1[2])
    floors = [int(x) for x in input().replace("\n", "").split(" ")]

    floors = sorted(floors, reverse=True)
    E = 0
    for i in range(0, len(floors), C):
        E += 2*floors[i]
    print(E)
