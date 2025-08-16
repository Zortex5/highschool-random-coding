def main():
    list = [8, 4, 1]
    print(list)
    sorted_list = mergesort(list, reverse=False)
    print(sorted_list)


""" sorts a list using mergesort
    return [] : sorted version of list
"""
def mergesort(list, reverse=False):
    if len(list) < 2:
        return list
    
    mid = int((len(list) + 1) / 2)

    list1 = list[:mid]
    list2 = list[mid:]

    mergesort(list1)
    mergesort(list2)

    if reverse:
        sorted_list = merge_desc(list1, list2)
    else:
        sorted_list = merge(list1, list2)

    return sorted_list


""" merges 2 lists into one sorted (ascending order) list 
    return [] : merged list
"""
def merge(list1, list2):
    list = []
    
    l = 0
    r = 0

    while l < len(list1) and r < len(list2):
        if list1[l] < list2[r]:
            list.append(list1[l])
            l += 1
        elif list2[r] < list1[l]:
            list.append(list2[r])
            r += 1
    
    while l < len(list1):
        list.append(list1[l])
        l += 1
    
    while r < len(list2):
        list.append(list2[r])
        r += 1
    
    return list


""" merges 2 lists into one sorted (descending order) list 
    return [] : merged list
"""
def merge_desc(list1, list2):
    list = []
    
    l = 0
    r = 0

    while l < len(list1) and r < len(list2):
        if list1[l] > list2[r]:
            list.append(list1[l])
            l += 1
        elif list2[r] > list1[l]:
            list.append(list2[r])
            r += 1
    
    while l < len(list1):
        list.append(list1[l])
        l += 1
    
    while r < len(list2):
        list.append(list2[r])
        r += 1
    
    return list


if __name__ == "__main__":
    main()