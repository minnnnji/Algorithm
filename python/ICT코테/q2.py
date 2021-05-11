def funWithAnagrams(text):
    # Write your code here
    result = [text[0]]
    result_copy = [sorted(text[0])]
    print(result_copy)
    for i in range(len(text)):
        tmp = sorted(text[i])
        if tmp not in result_copy:
            result.append(text[i])
            result_copy.append(sorted(text[i]))
    
    result = sorted(result)
    print(result)


n = 4
text = ["code","aaagmnrs","anagrams","doce"] 
funWithAnagrams(text)
#text = ["poke","pkoe","okpe","ekop"]