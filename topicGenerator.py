# Use this script to generate a topic to practice for today at random but in accordance with importance of topics

import random

# List of major topics
topics = ["Arrays", "Math", "Strings", "Binary Search", "Linked List", "Trees", "Two Pointers",
          "Greedy", "Backtracking", "Stacks and Queues", "Heap", "Graph", "Dynamic Programming", "Bit Manipulation", "Hashing"]
for index, topic in enumerate(topics):
    print(index+1, " : ", topic)

# Weights / Importance of various topics
topic_importance = [3, 2, 3, 3, 1, 1, 1, 2, 2, 2, 2, 3, 3, 2, 2]

# Making a random choice for today's keeping in mind the priority of various topics
todays_topic = random.choices(topics, weights=topic_importance)
print()
print("Topic for Today : ", todays_topic[0].upper())
