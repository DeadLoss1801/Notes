import sys

def main():
    height = [30, 10, 60, 10, 60, 50]
    n = len(height)
    prev = 0
    prev2=0
    for i in range(1, n):
        jumpTwo =  sys.maxsize
        jumpOne = prev + abs(height[i] -height[i-1])
        if i > 1:
            jumpTwo = prev2 + abs(height[i] -height[i-2])
        
        cur_i = min(jumpOne, jumpTwo)
        prev2 = prev
        prev =cur_i
    
    print(prev)

if __name__ == "__main__" :
    main()