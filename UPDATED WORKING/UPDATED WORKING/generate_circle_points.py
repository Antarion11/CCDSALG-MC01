import math
import random

# Generate points around a circle
def generate_circle_points(radius, n, filename):
    with open(filename, "w") as f:
        f.write(f"{n}\n")
        for i in range(n):
            angle = 2 * math.pi * i / n
            x = round(radius * math.cos(angle), 6)
            y = round(radius * math.sin(angle), 6)
            f.write(f"{x} {y}\n")

# Generate random points within a square area
def generate_random_points(n, max_x, max_y, filename):
    with open(filename, "w") as f:
        f.write(f"{n}\n")
        for _ in range(n):
            x = round(random.uniform(0, max_x), 6)
            y = round(random.uniform(0, max_y), 6)
            f.write(f"{x} {y}\n")

# Generate points in a grid pattern
def generate_grid_points(rows, cols, spacing, filename):
    n = rows * cols
    with open(filename, "w") as f:
        f.write(f"{n}\n")
        for i in range(rows):
            for j in range(cols):
                x = round(j * spacing, 6)
                y = round(i * spacing, 6)
                f.write(f"{x} {y}\n")

# Generate collinear points along a line (y = x)
def generate_collinear_points(n, max_val, filename):
    with open(filename, "w") as f:
        f.write(f"{n}\n")
        for i in range(n):
            x = round(i * (max_val / n), 6)
            y = x
            f.write(f"{x} {y}\n")

# Generate test cases based on your specifications
generate_circle_points(10, 64, r"C:\Users\aron\Desktop\circle_points_64.txt")
generate_random_points(256, 100, 100, r"C:\Users\aron\Desktop\random_points_256.txt")
generate_grid_points(32, 32, 3.125, r"C:\Users\aron\Desktop\grid_points_1024.txt")  # 32x32 grid within a 100x100 area
generate_collinear_points(2048, 200, r"C:\Users\aron\Desktop\collinear_points_2048.txt")
generate_random_points(32768, 1000, 1000, r"C:\Users\aron\Desktop\large_random_points_32768.txt")
