class MyCalendar:

    def __init__(self):
        self.bookings = []

    def book(self, start: int, end: int) -> bool:
        left = bisect_left(self.bookings, start)
        right = bisect_right(self.bookings, end-1)    
        
        if left != right or left%2==1:
            return False
        
        B = self.bookings
        self.bookings = B[:left] + [start,end-1] + B[left:]
        return True

# funny.. no one solves like I did
"""
Runtime: 355 ms, faster than 76.94% of Python3 online submissions for My Calendar I.
Memory Usage: 14.7 MB, less than 90.30% of Python3 online submissions for My Calendar I.
I did pass and actually pretty good
"""
