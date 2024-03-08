import sets, strformat

proc solution(): (int, int) =
    var 
        ttl1 = 0
        ttl2 = 0
    let file = open("input/Day6.txt");
    defer: file.close()

    for i in file.lines():
        for j in 0..<len(i) - 3:
            if len(i[j..j + 3].toHashSet()) == 4:
                ttl1 += j + 4
                break
        for j in 0..<len(i) - 13:
            if len(i[j..j + 13].toHashSet()) == 14:
                ttl2 += j + 14
                break

    return (ttl1, ttl2)
        
let ttl = solution()

echo &"Solution 1: {ttl[0]}\nSolution 2: {ttl[1]}"