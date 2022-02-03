class Solution(object):
    @staticmethod
    def lengthOfLongestSubstring(s):
        """
        :type s: str
        :rtype: int
        """
        if (len(s) <= 1):
            return len(s)

        max_count = 0
        start_point = 0
        end_point = 1
        sub_string = dict()
        sub_string[s[start_point]] = start_point

        while(end_point < len(s)):
            # If there's a repeat
            if (s[end_point] in (sub_string)):
                start_point = max(sub_string[s[end_point]] + 1, start_point) 
                if s[start_point] in sub_string:
                    del sub_string[s[start_point]]
                end_point = start_point + 1
            else:
                sub_string[s[end_point]] = end_point
                end_point += 1    
            max_count = max(max_count, end_point - start_point)
        return max_count

print(Solution.lengthOfLongestSubstring("abcabcbb"))
