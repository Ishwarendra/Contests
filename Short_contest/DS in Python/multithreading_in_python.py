# NOT USING MULTITHREADING

import time, threading

# def calc_sq(numbers):
#     print("Calculate square of numbers")
#     for n in numbers:
#         time.sleep(0.2)
#         print(f"Square: {n*n}")

# def calc_cube(numbers):
#     print("Calculate cube of numbers")
#     for n in numbers:
#         time.sleep(0.2)
#         print(f"Cube: {n*n*n}")

# arr = [1,2,3,4]
# t = time.time()

# calc_sq(arr)
# calc_cube(arr)

# print(f"Total time taken is {time.time() - t}") # time = 1.60


#USING MULTITHREADING

def calc_sq(numbers):
    print("Calculate square of numbers")
    for n in numbers:
        time.sleep(0.2)
        print(f"Square: {n*n}")

def calc_cube(numbers):
    print("Calculate cube of numbers")
    for n in numbers:
        time.sleep(0.2)
        print(f"Cube: {n*n*n}")

arr = [1,2,3,4]
t = time.time()

t1 = threading.Thread(target=calc_sq, args=(arr,)) # tuple containing arguments.
t2 = threading.Thread(target=calc_cube, args=(arr,))

t1.start()
t2.start()

t1.join()
t2.join()

print(f"Total time taken is {time.time() - t}") # time = 0.8 (half of earlier one where we weren't doing multithreading)
# do square while sleeping do cube then while sleeping back to square and so on 
