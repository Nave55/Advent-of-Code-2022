import StringTools.*;
using hx.strings.Strings;

class Day6 {
    static function main() {
        var data = [for (i in sys.io.File.getContent('Advent Files_2022/Day6.txt').split('\n')) trim(i)].join('');
        var pt1 = solution(data);
        var pt2 = solution(data, 14);
        Sys.println('Solution 1: $pt1\nSolution 2: $pt2');
    }

    static function solution(arr: String, window = 4) {
        var sli = arr.split('');
        for (j in 0...sli.length - window + 1) {
            var uniq = true;
            var str = sli.slice(j, j + window).join('');
            for (k in str.split('')) {
                if (str.countMatches(k) > 1) {
                    uniq = false;
                    break;
                }
            } 
            if (uniq) return j + window;            
        }  
        return 0;
    }
}