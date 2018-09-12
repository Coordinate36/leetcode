package main

import (
	"fmt"
	"strconv"
)

/* func calculate(s string) int {
	var result, num, next int
	op := '+'

	str := []rune(s)
	for i := 0; i < len(str); i++ {
		if str[i] >= '0' && str[i] <= '9' {
			next = int(str[i] - '0')
			for i++; i < len(str) && str[i] >= '0' && str[i] <= '9'; i++ {
				next = next*10 + int(str[i]-'0')
			}
			switch op {
			case '+':
				result += num
				num = next
			case '-':
				result += num
				num = -next
			case '*':
				num *= next
			case '/':
				num /= next
			}
		}
		if i < len(str) && str[i] != ' ' {
			op = str[i]
		}
	}
	result += num

	return result
} */

type Token struct {
	Typ string
	Val string
}

func calculate(s string) int {
	var result, num, next int
	tokens := tokenize(&s)

	op := "+"
	for i := 0; i < len(tokens); i++ {
		if tokens[i].Typ == "NUM" {
			next, _ = strconv.Atoi(tokens[i].Val)
			switch op {
			case "+":
				result += num
				num = next
			case "-":
				result += num
				num = -next
			case "*":
				num *= next
			case "/":
				num /= next
			}
		} else {
			op = tokens[i].Val
		}
	}

	result += num
	return result
}

func tokenize(s *string) []Token {
	var tokens []Token
	str := []rune(*s)

	for i := 0; i < len(str); i++ {
		if isDigit(str[i]) {
			val := []rune{str[i]}
			for i++; i < len(str) && isDigit(str[i]); i++ {
				val = append(val, str[i])
			}
			tokens = append(tokens, Token{"NUM", string(val)})
		}

		if i < len(str) && str[i] != ' ' {
			tokens = append(tokens, Token{"OP", string(str[i])})
		}
	}
	return tokens
}

func isDigit(c rune) bool {
	return c >= '0' && c <= '9'
}

func main() {
	str := "3/2"
	fmt.Println(tokenize(&str))
	fmt.Println(calculate(str))
}
