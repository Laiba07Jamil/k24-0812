import math

# Components of the vectors
a = [4.0, -3.0]  
b = [6.0, 8.0]   

magnitude_a = math.sqrt(a[0]**2 + a[1]**2)

angle_a = math.degrees(math.atan2(a[1], a[0]))
if angle_a < 0: 
    angle_a += 360


magnitude_b = math.sqrt(b[0]**2 + b[1]**2)

angle_b = math.degrees(math.atan2(b[1], b[0]))

sum_ab = [a[0] + b[0], a[1] + b[1]]
magnitude_sum_ab = math.sqrt(sum_ab[0]**2 + sum_ab[1]**2)
angle_sum_ab = math.degrees(math.atan2(sum_ab[1], sum_ab[0]))

diff_ba = [b[0] - a[0], b[1] - a[1]]
magnitude_diff_ba = math.sqrt(diff_ba[0]**2 + diff_ba[1]**2)
angle_diff_ba = math.degrees(math.atan2(diff_ba[1], diff_ba[0]))


diff_ab = [a[0] - b[0], a[1] - b[1]]
magnitude_diff_ab = math.sqrt(diff_ab[0]**2 + diff_ab[1]**2)
angle_diff_ab = math.degrees(math.atan2(diff_ab[1], diff_ab[0]))


angle_between_diff = 180.0


print(f"(a) Magnitude of a: {magnitude_a:.2f}")
print(f"(b) Angle of a: {angle_a:.2f} degrees")
print(f"(c) Magnitude of b: {magnitude_b:.2f}")
print(f"(d) Angle of b: {angle_b:.2f} degrees")
print(f"(e) Magnitude of a + b: {magnitude_sum_ab:.2f}")
print(f"(f) Angle of a + b: {angle_sum_ab:.2f} degrees")
print(f"(g) Magnitude of b - a: {magnitude_diff_ba:.2f}")
print(f"(h) Angle of b - a: {angle_diff_ba:.2f} degrees")
print(f"(i) Magnitude of a - b: {magnitude_diff_ab:.2f}")
print(f"(j) Angle of a - b: {angle_diff_ab:.2f} degrees")
print(f"(k) Angle between b - a and a - b: {angle_between_diff} degrees")
