class Solution(object):
    def reverseWords(self, s):
        l = s.split(" ")
        a = []
        for e in l:
            if e:
                a.append(e)
        a = a[::-1]
        return " ".join(a)
        