from functools import lru_cache


class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        self.s = s
        self.p = p
        return self.match(0, 0)
    
    @lru_cache(maxsize = None)
    def match(self, i, j):
        if i == len(self.s) and j == len(self.p):
            return True
            
        if i < len(self.s)  and j == len(self.p):
            return False
        
        is_star = self.p[j] == '*'

        if i == len(self.s) and j < len(self.p):
            if is_star:
                return self.match(i, j+1)
            return False

        if self.s[i] == self.p[j]:
            return self.match(i+1, j+1)
        
        else:
            if not is_star:
                if self.p[j] == '?':
                    return self.match(i+1, j+1)
                else:
                    return False
            else:
                return self.match(i, j+1) or self.match(i+1, j) \
                or self.match(i+1, j+1)


if __name__ == '__main__':
    s = 'adceb'
    p = '*a*b'
    print(Solution().isMatch(s, p))