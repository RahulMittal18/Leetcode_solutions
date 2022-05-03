class Solution:
    def decodeString(self, s: str) -> str:
        st=[]
        # ans=""
        for c in s:
            if c=="]":
                ans=""
                temp=""
                    
                while st[-1]!="[":
                    if st[-1].isalpha():
                        temp= st[-1]+temp      
                    st.pop()
                st.pop()
                i=1
                mult=0
                while len(st) and st[-1].isdigit():
                    mult=(ord(st[-1])-48)*i + mult
                    i*=10
                    st.pop()
                ans+=(mult*temp)
                st.append(ans)
            else:
                st.append(c)
        res=""
        while len(st):
            res=st[-1] + res
            st.pop()
        return res