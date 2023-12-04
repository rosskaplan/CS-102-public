import heapq

h = []
heapq.heappush(h, 2)
heapq.heappush(h, 1)
heapq.heappush(h, 3)
heapq.heappush(h, -1)

print(heapq.heappop(h))
print(heapq.heappop(h))
print(heapq.heappop(h))
print(heapq.heappop(h))

