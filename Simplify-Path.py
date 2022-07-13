class Solution:
    def simplifyPath(self, path: str) -> str:
        stack = []
        skip = {"",".",".."}
        for dirr in path.split("/"):
            if dirr == '..' and stack:
                stack.pop()
            elif dirr not in skip:
                stack.append(dirr)
                
        return "/" + "/".join(stack)