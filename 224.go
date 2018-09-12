package main

import "fmt"

func calculate(s string) int {
	var str []rune

	for _, c := range s {
		if c != ' ' {
			str = append(str, c)
		}
	}

	ans, step := walk(str, 0)

	var tmp int
	for step < len(str) {
		op := str[step]
		tmp, step = walk(str, step+1)
		if op == '+' {
			ans += tmp
		} else {
			ans -= tmp
		}
	}

	return ans
}

func walk(str []rune, step int) (int, int) {
	var ans int

	if isDigit(str[step]) {
		ans = int(str[step] - '0')
		for step++; step < len(str) && isDigit(str[step]); step++ {
			ans = ans*10 + int(str[step]-'0')
		}
	} else {
		ans, step = walk(str, step+1)

		var tmp int
		for str[step] != ')' {
			op := str[step]
			tmp, step = walk(str, step+1)
			if op == '+' {
				ans += tmp
			} else {
				ans -= tmp
			}
		}

		step++
	}

	return ans, step
}

func isDigit(c rune) bool {
	return c >= '0' && c <= '9'
}

func main() {
	fmt.Println(calculate("(1+(4+5+2)-3)+(6+8)"))
}
