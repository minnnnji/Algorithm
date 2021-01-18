
participants =["mislav", "stanko", "mislav", "ana"]
completion = ["stanko", "ana", "mislav"]

word_cnt = {}

for lst in participants:
    try: word_cnt[lst] += 1
    except: word_cnt[lst]=1

for i in completion:
    if i in word_cnt:
        word_cnt[i] -= 1

print(word_cnt)
answer = 0
for idx in word_cnt:
    if word_cnt[idx] != 0:
        answer = idx
        break

print(answer)