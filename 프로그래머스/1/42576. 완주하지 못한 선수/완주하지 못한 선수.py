def solution(participant, completion):
    answer = ''
    a = sorted(participant)
    b = sorted(completion)
    for i in range(len(b)):
        if a[i] != b[i]:
            answer = a[i]
            return answer
            
    answer = a[-1]
            
    return answer