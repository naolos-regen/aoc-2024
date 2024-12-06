#!/usr/bin/env python3

from collections import defaultdict, deque


def is_update_ordered(update, rules):
    for x, y in rules:
        if x in update and y in update:
            if update.index(x) > update.index(y):  # x must be before y
                return False
    return True


def topological_sort(pages, rules):
    graph = defaultdict(list)
    in_degree = defaultdict(int)
    list(map(lambda r: graph[r[0]].append(r[1])
             or in_degree.update({r[1]: in_degree[r[1]] + 1})
             if r[0] in pages and r[1] in pages else None, rules))

    for node in pages:
        if node not in in_degree:
            in_degree[node] = 0

    queue = deque(filter(lambda node: in_degree[node] == 0, pages))

    sorted_order = []
    while queue:
        current = queue.popleft()
        sorted_order.append(current)
        for neighbor in graph[current]:
            in_degree[neighbor] -= 1
            if in_degree[neighbor] == 0:
                queue.append(neighbor)

    return sorted_order


def sum_part_one(file_path):
    rules, updates = parse_input(file_path)
    correctly_ordered = filter(lambda update:
                               is_update_ordered(update, rules), updates)
    return sum(update[len(update) // 2] for update in correctly_ordered)


def sum_part_two(file_path):
    rules, updates = parse_input(file_path)
    incorrectly_ordered = filter(lambda update:
                                 not is_update_ordered(update, rules), updates)
    return sum(
        topological_sort(update, rules)[len(update) // 2]
        for update in incorrectly_ordered
    )


def parse_input(file_path):
    with open(file_path, 'r') as f:
        input_data = f.read()
    sections = input_data.strip().split("\n\n")
    rules = [tuple(map(int, line.split("|")))
             for line in sections[0].splitlines()]
    updates = [list(map(int, line.split(",")))
               for line in sections[1].splitlines()]
    return rules, updates


file_path = "input.txt"
result = sum_part_one(file_path)
print("Part 1: ", result)
result = sum_part_two(file_path)
print("Part 2: ", result)
