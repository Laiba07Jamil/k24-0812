import math

# Components of the vectors
a = [3.0, 3.0, 3.0]
b = [2.0, 1.0, 3.0]

# Step 1: Compute the dot product
dot_product = sum(a[i] * b[i] for i in range(3))

# Step 2: Compute the magnitudes of the vectors
magnitude_a = math.sqrt(sum(x**2 for x in a))
magnitude_b = math.sqrt(sum(x**2 for x in b))

# Step 3: Compute cosine of the angle
cos_theta = dot_product / (magnitude_a * magnitude_b)

# Step 4: Calculate the angle in degrees
theta = math.degrees(math.acos(cos_theta))

# Display results
print(f"Dot product (a · b): {dot_product}")
print(f"Magnitude of a: {magnitude_a:.2f}")
print(f"Magnitude of b: {magnitude_b:.2f}")
print(f"Angle between vectors (theta): {theta:.2f} degrees")

