class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        if s is '':
            return True
        if len(s) == 1:
            return False
        
        match_map = {
            '{': '}',
            '(': ')',
            '[': ']'
        }
        pop_stack = []
        for i in xrange(len(s)):
            if s[i] in match_map.keys():
                pop_stack.append(s[i])
            else:
                if len(pop_stack) == 0:
                    return False
                elif s[i] == match_map[pop_stack[-1]]:
                    pop_stack = pop_stack[:-1]
                else:
                    return False
        return len(pop_stack) == 0