import hx.strings.Char;
import StringTools.*;
import Std.*;
import Tools;

using hx.strings.Strings;
using Lambda;

class Day3 {
    static var alph = new Map<Char, Int>();
    static function main() {
        for (i in 1...27) {
             alph[(i + 96).toChar()] = i;
             alph[(i + 64).toChar()] = i + 26;
        }
        var data = parsefile();
        var pt1 = solution1(data), pt2 = solution2(data);
        Sys.println('Solution 1: $pt1\nSolution 2: $pt2');
    }

    static inline function parsefile() {
        var con: AS = [for (i in sys.io.File.getContent('Advent Files_2022/Day3.txt').split('\n')) trim(i)];
        return con;
    }

    static function solution1(arr: AS) {
        var sum = 0;
        for (i in arr) {
            var n = int(i.length / 2);
            var a = i.substring(0, n);
            var b = i.substring(n);
            for (i in a.split('')) {
                if (b.contains(i)) {
                    sum += alph[i];
                    break;
                }
            }
        }
        return sum;
    }

    static function solution2(arr: AS) {
        var sum = 0, cnt = 0;
        while (cnt < arr.length - 2) {
            for (j in arr[cnt].split('')) {
                if (arr[cnt + 1].contains(j) && arr[cnt + 2].contains(j)) {
                    sum += alph[j];
                    break;   
                }
            }
            cnt += 3;
        }
        return sum;
    }
}
