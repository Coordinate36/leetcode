def input():
    m = int(raw_input())
    labels = []
    for i in xrange(m):
        string = raw_input()
        labels.extend(string.split(';'))
    for i, label in enumerate(labels):
        x, y = label.split(',')
        labels[i] = (int(x), int(y))
    return labels

def main():
    ans = []
    labels = input()
    if not labels:
        print('')
        return

    labels.sort(key=lambda elem: elem[0])
    
    cur_left, cur_right = labels[0]

    for left, right in labels:
        if cur_right < left - 1:
            ans.append('%s,%s' % (cur_left, cur_right))
            cur_left, cur_right = left, right
        else:
            cur_right = max(cur_right, right)

    ans.append('%s,%s' % (cur_left, cur_right))

    print(';'.join(ans))

main()
