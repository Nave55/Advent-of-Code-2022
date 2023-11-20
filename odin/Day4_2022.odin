package main

import "core:fmt"
import "core:strings"
import "core:os"
import "core:strconv"

main :: proc() {
    solution("./AoC Files/Day4_2022.txt")
}

solution :: proc(filepath: string) {
    data, ok := os.read_entire_file(filepath, context.allocator)
    if !ok do return 
    defer delete(data, context.allocator)  

    it := string(data)
    it, _ = strings.replace(it, "-", ",", -1)
    it, _ = strings.replace(it, ",", "\n", -1)
    arr: [dynamic]int
    defer delete(arr)
   
    cnt, ttl, ttl2 := 1, 0, 0
    for line in strings.split_lines_iterator(&it) {
        append_elem(&arr, strconv.atoi(line))
        if cnt == 4 {
            if (arr[0] >= arr[2] && arr[1] <= arr[3]) || (arr[2] >= arr[0] && arr[3] <= arr[1]) {
                ttl += 1
            }
            if arr[0] >= arr[2] && arr[0] <= arr[3] || arr[1] >= arr[2] && arr[1] <= arr[3] || 
            arr[2] >= arr[0] && arr[2] <= arr[1] || arr[3] >= arr[1] && arr[3] <= arr[0] {
	            ttl2 += 1
            }
            clear(&arr)
            cnt = 0 
        }
        cnt += 1
    }
    fmt.println(ttl)
    fmt.println(ttl2)
}