import StringTools.*;
import Std.*;
import Tools;

using hx.strings.Strings;
using Lambda;

class Day4 {
    static function main() {
        var data = parsefile();
        var ttl = solution(data);
        var ttl1 = ttl[0], ttl2 = ttl[1];
        Sys.println('Solution 1: $ttl1\nSolution 2: $ttl2');
    }

    static inline function parsefile() {
        var con: AAI = [for (i in sys.io.File.getContent('Advent Files_2022/Day4.txt').replaceAll("-", ",").split(
                                                         "\n")) trim(i).split(',').map(item -> parseInt(item))];
        return con;
    }

    static function solution(arr: AAI) {
        var ttl1 = 0, ttl2 = 0;
        for (i in arr) {
            if (((i[0] >= i[2] && i[0] <= i[3]) && (i[1] >= i[2] && i[1] <= i[3])) || 
                ((i[2] >= i[0] && i[2] <= i[1]) && (i[3] >= i[0] && i[3] <= i[1]))) ttl1++;
            
            if (((i[0] >= i[2] && i[0] <= i[3]) || (i[1] >= i[2] && i[1] <= i[3])) || 
                ((i[2] >= i[0] && i[2] <= i[1]) || (i[3] >= i[0] && i[3] <= i[1]))) ttl2++;
            
        }
        return [ttl1, ttl2];
    }
}
