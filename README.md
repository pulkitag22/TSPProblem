# Unidirectional TSP Problem
Problems that require minimum paths through some domain appear in many different areas of computer science. For example, one of the constraints in VLSI routing problems is minimizing wire length. 

The Traveling Salesperson Problem (TSP) — finding whether all the cities in a salesperson’s route can be visited exactly once with a specified limit on travel time — is one of the canonical examples of an NP-complete problem; solutions appear to require an inordinate amount of time to generate, but are simple to check. This problem deals with finding a minimal path through a grid of points while traveling only from left to right. Given an m×n matrix of integers, you are to write a program that computes a path of minimal weight. 

A path starts anywhere in column 1 (the first column) and consists of a sequence of steps terminating in column n (the last column). A step consists of traveling from column i to column i + 1 in an adjacent (horizontal or diagonal) row. The first and last rows (rows 1 and m) of a matrix are considered adjacent, i.e., the matrix “wraps” so that it represents a horizontal cylinder. 

The weight of a path is the sum of the integers in each of the n cells of the matrix that are visited.
