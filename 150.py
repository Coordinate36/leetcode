class Solution(object):
    def evalRPN(self, tokens):
        """
        :type tokens: List[str]
        :rtype: int
        """
        st = []
        for token in tokens:
            if token not in ('+', '-', '*', '/'):
                st.append(int(token))
            else:
                right = st.pop()
                left = st.pop()
                if token == '+':
                    val = left + right;
                elif token == '-':
                    val = left - right;
                elif token == '*':
                    val = left * right
                else:
                    val = abs(left) / abs(right)
                    if (left < 0 and right > 0) or (left > 0 and right < 0):
                        val = -val
                st.append(val)
        return st[-1]