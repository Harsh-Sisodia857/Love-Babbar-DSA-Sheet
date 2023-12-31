# MAX GEMS:
def maximize_gems(dishes):
  dishes.sort()
  max_gems_max, max_gems_min = 0, 0
  current_sum_max, current_sum_min = 0, 0
  for dish_id, rating in dishes:
    if rating >= 0:
      current_sum_max += rating
      current_sum_min -= abs(rating)
    else:
      current_sum_max -= abs(rating)
      current_sum_min += rating
    max_gems_max = max(max_gems_max, current_sum_max)
    max_gems_min = max(max_gems_min, current_sum_min)
  return max(max_gems_max, max_gems_min)

dishes = [(6, -3), (2, 10), (8, 63), (-4, 5), (1, -92), (-12, 9), (10, 10)]
max_gems = maximize_gems(dishes)
print(f"Maximum number of gems: {max_gems}")