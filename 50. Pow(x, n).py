import sys
#sys.setrecursionlimit(1000000)

class Solution(object):
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        if(n==0):
            return 1
        if(n<0):
            n=-n
            x=1/x
        if(n == 1):
            return x
        if(n%2==1):
            return(x*self.myPow(x,n-1))
        else:
            a = self.myPow(x,n/2)
            return(a*a)
if (__name__=='__main__'):
    sol = Solution()
    ans = sol.myPow(0.44528,0)
    print(ans)
    