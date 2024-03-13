package AoC

import "core:fmt"
import "core:strings"
import "core:os"
import "core:strconv"
import "core:slice"

main :: proc() {
    a, b := solution("./AoC Files/Day7_2022.txt")
    fmt.printf("Part 1: %v\nPart 2: %v\n", a, b)
}

solution :: proc(filepath: string) -> (ans1, ans2:int) {
    data, ok := os.read_entire_file(filepath, context.allocator)
    if !ok do return 
    defer delete(data, context.allocator)  
    it := string(data)
    
    Directory :: struct {path : string, size : int}
    
    tmp, uniq_dir_names : [dynamic]string
    dir : [dynamic]Directory 
    
    for line in strings.split_lines_iterator(&it) {
        if line[0:4] == "$ cd" && line[5] != '.' {
            append(&tmp, line[5:])
            append(&uniq_dir_names, strings.join(tmp[:], "-"))   
        }
        if len(line) >= 6 && line[5] == '.' do pop(&tmp)
        if line[0] >= 48 && line[0] <= 57 {
            p := strings.join(tmp[:], "-")
            s := strconv.atoi(line[:strings.index(line, " ")])
            append(&dir, Directory{path = p, size = s})
        }
    }

    ttl : [dynamic]int
    for i in uniq_dir_names {
        t_sum := 0
        for j in dir {
            if strings.contains(j.path, i) do t_sum += j.size
        }
        append(&ttl, t_sum)       
    }
    
    slice.sort(ttl[:])
    for i in ttl {
        if i <= 100_000 do ans1 += i
        if i >= ttl[len(ttl) -1] - 40_000_000 {
            if ans2 == 0 do ans2 = i
        }
    }
    return ans1, ans2
}
