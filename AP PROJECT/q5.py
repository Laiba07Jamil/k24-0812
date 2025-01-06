import math

# Given data
vectors = [
    {"magnitude": 6.00, "angle_rad": 0.900},
    {"magnitude": 5.00, "angle_rad": -75.0 * math.pi / 180},  
    {"magnitude": 4.00, "angle_rad": 1.20},
    {"magnitude": 6.00, "angle_rad": -210.0 * math.pi / 180}  
]

R_x = 0
R_y = 0

for vector in vectors:
    r = vector["magnitude"]
    theta = vector["angle_rad"]
    R_x += r * math.cos(theta) 
    R_y += r * math.sin(theta) 

R = math.sqrt(R_x**2 + R_y**2)

angle_rad = math.atan2(R_y, R_x)  
angle_deg = math.degrees(angle_rad)


print(f"(a) Resultant vector in unit-vector notation: {R_x:.2f}i + {R_y:.2f}j")
print(f"(b) Magnitude of the resultant vector: {R:.2f} m")
print(f"(c) Angle of the resultant vector (degrees): {angle_deg:.2f}°")
print(f"(d) Angle of the resultant vector (radians): {angle_rad:.2f} rad")
