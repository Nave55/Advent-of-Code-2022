import os
import arrays {max}

fn main() {
	lines := os.read_lines("input/Day8_2022.txt")!
	solution(lines)!
}

fn solution(s []string)! {
	mut count := (s.len * 2 + s[0].len * 2) - 4
	mut scores := []int{}

	for rows in 1..s.len - 1 {
		for cols in 1..s.len - 1 {
			pos := rune(s[rows][cols]).str().i8()

			mut left := []i8{}
			mut right := []i8{}
			mut top := []i8{}
			mut bottom := []i8{}
			for i in 1..cols + 1 { left << rune(s[rows][cols - i]).str().i8() }
			for i in 1..s.len - cols { right << rune(s[rows][cols + i]).str().i8() }
			for i in 1..rows + 1 { top << rune(s[rows - i][cols]).str().i8() }
			for i in 1..s.len - rows { bottom << rune(s[rows + i][cols]).str().i8() }

			if max(left)! < pos || max(right)! < pos || max(top)! < pos || max(bottom)! < pos {
				count++
			}

			mut score := 1
			for lst in [left, right, top, bottom] {
				mut tracker := 0
				for i in 0.. lst.len {
					if lst[i] < pos {
						tracker += 1
					}
					else if lst[i] == pos {
						tracker += 1
						break
					}
					else {break}
				}
				
				score *= tracker
			scores << score
			}
		}
	}
	println("Part 1: ${count}\nPart 2: ${max(scores)!}")
}