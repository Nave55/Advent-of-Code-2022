package AoC

import "core:fmt"
import "core:strings"
import "core:os"
import "core:strconv"
import "core:slice"
import "core:math"

main :: proc() {
    a, b := solution("./AoC Files/Day7_2022.txt")
    fmt.printf("Part 1: %v\nPart 2: %v\n", a, b)
}

solution :: proc(filepath: string) -> (ans1, ans2: int) {
    data, ok := os.read_entire_file(filepath, context.allocator)
    if !ok do return 
    defer delete(data, context.allocator)  
    it := string(data)
    
    Directory :: struct {path : string, size : int}
    tmp, uniq_dir_names : [dynamic]string
    dir : [dynamic]Directory; defer delete(dir)
    defer delete(tmp); defer delete(uniq_dir_names)
    
    for line in strings.split_lines_iterator(&it) {
        if line[0:4] == "$ cd" && line[5] != '.' {
            append(&tmp, line[5:])
            append(&uniq_dir_names, strings.join(tmp[:], "-", context.temp_allocator))
        }
        if len(line) >= 6 && line[5] == '.' do pop(&tmp)
        if line[0] >= 48 && line[0] <= 57 {
            p := strings.join(tmp[:], "-", context.temp_allocator)
            s := strconv.atoi(line[:strings.index(line, " ")])
            append(&dir, Directory{path = p, size = s})
        }
    }
    defer free_all(context.temp_allocator)

    ttl : [dynamic]int; defer delete(ttl)
    for i in uniq_dir_names {
        t_sum := 0
        for j in dir {
            if strings.contains(j.path, i) do t_sum += j.size
        }
        append(&ttl, t_sum)       
    }
    
    ans1 = math.sum(slice.filter(ttl[:], proc(item: int) -> bool {return item <= 100_000}, context.temp_allocator))
    ans2 = slice.min(slice.filter(ttl[:], proc(item: int) -> bool {return item >= 41_609_574 - 40_000_000}, context.temp_allocator))
    return ans1, ans2
}
