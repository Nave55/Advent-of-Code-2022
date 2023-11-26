package main

import "core:fmt"
import "core:strings"
import "core:os"
import "core:strconv"
import "core:slice"
import "core:math/rand"

main :: proc() {
    a, b := solution("./AoC Files/Day7_2022.txt")
    fmt.printf("Part 1: %v\nPart 2: %v", a,b)
}

solution :: proc(filepath: string) -> (ans1, ans2: int){
    data, ok := os.read_entire_file(filepath, context.allocator)
    if !ok do return 
    defer delete(data, context.allocator)  
    it := string(data)
    dir, uniq_dir_names : [dynamic]string
    final : [dynamic][dynamic]string
    defer delete(dir); defer delete(uniq_dir_names); defer delete(final)

    for line in strings.split_lines_iterator(&it) {
        if line[0:4] == "$ cd" && line[5] != '.' {
            buf : [32]byte
            r_num := rand.float64_range(0,1000)
            s_num := string(strconv.generic_ftoa(buf[:],r_num,'f',3,64))[1:]
            num := strings.clone(s_num)
            append(&dir, num)
            if slice.contains(uniq_dir_names[:], num) == false {
                append(&uniq_dir_names, num)
            }
        }
        else if strings.contains(line, "$ cd ..") do pop(&dir)
        if line[0] >= 48 && line[0] <= 57 {
            num := line[:strings.index(line, " ")]
            tmp := slice.clone_to_dynamic(dir[:])
            inject_at(&tmp,0,num)
            append(&final, tmp)  
        }
    }

    sum := 0
    ttl : [dynamic]int
    defer delete(ttl)

    for i in uniq_dir_names {
        for j in final {
            if slice.contains(j[:], i) do sum += strconv.atoi(j[0])
        }
        if sum > 0 {
            append(&ttl, sum)
            sum = 0
        }
    }

    slice.sort(ttl[:])
    for i in ttl {
        if i <= 100_000 do ans1 += i
    }
    
    for i in ttl {
        if i >= ttl[len(ttl) -1] - 40_000_000 {
            ans2 = i
            break
        }
    }
    return ans1, ans2
}