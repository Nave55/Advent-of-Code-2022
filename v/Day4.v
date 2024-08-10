import os

fn main() {
	mut arr := [][]int{}
	mut lines := os.read_lines('input/Day4_2022.txt')!
	for i in 0 .. lines.len {
		lines[i] = lines[i].replace('-', ',')
		arr << lines[i].split(',').map(it.int())
	}
	mut ttl1, mut ttl2 := 0, 0
	for i in arr {
		if ((i[0] >= i[2] && i[0] <= i[3]) && (i[1] >= i[2] && i[1] <= i[3]))
			|| ((i[2] >= i[0] && i[2] <= i[1]) && (i[3] >= i[0] && i[3] <= i[1])) {
			ttl1++
		}

		if ((i[0] >= i[2] && i[0] <= i[3]) || (i[1] >= i[2] && i[1] <= i[3]))
			|| ((i[2] >= i[0] && i[2] <= i[1]) || (i[3] >= i[0] && i[3] <= i[1])) {
			ttl2++
		}
	}

	println('Part 1: ${ttl1}\nPart 2: ${ttl2}')
}
