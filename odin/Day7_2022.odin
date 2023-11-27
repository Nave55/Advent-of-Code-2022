package AoC

import "core:fmt"
import "core:strings"
import "core:os"
import "core:strconv"
import "core:slice"
import "core:math/rand"

main :: proc() {
    a, b := solution("./AoC Files/Day7_2022.txt")
    fmt.printf("Part 1: %v\nPart 2: %v\n", a, b)
}

solution :: proc(filepath: string) -> (ans1, ans2:int) {
    data, ok := os.read_entire_file(filepath, context.allocator)
    if !ok do return 
    defer delete(data, context.allocator)  
    it := string(data)
    
    Directory :: struct {
        Path : string,
        Size : int,
    }
    
    tmp, uniq_dir_names : [dynamic]string
    dir : [dynamic]Directory 
    
    for line in strings.split_lines_iterator(&it) {
        if line[0:4] == "$ cd" && line[5] != '.' {
            append(&tmp, line[5:])
            string_tmp := strings.join(tmp[:], "")
            if slice.contains(uniq_dir_names[:], string_tmp) == false {
                append(&uniq_dir_names, string_tmp)
            }
        }
        if len(line) >= 6 && line[5] == '.' do pop(&tmp)
        if line[0] >= 48 && line[0] <= 57 {
            string_tmp := strings.join(tmp[:], "")
            num := strconv.atoi(line[:strings.index(line, " ")])
            append(&dir, Directory{Path = string_tmp, Size = num})
        }
    }

    ttl : [dynamic]int

    for i in uniq_dir_names {
        for j in dir {
            if strings.contains(j.Path, i) do ans1 += j.Size
        }
        if ans1 > 0 {
            append(&ttl, ans1)
            ans1 = 0
        }
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
